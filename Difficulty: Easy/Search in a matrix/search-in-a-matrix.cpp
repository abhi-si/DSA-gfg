//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:    
    int matSearch(vector<vector<int>>& mat, int N, int M, int X) {
        int r = 0, c = M - 1; // Initialize the starting point at top-right corner of matrix
        while (r < N && c >= 0) { // Iterate until we reach the bottom-left corner of matrix
            if (mat[r][c] == X) return 1; // If the element is found, return 1
            if (mat[r][c] > X) c--; // If the current element is greater than the target element, move left
            else r++; // If the current element is less than the target element, move down
        }
        return 0; // If the element is not found, return 0
    }
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends