#include "researcher_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 研究人员数组和计数器，用于存储数据
struct Researcher researchers[100];
int researcher_count = 0;

// 从文件中加载研究人员数据
void load_researchers_from_file() {
    FILE* fp = fopen("researchers.dat", "rb");  // 打开数据文件，以二进制只读模式
    if (fp == NULL) {
        printf("Data file not found, starting with empty data.\n");  // 如果文件不存在，提示没有找到文件
        return;
    }
    // 从文件中读取研究人员数据，并更新研究人员数量
    researcher_count = fread(researchers, sizeof(struct Researcher), 100, fp);
    fclose(fp);  // 关闭文件
    printf("Loaded %d researchers from file.\n", researcher_count);
}

// 将新研究人员保存到文件中（追加模式）
void save_researcher_to_file(struct Researcher *researcher) {
    FILE* fp = fopen("researchers.dat", "ab");  // 以追加模式打开文件
    if (fp == NULL) {
        printf("Unable to save researcher data to file.\n");  // 如果文件无法打开，输出错误信息
        return;
    }
    fwrite(researcher, sizeof(struct Researcher), 1, fp);  // 写入新研究人员数据
    fclose(fp);  // 关闭文件
    printf("Researcher data has been saved successfully.\n");
}

// 将所有研究人员数据保存到文件（用于编辑或删除后保存）
void save_all_researchers_to_file() {
    FILE* fp = fopen("researchers.dat", "wb");  // 以覆盖模式打开文件
    if (fp == NULL) {
        printf("Unable to save researcher data to file.\n");  // 如果文件无法打开，输出错误信息
        return;
    }
    fwrite(researchers, sizeof(struct Researcher), researcher_count, fp);  // 写入所有研究人员数据
    fclose(fp);  // 关闭文件
    printf("All researcher data has been saved successfully.\n");
}

// 注册一个新的研究人员
void register_researcher(const char* name) {
    if (researcher_count >= 100) {
        printf("Cannot add more researchers. Maximum capacity reached.\n");  // 如果达到最大容量，提示无法添加
        return;
    }
    // 将研究人员的名字保存到结构体中，初始贡献设置为“暂无贡献”
    strcpy(researchers[researcher_count].name, name);
    strcpy(researchers[researcher_count].contributions, "No contributions yet.");
    save_researcher_to_file(&researchers[researcher_count]);  // 保存新研究人员的数据
    researcher_count++;  // 更新研究人员计数
    printf("Researcher %s has been successfully registered.\n", name);
}

// 编辑研究人员的详细信息
void edit_researcher_details(const char* name, const char* new_name, const char* new_contributions) {
    // 遍历研究人员数组，查找目标研究人员
    for (int i = 0; i < researcher_count; i++) {
        if (strcmp(researchers[i].name, name) == 0) {
            // 更新研究人员的名字和贡献信息
            strcpy(researchers[i].name, new_name);
            strcpy(researchers[i].contributions, new_contributions);
            save_all_researchers_to_file();  // 保存所有研究人员数据
            printf("Researcher details have been successfully updated.\n");
            return;
        }
    }
    printf("Researcher %s not found.\n", name);  // 如果没有找到研究人员，输出错误信息
}

// 删除研究人员账号
void delete_researcher(const char* name) {
    // 遍历研究人员数组，查找要删除的研究人员
    for (int i = 0; i < researcher_count; i++) {
        if (strcmp(researchers[i].name, name) == 0) {
            // 删除该研究人员，将后面的元素依次前移
            for (int j = i; j < researcher_count - 1; j++) {
                researchers[j] = researchers[j + 1];
            }
            researcher_count--;  // 更新研究人员计数
            save_all_researchers_to_file();  // 保存所有更新后的数据
            printf("Researcher %s has been successfully deleted.\n", name);
            return;
        }
    }
    printf("Researcher %s not found.\n", name);  // 如果没有找到研究人员，输出错误信息
}

// 查看研究人员的贡献
void view_researcher_contributions(const char* name) {
    // 遍历研究人员数组，查找目标研究人员
    for (int i = 0; i < researcher_count; i++) {
        if (strcmp(researchers[i].name, name) == 0) {
            // 输出研究人员的名字和贡献
            printf("Researcher: %s\nContributions: %s\n", researchers[i].name, researchers[i].contributions);
            return;
        }
    }
    printf("Researcher %s not found.\n", name);  // 如果没有找到研究人员，输出错误信息
}

// 研究人员账号管理的主菜单函数
void manageResearcherAccounts() {
    int choice;
    char name[50];
    char new_name[50];
    char contributions[200];

    // 从文件加载研究人员数据
    load_researchers_from_file();

    printf("\nYou have entered the Manage Researcher Accounts module.\n");
    do {
        // 输出管理菜单
        printf("\n---- Researcher Account Management ----\n");
        printf("1. Add Researcher\n");
        printf("2. Edit Researcher Details\n");
        printf("3. Delete Researcher\n");
        printf("4. View Researcher Activity and Contributions\n");
        printf("5. Exit\n");
        printf("Please select an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // 清空输入缓冲区
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter name: ");
                if (scanf("%49s", name) != 1) {
                    printf("Invalid input. Please re-enter the name.\n");
                    while (getchar() != '\n'); // 清空输入缓冲区
                    continue;
                }
                register_researcher(name);  // 注册新的研究人员
                break;
            case 2:
                printf("Enter the name of the researcher to edit: ");
                if (scanf("%49s", name) != 1) {
                    printf("Invalid input. Please re-enter the name.\n");
                    while (getchar() != '\n'); // 清空输入缓冲区
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
                    while (getchar() != '\n'); // 清空输入缓冲区
                    continue;
                }
                printf("Enter new contributions: ");
                if (scanf(" %199[^]", contributions) != 1) {
                    printf("Invalid input. Please re-enter the contributions.\n");
                    while (getchar() != '\n'); // 清空输入缓冲区
                    continue;
                }
                edit_researcher_details(name, new_name, contributions);  // 编辑研究人员详细信息
                break;
            case 3:
                printf("Enter the name of the researcher to delete: ");
                if (scanf("%49s", name) != 1) {
                    printf("Invalid input. Please re-enter the name.\n");
                    while (getchar() != '\n'); // 清空输入缓冲区
                    continue;
                }
                delete_researcher(name);  // 删除研究人员
                break;
            case 4:
                printf("Enter the name of the researcher to view: ");
                if (scanf("%49s", name) != 1) {
                    printf("Invalid input. Please re-enter the name.\n");
                    while (getchar() != '\n'); // 清空输入缓冲区
                    continue;
                }
                view_researcher_contributions(name);  // 查看研究人员的贡献
                break;
            case 5:
                printf("Exiting Researcher Account Management.\n");  // 退出管理模块
                break;
            default:
                printf("Invalid choice. Please try again.\n");  // 如果选择不在选项内，提示错误
                break;
        }
    } while (choice != 5);  // 当选择为5时，退出循环
}