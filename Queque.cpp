#include "Queque.h"
#include <stdio.h>
#include <stdlib.h>

/*
	- They are data structures that follows firt-in-first-out (FIFO) policy, that is,
	the element remove form a queque is the oldest in the queque.
	- Impementations: array, double linked list
	- Using an array of *fixed* size
	- New element insert at "last"+1
	- Element remove from "first"
	- When "last" reaches the end(N), it will wrap around to 0
	- When "first" reaches the end(N), it will wrap around to 0
	- The masimum number of elements at any time in queque will be N	 
*/
Queque::Queque(int maxN){
	first = 0;
	last = 0;
	n = 0; //current # of elements in queque
	this->maxN = maxN;
	array = new int [maxN];
}

Queque::~Queque(){
	delete [] array;
}

bool
Queque::enqueque(int value){
	if(n == maxN){
		//queue is full
		return false;
	}
	//queue is not full
	array[last] = value;
	last = (last+1) % maxN; //wrap around if reach end
	n++;
	return true;
}

bool
Queque::dequeque(int &value){
	if(n == 0){
		//queue is empty
		return false;
	}
	//queue is not empty, element to be removed is in "first"
	value = array[first];
	first = (first+1) % maxN;
	n--;
	return true;
}

int * 
Queque::getArray(){
	return this->array;
}

int main(int argc, char ** argv){
	Queque * q = new Queque(5);

	printf("enqueue...\n");
	q->enqueque(1);
	q->enqueque(2);
	q->enqueque(3);
	q->enqueque(4);
	q->enqueque(5);

	int * array = q->getArray();

	for(int i = 0; i < 5; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("dequeque...\n");
	for(int i = 0; i < 5; i++){
		int value;
		q->dequeque(value);
		printf("dequeue() = %d\n", value);
	}
	printf("\n");
}

