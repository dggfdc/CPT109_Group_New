#ifndef RESEARCHER_CATALOGUE_H
#define RESEARCHER_CATALOGUE_H

#define MAX_NAME_LEN 50

// 研究者信息结构体
typedef struct {
    int account_number;      // 唯一账号
    char name[MAX_NAME_LEN]; // 研究者姓名
    int contributions;       // 贡献数量
} Researcher;

// 研究者管理函数
void addResearcher(Researcher researcher);
void editResearcher(int account_number, const char* new_name);
void deleteResearcher(int account_number);
void viewResearchers();

#endif
