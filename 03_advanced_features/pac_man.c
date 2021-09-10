#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "pac_man.h"

MAP m;
POSITION hero;

void move(char command)
{
  int x;
  int y;

  m.matrices[hero.x][hero.y] = '.';

  switch (command)
  {
  case 'a':
    m.matrices[hero.x][hero.y - 1] = '@';
    hero.y--;
    break;
  case 'w':
    m.matrices[hero.x - 1][hero.y] = '@';
    hero.x--;
    break;
  case 's':
    m.matrices[hero.x + 1][hero.y] = '@';
    hero.x++;
    break;
  case 'd':
    m.matrices[hero.x][hero.y + 1] = '@';
    hero.y++;
    break;
  }
}

int finish()
{
  return 0;
}

int main()
{
  readMap(&m);

  findMap(&m, &hero, '@');

  do
  {
    printMap(&m);

    char command;
    scanf(" %c", &command);
    move(command);

  } while (!finish());

  freeMap(&m);

  return 0;
}