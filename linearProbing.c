#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int size = 11, i;
	int* hash = (int*)malloc(size*sizeof(int));
	for(i=0; i<size; i++){
		hash[i] = INT_MAX;
	}
	
	insert(3, hash, size);
	insert(86, hash, size);
	insert(19, hash, size);
	insert(8, hash, size);
	insert(10, hash, size);
	insert(10, hash, size);
	printHash(hash, size);
	printf("\n");
	int a = search(8, hash, size);
	printf("Value 8 in %dth index\n", a);
	int b = search(10, hash, size);
	printf("Value 10 in %dth index\n", b);
	
	
	return 0;
}

int insert(int value, int* hash, int size){
	int key = value % size;
	int control = 0;
	
	while(hash[key] != INT_MAX && control < size){
		key++;
		if(key >= size){
			key = 0;
		}
		control++;
	}
	
	if(control < size){
		hash[key] = value;
		return 1;
	}
	
	return -1;
}

int search(int value, int* hash, int size){
	int key = value % size;
	int index = value % size;
	int control = 0;
	
	while(hash[index] != INT_MAX && hash[index] != key && control < size){
		index++;
		if(index >= size){
			index = 0;
		}
		control++;
	}
	
	if(control >= size || hash[index] == INT_MAX){
		return -1;
	}
	else{
		return index;
	}
}

void printHash(int* hash, int size){
	int i;
	printf("hash = ");
	for(i=0;i<size;i++){
		if(hash[i] == INT_MAX){
			printf("(empty) ");
		}else{
			printf("%d ",hash[i]);
		}
		
	}

		
}


