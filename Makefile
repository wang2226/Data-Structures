all: DoubleLinkedList HashTable Queque BinTree Heap BinarySearchD MergeSort QuickSort

DoubleLinkedList: DoubleLinkedList.h DoubleLinkedList.cpp
	g++ -g -o DoubleLindedList DoubleLinkedList.cpp

HashTable: HashTable.h HashTable.cpp
	g++ -g -o HashTable HashTable.cpp

Queque: Queque.h Queque.cpp
	g++ -g -o Queque Queque.cpp

BinTree:: BinTree.h BinTree.cpp
	g++ -g -o BinTree BinTree.cpp

Heap: Heap.h Heap.cpp
	g++ -g -o Heap Heap.cpp

BinarySearchD: BinarySearchD.h BinarySearchD.cpp
	g++ -g -o BinarySearchD BinarySearchD.cpp

MergeSort: MergeSort.cpp
	g++ -g -o MergeSort MergeSort.cpp

QuickSort: QuickSort.cpp
	g++ -g -o QuickSort QuickSort.cpp

clean:
	rm -f *.o *.out DoubleLinkedList HashTable Queque Heap BinTree BinarySearchD MergeSort QuickSort
