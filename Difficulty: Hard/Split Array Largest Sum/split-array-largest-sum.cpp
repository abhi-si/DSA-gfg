//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPartitions(vector<int> &arr, int maxSum) {
    int n = arr.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + arr[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += arr[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = arr[i];
        }
    }
    return partitions;
}
    int splitArray(int arr[] ,int N, int K) {
        int low = *max_element(arr, arr + N);
        int high = accumulate(arr, arr + N, 0);
        int ans = -1;
        vector<int> arrVec(arr, arr + N);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartitions( arrVec, mid);
        if (partitions > K) {
            low = mid + 1;
        }
        else {
            ans = mid;
            high = mid - 1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends