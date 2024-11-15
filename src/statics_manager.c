#include <stdio.h>
#include <string.h>
#include <tgmath.h>
#include "statics_manager.h"

// 按名称搜索行星
void searchPlanetByName(Planet planets[], int numPlanets, const char* name) {
    int found = 0;
    for (int i = 0; i < numPlanets; i++) {
        if (strcmp(planets[i].name, name) == 0) {
            printf("Found Planet: %s\n", planets[i].name);
            printf("Type: %s\n", planets[i].type);
            printf("Size: %.2lf\n", planets[i].size);
            printf("Distance from Star: %.2lf AU\n", planets[i].distanceFromStar);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Planet not found.\n");
    }
}

// 按类型搜索行星
void searchPlanetType(Planet planets[], int numPlanets, const char* type) {
    int found = 0;
    for (int i = 0; i < numPlanets; i++) {
        if (strcmp(planets[i].type, type) == 0) {
            printf("Found Planet: %s\n", planets[i].name);
            printf("Type: %s\n", planets[i].type);
            printf("Size: %.2lf\n", planets[i].size);
            printf("Distance from Star: %.2lf AU\n", planets[i].distanceFromStar);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Planet not found.\n");
    }
}

// 按尺寸搜索行星
// 结果会输出最接近输入的行星
void searchPlanetBySize(Planet planets[], int numPlanets, double size) {
    double minDiff = __DBL_MAX__;  // 设置一个很大的初始差值
    int closestIndex = -1;

    for (int i = 0; i < numPlanets; i++) {
        double diff = fabs(planets[i].size - size);  // 计算尺寸差的绝对值
        if (diff < minDiff) {
            minDiff = diff;
            closestIndex = i;
        }
    }

    if (closestIndex != -1) {
        printf("Closest Planet by Size: %s\n", planets[closestIndex].name);
        printf("Type: %s\n", planets[closestIndex].type);
        printf("Size: %.2lf\n", planets[closestIndex].size);
        printf("Distance from Star: %.2lf AU\n", planets[closestIndex].distanceFromStar);
    } else {
        printf("No planets found.\n");
    }
}

// 按行星到恒星的距离搜索行星
// 结果会输出最接近输入的行星
void searchPlanetByDistance(Planet planets[], int numPlanets, double distance) {
    double minDiff = __DBL_MAX__;  // 设置一个很大的初始差值
    int closestIndex = -1;

    for (int i = 0; i < numPlanets; i++) {
        double diff = fabs(planets[i].distanceFromStar - distance);  // 计算距离差的绝对值
        if (diff < minDiff) {
            minDiff = diff;
            closestIndex = i;
        }
    }

    if (closestIndex != -1) {
        printf("Closest Planet by Distance: %s\n", planets[closestIndex].name);
        printf("Type: %s\n", planets[closestIndex].type);
        printf("Size: %.2lf\n", planets[closestIndex].size);
        printf("Distance from Star: %.2lf AU\n", planets[closestIndex].distanceFromStar);
    } else {
        printf("No planets found.\n");
    }
}

// 显示所有行星信息
void displayAllPlanets(Planet planets[], int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        printf("Planet %d: %s\n", i + 1, planets[i].name);
        printf("Type: %s, Size: %.2lf, Distance from Star: %.2lf AU\n", planets[i].type, planets[i].size, planets[i].distanceFromStar);
    }
}

