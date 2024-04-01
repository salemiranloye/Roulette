#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define startingBalance 500

void welcomeUser(char *username, int balance) {
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("\nWelcome %s to Roulette \nYour Starting Balance is: $%d\n", username, balance);
}

void playRound(int *balance){
    char input;
    int bet;
    int gamble;
    printf("Input gamble amount: ");
    scanf("%d", &gamble);
    
    printf(
        "\n------------------------------------------\n"
        "Enter your bet for the Round:\n"
           "(a) Even\n"
           "(b) Odd\n"
           "(c) Red\n"
           "(d) Black\n"
           "(e) 1-18\n"
           "(f) 19-36\n"
           "(g) 1-12\n"
           "(h) 13-24\n"
           "(i) 25-36\n"
           "(Enter number) to place bet on specific number: \n"
           "Input: ");

    scanf(" %c", &input);

    input = tolower(input);

    if (isdigit(input)) {
        bet = input - '0';
        printf("You placed a bet on the number: %d\n", bet);
    } else {
        switch (input) {
            case 'a':
                printf("You placed a bet on Even.\n");
                break;
            case 'b':
                printf("You placed a bet on Odd.\n");
                break;
            case 'c':
                printf("You placed a bet on Red.\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
}

bool askIfPlaying(){

}

int main() {
    char username[50];
    int balance = startingBalance;
    bool playing = true;

    welcomeUser(&username, balance);

    while (playing)
    {
        playRound(&balance);
        playing = askIfPlaying();
    }
    

    return 0;
}
