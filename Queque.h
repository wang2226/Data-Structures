class Queque{
	private:
		int first;
		int last;
		int n;	//num of elements in queue currently
		int maxN;	//max num of elements
		int * array;

	public:
		Queque(int maxN);
		~Queque();
		int * getArray();
		bool enqueque(int value);
		bool dequeque(int &value);
};
