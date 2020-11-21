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

void insertCases(void);

void testInsertItem(Set *, int, Boolean);

int main(void)
{
	insertCases();

	printf("end of processing.");
	return(0);

} //main

void insertCases(void)
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
void removeCases(void)
{
	
	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("TESTS FOR removeItem()\n");
	// test and print out the progress from the typical cases
	printf("Testing typical cases.\n\n");
	display();

	testRemoveItem(5, true);
	display();
	testRemoveItem(12, true);
	display();
	testRemoveItem(-5, true);
	display();
	
	printf("Removing an item that was not in the table...\n");
	testRemoveItem(100, false); // item not in the table
	display();
	
	printf("---------------------------\n");
	printf("Testing edge cases.\n\n");
	// test and print out the progress from the edge cases
	
	printf("Removing the entry in the first position of the table...\n");
	testRemoveItem(2147483647, true); 
	display();
	
	printf("Removing the entry in the last position of the table...\n");
	testRemoveItem(-2147483648, true); 
	display();
	
	printf("Removing the last entry left in the table...\n");
	testRemoveItem(0, true); 
	display();
	
	printf("Removing an item when the table is empty...\n");
	testRemoveItem(12, false); 
	display();
	
	printf("----------------------------------------------------------------------------------------------------------\n\n");

} // removeCases

void testInsertItem(Set* test, int item, Boolean expectedResult)
{
	Boolean testResult = insertItem(test, item);
	
	printf("Inserting %i...\n", item);
	
	if(testResult == expectedResult)
	{
		if(testResult)
		{
			printf("Passed! %i is a valid entry that was inserted successfully in the table.\n", item);
		}
		else
		{
			printf("Passed! %i is a *not* a valid (not unique) entry so it was *not* inserted in the table.\n", item);
		}
	}
	else 
	{
		if (testResult && !expectedResult)
		{
			printf("FAILED: I thought that the value would *not* be added to the table but it was added.\n");
		} 
		else 
		{
			printf("FAILED: I thought that the value would be added to the table but it was *not* added.\n");
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
void testRemoveItem(int item, bool expectedResult)
{

	bool testResult = removeItem(item);

	printf("Removing %i...\n", item);
	
	if(testResult == expectedResult)
	{
		if(testResult)
		{
			printf("Passed! %i was successfully removed from the table.\n", item);
		}
		else
		{
			printf("Passed! %i was not removed from the table (and we didn't expect it to).\n", item);
		}
	}
	else 
	{
		if(testResult && !expectedResult)
		{
			printf("FAILED: I thought the %i would *not* be removed, but something was removed...\n", item);		
		}
		else
		{
			printf("FAILED: I thought the %i would be removed, but it was *not*\n", item);		
		}
		testsFailed++;
	}
	
	testsExecuted++;

} // testRemoveItem
