/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	linkedlist_ull.c
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "linkedlist_ull.h"

#include <stdio.h>
#include <stdlib.h>

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	print_list_llu
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
void print_list_llu(list_llu* current){
	fprint_list_llu(stdout, current);
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	fprint_list_llu
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	init_node_llu
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	init_list_llu
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	free_list_llu
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	add_node_llu
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	in_list
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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
