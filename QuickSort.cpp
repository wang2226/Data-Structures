//Quick Sort is a popular "in-place" sorting algorithm that also uses divide and conguer
//Quick Sort Steps: 1. Divide
//					-if array has only one element, return
//					-otherwise choose an element x in s called the "pivot"
//					-divide array into three sets: Less, Equal, Greater
//					 such that the elements in Less are smaller than x
//							   the elements in Equal are equal to x
//							   the elements in Greater are larger than x
//					2. Recur
//					- quickSort(Less), Equal, quickSort(Greater)
//					3. Conquer
//					- put elements in Less, Equal, Greater back into array
// Average case time complexity is O(n*log(n))
// Worst case time complexity is O(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//sort an array of int using quick sort
void quickSortSubrange(int * s, int left, int right);

void quickSort(int * s, int n){
	if(n <= 1) return;
	quickSortSubrange(s,0,n-1);
}

//sort a subrange of array using quick sort
void quickSortSubrange(int * s, int left, int right){
	//base case: return if s has 1 or no elements
	if(left >= right){
		return;
	}

	//use last element as "pivot"
	int x = s[right];
	
	//divide s into Less, Equal, Greater
	int l = left;	//left index
	int r = right-1;	//right index

	//loop until l and r cross
	while(l <= r){
		//move l to the right until we find a number
		//that is larger than the pivot x that should not be in less
		while(l <= r && s[l] < x){
			l++;
		}

		//move r to the left until we find a number
		//that is smaller than the pivot x that should not be in greater
		while(r >= l && s[r] >= x){
			r--;
		}

		//if still l < r and l and r are indexes of elements that should not be in Less and Greater
		//then we will swap them
		if(l < r){
			//swap s[l] and s[r]
			int temp = s[l];
			s[l] = s[r];
			s[r] = temp;
		}
	}	//while

	//move pivot into place
	int temp = s[l];
	s[l] = x;
	s[right] = temp;

	//Less and Greater have been formed
	//recur into Less and Greater
	quickSortSubrange(s,left,l-1);	//Less
	quickSortSubrange(s,l+1,right);	//Greater
}

int main(){
	int * array = new int [10];	
	srand(time(NULL));

	printf("Array: ");
	for(int i = 0; i < 10; i++){
		array[i] = rand() % 100 + 1;
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("After Quick Sort: ");
	quickSort(array,10);
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

