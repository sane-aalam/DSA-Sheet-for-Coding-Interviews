
// Notice that, if u and v are not connected then the answer is -1, 
// otherwise we can use all the edges from the connected component where both belong to.
// DSU algorithm:
// Combine 2 sets (union)
// to this belong to find(x,w) to given set or NOT.

// STEP1: dsu (find,union)
// STEP2: prarent, cost(-1)
// STEP3: process each edge & calcualate the parent, cost
// STEP4: process the query 

#include<bits/stdc++.h>
using namespace std;
// namespace std - telling the compiler to consider all the names in the std namespace as if they're in the global namespace.

class Solution {

    // STEP1: dsu (find,union)
    public:
       vector<int> parent;
       // find - DSU
       int find(int x){
          if(parent[x] == x){
            return x;
          }
          return parent[x] = find(parent[x]);
       }
       // union - DSU
       void Union(int x, int y){
           parent[y] = x;
       }
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
          // parent array of each node
          // Who are my parent node, starting me [khud hi parent node hai]
          // Apnu hi bhagwan hai khud ka
            parent.resize(n);
    
          // STEP2: prarent, cost(-1)
          // Store "And operation" cost of each component
           vector<int> cost(n);  
            
            for(int i = 0; i<n; i++) {
                parent[i] = i;
                cost[i]   = -1;
            }
    
            // STEP3: process each edge & calcualate the parent, cost
            // cost for each edge, combine
    
            for(auto & it : edges){
                int u = it[0];
                int v = it[1];
                // edge weights
                int w = it[2];
    
                int parent_u = find(u);
                int parent_v = find(v);
    
                if(parent_u != parent_v){
                    // are not are belong same set, combine them, but cost of both them AND bitwise you have to do.
                    cost[parent_u] &= cost[parent_v];
                    Union(parent_u, parent_v);
                }
    
                // perform edge weights AND opreation 
                cost[parent_u] &= w;
            }
    
            // STEP4: processing all queries given query = [[0,3],[3,4]]
               vector<int> result;
               
               for(auto &it : query){
                  int startNode = it[0];
                  int endNode = it[1];
    
                  // kya startNode, endNode, same union set me belong karte hai
                  int p1 = find(startNode);
                  int p2 = find(endNode);
    
                // START_END (same node), NOT POSSIBLE TO MOVE, STORE-0
                  if(startNode == endNode){
                     result.push_back(0);
                // CASE-1 p1 and p2 are not same parent child (-1), are not same set belong 
                  }else if(p1 != p2){
                    result.push_back(-1);
                  }else{
                     result.push_back(cost[p1]);
                  }
               }
    
    
            // STEP:5 return result
    
            return result;
        }
    };