//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int l=0;
        int h=n-1;
        int ans =INT_MAX;
        while(l <= h){
            int mid = (l+h)/2;
            if(arr[l] <= arr[mid]){
                ans = min(ans,arr[l]);
                l = mid+1;
            }
            else{
                h=mid-1;
                ans = min(ans,arr[mid]);
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.findMin(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends