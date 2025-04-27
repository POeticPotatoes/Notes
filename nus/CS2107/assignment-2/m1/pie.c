#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main();
int menu();

int setup() {
    setbuf(stdin, 0);
    setbuf(stdout, 0);
}

int win() {
    char* argv[3] = {"/bin/cat", "flag.txt", NULL};
    printf("Good job!\n");
    execve("/bin/cat", argv, NULL);
}

int viewingredients() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Ingredients for our signature Lemon Blueberry Tart\n\n");
    printf("Sauce:\n");
    printf("1 teaspoon cornstarch\n");
    printf("2 teaspoons lemon juice (or water)\n");
    printf("1 cup (140g) fresh or frozen blueberries (do not thaw)\n");
    printf("2 teaspoons granulated sugar\n\n");
    printf("Shortbread Crust:\n");
    printf("1/2 cup (8 Tbsp; 113g) unsalted butter, melted\n");
    printf("1/4 cup (50g) granulated sugar\n");
    printf("1 teaspoon pure vanilla extract\n");
    printf("1/4 teaspoon salt\n");
    printf("1 cup (125g) all-purpose flour (spooned & leveled)\n");
    printf("Filling:\n\n");
    printf("1 (14 ounce weight) can full-fat sweetened condensed milk\n");
    printf("6 Tablespoons (90ml) lemon juice (about 2 lemons)\n");
    printf("1 teaspoon lemon zest (1 lemon)\n");
    printf("1 large egg yolk\n\n");
    printf("Press ENTER to return to menu.\n");
    getchar();
}

int search() {
    char input[0x10];

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Welcome to catalog search!\n");
    printf("Please use this to view our ingredients catalog.\n\n");
    printf("Please enter your search term:\n");
    fgets(input, 0x10, stdin);
    printf("Nothing found on your search term: ");
    printf(input);
    printf("\n\nPress ENTER to return to menu.\n");
    getchar();
}

int bake() {
    char input[0x30];

    printf("\n\n");
    printf("Input to bake your pie: ");
    gets(input);
    printf("\nBaking pie...\n\n");
    printf("Your pie has been baked. Please proceed to the factory to collect it :)\n\n");
}

int menu() {
    char input[4];

    while(1) {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\033[1;36m");
        printf("=====================\n");
        printf("|                   |\n");
        printf("|     PIE MAKER     |\n");
        printf("|       31415       |\n");
        printf("|                   |\n");
        printf("=====================\n\n");
        printf("\033[0;36m");
        printf("1. View Required Ingredients\n");
        printf("2. Search Catalog\n");
        printf("3. Bake Pie\n");

        printf("\nOption: ");
        fgets(input, 4, stdin);
        switch(atoi(input)) {
            case 1:
                viewingredients();
                break;
            case 2:
                search();
                break;
            case 3:
                bake();
                break;
            default:
                printf("Invalid choice!\n");
                sleep(1.5);
                continue;
        }
    }
}

int main() {
    setup();
    menu();
}
