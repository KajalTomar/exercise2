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
void testAreEqual(Set *, Set *, Boolean);

int main(void)
{
	newSetCases();
	deleteSetCases();
	insertCases();
	removeCases();
	areEqualCases();	
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
	const int SET_AMOUNT = 6;
	const int SM_SET_SIZE = 5; // small set size
	const int L_SET_SIZE = 10; // large set size

	Set * testSets[SET_AMOUNT];

	int i; // to iterate 
	
	for(i = 0; i < SET_AMOUNT; i++)
	{
		testSets[i] = newSet();
	}

	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR areEqual()\n");

	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	
	// identical sets
	for(i = 0; i < SM_SET_SIZE; i++)
	{
		insertItem(testSets[0], i*SM_SET_SIZE);  // testSet[0] = [0 5 10 15 20]
		insertItem(testSets[1], i*SM_SET_SIZE);  // testSet[1] = [0 5 10 15 20] 
		insertItem(testSets[3], i*SM_SET_SIZE+1); // testSet[3] = [1 6 11 16 21]
	}

	// since the orders are already switched here do NOT switch them in the test function
	printf("Checking if two identical sets are equal...\n");
	testAreEqual(testSets[0], testSets[1], true);
	printf("Checking if the same two identical sets are equal when compared in reverse order ...\n");
	testAreEqual(testSets[1], testSets[0], true);
	
	// unequal sets
	printf("Checking if two completly different sets are equal...\n");
	testAreEqual(testSets[0], testSets[3], false);
	printf("Checking if two completly different sets are equal when compared in reverse order...\n");
	testAreEqual(testSets[3], testSets[0], false);

	// different sizes but one is a part of the other one
	for(i = SM_SET_SIZE; i <= L_SET_SIZE; i++)
	{
		insertItem(testSets[1], i*SM_SET_SIZE); // testSet[1] = [0 5 10 15 20 25 30 35 40 45]
		insertItem(testSets[2], i*SM_SET_SIZE); // testSet[2] = [25 30 35 40 45]
	}
	
	// test one set equals the beggining of another set
	printf("Testing if [0 5 10 15 20] == [0 5 10 15 20 25 30 35 40 45]...\n");
	testAreEqual(testSets[0], testSets[1], false);
	printf("Testing if [0 5 10 15 20 25 30 35 40 45] == [0 5 10 15 20]...\n");
	testAreEqual(testSets[1], testSets[0], false);

	// test when one set equals the end of another set
	printf("Testing if [25 30 35 40 45] == set [0 5 10 15 20 25 30 35 40 45]...\n");
	testAreEqual(testSets[1], testSets[2], false);
	printf("Testing if [0 5 10 15 20 25 30 35 40 45] == set [25 30 35 40 45]...\n");
	testAreEqual(testSets[2], testSets[1], false);

	// test when one set equals another if it's contained in the bigger set
	removeItem(testSets[0], 0);
	removeItem(testSets[0], 5);
	removeItem(testSets[0], 10);
	insertItem(testSets[0], 25);
	insertItem(testSets[0], 30);
	// testSets[0] = [15 20 25 30]

	printf("Testing if [15 20 25 30] == set [0 5 10 15 20 25 30 35 40 45]...\n");
	testAreEqual(testSets[0], testSets[1], false);
	printf("Testing if [0 10 15 20 25 30 35 40 45] == set [15 20 25 30]...\n");
	testAreEqual(testSets[1], testSets[0], false);

	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	
	printf("Testing if a set is uqual to iteslf...\n");
	testAreEqual(testSets[0],testSets[0], true);

	printf("Testing if an empty set is equal to a set with values...\n");
	testAreEqual(testSets[4], testSets[0], false);

	printf("Testing if two emptry sets are equal to itself...\n");
	testAreEqual(testSets[4], testSets[4], true);

	printf("Testing if an emptry sets are equal to a different empty set...\n");
	testAreEqual(testSets[4], testSets[5], true);
	
	for(i = 0; i < SET_AMOUNT; i++)
	{
		deleteSet(testSets[i]);
	}

    testMemLeak();

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
void testAreEqual(Set * setA, Set *setB, Boolean expectedResult)
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


