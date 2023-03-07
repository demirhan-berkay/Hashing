#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
	int data;
	struct node* next;
	
}NODE;

NODE* createNode(int value);
void insert(int value, NODE**hash, int size);
int search(int value, NODE**hash, int size);
void printHash(NODE** hash, int size);

int main(void){
	
	int size = 13, i;
	NODE** hash = (NODE**)malloc(size * sizeof(NODE*));
	
	for(i=0 ;i<size; i++){
		hash[i] = NULL;
	}
	
	insert(5, hash, size);
	insert(5, hash, size);
	insert(18, hash, size);
	insert(31, hash, size);
	insert(10, hash, size);
	insert(23, hash, size);
	printHash(hash, size);
	printf("\n");
	printf("%d ",search(23, hash, size));
	printf("%d ",search(9, hash, size));
	printf("%d ",search(18, hash, size));
	printf("%d ",search(36, hash, size));
	
	return 0;
}

NODE* createNode(int value){
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	tmp->data = value;
	tmp->next = NULL;
	return tmp;
}

void insert(int value, NODE**hash, int size){
	
	int key = value % size;
	NODE* tmp = createNode(value);
	if(hash[key] == NULL){
		hash[key] = tmp;
	}else{
		tmp->next = hash[key];
		hash[key] = tmp;
	}
	
}

int search(int value, NODE**hash, int size){
	int key = value % size;
	NODE* tmp;
	if(hash[key] == NULL){
		return -1;
	}else{
		tmp = hash[key];	
	}

	while(tmp != NULL && tmp->data!=value){
		tmp= tmp->next;
	}
	if(tmp!=NULL){
		return key;
	}else{
		return -1;
	}
}

void printHash(NODE** hash, int size){
	
	int i;
	NODE* tmp;
	for(i=0; i<size; i++){
		printf("%dth index = ",i);
		tmp = hash[i];
		while(tmp != NULL){
			printf("%d ",tmp->data);
			tmp = tmp->next;
		}
		printf("\n");
	}
}
