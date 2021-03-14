//#include "terminal_io.h"
#include <string.h>
#include <stdbool.h>
#include "administration.h"
#include "unity.h"
#include "unity_test_module.h"


// leave resource_detector.h as last include!
#include "resource_detector.h"

// I rather dislike keeping line numbers updated, so I made my own macro to ditch the line number
#define MY_RUN_TEST(func) RUN_TEST(func, 0)

void administration_setUp(void)
{
    // const size_t MaxNrAnimals = 20;
    // size_t* nrAnimals = 0;
    // Animal animals[MaxNrAnimals];
    // Animal a1 = {1, Dog, Male, 12, {1, 2, 3}};
    // Animal a2 = {2, Cat, Female, 4, {4, 3, 2}};
    // Animal a3 = {3, Parrot, Male, 40, {8, 9, 10}};
    // Animal a4 = {4, Dog, Female, 1, {1, 1, 10}};
    // Animal a5 = {5, GuineaPig, Male, 3, {3, 4, 1}};

    // animals[(*nrAnimals)++] = a1;
    // animals[(*nrAnimals)++] = a2;
    // animals[(*nrAnimals)++] = a3;
    // animals[(*nrAnimals)++] = a4;
    // animals[(*nrAnimals)++] = a5;
}

void administration_tearDown(void)
{
    // This is run after EACH test
}

void test_Add_Animal(void)
{
    Animal animal;
    animal.Id = 42;
    animal.Species = Dog;
    animal.Sex = Male;
    animal.DateFound.Day = 07;
    animal.DateFound.Month = 03;
    animal.DateFound.Year = 2021;

    Animal animalArray[6];

    size_t animalArrayLength = 6;
    size_t numberOfAnimalsPresent = 1;

    Animal *animalPtr = &animal;

    int result = addAnimal(animalPtr, 
                            animalArray, 
                            animalArrayLength, 
                            numberOfAnimalsPresent, 
                            &numberOfAnimalsPresent);

    TEST_ASSERT_EQUAL(0, result);
    TEST_ASSERT_EQUAL_MEMORY(&animal, &animalArray[1], sizeof(Animal));
    TEST_ASSERT_EQUAL(2, numberOfAnimalsPresent);
}

void test_Remove_Animal(void)
{
Animal animal_1;
    animal_1.Id = 36;
    animal_1.Species = Dog;
    animal_1.Sex = Male;
    animal_1.DateFound.Day = 07;
    animal_1.DateFound.Month = 03;
    animal_1.DateFound.Year = 1985;

    Animal animal_2;
    animal_2.Id = 30;
    animal_2.Species = Cat;
    animal_2.Sex = Female;
    animal_2.DateFound.Day = 16;
    animal_2.DateFound.Month = 02;
    animal_2.DateFound.Year = 1991;

    Animal animalArray[6];

    size_t animalArrayLength = 6;
    size_t numberOfAnimalsPresent = 0;

    Animal *animalPtr_1 = &animal_1;
    Animal *animalPtr_2 = &animal_2;

    addAnimal(animalPtr_1, animalArray, animalArrayLength, numberOfAnimalsPresent, &numberOfAnimalsPresent);
    addAnimal(animalPtr_2, animalArray, animalArrayLength, numberOfAnimalsPresent, &numberOfAnimalsPresent);

    int result = removeAnimal(animal_1.Id, 
                            animalArray, 
                            numberOfAnimalsPresent, 
                            &numberOfAnimalsPresent);

    TEST_ASSERT_EQUAL(1, result);
    TEST_ASSERT_EQUAL_MEMORY(&animal_2, &animalArray[1], sizeof(Animal));
    TEST_ASSERT_EQUAL(1, numberOfAnimalsPresent);
}

void test_Find_Animal()
{
    Animal animal;
    animal.Id = 42;
    animal.Species = Dog;
    animal.Sex = Male;
    animal.DateFound.Day = 07;
    animal.DateFound.Month = 03;
    animal.DateFound.Year = 2021;

    Animal animalArray[6];

    size_t animalArrayLength = 6;
    size_t numberOfAnimalsPresent = 1;

    Animal *animalPtr = &animal;

    addAnimal(animalPtr,animalArray,animalArrayLength, numberOfAnimalsPresent, &numberOfAnimalsPresent);
    int result = findAnimalById(animal.Id, animalArray, numberOfAnimalsPresent, animalPtr);
    int result_2 = findAnimalById(1, animalArray, numberOfAnimalsPresent, animalPtr);

    TEST_ASSERT_EQUAL(1, result);
    TEST_ASSERT_EQUAL(0,result_2);
}
void run_administration_tests()
{
    UnityRegisterSetupTearDown( administration_setUp, administration_tearDown);

    MY_RUN_TEST(test_Add_Animal);
    MY_RUN_TEST(test_Remove_Animal);
    MY_RUN_TEST(test_Find_Animal);

    UnityUnregisterSetupTearDown();
}
