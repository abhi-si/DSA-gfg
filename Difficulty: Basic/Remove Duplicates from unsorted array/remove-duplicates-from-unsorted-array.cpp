//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<int> removeDuplicate(int arr[], int n) {
        
        unordered_set<int> s;
        vector<int>result;
        for (int i = 0; i < n; i++) {
            if (s.find(arr[i]) == s.end()) {
                s.insert(arr[i]);
                result.push_back(arr[i]);
           
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

// Driver method to test above method
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
        vector<int> v = ob.removeDuplicate(a, n);

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends