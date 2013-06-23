/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	LinkedList.c
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Provides structures and functions for linked lists of integer type.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		Nov 20 2012
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "LinkedList.h"
/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	init_node
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	init_list
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	free_list
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	print_list
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	fprint_list
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	add_node
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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
