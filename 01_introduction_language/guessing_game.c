#include <stdio.h>

int main()
{
  printf("********************************\n");
  printf("* Welcome to the guessing game *\n");
  printf("********************************\n");

  int secretNumber = 42;
  int userEstimate;
  int win = 0;
  int attempts = 0;

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

      win = 1;
    }

    else if (greater)
    {
      printf("\nYour estimate is greater than the secret number\n");
    }

    else
    {
      printf("\nYour estimate is less than the secret number\n");
    }
  }

  printf("\nGAME OVER! YOU WON IN %dst ATTEMP!\n", attempts);

  return 0;
}