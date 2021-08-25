#include <stdio.h>

#define ATTEMPTS 5 // const

int main()
{
  printf("********************************\n");
  printf("* Welcome to the guessing game *\n");
  printf("********************************\n");

  int secretNumber = 42;
  int userEstimate;

  for (int i = 1; i <= ATTEMPTS; i++)
  {
    printf("\nAttempt: %d of %d \n", i, ATTEMPTS);

    printf("\nDigit your estimate: ");
    scanf("%d", &userEstimate);

    printf("\nYour estimate is %d \n", userEstimate);

    if (userEstimate < 0)
    {
      printf("\nNegative numbers are not valid!\n");
      i--;
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

    printf("\nYOU LOST! TRY AGAIN!\n");
  }

  printf("\nGAME OVER!\n");

  return 0;
}