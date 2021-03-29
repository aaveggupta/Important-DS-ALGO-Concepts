# Scanline Algorithm (1D)

### USE-CASE

Suppose you are given an array with N integers, along with this you are given Q queries, every query has 3 values let's call them k, a, b. In each query you are asked to add k to all the integers in the range [a, b] of given array.

### BRUTE-FORCE

The first approach that comes in our mind is Brute Force in which we'll traverse from a to b and add k to all the integers in this range for Q queries.

In the worst case, time complexity will be O(N * Q) 

### BETTER-APPROACH

Make an another array with n capacity initialized with 0. And for each query do the following steps:

- Go to position  $a$ and add $k$  to the value at $a'th$ position.
- Go to position $b$ and subtract $k$ to the value at $(b+1)'th$ position.

**Note:** *If $a'th$  position is less than 0 and take it as 0 and if $(b+1)'th$  position greater than n then ignore that step*

After all the queries convert the array into its Prefix Sum. And add all the elements of old array and modified array index by index.

In the worst case, time complexity will be O(N + Q) *[This is a huge improvement compared to brute force solution]*

### CODE

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n; //Size of Array

  //Input the Array by 1-based Indexing
  //Very Usefull in range based problems
  vector<int> v(n + 1);
  for (int i = 1; i <= n; ++ i)
    cin >> v[i];

  //New Array initialized with zero
  vector<int> newArr(n + 1, 0);

  int q; cin >> q; //Number of Queries
  int k; cin >> k; //Number to be added
  while (q --) {
    int a, b; cin >> a >> b;
    newArr[a] += k;
    if (b + 1 <= n)
    newArr[b + 1] -= k;
  } 

  //Prefix sum of new Array
  for (int i = 2; i <= n; ++ i)
    newArr[i] += newArr[i - 1];

  //Add new and old Array
  for (int i = 1; i <= n; ++ i)
    v[i] += newArr[i];

  for (int i = 1; i <= n; ++ i)
    cout << v[i] << " ";
 
}
```

### INPUT

5
1 2 3 4 5
3 2
1 3
2 5
3 4

### OUTPUT

3 6 9 8 7