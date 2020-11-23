//------------------------------------------------------------------------------
// NAME: Kajal Tomar
// STUDENT NUMBER: 7793306
// COURSE: COMP2160, SECTION: A01
// INSTRUCTOR: Dr. Mehdi Niknam
// ASSIGNMENT: 3, QUESTION: 2
// 
// REMARKS: This is the automated test suite for the set ADT implementation. 
//-------------------------------------------------------------------------------

#include<stdio.h>
#include<assert.h>
#include"set.h"

//-----------------------------------------------------------------------------
// CONSTANTS AND TYPES
//-----------------------------------------------------------------------------
#define SET_AMOUNT 21
#define SM_SET_SIZE 5 // small set size
#define M_SET_SIZE 10 // med set size
#define XL_SET_SIZE = 10000 // large set size

Set * testSets[SET_AMOUNT];

int testsFailed = 0;
int testsExecuted = 0;

//-----------------------------------------------------------------------------
// PROTOTYPES
//-----------------------------------------------------------------------------

static void newSetCases(void);
static void deleteSetCases(void);
static void insertCases(void);
static void removeCases(void);
static void areEqualCases(void);
static void areDisjointCases(void);
static void unionOfCases(void);
static void symmetricDiffCases(void);

static void testMemLeak(void); // move this to the end
static void testNewSet(Set *, Boolean);
static void testDeleteSet(Set *, Boolean);
static void testInsertItem(Set *, int, Boolean);
static void testRemoveItem(Set *, int, Boolean);
static void testAreEqual(Set *, Set *, Boolean);
static void testAreDisjoint(Set *, Set *, Boolean);
static void testUnionOf(Set *, Set *, Set *);
static void testSymmetricDiff(Set *, Set *, Set *);

static void createComparisonSets(void);
static void deleteComparisonSets(void);

int main(void)
{
	newSetCases();
	deleteSetCases();
	insertCases();
	removeCases();

	createComparisonSets();

	areEqualCases();	
	areDisjointCases();
	unionOfCases();
	symmetricDiffCases();

	deleteComparisonSets();

	//  print out how many tests executes, passes, failed
	printf("\n----------------------------------------------------------------------------------------------------------\n");
	printf("Total number of tests executed: %i\n", testsExecuted);
	printf("Total number of tests passed: %i\n", testsExecuted - testsFailed);
	printf("Total number of tests failed: %i\n", testsFailed);
	printf("----------------------------------------------------------------------------------------------------------\n");
	
	printf("end of processing.");
	return(0);

} //main

// -------------------------------------------------------------------------------------------------------
// FUNCTIONS THAT CALL THE TEST FUNCIONS TO TEST TYPICAL AND EDGE CASES
// -------------------------------------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// newSetCases
// 
// PURPOSE: calls the testNewSet to test normal and edge cases
// -----------------------------------------------------------------------------
static void newSetCases(void)
{
	Set * setA = NULL; 
	Set * setB = NULL;
	
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR newSet()\n");
	
	printf("Testing typical cases.\n\n");
	// test and print out the progress from the typical cases
	
	printf("Creating a new set and the checking if it exists...\n");
	testNewSet(setA, true);
	
	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");

	printf("Creating another set and assigning it to the same pointer as the last one...\n");
	testNewSet(setA, true);

	printf("Creating another set (so two sets exist now)... \n");
	testNewSet(setB, true);
    
    testMemLeak();
	printf("----------------------------------------------------------------------------------------------------------\n\n");
} // newSetCases

// -----------------------------------------------------------------------------
// deleteSet
// 
// PURPOSE: calls the testDeleteSet to test normal and edge cases
// -----------------------------------------------------------------------------
static void deleteSetCases(void)
{
	Set * twoItemSet = newSet();
	Set * singleItemSet = newSet();
	Set * emptySet = newSet();

	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR deleteSetItem()\n");
	
	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	insertItem(twoItemSet, 10);
	insertItem(twoItemSet, 15);
	printf("Deleting a set with two items...\n");
	testDeleteSet(twoItemSet, true);

	insertItem(singleItemSet, 5);
	printf("Deleting a set with only one item...\n");
	testDeleteSet(singleItemSet, true);

	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");

	printf("Deleting an empty set...\n");
	testDeleteSet(emptySet, true);
    
	testMemLeak();
	printf("----------------------------------------------------------------------------------------------------------\n\n");

} // deleteSetCases

