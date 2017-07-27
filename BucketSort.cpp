// Bucket Sort
// It is a sorting algorithm useful to sort large sequence of numbers that have a small range of values.
// Algorithm:	1.Create m empty buckets.
//				2.Insert array[i] into bucket[m * array[i]].
//				3.Sort individual buckets using insertion sort.
//				4.Concatenate all sorted buckets.
// Time Complexity: O(n + m) since n >> m, ~= **O(n)**

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int * array, int n){
	int * bucket = new int [n];

	int i, j;

	for(i = 0; i < n; i++){	//initialize bucket	
		(bucket[i] = 0);
	}

	for(i = 0; i < n; i++){	//add to bucket
		(bucket[array[i]])++;
	}

	for(i = 0, j = 0; i < n; i++){
		while(bucket[i] > 0){
			array[j++] = i;
			bucket[i]--;
		}
	}

	delete [] bucket;
}

int main(){
	int * array = new int [20];
	srand(time(NULL));

	printf("Array: ");
	for(int i= 0; i < 20; i++){
		array[i] = rand() % 10 + 1;
		printf("%d ", array[i]);
	}
	printf("\n");

	bucketSort(array,20);

	printf("Bucket Sort: ");
	for(int i = 0; i < 20; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
