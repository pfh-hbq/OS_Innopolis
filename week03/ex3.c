#include <stdio.h>
#include <stdlib.h>

// Node structure;
typedef struct Node {
	int value;
	struct Node *next;
} Node;

// Linked List structure;
typedef struct linked_list {
	Node *head;
} linked_list;

// function, that creates new Node with given value;
Node *create_node(int value) {
    Node *newNode = malloc(sizeof(Node));
    
    newNode->value = value;
    newNode->next = NULL;
    
    return newNode;
}

// prints list elements values;
void print_list(linked_list *list);
// inserts new node at the end of the list;
void insert_node(linked_list *list, Node *newNode);
// finds node by given value and delete it;
void delete_node(linked_list *list, int value);

int main(int argc, char const *argv[]) {

	// create new linked list;
	linked_list *list = malloc(sizeof(linked_list));
	list->head = NULL;

	// create three nodes;
	Node *newN1 = create_node(10);
	Node *newN2 = create_node(3214);
	Node *newN3 = create_node(12);

	// insert new nodes into list;
	insert_node(list, newN1);
	insert_node(list, newN2);
	insert_node(list, newN3);

	print_list(list);

	// delete node with value 10;
	delete_node(list, 10);
	print_list(list);
	
	// delete node with value 3214;
	delete_node(list, 3214);
	print_list(list);

	// try to delete node with value -5 (no such element);
	delete_node(list, -5);
	print_list(list);
	
	// delete node with value 12;
	delete_node(list, 12);
	print_list(list);

	// try to delete node with value 13 (empty list);
	delete_node(list, 13);
	print_list(list);

	// create two nodes with same value;
	Node *newN4 = create_node(5);
	Node *newN5 = create_node(5);

	insert_node(list, newN4);
	insert_node(list, newN5);
	print_list(list);

	// delete only one node with value 5;
	delete_node(list, 5);
	print_list(list);

	return 0;
}

void print_list(linked_list *list) {
	if (list->head == NULL)
		printf("List is empty.");
	else {
		Node *nodeCurr = list->head;

		printf("List:\n");
		
		printf("%d ", nodeCurr->value);

		while (nodeCurr->next != NULL) {
			nodeCurr = (Node *)nodeCurr->next;
			printf("%d ", nodeCurr->value);
		}
	}

	printf("\n");
}

void insert_node(linked_list *list, Node *newNode) {
	if (list->head == NULL)
		list->head = newNode;
	else {
		Node *nodeCurr = list->head;
		while (nodeCurr->next != NULL)
			nodeCurr = (Node *)nodeCurr->next;

		nodeCurr->next = newNode;
	}
}

void delete_node(linked_list *list, int value) {
	if (list->head == NULL) {
		printf("List is empty.\n");
		return;
	}
	// check if there exist node with given value, if no return;
	else {
		int exist = 0;

		Node *nodeCurr = list->head;

		if (nodeCurr->value == value)
			exist = 1;

		while (nodeCurr->next != NULL) {
			if (nodeCurr->value == value){
				exist = 1;
				break;
			}

			nodeCurr = (Node *)nodeCurr->next;
		}

		if (!exist) {
			printf("No element with value: %d.\n", value);
			return;
		}
	}

	printf("Node with value %d deleted.\n", value);

	// delete node with given value
	if (list->head->value == value) {
		list->head = list->head->next;
	} else {
		Node *nodeCurr = list->head;
		
		while (nodeCurr->next->value != value)
			nodeCurr = (Node *)nodeCurr->next;

		nodeCurr->next = nodeCurr->next->next;
	}
}