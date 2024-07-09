//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:
    int countPainters(vector<int> &arr, long long time) {
        int n = arr.size();
        int painters = 1;
        long long boardsPainter = 0;
        for (int i = 0; i < n; i++) {
            if (boardsPainter + arr[i] <= time) {
                boardsPainter += arr[i];
            } else {
                painters++;
                boardsPainter = arr[i];
            }
        }
        return painters;
    }

    long long minTime(int arr[], int n, int k) {
        int low = *max_element(arr, arr + n);
        long long high = accumulate(arr, arr + n, 0LL);  // Accumulate with long long
        vector<int> arrVec(arr, arr + n);
        long long ans = -1;

        // Apply binary search:
        while (low <= high) {
            long long mid = (low + high) / 2;
            int painters = countPainters(arrVec, mid);
            if (painters > k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends