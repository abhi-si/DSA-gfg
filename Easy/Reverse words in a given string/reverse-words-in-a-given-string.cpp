//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        vector<string> a;
        int n = S.size();
        string s = "";
        for(int i=0;i<n;i++){
            if(S[i] == '.'){
                a.push_back(s);
                s = "";
            }
            else{
                s += S[i];
            }
        }
        a.push_back(s);
        
        n = a.size();
        s = "";
        for(int i=n-1; i>=0;i--){
            s += a[i];
            if(i != 0){
                s+='.';
            }
        }
        return s;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends