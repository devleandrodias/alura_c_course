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

void freeMap(MAP *m);
void readMap(MAP *m);
void printMap(MAP *m);
void dynamicMapAllocation(MAP *m);
void findMap(MAP *m, POSITION *p, char c);
