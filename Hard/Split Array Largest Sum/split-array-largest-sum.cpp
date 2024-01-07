//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int splitLargestSum(int n,int arr[],int size)
    {
        int c=1,s=0;
        for(int i=0;i<size;i++)
        {
            if(s+arr[i]<=n)
            {
                s+=arr[i];
            }
            else
            {
                s=arr[i];
                c++;
            }
        }
        return c;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int low=*max_element(arr,arr+N);
        int high=accumulate(arr,arr+N,0);
        // for(int i=low;i<=high;i++)
        // {
        //     if(splitLargestSum(i,arr,N)==K) return i;
        // }
        // return low;
        
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            // cout<<mid<<" ";
            if(splitLargestSum(mid,arr,N)<=K)
            {
                high=mid-1;
                // cout<<"hight"<<endl;
            }
            else if(splitLargestSum(mid,arr,N)>K)
            {
                low=mid+1;
                // cout<<"low "<<endl;
            }
        }
        return low;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends