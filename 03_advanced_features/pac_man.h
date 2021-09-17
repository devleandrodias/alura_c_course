#ifndef _PAC_MAN_H
#define _PAC_MAN_H

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

void gosts();
void move(char command);
void recursiveExplodeBomb();
void explodeBomb(int x, int y, int newX, int newY, int quantity);

int finish();
int commandIsValid(char command);
int moveGost(int currentX, int currentY, int *destinyX, int *destinyY);

#endif