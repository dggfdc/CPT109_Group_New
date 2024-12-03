#include "statics_manager.h"
#include "searchplanet_manager.h"
#include <stdio.h>
#include <string.h>

// 查看统计数据模块
void viewStat()
{
	// printf("\nYou have entered the View Statistics module.\n");

	// open the given file
	FILE *file = fopen("planets.dat", "rb");
	if (file == NULL) {
		printf("Unable to open file.\n");
		return;
	}


	int catalogedCount = 0;
	int discoveredCount = 0;
	int observedCount = 0;
	int errCa=0;
	int errDis=0;
	int errObs=0;

	// set a temporary struct to save data
	Planet tempPlanet;

	// read the data saved in the file
	while (fread(&tempPlanet, sizeof(Planet), 1, file) == 1) {


		// check if the input values are valid ( only 0 or 1)
		if (tempPlanet.isCataloged != 0 && tempPlanet.isCataloged != 1) {
			printf("Invalid 'isCataloged' value for planet %s. \n", tempPlanet.name);
			errCa++;//add invalid value
		}
		if (tempPlanet.isDiscovered != 0 && tempPlanet.isDiscovered != 1) {
			printf("Invalid 'isDiscovered' value for planet %s. \n", tempPlanet.name);
			errDis++;
		}
		if (tempPlanet.isObserved != 0 && tempPlanet.isObserved != 1) {
			printf("Invalid 'isObserved' value for planet %s. Skipping this planet.\n", tempPlanet.name);
			errObs++;
		}

		// both numbers
		if (tempPlanet.isCataloged) {
			catalogedCount++;
		}
		if (tempPlanet.isDiscovered) {
			discoveredCount++;
		}
		if (tempPlanet.isObserved) {
			observedCount++;
		}
	}


	fclose(file);

	// print all of the data
	printf("Cataloged Planets: %d\n", catalogedCount-errCa);
	printf("Discovered Planets: %d\n", discoveredCount-errDis);
	printf("Observed Planets: %d\n", observedCount-errObs);
}
