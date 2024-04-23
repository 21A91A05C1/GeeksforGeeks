//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
int mod=1000000007;
    int checkPaths(int x,int y,vector<vector<int>>&dp)
    {
        if(x==0 and y==0){
            return 1;
        }
        else if(x<0 or y<0){
            return 0;
        }
        if(dp[x][y]!=-1) return dp[x][y];
        int left=0,down=0;
        left=checkPaths(x-1,y,dp);
        down=checkPaths(x,y-1,dp);
        
        return dp[x][y]=((left)%mod+(down)%mod)%mod;
            
    }
    int ways(int x, int y)
    {
        //code here.
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return checkPaths(x,y,dp)%mod;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends