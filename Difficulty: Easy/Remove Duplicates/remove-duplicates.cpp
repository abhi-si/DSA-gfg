//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string s) {
       unordered_map<char,int> count;
        string result = "";
       for (char c : s) {
            count[c]++;
        }
        for (char c : s) {
            if (count[c] > 0) {
                result += c;
                count[c] = 0; 
// Set the count to 0 to indicate this character has been added to result
            }
        }
         return result;
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends