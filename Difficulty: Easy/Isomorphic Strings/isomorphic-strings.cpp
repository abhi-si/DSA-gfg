//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        unordered_map<char,char>m1;
        unordered_map<char,char>m2;
        int n1 = str1.size();
        int n2 = str2.size();
        if(n1 != n2) return 0;
        for(int i=0;i<n1;i++){
            if(m1[str1[i]]==0 && m2[str2[i]]==0){
                m1[str1[i]] = str2[i];
                m2[str2[i]] = str1[i];
            }
            if(m1[str1[i]] != str2[i] && m2[str2[i]] != str1[i]){
                return 0;
            }
        }
        return 1;

        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends