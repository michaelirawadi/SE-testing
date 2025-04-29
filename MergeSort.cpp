#include<stdio.h>

void printArray(int arr[], int size){
	for(int i=0; i<size; i++){
		printf(" %d", arr[i]);
	}
	printf("\n");
}

void sort(int arr[], int left, int mid, int right){
	const int leftSize = mid - left + 1;
	const int rightSize = right - mid;
	
	int leftArray[leftSize];
	int rightArray[rightSize];
	
	for(int i=0; i<leftSize; i++){
		leftArray[i] = arr[i+left];
	}
	for(int i=0; i< rightSize; i++){
		rightArray[i] = arr[i+mid+1];
	}
	
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = left;
	
	while(leftIndex < leftSize && rightIndex < rightSize){
		int currentLeft = leftArray[leftIndex];
		int currentRight = rightArray[rightIndex];// 
		
		if(currentLeft < currentRight){
			arr[mergedIndex] = currentLeft;
			leftIndex++;
		}
		else{
			arr[mergedIndex] = currentRight;
			rightIndex++;
		}
		mergedIndex++;
	}
	while(rightIndex < rightSize){
		int currentRight = rightArray[rightIndex];
		arr[mergedIndex] = currentRight;
		mergedIndex++;
		rightIndex++;
	}
	while(leftIndex < leftSize){
		int currentLeft = leftArray[leftIndex];
		arr[mergedIndex] = currentLeft;
		mergedIndex++;
		leftIndex++;
	}
}

void mergeSort(int arr[], int left, int right){
	if(left >= right){
		return;
	}
	
	int mid = (left+right)/2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	sort(arr, left, mid, right);
}

int main(){
	
	int arr[] = {12, 11, 13, 5, 6, 7};	
	int size = sizeof(arr)/sizeof(arr[0]);
//	int size = sizeof(arr)/sizeof(int); // bisa pake ini juga (kalo variable nya int)
	
	printf("Before: ");
	printArray(arr, size);
	
	mergeSort(arr, 0, size-1);	
	printf("After: ");
	printArray(arr, size);
	
	return 0;
}
