//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int,pair<int,int>>>arr;
        vector<int>ans;
        for(int i=0;i<N;i++)
        {
            arr.push_back({F[i],{S[i],i+1}});
        }
        sort(arr.begin(),arr.end());
        // for(auto it:arr)
        // {
        //     cout<<it.first<<" "<<it.second.first<<endl;
        // }
        int prev=0;
        for(int i=0;i<N;i++)
        {
            if(i==0)
            {
                prev=arr[i].first;
                ans.push_back(arr[i].second.second);
            }
            else if(arr[i].second.first>prev)
            {
                ans.push_back(arr[i].second.second);
                prev=arr[i].first;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends