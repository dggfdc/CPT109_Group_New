#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "planet_manager.h"



#define MAX_PLANETS 100
#define NAME_LENGTH 50
#define TYPE_LENGTH 20
#define SIZE_LENGTH 20
#define RELEVANT_DATA_LENGTH 100
#define RELEVANT_DATA_COUNT 5



Planeta catalogue[MAX_PLANETS];
int planetCount = 0;

void addPlanet() {
    if (planetCount >= MAX_PLANETS) {
        printf("Catalogue is full. Cannot add more planets.\n");
        return;
    }

    Planeta newPlanet;
    printf("Enter planet name: ");
    scanf("%49s", newPlanet.name);
    printf("Enter planet type: ");
    scanf("%19s", newPlanet.type);
    printf("Enter planet size: ");
    scanf("%19s", newPlanet.size);
    printf("Enter planet's distance from star in astronomical units (AU): ");
    scanf("%lf", &newPlanet.distanceFromStar);
    printf("Enter relevant data points:");
    scanf("%19s", newPlanet.relevantData);

    catalogue[planetCount++] = newPlanet;
    printf("Planet added successfully.\n");
}

void editPlanet() {
    char planetName[NAME_LENGTH];
    printf("Enter the name of the planet to edit: ");
    scanf("%49s", planetName);
    getchar(); // 清空换行符

    for (int i = 0; i < planetCount; i++) {
        if (strcmp(catalogue[i].name, planetName) == 0) {
            printf("Enter new name: ");
            char newName[NAME_LENGTH];
            fgets(newName, NAME_LENGTH, stdin);
            if (newName[0] != '\n') {
                newName[strcspn(newName, "\n")] = '\0'; // 移除换行符
                strcpy(catalogue[i].name, newName);
            }

            printf("Enter new type: ");
            char newType[TYPE_LENGTH];
            fgets(newType, TYPE_LENGTH, stdin);
            if (newType[0] != '\n') {
                newType[strcspn(newType, "\n")] = '\0'; // 移除换行符
                strcpy(catalogue[i].type, newType);
            }

            printf("Enter new size: ");
            char newSize[SIZE_LENGTH];
            fgets(newSize, SIZE_LENGTH, stdin);
            if (newSize[0] != '\n') {
                newSize[strcspn(newSize, "\n")] = '\0'; // 移除换行符
                strcpy(catalogue[i].size, newSize);
            }

            printf("Enter new distance from star in AU: ");
            char distanceInput[20];
            fgets(distanceInput, 20, stdin);
            if (distanceInput[0] != '\n') {
                double newDistance = atof(distanceInput);
                if (newDistance != 0) catalogue[i].distanceFromStar = newDistance;
            }

            printf("Enter new relevant data point: ");
            char newData[RELEVANT_DATA_LENGTH];
            fgets(newData, RELEVANT_DATA_LENGTH, stdin);
            if (newData[0] != '\n') {
                newData[strcspn(newData, "\n")] = '\0'; // 移除换行符
                strcpy(catalogue[i].relevantData[0], newData); // 存储在第一个位置
            }

            printf("Planet edited successfully.\n");
            return;
        }
    }
    printf("Planet not found.\n");
}


void removePlanet() {
    char planetName[NAME_LENGTH];
    printf("Enter the name of the planet to remove: ");
    scanf("%49s", planetName);

    for (int i = 0; i < planetCount; i++) {
        if (strcmp(catalogue[i].name, planetName) == 0) {
            for (int j = i; j < planetCount - 1; j++) {
                catalogue[j] = catalogue[j + 1];
            }
            planetCount--;
            printf("Planet removed successfully.\n");
            return;
        }
    }
    printf("Planet not found.\n");
}

void displayCatalogue() {
    printf("Planet Catalogue:\n");
    for (int i = 0; i < planetCount; i++) {
        printf("Name: %s, Type: %s, Size: %s, Distance from star: %.2f AU, Relevant Data:\n",
               catalogue[i].name, catalogue[i].type, catalogue[i].size, catalogue[i].distanceFromStar);
        for (int j = 0; j < RELEVANT_DATA_COUNT; j++) {
            printf("  - %s\n", catalogue[i].relevantData[j]);
        }
    }
}

void planet_manager() {
    char choice;
    do {
        printf("\nManage Planet Information\n");
        printf("1. Add a planet\n");
        printf("2. Edit a planet\n");
        printf("3. Remove a planet\n");
        printf("4. Display catalogue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", &choice);

        switch (choice) {
            case '1':
                addPlanet();
                break;
            case '2':
                editPlanet();
                break;
            case '3':
                removePlanet();
                break;
            case '4':
                displayCatalogue();
                break;
            case '5':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return;
}
