#include <stdio.h>
#include <string.h>

int main()
{
  char estimates[26];
  char secretWord[20];

  int win = 0;
  int lost = 0;
  int estimate = 0;

  sprintf(secretWord, "TESLA");

  do
  {
    printf("\n");

    for (int i = 0; i < strlen(secretWord); i++)
    {
      int show = 0;

      for (int j = 0; j < estimate; j++)
      {
        if (estimates[j] == secretWord[i])
        {
          show = 1;
          break;
        }
      }

      if (show)
      {
        printf("%c ", secretWord[i]);
      }

      else
      {
        printf("_ ");
      }
    }

    printf("\n");

    char estimateCharacter;
    printf("\nDigit your estimate: ");
    scanf(" %c", &estimateCharacter);

    estimates[estimate] = estimateCharacter;
    estimate++;
  } while (!win && !lost);

  return 0;
}