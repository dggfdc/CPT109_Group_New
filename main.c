#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include "planet_manager.h"
#include "researcher_manager.h"
#include "search_manager.h"
#include "statics_manager.h"
#include "user_manager.h"

// 函数声明
void managePlanetInfo();
void viewStatistics();
void manageResearcherAccounts();
void searchAndInspectPlanets();
void manageCustomerAccounts();
void displayMenu();

int main()
{
    // 初始5个行星数据
    Planet initialPlanets[5] = {
        {"Earth", "Terrestrial", 12742, 1.0, 1, 1, 1},
        {"Mars", "Terrestrial", 6779, 1.52, 1, 1, 1},
        {"Jupiter", "Gas Giant", 139820, 5.2, 1, 1, 1},
        {"Saturn", "Gas Giant", 116460, 9.58, 1, 1, 1},
        {"Venus", "Terrestrial", 12104.0, 0.72, 1, 1, 1}
    };

    // 检查文件是否存在，如果不存在则写入初始数据
    FILE* file = fopen("planets.dat", "rb");
    if (file == NULL)
    {
        // 文件不存在，写入初始数据
        file = fopen("planets.dat", "wb");
        if (file == NULL)
        {
            printf("无法打开文件\n");
            exit(1);
        }
        fwrite(initialPlanets, sizeof(Planet), 5, file);
        printf("Initial planet data written to file successfully.\n");
        fclose(file);
    }
    else
    {
        // 文件存在，直接关闭
        printf("File already exists.\n");
        fclose(file);
    }

    int choice;

    do
    {
        displayMenu();  // 显示主菜单
        printf("Enter your choice (1-5, 0 to exit): ");
        scanf("%d", &choice);
        getchar();  // 清理输入缓冲区，防止残留字符影响下一次输入

        switch (choice)
        {
        case 1:
            printf("You selected: Manage Planet Information\n");  // 调试信息
            managePlanetInfo();
            break;
        case 2:
            printf("You selected: View Statistics\n");  // 调试信息
            viewStatistics();
            break;
        case 3:
            printf("You selected: Manage Researcher Accounts\n");  // 调试信息
            manageResearcherAccounts();
            break;
        case 4:
            printf("You selected: Search and Inspect Planets\n");  // 调试信息
            searchAndInspectPlanets();
            break;
        case 5:
            printf("You selected: Manage Customer Accounts\n");  // 调试信息
            manageCustomerAccounts();
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 0 and 5.\n");
        }
    } while (choice != 0);

    return 0;
}

// 显示主菜单
void displayMenu()
{
    printf("\n--- Main Menu ---\n");
    printf("1. Manage Planet Information\n");
    printf("2. View Statistics\n");
    printf("3. Manage Researcher Accounts\n");
    printf("4. Search and Inspect Planets\n");
    printf("5. Manage Customer Accounts\n");
    printf("0. Exit\n");
}

// 管理星球信息模块
void managePlanetInfo()
{
    printf("\nYou have entered the Manage Planet Information module.\n");
    // 这里可以进一步实现管理星球信息的功能，如添加、编辑或删除星球等
}

// 查看统计数据模块
void viewStatistics()
{
    printf("\nYou have entered the View Statistics module.\n");
    // 这里可以进一步实现查看统计数据的功能，如编入星球的数量、发现星球的数量等
}

// 管理研究人员账户模块
// Define Researcher structure
typedef struct {
    int account_number;
    char name[50];
    char email[50];
} Researcher;

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




// 搜索和检查行星模块
void searchAndInspectPlanets()
{
    printf("\nYou have entered the Search and Inspect Planets module.\n");
    // 这里可以进一步实现搜索和检查行星的功能，如按名称、类型等进行搜索

    // 用户选择搜索类型
    int choice;
    printf("Choose search criteria:\n");
    printf("1. Search by Name\n");
    printf("2. Search by Type\n");
    printf("3. Search by Size\n");
    printf("4. Search by Distance from Sun\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    getchar();  // 清理输入缓冲区，防止残留字符影响下一次输入

    switch (choice)
    {
    case 1:
    {
        // 根据行星名称搜索
        char searchName[50];
        printf("Enter the name of the planet to search: ");
        scanf("%s", searchName);
        getchar();
        searchPlanetByName("planets.dat", searchName);
        break;
    }
    case 2:
    {
        // 根据行星类型搜索
        char searchType[50];
        printf("Enter the type of the planet to search (e.g., Terrestrial, Gas Giant, Ice Giant): ");
        scanf("%s", searchType);
        getchar();
        searchPlanetType("planets.dat", searchType);
        break;
    }
    case 3:
    {
        // 根据行星大小搜索
        double searchSize;
        printf("Enter the closest size of the planet to search (in km): ");
        scanf("%lf", &searchSize);
        getchar();
        searchPlanetBySize("planets.dat", searchSize);
        break;
    }
    case 4:
    {
        // 根据行星距离搜索
        double searchDistance;
        printf("Enter the minimum distance from the sun to search (in AU): ");
        scanf("%lf", &searchDistance);
        getchar();
        searchPlanetByDistance("planets.dat", searchDistance);
        break;
    }
    default:
        printf("Invalid choice. Please enter a number between 1 and 4.\n");
    }

    // 显示所有行星信息
    printf("\nDisplaying all planets:\n");
    int display_choice;
    printf("1. Display all information\n");
    printf("2. Do not display all information\n");
    scanf("%d", &display_choice);
    getchar();
    if (display_choice == 1)
    {
        displayAllPlanets("planets.dat");
    }
}

// 客户管理模块
void manageCustomerAccounts()
{
    printf("\nYou have entered the Manage Customer Accounts module.\n");
    // 这里可以进一步实现客户管理的功能，如注册新账户、编辑账户信息等
}
