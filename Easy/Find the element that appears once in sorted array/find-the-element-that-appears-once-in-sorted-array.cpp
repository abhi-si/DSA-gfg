//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int a[], int n)
    {
        if(n==1) return a[0];
        if(a[0] != a[1]) return a[0];
        if(a[n-1] != a[n-2]) return a[n-1];
        int low = 1;
        int high =n-2;
        while(low <= high){
            int mid = (low+high)/2;
            if(a[mid] != a[mid-1] && a[mid]!=a[mid+1]){
                return a[mid];
            }
            if(mid%2==0 && a[mid]==a[mid+1] || mid%2==1 && a[mid]==a[mid-1]){
                low =mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends