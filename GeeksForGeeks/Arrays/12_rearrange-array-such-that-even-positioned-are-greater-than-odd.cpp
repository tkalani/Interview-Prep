/*
    Observe that array consists of [n/2] even positioned elements. If we assign largest [n/2] elements to the even positions and rest of the elements to the odd positions, our problem is solved. Because element at odd position will always be less than the element at even position as it is maximum element and vice versa. Sort the array and assign the first [n/2] elements at even positions.
*/

// C++ program to rearrange the elements 
// in array such that even positioned are 
// greater than odd positioned elements 
#include<bits/stdc++.h> 
using namespace std; 

void assign(int a[], int n) 
{ 
	// Sort the array 
	sort(a, a + n); 

	int ans[n]; 
	int p = 0, q = n - 1; 
	for (int i = 0; i < n; i++) 
	{ 
		// Assign even indexes with maximum elements 
		if ((i + 1) % 2 == 0) 
			ans[i] = a[q--]; 

		// Assign odd indexes with remaining elements 
		else
			ans[i] = a[p++]; 
	} 

	// Print result 
	for (int i = 0; i < n; i++) 
		cout << ans[i] << " "; 
} 

// Driver Code 
int main() 
{ 
	int A[] = { 1, 3, 2, 2, 5 }; 
	int n = sizeof(A) / sizeof(A[0]); 
	assign(A, n); 
	return 0; 
} 
