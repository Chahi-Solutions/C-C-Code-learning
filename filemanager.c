#include <stdio.h>
#include <stdlib.h>
#include <string.h>

   // Function to display the menu
void displayMenu() {
    printf("\nFile Manager Menu:\n");
    printf("1. View a File\n");
    printf("2. Copy a File\n");
    printf("3. Delete a File\n");
    printf("4. Rename a File\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

  // Function to view a file's content
void viewFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    printf("\n--- File Content ---\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\n--- End of File ---\n");

    fclose(file);
}

     // Function to copy a file
void copyFile(const char *source, const char *destination) {
    FILE *srcFile = fopen(source, "r");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *destFile = fopen(destination, "w");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(srcFile);
        return;
    }

    char ch;
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    fclose(srcFile);
    fclose(destFile);
}

     // Function to delete a file
void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        perror("Error deleting file");
    }
}

     // Function to rename a file
void renameFile(const char *oldName, const char *newName) {
    if (rename(oldName, newName) == 0) {
        printf("File renamed successfully.\n");
    } else {
        perror("Error renaming file");
    }
}

    // Main function
int main() {
    int choice;
    char filename[100], source[100], destination[100], newName[100];

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter the file name to view: ");
                scanf("%s", filename);
                viewFile(filename);
                break;

            case 2:
                printf("Enter the source file name: ");
                scanf("%s", source);
                printf("Enter the destination file name: ");
                scanf("%s", destination);
                copyFile(source, destination);
                break;

            case 3:
                printf("Enter the file name to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;

            case 4:
                printf("Enter the current file name: ");
                scanf("%s", filename);
                printf("Enter the new file name: ");
                scanf("%s", newName);
                renameFile(filename, newName);
                break;

            case 5:
                printf("Exiting File Manager. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
