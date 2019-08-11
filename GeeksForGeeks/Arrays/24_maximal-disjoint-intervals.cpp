// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 

// Function to sort the vector elements 
// by second element of pairs 
bool sortbysec(const pair<int, int>& a, 
			const pair<int, int>& b) 
{ 
	return (a.second < b.second); 
} 

// Function to find maximal disjoint set 
void maxDisjointIntervals(vector<pair<int, int> > list) 
{ 

	// Sort the list of intervals 
	sort(list.begin(), list.end(), sortbysec); 

	// First Interval will always be 
	// included in set 
	cout << "[" << list[0].first << ", "
		<< list[0].second << "]" << endl; 

	// End point of first interval 
	int r1 = list[0].second; 

	for (int i = 1; i < list.size(); i++) { 
		int l1 = list[i].first; 
		int r2 = list[i].second; 

		// Check if given interval overlap with 
		// previously included interval, if not 
		// then include this interval and update 
		// the end point of last added interval 
		if (l1 > r1) { 
			cout << "[" << l1 << ", "
				<< r2 << "]" << endl; 
			r1 = r2; 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	int N = 4; 
	vector<pair<int, int> > intervals = { { 1, 4 }, 
										{ 2, 3 }, 
										{ 4, 6 }, 
										{ 8, 9 } }; 
	maxDisjointIntervals(intervals); 

	return 0; 
} 
