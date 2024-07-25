//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

//Back-end complete function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //creating a 2D table to store results of subproblems.
        int ans[a][b];
        
        //count of paths to reach any cell in first row is 1.
        for(int i=0;i<b;i++)
            ans[0][i]=1;
        
        //count of paths to reach any cell in first column is 1.
        for(int i=0;i<a;i++)
            ans[i][0]=1;
        
   
        for(int i=1;i<a;i++)
        {
            for(int j=1;j<b;j++)
                //calculating number of path from previous column+previous row.
                ans[i][j]=ans[i-1][j]+ans[i][j-1];
        }
        
        
         return ans[a-1][b-1];
    }

};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends