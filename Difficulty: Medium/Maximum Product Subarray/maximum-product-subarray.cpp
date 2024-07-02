//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long prefix =1;
	    long sufix =1;
	    long ans = INT_MIN;
	    for(int i=0;i<n;i++){
	        if(prefix==0) prefix =1;
	        else if(sufix==0) sufix =1;
	        prefix = prefix * arr[i];
	        sufix = sufix* arr[n-i-1];
	        ans = max(ans,max(prefix,sufix));
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends