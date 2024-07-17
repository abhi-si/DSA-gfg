//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
struct meeting {
    int start;
    int end;
    int pos;
};
class Solution {
public:
    static bool comp(struct meeting m1, struct meeting m2) {
        return m1.end < m2.end;
    }
    
    int maxMeetings(int start[], int end[], int n) {
        struct meeting meet[n];
        for (int i = 0; i < n; i++) {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }

        sort(meet, meet + n, comp);
        
        int cnt = 1;
        int freeTime = meet[0].end;
        for (int i = 1; i < n; i++) {
            if (meet[i].start > freeTime) {
                cnt++;
                freeTime = meet[i].end;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends