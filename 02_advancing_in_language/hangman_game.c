#include <stdio.h>
#include <string.h>

char secretWord[20];
char estimates[26];
int estimate = 0;

void showHeader()
{
  printf("************************\n");
  printf("      HANGMAN GAME      \n");
  printf("************************\n");
}

void chooseWord()
{
  sprintf(secretWord, "TESLA");
}

void kick(int *estimate, char estimates[26])
{
  char estimateCharacter;
  printf("\nDigit your estimate: ");
  scanf(" %c", &estimateCharacter);

  estimates[*estimate] = estimateCharacter;

  (*estimate)++;
}

int alreadyKicked(char letter)
{
  int show = 0;

  for (int j = 0; j < estimate; j++)
  {
    if (estimates[j] == letter)
    {
      show = 1;
      break;
    }
  }

  return show;
}

void drawGallows()
{
  printf("\n");

  for (int i = 0; i < strlen(secretWord); i++)
  {

    if (alreadyKicked(secretWord[i]))
    {
      printf("%c ", secretWord[i]);
    }

    else
    {
      printf("_ ");
    }
  }

  printf("\n");
}

int main()
{
  int win = 0;
  int lost = 0;

  showHeader();

  chooseWord();

  do
  {
    drawGallows();

    kick(&estimate, estimates);

  } while (!win && !lost);

  return 0;
}