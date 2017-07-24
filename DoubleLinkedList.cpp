#include "DoubleLinkedList.h"
#include <stdio.h>

DLList::DLList(){
	head = new DLLNode();
	head->next = head;
	head->prev = head;
	head->data = 0;
}

DLList::~DLList(){
	DLLNode * p = head->next;
	DLLNode * next;

	while(p != head){
		next = p->next;
		delete p;
		p = next;
	}
}

void
DLList::insertFront(int val){
	DLLNode * insert = new DLLNode();
	insert->data = val;

	insert->next = head->next;
	insert->prev = head;
	head->next = insert;
	insert->next->prev = insert;
}

void
DLList::insertEnd(int val){
	DLLNode * insert = new DLLNode();
	insert->data = val;

	insert->prev = head->prev;
	insert->next = head;
	head->prev = insert;
	insert->prev->next = insert;
}

bool
DLList::removeFront(int & val){
	//check if empty
	if(head->next == head)
		return false;
	DLLNode * p = head->next;
	head->next = p->next;
	p->next->prev = head;
	
	val = p->data;
	delete p;
	return true;
}

bool
DLList::removeEnd(int & val){
	//check if empty
	if(head->next == head)
		return false;

	DLLNode * p = head->prev;
	head->prev = p->prev;
	p->prev->next = head;

	val = p->data;
	delete p;
	return true;
}

void
DLList::print(){
	DLLNode * p = head->next;
	while(p != head){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void test(){
	DLList list1, list2;

	for(int i = 1; i <= 20; i++){
		list1.insertFront(i);
	}
	printf("list1 insertFront... \n");
	list1.print();

	for(int i = 1; i <= 20; i++){
		list2.insertEnd(i);
	}
	printf("list2 insertEnd... \n");
	list2.print();
	
	printf("list1 removeFront... \n");
	for(int i = 1; i <= 20; i++){
		int value;
		list1.removeFront(value);
		printf("value = %d \n", value);
		list1.print();
	}

	printf("list2 removeEnd... \n");
	for(int i = 1; i <= 20; i++){
		int value;
		list2.removeEnd(value);
		printf("value = %d \n", value);
		list2.print();
	}

}

int main(int argc, char ** argv){
	printf("Testing...\n");
	test();
	return 0;
}
