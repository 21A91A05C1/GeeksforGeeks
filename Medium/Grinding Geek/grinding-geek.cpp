//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int fun(vector<int>&cost,int i,int n,int money,vector<vector<int>>&dp)
    {
        if(i>=n) return 0;
        if(dp[i][money]!=-1) return dp[i][money];
        int pick=0,notpick=0;
        int rem=(cost[i]*90)/100;
        //cost[i]=rem;
        //cout<<money-cost[i]+rem<<" ";
        if(money>=cost[i]){
            pick+=1+fun(cost,i+1,n,money-cost[i]+rem,dp);
        }
        
        notpick+=fun(cost,i+1,n,money,dp);
        
        return dp[i][money]=max(pick,notpick);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        int money=total,ans=0,s=0;
        s+=total;
        for(auto it:cost) s+=it;
        // for(int i=0;i<cost.size();i++)
        // {
        //     if(money>=cost[i])
        //     {
        //         int rem=(cost[i]*90.0)/100.0;
        //         cout<<rem<<" ";
        //         money-=(cost[i]-rem);
        //         cout<<money<<endl;
        //         ans++;
        //     }
        // }
        vector<vector<int>>dp(n+1,vector<int>(total+1,-1));
        return fun(cost,0,n,money,dp);
        // return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends