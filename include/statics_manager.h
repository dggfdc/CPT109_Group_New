#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

#include"search_manager.h" //包含search_manager.h

void calculateStatistics(Planet planets[], int count, Statistics* stats);
void displayStatistics(const Statistics* stats);


//定义一个结构体用于储存
typedef struct {
	int catalogedPlanets;
	int discoveredPlanets;
	int observedPlanets;
}Statistics;

#endif //SEARCH_MANAGER_H
