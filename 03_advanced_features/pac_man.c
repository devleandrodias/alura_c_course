#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "map.h"
#include "pac_man.h"

MAP m;

POSITION hero;

int moveGost(int currentX, int currentY, int *destinyX, int *destinyY)
{
  int options[4][2] = {
      {currentX, currentY + 1},
      {currentX + 1, currentY},
      {currentX, currentY - 1},
      {currentX - 1, currentY},
  };

  srand(time(0));

  for (int i = 0; i < 10; i++)
  {
    int position = rand() % 4;

    if (canWalk(&m, GOST, options[position][0], options[position][1]))
    {
      *destinyX = options[position][0];
      *destinyY = options[position][1];

      return 1;
    }
  }

  return 0;
}

void gosts()
{
  MAP copy;

  copyMap(&copy, &m);

  for (int i = 0; i < m.lines; i++)
  {
    for (int j = 0; j < m.columns; j++)
    {
      if (copy.matrices[i][j] == GOST)
      {
        int destinyX;
        int destinyY;

        int find = moveGost(i, j, &destinyX, &destinyY);

        if (find)
          walkOnTheMap(&m, i, j, destinyX, destinyY);
      }
    }
  }

  freeMap(&copy);
}

int commandIsValid(char command)
{
  return (command == UP || command == DOWN || command == LEFT || command == RIGHT);
}

void move(char command)
{
  if (!commandIsValid(command))
    return;

  system("clear");

  int nextX = hero.x;
  int nextY = hero.y;

  switch (command)
  {
  case LEFT:
    nextY--;
    break;
  case UP:
    nextX--;
    break;
  case DOWN:
    nextX++;
    break;
  case RIGHT:
    nextY++;
    break;
  }

  if (!canWalk(&m, HERO, nextX, nextY))
    return;

  walkOnTheMap(&m, hero.x, hero.y, nextX, nextY);

  hero.x = nextX;
  hero.y = nextY;
}

int finish()
{
  POSITION p;

  return (!findOnTheMap(&m, &p, HERO));
}

int main()
{
  system("clear");

  readMap(&m);

  findOnTheMap(&m, &hero, HERO);

  do
  {
    printMap(&m);

    char command;
    scanf(" %c", &command);
    move(command);
    gosts();

  } while (!finish());

  freeMap(&m);

  return 0;
}