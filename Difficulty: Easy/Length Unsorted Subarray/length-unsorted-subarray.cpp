//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:	
    vector<int> printUnsorted(int arr[], int n) {
        if (n <= 1) {
            return {0, 0};
        }
        int k = -1, j = -1;
        
        // Identify the first position from the left where the order is violated
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                k = i;
                break;
            }
        }
        
        // If no such position is found, the array is already sorted
        if (k == -1) {
            return {};
        }
        
        // Identify the first position from the right where the order is violated
        for (int i = n - 1; i > 0; --i) {
            if (arr[i] < arr[i - 1]) {
                j = i;
                break;
            }
        }
        
        // Find the minimum and maximum values in the subarray arr[k...j]
        int minVal = arr[k], maxVal = arr[k];
        for (int i = k; i <= j; ++i) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        
        // Extend the left boundary if needed
        for (int i = 0; i < k; ++i) {
            if (arr[i] > minVal) {
                k = i;
                break;
            }
        }
        
        // Extend the right boundary if needed
        for (int i = n - 1; i > j; --i) {
            if (arr[i] < maxVal) {
                j = i;
                break;
            }
        }
        
        return {k, j};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends