#include <stdio.h>
#include <stdlib.h>

#include "ui.h"
#include "map.h"

char drawGost[4][7] = {
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}};

char drawWall[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}};

char drawHero[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}};

char drawBomb[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}};

char drawEmpty[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}};

void printPart(char draw[4][7], int part)
{
  printf("%s", draw[part]);
}

void printMap(MAP *m)
{
  for (int i = 0; i < m->lines; i++)
  {
    for (int part = 0; part < 4; part++)
    {
      for (int j = 0; j < m->columns; j++)
      {
        switch (m->matrices[i][j])
        {
        case GOST:
          printPart(drawGost, part);
          break;
        case HERO:
          printPart(drawHero, part);
          break;
        case BOMB:
          printPart(drawBomb, part);
          break;
        case VERTICAL_WALL:
        case HORIZONTAL_WALL:
          printPart(drawWall, part);
          break;
        case EMPTY:
          printPart(drawEmpty, part);
          break;
        }
      }

      printf("\n");
    }
  }
}