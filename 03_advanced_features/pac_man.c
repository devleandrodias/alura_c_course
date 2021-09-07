#include <stdio.h>
#include <stdlib.h>

#include "pac_man.h"

char **map;
int lines;
int columns;

void freeMemory()
{
  for (int i = 0; i < lines; i++)
  {
    free(map[i]);
  }

  free(map);
}

void dynamicMapAllocation()
{
  map = malloc(sizeof(char *) * lines);

  for (int i = 0; i < lines; i++)
  {
    map[i] = malloc(sizeof(char) * (columns + 1));
  }
}

void readMap()
{
  FILE *file = fopen("map.txt", "r");

  if (file == 0)
  {
    printf("Error loading map...");
    exit(1);
  }

  fscanf(file, "%d %d", &lines, &columns);

  dynamicMapAllocation();

  for (int i = 0; i < 5; i++)
  {
    fscanf(file, "%s", map[i]);
  }

  fclose(file);
}

int main()
{
  readMap();

  for (int i = 0; i < 5; i++)
  {
    printf("%s\n", map[i]);
  }

  freeMemory();

  return 0;
}