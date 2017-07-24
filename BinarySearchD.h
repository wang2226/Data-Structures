struct BinSearchTable{
	char * key;
	void * data;
};

class BinarySearchD{
	BinSearchTable * table;
	int currSize;
	int maxSize;
	bool sorted;

	public:
		BinarySearchD(int maxSize);
		~BinarySearchD();
		int getCurrSize();
		BinSearchTable * getTable();
		void insert(char * key, void * data);
		bool lookup(char * key, int & index);
		bool remove(char * key, void * &data);
};
