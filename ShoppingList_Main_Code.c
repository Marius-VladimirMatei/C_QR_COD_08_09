#include <stdio.h>
#include <string.h>

void main() {
    char articleName[2][50];  // Array for article names (2 items, max length 50)
    int articleQuantity[2];    // Array for article quantities
    int itemCount = 0;

    // Loop for input items and quantities until the array is full
    while (1) {
        if (itemCount >= 2) { // Check if the list is full
            printf_s("Your list is full.\n");
            break;
        }

        printf_s("Enter your item (or press Enter to finish): ");
        // fgets returns the string from stdin (standard input - keyboard)
        fgets(articleName[itemCount], 50, stdin);

        // Remove newline character added by fgets
        articleName[itemCount][strcspn(articleName[itemCount], "\n")] = 0;

        // Check if input is empty
        if (strlen(articleName[itemCount]) == 0) {
            printf_s("Please enter an item.\n");
            continue; // Ask for input again
        }

        printf_s("Enter quantity for %s: ", articleName[itemCount]);
        scanf_s("%d", &articleQuantity[itemCount]);

        // Clear input buffer
        while (getchar() != '\n');

        itemCount++;
    }

    // Outputs the list
    printf_s("\nYour list contains:\n");
    for (int i = 0; i < itemCount; i++) {
        printf_s("%d. %s - quantity: %d\n", i + 1, articleName[i], articleQuantity[i]);
    }

}
