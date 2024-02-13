//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        int i=0,j=k;
        for(int y=0;y<k;y++)
        {
            pq.push({arr[y],y});
        }
        ans.push_back(pq.top().first);
        while(j<n)
        {
            pq.push({arr[j],j});
            
            while(pq.top().second<=i){
                pq.pop();
            }
            if(!pq.empty()) ans.push_back(pq.top().first);
            j++;
            i++;
 
        }
        //if(!pq.empty()) ans.push_back(pq.top().first);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends