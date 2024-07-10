//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
// 0 sum subarray exist in 2 condition either prefix sum =0 or prefix sum repeats
        unordered_map<int,bool>mpp;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum == 0 || mpp[sum] == true){
            return true;
        }
        mpp[sum] = true;
        }
        return false;
        
        
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends