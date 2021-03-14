#include "administration.h"
//#include "terminal_io.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// leave resource_detector.h as last include!
#include "resource_detector.h"

int addAnimal(
            const Animal* animalPtr, Animal* animalArray,
            size_t animalArrayLength, size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent)
{
    if (animalPtr == NULL || animalArray == NULL || newNumberOfAnimalsPresent  == NULL || numberOfAnimalsPresent >= 20)
    {
        return -1;
    }
    animalArray[numberOfAnimalsPresent] = *animalPtr;    
    *newNumberOfAnimalsPresent = numberOfAnimalsPresent + 1;

    return 0;
}

int removeAnimal(
            int animalId, Animal* animalArray,
            size_t numberOfAnimalsPresent,
            size_t* newNumberOfAnimalsPresent)
{
    if(animalId == 0)
    {
        return -1;
    }
    for(int i = 0; i <= numberOfAnimalsPresent; i++)
    {
        if(animalArray[i].Id == animalId)
        {
            for(i=animalId-1; i<numberOfAnimalsPresent-1; i++)
            {
            animalArray[i] = animalArray[i+1];
            *newNumberOfAnimalsPresent = numberOfAnimalsPresent -1;
            }
            return *newNumberOfAnimalsPresent;
            
        }
    }
    return 0;
}

int findAnimalById(
            int animalId, const Animal* animalArray,
            size_t numberOfAnimalsPresent, Animal* animalPtr)
{
    if(animalId == 0)
    {
        return -1;
    }
     for(int i = 0; i <=numberOfAnimalsPresent; i++)
         if(animalArray[i].Id == animalId)
         {
             *animalPtr = animalArray[i];
             return 1;
         }
     
    return 0;
}

/*-------------------------------------------------------------------------------*/
int sortAnimalsByAge(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    Animal temp;
    for(int i = 0; i < numberOfAnimalsPresent; i++)
    {
        for(int j = i +1; j <numberOfAnimalsPresent; j++)
        {
            if(animalArray[i].Age > animalArray[j].Age)
            {
                temp = animalArray[i];
                animalArray[i] = animalArray[j];
                animalArray[j] = temp;
            }
        }
    }
  //      printAnimals(animalArray, numberOfAnimalsPresent);
    
    return 0;
}

int sortAnimalsByYearFound(
            Animal* animalArray, size_t numberOfAnimalsPresent)
{
    Animal temp;
    for (int i = 0; i < numberOfAnimalsPresent; i++)
    {
        for (int j = i + 1; j < numberOfAnimalsPresent; j++)
        {
            if (animalArray[i].DateFound.Year > animalArray[j].DateFound.Year)
            {
                temp = animalArray[i];
                animalArray[i] = animalArray[j];
                animalArray[j] = temp;
            }
        }
    }
 //   printAnimals(animalArray, numberOfAnimalsPresent);

    return 0;
}

int sortAnimalsBySex(Animal* animalArray, size_t numberOfAnimalsPresent)
{
    Animal temp;
    for (int i = 0; i < numberOfAnimalsPresent; i++)
    {
        for (int j = i + 1; j < numberOfAnimalsPresent; j++)
        {
            if (animalArray[i].Sex > animalArray[j].Sex)
            {
                temp = animalArray[i];
                animalArray[i] = animalArray[j];
                animalArray[j] = temp;
            }
        }
    }
 //   printAnimals(animalArray, numberOfAnimalsPresent);

    return 0;
}
