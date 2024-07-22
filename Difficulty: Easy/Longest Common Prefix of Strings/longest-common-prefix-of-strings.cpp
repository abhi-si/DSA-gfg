//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    string compare(const string &a, const string &b) {
        int i = 0, j = 0;
        string ret = "";
        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j]) {
                ret += a[i];
                i++;
                j++;
            } else {
                return ret;
            }
        }
        return ret;
    }

    string longestCommonPrefix(vector<string> &arr) {
        int n = arr.size();
        if (n == 0) return "-1";
        string ans = arr[0];
        for (int i = 1; i < n; i++) {
            string x = compare(ans, arr[i]);
            if (x.empty()) return"-1";
            ans = x;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends