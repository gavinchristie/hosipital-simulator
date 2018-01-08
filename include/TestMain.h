/**
 * Header file containing function from main.c
 **/

/**
 * This function compares to nodes stored in a list of integers
 * 
 * @param first This is the first node to be compared
 * @param second This is the second node to be compared
 * @return Returns integer value based on which should be ordered first
 **/
int compareInt ( const void * first, const void * second );

/**
 * This function is used to print a node containing integers
 *
 * @param toBePrinted is a void pointer to the node containing the data to be printed
 **/
void printInt ( void * toBePrinted );

/**
 * This funciton is used to delete a node from a list containing integers
 *
 * @param nodeDel is the node to be deleted
 **/
void deleteInt ( void * toBeDeleted );

/**
 * This function compare the priority of two nodes
 * @param first Integer representing the priority of the first node
 * @param second Integer representing the priority of the second node
 * @return Returns integer value based on which should be ordered first
 */
int comparePriority ( const int first, const int second );
