/*********************
/Author -> AAVEG GUPTA
*********************/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define int ll


// BINARY SEARCH
// Time Complexity -> O(log(n)) 
int binarySearch(vector <int> v, int element) {
	int start = 0, end = v.size() - 1;
	
	while (start <= end) {
	//	int mid = (start + end) / 2; -> Start and end are very big then there may be int overflow
	//  To avoid this Write like below
		int mid = start + ((end - start) / 2);
		
		if (v[mid] == element) {
			return mid;
		} else if (v[mid] > element) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	
	return -1;
	
}


signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   
   int n;
   cin >> n;
   
   vector <int> v(n);
   for (int i = 0; i < n; i ++) {
   	cin >> v[i];
   }
   
   int element;
   cin >> element;
   
   int ind = binarySearch(v, element);
   
   cout << ind;
 
   return 0;
}
