/*********************
/Author -> AAVEG GUPTA
*********************/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define int ll


// BINARY SEARCH ON ORDER AGNOSTIC SEARCH
// In this case, we don't know whether array is in asc or desc order

int binarySearchDesc(vector <int> v, int element) {
	int start = 0, end = v.size() - 1;
	
	while (start <= end) {

		int mid = start + ((end - start) / 2);
		
		if (v[mid] == element) {
			return mid;
		} else if (v[mid] > element) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	
	return -1;
}

int binarySearchAsc(vector <int> v, int element) {
	int start = 0, end = v.size() - 1;
	
	while (start <= end) {

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
   
   int ind;
   
   if (v[0] < v[n - 1]) {
   	ind = binarySearchAsc(v, element);
   } else {
   	ind = binarySearchDesc(v, element);
   }
   
   cout << ind;
 
   return 0;
}
