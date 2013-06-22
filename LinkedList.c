/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	LinkedList.c
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Provides structures and functions for linked lists of integer type.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		Nov 20 2012
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	References:	LinkedList.h		Predeclares all functions.
 *	Dependancy:	stdio.h				printlist
 *				stdlib.h			init_node
 *									init_list
 *									printlist
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
#include "LinkedList.h"
/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	init_node
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Creates a new node with a given value, and returns the reference.
 === === === === === === === === === === === === === === === === === === === === === === ===
 * 	@param:		value, 				the value to be stored in the node
 * 	@return:	node_making, 		a reference to an initialised node.
 *				NULL,				Allocation of the node was unsuccessful.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
node* init_node(int value){
	node* node_making;
	
	if( (node_making = malloc(sizeof(node))) == NULL){
		return NULL;					/*Allocation unsuccessful, return error value.*/
	}
	/*	Node is set to the value, with no next node.	*/
	node_making->value = value;
	node_making->next = NULL;
	
	return node_making;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	init_list
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	To create a new linked list.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		value,				The value that the head of the list will hold.
 *	@return:	list_making,		The name of the list that was created.
 *				NULL,				Allocation of memory for node or list was unsuccessful. 
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
list* init_list(int value){
	/*	List is declared and memory allocated to it.	*/
	list* list_making;
	node* node_making;
	
	if( (node_making = init_node(value)) == NULL){
		return NULL;						/*Allocation unsuccessful, return error value.*/
	}
	if( (list_making = malloc(sizeof(list))) == NULL){
		free(node_making);					/*Allocation unsuccessful, return error value.*/
		return NULL;
	}	
	/*	The node for the head is set, the tail is pointed to the head.	*/
	list_making->head = node_making;
	list_making->tail = node_making;
	
	/*	A reference to the newly created list is returned.	*/
	return list_making;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Subroutine:	free_list
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	To free all nodes in a linked list of integers.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		list_deleting,	The list whos nodes will all be freed.
 === === === === === === === === === === === === === === === === === === === === === === ===
*/
void free_list(list* list_deleting){
	node *conductor, *prev;
	
	/*	The list is traversed, with the last node being deleted.	*/
	for( conductor = list_deleting->head; conductor != NULL;){
		prev = conductor;
		conductor = conductor->next;
		/*	Frees the node itself.	*/
		free(prev);
		prev = NULL;
	}
	/*	Frees the entire list itself.	*/
	free(list_deleting);
	list_deleting = NULL;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Subroutine:	print_list
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Prints out all elements stored in a linked list.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		traverse,			The list whos contents will be printed.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Starting from the head of a list, every element is printed to screen.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
void print_list(list* traverse){
	node* conductor;
	
	fprintf(stdout,"\n");					/*For formatting.*/
	
	/*	Every element in the list is visited and its elements are printed.	*/
	/*	Starting from head, until the end is reached, every node in the list is visited.*/
	for(conductor = traverse->head; conductor != NULL; conductor = conductor->next){
		fprintf(stdout,"%d\t",conductor->value);
	}
	
	fprintf(stdout,"\n");					/*For formatting.*/
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Subroutine:	fprint_list
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Prints out all elements stored in a linked list to a given stream.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		stream,				Where the elements will be printed to.
 *				traverse,			The list whos contents will be printed.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Starting from the head of a list, every element is printed to given stream.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
void fprint_list(FILE* stream, list* traverse){
	node* conductor;
	
	fprintf(stream,"\n");					/*For formatting.*/
	
	/*	Every element in the list is visited and its elements are printed.	*/
	/*	Starting from head, and until the end is reached, every node in list is visited.*/
	for(conductor = traverse->head; conductor != NULL; conductor = conductor->next){
		/*Element of current position is printed.*/
		fprintf(stream,"%d\t",conductor->value);			
	}
	
	fprintf(stream,"\n");											/*For formatting.*/
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	add_node
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Adds a node to the end of a linked list.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		current,			The list who will have a node added to it.
 *	@return:	1,					The node was successfully added.
 *				0,					The node was not successfully created.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int add_node(list* current, int value){
	/*	New node is declared and given a value by calling a function.	*/
	node* node_making;
	if( (node_making = init_node(value)) == NULL){
		return 0;
	}	
	/*	Node is added to the tail of the list.	*/
	current->tail->next = node_making;
	current->tail = node_making;
	return 1;
}
