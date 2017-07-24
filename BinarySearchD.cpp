#include "BinarySearchD.h"
#include <stdio.h>
#include <string.h>

BinarySearchD::BinarySearchD(int maxSize){
	table = new BinSearchTable[maxSize];
	currSize = 0;
	this->maxSize = maxSize;
	sorted = false;
}

BinarySearchD::~BinarySearchD(){
	delete table;
}

void
BinarySearchD::insert(char * _key, void * _data){
	if(currSize > maxSize)
		return;

	table[currSize].key = strdup(_key);
	table[currSize].data = _data;
	currSize++;
}

bool
BinarySearchD::lookup(char * key, int &index){
	if(sorted == false)
		sorted = true;

	int low;
	int high;
	int mid;
	low = 0;
	high = currSize - 1;
	
	while(low < high){
		mid = (low + high) / 2;
		int flag = strcmp(table[mid].key, key);
		if(flag > 0){
			low = mid + 1;
			mid = (low + high) / 2;
		} else if (flag < 0){
			high = mid - 1;
			mid = (low + high) / 2;
		} else {
			index = mid;
			return true;
		}
	}
	return false;
}

bool
BinarySearchD::remove(char * key, void * &data){
	int index = 0;
	if(!lookup(key,index))
		return false;

 	BinSearchTable p = table[index];
	data = p.data;
	currSize--;
	return true;
}

int 
BinarySearchD::getCurrSize(){
	return this->currSize;
}

BinSearchTable *
BinarySearchD::getTable(){
	return this->table;
}

int main(int argc, char ** argv){
	BinarySearchD * bsd = new BinarySearchD(10);

	printf("insert...\n");
	bsd->insert("apple",(void *)"red color fruit");
	bsd->insert("banana",(void *)"yellow color fruit");
	bsd->insert("orange",(void *)"orange color fruit");
	BinSearchTable * table = bsd->getTable();
	for(int i = 0; i < bsd->getCurrSize(); i++){
		printf("%s %s\n", table[i].key, (char *)table[i].data);
	}
	printf("\n");

	printf("remove banana...\n");
	void * ret;
	bsd->remove("banana", ret);
	for(int i = 0; i < bsd->getCurrSize(); i++){
		printf("%s %s\n", table[i].key, (char *)table[i].data);
	}
	printf("\n");

}
