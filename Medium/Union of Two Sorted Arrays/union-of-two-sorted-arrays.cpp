//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
     
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        
        //Most optimal approach
        vector<int>vt;
        
        int i = 0;
        int j = 0;
        while(i < n && j < m ){
            if(arr1[i]<arr2[j]){
                if(vt.size()==0 ||  vt.back()!=arr1[i]){
                    vt.push_back(arr1[i]);
                }
                i++;
            }
            else{
                
                if(vt.size()==0 ||  vt.back()!=arr2[j]){
                    vt.push_back(arr2[j]);
                }
                j++;
            }
        }
        while(i<n){
            if(vt.size()==0 ||  vt.back()!=arr1[i]){
                    vt.push_back(arr1[i]);
                }
                i++;
        }
        while(j<m){
            if(vt.size()==0 ||  vt.back()!=arr2[j]){
                    vt.push_back(arr2[j]);
                }
                j++;
        }
        return vt;//sc:o(n+m)
    }
    
};


//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends