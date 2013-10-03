#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

struct lnode {
	char *word; 
	int line;
	int count;
	struct lnode *next;
}; 

/*
 * Returns a new linked list node filled in with the given word and line, and
 * sets the count to be 1. Make sure to duplicate the word, as the original word
 * may be modified by the calling function.
 */

struct lnode* newNode (char* word, int line) {
  struct lnode *newNode = NULL;
  newNode = (struct lnode*) malloc(sizeof(struct lnode));
  if (newNode == NULL) {
  	return NULL;
  }
  newNode->word = word;
  newNode->line = line;
  newNode->count = 1;
  newNode->next = NULL;
  free(newNode);
  return newNode;
}

/**
 * In a linked list with *head as the head pointer, adds the given node to the
 * front of the list.
 */
void pushNode (struct lnode** head, struct lnode* node) {
	node->next = *head;
}

/**
 * Returns the pointer to the node containing the given word in the linked list
 * with head as the head pointer. If a node with the given word cannot be found,
 * the function returns NULL.
 */
struct lnode* getNode (struct lnode *head, char* word) {
	int i = 0;
	while( (head + i)->word != word && (head + i) != NULL) {
		i++;
	}
	if ((head + i) == NULL) {
		return NULL;
	}
	return (head + i);
}

/**
 * Removes the specified node from the list, and frees all memory the node is
 * using. Remember if *head is the node being deleted, it must be updated.
 */
void deleteNode (struct lnode** head, struct lnode* node) {
	int i = 0;
	while(*(head + i) != node) {
		i++;
	}
	(node - 1)->next = (node + 1);
	free(node);
}

/**
 * Simply returns the next node in the list, or NULL if there are no further nodes.
 */
struct lnode *nodeGetNext(struct lnode *node) {
    return node->next;
}

/**
 * Simply returns the word in the given node.
 */
char *nodeGetWord(struct lnode *node) {
    return node->word;
}

/**
 * Simply returns the line in the given node.
 */
int nodeGetLine(struct lnode *node) {
    return node->line;
}

/**
 * Simply returns the count in the given node.
 */
int nodeGetCount(struct lnode *node) {
    return node->count;
}

/**
 * Set the count in the node to be the given count.
 */
void nodeSetCount(struct lnode *node, int count) {
	node->count = count;
}

/**
 * Set the line in the node to be the given line.
 */
void nodeSetLine(struct lnode *node, int line) {
	node->line = line;
}


/**
 * Deletes every node in the list with *head as the head pointer. After calling
 * this function, all memory used by the list should be freed, and *head
 * should be NULL.
 */
void deleteList(struct lnode **head) {
	int i = 0;
	while(*(head + i) != NULL) {
		*(head + i) = NULL;
		free(*(head+i));
		i++;
	}
	free(head);
}

int main() {
	struct lnode *new = newNode("hello",1);
	printf("%s, %d\n", new->word,new->line);
	free(new);
}
