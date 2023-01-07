//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;
        
        for(int nextNode : adj[node]) {
            // if it's not visited, traverse it
            if(!visited[nextNode]) {
                // if it is not visited then it is not path visited
                // if subtree has a cycle then return true
                if (dfs(nextNode, adj, visited, pathVisited)) return true;
            } else if(pathVisited[nextNode]){
                // if it is visited and also path visited
                return true;
            }
        }
        
        pathVisited[node] = false;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        for(int i = 0; i < V; i += 1) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, pathVisited)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends