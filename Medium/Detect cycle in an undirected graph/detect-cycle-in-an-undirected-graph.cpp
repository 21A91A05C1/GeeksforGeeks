//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int>adj[]) {
        // cout<<V<<" ";
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                queue<pair<int,int>>qu;
                qu.push({i,-1});
                vis[i]=true;
                while(!qu.empty())
                {
                    int node=qu.front().first;
                    // cout<<node<<" ";
                    int parent=qu.front().second;
                    qu.pop();
                    for(auto it:adj[node])
                    {
                        if(!vis[it]){
                            qu.push({it,node});
                            vis[it]=true;
                        }
                        else{
                            if(it!=parent) return 1;
                        }
                    }
                }
            }
        }
        return 0;
       
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