//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> sumClosest(vector<int> arr, int x) {
        int n = arr.size();
        int left = 0, right = 0;
        int i = 0, j = n - 1;
        int closest_sum = INT_MAX;

        while (j > i) {
            int current_sum = arr[i] + arr[j];
            int current_diff = abs(x - current_sum);

            if (current_diff < abs(x - closest_sum)) {
                closest_sum = current_sum;
                left = arr[i];
                right = arr[j];
            }

            if (current_sum < x) {
                i++;
            } else {
                j--;
            }
        }

        return {left, right};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends