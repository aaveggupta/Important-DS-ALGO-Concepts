/*********************
/Author -> AAVEG GUPTA
*********************/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define vi vector<int>
typedef long long ll;
#define int ll

vector <vi> adj;
vi level, subtree_size;
int n;

void dfs (int currentNode = 1, int parentNode = 0) {

   //cout << currentNode << "\n";
   level[currentNode] = level[parentNode] + 1;
   subtree_size[currentNode] = 1;

   for (auto neighbourNode : adj[currentNode]) {
      if (neighbourNode == parentNode) {
         continue;
      }

      dfs(neighbourNode, currentNode);
      subtree_size[currentNode] += subtree_size[neighbourNode]; 
   }

}

// Level of every Node = level of Parent + 1
// Subtree Size = Subtree size of its children + 1

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> n;

   adj.resize(n + 1);
   level.resize(n + 1);
   subtree_size.resize(n + 1);

   for (int i = 0; i < n - 1; i ++) {
      int u, v;
      cin >> u >> v;

      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   level[0] = -1;
   // Root is 1
   dfs();

   
   for (int i = 1; i <= n; i ++) {
      cout << i << " " << subtree_size[i] << "\n";
   }


   return 0;
}
