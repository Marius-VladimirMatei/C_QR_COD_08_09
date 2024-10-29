#include <stdio.h>
#include <string.h>


// macros to define the array size
#define max_items 2
#define max_name_length 50

void main() {
    char articleName[max_items][max_name_length];
    int articleQuantity[max_items];
    int itemCount = 0;

    // loop for input items and qtys until the setup array is full
    while (1) {
        if (itemCount >= max_items) {
            printf("Your list is full.\n");
            break;
        }

        printf("Enter your item (or press Enter to finish): ");
        //fgets returns the the string; stdin (standard input - keyboard
        fgets(articleName[itemCount], max_name_length, stdin);

        // Remove newline character added by fgets
        //articleName[itemCount][strcspn(articleName[itemCount], "\n")] = 0;

        // Check if input is empty
        if (strlen(articleName[itemCount]) == 0) {
            printf("Please enter an item.\n");
            continue; // Ask for input again
        }

        printf("Enter quantity for %s: ", articleName[itemCount]);
        scanf_s("%d", &articleQuantity[itemCount]);

        // Clear input buffer
        while (getchar() != '\n');

        itemCount++;
    }

    // Outputs the list
    printf("\nYour list contains:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - quantity: %d\n", i + 1, articleName[i], articleQuantity[i]);
    }

}