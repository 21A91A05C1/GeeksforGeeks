//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void findBinaryNum(int n,int z,int o,int i,string &s,vector<string>&ans)
    {
        if(i>=n){
            ans.push_back(s);
            return ;
        }
        if(o>=z)
        {
            s+='1';
            findBinaryNum(n,z,o+1,i+1,s,ans);
            s.pop_back();
        }
        if(z<o){
            s+='0';
            findBinaryNum(n,z+1,o,i+1,s,ans);
            s.pop_back();
        }
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>ans;
	    string s;
	    findBinaryNum(n,0,0,0,s,ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends