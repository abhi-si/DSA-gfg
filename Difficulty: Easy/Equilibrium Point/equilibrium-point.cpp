//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int equilibriumPoint(const std::vector<long long>& a) {
        long long totalsum = 0;
        long long sum = 0;
        int n = a.size();
        
        // Calculate the total sum of all elements in the array.
        for (int i = 0; i < n; i++) {
            totalsum += a[i];  // Use += to accumulate the sum correctly.
        }
        
        // Traverse through the array to find the equilibrium point.
        for (int i = 0; i < n; i++) {
            if (sum == (totalsum - sum - a[i])) {
                return i + 1;  // Return 1-based index of equilibrium point.
            }
            sum += a[i];  // Incrementally add current element to the left sum.
        }
        
        return -1;  // If no equilibrium point is found, return -1.
    }
};
    
  


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends