//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    void rearrange(int arr[], int n) {
        vector<int> pos, neg;
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }

        int posInd = 0, negInd = 0, i = 0;
        
        // Alternate positions starting with a positive number
        while(posInd < pos.size() && negInd < neg.size()) {
            if(i % 2 == 0) {
                arr[i++] = pos[posInd++];
            } else {
                arr[i++] = neg[negInd++];
            }
        }
        
        // If there are remaining positive numbers
        while(posInd < pos.size()) {
            arr[i++] = pos[posInd++];
        }
        
        // If there are remaining negative numbers
        while(negInd < neg.size()) {
            arr[i++] = neg[negInd++];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends