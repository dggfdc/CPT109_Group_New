#include <stdio.h>
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
    int choice;

    do {
        displayMenu();  // 显示主菜单
        printf("Enter your choice (1-5, 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                managePlanetInfo();
                break;
            case 2:
                viewStatistics();
                break;
            case 3:
                manageResearcherAccounts();
                break;
            case 4:
                searchAndInspectPlanets();
                break;
            case 5:
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
void displayMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Manage Planet Information\n");
    printf("2. View Statistics\n");
    printf("3. Manage Researcher Accounts\n");
    printf("4. Search and Inspect Planets\n");
    printf("5. Manage Customer Accounts\n");
    printf("0. Exit\n");
}

// 管理星球信息模块
void managePlanetInfo() {
    printf("\nYou have entered the Manage Planet Information module.\n");
    // 这里可以进一步实现管理星球信息的功能，如添加、编辑或删除星球等。
}

// 查看统计数据模块
void viewStatistics() {
    printf("\nYou have entered the View Statistics module.\n");
    // 这里可以进一步实现查看统计数据的功能，如编入星球的数量、发现星球的数量等。
}

// 管理研究人员账户模块
void manageResearcherAccounts() {
    printf("\nYou have entered the Manage Researcher Accounts module.\n");
    // 这里可以进一步实现管理研究人员账户的功能，如添加、编辑或删除研究人员账户等。
}

// 搜索和检查行星模块
void searchAndInspectPlanets() {
    printf("\nYou have entered the Search and Inspect Planets module.\n");
    // 这里可以进一步实现搜索和检查行星的功能，如按名称、类型等进行搜索。
}

// 客户管理模块
void manageCustomerAccounts() {
    printf("\nYou have entered the Manage Customer Accounts module.\n");
    // 这里可以进一步实现客户管理的功能，如注册新账户、编辑账户信息等。
}
