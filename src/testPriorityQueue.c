#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueueAPI.h"

void printInteger ( void *toBePrinted )
{
	int *tBP = ( int * )toBePrinted;
	printf( "%d\n", *tBP );
}

void deleteInteger ( void *toBeDeleted )
{
	free ( toBeDeleted );
	toBeDeleted = NULL;
}

int compareData ( const void *first, const void *second )
{
	const int f = *( int * )first;
	const int s = *( int * )second;
	return ( f - s );
}

int comparePriority ( const int f, const int s )
{
	return ( f - s );
}

int main (  )
{
	PriorityQueue * q;
	int *num1;
	num1 = malloc ( sizeof ( int ) );
	*num1 = 3;
	printf("Testing Priority Queue using integers\n");

    /** Test 1: Creating new queue with NULL function pointers doesn't break **/
    printf ( "\n***** TEST 1 *****\n" );
    printf ( "Checking that createPriorityQueue does not break when function pointers are null\n" );
    q = createPriorityQueue ( NULL, NULL, NULL, NULL );
    if ( q == NULL ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, queue was not set to NULL\n" );
    }

    /** Test 2: Creating new queue with valid function pointers doesn't break and doesn't return null **/
    printf ( "\n***** TEST 2 *****\n" );
    printf ( "Checking that createPriorityQueue when valid input is input\n" );
    q = createPriorityQueue ( &printInteger, &deleteInteger, &compareData, &comparePriority );
    if ( q != NULL ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, queue returned was NULL\n" );
    }

    /** Test 3: destroyPriorityQueue when the queue is set as NULL doesn't break **/
    printf ( "\n***** TEST 3 *****\n" );
    printf ( "Checking that destroyPriorityQueue does not break when passed null\n" );
    destroyPriorityQueue ( NULL );
    printf("Test PASSED based on output to console\n");

    /** Test 4: destroyPriorityQueue doesn't break when valid input is passed and that the queue is set to NULL **/
    printf ( "\n***** TEST 4 *****\n" );
    printf ( "Checking that destroyPriorityQueue does not break when passed valid input and that the queue is set to NULL afterwards\n" );
    insert ( q, ( void * ) num1, 5 );
    q = destroyPriorityQueue ( q );
    if ( q == NULL ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, queue was not set to NULL\n" );
    }

    /** Test 5: insert doesn't break when list is null **/
    printf ( "\n***** TEST 5 *****\n" );
    printf ( "Checking that insert doesn't break when list is null\n" );
    insert ( NULL, num1, 3 );
    printf("Test PASSED based on output to console\n");
    

    /** Test 6: insert doesn't added null to the list **/
    printf ( "\n***** TEST 6 *****\n" );
    printf ( "Checking that insert does not add NULL to the list\n" );
    q = createPriorityQueue ( &printInteger, &deleteInteger, &compareData, &comparePriority );
    insert ( q, NULL, 5 );
    if ( q->count == 0 ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, NULL added to the list\n" );
    }

    /** Test 7: insert works when valid input is added to the list **/
    printf ( "\n***** TEST 7 *****\n" );
    printf ( "Checking that insert works with valid input\n" );
    insert ( q, num1, 5 );
    if ( q->count == 1 ) {
    	printf( "Test PASSED\nExpected: %d\nOutput: %d\n", *num1, *( int * ) peek ( q ) );
    } else {
    	printf( "Test FAILED\nExpected: %d\nOutput: %d\n", *num1, *( int * ) peek ( q ) );
    }

    /** Test 8: pop doesn't break when the queue passed is null **/
    printf ( "\n***** TEST 8 *****\n" );
    printf ( "Checking that pop doesn't break when the queue passed is NULL\n" );
    pop ( NULL );
    printf("Test PASSED based on output to console\n");

    /** Test 9: pop doesn't break when the queue is empty **/
    printf ( "\n***** TEST 9 *****\n" );
    printf ( "Checking that pop doesn't break when the queue passed is NULL\n" );
    destroyPriorityQueue ( q );
    q = createPriorityQueue ( &printInteger, &deleteInteger, &compareData, &comparePriority );
    pop ( q );
    if ( q->count == 0 ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, count is less than it should be\n" );
    }

    /** Test 10: pop removes the first item **/
    printf ( "\n***** TEST 10 *****\n" );
    printf ( "Checking that pop removes the first item\n" );
    insert ( q, num1, 5 );
    pop ( q );
    if ( q->count == 0 ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, count is less than it should be\n" );
    }

    /** Test 11: peek doesn't break when queue is null **/
    printf ( "\n***** TEST 11 *****\n" );
    printf ( "Checking that peek doesn't break when queue is null\n" );
    int *peekResult = ( int * ) peek ( NULL );
    if ( peekResult == NULL ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, peek returned none null value\n" );
    }

    /** Test 12: peek doesn't break when the queue is empty **/
    printf ( "\n***** TEST 12 *****\n" );
    printf ( "Checking that peek doesn't break when the queue is empty\n" );
    destroyPriorityQueue ( q );
    q = createPriorityQueue ( &printInteger, &deleteInteger, &compareData, &comparePriority );
    peekResult = ( int * ) peek ( q );
    if ( peekResult == NULL ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, peek returned none null value\n" );
    }

    /** Test 13: peek returns the correct value **/
    printf ( "\n***** TEST 13 *****\n" );
    printf ( "Checking that peek returns the correct value\n" );
    *num1 = 3;
    insert ( q, num1, 5 );
    peekResult = ( int * ) peek ( q );
    if ( *peekResult == *num1 ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, peek returned value different from one inserted into list\n" );
    }

    /** Test 14: removeFromQueue doesn't break when the queue is null **/
    printf ( "\n***** TEST 14 *****\n" );
    printf ( "Checking that removeFromQueue doesn't break when the queue is null\n" );
    removeFromQueue ( NULL, ( void * ) num1 );
    printf("Test PASSED based on output to console\n");

    /** Test 15: removeFromQueue doesn't break when the data being removed is null **/
    printf ( "\n***** TEST 15 *****\n" );
    printf ( "Checking that removeFromQueue doesn't break when the data being removed is null\n" );
    removeFromQueue ( q, NULL );
    printf("Test PASSED based on output to console\n");

    /** Test 16: removeFromQueue gets ride of the element with proper value **/
    printf ( "\n***** TEST 16 *****\n" );
    printf ( "Checking that removeFromQueue removes the element with proper value\n" );
    int *num2 = malloc ( sizeof ( int ) );
    *num2 = *num1;
    removeFromQueue ( q, ( void * ) num1 );
    if ( q->count == 0 ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, item was not removed from list, count is incorrect value\n" );
    }

    /** Test 17: check isEmpty when the queue is empty **/
    printf ( "\n***** TEST 17 *****\n" );
    printf ( "Checking that isEmpty returns true when the queue is empty\n" );
    destroyPriorityQueue ( q );
    q = createPriorityQueue ( &printInteger, &deleteInteger, &compareData, &comparePriority );
    if ( isEmpty ( q ) ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, the queue should be empty but isEmpty says that it contains items\n" );
    }

    /** Test 18: check isEmpty when the queue is not empty **/
    printf ( "\n***** TEST 18 *****\n" );
    printf ( "Checking that isEmpty returns false when the queue is not empty\n" );
    insert ( q, num1, 5 );
    if ( !isEmpty ( q ) ) {
    	printf( "Test PASSED\n" );
    } else {
    	printf( "Test FAILED, the queue is not empty but isEmpty says that it is\n" );
    }

    /** Test 19: check count when the queue has items **/
    printf ( "\n***** TEST 19 *****\n" );
    printf ( "Checking that count returns the numbre of items when the queue is not empty\n" );
    int numNodes = count ( q );
    if ( numNodes == 1 ) {
    	printf( "Test PASSED\nExpected: %d\nOutput: %d\n", 1, numNodes );
    } else {
    	printf( "Test FAILED, the count should be one\n" );
    }

    /** Test 20: check count when the queue is empty **/
    printf ( "\n***** TEST 20 *****\n" );
    printf ( "Checking that count returns zero when the queue is empty\n" );
    destroyPriorityQueue ( q );
    q = createPriorityQueue ( &printInteger, &deleteInteger, &compareData, &comparePriority );
    numNodes = count ( q );
    if ( isEmpty ( q ) && numNodes == 0 ) {
    	printf( "Test PASSED\nExpected: %d\nOutput: %d\n", 0, numNodes );
    } else {
    	printf( "Test FAILED, the count should be zero or the list is not empty\n" );
    }

    q = destroyPriorityQueue ( q );
    free ( num1 );
    free ( num2 );

}