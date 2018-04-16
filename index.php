<?php

if( isset($_POST['data']) ) {
    $log_file = 'sound_log.txt';
    $data = $_POST['data'];
    $today = date("Y-m-d H:i:s");
    $str = $today . ', ' . $data . "\n";
    //echo "\nThis is from the server\n";
    // now we open the file
    if (file_exists($log_file)) {
        $fp = fopen($log_file, "a");
        fwrite($fp, $str);
        fclose($fp);
    } else {
        $fp = fopen($log_file, "w");
        fwrite($fp, $str);
        fclose($fp);
    }
    echo "Data is stored\n";
} else {
    $log_file = 'sound_log.txt';
    $fp = fopen($log_file, "r");
    $last = 0;
    while (!feof($fp)){
        fgets($fp);
        $last++;
    }
    fseek($fp, 0);
    for($i = 0; $i < $last - 1; $i++){
        $line = fgets($fp);
    }
    $data = substr($line,21, 1024);
    $data = substr($data,0, strlen($data) - 2);
    fclose($fp);
	include "ui.html";
}

?>

