//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int s=0;
        int p=0;
        // for(int i=0;i<=31;i++)
        // {
        //     p=(1<<i)&n;
        // }
        for(int i=3;i>=0;i--)
        {
            // s=s|((1<<(i))&n);
            if((1<<i)&n){
                // cout<<pow(2,(i+3))<<" ";
                s+=pow(2,(i+4));
            }
            // cout<<(1<<i)
        }
        for(int i=7;i>=4;i--){
            // s=s|((1<<(i))&n);
            if((1<<i)&n){
                // cout<<pow(2,(i+3))<<" ";
                // cout<<pow(2,(i-4))<<" ";
                s+=pow(2,(i-4));
            }
        }
        return s;
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
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends