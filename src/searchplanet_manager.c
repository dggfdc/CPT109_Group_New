#include <stdio.h>
#include <string.h>
#include <tgmath.h>
#include "searchplanet_manager.h"

// 按名称搜索恒星
void searchPlanetByName(const char *filename, const char* name)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    Planet planet;
    int found = 0;
    while (fread(&planet, sizeof(Planet), 1, file) == 1)
    {
        if (strcmp(planet.name, name) == 0)
        {
            printf("Found Planet: %s\n", planet.name);
            printf("Type: %s\n", planet.type);
            printf("Size: %.2lf\n", planet.size);
            printf("Distance from Star: %.2lf AU\n", planet.distanceFromStar);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Planet not found.\n");
    }

    fclose(file);
}

// 按类型搜索恒星
void searchPlanetType(const char *filename, const char* type)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    Planet planet;
    int found = 0;
    while (fread(&planet, sizeof(Planet), 1, file) == 1)
    {
        if (strcmp(planet.type, type) == 0)
        {
            printf("Found Planet: %s\n", planet.name);
            printf("Type: %s\n", planet.type);
            printf("Size: %.2lf\n", planet.size);
            printf("Distance from Star: %.2lf AU\n", planet.distanceFromStar);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Planet not found.\n");
    }

    fclose(file);
}

// 按行星尺寸搜索行星
// 结果会输出最接近输入的行星
// void searchPlanetBySize(const char *filename, double size)
// {
//     FILE *file = fopen(filename, "rb");
//     if (file == NULL)
//     {
//         printf("Error opening file for reading.\n");
//         return;
//     }
//
//     Planet planet;
//     int found = 0;
//     while (fread(&planet, sizeof(Planet), 1, file) == 1)
//     {
//         if (planet.size >= size)
//         {
//             printf("Found Planet: %s\n", planet.name);
//             printf("Type: %s\n", planet.type);
//             printf("Size: %.2lf\n", planet.size);
//             printf("Distance from Star: %.2lf AU\n", planet.distanceFromStar);
//             found = 1;
//         }
//     }
//
//     if (!found) {
//         printf("No planets found with size greater than or equal to %.2lf.\n", size);
//     }
//
//     fclose(file);
// }

void searchPlanetBySize(const char *filename, double size)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    Planet planet;
    Planet closestPlanet;
    double closestDifference = -1;
    int found = 0;

    while (fread(&planet, sizeof(Planet), 1, file) == 1)
    {
        double difference = fabs(planet.size - size);
        if (!found || difference < closestDifference)
        {
            closestPlanet = planet;
            closestDifference = difference;
            found = 1;
        }
    }

    if (found)
    {
        printf("Closest Planet: %s\n", closestPlanet.name);
        printf("Type: %s\n", closestPlanet.type);
        printf("Size: %.2lf\n", closestPlanet.size);
        printf("Distance from Star: %.2lf AU\n", closestPlanet.distanceFromStar);
    }
    else
    {
        printf("No planets found in the file.\n");
    }

    fclose(file);
}

// 按行星到恒星的距离搜索行星
// 结果会输出最接近输入的行星
void searchPlanetByDistance(const char *filename, double distance)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    Planet planet;
    int found = 0;
    while (fread(&planet, sizeof(Planet), 1, file) == 1)
    {
        if (planet.distanceFromStar >= distance)
        {
            printf("Found Planet: %s\n", planet.name);
            printf("Type: %s\n", planet.type);
            printf("Size: %.2lf\n", planet.size);
            printf("Distance from Star: %.2lf AU\n", planet.distanceFromStar);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No planets found with distance greater than or equal to %.2lf AU.\n", distance);
    }

    fclose(file);
}

// 显示所有行星信息
void displayAllPlanets(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    Planet planet;
    printf("\nDisplaying all planets:\n");
    while (fread(&planet, sizeof(Planet), 1, file) == 1)
    {
        printf("Name: %s\n", planet.name);
        printf("Type: %s\n", planet.type);
        printf("Size: %.2lf km\n", planet.size);
        printf("Distance from Star: %.2lf AU\n", planet.distanceFromStar);
        printf("\n");
    }

    fclose(file);
}