// -----------------------------------------------------------------------------
// insertCases
// 
// PURPOSE: calls the testInsertItem to test normal and edge cases
// -----------------------------------------------------------------------------
static void insertCases(void)
{
	Set * testSet = newSet();
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR insertItem()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	testInsertItem(testSet, 5, true);
	
	printf("Inserting an entry that is not unique...\n");
	testInsertItem(testSet, 5, false); // not unique
	
	testInsertItem(testSet, 0, true);
	testInsertItem(testSet, 12, true);
	
	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	// test and print out the progress from the edge cases
	testInsertItem(testSet, -5, true);
	
	removeItem(testSet, 12);
	printf("Removed entry [12].\n");
	testInsertItem(testSet, 12, true);

	printf("Inserting a negative entry that is not unique...\n");
	testInsertItem(testSet, -5, false); // not unique
	
	printf("Inserting the maximum value for an integer in C...\n");
	testInsertItem(testSet, 2147483647, true); // max value for an int 
	
	printf("Inserting the minimum value for an integer in C...\n");
	testInsertItem(testSet, -2147483648, true); // min value for an int 
	
	printf("Inserting the maximum value - 1 for an integer in C...\n");
	testInsertItem(testSet, 2147483646, true); // max value for an int 
    
	deleteSet(testSet);
	testMemLeak();
	printf("----------------------------------------------------------------------------------------------------------\n\n");
	
} // insertCases

// -----------------------------------------------------------------------------
// removeCases
//
// PURPOSE: Calls testRemoveItem to test normal and edge cases
// -----------------------------------------------------------------------------
static void removeCases(void)
{
	Set * testSet = newSet();
	int i; // to iterate
	int totalSets = 5;

	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR removeItem()\n");
	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	for(i = 0; i < totalSets; i++)
	{
		insertItem(testSet, i*totalSets); // [0 5 10 15 20 25]
	}

	testRemoveItem(testSet, 5, true);
	testRemoveItem(testSet, 15, true);
	testRemoveItem(testSet, 10, true);
	
	printf("Removing an item that was not in the table...\n");
	testRemoveItem(testSet, 100, false); // item not in the table

	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	// test and print out the progress from the edge cases
	
	printf("Removing the entry in the first position of the table...\n");
	testRemoveItem(testSet, 0, true); 
	
	printf("Removing the entry in the last position of the table...\n");
	testRemoveItem(testSet, 25, true); 
	
	printf("Removing the last entry left in the table...\n");
	testRemoveItem(testSet, 20, true); 

	printf("Removing an item when the table is empty...\n");
	testRemoveItem(testSet, 12, false); 
	
	deleteSet(testSet);
    testMemLeak();

	printf("----------------------------------------------------------------------------------------------------------\n\n");

} // removeCases

// -----------------------------------------------------------------------------
// areEqualCases
// 
// PURPOSE: calls the testAreEqual to test normal and edge cases
// -----------------------------------------------------------------------------
static void areEqualCases(void)
{
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR areEqual()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	// identical sets
	
	// since the orders are already switched here do NOT switch them in the test function
	printf("Checking if two identical sets are equal...\n");
	testAreEqual(testSets[0], testSets[4], true);
	printf("Checking if the same two identical sets are equal when compared in reverse order ...\n");
	testAreEqual(testSets[4], testSets[0], true);
	
	// unequal sets
	printf("Checking if two completly different sets are equal...\n");
	testAreEqual(testSets[0], testSets[8], false);
	printf("Checking if two completly different sets are equal when compared in reverse order...\n");
	testAreEqual(testSets[8], testSets[0], false);

	// different sizes but one is a part of the other one
	// test one set equals the beggining of another set
	printf("Testing if [0 5 10 15 20] == [0 5 10 15 20 25 30 35 40 45]...\n");
	testAreEqual(testSets[5], testSets[0], false);
	printf("Testing if [0 5 10 15 20 25 30 35 40 45] == [0 5 10 15 20]...\n");
	testAreEqual(testSets[0], testSets[5], false);

	// test when one set equals the end of another set
	printf("Testing if [25 30 35 40 45] == set [0 5 10 15 20 25 30 35 40 45]...\n");
	testAreEqual(testSets[6], testSets[0], false);
	printf("Testing if [0 5 10 15 20 25 30 35 40 45] == set [25 30 35 40 45]...\n");
	testAreEqual(testSets[0], testSets[6], false);

	// test when one set equals another if it's contained in the bigger set
	printf("Testing if [15 20 25 30 35] == set [0 5 10 15 20 25 30 35 40 45]...\n");
	testAreEqual(testSets[7], testSets[0], false);
	printf("Testing if [0 10 15 20 25 30 35 40 45] == set [15 20 25 30]...\n");
	testAreEqual(testSets[0], testSets[7], false);

	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
	printf("Testing if a given set is equal to iteslf...\n");
	testAreEqual(testSets[9],testSets[9], true);

	printf("Testing if an empty set is equal to a set with values...\n");
	testAreEqual(testSets[4], testSets[1], false);

	printf("Testing if an empty set is equal to itself...\n");
	testAreEqual(testSets[1], testSets[1], true);

	printf("Testing if an empty sets are equal to a different empty set...\n");
	testAreEqual(testSets[1], testSets[2], true);
	
	printf("----------------------------------------------------------------------------------------------------------\n\n");

} // areEqualCases

// -----------------------------------------------------------------------------
// areDisjointCases
// 
// PURPOSE: calls the areDisjoint function to test normal and edge cases
// -----------------------------------------------------------------------------
static void areDisjointCases(void)
{
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR areDisjoint()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	// identical sets
	
	// since the orders are already switched here do NOT switch them in the test function
	printf("Checking if two identical sets are disjoint...\n");
	testAreDisjoint(testSets[0], testSets[4], false);
	printf("Checking if the same two identical sets are disjoint when compared in reverse order ...\n");
	testAreDisjoint(testSets[4], testSets[0], false);
	
	// unequal sets
	printf("Checking if two completly different sets are disjoint...\n");
	testAreDisjoint(testSets[0], testSets[8], true);
	printf("Checking if two completly different sets are disjoint when compared in reverse order...\n");
	testAreDisjoint(testSets[8], testSets[0], true);

	// different sizes but one is a part of the other one
	printf("Testing if two sets are disjoint when one set contains all of the first few values of the other set...\n");
	testAreDisjoint(testSets[5], testSets[0], false);
	printf("Testing if two sets are disjoint when one set contains all of the first few values of the other set (in reverse order)...\n");
	testAreDisjoint(testSets[0], testSets[5], false);

	// test when one set equals the end of another set
	printf("Testing if two sets are disjoint when one set contains all of the last few values of the other set...\n");
	testAreDisjoint(testSets[6], testSets[0], false);
	printf("Testing if two sets are disjoint when one set contains all of the last few values of the other set (in reverse order)...\n");
	testAreDisjoint(testSets[0], testSets[6], false);

	// test when one set is disjoint from another if it's contained in the bigger set
	printf("Testing if two sets are disjoint when they contain some middle values in common...\n");
	testAreDisjoint(testSets[7], testSets[0], false);
	printf("Testing if two sets are disjoint when they contain some middle values in common...\n");
	testAreDisjoint(testSets[0], testSets[7], false);

	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
	printf("Testing if a given set is disjoint from iteslf...\n");
	testAreDisjoint(testSets[9],testSets[9], false);

	printf("Testing if an empty set is disjoint from a set with values...\n");
	testAreDisjoint(testSets[4], testSets[1], true);

	printf("Testing if an empty set is disjoint from itself...\n");
	testAreDisjoint(testSets[1], testSets[1], true);

	printf("Testing if an empty sets is disjoint from a different empty set...\n");
	testAreDisjoint(testSets[1], testSets[2], true);
	
	printf("Testing if an empty sets is disjoint from a set with exactly one item...\n");
	testAreDisjoint(testSets[1], testSets[3], true);
	printf("----------------------------------------------------------------------------------------------------------\n\n");
} // areDisjointCases

// -----------------------------------------------------------------------------
// unionOfCases
// 
// PURPOSE: calls the testUnionOf function to test normal and edge cases
// -----------------------------------------------------------------------------
static void unionOfCases(void)
{
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR unionOf()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	// identical sets
	
	// since the orders are already switched here do NOT switch them in the test function
	printf("Finding the union of identical sets...\n");
	testUnionOf(testSets[0], testSets[4], testSets[4]);
	printf("Finding the union of identical sets when compared in reverse order ...\n");
	testUnionOf(testSets[4], testSets[0], testSets[4]);
	
	// disjoint sets
	printf("Finding the union of two completly different sets that are disjoint...\n");
	testUnionOf(testSets[0], testSets[8], testSets[18]);
	printf("Finding the union of are two completly different sets that are disjoint (compared in reverse order)...\n");
	testUnionOf(testSets[8], testSets[0], testSets[18]);

	// different sizes but one is a part of the other one
	printf("Finding the union of two sets where one set contains all of the first few values of the other set...\n");
	testUnionOf(testSets[5], testSets[0], testSets[0]);
	printf("Finding the union of two sets where one set contains all of the first few values of the other set... (compared in reverse order)...\n");
	testUnionOf(testSets[0], testSets[5],  testSets[0]);

	// test when one set equals the end of another set
	printf("Finding the union of two sets where one set contains all of the last few values of the other set...\n");
	testUnionOf(testSets[6], testSets[0], testSets[0]);
	printf("Finding the union of two sets where one set contains all of the last few values of the other set... (compared in reverse order)...\n");
	testUnionOf(testSets[0], testSets[6], testSets[0]);

	// test when one set is contained in the bigger set
	printf("Finding the union of two sets where they contain some middle values in common...\n");
	testUnionOf(testSets[7], testSets[0], testSets[0]);
	printf("Finding the union of two sets where they contain some middle values in common...\n");
	testUnionOf(testSets[0], testSets[7], testSets[0]);

	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
	printf("Finding the union of a given set from iteslf...\n");
	testUnionOf(testSets[9],testSets[9], testSets[9]);

	printf("Finding the union of an empty set and a set with values...\n");
	testUnionOf(testSets[4], testSets[1], testSets[4]);

	//printf("Finding the union of an empty set and itself...\n");
	//testUnionOf(testSets[1], testSets[1], testSets[1]);

	//printf("Finding the union of an empty set and a different empty set...\n");
	//testUnionOf(testSets[1], testSets[2], testSets[1]);
	
	printf("Finding the union of an empty set and a set with exactly one item...\n");
	testUnionOf(testSets[1], testSets[3], testSets[3]);
	
	printf("----------------------------------------------------------------------------------------------------------\n\n");

} // unionOfCases

// -----------------------------------------------------------------------------
// symmetricDiffCases
// 
// PURPOSE: calls the testSymetricDiff function to test normal and edge cases
// -----------------------------------------------------------------------------
static void symmetricDiffCases(void)
{
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR symetricDiff()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	// identical sets
	
	// since the orders are already switched here do NOT switch them in the test function
	printf("Finding the symmetric difference of identical sets...\n");
	testSymmetricDiff(testSets[0], testSets[4], testSets[1]);
	printf("Finding the union of identical sets when compared in reverse order ...\n");
	testSymmetricDiff(testSets[4], testSets[0], testSets[1]);
	
	// disjoint sets
	printf("Finding the symmetric difference of two completly different sets that are disjoint...\n");
	testSymmetricDiff(testSets[0], testSets[8], testSets[15]);
	printf("Finding the symmetric difference of two completly different sets that are disjoint (compared in reverse order)...\n");
	testSymmetricDiff(testSets[8], testSets[0], testSets[15]);

	// different sizes but one is a part of the other one
	printf("Finding the symmetric difference of two sets where one set contains all of the first few values of the other set...\n");
	testSymmetricDiff(testSets[5], testSets[0], testSets[6]);
	printf("Finding thesymmetric difference of two sets where one set contains all of the first few values of the other set... (compared in reverse order)...\n");
	testSymmetricDiff(testSets[0], testSets[5], testSets[6]);

	// test when one set equals the end of another set
	printf("Finding the symmetric difference of two sets where one set contains all of the last few values of the other set...\n");
	testSymmetricDiff(testSets[6], testSets[0], testSets[5]);
	printf("Finding the symmetric difference of two sets where one set contains all of the last few values of the other set... (compared in reverse order)...\n");
	testSymmetricDiff(testSets[0], testSets[6], testSets[5]);

	// test when one set is contained in the bigger set
	printf("Finding the symmetric difference of two sets where they contain some middle values in common...\n");
	testSymmetricDiff(testSets[7], testSets[0], testSets[16]);
	printf("Finding the symmetric difference of two sets where they contain some middle values in common...\n");
	testSymmetricDiff(testSets[0], testSets[7], testSets[16]);

	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
	printf("Finding the symmetric difference of a given set from iteslf...\n");
	testSymmetricDiff(testSets[9],testSets[9], testSets[1]);

	printf("Finding the symmetric difference of an empty set and a set with values...\n");
	testSymmetricDiff(testSets[4], testSets[1], testSets[4]);

	printf("Finding the symmetric difference of an empty set and itself...\n");
	testSymmetricDiff(testSets[1], testSets[1], testSets[1]);

	printf("Finding the symmetric difference of an empty set and a different empty set...\n");
	testSymmetricDiff(testSets[1], testSets[2], testSets[1]);
	
	printf("Finding the symmetric difference of an empty set and a set with exactly one item...\n");
	testSymmetricDiff(testSets[1], testSets[3], testSets[3]);
	
	printf("----------------------------------------------------------------------------------------------------------\n\n");

} // symmetricDiffCases

// -------------------------------------------------------------------------------------------------------
// FUNCTIONS THAT TEST AND PRINT THE RESULTS 
// -------------------------------------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// testMemLeak
// 
// PURPOSE: Tests if a function or case created a memory leak in the program
// and the shows the results. 
// -----------------------------------------------------------------------------
static void testMemLeak(void)
{
	printf("---------------------------\n");
	if(validateMemUse())
	{
		printf("There was no memory leak created!\n");
	}
	else 
	{
		printf("A memory leak was created. :(\n");
	}
}

// -----------------------------------------------------------------------------
// testNewSet
// 
// PURPOSE: Test if the newSet function creats (or or does not create) sets as
// we expect. Display the outcome.
// INPUT: Pointer to the new set being created, the expected result (Boolean)
// to compare the results with.
// -----------------------------------------------------------------------------
static void testNewSet(Set * set, Boolean expectedResult)
{
	Boolean setExists = false;
	
	set = newSet();

	if (set)
	{
		setExists = true;
	}

	if(setExists == expectedResult)
	{
		if(setExists)
		{
			printf("Passed! A new set was created just like we expected.\n\n");
		}
		else 
		{
			printf("Passed! As expected, no new sets were created.\n\n");
		}
	}
	else 
	{
		if(setExists)
		{
			printf("FAILED: A new set was created but we did *not* expect this.\n\n");
		}
		else
		{
			printf("FAILED: A new set was *not* created. We expected for it to be created. \n\n");
		}

		testsFailed++;
	}
	
	deleteSet(set); 

	testsExecuted++;
} // testNewSet

// -----------------------------------------------------------------------------
// testDeleteSet
// PURPOSE: Test if the deleteSet function function deletes sets as expected. 
// Dispay the expected and the true outcome. 
// INPUT: A pointer to the Set to delete, the expected Result (Boolean)
// -----------------------------------------------------------------------------
static void testDeleteSet(Set * deleteMe, Boolean expectedResult)
{
	Boolean gotDeleted = false;

	if (deleteSet(deleteMe) == NULL)
	{
		gotDeleted = true;
	}

	if(gotDeleted == expectedResult)
	{
		if(gotDeleted)
		{
			printf("Passed! The set was delete as expected.\n\n");
		}
		else
		{
			printf("Passed! As expected, the set ws *not* deleted.\n\n");
		}
	}
	else 
	{
		if(gotDeleted)
		{
			printf("FAILED: We didn't expect anything to get deleted but something was deleted according to the function.\n\n");
		}
		else
		{
			printf("FAILED: We expected the set to get deleted but it wasn't.\n\n");
		}
	}

} //testDeleteSet

// -----------------------------------------------------------------------------
// testInsertItem
// 
// PURPOSE: Test if the removeItem function's results match the expected results 
// then display the outcome.
// INPUT: int item is the item to be inserted, the expected results (Boolean) to 
// test against
// -----------------------------------------------------------------------------
static void testInsertItem(Set* test, int item, Boolean expectedResult)
{
	Boolean testResult = insertItem(test, item);
	
	printf("Inserting %i...\n", item);
	
	if(testResult == expectedResult)
	{
		if(testResult)
		{
			printf("Passed! %i is a valid entry that was inserted successfully in the table.\n\n", item);
		}
		else
		{
			printf("Passed! %i is a *not* a valid (not unique) entry so it was *not* inserted in the table.\n\n", item);
		}
	}
	else 
	{
		if (testResult && !expectedResult)
		{
			printf("FAILED: I thought that the value would *not* be added to the table but it was added.\n\n");
		} 
		else 
		{
			printf("FAILED: I thought that the value would be added to the table but it was *not* added.\n\n");
		}
		testsFailed++;
	}

	testsExecuted++;
} // testInsertItem

// -----------------------------------------------------------------------------
// testRemoveItem
//
// PURPOSE: Test if the removeItem's results match the expected results then 
// display the outcome
// INPUT: int item is the item to be removed, the expected reults (bool) to
// test against
// -----------------------------------------------------------------------------
static void testRemoveItem(Set * testSet, int item, Boolean expectedResult)
{

	Boolean testResult = removeItem(testSet, item);

	printf("Removing %i...\n", item);
	
	if(testResult == expectedResult)
	{
		if(testResult)
		{
			printf("Passed! %i was successfully removed from the table.\n\n", item);
		}
		else
		{
			printf("Passed! %i was not removed from the table (and we didn't expect it to).\n\n", item);
		}
	}
	else 
	{
		if(testResult && !expectedResult)
		{
			printf("FAILED: I thought the %i would *not* be removed, but something was removed...\n\n", item);		
		}
		else
		{
			printf("FAILED: I thought the %i would be removed, but it was *not*\n\n", item);		
		}
		testsFailed++;
	}
	
	testsExecuted++;

} // testRemoveItem


// -----------------------------------------------------------------------------
// testAreEqual
// 
// PURPOSE: Test if the areEqual function's results match the expected results,
// then display the outcome.  
// INPUT: setA and setB to compare, the expected result (Boolean) to test 
// against.
// -----------------------------------------------------------------------------
static void testAreEqual(Set * setA, Set *setB, Boolean expectedResult)
{
	Boolean equalSets = areEqual(setA, setB);
	
	if(equalSets == expectedResult)
	{
		if(equalSets)
		{
			printf("Passed! The two sets are equal, as expected!\n\n");
		}
		else 
		{
			printf("Passed! The two sets are *not* equal, as expected!\n\n");
		}
	}
	else
	{
		if(equalSets)
		{
			printf("FAILED: The function says the tests are equal, even though they are *not* equal.\n\n");
		}
		else
		{
			printf("FAILED: The function says the tests are *not* equal, even though they are.\n\n");
		}
		testsFailed++;
	}

	testsExecuted++;

} // testAreEqual


// -----------------------------------------------------------------------------
// testAreDisjoint
// 
// PURPOSE: Test if the areDisjoint function's results match the expected results,
// then display the outcome.  
// INPUT: setA and setB to compare, the expected result (Boolean) to test 
// against.
// -----------------------------------------------------------------------------
static void testAreDisjoint(Set * setA, Set *setB, Boolean expectedResult)
{
	Boolean disjointSets = areDisjoint(setA, setB);
	
	if(disjointSets == expectedResult)
	{
		if(disjointSets)
		{
			printf("Passed! The two sets are disjoint, as expected!\n\n");
		}
		else 
		{
			printf("Passed! The two sets are *not* disjoint, as expected!\n\n");
		}
	}
	else
	{
		if(disjointSets)
		{
			printf("FAILED: The function says the tests are disjoint, even though they are *not* disjoint.\n\n");
		}
		else
		{
			printf("FAILED: The function says the tests are *not* disjoint, even though they are.\n\n");
		}
		testsFailed++;
	}

	testsExecuted++;
	
} //testAreDisjoint

// -----------------------------------------------------------------------------
// testUnionOf
// 
// PURPOSE: Test if the unionOf function's results match the expected results,
// then display the outcome.  
// INPUT: setA and setB to find the union from, the expected result (Boolean) 
// to test against.
// -----------------------------------------------------------------------------
static void testUnionOf(Set * setA, Set * setB, Set * expectedSet)
{	
	Boolean changed = false;
	
	Set * setACopy = newSet();
	Set * setBCopy = newSet();
	Set * unionSet = newSet();
	
	setACopy = setA;
	setBCopy = setB;
	
	unionSet = unionOf(setA, setB);
	
	if(!areEqual(setA, setACopy) ||  !areEqual(setB, setBCopy))
	{
		changed = false;
		printf("One of the original sets was changed by the unionOf function!\n");	
	}
	
	if(areEqual(unionSet,expectedSet) && !changed)
	{
		if(unionSet)
		{
			printf("Passed! A valid new union set was created, as expected!\n\n");
		}
		else 
		{
			printf("Passed! No union set was created, as expected!\n\n");
		}
	}
	else
	{
		if(unionSet && !expectedSet)
		{
			printf("FAILED: The function created a union set, but we didn't expect it to..\n\n");
		}
		else if (!unionSet && expectedSet)
		{
			printf("FAILED: The function failed to create a union set even it should have.\n\n");
		}
		else 
		{
			printf("FAILED: The union set created by the function is wrong.\n\n");	
		}
		testsFailed++;
	}

	testsExecuted++;
	   
	deleteSet(unionSet);
} // testUnionof

// -----------------------------------------------------------------------------
// testUnionOf
// 
// PURPOSE: Test if the symmetricDifferenceOf function's results match the 
// expected results then display the outcome.  
// INPUT: setA and setB to find the symmetric difference of, the expected 
// result (Boolean) to compare the results with.
// -----------------------------------------------------------------------------
static void testSymmetricDiff(Set * setA, Set *setB, Set * expectedSet)
{	
	Boolean notChanged = true;
	
	Set * setACopy = newSet();
	Set * setBCopy = newSet();
	Set * symmetricDiff = newSet();
	
	setACopy = setA;
	setBCopy = setB;
	symmetricDiff = symmetricDifferenceOf(setA, setB);
	
	if(areEqual(setA, setACopy) && areEqual(setB, setB))
	{
		notChanged = false;
		printf("One of the original sets was changed by the symmetricDifferenceOf function!\n");	
	}
	
	if(areEqual(symmetricDiff, expectedSet) && !notChanged)
	{
		if(symmetricDiff)
		{
			printf("Passed! A valid new symmetric difference set was created, as expected!\n\n");
		}
		else 
		{
			printf("Passed! The two sets were equal to each other therefore no symmetric difference set was created. As expected!\n\n");
		}
	}
	else
	{
		if(symmetricDiff && !expectedSet)
		{
			printf("FAILED: The function created a symmetric difference set, even though the sets are equal.\n\n");
		}
		else if (!symmetricDiff && expectedSet)
		{
			printf("FAILED: The function failed to create a  symmetric difference set.\n\n");
		}
		else 
		{
			printf("FAILED: The symmetric difference set created by the function is wrong.\n\n");	
		}
		testsFailed++;
	}

	testsExecuted++;
	   
	 deleteSet(symmetricDiff);
	
} //testSymmetricDiff
// -----------------------------------------------------------------------------
// createComparisonSets
// 
// PURPOSE: Creates a bunch of sets we can use for comparison.
//  
// -----------------------------------------------------------------------------
static void createComparisonSets(void)
{
	/***************************************************************************

	INDEX = DESCRIPTION IN COMPARISON TO GENERAL SET = THE SET 
	
	[0] = general = [0 5 10 15 20 25 30 35 40 45] 
	[1] = empty01 = [] 
	[2] = empty02 = [] 
	[3] = onlyOneItem = [123] 
	[4] = indenticalToGeneral = [0 5 10 15 20 25 30 35 40 45] 
	[5] = onlyFirsthalf = [0 5 10 15 20]
	[6] = onlyLastHalf = [25 30 35 40 45] 
	[7] = middleValues = [15 20 25 30 35]
	[8] = unique01 = [1 6 11 16 21 26 31 36 41 46] 
	[9] = unique02 = [2 7 12 17 22 27 32 37 42 47] 
	[10] = singleDiffVal = [0 5 10 15 22 25 30 35 40 45] 
	[11] = FirstValDiff = [2 5 10 15 20 25 30 35 40 45] 
	[12] = LastValDiff = [0 5 10 15 20 25 30 35 40 47] 
	[13] = firstHalfSame = [0 5 10 15 20 908 445 66 76 23] 
	[14] = lastHalfSame = [908 445 66 76 23 25 30 35 40 45] 
	[15] = [0] union [1] = [0 5 10 15 20 25 30 35 40 45 1 6 11 16 21 26 31 36 41 46]
	[16] = [0] Symmetric Difference [7] = [0 5 10 40 45]
	[17] = [0] Symmetric Differece [10] = [22] 
	[18] = [0] Symmetric Differece [11] = [2] 
	[19] = [0] Symmetric Differece [12] = [47]
	[20] = signify expected empty = [-1] 
	****************************************************************************/
	
	int i; // to iterate

	for(i = 0; i < SET_AMOUNT; i++)
	{
		testSets[i] = newSet();
	}
	
	insertItem(testSets[20],-1); // signify expected empty
	insertItem(testSets[3],123); // unique
	insertItem(testSets[17],22); 
	insertItem(testSets[18],2); 
	insertItem(testSets[18],47); 
	
	for(i = 0; i < M_SET_SIZE; i++)
	{
		insertItem(testSets[0],i*SM_SET_SIZE); // general
		insertItem(testSets[4],i*SM_SET_SIZE); // indentical to general
		insertItem(testSets[8],i*SM_SET_SIZE+1); // unique01
		insertItem(testSets[9],i*SM_SET_SIZE+2); // unique02
		insertItem(testSets[15],i*SM_SET_SIZE); // generalUnionUnique01 
		if (i == 0)
		{
			insertItem(testSets[11],i*SM_SET_SIZE+2); // FirstValDiff;
		}
		else if (i == 4)
		{
			insertItem(testSets[10],i*SM_SET_SIZE+2); // singleDiffVal;
		}
		else if (i == M_SET_SIZE-1)
		{
			insertItem(testSets[12],i*SM_SET_SIZE+2); // LastValDiff;
		}
		else 
		{
			insertItem(testSets[10],i*SM_SET_SIZE); // singleDiffVal;
			insertItem(testSets[11],i*SM_SET_SIZE); // FirstValDiff;
			insertItem(testSets[12],i*SM_SET_SIZE); // LastValDiff;
		}
		
		
	}
	
	for(i = 0; i < SM_SET_SIZE; i++)
	{
		insertItem(testSets[5],i*SM_SET_SIZE); // onlyFirsthalf
		insertItem(testSets[13],i*SM_SET_SIZE); // firsthalfSame
		insertItem(testSets[14],i*SM_SET_SIZE+3); // lasthalfSame
		insertItem(testSets[15],i*SM_SET_SIZE+1); // generalUnionUnique01 
	}
	
	
	
	for(i = SM_SET_SIZE; i <= M_SET_SIZE; i++)
	{
		insertItem(testSets[6],i*SM_SET_SIZE); // onlyLastHalf
		insertItem(testSets[14],i*SM_SET_SIZE); // lasthalfSame
		insertItem(testSets[13],i*SM_SET_SIZE+3); // firsthalfSame
		insertItem(testSets[15],i*SM_SET_SIZE+1); // generalUnionUnique01 
	}
	
	
	// middleValues
	insertItem(testSets[7], 15);
	insertItem(testSets[7], 20);
	insertItem(testSets[7], 25);
	insertItem(testSets[7], 30);
	insertItem(testSets[7], 35);
	
	// OriginalMinusMiddle
	insertItem(testSets[16], 0);
	insertItem(testSets[16], 5);
	insertItem(testSets[16], 10);
	insertItem(testSets[16], 40);
	insertItem(testSets[16], 45);
	
} // createComparisonSets

// -----------------------------------------------------------------------------
// deleteComparisonSets
// 
// PURPOSE: Deletes all the comparison sets.
// -----------------------------------------------------------------------------
static void deleteComparisonSets(void)
{
	int i; // to iterate 

	for(i = 0; i < SET_AMOUNT; i++)
	{
		deleteSet(testSets[i]);
	}	
	assert(validateMemUse);
} // deleteComparisonSets

