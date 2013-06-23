/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	LinkedListString.c
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "LinkedListString.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	fprint_list_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
void fprint_list_string(FILE* stream, list_string* traverse){
	node_string* current;
	fprintf(stream,"\n");
	for(current = traverse->head;current!=NULL;current=current->next){
		fprintf(stream,"%s\t",current->value);
	}
	fprintf(stream,"\n");
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	in_list_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
int in_list_string(list_string* files, char* target){
	node_string* conductor;							/*Pointer used to conduct transverse.*/
	int in = 0;										/*Boolean for if value is in list.*/
	
	/*	Every element in a list is checked to see if it has the target element.	*/
	/*	Starting at the head, the list is traversed until the end is reached.	*/
	for(conductor = files->head; conductor != NULL; conductor = conductor->next){
		/*	The value of the current node is compared with the target value.	*/
		if(strcmp(target, conductor->value) != 0){			/*No match found.*/
			/*	Continue searching.	*/
			continue;
		}
		else{												/*Match is found.*/
			/*	Stop searching.	*/
			in = 1;
			break;
		}
	}
	/* in is 1 if and only if a match has been found, 0 otherwise. */
	return in;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	init_node_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
node_string* init_node_string(char* word){
	node_string* node_making;						/*The new node to be created.*/
	char* adder;									/*Will hold a copy of the word.*/
	
	/*	The word is copied into another string.	*/
	/*	Allocated enough space for word and null characters, checks if successful.	*/
	if( (adder = malloc((1+strlen(word))*sizeof(char))) == NULL){
		/*	Allocation was unsuccessful, return error value.	*/
		return NULL;
	}
	strcpy(adder, word);
	adder[strlen(adder)] = '\0';					/*Ends it with a null character.*/
	
	/*	The node is allocated memory and the value points to a copy of the word. */
	if( (node_making = malloc(sizeof(node_string))) == NULL){
		/*	Allocation was unsuccessful.	*/
		free(adder);
		adder = NULL;
		return NULL;
	}
	node_making->value = adder;
	node_making->next = NULL;
	
	return node_making;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	init_list_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
list_string* init_list_string(char* word){
	list_string* list_making;
	
	/*	Allocates memory for the structures.*/
	if( (list_making = malloc(sizeof(list_string))) == NULL){	/*	Allocation failed.	*/
		return NULL;							
	}
	if( (list_making->head = init_node_string(word)) == NULL){	/*	Allocation failed.	*/
		free(list_making);
		list_making = NULL;
		return NULL;
	}
	list_making->tail = list_making->head;
	return list_making;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	free_list_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
*/
void free_list_string(list_string* list_deleting){
	node_string *conductor, *prev;
	
	/*	The list is traversed, with the last node visited's string value and itself being
	 * 	deleted.	*/
	for( conductor = list_deleting->head; conductor != NULL;){
		prev = conductor;
		conductor = conductor->next;
		
		/*	Frees the allocated word stored in the node.	*/
		free(prev->value);
		prev->value = NULL;
		/*	Frees the node itself.	*/
		free(prev);
		prev = NULL;
	}
	/*	Frees the entire list itself.	*/
	free(list_deleting);
	list_deleting = NULL;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	add_node_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
int add_node_string(list_string* current, char* word){
	/*	Declares and sets value of the node to be added.	*/
	node_string* adder;
	if( (adder = init_node_string(word)) == NULL){
		/*	Initialisation of node was unsuccessful.	*/
		return -1;
		
	}
	/*	Adds the new node to the end of the list.	*/
	current->tail->next = adder;
	current->tail = adder;
	
	return 0;
}
/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	set_node_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
void set_node_string(node_string* current, char* word){
	char* adder;							/*Used to store a copy of the given word.*/
	
	/*	A copy of the word is stored in another string, which ends in a null character.*/
	if( (adder = malloc((1+strlen(word))*sizeof(char))) != NULL){
		/*	Allocation was successful.	*/
		strcpy(adder, word);
		adder[strlen(adder)] = '\0';
		
		free(current->value);					/*Current value is not used again.*/
		current->value = adder;					/*Value points at the new word.*/
	}
}
