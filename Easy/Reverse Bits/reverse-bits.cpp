//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        // long long arr[32];
        long long arr=0;
        for(int i=0;i<32;i++)
        {
            if(x&(1<<i)){
                arr+=pow(2,31-i);
            }
        }
        // reverse(arr.begin(),arr.end());
        // cout<<arr<<" ";
        return arr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends