//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        map<int,int>mpp;
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<n;i++)
        {
            int k=ans[i-1]-i;
            // cout<<i<<" "<<ans[i-1]<<" "<<i<<endl;
            if(mpp.find(ans[i-1]-i)!=mpp.end() or k<=0)
            {
                ans.push_back(ans[i-1]+i);
                mpp[ans[i-1]+i]++;
            }
            else {ans.push_back(k); mpp[k]++;}
        }
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
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends