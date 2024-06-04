//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int n=s.size();
        int i=n-1;
        if(s[n-1]=='0'){
            s[n-1]='1';
        }
        else{
            while(i>=0 and s[i]!='0'){
                s[i]='0';
                i--;
            }
            if(i>=0 and s[i]=='0'){
                s[i]='1';
            }
            else{
                s='1'+s;
            }
            
        }
        string ans="";
        int f=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0' and f==0){
                continue;
            }
            else{
                f=1;
                ans+=s[i];
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends