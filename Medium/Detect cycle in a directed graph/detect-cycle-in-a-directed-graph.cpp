//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int>adj[],int i,vector<bool>&vis,vector<int>&ans,
    vector<bool>&pathVis)
    {
        vis[i]=true;
        pathVis[i]=true;
        for(auto it:adj[i])
        {
            if(pathVis[it]==true) return true;
            if(!vis[it])
            {
                if(dfs(adj,it,vis,ans,pathVis)) return true;
            }
        }
        pathVis[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>ans;
        vector<bool>vis(V,false);
        vector<bool>pathVis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,i,vis,ans,pathVis)) return 1;
            }
        }
        return 0;
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