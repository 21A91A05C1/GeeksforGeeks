//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Main {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            Solution obj = new Solution();
            int ans[] = obj.Series(n);
            for (int i : ans) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


class Solution {
    int mod=1000000007;
    int[] Series(int n) {
        // code here
        int [] arr =new int[n+1];
        int i=0;
        arr[i]=0;
        i++;
        arr[i++]=1;
        while(i<=n)
        {
            arr[i]=((arr[i-1])%mod+(arr[i-2])%mod)%mod;
            i++;
        }
        // System.out.println(mod);
        return arr;
    }
}