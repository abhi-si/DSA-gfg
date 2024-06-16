//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    vector<int> common_element(vector<int> v1, vector<int> v2)
    {
        unordered_map<int, int> freq;
        int n = v1.size();
        int m = v2.size();
        
        // Count the frequency of elements in v1
        for (int i = 0; i < n; i++) {
            freq[v1[i]]++;
        }
        
        vector<int> result;
        
        // Iterate over elements in v2 to find common elements
        for (int i = 0; i < m; i++) {
            // If the element exists in freq and its frequency is greater than 0
            if (freq.find(v2[i]) != freq.end() && freq[v2[i]] > 0) {
                result.push_back(v2[i]); // Add it to the result vector
                freq[v2[i]]--; // Decrease the frequency count
            }
        }
        
       
        sort(result.begin(), result.end());
        
        return result;
    }   
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}
// } Driver Code Ends