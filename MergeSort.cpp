// Merge sort is a sorting algorithm that uses divide and conquer 
// time complexity is O(n*log(n))
// notes on merge sort: not an "in-place" sort algorithm, meaning that, we can't use the same array to do the sorting

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int * s, int n){
	//sort array s with n elements using merge sort
	if(n <= 1){	//end condition
		return;
	}

	//divide
	//create s1 and s2
	int n1 = n / 2;
	int n2 = n - n1;
	int * s1 = new int [n1];
	int * s2 = new int [n2];

	//put elements into s1,s2
	for(int i = 0; i < n1; i++){
		s1[i] = s[i];
	}

	for(int i = 0; i < n2; i++){
		s2[i] = s[i+n1];
	}

	//call merge sort recursively
	mergeSort(s1,n1);
	mergeSort(s2,n2);

	//s1 and s2 are sorted now
	//merge s1 and s2 into s
	int i1 = 0;	//index for s1
	int i2 = 0;	//index for s2
	int i = 0;	//index for s

	while(i1 < n1 && i2 < n2){
		if(s1[i1] < s2[i2]){
			s[i] = s1[i1];
			i1++;
		} else {
			s[i] = s2[i2];
			i2++;
		}
		i++;
	}	//while

	//copy remaining elements in s1 if any
	for( ; i1 < n1; i1++, i++){
		s[i] = s1[i1];
	}

	//copy remaining elements in s2 if any
	for( ; i2 < n2; i2++, i++){
		s[i] = s2[i2];
	}
	
	//s is sorted
	//delete temporary arrays s1[] and s2[]
	delete [] s1;
	delete [] s2;
}//end of merge sort

int main(){
	int * array = new int [10];
	srand (time(NULL));

	printf("Array is: ");
	for(int i = 0; i < 10; i++){
		array[i] = rand() % 100 + 1;	//range 1 to 100
		printf("%d ", array[i]);
	}
	printf("\n");

	mergeSort(array,10);

	printf("After merge sort: ");
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
