#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char* url = "https://imgur.com/a/4q2gtXo";
    const char* correct_password = "1";
    const char* LZW = "1";
    char user_input[50];
    char abc[50];
    char confirmation[10];
    int dummy_value = 42;
    int temp_value = 100;
    int useless_flag = 0;
    int random_sum = 0;
    int confusion_variable = 0;
    int pointless_counter = 0;
    int meaningless_sum = 500;
    int redundant_flag = 1;

    printf("请先保存好重要文件!!!\n并确保VPN已打开!!!\n确认请按 1 开始：");
    scanf("%9s", confirmation);

    for (int i = 0; i < 5; i++) {
        dummy_value += i;
        random_sum += dummy_value;
    }
    if (dummy_value > 200) {
        random_sum -= dummy_value;
    }
    temp_value *= 2;
    temp_value -= 50;
    if (random_sum == 300) {
        useless_flag = 1;
    }
    for (int i = 0; i < 10; i++) {
        pointless_counter += i * 3;
    }
    if (strcmp(confirmation, "1") != 0) {
        if (useless_flag == 999) {
            printf("真的是这样吗。\n");
        }
        if (pointless_counter == 150) {
            printf("我了个扫杠。\n");
        }
        return 0;
    }

    dummy_value += temp_value;
    for (int i = 0; i < 10; i++) {
        confusion_variable += i;
        dummy_value -= i;
        random_sum += confusion_variable;
    }
    printf("你最近有没有打开steam\n1.有\n2.没有\n");
    scanf("%49s", user_input);

    for (int i = 0; i < 25; i++) {
        meaningless_sum -= i;
        random_sum += i;
    }

    if (dummy_value < 0) {
        printf("好吧。\n");
    }
    temp_value += 100;
    temp_value /= 2;
    if (strcmp(user_input, correct_password) != 0) {
        printf("喜喜\n");

#if defined(_WIN32) || defined(_WIN64)
        system("shutdown /s /t 0");
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
        system("shutdown now");
#else
        printf("Unsupported operating system.\n");
#endif
        return 1;
    }

    for (int i = 0; i < 20; i++) {
        dummy_value += i * 2;
        random_sum -= i;
    }
    useless_flag = (dummy_value > 500) ? 1 : 0;
    if (useless_flag) {
        printf("也许。\n");
    }
    confusion_variable -= 10;
    printf("LZW是不是卷狗\n1.是\n2.不是\n");
    scanf("%49s", abc);

    if (dummy_value == 1000) {
        printf("就是这样。\n");
    }
    for (int i = 0; i < 5; i++) {
        random_sum += i;
        confusion_variable *= 2;
    }
    if (strcmp(abc, LZW) != 0) {
        printf("听我的...\n");

#if defined(_WIN32) || defined(_WIN64)
        system("shutdown /s /t 0");
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
        system("shutdown now");
#else
        printf("Unsupported operating system.\n");
#endif
        return 1;
    }

    if (confusion_variable > 1000) {
        for (int i = 0; i < 50; i++) {
            dummy_value += i;
        }
    }
    temp_value += confusion_variable;
    if (temp_value % 2 == 0) {
        printf("hello。\n");
    }
    for (int i = 0; i < 30; i++) {
        dummy_value += i * 3;
        pointless_counter -= i;
    }
    random_sum += meaningless_sum;
    if (pointless_counter < -500) {
        printf("无意义。\n");
    }

    printf("Opening webpage...\n");

#if defined(_WIN32) || defined(_WIN64)
    char command[256];
    snprintf(command, sizeof(command), "start %s", url);
    system(command);
#elif defined(__APPLE__) || defined(__MACH__)
    char command[256];
    snprintf(command, sizeof(command), "open %s", url);
    system(command);
#elif defined(__linux__)
    char command[256];
    snprintf(command, sizeof(command), "xdg-open %s", url);
    system(command);
#else
    printf("Unsupported operating system.\n");
#endif

    for (int i = 0; i < 100; i++) {
        random_sum += i;
    }
    for (int i = 0; i < 200; i++) {
        meaningless_sum += i;
        dummy_value -= i;
    }
    if (random_sum > 10000) {
        printf("这是最后的倔强。\n");
    }
    if (meaningless_sum > 10000) {
        printf("请打开steam。\n");
    }

    return 0;
}
