#ifndef STATICS_MANAGER_H
#define STATICS_MANAGER_H

// 行星结构体
typedef struct {
    char name[50];
    char type[50];
    double size;
    double distanceFromStar;
} Planet;

// 传入参数为 1.行星数组 2.数组的长度 3.要搜索行星的名称
void searchPlanetByName(Planet planets[], int numPlanets, const char* name);
void searchPlanetType(Planet planets[], int numPlanets, const char* type);
void searchPlanetBySize(Planet planets[], int numPlanets, double size);
void searchPlanetByDistance(Planet planets[], int numPlanets, double distance);
void displayAllPlanets(Planet planets[], int numPlanets);

#endif //STATICS_MANAGER_H
