class Heap {
	private:
		int n; //current number of elements
		int nMax; //maximum number of elements in heap
		int * array; //array that stores heap
	
	public:
		Heap(int maxSize);
		~Heap();
		void insert(int key);
		int removeMin();
		void heapSort(int * array, int n);
		int * getArray();
	public:
		#define left_child(i) 2*i+1
		#define right_child(i) 2*i+2
		#define iparent(i) (i-1)/2
};
