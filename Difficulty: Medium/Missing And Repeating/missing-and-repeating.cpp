//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        long long N = n;  // Correct variable name
        long long SN = (N * (N + 1)) / 2;
        long long S2N = (N * (N + 1) * (2 * N + 1)) / 6;
        
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += arr[i];
            S2 += (long long)arr[i] * arr[i];
        }

        long long val1 = S - SN;   // x - y
        long long val2 = S2 - S2N; // x^2 - y^2
        
        // val2 = (x + y)(x - y)
        // val1 = x - y
        // val2 / val1 = x + y
        val2 = val2 / val1;
        
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
//static_cast is used to convert the long long results back to 
//int before returning them in the vector.
        return {static_cast<int>(x), static_cast<int>(y)};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends