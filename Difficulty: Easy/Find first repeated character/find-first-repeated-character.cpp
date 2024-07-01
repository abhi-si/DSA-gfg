//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
     unordered_map<char, int> charCount;

        for (char c : s) {
            if (charCount[c] == 1) {
// The string class in C++ provides a constructor that takes two parameters: 
// the number of times to repeat a character and the character itself.
                return string(1, c);
            }
            charCount[c]++;
        }

        return "-1";
    
}