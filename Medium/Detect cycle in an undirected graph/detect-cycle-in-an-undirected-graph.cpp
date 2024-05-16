//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    int dfs(vector<int>adj[],vector<int>&vis,int i,int par)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it]){
                if(dfs(adj,vis,it,i)) return 1;
            }
            else{
                if(it!=par){
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V+1,0);
        for(int i=0;i<V;i++)
        {
            int k=0;
            if(!vis[i]){
                k=dfs(adj,vis,i,-1);
                if(k==1) return 1;
            }
        }
        return 0;
    }
    // 1->2->3
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends