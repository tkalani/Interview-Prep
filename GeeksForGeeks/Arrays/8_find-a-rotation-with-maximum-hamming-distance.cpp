/*

Hamming distance between two arrays or strings of equal length is the number of positions at which the corresponding character(elements) are different.
    Create another array which is double the size of the original array, such that the elements of this new array (copy array) are just the elements of the original array repeated twice in the same sequence. Example, if the original array is 1 4 1, then the copy array is 1 4 1 1 4 1.
Now, iterate through the copy array and find hamming distance with every shift (or rotation). So we check 4 1 1, 1 1 4, 1 4 1, choose the output for which the hamming distance is maximum.
*/

// C++ program to Find another array 
// such that the hamming distance 
// from the original array is maximum 
#include <bits/stdc++.h> 
using namespace std; 

// Return the maximum hamming distance of a rotation 
int maxHamming(int arr[], int n) 
{ 
	// arr[] to brr[] two times so that 
	// we can traverse through all rotations. 
	int brr[2 *n + 1]; 
	for (int i = 0; i < n; i++) 
		brr[i] = arr[i]; 
	for (int i = 0; i < n; i++) 
		brr[n+i] = arr[i]; 

	// We know hamming distance with 0 rotation 
	// would be 0. 
	int maxHam = 0;	 

	// We try other rotations one by one and compute 
	// Hamming distance of every rotation 
	for (int i = 1; i < n; i++) 
	{ 
		int currHam = 0; 
		for (int j = i, k=0; j < (i + n); j++,k++) 
			if (brr[j] != arr[k]) 
				currHam++; 

		// We can never get more than n. 
		if (currHam == n) 
			return n; 

		maxHam = max(maxHam, currHam); 
	} 

	return maxHam; 
} 

// driver program 
int main() 
{ 
	int arr[] = {2, 4, 6, 8};	 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << maxHamming(arr, n);	 
	return 0; 
} 
