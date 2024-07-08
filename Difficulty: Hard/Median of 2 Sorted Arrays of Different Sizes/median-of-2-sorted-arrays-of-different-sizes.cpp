//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++



class Solution {
public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2) {
        int m = array1.size();
        int n = array2.size();
        
        // Merge arrays into a single sorted array
        vector<int> merged(m + n);
        int i = 0, j = 0, k = 0;
        
        while (i < m && j < n) {
            if (array1[i] < array2[j]) {
                merged[k] = array1[i];
                i++;
            } else {
                merged[k] = array2[j];
                j++;
            }
            k++;
        }
        
        // Copy remaining elements from array1, if any
        while (i < m) {
            merged[k] = array1[i];
            i++;
            k++;
        }
        
        // Copy remaining elements from array2, if any
        while (j < n) {
            merged[k] = array2[j];
            j++;
            k++;
        }
        
        // Calculate median
        if ((m + n) % 2 != 0) {
            // Odd number of elements
            return merged[(m + n) / 2];
        } else {
            // Even number of elements
            int x = (m + n) / 2;
            double p = merged[x];
            double q = merged[x - 1];
            return (p + q) / 2.0;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends