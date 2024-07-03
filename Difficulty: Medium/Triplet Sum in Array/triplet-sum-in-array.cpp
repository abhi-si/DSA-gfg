//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {

        sort(arr, arr + n);
        
        // Traverse the array
        for (int i = 0; i < n - 2; i++) {
            // Avoid duplicates
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            
            // Initialize two pointers
            int j = i + 1;
            int k = n - 1;
            
            // Find the triplet
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                
                // If sum is less than x, move the left pointer to the right
                if (sum < x) {
                    j++;
                }
                // If sum is greater than x, move the right pointer to the left
                else if (sum > x) {
                    k--;
                }
                // If sum equals x, we found a triplet
                else {
                    return true;
                }
            }
        }
        
        // If no triplet is found
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends