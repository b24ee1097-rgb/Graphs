#include<bits/std++.cpp>
using namespace std;
vector<int> Dijkstra(vector<vector<pair<int,int>>&adj , int src){
    int v = adj.size();
    vector<int> dist(v , INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.emplace(0,src);
    

}