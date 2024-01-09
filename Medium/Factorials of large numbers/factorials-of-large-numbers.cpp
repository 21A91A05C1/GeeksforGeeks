//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n){
        // code here
        vector<int>arr;
        arr.push_back(1);
        int y=0,size=1;
        //cout<<arr[0]<<" ";
        int ans=0;
        int c=0;
        for(int i=1;i<=n;i++)
        {
            int c=0;
            for(int j=0;j<size;j++)
            {
                ans=(i*arr[j])+c;
                int k=ans%10;
                arr[j]=k;
                c=ans/10;
                //cout<<k<<" "<<c<<" ";
            }
            while(c)
            {
                int p=c%10;
                arr.push_back(p);
                c/=10;
                size++;
            }
            //cout<<endl;
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends