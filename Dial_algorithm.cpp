#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int src ,vector<vector<int>>&edges){
    vector<vector<vector<int>>>adj(n);
    for(auto e :edges){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
    }
    int max_weight = 0;
    for(auto e :edges){
        max_weight = max(max_weight , e[2]);
    }
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    int  maxDist = (n-1)*max_weight;
    vector<unordered_set<int>> buckets(maxDist + 1);
    buckets[0].insert(src);
//         // Process buckets in order
//     for (int d = 0; d <= maxDist; d++) {
        
//         // Process all nodes in current bucket
//         while (!buckets[d].empty()) {
//             int u = *buckets[d].begin();
//             buckets[d].erase(buckets[d].begin());
            
//             // Skip if we already found a better path
//             if (d > dist[u]) continue;
            
//             // Process all adjacent nodes
//             for (auto& edge : adj[u]) {
//                 int v = edge[0];
//                 int weight = edge[1];
//                 int newDist = dist[u] + weight;
                
//                 // If shorter path found
//                 if (newDist < dist[v]) {
                    
//                     // Remove from old bucket if it was there
//                     if (dist[v] != INT_MAX) {
//                         buckets[dist[v]].erase(v);
//                     }
                    
//                     // Update distance and add to new bucket
//                     dist[v] = newDist;
//                     buckets[newDist].insert(v);
//                 }
//             }
//         }
//     }
    
//     return dist;
// }

// int main() {
//     int n = 9;
//     int src = 0;
//     vector<vector<int>> edges = {
//         {0, 1, 4},
//         {0, 7, 8},
//         {1, 2, 8},
//         {1, 7, 11},
//         {2, 3, 7},
//         {2, 8, 2},
//         {3, 4, 9},
//         {3, 5, 14},
//         {4, 5, 10},
//         {5, 6, 2},
//         {6, 7, 1},
//         {6, 8, 6},
//         {7, 8, 7}
//     };
    
//     vector<int> res = shortestPath(n, src, edges);
//     for (auto val : res) {
//         cout << val << " ";
//     }
//     cout << endl;
//     return 0;
// }
for(int d = 0 ;  d <= maxDist ;d++){
  while(!buckets[d].empty()){
    int u = *buckets[d].begin();
    buckets[d].erase(buckets[d].begin());
    if(d > dist[u] ) continue;
    for( auto &edges : adj[u]){    //in this we are considering the element of each adj[i] and that is e[0] is the next neighbour and e[1] is the weight
        int v = edges[0];
        int weight = edges[1];
        int newDist = weight+dist[u];
        if(newDist<dist[v]){
            if(dist[v]!=INT_MAX){
                buckets[dist[v]].erase(v);
            }
            dist[v] = newDist;
            buckets[newDist].insert(v);
        }
    }
  }
}
return dist;
}
 int main() {
      int n = 9;
          int src = 0;
    vector<vector<int>> edges = {
      {0, 1, 4},
        {0, 7, 8},
        {1, 2, 8},
       {1, 7, 11},
       {2, 3, 7},
      {2, 8, 2},
       {3, 4, 9},
       {3, 5, 14},
        {4, 5, 10},
       {5, 6, 2},
       {6, 7, 1},
       {6, 8, 6},
       {7, 8, 7}
   };
    
    vector<int> res = shortestPath(n, src, edges);
   for (auto val : res) {
       cout << val << " ";
   }
    cout << endl;
    return 0;
}
