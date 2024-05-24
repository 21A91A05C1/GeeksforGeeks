//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
    int findPossible(vector<int>&arr,int i,int target,int s,vector<vector<int>>&dp)
    {
        if(i>=arr.size()){
            if(s==target){
                return 1;
            }
            return 0;
        }
        if(dp[i][s]!=-1) return dp[i][s];
        int pick=0,notpick=0;
        pick=findPossible(arr,i+1,target,s+arr[i],dp)%mod;
        notpick=findPossible(arr,i+1,target,s,dp)%mod;
        return dp[i][s]=(pick+notpick)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        // sum*=1.0;
        // cout<<sum*1.0<<" ";
        double p=(double)(sum-d)/2.0;
        // cout<<p<<" ";
        // int total=accumulate(arr.begin(),arr.end(),0);
        // double t=(double)(total-d)/2.0;
        // cout<<t<<" ";
        if(p!=int(p)) return 0;
        // return 0;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return findPossible(arr,0,p,0,dp);
        // 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends