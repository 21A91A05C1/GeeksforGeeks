//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution
{
    
    public:
    void bfs(queue<int>&qu,vector<int>&indeg,vector<int>adj[],vector<int>&ans)
    {
        while(!qu.empty())
        {
            int n=qu.front();
            qu.pop();
            ans.push_back(n);
            for(auto it:adj[n])
            {
                indeg[it]--;
                if(indeg[it]==0) qu.push(it);
            }
        }
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        vector<int>ans;
        vector<int>adj[n];
        queue<int>qu;
        vector<int>indeg(n,0);
        for(int i=0;i<pre.size();i++)
        {
            int v=pre[i][0];
            int u=pre[i][1];
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indeg[it]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0) qu.push(i);
        }
        //if(qu.empty()) return {};
        bfs(qu,indeg,adj,ans);
        // for(auto it:ans)
        // {
        //     cout<<it<<" ";
        // }
        if(ans.size() != n) return {};
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends