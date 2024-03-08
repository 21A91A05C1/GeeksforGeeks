//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char,int>mpp;
	    unordered_map<int,int>cpp;
	   // sort(s.begin(),s.end());
	    for(int i=0;i<s.size();i++)
	    {
	        mpp[s[i]]++;
	    }
	    for(auto it:mpp)
	    {
	        cpp[it.second]++;
	       // cout<<it.second<<" ";
	    }
	   // for(auto it:cpp)
	   // {
	   //    cout<<it.first<<" "<<it.second<<endl;
	   // }
	    if(cpp.size()==1) return 1;
	    else if(cpp.size()>2) return 0;
	    else if(cpp.size()==2)
	    {
	       // cout<<"hi" ;
	       int f=0,s=0;
	        for(auto it:cpp)
	        {
	            if(f==0)
	            {
	                f=it.first;
	            }
	            else s=it.first;
	        }
	       // cout<<f<<" "<<s<<endl;
	        if(min(f,s)==1 and cpp[min(f,s)]==1) {
	            return cpp[min(f,s)]==1?1:0;
	        }
	        else if(cpp[max(f,s)]>=2) return 0;
	        else if(cpp[max(f,s)]==1)
	        {
	            if(abs(f-s)==1) return 1;
	            return 0;
	        }
	        else if(cpp[max(f,s)]==1 ) return 0;
	        
	        return 1;
	    }
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends