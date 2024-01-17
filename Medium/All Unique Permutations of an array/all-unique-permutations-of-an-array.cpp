//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void findAllPermutations(vector<int>&arr,int n,vector<vector<int>>&ans,vector<int>&a
    ,vector<int>&vis)
    {
        if(arr.size()==a.size()) 
        {
            ans.push_back(a);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1){
                vis[i]=1;
                a.push_back(arr[i]);
                findAllPermutations(arr,n,ans,a,vis);
                vis[i]=0;
                a.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        // set<vector<intvector<int>>st;
        vector<vector<int>>ans;
        vector<int>a;
        vector<int>vis(n,0);
        findAllPermutations(arr,n,ans,a,vis);
        set<vector<int>>st;
        for(auto it:ans) st.insert(it);
        vector<vector<int>>bns;
        for(auto it:st)
        {
            bns.push_back(it);
        }
        return bns;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends