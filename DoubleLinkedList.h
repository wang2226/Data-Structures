struct DLLNode {
	int data;
	DLLNode * prev;
	DLLNode * next;
};

class DLList {
	private:
		DLLNode * head;
	public:
		DLList();
		~DLList();
		void print();
		void insertFront(int val);
		void insertEnd(int val);
		bool removeFront(int & val);
		bool removeEnd(int & val);
};

