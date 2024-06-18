//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
       if (nums.size() % 2 != 0) {
            return false;
        }
        
        // Create a frequency map to count remainders
        std::unordered_map<int, int> remainderCount;
        for (int i = 0; i < nums.size(); ++i) {
            int remainder = nums[i] % k;
            remainderCount[remainder]++;
        }
        
        // Check pairing conditions
        for (const auto& pair : remainderCount) {
            int remainder = pair.first;
            int count = pair.second;
            
            // If the remainder is 0, we need an even count to form pairs
            if (remainder == 0) {
                if (count % 2 != 0) {
                    return false;
                }
            } else {
                // The count of remainder `i` should match the count of remainder `k - i`
                int complement = k - remainder;
                if (remainderCount[remainder] != remainderCount[complement]) {
                    return false;
                }
            }
        }
        
        // If all checks pass, we can form the pairs
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends