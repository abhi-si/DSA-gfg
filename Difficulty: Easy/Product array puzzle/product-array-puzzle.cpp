//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       std::vector<long long int> result(n, 1);
        
        // Step 1: Compute the left products for each element
        long long int left_product = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = left_product;
            left_product *= nums[i];
        }
        
        // Step 2: Compute the right products and multiply with the left products
        long long int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= right_product;
            right_product *= nums[i];
        }
        
        return result;
             
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends