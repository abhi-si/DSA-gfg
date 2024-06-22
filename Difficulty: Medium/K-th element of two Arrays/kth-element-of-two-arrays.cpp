//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
      int i = 0, j = 0;
        int count = 0;
        int kthElement = -1;

        // Iterate through both arrays to find the k-th smallest element
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                // Current element from arr1 is smaller or equal
                count++;
                if (count == k) {
                    kthElement = arr1[i];
                    break;
                }
                i++;
            } else {
                // Current element from arr2 is smaller
                count++;
                if (count == k) {
                    kthElement = arr2[j];
                    break;
                }
                j++;
            }
        }

        // If k-th element is not found yet and there are remaining elements
        while (i < n && count < k) {
            count++;
            if (count == k) {
                kthElement = arr1[i];
                break;
            }
            i++;
        }

        while (j < m && count < k) {
            count++;
            if (count == k) {
                kthElement = arr2[j];
                break;
            }
            j++;
        }

        return kthElement;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends