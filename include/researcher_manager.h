#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

// 定义结构体用于存储研究人员信息
struct Researcher {
    char name[50];
    char contributions[200];
};

void manageResearcherAccounts();
void register_researcher(const char* name);
void edit_researcher_details(const char* name, const char* new_name, const char* new_contributions);
void delete_researcher(const char* name);
void view_researcher_contributions(const char* name);

#endif // SEARCH_MANAGER_H
