//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        int dp[100006][2][2];
        int maxShare(vector<int>&price,int buy,int i,int n ,int c)
        {
             if(i>=n) return 0;
            if(c==2) return 0;
            if(i==n-1)
            {
                if(buy==0)
                {
                    return price[i];
                }
                else
                {
                    return 0;
                }
            }
            
            int pick=0,notpick=0;
            if(dp[i][buy][c]!=-1) return dp[i][buy][c];
            if(buy)  //  1 -- buy
            {
                pick=-price[i]+maxShare(price,0,i+1,n,c);
            }
            else
            {
                pick=price[i]+maxShare(price,1,i+1,n,c+1);
                // notpick=maxShare(price,0,i+1,n,c);
            }
            notpick=maxShare(price,buy,i+1,n,c);
            return dp[i][buy][c]=max(pick,notpick);
        }
        int maxProfit(vector<int>&price){
            //Write your code here..
            int i=0,buy=1,n=price.size(),c=0;
            memset(dp,-1,sizeof(dp));
           // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
            return maxShare(price,buy,i,n,c);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends