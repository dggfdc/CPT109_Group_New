#include "statics_manager.h"
#include "searchplanet_manager.h"
#include <stdio.h>
#include <string.h>

// 查看统计数据模块
void viewStat()
{
    printf("\nYou have entered the View Statistics module.\n");

    // open the given file
    FILE *file = fopen("planets.dat", "rb");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    // initilize the amount catagorized
    int catalogedCount = 0;
    // initilize the amount discovered
    int discoveredCount = 0;
    // initilize the amount observed
    int observedCount = 0;

    // set a temporary struct to save data
    Planet tempPlanet;

    // read the data saved in the file
    while (fread(&tempPlanet, sizeof(Planet), 1, file) == 1) {
        if (tempPlanet.isCataloged) catalogedCount++;
        if (tempPlanet.isDiscovered) discoveredCount++;
        if (tempPlanet.isObserved) observedCount++;
    }


    fclose(file);

    // print all of the data
    printf("Cataloged Planets: %d\n", catalogedCount);
    printf("Discovered Planets: %d\n", discoveredCount);
    printf("Observed Planets: %d\n", observedCount);
}