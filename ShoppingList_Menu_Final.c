#include <stdio.h>
#include <string.h>

// variables to define the array size => valid for the entire code
#define max_items 2
#define max_name_length 50

// Define the structure for articles using typedef
typedef struct {
    char articleName[max_name_length];
    int articleQuantity;
} Article;

/*Functions prototypes |
int* itemCount => the pointer that indicates to the item number/order in the array */
void addItem_s(Article inventory[], int* itemCount);
void showArticles_s(Article inventory[], int itemCount);

int main() {
    Article inventory[max_items];
    int itemCount = 0;
    int choice;

    while (1) {
        // Display the menu
        printf_s("1. Add item\n");
        printf_s("2. Show all items\n");
        printf_s("3. Exit\n");
        printf_s("Choose an option (1-3): ");
        scanf_s("%d", &choice);

        // Clear input buffer
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            addItem_s(inventory, &itemCount);
            break;
        case 2:
            showArticles_s(inventory, itemCount);
            break;
        case 3:
            printf_s("Exiting...\n");
            return 0;

        default:
            printf_s("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add an item to the inventory
void addItem_s(Article inventory[], int* itemCount) {
    // Check if the inventory is full
    if (*itemCount >= max_items) {
        printf_s("Your list is full.\n");
        return;
    }

    // Prompt for item name
    printf_s("Enter your item: ");
    fgets(inventory[*itemCount].articleName, max_name_length, stdin);
    // Remove the new line character added by fgets
    inventory[*itemCount].articleName[strcspn(inventory[*itemCount].articleName, "\n")] = 0;


    // Check if input is empty
    if (strlen(inventory[*itemCount].articleName) == 0) {
        printf_s("Please enter an item.\n");
        return; // Do not increment itemCount
    }


    // Prompt for quantity
    printf_s("Enter quantity for %s: ", inventory[*itemCount].articleName);
    scanf_s("%d", &inventory[*itemCount].articleQuantity);


    // Clear input buffer
    while (getchar() != '\n');

    (*itemCount)++;
}


// Function to show all articles in the inventory
void showArticles_s(Article inventory[], int itemCount) {
    if (itemCount == 0) {
        printf_s("Your inventory is empty.\n");
        return;
    }


    printf_s("\nYour list contains:\n");
    for (int i = 0; i < itemCount; i++) {
        printf_s("%d. %s - quantity: %d\n", i + 1, inventory[i].articleName, inventory[i].articleQuantity);
    }
}
