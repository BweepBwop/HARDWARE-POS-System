#include <stdio.h>
#include <string.h>

// Define a struct to hold product information
typedef struct {
    char name[20];
    float price;
} Product;

// Define a struct to hold the receipt information
typedef struct {
    char date[10];
    char time[10];
    float total;
    int num_items;
    Product items[10]; // max 10 items per receipt
} Receipt;

// Function to display the login menu
void display_login_menu() {
    printf("Point of Sale System\n");
    printf("---------------------\n");
    printf("1. Login\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

// Function to handle user login
void login(char *password) {
    char input[20];
    printf("Enter password: ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    if (strcmp(input, password) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Invalid password. Try again.\n");
        login(password);
    }
}

// Function to display the main menu
void display_main_menu() {
    printf("Point of Sale System\n");
    printf("---------------------\n");
    printf("1. Add item to cart\n");
    printf("2. View cart\n");
    printf("3. Checkout\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function to add an item to the cart
void add_item_to_cart(Receipt *receipt) {
    Product item;
    printf("Enter item name: ");
    fgets(item.name, 20, stdin);
    item.name[strcspn(item.name, "\n")] = 0;
    printf("Enter item price: ");
    scanf("%f", &item.price);
    receipt->items[receipt->num_items] = item;
    receipt->num_items++;
    receipt->total += item.price;
}

// Function to view the cart
void view_cart(Receipt *receipt) {
    printf("Your cart:\n");
    for (int i = 0; i < receipt->num_items; i++) {
        printf("%s: $%.2f\n", receipt->items[i].name, receipt->items[i].price);
    }
    printf("Total: $%.2f\n", receipt->total);
}

// Function to checkout and print the receipt
void checkout(Receipt *receipt) {
    printf("Receipt:\n");
    printf("Date: %s\n", receipt->date);
    printf("Time: %s\n", receipt->time);
    printf("Items:\n");
    for (int i = 0; i < receipt->num_items; i++) {
        printf("%s: $%.2f\n", receipt->items[i].name, receipt->items[i].price);
    }
    printf("Total: $%.2f\n", receipt->total);
}

int main() {
    char password[] = "password123"; // password
    Receipt receipt;
    receipt.num_items = 0;
    receipt.total = 0.0;

    display_login_menu();
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        login(password);
        display_main_menu();
        while (1) {
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    add_item_to_cart(&receipt);
                    break;
                case 2:
                    view_cart(&receipt);
                    break;
                case 3:
                    checkout(&receipt);
                    return 0;
                case 4:
                    return 0;
                default:
                    printf("Invalid choice. Try again.\n");
            }
        }
    } else {
        return 0;
    }
}
