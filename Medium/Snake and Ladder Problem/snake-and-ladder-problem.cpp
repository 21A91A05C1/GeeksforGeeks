//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSnakeLadder(int i,map<int,int>&mpp1,map<int,int>&mpp2,vector<int>&dp)
    {
        if(i>=30) return 0;
        int ans=1e9;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=6;j++)
        {
            int k=i+j;
            int pick=0;
            if(mpp1.find(k)!=mpp1.end())
            {
                pick=1+minSnakeLadder(mpp1[k],mpp1,mpp2,dp);
            }
            else if(mpp2.find(k)!=mpp2.end())
            {
                continue;
            }
            else
            {
                pick=1+minSnakeLadder(k,mpp1,mpp2,dp);
            }
            
    
            ans=min(ans,pick);
            
        }
        return dp[i]=ans;
    }
    int minThrow(int N, int arr[]){
        // code here
        map<int,int>mpp1,mpp2;
        for(int i=0;i<2*N;i+=2)
        {
            if(arr[i]<arr[i+1]){
            mpp1[arr[i]]=arr[i+1];
            }
            else{
                mpp2[arr[i]]=arr[i+1];
            }
        }
        vector<int>dp(31,-1);
        return minSnakeLadder(1,mpp1,mpp2,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends