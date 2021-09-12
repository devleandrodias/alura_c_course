#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void gosts();
void move(char command);

int finish();
int commandIsValid(char command);
int moveGost(int currentX, int currentY, int *destinyX, int *destinyY);