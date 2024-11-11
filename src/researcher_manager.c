#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define RESEARCHER_FILE "researchers.dat"

// 研究者信息结构体
typedef struct {
    int account_number;      // 唯一账号
    char name[MAX_NAME_LEN]; // 研究者姓名
    int contributions;       // 贡献数量
} Researcher;

// 添加研究者账号
void addResearcher(Researcher researcher) {
    FILE* file = fopen(RESEARCHER_FILE, "ab");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }
    fwrite(&researcher, sizeof(Researcher), 1, file);
    fclose(file);
    printf("Researcher %s added successfully.\n", researcher.name);
}

// 编辑研究者账号
void editResearcher(int account_number, const char* new_name) {
    FILE* file = fopen(RESEARCHER_FILE, "rb+");
    if (file == NULL) {
        printf("Error: Unable to open file for updating.\n");
        return;
    }

    Researcher researcher;
    int found = 0;

    // 搜索要修改的研究者
    while (fread(&researcher, sizeof(Researcher), 1, file) == 1) {
        if (researcher.account_number == account_number) {
            // 找到研究者，更新信息
            fseek(file, -(long)sizeof(Researcher), SEEK_CUR);
            strncpy_s(researcher.name, MAX_NAME_LEN, new_name, _TRUNCATE);
            fwrite(&researcher, sizeof(Researcher), 1, file);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        printf("Researcher account %d updated successfully.\n", account_number);
    }
    else {
        printf("Researcher account %d not found.\n", account_number);
    }
}

// 删除研究者账号
void deleteResearcher(int account_number) {
    FILE* file = fopen(RESEARCHER_FILE, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    FILE* temp = fopen("temp_researchers.dat", "wb");
    if (temp == NULL) {
        printf("Error: Unable to open temporary file.\n");
        fclose(file);
        return;
    }

    Researcher researcher;
    int found = 0;

    // 将不需要删除的研究者写入临时文件
    while (fread(&researcher, sizeof(Researcher), 1, file) == 1) {
        if (researcher.account_number != account_number) {
            fwrite(&researcher, sizeof(Researcher), 1, temp);
        }
        else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    if (found) {
        if (remove(RESEARCHER_FILE) != 0) {
            perror("Error deleting original file");
            return;
        }
        if (rename("temp_researchers.dat", RESEARCHER_FILE) != 0) {
            perror("Error renaming temporary file");
            return;
        }
        printf("Researcher account %d deleted successfully.\n", account_number);
    }
    else {
        remove("temp_researchers.dat");
        printf("Researcher account %d not found.\n", account_number);
    }
}

// 查看所有研究者账号及其贡献
void viewResearchers() {
    FILE* file = fopen(RESEARCHER_FILE, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return;
    }

    Researcher researcher;

    // 读取文件中的所有研究者信息
    while (fread(&researcher, sizeof(Researcher), 1, file) == 1) {
        printf("Account Number: %d, Name: %s, Contributions: %d\n",
            researcher.account_number, researcher.name, researcher.contributions);
    }

    fclose(file);
}

// 主程序入口
int main() {
    int choice;

    while (1) {
        printf("\nResearcher Account Management System\n");
        printf("1. Add Researcher\n");
        printf("2. Edit Researcher\n");
        printf("3. Delete Researcher\n");
        printf("4. View Researchers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Researcher researcher;
            printf("Enter researcher account number: ");
            scanf("%d", &researcher.account_number);
            printf("Enter researcher name: ");
            scanf("%49s", researcher.name);  // 限制输入长度
            researcher.contributions = 0; // 初始贡献为 0
            addResearcher(researcher);
        }
        else if (choice == 2) {
            int account_number;
            char new_name[MAX_NAME_LEN];
            printf("Enter researcher account number to edit: ");
            scanf("%d", &account_number);
            printf("Enter new researcher name: ");
            scanf("%49s", new_name);  // 限制输入长度
            editResearcher(account_number, new_name);
        }
        else if (choice == 3) {
            int account_number;
            printf("Enter researcher account number to delete: ");
            scanf("%d", &account_number);
            deleteResearcher(account_number);
        }
        else if (choice == 4) {
            viewResearchers();
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
