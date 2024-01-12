//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int>p;
    void precompute(){
        vector<int>primes(1e6+1,1);
        primes[0]=0;
        primes[1]=0;
        for(int i=2;i*i<=1e6+1;i++)
        {
            if(primes[i]==1)
            {
                for(int j=i*i;j<=1e6+1;j+=i)
                {
                    primes[j]=0;
                }
            }
        }
        for(int i=2;i<=1e6+1;i++)
        {
            if(primes[i]) p.push_back(i);
        }
    }
    
    void dfs(vector<int>adj[],int &c,int vis[],int i)
    {
        vis[i]=1;
        c++;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(adj,c,vis,it);
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        vector<int>adj[n+1];
        int vis[n+1]={0};
        for(auto it:g)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int i=0;i<n+1;i++)
        {
            
            if(!vis[i])
            {
                int c=0,d=0;
                dfs(adj,c,vis,i);
                //cout<<c<<" ";
                ans=max(ans,c);
            }
            //cout<<endl;
        }
        //cout<<ans<<" ";
        if(ans==1) return -1;
        return p[ans-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g;
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g.push_back({u, v});
// 			g[u].push_back(v);
// 			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends