#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "hangman_game.h"

// Global variables
char secretWord[20];
char estimates[26];
int estimate = 0;

void addNewWord()
{
  char option;
  printf("Do you want to add a new word in the game? (y/n) ");
  scanf(" %c", &option);

  if (option == 'y')
  {
    char newWord[20];
    printf("What new word? ");
    scanf("%s", newWord);

    FILE *file;

    file = fopen("words.txt", "r+");

    if (file == 0)
    {
      printf("\nSorry! Database unavailable!\n");
      exit(1);
    }

    int quantityWords;
    fscanf(file, "%d", &quantityWords);
    quantityWords++;

    fseek(file, 0, SEEK_SET);
    fprintf(file, "%d", quantityWords);

    fseek(file, 0, SEEK_END);
    fprintf(file, "\n%s", newWord);

    fclose(file);
  }
}

void showHeader()
{
  printf("************************\n");
  printf("      HANGMAN GAME      \n");
  printf("************************\n");
}

void chooseWord()
{
  FILE *file = fopen("words.txt", "r");

  if (file == 0)
  {
    printf("\nSorry! Database unavailable!\n");
    exit(1);
  }

  int quantityWords;
  fscanf(file, "%d", &quantityWords);

  srand(time(0));
  int random = rand() % quantityWords;

  for (int i = 0; i < random; i++)
  {
    fscanf(file, "%s", secretWord);
  }

  fclose(file);
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

int lost()
{
  int errors = 0;

  for (int i = 0; i < estimate; i++)
  {
    int exists = 0;

    for (int j = 0; j < strlen(secretWord); j++)
    {
      if (estimates[i] == secretWord[j])
      {
        exists = 1;
        break;
      }
    }

    if (!exists)
    {
      errors++;
    }
  }

  if (errors >= 5)
    printf("\nGAME OVER! YOU LOST!\n");

  return errors >= 5;
}

int win()
{
  for (int i = 0; i < strlen(secretWord); i++)
  {
    if (!alreadyKicked(secretWord[i]))
    {
      return 0;
    }
  }

  printf("\nGAME OVER! YOU WIN!\n");

  return 1;
}

int main()
{
  showHeader();

  chooseWord();

  do
  {
    drawGallows();

    kick(&estimate, estimates);

  } while (!win() && !lost());

  addNewWord();

  return 0;
}