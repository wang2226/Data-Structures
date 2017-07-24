struct BTNode {
	int value;
	BTNode * left;
	BTNode * right;
};

class BinTree {
	BTNode * root;
	
	public:
		BinTree();
		~BinTree();
		BTNode * getRoot();
		bool insert(int val);
		void inOrderPrint(BTNode * node);
};
