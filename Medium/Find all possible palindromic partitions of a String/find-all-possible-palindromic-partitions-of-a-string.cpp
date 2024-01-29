//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool ispal(string &p)
    {
        string r=p;
        reverse(p.begin(),p.end());
        return r==p;
    }
    void checkPartitions(string &s,vector<vector<string>>&ans,vector<string>&m,int n,int j)
    {
        if(j==n)
        {
            ans.push_back(m);
            return ;
        }
        for(int i=j;i<n;i++)
        {
            string p=s.substr(j,i-j+1);
            if(ispal(p))
            {
                m.push_back(p);
                checkPartitions(s,ans,m,n,i+1);
                m.pop_back();
            }
            //else return ;
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        int n=S.size();//
        vector<string>m;//
        vector<vector<string>>ans;//
        checkPartitions(S,ans,m,n,0);//
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends