//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool Search(int N, vector<int>& A, int key) {
        
        int l = 0;
        int h = N - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (A[mid] == key) {
                return true; // Return true when key is found
            }
            if (A[mid] == A[l] && A[mid] == A[h]) {
                l++, h--;
                continue;
            }
            if (A[l] <= A[mid]) {
                if (A[l] <= key && key <= A[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (A[mid] <= key && key <= A[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return false; // Return false if key is not found
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends