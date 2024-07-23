//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int calculate(char a){
        if(a=='I') return 1;
        else if(a=='V') return 5;
        else if(a=='X') return 10;
        else if(a=='L') return 50;
        else if(a=='C') return 100;
        else if(a=='D') return 500;
        else if(a=='M') return 1000;
    }
    int romanToDecimal(string &str) {
        int n  = str.size(), i,v1,v2;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i<n-1){
                v1=calculate(str[i]);
                v2=calculate(str[i+1]);
                if(v1<v2) ans = ans-v1;
                else ans=ans+v1;
            }
            else{
                ans = ans+calculate(str[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends