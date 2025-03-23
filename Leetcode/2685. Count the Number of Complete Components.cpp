
//What is connected components?
// step-1 to check connected component - total number of edges (n*(n-1)/2) following this condition
// step-2 degree of node is (n-1)

// AFTER DOING DRY-RUN - A connected component is a subgraph of a graph in which there exists a path between any two vertices
// Number of Nodes == Number of edges (which means - A connected component is said to be complete)
// Need Traversal Algorithm 
// DFS,BFS algorithm we have written 100% times

// STEP-1 : Creation of graphs using edeges matrix 2-D
// STEP-2 : Apply BFS/DFS algorithm count number of edges, number of nodes
// STEP-3 : if number of nodes == number of edges) result++
//        : means you have got A connected component

/* DFS template
   visted[i] = true;
   for(auto it : adj[node]){
     // if node is not visited - adj-list node
     // DFS(adjNode,visited,adj)
   }
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
       void BFS(int currNode,vector<int>& visited,unordered_map<int,vector<int>> &adj, int &v, int &e){
          
          // BFS template
          // Create Queue DSA,push startNode into queue, mark visited
          // Explore all connected neighbourNodes with help of adjList
          queue<int> q;
          q.push(currNode);
          visited[currNode] = true;
    
          while(!q.empty()){
            int currNode = q.front();
            q.pop();
    
            v++;
            e += adj[currNode].size();
    
             // Explore all neighbourNodes with help of adj-list
            for(auto neighbourNodes : adj[currNode]){
                if(visited[neighbourNodes] == false){
                     q.push(neighbourNodes);
                     visited[neighbourNodes] = true;
                }
            }
          } 
          // end of BFS function
       }
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
             unordered_map<int,vector<int>> adj;
    
             for(int i = 0; i<edges.size(); i++){
                // there exists an undirected edge connecting vertices ai and bi
                 int a = edges[i][0];
                 int b = edges[i][1];
    
                 adj[a].push_back(b);
                 adj[b].push_back(a);
             }
    
             int NumberCompleteComponents = 0;
    
    
        // VISITED_ARRAY : Keep track node is alredy visited or not alredy visited
             vector<int> visited(n,false);
    
            //All Nodes numbered from 0 to n - 1. 
             for(int node = 0; node<n; node++){
    
                 if(visited[node] == true){
                    continue;
                 }
            // count number of nodes
            // count number of edeges
                 int v = 0;
                 int e = 0;
                 BFS(node,visited,adj,v,e);
    
             //step-1 to check connected component - total number of edges (n*(n-1)/2) following this condition
                 int numberNode = (v*(v-1)/2);
                 int numberEdge = (e / 2);
    
                 cout << numberNode << endl;
                 cout << numberEdge << endl;
    
                 if(numberNode == numberEdge){
                    NumberCompleteComponents = NumberCompleteComponents + 1;
                 }
             }
             return NumberCompleteComponents;
        }
    };