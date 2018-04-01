// constant definitions
enum COLORS {BLACK = 30, RED = 31, GREEN = 32, YELLOW = 33, BLUE = 34, MAGENTA = 35, CYAN = 36, WHITE = 37};
#define ESC 0x1B

// functions prototype
void clearScreen	(void);
void gotoxy			(int, int);
void setColour		(int);
void dispBar		(int, double);
