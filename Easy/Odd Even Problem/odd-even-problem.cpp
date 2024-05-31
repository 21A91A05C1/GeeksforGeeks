//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int c=0;
        map<int,int>mpp,cpp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]%2){
                mpp[s[i]]++;
            }
            else{
                cpp[s[i]]++;
            }
        }
        for(auto it:mpp){
            if(it.second%2==1){
                c++;
            }
        }
        for(auto it:cpp){
            if(it.second%2==0){
                c++;
            }
        }
        if(c%2) return "ODD";
        else return "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends