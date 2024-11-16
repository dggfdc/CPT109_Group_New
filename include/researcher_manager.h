#ifndef RESEARCHER_MANAGER_H
#define RESEARCHER_MANAGER_H

#define MAX_NAME_LEN 50

typedef struct {
    int account_number;      // 唯一账号
    char name[MAX_NAME_LEN]; // 研究者姓名
    int contributions;       // 贡献数量
} Researcher;

// 函数声明
void addResearcher(Researcher researcher);
void editResearcher(int account_number, const char* new_name);
void deleteResearcher(int account_number);
void viewResearchers();

#endif // RESEARCHER_MANAGER_H
