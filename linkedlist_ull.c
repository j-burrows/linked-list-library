/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	linkedlist_ull.c
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Provide the structure of a linked list of unsigned long longs, and
 *				functions for it.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		November 30th 2012
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Dependancy:	string.h
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
#include "linkedlist_ull.h"

#include <stdio.h>
#include <stdlib.h>

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	print_list_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Prints all elements in a linked list of unsigned long longs to the screen.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		current,		The list whos elements will be printed to screen.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
void print_list_llu(list_llu* current){
	fprint_list_llu(stdout, current);
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	fprint_list_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Prints all elements in a linked list of unsigned long longs to a stream.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		stream,			Where the elements will be printed to.
 *				current,		The list whos elements will be printed to a stream.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
void fprint_list_llu(FILE* stream, list_llu* current){
	node_llu* traverse;
	fprintf(stream,"\n");
	
	/*	Every node in the list is visited, and it's value displayed to the stream.	*/
	for(traverse = current->head; traverse != NULL; traverse = traverse->next){
		fprintf(stream,"%"SCNu64"\t",traverse->value);
	}
	fprintf(stream,"\n");
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	init_node_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Creates a new node with a given value, and returns a pointer to it.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		value,			Value that the node will have.
 *	@return:	node_making,		Node which was created with the given value.
 *				NULL,			Could not allocate memory for new node.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Error:		If memory could not be allocated for a new node, NULL is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
node_llu* init_node_llu(unsigned long long value){
	node_llu* node_making;				/*Return pointer.*/
	
	/*	Attempts to allocate memory for the list. */
	if((node_making = malloc(sizeof(node_llu))) == NULL){
		/*	Unsuccessful attempt to allocate memory, return error value.	*/
		return NULL;
	}
	/*	Allocation was successful, assign given value and set next to null.	*/
	node_making->value = value;
	node_making->next = NULL;
	
	return node_making;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	init_list_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Creates a new list with head set to a given value, and returns a pointer
 *				to the newly created list.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		value_head,		Value that the head node will be set to.
 *	@return:	list_making,		A pointer to the newly created list.
 *				NULL,			Memory allocation failed.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Errors:		If memory couldn't be allocated to create a new node/list, NULL is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
list_llu* init_list_llu(unsigned long long value_head){
	list_llu* list_making;				/*Return pointer.*/
	node_llu* node_making;
	
	/*	Creates new node, and checks that memory allocation was successful.	*/
	if((node_making = init_node_llu(value_head)) == NULL){
		/*	Memory allocation was unsuccessful, return error value.	*/
		return NULL;
	}
	/*	Allocation was successful, attempts to allocate memory for new list.	*/
	if( (list_making = malloc(sizeof(list_llu))) == NULL){
		/*	Failed to allocate memory for new list, free node and return error value.	*/
		free(node_making);
		return NULL;
	}
	/*	All allocations were successful, begin to set pointers for head and tail.	*/
	list_making->head = node_making;
	list_making->tail = node_making;
	
	return list_making;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Subroutine:	free_list_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	To free all nodes in a linked list of unsigned long longs.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		list_deleting,	The list whos nodes will all be freed.
 === === === === === === === === === === === === === === === === === === === === === === ===
*/
void free_list_llu(list_llu* list_deleting){
	node_llu* conductor, *prev;
	
	for( conductor = list_deleting->head; conductor != NULL;){
		prev = conductor;
		conductor = conductor->next;
		
		free(prev);
		prev = NULL;
	}
	free(list_deleting);
	list_deleting = NULL;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	add_node_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Adds a new node, with a given value, to the back of the list.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		current,		List the node is being added to.
 *				value_adding,	Value the node being added will take.
 *	@return:	1,				The node was successfully added.
 *				0,				The node was not successfully added.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Errors:		If memory allocation fails for the node to be added, then list is unchanged
 *				and a value of zero is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int add_node_llu(list_llu* current, unsigned long long value_adding){
	node_llu* node_adding;
	
	/*	Initialises node and checks if allocation was successful.	*/
	if( (node_adding = init_node_llu(value_adding)) == NULL){
		return 0;					/*Allocation unsuccessful, return error value.*/
	}
	
	/*	Allocation was successful, node is added to the tail of the list.	*/
	current->tail->next = node_adding;
	current->tail = node_adding;
	
	return 1;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	in_list
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Checks if a node in the given list has a matching value with the given.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		current,		List whos being checked for a matching value.
 *				value_matching,	Value that is being compared against node's values.
 *	@return:	0,				No node in list with a matching value.
 *				1,				There exists a node in the list with a matching value.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int in_list(list_llu* current, unsigned long long value_matching){
	int in = 0;								/*Return value.*/
	node_llu* conductor;					/*Traverses the list.*/
	
	/*	Goes through every element in the list. If a match is found, in is set to 1, and
	 *	the loop breaks.	*/
	for(conductor = current->head; conductor != NULL; conductor = conductor->next){
		if( conductor->value == value_matching){	/*Match found.*/
			in = 1;									/*Flaged as match found and breaks.*/
			break;
		}
	}
	
	return in;
}
