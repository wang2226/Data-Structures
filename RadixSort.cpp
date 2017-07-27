// Radix sort
// Algorithm:	1.assuming binary representation of the key, examin bits from right to left.
//				2.at every step k, sort the array by looking only at bit k and keep the order of the keys unchanged.
// Time complexity:	b - # of bits used to represent a key
//					n - # of entries need to sort
//					Radix Sort takes = b steps * O(n)
//					**O(bn)**


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

//sorts an array of unsigned ints
//using radix sort
void radixSort(unsigned	int * array, int n){
	//allocate scratch memory
	unsigned int * array2 = new unsigned int [n];
	assert(array2 != NULL);

	int nbits = sizeof(unsigned int	) * 8;

	//for all bit positions
	for(int i = 0; i < nbits; i++){

		int j = 0; //index of array2

		//sort 0's first
		for(int k = 0; k < n; k++){
			//check if column i of array[k] is 0
			if((array[k] & (1 << i)) == 0){	//1<<i mask with 1 at bit i
				//array[k] has 0 at bit i
				array2[j] = array[k];
				j++;
			}
		}

		//sort 1's next
		for(int k = 0; k < n; k++){
			//check if bit i of array[k] is 1
			if((array[k] & (1 << i)) != 0){
				//array[k] has 1 at bit i
				array2[j] = array[k];
				j++;
			}
		}

		//copy array2 to array
		memcpy(array, array2, n * sizeof(unsigned int));
	}	//for

	delete [] array2;
}

int main(){
	unsigned int * array = new unsigned int [10];
	
	srand(time(NULL));

	printf("Array: ");
	for(int i = 0; i < 10; i++){
		array[i] = (unsigned int) (rand() % 100 + 1);
		printf("%d ", array[i]);
	}
	printf("\n");

	radixSort(array,10);

	printf("Radix Sorted: ");
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
