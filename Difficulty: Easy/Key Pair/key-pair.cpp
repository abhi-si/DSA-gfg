//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function to check if array has 2 elements
    // whose sum is equal to the given value
    bool hasArrayTwoCandidates(vector<int>& arr, int x) {
        map<int,int>mpp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int num = arr[i];
            int reqd = x - num ;
            if(mpp.find(reqd) != mpp.end()){
                return true;
            }
            mpp[num] = i;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    if (t == 1) {
        cout << "-1" << endl;
        // cout<<"~"<<endl;
    }
    while (t--) {
        int x;
        cin >> x;
        cin.ignore(); // To discard any leftover newline characters

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, x);
        cout << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}

// } Driver Code Ends