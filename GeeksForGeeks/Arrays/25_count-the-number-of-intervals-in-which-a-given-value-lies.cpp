// C++ program to count the 
// number of intervals in which 
// a given value lies 
#include<bits/stdc++.h> 
using namespace std; 

const int MAX_VAL = 200000; 

// Function to count the 
// number of intervals in which 
// a given value lies 
int countIntervals(int arr[][2], int V, int N) 
{ 
	// Variables to store overall minimum and 
	// maximum of the intervals 
	int min = INT_MAX; 
	int max = INT_MIN; 

	// Variables to store start and 
	// end of an interval 
	int li, ri; 

	// Frequency array to keep track of 
	// how many of the given intervals 
	// an element lies in 
	int freq[MAX_VAL]; 

	for (int i = 0; i < N; i++) 
	{ 
		li = arr[i][0]; 
		freq[li] = freq[li] + 1; 
		ri = arr[i][1]; 
		freq[ri + 1] = freq[ri + 1] - 1; 

		if (li < min) 
			min = li; 
		if (ri > max) 
			max = ri; 
	} 

	// Constructing the frequency array 
	for (int i = min; i <= max; i++) 
		freq[i] = freq[i] + freq[i - 1]; 

	return freq[V]; 
} 

// Driver code 
int main() 
{ 
	int arr[5][2] = { { 1, 10 }, { 5, 10 }, 
					{ 15, 25 }, { 7, 12 }, 
					{ 20, 25 } }; 

	int V = 7; 

	// length of the array 
	int N = sizeof(arr) / sizeof(arr[0]); 

	cout << (countIntervals(arr, V, N)); 
} 

// This code is contributed by 
// Surendra_Gangwar 
