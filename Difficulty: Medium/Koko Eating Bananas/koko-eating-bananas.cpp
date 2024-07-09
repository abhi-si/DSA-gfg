//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findMax(int N, vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < N; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    int calculateHrs(int N,vector<int>& piles, int mid) {
        int totalHrs = 0;
        for (int i = 0; i < N; i++) {
            totalHrs += std::ceil((double)piles[i] / mid);
        }
        return totalHrs;
    }

    int Solve(int N, vector<int>& piles, int H) {
        int l = 1; 
        int h = findMax(N, piles);
        int ans = 0; 

        while (l <= h) {
            int mid = (l + h) / 2;
            int totalHrs = calculateHrs(N, piles, mid);

            if (totalHrs <= H) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
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
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends