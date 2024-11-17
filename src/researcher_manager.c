#include "researcher_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 管理研究人员账户模块
// Array of researchers and counter for storing data
Researcher researchers[100];
int researcher_count = 0;

// Save researcher data to file
void save_researchers_to_file() {
    FILE* fp = fopen("researchers.dat", "wb");
    if (fp == NULL) {
        printf("Unable to save researcher data to file.\n");
        return;
    }
    fwrite(researchers, sizeof(Researcher), researcher_count, fp);
    fclose(fp);
}

// Load researcher data from file
void load_researchers_from_file() {
    FILE* fp = fopen("researchers.dat", "rb");
    if (fp == NULL) {
        printf("Data file not found, starting with empty data.\n");
        return;
    }
    researcher_count = fread(researchers, sizeof(Researcher), 100, fp);
    fclose(fp);
}

// Register a new researcher
void register_researcher(int account_number, char* name, char* email) {
    researchers[researcher_count].account_number = account_number;
    strcpy(researchers[researcher_count].name, name);
    strcpy(researchers[researcher_count].email, email);
    researcher_count++;
    save_researchers_to_file();  // Save data to file
    printf("Researcher %s has been successfully registered with account number %d.\n", name, account_number);
}

// Edit researcher details
void edit_researcher_details(int account_number, char* new_name, char* new_email) {
    for (int i = 0; i < researcher_count; i++) {
        if (researchers[i].account_number == account_number) {
            strcpy(researchers[i].name, new_name);
            strcpy(researchers[i].email, new_email);
            save_researchers_to_file();  // Save updated data to file
            printf("Researcher details have been successfully updated.\n");
            return;
        }
    }
    printf("Researcher with account number %d not found.\n", account_number);
}

// Delete researcher account
void delete_researcher(int account_number) {
    for (int i = 0; i < researcher_count; i++) {
        if (researchers[i].account_number == account_number) {
            for (int j = i; j < researcher_count - 1; j++) {
                researchers[j] = researchers[j + 1];
            }
            researcher_count--;
            save_researchers_to_file();  // Save updated data to file
            printf("Researcher with account number %d has been successfully deleted.\n", account_number);
            return;
        }
    }
    printf("Researcher with account number %d not found.\n", account_number);
}

// View researcher activities and contributions
void view_researcher_contributions(int account_number) {
    for (int i = 0; i < researcher_count; i++) {
        if (researchers[i].account_number == account_number) {
            printf("Activities and contributions of researcher %s (Account number: %d):\n", researchers[i].name, account_number);
            // Add logic to view specific activities and contributions here
            printf("No specific contribution data recorded yet.\n");
            return;
        }
    }
    printf("Researcher with account number %d not found.\n", account_number);
}

// Main menu function for managing researcher accounts
void manageResearcherAccounts() {
    int choice;
    int account_number;
    char name[50];
    char email[50];

    // Load data from file
    load_researchers_from_file();

    printf("\nYou have entered the Manage Researcher Accounts module.\n");
    do {
        printf("\n---- Researcher Account Management ----\n");
        printf("1. Add Researcher\n");
        printf("2. Edit Researcher\n");
        printf("3. Delete Researcher\n");
        printf("4. View Researcher Activities and Contributions\n");
        printf("5. Exit\n");
        printf("Please select an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
        case 1:
            printf("Enter account number: ");
            if (scanf("%d", &account_number) != 1) {
                printf("Invalid input. Please enter a valid account number.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            printf("Enter name: ");
            if (scanf("%49s", name) != 1) {
                printf("Invalid input. Please re-enter the name.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            printf("Enter email: ");
            if (scanf("%49s", email) != 1) {
                printf("Invalid input. Please re-enter the email.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            register_researcher(account_number, name, email);
            break;
        case 2:
            printf("Enter the account number of the researcher to edit: ");
            if (scanf("%d", &account_number) != 1) {
                printf("Invalid input. Please enter a valid account number.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            printf("Enter new name: ");
            if (scanf("%49s", name) != 1) {
                printf("Invalid input. Please re-enter the name.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            printf("Enter new email: ");
            if (scanf("%49s", email) != 1) {
                printf("Invalid input. Please re-enter the email.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            edit_researcher_details(account_number, name, email);
            break;
        case 3:
            printf("Enter the account number of the researcher to delete: ");
            if (scanf("%d", &account_number) != 1) {
                printf("Invalid input. Please enter a valid account number.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            delete_researcher(account_number);
            break;
        case 4:
            printf("Enter the account number of the researcher to view: ");
            if (scanf("%d", &account_number) != 1) {
                printf("Invalid input. Please enter a valid account number.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            view_researcher_contributions(account_number);
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
