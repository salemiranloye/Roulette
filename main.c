#include <stdio.h>
#include <windows.h>

#define startingBalance 500

void welcomeUser(char username[50]) {
    DWORD usernameSize = sizeof(char) * 50;

    if (!GetUserName(username, &usernameSize)) {
        printf("Please enter your username: ");
        scanf("%s", username);
    }
    printf("Welcome %s to Roulette\n", username);
}

int main() {
    char username[50];
    int balance = startingBalance;
    welcomeUser(username);
    

    return 0;
}
