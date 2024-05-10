//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    set<vector<int>>st;
    void combinations(vector<int>&arr,int n,int k,int sum,vector<vector<int>>&ans,vector<int>&a,int i)
    {
        if(sum==k){
                st.insert(a);
                return ;
        }
        if(i>=n)    return ;
        if((sum+arr[i])<=k){
            a.push_back(arr[i]);
            combinations(arr,n,k,sum+arr[i],ans,a,i+1);
            a.pop_back();
        }
        combinations(arr,n,k,sum,ans,a,i+1);
        // return ;
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        vector<int>a;
        combinations(arr,n,k,0,ans,a,0);
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends