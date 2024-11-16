void manageResearcherAccounts() {
    int choice;
    do {
        printf("\n--- Researcher Account Management ---\n");
        printf("1. Add Researcher\n");
        printf("2. Edit Researcher\n");
        printf("3. Delete Researcher\n");
        printf("4. View Researchers\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Researcher researcher;
                printf("Enter researcher account number: ");
                scanf("%d", &researcher.account_number);
                printf("Enter researcher name: ");
                scanf("%49s", researcher.name);  // 限制输入长度
                researcher.contributions = 0;   // 初始贡献为 0
                addResearcher(researcher);
                break;
            }
            case 2: {
                int account_number;
                char new_name[MAX_NAME_LEN];
                printf("Enter researcher account number to edit: ");
                scanf("%d", &account_number);
                printf("Enter new researcher name: ");
                scanf("%49s", new_name);  // 限制输入长度
                editResearcher(account_number, new_name);
                break;
            }
            case 3: {
                int account_number;
                printf("Enter researcher account number to delete: ");
                scanf("%d", &account_number);
                deleteResearcher(account_number);
                break;
            }
            case 4:
                viewResearchers();
                break;
            case 5:
                printf("Returning to the main menu.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}
