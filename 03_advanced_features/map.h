#define HERO '@'
#define GOST 'G'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'

struct Map
{
  char **matrices;
  int lines;
  int columns;
};

struct Position
{
  int x;
  int y;
};

typedef struct Map MAP;
typedef struct Position POSITION;

int isWall(MAP *m, int x, int y);
int positionIsValid(MAP *m, int x, int y);
int positionIsEmpty(MAP *m, int x, int y);
int findOnTheMap(MAP *m, POSITION *p, char c);
int canWalk(MAP *m, char character, int x, int y);
int isCharacter(MAP *m, int x, int y, char character);

void freeMap(MAP *m);
void readMap(MAP *m);
void printMap(MAP *m);
void dynamicMapAllocation(MAP *m);
void copyMap(MAP *destiny, MAP *origin);
void walkOnTheMap(MAP *m, int originX, int originY, int destinyX, int destinyY);
