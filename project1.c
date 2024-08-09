#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = (rand() % 100) + 1;

     printf("this is a guessing game the computer will pick a random number between 1 to 100, you have to guess it.\nall the best.\n" );

    int guess;
    int attempts =0 ;
    while (1)
    {
        printf("guess the number");
    scanf("%d",&guess);
    attempts++;
    
    if (guess < randomNumber )
    {
        printf("higher number please\n");
    }
    else if (guess > randomNumber)
    {
        printf("Lower number please\n");
    }
    else if (guess=randomNumber)
    {
        printf("you guessed the correct number you take %d attempts", attempts);
        break;
    }
    
    }
    

    return 0;
}
