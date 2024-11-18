#include "researcher_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Array of researchers and counter for storing data
struct Researcher researchers[100];
int researcher_count = 0;

// Load researcher data from file
void load_researchers_from_file() {
    FILE* fp = fopen("researchers.dat", "rb");
    if (fp == NULL) {
        printf("Data file not found, starting with empty data.\n");
        return;
    }
    researcher_count = fread(researchers, sizeof(struct Researcher), 100, fp);
    fclose(fp);
    printf("Loaded %d researchers from file.\n", researcher_count);
}

// Save new researcher to file (in append mode)
void save_researcher_to_file(struct Researcher *researcher) {
    FILE* fp = fopen("researchers.dat", "ab");  // 使用追加模式保存新研究人员
    if (fp == NULL) {
        printf("Unable to save researcher data to file.\n");
        return;
    }
    fwrite(researcher, sizeof(struct Researcher), 1, fp);
    fclose(fp);
    printf("Researcher data has been saved successfully.\n");
}

// Save all researcher data to file (used when editing or deleting)
void save_all_researchers_to_file() {
    FILE* fp = fopen("researchers.dat", "wb");  // 使用覆盖模式保存所有研究人员数据
    if (fp == NULL) {
        printf("Unable to save researcher data to file.\n");
        return;
    }
    fwrite(researchers, sizeof(struct Researcher), researcher_count, fp);
    fclose(fp);
    printf("All researcher data has been saved successfully.\n");
}

// Register a new researcher
void register_researcher(const char* name) {
    if (researcher_count >= 100) {
        printf("Cannot add more researchers. Maximum capacity reached.\n");
        return;
    }
    strcpy(researchers[researcher_count].name, name);
    strcpy(researchers[researcher_count].contributions, "No contributions yet.");
    save_researcher_to_file(&researchers[researcher_count]);  // 保存新研究人员的数据
    researcher_count++;
    printf("Researcher %s has been successfully registered.\n", name);
}

// Edit researcher details
void edit_researcher_details(const char* name, const char* new_name, const char* new_contributions) {
    for (int i = 0; i < researcher_count; i++) {
        if (strcmp(researchers[i].name, name) == 0) {
            strcpy(researchers[i].name, new_name);
            strcpy(researchers[i].contributions, new_contributions);
            save_all_researchers_to_file();  // 保存所有更新后的数据
            printf("Researcher details have been successfully updated.\n");
            return;
        }
    }
    printf("Researcher %s not found.\n", name);
}

// Delete researcher account
void delete_researcher(const char* name) {
    for (int i = 0; i < researcher_count; i++) {
        if (strcmp(researchers[i].name, name) == 0) {
            for (int j = i; j < researcher_count - 1; j++) {
                researchers[j] = researchers[j + 1];
            }
            researcher_count--;
            save_all_researchers_to_file();  // 保存所有更新后的数据
            printf("Researcher %s has been successfully deleted.\n", name);
            return;
        }
    }
    printf("Researcher %s not found.\n", name);
}

// View researcher contributions
void view_researcher_contributions(const char* name) {
    for (int i = 0; i < researcher_count; i++) {
        if (strcmp(researchers[i].name, name) == 0) {
            printf("Researcher: %s\nContributions: %s\n", researchers[i].name, researchers[i].contributions);
            return;
        }
    }
    printf("Researcher %s not found.\n", name);
}

// Main menu function for managing researcher accounts
void manageResearcherAccounts() {
    int choice;
    char name[50];
    char new_name[50];
    char contributions[200];

    // Load data from file
    load_researchers_from_file();

    printf("\nYou have entered the Manage Researcher Accounts module.\n");
    do {
        printf("\n---- Researcher Account Management ----\n");
        printf("1. Add Researcher\n");
        printf("2. Edit Researcher Details\n");
        printf("3. Delete Researcher\n");
        printf("4. View Researcher Activity and Contributions\n");
        printf("5. Exit\n");
        printf("Please select an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter name: ");
                if (scanf("%49s", name) != 1) {
                    printf("Invalid input. Please re-enter the name.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                register_researcher(name);
                break;
            case 2:
                printf("Enter the name of the researcher to edit: ");
                if (scanf("%49s", name) != 1) {
                    printf("Invalid input. Please re-enter the name.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                // 显示原始姓名和贡献
                for (int i = 0; i < researcher_count; i++) {
                    if (strcmp(researchers[i].name, name) == 0) {
                        printf("Current Name: %s\n", researchers[i].name);
                        printf("Current Contributions: %s\n", researchers[i].contributions);
                        break;
                    }
                }
                printf("Enter new name: ");
                if (scanf("%49s", new_name) != 1) {
                    printf("Invalid input. Please re-enter the new name.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                printf("Enter new contributions: ");
                if (scanf(" %199[^]", contributions) != 1) {
                    printf("Invalid input. Please re-enter the contributions.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                edit_researcher_details(name, new_name, contributions);
                break;
            case 3:
                printf("Enter the name of the researcher to delete: ");
                if (scanf("%49s", name) != 1) {
                    printf("Invalid input. Please re-enter the name.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                delete_researcher(name);
                break;
            case 4:
                printf("Enter the name of the researcher to view: ");
                if (scanf("%49s", name) != 1) {
                    printf("Invalid input. Please re-enter the name.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    continue;
                }
                view_researcher_contributions(name);
                break;
            case 5:
                printf("Exiting Researcher Account Management.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
}
