/*
    Another Approach : There is another method to do so. In c++ STL, There is an inbuilt function std::sort(). We can modify the comp() function to obtain the desired result. As we have to place negative numbers first and then positive numbers. We also have to keep zero’s(if present) between positive and negative numbers.

The comp() function in this code rearranges the given array in required order. Here in bool comp(int a, int b), if integer ‘a’ is of j-th index and integer ‘b’ is of i-th index elements in the arr[], then j>i. comp() function will be called in this way. If the comp() return true then swap will be done.
*/

// CPP program to rearrange positive 
// and negative integers keeping 
// order of elements. 
#include <bits/stdc++.h> 

using namespace std; 

bool comp(int a, int b) 
{ 

// swap not needed 
if((a > 0 && b > 0) || 
(a < 0 && b < 0) || 
(a > 0 && b < 0 )) 
return false; 

// swap needed 
if(a < 0 && b > 0) 
return true; 

// swap not needed 
if((a == 0 && b < 0) || 
(a > 0 && b == 0)) 
return false; 

// swap needed 
if((a == 0 && b > 0) || 
(a < 0 && b == 0)) 
return true; 

} 

void rearrange(int arr[], int n) 
{ 
	sort(arr, arr + n, comp); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { -12, 11, -13, -5, 
				6, -7, 5, -3, -6 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	rearrange(arr, n); 
	for (int i = 0; i < n; i++) 
		cout << " " << arr[i]; 

	return 0; 
} 
