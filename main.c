#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include "planet_manager.h"
#include "researcher_manager.h"
#include "searchplanet_manager.h"
#include "statics_manager.h"
#include "user_manager.h"

// 函数声明
void managePlanetInfo();
void viewStatistics();
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
    viewStat();
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
