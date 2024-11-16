#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义结构体用于存储研究人员信息
typedef struct {
    int account_number;
    char name[50];
    char email[50];
} Researcher;

// 用于演示的模拟数据
Researcher researchers[100];
int researcher_count = 0;

// 注册新研究人员的函数
void register_researcher(int account_number, char* name, char* email) {
    researchers[researcher_count].account_number = account_number;
    strcpy(researchers[researcher_count].name, name);
    strcpy(researchers[researcher_count].email, email);
    researcher_count++;
    printf("研究人员 %s 已成功注册，账户号为 %d。\n", name, account_number);
}

// 编辑研究人员详细信息的函数
void edit_researcher_details(int account_number, char* new_name, char* new_email) {
    for (int i = 0; i < researcher_count; i++) {
        if (researchers[i].account_number == account_number) {
            strcpy(researchers[i].name, new_name);
            strcpy(researchers[i].email, new_email);
            printf("研究人员详细信息已成功更新。\n");
            return;
        }
    }
    printf("未找到账户号为 %d 的研究人员。\n", account_number);
}

// 删除研究人员账户的函数
void delete_researcher(int account_number) {
    for (int i = 0; i < researcher_count; i++) {
        if (researchers[i].account_number == account_number) {
            for (int j = i; j < researcher_count - 1; j++) {
                researchers[j] = researchers[j + 1];
            }
            researcher_count--;
            printf("研究人员账户号为 %d 的研究人员已成功删除。\n", account_number);
            return;
        }
    }
    printf("未找到账户号为 %d 的研究人员。\n", account_number);
}

// 查看研究人员活动和贡献的函数
void view_researcher_contributions(int account_number) {
    for (int i = 0; i < researcher_count; i++) {
        if (researchers[i].account_number == account_number) {
            printf("研究人员 %s (账户号: %d) 的活动和贡献:\n", researchers[i].name, account_number);
            // 此处可以加入查看具体活动和贡献的逻辑
            printf("暂未记录具体贡献数据。\n");
            return;
        }
    }
    printf("未找到账户号为 %d 的研究人员。\n", account_number);
}

// 管理研究人员账户的主菜单函数
void manageResearcherAccounts() {
    int choice;
    int account_number;
    char name[50];
    char email[50];

    do {
        printf("\n---- 研究人员账户管理 ----\n");
        printf("1. 添加研究人员\n");
        printf("2. 编辑研究人员\n");
        printf("3. 删除研究人员\n");
        printf("4. 查看研究人员活动和贡献\n");
        printf("5. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("输入账户号: ");
            scanf("%d", &account_number);
            printf("输入姓名: ");
            scanf("%s", name);
            printf("输入电子邮件: ");
            scanf("%s", email);
            register_researcher(account_number, name, email);
            break;
        case 2:
            printf("输入要编辑的研究人员账户号: ");
            scanf("%d", &account_number);
            printf("输入新姓名: ");
            scanf("%s", name);
            printf("输入新电子邮件: ");
            scanf("%s", email);
            edit_researcher_details(account_number, name, email);
            break;
        case 3:
            printf("输入要删除的研究人员账户号: ");
            scanf("%d", &account_number);
            delete_researcher(account_number);
            break;
        case 4:
            printf("输入要查看的研究人员账户号: ");
            scanf("%d", &account_number);
            view_researcher_contributions(account_number);
            break;
        case 5:
            printf("退出研究人员账户管理。\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
            break;
        }
    } while (choice != 5);
}
