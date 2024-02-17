//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<vector<int>>& adj,int i,vector<int>&vis,vector<int>&ans)
	{
	    
	    vis[i]=1;
	    for(auto it:adj[i]){
	        if(!vis[it]){
	            dfs(adj,it,vis,ans);
	        }
	    }
	    ans.push_back(i);
	}
	void dfs(vector<int>adj[],int i,vector<int>&vis,vector<int>&ans)
	{
	    
	    vis[i]=1;
	    for(auto it:adj[i]){
	        if(!vis[it]){
	            dfs(adj,it,vis,ans);
	        }
	    }
	    ans.push_back(i);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>ans;
        vector<int>vis(V,0);
        for(int i=0 ; i <V ;i++)
        {
            if(!vis[i]){
                dfs(adj,i,vis,ans);
            }
        }
        // for(auto it:ans)
        // {
        //     cout<<it<<" ";
        // }
        vector<int>adjT[V];
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                // cout<<"ji";
                adjT[it].push_back(i);
            }
        }
        //cout<<endl;
        reverse(ans.begin(),ans.end());
        vector<int>ans1;
        vector<int>vis1(V,0);
        int c=0;
        for(int i=0 ; i <ans.size() ;i++)
        {
            if(!vis1[ans[i]]){
                dfs(adjT,ans[i],vis1,ans1);
                c++;
            }
        }
        // for(auto it:ans1)
        // {
        //     cout<<it<<" ";
        // }
        return c;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends