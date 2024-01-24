//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    // bool dfs(vector<int>adj[],int i,vector<int>&vis,int parent)
    // {
    //     vis[i]=1;
    //     for(int j=0;j<adj[i].size();j++)
    //     {
    //         if(adj[i][j]!=parent)
    //         {
    //             if(vis[adj[i][j]]==1) return 1;
    //             bool y=dfs(adj,adj[i][j],vis,i);
    //             if(y==1) return 1;
    //         }
    //     }
    //     return 0;
    // }
    bool dfs(int vis[],vector<int>adj[],int parent,int node)
    {
        vis[node]=1;
        for(int  i = 0 ; i < adj[node].size() ; i++)
        {
            if(adj[node][i]!=parent)
            {
                if(vis[adj[node][i]]==1) return 1;
                bool f=dfs(vis,adj,node,adj[node][i]);
                if(f==1) return 1;
            }
        }
        return 0;
    }
    int isTree(int n, int m, vector<vector<int>> &mat) {
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            int u=mat[i][0];
            int v=mat[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int c=0;
        int vis[n]={0};
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1) 
            {
                int m=dfs(vis,adj,-1,i);
                //int m=dfs(adj,i,vis,-1);
                if(m==1) return 0;
                c++;
            }
            
        }
        if(c<=1) return 1;
        return 0;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends