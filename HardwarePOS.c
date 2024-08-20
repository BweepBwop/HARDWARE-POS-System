#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    float price;
} Product;

typedef struct {
    char date[10];
    char time[10];
    float total;
    int num_items;
    Product items[10]; // max 10 items
} Receipt;

typedef struct {
    char name[20];
    Product products[10]; // max 10 products
    int num_products;
} Category;

void display_login_menu() {
    printf("Point of Sale System\n");
    printf("---------------------\n");
    printf("Enter password: ");
}

// Function to handle user login
void login(char *password) {
    char input[20];
    display_login_menu();
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = 0;
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
    printf("1. Tools\n");
    printf("2. Lumber\n");
    printf("3. Tiles\n");
    printf("4. Construction Materials\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void display_category(Category category) {
    printf("%s:\n", category.name);
    for (int i = 0; i < category.num_products; i++) {
        printf("[%d] - %s: $%.2f\n", i + 1, category.products[i].name, category.products[i].price);
    }
    printf("Enter your choice: ");
}

void add_item_to_cart(Receipt *receipt, Product item) {
    receipt->items[receipt->num_items] = item;
    receipt->num_items++;
    receipt->total += item.price;
}

void view_cart(Receipt *receipt) {
    printf("Your cart:\n");
    for (int i = 0; i < receipt->num_items; i++) {
        printf("%s: $%.2f\n", receipt->items[i].name, receipt->items[i].price);
    }
    printf("Total: $%.2f\n", receipt->total);
}

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

    Category tools;
    strcpy(tools.name, "Tools");
    tools.num_products = 4;
    strcpy(tools.products[0].name, "Wrench");
    tools.products[0].price = 10.99;
    strcpy(tools.products[1].name, "Hammer");
    tools.products[1].price = 5.99;
    strcpy(tools.products[2].name, "Saw");
    tools.products[2].price = 7.99;
    strcpy(tools.products[3].name, "Screwdriver");
    tools.products[3].price = 3.99;

    Category lumber;
    strcpy(lumber.name, "Lumber");
    lumber.num_products = 4;
    strcpy(lumber.products[0].name, "2x4");
    lumber.products[0].price = 2.99;
    strcpy(lumber.products[1].name, "2x6");
    lumber.products[1].price = 4.99;
    strcpy(lumber.products[2].name, "2x8");
    lumber.products[2].price = 6.99;
    strcpy(lumber.products[3].name, "2x10");
    lumber.products[3].price = 8.99;

    Category tiles;
    strcpy(tiles.name, "Tiles");
    tiles.num_products = 4;
    strcpy(tiles.products[0].name, "Ceramic Tile");
    tiles.products[0].price = 1.99;
    strcpy(tiles.products[1].name, "Porcelain Tile");
    tiles.products[1].price = 2.99;
        strcpy(tiles.products[2].name, "Marble Tile");
    tiles.products[2].price = 4.99;
    strcpy(tiles.products[3].name, "Granite Tile");
    tiles.products[3].price = 5.99;

    Category constructionMaterials;
    strcpy(constructionMaterials.name, "Construction Materials");
    constructionMaterials.num_products = 4;
    strcpy(constructionMaterials.products[0].name, "Cement");
    constructionMaterials.products[0].price = 3.99;
    strcpy(constructionMaterials.products[1].name, "Sand");
    constructionMaterials.products[1].price = 2.99;
    strcpy(constructionMaterials.products[2].name, "Gravel");
    constructionMaterials.products[2].price = 4.99;
    strcpy(constructionMaterials.products[3].name, "Bricks");
    constructionMaterials.products[3].price = 5.99;

    login(password);
    int choice;
    display_main_menu();
    scanf("%d", &choice);
    while (1) {
        switch (choice) {
            case 1:
                display_category(tools);
                int toolChoice;
                scanf("%d", &toolChoice);
                add_item_to_cart(&receipt, tools.products[toolChoice - 1]);
                printf("[1] - Add another item\n");
                printf("[2] - Checkout\n");
                int nextChoice;
                scanf("%d", &nextChoice);
                if (nextChoice == 1) {
                    continue;
                } else if (nextChoice == 2) {
                    break;
                } else {
                    printf("Invalid choice. Try again.\n");
                }
                break;
            case 2:
                display_category(lumber);
                int lumberChoice;
                scanf("%d", &lumberChoice);
                add_item_to_cart(&receipt, lumber.products[lumberChoice - 1]);
                printf("[1] - Add another item\n");
                printf("[2] - Checkout\n");
                scanf("%d", &nextChoice);
                if (nextChoice == 1) {
                    continue;
                } else if (nextChoice == 2) {
                    break;
                } else {
                    printf("Invalid choice. Try again.\n");
                }
                break;
            case 3:
                display_category(tiles);
                int tileChoice;
                scanf("%d", &tileChoice);
                add_item_to_cart(&receipt, tiles.products[tileChoice - 1]);
                printf("[1] - Add another item\n");
                printf("[2] - Checkout\n");
                scanf("%d", &nextChoice);
                if (nextChoice == 1) {
                    continue;
                } else if (nextChoice == 2) {
                    break;
                } else {
                    printf("Invalid choice. Try again.\n");
                }
                break;
            case 4:
                display_category(constructionMaterials);
                int constructionMaterialsChoice;
                scanf("%d", &constructionMaterialsChoice);
                add_item_to_cart(&receipt, constructionMaterials.products[constructionMaterialsChoice - 1]);
                printf("[1] - Add another item\n");
                printf("[2] - Checkout\n");
                scanf("%d", &nextChoice);
                if (nextChoice == 1) {
                    continue;
                } else if (nextChoice == 2) {
                    break;
                } else {
                    printf("Invalid choice. Try again.\n");
                }
                break;
            case 5:
                view_cart(&receipt);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    checkout(&receipt);
    float payment;
    printf("Enter payment amount: $");
    scanf("%f", &payment);
    while (payment < receipt.total) {
        printf("Please enter the correct amount: $");
        scanf("%f", &payment);
    }
    printf("Change: $%.2f\n", payment - receipt.total);
    return 0;
}
