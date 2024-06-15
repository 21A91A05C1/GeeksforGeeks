//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long checkPossible(int i ,int j,vector<vector<int>>&mat,long long p,vector<vector<vector<long long >>>&dp)
    {
        if(p<=0)
        {
            // cout<<" hi ";
            return 1;
        }
        if(dp[i][j][p]!=-1) return dp[i][j][p];
        long long pick=0;
        int newrow[5]={-1,0,+1,0,0};
        int newcol[5]={0,+1,0,-1,0};
        for(int k=  0 ; k <5 ;k++)
        {
            int ni=i+newrow[k];
            int nj=j+newcol[k];
            if(ni>=0 and nj>=0 and ni<mat.size() and nj<mat[0].size() and mat[ni][nj]!=-1)
            {
                // cout<<"hi"<<" ";
                pick+=checkPossible(ni,nj,mat,p-1,dp);
            }
        }
        return dp[i][j][p]=pick;
        
    }
    long long getCount(int n) {
        // Your code goes here
        //forming the mobile with digits
        vector<vector<int>>mat(4,vector<int>(3,0));
        int s=1;
        for(int i = 0 ; i <3 ;i++)
        {
            for(int j = 0 ; j<3 ;j++)
            {
                mat[i][j]=s;
                s++;
            }
        }
        mat[3][0]=-1;
        mat[3][1]=0;
        mat[3][2]=-1;
        if(n==1) return 10;
        int l=mat.size();
        int m=mat[0].size();
        vector<vector<vector<long long >>>dp(l,vector<vector<long long >>(m,vector<long long >(26,-1)));
        long long ans=0;
        for(int  i = 0 ; i <4; i++)
        {
            for(int j= 0 ; j <3 ;j++)
            {
                if(mat[i][j]!=-1)
                {
                    long long l=n,w=0;
                    ans+=checkPossible(i,j,mat,l-1,dp);
                }
            }
        }
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

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends