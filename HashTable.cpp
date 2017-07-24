#include "HashTable.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
HashTable::hash(const char * key){
	int sum = 0;
	int len = strlen(key);

	for(int i = 0; i < len; i++){
		sum += (i+1) * key[i];
	}
	return sum % BucketSize;
}

HashTable::HashTable(){
	_maxSize = BucketSize;
	_n = 0;

	_buckets = new HashTableEntry * [BucketSize];

	for(int i = 0; i < BucketSize; i++){
		_buckets[i] = NULL;
	}
}

HashTable::~HashTable(){
	HashTableEntry * curr;
	HashTableEntry * next;

	for(int i = 0; i < BucketSize; i++){
		curr = _buckets[i];
		while(curr != NULL){
			next = curr->_next;
			free((char *)(curr->_key));
			delete curr;
			curr = next;
		}
	}
	delete [] _buckets;
}

bool
HashTable::insert(const char * key, char * data){
	int h = hash(key);

	HashTableEntry * e;
	e = _buckets[h];

	while(e != NULL){
		if(strcmp(e->_key, key) == 0){
			e->_data = data;
			return true;
		}
		e = e->_next;
	}

	e = new HashTableEntry();
	e->_key = strdup(key);
	e->_data = data;

	e->_next = _buckets[h];
	_buckets[h] = e;

	return false;
}

bool
HashTable::remove(const char * key){
	int h = hash(key);

	HashTableEntry * curr;
	curr = _buckets[h];
	HashTableEntry * prev;
	prev = NULL;

	if(curr == NULL)
		return false;

	if(strcmp(curr->_key, key) == 0){
		_buckets[h] = curr->_next;
		free((char *) curr->_key);
		delete curr;
		return true;
	}

	while(curr != NULL){
		if(strcmp(curr->_key, key) == 0){	
			prev->_next = curr->_next;
			free((char *) curr->_key);
			delete curr;
			return true;
		}
		prev = curr;
		curr = curr->_next;
	}

	return false;
}
 
bool
HashTable::lookup(const char * key, char ** data){
	int h = hash(key);

	HashTableEntry * e = _buckets[h];

	while(e != NULL){
		if(strcmp(e->_key, key) == 0){
			*data = e->_data;
			return true;
		}
		e = e->_next;
	}

	return false;
}

void
HashTable::rehash(){
	int oldSize = _maxSize;
	_maxSize = 2 * _maxSize;

	HashTableEntry ** newBuckets=(HashTableEntry **)malloc(_maxSize * sizeof(HashTableEntry *));
	for(int i = 0; i < _maxSize; i++){
		newBuckets[i] = NULL; 
	}

	for(int i = 0; i < oldSize; i++){
		HashTableEntry * e = _buckets[i]; 
		while(e != NULL){
			HashTableEntry * next = e->_next;
			int h = hash(e->_key);
			e->_next = newBuckets[h];
			newBuckets[h] = e;
			e = next;
		}
	}

	free(_buckets);
	_buckets = newBuckets;
}

int main(int argc, char ** argv){
}
