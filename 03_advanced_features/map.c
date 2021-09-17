#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

int canWalk(MAP *m, char character, int x, int y)
{
  return (positionIsValid(m, x, y) && !isWall(m, x, y) && !isCharacter(m, x, y, character));
}

int isWall(MAP *m, int x, int y)
{
  return m->matrices[x][y] == VERTICAL_WALL || m->matrices[x][y] == HORIZONTAL_WALL;
}

int isCharacter(MAP *m, int x, int y, char character)
{
  return m->matrices[x][y] == character;
}

void copyMap(MAP *destiny, MAP *origin)
{
  destiny->lines = origin->lines;
  destiny->columns = origin->columns;

  dynamicMapAllocation(destiny);

  for (int i = 0; i < origin->lines; i++)
  {
    strcpy(destiny->matrices[i], origin->matrices[i]);
  }
}

void walkOnTheMap(MAP *m, int originX, int originY, int destinyX, int destinyY)
{
  char character = m->matrices[originX][originY];

  m->matrices[originX][originY] = EMPTY;
  m->matrices[destinyX][destinyY] = character;
}

int positionIsValid(MAP *m, int x, int y)
{
  if (x >= m->lines)
    return 0;

  if (y >= m->columns)
    return 0;

  return 1;
}

int positionIsEmpty(MAP *m, int x, int y)
{
  return (m->matrices[x][y] == EMPTY);
}

int findOnTheMap(MAP *m, POSITION *p, char c)
{
  for (int i = 0; i < m->lines; i++)
  {
    for (int j = 0; j < m->columns; j++)
    {
      if (m->matrices[i][j] == c)
      {
        p->x = i;
        p->y = j;
        return 1;
      }
    }
  }

  return 0;
}

void freeMap(MAP *m)
{
  for (int i = 0; i < (*m).lines; i++)
  {
    free(m->matrices[i]);
  }

  free(m->matrices);
}

void dynamicMapAllocation(MAP *m)
{
  m->matrices = malloc(sizeof(char *) * m->lines);

  for (int i = 0; i < m->lines; i++)
  {
    m->matrices[i] = malloc(sizeof(char) * (m->columns + 1));
  }
}

void readMap(MAP *m)
{
  FILE *file = fopen("map.txt", "r");

  if (file == 0)
  {
    printf("Error loading map...");
    exit(1);
  }

  fscanf(file, "%d %d", &m->lines, &m->columns);

  dynamicMapAllocation(m);

  for (int i = 0; i < 5; i++)
  {
    fscanf(file, "%s", m->matrices[i]);
  }

  fclose(file);
}
