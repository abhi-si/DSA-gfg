//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        unordered_map<int ,int> freq;
        vector<pair<int,int> > result;
        
        // Count the frequency of elements in array B
        for(int i = 0; i < M; i++) {
            freq[B[i]]++;
        }
        
        // Iterate over array A to find pairs
        for(int i = 0; i < N; i++) {
            int reqd = X - A[i];
            for(int j = 0; j < freq[reqd]; j++) {
                result.push_back({A[i], reqd});
                    
            }
        }
        sort(result.begin(),result.end());
        return result;
    }   
};

// vector<pair<int,int>> result;
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<M;j++){
        //         if(A[i]+B[j]==X){
        //             result.push_back(make_pair(A[i], B[j]));
        //         }
        //     }
        // }
        // return result;
        //brute force approach


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends