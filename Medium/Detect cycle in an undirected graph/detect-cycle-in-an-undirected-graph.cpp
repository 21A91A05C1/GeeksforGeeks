//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool ans=false;
    void DFS(vector<bool>&vis,vector<int>adj[],int i,int par)
    {
        vis[i]=true;
        for(auto it:adj[i])
        {
            if(!vis[it]){
                DFS(vis,adj,it,i);
            }
            else{
                if(it!=par){
                    ans=true;
                    return ;
                }
            }
        }
    }
    bool isCycle(int V,vector<int>adj[]) {
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                DFS(vis,adj,i,-1);
            }
        }
        return ans;
    }
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