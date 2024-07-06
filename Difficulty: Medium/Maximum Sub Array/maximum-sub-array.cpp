//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

//Back-end complete function template for C++
class Solution {
  public:
    vector<int> findSubarray(int n, int a[]) {
        long long max_sum = -1;
        long long cur_sum = 0;
        int max_range_left = -1;
        int max_range_right = -1;
        int cur_range_left = 0;
        int cur_range_right = 0;

        // iterating over the array
        while (cur_range_right < n) {
            // if current element is negative, start new range
            if (a[cur_range_right] < 0) {
                cur_range_left = cur_range_right + 1;
                cur_sum = 0;
            } else {
                // adding current element to current sum
                cur_sum += (long long)a[cur_range_right];

                // updating maximum sum and range if current sum is greater
                if (cur_sum > max_sum) {
                    max_sum = cur_sum;
                    max_range_left = cur_range_left;
                    max_range_right = cur_range_right;
                }
                // if current sum is equal to maximum sum, update range only if current
                // range is larger
                else if (cur_sum == max_sum) {
                    if (cur_range_right + 1 - cur_range_left >
                        max_range_right + 1 - max_range_left) {
                        max_range_left = cur_range_left;
                        max_range_right = cur_range_right;
                    }
                }
            }
            cur_range_right++;
        }
        vector<int> ans;

        // if no positive subarray found, return -1
        if (max_range_left == -1 || max_range_right == -1) {
            ans.push_back(-1);
            return ans;
        }

        // add elements from maximum subarray to answer vector
        for (int i = max_range_left; i <= max_range_right; ++i)
            ans.push_back(a[i]);

        return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(n, a);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends