//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
public:
    // Function to check whether the list is palindrome.
    struct Node* reverseList(struct Node *head)
    {
        if(head == nullptr || head->next == nullptr) return head;
        Node* newHead = reverseList(head->next); // Corrected the function call
        Node* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }

    bool isPalindrome(Node *head)
    {
        if(head == nullptr || head->next == nullptr) return true;
        
        Node* slow = head;
        Node* fast = head;
        
        // Find the middle of the list
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;  // Fixed the typo
            fast = fast->next->next;
        }
        
        // Reverse the second half of the list
        Node* newHead = reverseList(slow->next);
        Node* first = head;
        Node* second = newHead;
        
        // Compare the first and second halves
        while(second != nullptr){
            if(first->data != second->data){
                reverseList(newHead);  // Restore the original list
                return false;
            }
            first = first->next;
            second = second->next;
        }
        
        // Restore the original list
        reverseList(newHead);
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends