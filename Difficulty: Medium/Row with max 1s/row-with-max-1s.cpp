//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    int rowWithMax1s(vector<std::vector<int>> arr, int n, int m) {
        int cnt_max = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            // finds the first position where 1 could be inserted to keep the array sorted. 
            //If 1 is present, it returns the iterator to the first 1.
            auto it = lower_bound(arr[i].begin(), arr[i].end(), 1);
            int cnt_ones = arr[i].end() - it; // Calculate the number of 1s
            
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends