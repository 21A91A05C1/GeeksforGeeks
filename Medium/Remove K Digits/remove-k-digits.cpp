//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        stack<char>st;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                while(!st.empty() and s[i]<st.top() and k>0) {
                    k--;
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(k--)
        {
            st.pop();
        }
        string res="";
        while(!st.empty()){
            char i=st.top();
            st.pop();
            res+=i;
        }
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();i++)
        {
            if(res[i]=='0' and ans.size()==0) {
                continue;
            }
            else {
                ans+=res[i];
            }
            
        }
        if(ans.size()==0) ans+='0';
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends