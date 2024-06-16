//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void generateSieve(vector<bool>&primes,int n)
    {
        primes[0]=0;
        primes[1]=0;
        for(int i=2;i*i<=n+1;i++)
        {
            for(int j=i*i;j<n+1;j+=i)
            {
                primes[j]=false;
            }
        }
    }
    vector<int> getPrimes(int n) {
        vector<int>arr;
        vector<bool>primes(n+1,true);
        generateSieve(primes,n);
        for(int i  = 0 ;i <=n ;i++)
        {
            if(primes[i]==1)
            {
                int p=n-i;
                if(primes[p]){
                    return {i,p};
                }
            }
        }
        return {-1,-1};
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends