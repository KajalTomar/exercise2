# COMP2150 - A3 - Q2

## Notes for set1.o
	
	* I did not find any bugs in this version.

> Total number of tests executed: 84, 
> Total number of tests passed: 84, 
> Total number of tests failed: 0

---

## Notes for set2.o

	* The insertItem item allows duplicate values to be added. 
	* The removeItem function is not removing anything. 

> Total number of tests executed: 84, 
> Total number of tests passed: 76, 
> Total number of tests failed: 8

---

## Notes for set3.o

	* When comparing an empty set A with a non-empty set B, the program isn't able to
	identify that the two sets are disjoint. 
	
	* All the tests for the symmetricDifferenceOf function that were testing cases
	where the sets had 1 or more items in common failed. The program only seems to be 
	able to identify symmetric differences with disjoint sets.
	
> Total number of tests executed: 84, 
> Total number of tests passed: 70, 
> Total number of tests failed: 14

---

## Notes for set4.o

	* I did not find any bugs in this version.

> Total number of tests executed: 84, 
> Total number of tests passed: 84, 
> Total number of tests failed: 0

---

## Notes for set5.o

	* areEqual function could not _not_ identify when two sets were equal. Since it is able to 
	identify when two sets are not equal everytime, I would check if it always returns false for 
	some reason.
	
	* isDisjoint function could _not_ identify when when two sets were disjoint in many cases. 
	It did successfully identify when functins were not disjoint. For this reason it think it may 
	always returns false.
	
	* Failed every test for unionOf function. Changed the original sets being passed everytime, 
	this _could_ be the reason for failing the test each time as a new set did get created. 
	
	* Failed every test for symmetricDifferenceOf function. Changed the original sets being 
	passed everytime, this _could_ be the reason for failing the test each time as a new set 
	did get created.

> Total number of tests executed: 84, 
> Total number of tests passed: 43, 
> Total number of tests failed: 41

---
