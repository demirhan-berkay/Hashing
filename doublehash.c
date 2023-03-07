#include <stdio.h>
#include <stdlib.h>

void printHash(int* hash, int size);

int main(void){
	
	int size = 13, i;
	int* hash = (int*)malloc(size*sizeof(int));
	for(i=0; i<size; i++){
		hash[i] = INT_MAX;
	}
	insert(5, hash, size);
	insert(5, hash, size);
	insert(5, hash, size);
	insert(12, hash, size);
	insert(12, hash, size);
	insert(12, hash, size);
	insert(2, hash, size);
	printHash(hash, size);
	printf("\n");
	printf("%d ", search(2, hash, size));
	printf("%d ", search(10, hash, size));
	
	
	return 0;
}

int insert(int value, int* hash, int size){
	int key = value % size;
	int index = value % size;
	int control = 0;
	
	while(hash[index] != INT_MAX && control < size){
		index = (index + (key%11)) % size;
		control++;
	}
	
	if(control < size){
		hash[index] = value;
		return 1;
	}
	
	return -1;
}

int search(int value, int* hash, int size){
	int key = value % size;
	int index = value % size;
	int control = 0;
	
	while(hash[index] != value && hash[index] != INT_MAX && control < size){
		index = (index + (key%11)) % size;
		control++;
	}
	
	if(hash[index] == INT_MAX || control >= size){
		return -1;
	}
	return index;
	
	
	
}

void printHash(int* hash, int size){
	
	int i;
	printf("hash = ");
	for(i=0; i<size; i++){
		if(hash[i] == INT_MAX){
			printf("(empty) ");
		}else{
			printf("%d ", hash[i]);
		}
		
	}
	
	
}
