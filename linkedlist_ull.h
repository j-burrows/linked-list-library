/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	linkedlist_ull.h
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
#ifndef LINKEDLIST_ULL_H
#define LINKEDLIST_ULL_H 1

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Structure:	list_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	To have a structure that contains a node in a linked list. Has a unsigned
 *				long long element, and a pointer to the next link in the list.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
typedef struct node_llu{
	unsigned long long value;
	struct node_llu* next;
} node_llu;

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Structure:	list_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	To have a structure that contains the head and tail of a linked list.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
typedef struct list_llu{
	node_llu* head;
	node_llu* tail;
} list_llu;

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	print_list_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Prints all elements in a linked list of unsigned long longs to the screen.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		current,		The list whos elements will be printed to screen.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
extern void print_list_llu(list_llu* current);

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
extern void fprint_list_llu(FILE* stream, list_llu* current);

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	init_node_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Creates a new node with a given value, and returns a pointer to it.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		value,			Value that the node will have.
 *	@return:	made_node,		Node which was created with the given value.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
extern node_llu* init_node_llu(unsigned long long value);

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	init_list_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Creates a new list with head set to a given value, and returns a pointer
 *				to the newly created list.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		value_head,		Value that the head node will be set to.
 *	@return:	made_list,		A pointer to the newly created list.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
extern list_llu* init_list_llu(unsigned long long value_head);

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Subroutine:	free_list_llu
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	To free all nodes in a linked list of unsigned long longs.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		list_deleting,	The list whos nodes will all be freed.
 === === === === === === === === === === === === === === === === === === === === === === ===
*/
extern void free_list_llu(list_llu* list_deleting);

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
 */
extern int add_node_llu(list_llu* current, unsigned long long value_adding);

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
extern int in_list(list_llu* current, unsigned long long value_matching);

#endif
