//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {   
public:
    int countSmallEqual(vector<vector<int>> &matrix, int R, int C, int x) {
        int cnt = 0;
        for (int i = 0; i < R; ++i) {
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
        }
        return cnt;
    }

    int median(vector<vector<int>> &matrix, int R, int C) {
        int l =INT_MIN;
        int h = INT_MAX;
        for (int i = 0; i < R; ++i) {
            l = min(l, matrix[i][0]);
            h = max(h, matrix[i][C - 1]);
        }
        int ans = (R * C) / 2;
        while (l <= h) {
            int mid = (l + h) / 2;
            int smallEqual = countSmallEqual(matrix, R, C, mid);
            if (smallEqual <= ans) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends