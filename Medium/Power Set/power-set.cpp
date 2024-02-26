//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void findPowerSet(vector<string>&ans,string &k,string &s,int i)
	    {
	        if(i>=s.size())
	        {
	            if(!k.empty()) ans.push_back(k);
	            return ;
	        }
	        k+=s[i];
	        findPowerSet(ans,k,s,i+1);
	        k.pop_back();
	        findPowerSet(ans,k,s,i+1);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    
		    string k="";
		    findPowerSet(ans,k,s,0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends