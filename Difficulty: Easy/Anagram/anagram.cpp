//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        if (a.length() != b.length()) {
            return false;
        }

        unordered_map<char, int> countA;
        unordered_map<char, int> countB;

        for (char c : a) {
            countA[c]++;
        }

       
        for (char c : b) {
            countB[c]++;
        }

       //It checks if both unordered_map objects have the same set of keys.
        return countA == countB;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends