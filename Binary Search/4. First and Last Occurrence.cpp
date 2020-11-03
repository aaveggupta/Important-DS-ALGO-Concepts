/*********************
/Author -> AAVEG GUPTA
*********************/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define int ll

// First and Last occurrence of element

int firstOccurrence (vector <int> &v, int element) {
	int s = 0, e = v.size() - 1, res = -1;
	
	while (s <= e) {
		int mid = s + ((e - s) / 2);
		if (v[mid] == element) {
			res = mid;
			e = mid - 1;
		} else if (v[mid] > element) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	
	return res;
}

int lastOccurrence (vector <int> &v, int element) {
	int s = 0, e = v.size() - 1, res = -1;
	
	while (s <= e) {
		int mid = s + ((e - s) / 2);
		if (v[mid] == element) {
			res = mid;
			s = mid + 1;
		} else if (v[mid] > element) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	
	return res;
}

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   
   vector <int> v = {1, 3, 3, 5, 5, 5, 7};
   
   cout << firstOccurrence(v, 5) << "\n";
   cout << lastOccurrence(v, 5);
   
   
 
   return 0;
}
