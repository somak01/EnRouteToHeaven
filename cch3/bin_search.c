#include<stdio.h>
#define size(x) sizeof(x)/sizeof((*x))
int binary_search(int arr[], int n, int target);
int binary_search2(int arr[], int n, int target);
int main() {
	int t1[] ={1, 2, 3, 4, 5,5, 9};
	int t2[] = {};
	int t3[] = {3, 5, 9, 11, 22, 444};
	printf("%d\t%d\t%d\t", binary_search(t1, size(t1), 6), binary_search(t2, size(t2), 9), binary_search(t3, 6, 444));
	printf("\n%d\n", size(t3));
	printf("%d\t%d\t%d\t", binary_search2(t1, size(t1), 6), binary_search2(t2, size(t2), 9), binary_search2(t3, size(t3), 444));
	
	return 0;
}


int binary_search(int arr[], int n, int target) {
	int left, right, mid;
	
	left = 0;
	right = n-1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] < target) {
			left = mid+1;
		} else if (arr[mid] > target) {
			right = mid-1;
		} else {
			return mid;
		}
	}
	return -1;
}


int binary_search2(int arr[], int n, int target) {
	int left, right, mid;
	left = 0;
	right = n-1;
	while (left <= right && target != arr[mid = (left+right)/2]) {
		if (arr[mid] <= target) {
			left = mid+1;
		} else {
		 	right = mid-1;
		}
	}
	return ((target == arr[mid]) ? mid : -1);
} 
