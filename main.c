#include <stdio.h>

#define startingBalance 500

void welcomeUser(char username[50]) {
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Welcome %s to Roulette\n", username);
}

int main() {
    char username[50];
    int balance = startingBalance;
    welcomeUser(&username);
    return 0;
}
