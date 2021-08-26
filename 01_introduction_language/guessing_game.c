#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
  printf("********************************\n");
  printf("* Welcome to the guessing game *\n");
  printf("********************************\n");

  srand(time(0)); // Random (S = Seed, rand = Random)

  int random = rand();

  int secretNumber = random % 100;
  int userEstimate;
  int win = 0;
  int attempts = 0;
  double score = 1000;
  int tryNumber = 0;
  int difficult = 0;

  printf("(1) - Easy \n(2) - Medium \n(3) - Hard\n");
  printf("Choice: ");
  scanf("%d", &difficult);

  switch (difficult)
  {
  case 1:
    tryNumber = 20;
    break;
  case 2:
    tryNumber = 15;
    break;
  case 3:
    tryNumber = 10;
    break;
  default:
    printf("Invalid option!");
    break;
  }

  if (tryNumber > 0)
  {

    for (int i = 1; i <= tryNumber; i++)
    {
      attempts++;

      printf("\nAttempt: %d\n", attempts);

      printf("\nDigit your estimate: ");
      scanf("%d", &userEstimate);

      printf("\nYour estimate is %d \n", userEstimate);

      if (userEstimate < 0)
      {
        printf("\nNegative numbers are not valid!\n");
        continue;
      }

      int greater = userEstimate > secretNumber;

      win = secretNumber == userEstimate;

      if (win)
      {
        break;
      }

      else if (greater)
      {
        printf("\nYour estimate is greater than the secret number\n");
      }

      else
      {
        printf("\nYour estimate is less than the secret number\n");
      }

      double lostPoints = (userEstimate - secretNumber) / (double)2;

      score -= fabs(lostPoints);
    }

    if (win)
    {
      printf("\nYOU WIN!\n");
      printf("\nYOU WON IN %dst ATTEMP! AND YOUR SCORE IS %.1fpt\n", attempts, score);
    }

    else
    {
      printf("\nGAME OVER! TRY AGAIN!\n");
    }
  }

  return 0;
}

// short (2 bytes), int (4 bytes), long (8 bytes) - Integers

// float (4 bytes), double (8 bytes) - Decimals