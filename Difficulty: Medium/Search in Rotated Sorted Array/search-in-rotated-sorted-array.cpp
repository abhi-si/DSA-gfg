//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int search(vector<int>& arr, int key) {
        int l = 0;
        int h = arr.size() - 1;

        while (l <= h) {
            int mid = (l + h) / 2;
            if (arr[mid] == key) {
                return mid;
            }
            // Checking left sorted
            if (arr[l] <= arr[mid]) {
                if (arr[l] <= key && key <= arr[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (arr[mid] <= key && key <= arr[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends