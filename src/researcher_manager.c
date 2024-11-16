#include "researcher_manager.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 用于演示的模拟数据
Researcher researchers[100];
int researcher_count = 0;

// 注册新研究人员的函数
void register_researcher(int account_number, char* name, char* email) {
    researchers[researcher_count].account_number = account_number;
    strcpy(researchers[researcher_count].name, name);
    strcpy(researchers[researcher_count].email, email);
    researcher_count++;
    printf("Researcher %s has been successfully registered with account number %d.\n", name, account_number);
}

// 编辑研究人员详细信息的函数
void edit_researcher_details(int account_number, char* new_name, char* new_email) {
    for (int i = 0; i < researcher_count; i++) {
        if (researchers[i].account_number == account_number) {
            strcpy(researchers[i].name, new_name);
            strcpy(researchers[i].email, new_email);
            printf("Researcher details have been successfully updated.\n");
            return;
        }
    }
    printf("Researcher with account number %d not found.\n", account_number);
}

// 删除研究人员账户的函数
void delete_researcher(int account_number) {
    for (int i = 0; i < researcher_count; i++) {
        if (researchers[i].account_number == account_number) {
            for (int j = i; j < researcher_count - 1; j++) {
                researchers[j] = researchers[j + 1];
            }
            researcher_count--;
            printf("Researcher with account number %d has been successfully deleted.\n", account_number);
            return;
        }
    }
    printf("Researcher with account number %d not found.\n", account_number);
}

// 查看研究人员活动和贡献的函数
void view_researcher_contributions(int account_number) {
    for (int i = 0; i < researcher_count; i++) {
        if (researchers[i].account_number == account_number) {
            printf("Activities and contributions of researcher %s (Account number: %d):\n", researchers[i].name, account_number);
            // 此处可以加入查看具体活动和贡献的逻辑
            printf("No specific contribution data recorded yet.\n");
            return;
        }
    }
    printf("Researcher with account number %d not found.\n", account_number);
}
