#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#define startingBalance 500

void welcomeUser(char *username, int balance) {
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("\nWelcome %s to Roulette \nYour Starting Balance is: $%d\n", username, balance);
}

bool isRed(int number) {
  int redNumbers[] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
  for (int i = 0; i < sizeof(redNumbers) / sizeof(redNumbers[0]); i++) {
    if (number == redNumbers[i]) {
      return true;
    }
  }
  return false;
}

void playRound(int *balance) {
    char input;
    int bet = 0, gamble, winningNumber, guessedNumber;
    printf("Input gamble amount: ");
    scanf("%d", &gamble);
    srand(time(NULL));

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
           "(j) to place bet on specific number: \n"
           "Input: ");

    scanf(" %c", &input);

    winningNumber = rand() % 37;

    switch (input) {
        case 'a':
            if (winningNumber % 2 == 0) {
                bet = gamble;
            } else {
                bet = -gamble;
            }
            break;
        case 'b':
            if (winningNumber % 2 != 0) { // Odd Number
                bet = gamble;
            } else {
                bet = -gamble;
            }
            break;
        case 'c':
            if (isRed(winningNumber)) {
                bet = gamble;
            } else {
                bet = -gamble;
            }
            break;
        case 'd':
            if (!isRed(winningNumber)) {
                bet = gamble;
            } else {
                bet = -gamble;
            }
            break;
        case 'e':
            if (winningNumber >= 1 && winningNumber <= 18) {
                bet = gamble;
            } else {
                bet = -gamble;
            }
            break;
        case 'f':
            if (winningNumber >= 19 && winningNumber <= 36) {
                bet = gamble;
            } else {
                bet = -gamble;
            }
            break;
        case 'g':
            if (winningNumber >= 1 && winningNumber <= 12) {
                bet = gamble*2;
            } else {
                bet = -gamble;
            }
            break;
        case 'h':
            if (winningNumber >= 13 && winningNumber <= 24) {
                bet = gamble*2;
            } else {
                bet = -gamble;
            }
            break;
        case 'i':
            if (winningNumber >= 25 && winningNumber <= 36) {
                bet = gamble*2;
            } else {
                bet = -gamble;
            }
            break;
        case 'j':
            printf("Enter Specific Number: \n");
            scanf(" %d", &guessedNumber);
            if (guessedNumber == winningNumber) {
                bet = gamble * 35;
            } else {
                bet = -gamble;
            }
            break;
        default:
            printf("Invalid input.\n");
            return;
    }

    printf("The ball landed in %d so you ", winningNumber);
    if (bet > 0) {
        printf("won $%d\n", bet);
    } else if (bet < 0) {
        printf("lost $%d\n", -bet);
    }
    *balance += bet;
    printf("Your balance after this round: $%d\n", *balance);
}

bool askIfPlaying(int balance){
    char response;
    printf("Do you want to play another round? (Y/N): ");
    scanf(" %c", &response);
    return (response == 'Y' || response == 'y') && balance > 0;
}

int main() {
    char username[50];
    int balance = startingBalance;
    bool playing = true;

    welcomeUser(username, balance);

    while (playing) {
        playRound(&balance);
        if (balance <= 0) {
            printf("You have run out of balance.\n");
            break;
        }
        playing = askIfPlaying(balance);
    }

    printf("Thank you for playing. Your final balance is: $%d\n", balance);
    return 0;
}
