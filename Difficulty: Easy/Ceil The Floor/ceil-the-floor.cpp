//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

    int findFloor(int arr[], int n, int x) {
        int l = 0;
        int h = n - 1;
        int ans = -1;
        while (l <= h) {
            int mid = (l + h) / 2; 
            if (arr[mid] <= x) {
                ans = arr[mid];
                l = mid + 1;  
            } else {
                h = mid - 1; 
            }
        }
        return ans;  
    }

    int findCeil(int arr[], int n, int x) {
        int l = 0;
        int h = n - 1;
        int ans = -1;
        while (l <= h) {
            int mid = (h +l ) / 2;  
            if (arr[mid] >= x) {
                ans = arr[mid];
                h = mid - 1;  
            } else {
                l = mid + 1;  
            }
        }
        return ans;  
    }
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
 

    sort(arr, arr + n);
    int floor = findFloor(arr, n, x);
    int ceil = findCeil(arr, n, x);

    return {floor, ceil};
}
