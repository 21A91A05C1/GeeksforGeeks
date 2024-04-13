//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void checkAllPossibleWays(vector<vector<int>>&maze,int n,vector<string>&ans,string s,int i,int j
    ,vector<vector<int>>&vis)
    {
        if(i<0 or j<0 or i>=n or j>=n or maze[i][j]==0) return ;
        if(i==n-1 and j==n-1){
            ans.push_back(s);
            return ;
        }
        
        if(vis[i][j]==0){
            vis[i][j]=1;  
            checkAllPossibleWays(maze,n,ans,s+"D",i+1,j,vis);
            // checkAllPossibleWays(maze,n,ans,s+"U",i-1,j,vis);
            // checkAllPossibleWays(maze,n,ans,s+"R",i,j+1,vis);
            vis[i][j]=0;  
        }
        if(vis[i][j]==0){
            vis[i][j]=1;  
            checkAllPossibleWays(maze,n,ans,s+"U",i-1,j,vis);
            vis[i][j]=0;
        }
        if(vis[i][j]==0){
            vis[i][j]=1;  
            checkAllPossibleWays(maze,n,ans,s+"R",i,j+1,vis);
            vis[i][j]=0;
        }
        if(vis[i][j]==0){
            vis[i][j]=1;  
            checkAllPossibleWays(maze,n,ans,s+"L",i,j-1,vis);
            vis[i][j]=0;
        }
        return ;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
        string s="";
        // vis[0][0]=1;
        checkAllPossibleWays(m,n,ans,s,0,0,vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends