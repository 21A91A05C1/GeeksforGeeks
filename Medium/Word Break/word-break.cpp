//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int find(string &p,vector<string>&dict)
    {
        
        for(int i=0;i<dict.size();i++)
        {
            if(dict[i]==p) {
                return 1;
                // cout<<p<<" ";
            }
        }
        return 0;
    }
    int check(string &p,string &s,vector<string>&dict,int i,int n)
    {
        
        p+=s[i];
        if(i==n-1){
            // cout<<p<<"";
            if(find(p,dict)){
                return 1;
            } 
            return 0;
        }
        int pick=0,notpick=0;
        if(find(p,dict))
        {
            string t;
            pick=check(t,s,dict,i+1,n);
        }
        notpick=check(p,s,dict,i+1,n);
        
        return pick||notpick;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        string p="";
        int m=s.size();
        return check(p,s,dictionary,0,m);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends