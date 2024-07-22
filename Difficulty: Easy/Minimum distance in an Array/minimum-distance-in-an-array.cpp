//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int minDist(int a[], int n, int x, int y) {
        int i = -1; // index of the previous occurrence of x or y
        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (a[j] == x || a[j] == y) {
                if (i != -1 && a[i] != a[j]) {
                    ans = min(ans, j - i);
                }
                i = j; // update the previous index
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends