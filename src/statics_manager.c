// #include "statics_manager.h"
// #include<stdio.h>
// #include<string.h>
//
// //定义函数用于数据计算
// void calculateStatistics(Planet planets[], int count, Statistics* stats) {
//
// 	stats->catalogedPlanets = 0;
// 	stats->discoveredPlanets = 0;
// 	stats->observedPlanets = 0;
//
//
// 	for (int i = 0; i < count; i++) {
// 		if (planets[i].isCataloged) {
// 			(stats->catalogedPlanets)++;
// 		}
// 		if (planets[i].isDiscovered) {
// 			(stats->discoveredPlanets)++;
// 		}
// 		if (planets[i].isObserved) {
// 			(stats->observedPlanets)++;
// 		}
// 	}
// }
//
// //定义函数用于打印
// void displayStatistics(const Statistics* stats) {
// 	if (stats == NULL) {
// 		printf("Error: stats pointer is NULL.\n");
// 		return;
// 	}
// 	printf("Cataloged Planets: %d\n", stats->catalogedPlanets);
// 	printf("Discovered Planets: %d\n", stats->discoveredPlanets);
// 	printf("Obsevered Planets: %d\n", stats->observedPlanets);
// }
