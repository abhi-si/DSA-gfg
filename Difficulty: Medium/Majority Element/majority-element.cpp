//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        map<int,int>mpp;
        for(int i=0;i<size;i++){
            mpp[a[i]]++;
        }
        for(auto it:mpp){
            if(it.second>size/2){
                return it.first;
            } 
            
        }
        return -1;
        // better solution
        
        //optimal solution
        //MOORE'S VOTING ALGORITHM
        // int cnt=0;
        // int el;
        // for(int i=0; i<size; i++){
        //     if(cnt==0){
        //         cnt=1;
        //         el=a[i];
        //     }
        //     else if(el==a[i]){
        //         cnt++;
        //     }
        //     else cnt--;
        // }
        // int cnt1=0;
        // for(int i=0; i<size; i++){
        //     if(a[i]==el){
        //         cnt1++;
        //     }
        //     if(cnt1>size/2){
        //         return el;
        //     }
        // }
        // return -1;
        
        
        
        
        
    }
};


//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends