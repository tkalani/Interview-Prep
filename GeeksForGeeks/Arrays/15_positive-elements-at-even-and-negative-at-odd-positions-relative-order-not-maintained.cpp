/*
    We take two pointers positive and negative. We set the positive pointer at start of the array and the negative pointer at 1st position of the array.
We move positive pointer two steps forward till it finds a negative element. Similarly we move negative pointer forward by two places till it finds a positive value at its position.
If the positive and negative pointers are in the array then we will swap the values at these indexes otherwise we will stop executing the process.
*/

// C++ program to rearrange positive and negative 
// numbers 
#include <bits/stdc++.h> 
using namespace std; 

void rearrange(int a[], int size) 
{ 
	int positive = 0, negative = 1; 

	while (true) { 

		/* Move forward the positive pointer till 
		negative number number not encountered */
		while (positive < size && a[positive] >= 0) 
			positive += 2; 

		/* Move forward the negative pointer till 
		positive number number not encountered */
		while (negative < size && a[negative] <= 0) 
			negative += 2; 

		// Swap array elements to fix their position. 
		if (positive < size && negative < size) 
			swap(a[positive], a[negative]); 

		/* Break from the while loop when any index 
			exceeds the size of the array */
		else
			break; 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, -3, 5, 6, -3, 6, 7, -4, 9, 10 }; 
	int n = (sizeof(arr) / sizeof(arr[0])); 

	rearrange(arr, n); 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 

	return 0; 
} 
