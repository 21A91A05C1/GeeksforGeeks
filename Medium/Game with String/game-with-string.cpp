//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue<int>pq;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        for(auto it:mpp)
        {
            pq.push(it.second);
        }
        while(!pq.empty() and k>0)
        {
            int l=pq.top();
            l--;
            pq.push(l);
            pq.pop();
            k--;
        }
        int ans=0;
        while(!pq.empty())
        {
            int l=pq.top();
            ans+=pow(l,2);
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends