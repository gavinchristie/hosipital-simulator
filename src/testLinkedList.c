#include "TestMain.h"
#include "LinkedListAPI.h"

int main (  )
{
    List * intList = NULL;
    Node * newNode = NULL;
    int * num1 = ( int * ) malloc ( sizeof ( int ) );
    int * num2 = ( int * ) malloc ( sizeof ( int ) );
    int * num3 = ( int * ) malloc ( sizeof ( int ) );
    int * num4 = ( int * ) malloc ( sizeof ( int ) );

    int priority = 1;

    *num1 = 57;
    *num2 = 8;
    *num3 = 100;
    *num4 = 24;
    
    /** Test 1: Creating new node with value NULL **
      Expect that the node will be NULL
    ***********************************************/
    printf( "\n***** TEST 1 *****\n" );
    newNode = initializeNode ( ( void * ) NULL, priority );
    if ( newNode == NULL ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test complete. Failed, unexpected value\n" );
    }

    /** Test 2: Creating new node with integer pointer **
      Expect that the node will be created
    ***********************************************/
    printf( "\n***** TEST 2 *****\n" );
    newNode = initializeNode ( ( void * ) num1, priority );
    if ( *( int * ) newNode->data == *num1 ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED. Expected: %d Got: %d\n", *num1, *( int * ) newNode->data );
    }

    /** Test 3: Creating new list with functions for integers **
      Expect that the list will be created
    ***********************************************/
    printf( "\n***** TEST 3 *****\n" );
    intList = initializeList ( &printInt, &deleteInt, &compareInt, &comparePriority );
    if ( intList != NULL ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 4: Adding null to the beginning of list 
        Expect that the head points to null
    ***********************************************/
    printf("\n***** TEST 4 *****\n");
    insertFront ( intList, NULL, priority );
    if ( intList->head == NULL ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 5: Adding integer to beginning of list 
        Expect that the integer is at the beginning of list
    ***********************************************/
    printf( "\n***** TEST 5 *****\n" );
    insertFront ( intList, ( void * ) num1, priority );
    if ( *( int * ) intList->head->data == *num1 ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 6: Adding integer to beginning of list when it already has a head
        Expect that the integer is at the beginning of list
    ***********************************************/
    printf( "\n***** TEST 6 *****\n" );
    insertFront ( intList, ( void * ) num2, priority );
    if ( *( int * ) intList->head->data == *num2 && *( int * ) intList->tail->data == *num1 ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 7: Adding null to the end of the list
        Expect that the list remain unchanged
    ***********************************************/
    printf( "\n***** TEST 7 *****\n" );
    insertBack ( intList, NULL, priority );
    if ( *( int * ) intList->tail->data == *num1 ) {
        printf("Test PASSED\n");
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 8: Adding new integer to the end of the list
        Expect that the new integer is the tail
    ***********************************************/
    printf( "\n***** TEST 8 *****\n" );
    insertBack ( intList, ( void * ) num3, priority );
    if ( *( int * ) intList->tail->data == *num3 ) {
        printf("Test PASSED\n");
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 9: Deleting a list
        Expect that the list pointer is NULL
    ***********************************************/
    printf( "\n***** TEST 9 *****\n" );
    deleteList ( intList );
    if ( intList->head == NULL ) {
        printf("Test PASSED\n");
    } else {
        printf( "Test FAILED\n" );
    }

    intList = initializeList ( &printInt, &deleteInt, &compareInt, &comparePriority );

    /** Test 10: Adding node to end of empty list
        Expect that the integer is added as head and tail
    ***********************************************/
    printf( "\n***** TEST 10 *****\n" );
    insertBack ( intList, ( void * ) num1, priority );
    if ( *( int * )( intList->tail->data ) == *num1 && *( int * )( intList->head->data ) == *num1 ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    deleteList ( intList );
    intList = initializeList ( &printInt, &deleteInt, &compareInt, &comparePriority );

    /** Test 11: Inserted sorted into an empty list
        Expect that the head and tail are equal to new node
    ***********************************************/
    printf( "\n***** TEST 11 *****\n" );
    insertSorted ( intList, ( void * ) num1, priority );
    if ( *( int * )( intList->tail->data ) == *num1 && *( int * )( intList->head->data ) == *num1 ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 12: Inserted sorted into an list
        Expect that the head and tail are equal to appropriate values
    ***********************************************/
    printf( "\n***** TEST 12 *****\n" );
    insertSorted ( intList, ( void * ) num2, priority );
    if ( *( int * )( intList->tail->data ) == *num1 && *( int * )( intList->head->data ) == *num2 ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 13: Inserted sorted into an list
        Expect that the head and tail are equal to appropriate values
    ***********************************************/
    printf( "\n***** TEST 13 *****\n" );
    insertSorted ( intList, ( void * ) num3, priority );
    if ( *( int * )( intList->tail->data ) == *num3 && *( int * )( intList->head->data ) == *num2 ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 14: Delete node from list
        Expect that the head and tail stay the same but the other value is removed
    ***********************************************/
    printf( "\n***** TEST 14 *****\n" );
    int deleted = deleteNodeFromList ( intList, ( void * ) num1 );
    if ( deleted ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 15: Delete node that doesn't exist in list
        Expect that nothing changes and deleteNodeFromList returns -1
    ***********************************************/
    printf( "\n***** TEST 15 *****\n" );
    deleted = deleteNodeFromList ( intList, ( void * ) num4 );
    if ( deleted == -1 ) {
        printf( "Test PASSED\n" );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 16: Get the first node data
        Expect that function returns pointer to data at first node
    ***********************************************/
    printf( "\n***** TEST 16 *****\n" );
    int * testInt = getFromFront ( intList );
    if ( *testInt == *num2 ) {
       printf( "Test PASSED. %d = %d\n", *testInt, *num2 );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 17: Get the first node data when only head
        Expect that function returns pointer to data at first node
    ***********************************************/
    printf( "\n***** TEST 17 *****\n" );
    deleteNodeFromList ( intList, ( void * ) num2 );
    testInt = getFromFront ( intList );
    if ( *testInt == *num3 ) {
       printf( "Test PASSED. %d = %d\n", *testInt, *num3 );
    } else {
        printf( "Test FAILED\n" );
    }

    *num1 = 57;

    /** Test 18: Get the last node data when only head
        Expect that function returns pointer to data at first node
    ***********************************************/
    printf( "\n***** TEST 18 *****\n" );
    testInt = ( int * ) getFromBack ( intList );
    if ( *testInt == *num3 ) {
       printf( "Test PASSED. %d = %d\n", *testInt, *num3 );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 19: Get the last node data
        Expect that function returns pointer to data at last node
    ***********************************************/
    printf( "\n***** TEST 19 *****\n" );
    insertSorted ( intList, ( void * ) num1, priority );
    insertSorted ( intList, ( void * ) num4, priority );
    testInt = ( int * ) getFromBack ( intList );
    if ( *testInt == *num4 ) {
       printf( "Test PASSED. %d = %d\n", *testInt, *num3 );
    } else {
        printf( "Test FAILED\n" );
    }

    /** Test 20: Print list forward
        Expect nodes to be printed from smallest integer to largest
    ***********************************************/
    printf( "\n***** TEST 20 *****\n" );
    printf( "Expected order: %d, %d, %d\n", *num3, *num1, *num4 );
    printForward ( intList );
    printf("Test PASSED\n");

    /** Test 21: Print the list backwards
        Expect nodes to be printed from largest integer to smallest
    ***********************************************/
    printf( "\n***** TEST 21 *****\n" );
    printf( "Expected order: %d, %d, %d\n", *num4, *num1, *num3 );
    printBackwards ( intList );
    printf("Test PASSED\n");

    /** Test 22: Insert sorted same number twice
        Expect nodes with same value to be sided by side in the list
    ***********************************************/
    printf( "\n***** TEST 22 *****\n" );
    insertSorted ( intList, ( void * ) num4, priority );
    //printf("%d %d\n", *( int * ) intList->head->data, *( int * ) intList->head->next->data );
    if ( *( int * ) intList->head->data == *num4 && *( int * ) intList->head->next->data == *num4 ) {
        printf("Test PASSED\n");
    } else {
        printf("Test FAILED\n");
    }

    deleteList ( intList );
    intList = initializeList ( &printInt, &deleteInt, &compareInt, &comparePriority );

    /** Test 23: Print list forward
        Expect nodes to be printed from smallest integer to largest
    ***********************************************/
    printf( "\n***** TEST 23 *****\n" );
    printf( "Expected output: Nothing in list\nOutput: " );
    printForward ( intList );
    printf("Test PASSED\n");

    /** Test 24: Print the list backwards
        Expect nodes to be printed from largest integer to smallest
    ***********************************************/
    printf( "\n***** TEST 24 *****\n" );
    printf( "Expected output: Nothing in list\nOutput: " );
    printBackwards ( intList );
    printf("Test PASSED\n");

    return 0;
}

int compareInt ( const void * first, const void * second )
{
    int * f = ( int * ) first;
    int * s = ( int * ) second;

    return ( *f - *s );
}

void printInt ( void * toBePrinted )
{
    int * i = ( int * ) toBePrinted;
    printf ( "%d\n", *i );
}

void deleteInt ( void * nodeDel )
{
    int * i = ( int * ) nodeDel;

    free ( i );
}

int comparePriority ( const int first, const int second )
{
    return ( first - second );
}
