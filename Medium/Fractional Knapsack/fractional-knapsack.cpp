//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double res=0;
        vector<pair<double,int>>vp;
        for(int i=0;i<n;i++)
        {
            double ans=(double)arr[i].value/(double)arr[i].weight;
            vp.push_back({ans,i});
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        for(auto it:vp)
        {
            int s=it.second;
            if(arr[s].weight<=W)
            {
                res+=arr[s].value;
                W-=arr[s].weight;
            }
            else
            {
                double val=arr[s].value;
                double wei=arr[s].weight;
                double u=(val/wei)*W;
                res+=u;
                W=0;
                break;
            }
            
        }
        
        return res;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends