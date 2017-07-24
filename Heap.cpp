#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Heap::Heap(int maxSize){
	n = 0;
	nMax = maxSize;
	array = new int [maxSize];
}

Heap::~Heap(){
	delete [] array;
}

//insert key in heap
void
Heap::insert(int key){
	//make sure there is space in heap
	assert(n < nMax);

	//add key in the next available position in array
	array[n] = key;
	n++;

	//apply up-heap
	int child = n-1;
	int parent = iparent(child);

	while(child > 0){
		if(array[child] > array[parent]){
			//no need to swap
			break;
		}
		//need to swap parent and child
		int temp = array[child];
		array[child] = array[parent];
		array[parent] = temp;

		child = parent;
		parent = iparent(child);
	}

}

//returns minimum key after remove it
int
Heap::removeMin(){
	//heap not empty
	assert(n > 0);

	int miniKey = array[0];
	n--;

	if(n == 0) {
		//heap is empty, no need to fix
		return miniKey;
	}

	//move last element in heap to the top
	array[0] = array[n];

	//fix heap doing down-heap, starting from the top
	int parent = 0;
	int left = left_child(parent);
	int right = right_child(parent);

	//repeat until bottom is reached
	while(left < n){
		//determine smallest child
		int miniChild = left;
		if(right < n && array[right] < array[left]){
			//right child is mini
			miniChild = right;
		}
		//check if we need to swap
		if(array[parent] < array[miniChild]){
			//no need to swap
			break;
		}
		//need to swap
		int temp = array[miniChild];
		array[miniChild] = array[parent];
		array[parent] = temp;
		//go down in heap
		parent = miniChild;
		left = left_child(parent);
		right = right_child(parent);
	}//while
	//heap has been fixed
	return miniKey;
}

void
Heap::heapSort(int * array, int n){
	//create a heap of n elements max
	Heap * heap = new Heap (n);
	//insert all elements of array in heap
	for(int i = 0; i < n; i++){
		heap->insert(array[i]);
	}
	//now put the elements back into the array
	//obtaining the minimum element one at a time using removeMin
	for(int i = 0; i < n; i++){
		array[i] = heap->removeMin();
	}
	//the array is sorted
}

int *
Heap::getArray(){
	return this->array;
}

int main(int argc, char ** argv){
	Heap * h = new Heap(15);
	
	printf("insert...\n");
	h->insert(6);
	h->insert(7);
	h->insert(8);
	h->insert(9);
	h->insert(10);
	h->insert(11);
	h->insert(12);
	h->insert(13);
	h->insert(14);
	h->insert(15);
	h->insert(16);
	h->insert(1);
	h->insert(2);
	h->insert(3);
	h->insert(4);

	int * array = h->getArray();
	for(int i = 0; i < 15; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
	printf("sort...\n");
	h->heapSort(array, 15);
	for(int i = 0; i < 15; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
	
	printf("removeMin()...\n");
	h->removeMin();
	for(int i = 0; i < 15; i++){
		int * array = h->getArray();
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("removeMin()...\n");
	h->removeMin();
	for(int i = 0; i < 15; i++){
		int * array = h->getArray();
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("removeMin()...\n");
	h->removeMin();
	for(int i = 0; i < 15; i++){
		int * array = h->getArray();
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("removeMin()...\n");
	h->removeMin();
	for(int i = 0; i < 15; i++){
		int * array = h->getArray();
		printf("%d ", array[i]);
	}
	printf("\n");

}
