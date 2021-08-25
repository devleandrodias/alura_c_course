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

  while (1)
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

    if (secretNumber == userEstimate)
    {
      printf("\nYOU WIN!\n");
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

  printf("\nGAME OVER! YOU WON IN %dst ATTEMP! AND YOUR SCORE IS %.1fpt\n", attempts, score);

  return 0;
}

// short (2 bytes), int (4 bytes), long (8 bytes) - Integers

// float (4 bytes), double (8 bytes) - Decimals