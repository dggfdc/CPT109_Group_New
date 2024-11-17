#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

// 定义结构体用于存储研究人员信息
typedef struct {
    int account_number;
    char name[50];
    char email[50];
} Researcher;

void manageResearcherAccounts();
void register_researcher(int account_number, char* name, char* email);
void edit_researcher_details(int account_number, char* new_name, char* new_email);
void delete_researcher(int account_number);
void view_researcher_contributions(int account_number);

#endif //SEARCH_MANAGER_H
