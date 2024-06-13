//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod=1e9+7;
    int padovanSequence(int n) {
        // code here.
        int p0=1,p1=1,p2=1;
        if(n<=2) return 1;
        for(int i= 3 ;i <=n ; i++)
        {
            int c=(p0+p1)%mod;
            p0=p1%mod;
            p1=p2%mod;
            p2=c%mod;
        }
        return p2%mod;
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends