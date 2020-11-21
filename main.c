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
#include"set.h"

//-----------------------------------------------------------------------------
// CONSTANTS AND TYPES
//-----------------------------------------------------------------------------

int testsFailed = 0;
int testsExecuted = 0;

//-----------------------------------------------------------------------------
// PROTOTYPES
//-----------------------------------------------------------------------------

static void newSetCases(void);
static void deleteSetCases(void)
static void insertCases(void);
static void removeCases(void);
static void areEqualCases(void)
static void areDisjointCases(void)
static void unionOfCases(void)
static void symmetricDiffCases(void)

static void testInsertItem(Set *, int, Boolean);
static void testRemoveItem(Set *, int, Boolean);

int main(void)
{
	insertCases();
	removeCases();
	
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
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR insertItem()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
	printf("----------------------------------------------------------------------------------------------------------\n\n");

} // newSetCases

// -----------------------------------------------------------------------------
// deleteSet
// 
// PURPOSE: calls the testDeleteSet to test normal and edge cases
// -----------------------------------------------------------------------------
static void deleteSetCases(void)
{
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR deleteSetItem()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
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
	
	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
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
	printf("TESTS FOR are areDisjoint()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
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
	printf("TESTS FOR are unionOf()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
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
	printf("TESTS FOR are symmetricDifferenceOf()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
	printf("----------------------------------------------------------------------------------------------------------\n\n");

} // symmetricDiffCases

// -------------------------------------------------------------------------------------------------------
// FUNCTIONS THAT TEST AND PRINT THE RESULTS 
// -------------------------------------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// testNewSet
// 
// PURPOSE: 
// INPUT: 
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// testInsertItem
// 
// PURPOSE: Test if the removeItem's results match the expected results then 
// display the outcome.
// INPUT: int item is the item to be inserted, the expected results (bool) to 
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
