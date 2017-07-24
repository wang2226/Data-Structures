struct HashTableEntry {
	const char * _key;
	char * _data;
	HashTableEntry * _next;
};

class HashTable {
	public:
		enum {BucketSize = 2039};
		HashTableEntry ** _buckets;
		int _maxSize; //Table size
		int _n; //current number of entries
	public:
		HashTable();
		~HashTable();
		int hash(const char * key);
		void rehash(); //make hash table larger
		bool insert(const char * key, char * data);
		bool remove(const char * key);
		bool lookup(const char * key, char ** data);
};
