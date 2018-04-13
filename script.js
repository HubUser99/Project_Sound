let rawData = "";
let prevRawData = "";
let array = [];
let levelData = "";
let prevLevelData = "";
let levelsArray = [];
let levelsArraydB = [];
let prevLevelsArray = [];
let ctx = document.getElementById("myChart").getContext('2d');

let myChart = new Chart(ctx, {
    type: 'bar',
    data: "",
    options: ""
});

$.ajaxSetup({
    // Disable caching of AJAX responses
    cache: false
});

function drawer() {
    myChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: Array(8).fill(''),
            datasets: [{
                label: '',
                data: levelsArray,
                borderColor: Array(8).fill('rgba(0, 0, 0, 1)'),
                borderWidth: 1
            }, {
                label: 'dB',
                data: levelsArraydB,
                borderColor: 'rgba(0, 100, 100, 1)',
                backgroundColor: 'rgba(0, 100, 100, 0.2)',
                borderWidth: 1,
                cubicInterpolationMode: 'monotone',
                type: 'line'
            }]
        },
        options: {
            maintainAspectRatio: false,
            responsive: true,
            scales: {
                yAxes: [{
                    ticks: {
                        beginAtZero: true
                    }
                }]
            }
        }

    });
}

function loader() {
    $.get('sound_log.txt', (data) => {
        array = data.split('\n');
        rawData = array[array.length - 2];
        prevRawData = array[array.length - 3];
        levelData = rawData.substring(21, rawData.length);
        prevLevelData = prevRawData.substring(21, prevRawData.length);
        let temp = "";
        let j = 0;

        for (let i = 0; i < levelData.length; i++) {
            if (levelData[i] !== ';') {
                temp += levelData[i];
            } else {
                levelsArray[j] = parseFloat(temp);
                levelsArraydB[j] = Math.log(parseFloat(temp)) / Math.log(10) * 20;
                temp = "";
                j++;
            }
        }

        for (let i = 0; i < prevLevelData.length; i++) {
            if (prevLevelData[i] !== ';') {
                temp += prevLevelData[i];
            } else {
                prevLevelsArray[j] = parseFloat(temp);
                temp = "";
                j++;
            }
        }

        levelsArraydB[j] = Math.log(parseFloat(temp)) / Math.log(10) * 20;
        levelsArray[j] = parseFloat(temp);
    });
}

function updater(){
    let flag = true;
    for(let i = 0; i < levelsArray.length; i++){
        if (prevLevelsArray[i] === levelsArray[i]) flag = false;
    }
    if (flag){
        myChart.update();
        for(let i = 0; i < levelsArray.length; i++){
            prevLevelsArray[i] = levelsArray[i];
        }
    }
}

$(()=> {
    loader();
    drawer();
    setInterval(function () {
        loader();
        updater();
        //myChart.update();
    }, 200);
});