#include <string.h>
#include <stdio.h>

int add(void) {
    int isbn;
    int year;
    int id;
    char title[100];

    printf("ISBN or ISSN: ");
    scanf("%d", &isbn);

    printf("Year: ");
    scanf("%d", &year);

    printf("ID: ");
    scanf("%d", &id);

    getchar(); // Consume newline
    printf("Title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline

    FILE *out_file = fopen("books.txt", "a");
    if (out_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(out_file, "ISBN/ISSN: %d\n", isbn);
    fprintf(out_file, "Year: %d\n", year);
    fprintf(out_file, "ID: %d\n", id);
    fprintf(out_file, "Title: %s\n\n", title);

    fflush(out_file);
    fclose(out_file);

    printf("Book added successfully.\n");
    return 0;
}

int rem(void) {
    // Placeholder for remove function
    return 0;
}

int main(void) {
    printf("Type 'help' to get a command list.\n");

    char input[10];
    while (1) {
        // Prompt and input
        printf(">>> ");
        scanf("%s", input);

        // Command check
        if (strcmp(input, "help") == 0) {
            printf("Commands : add, remove, exit\n");
        } else if (strcmp(input, "add") == 0) {
            add();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "remove") == 0) {
            rem();
        } else {
            printf("Type 'help' to get a command list.\n");
        }
    }

    return 0;
}
