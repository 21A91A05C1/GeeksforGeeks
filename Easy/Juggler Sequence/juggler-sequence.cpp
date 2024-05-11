//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        // code here
        int c=n;
        vector<int>ans;
        ans.push_back(n);
        // c--;
        while(n>1)
        {
            int k=0;
            if(n%2)
            {
                k=pow(n,3*1.0/2);
            }
            else{
                k=pow(n,1*1.0/2);
            }
            
            ans.push_back(k);
            n=k;
            // break;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends