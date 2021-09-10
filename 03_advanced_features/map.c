#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void findMap(MAP *m, POSITION *p, char c)
{
  for (int i = 0; i < m->lines; i++)
  {
    for (int j = 0; j < m->columns; j++)
    {
      if (m->matrices[i][j] == c)
      {
        p->x = i;
        p->y = j;
        break;
      }
    }
  }
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

void printMap(MAP *m)
{
  for (int i = 0; i < 5; i++)
  {
    printf("%s\n", m->matrices[i]);
  }
}
