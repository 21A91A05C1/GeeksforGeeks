//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	    int vis[v]={0};
	    for(int i=0;i<v;i++)
	    {
	        for(auto it:adj[i])
	        {
	            vis[it]++;
	        }
	    }
	    for(int i=0;i<v;i++)
	    {
	        if(vis[i]%2) return 0;
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends