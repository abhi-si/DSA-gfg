//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long merge(long long arr[], int low, int mid, int high) {
        vector<long long> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
        long long cnt = 0; 
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); // Increment inversion count
                right++;
            }
        }
        // If elements on the left half are still remaining
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // If elements on the right half are still remaining
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Transfer elements from temp array to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt; // Return the inversion count for this merge step
    }

    long long mergeSort(long long arr[], int low, int high) {
        long long cnt = 0; 
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);  // Sort the left half
        cnt += mergeSort(arr, mid + 1, high); // Sort the right half
        cnt += merge(arr, low, mid, high);  // Merge the two halves and count inversions
        return cnt; 
    }

    long long int inversionCount(long long arr[], int n) {
       
        return mergeSort(arr, 0, n - 1); // Perform merge sort and return the count of inversions
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends