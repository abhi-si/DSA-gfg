//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sumByD(vector<int>& nums,int el){
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += ceil((double)(nums[i])/(double)(el));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int K) {

       int l = 1, h = *max_element(nums.begin(),nums.end());
       int ans =-1;
       while(l<=h){
           int mid = (l+h)/2;
           if(sumByD(nums,mid) <= K){
               ans = mid;
               h = mid-1;
           }
           else{
               l = mid+1;
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends