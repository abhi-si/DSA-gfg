//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    // Function to reverse a linked list.
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* dummyHead = new Node(-1);  // Initialize dummyHead here
        Node* curr = dummyHead;
        Node* temp1 = reverse(num1);
        Node* temp2 = reverse(num2);
        int carry = 0;

        while (temp1 != nullptr || temp2 != nullptr || carry != 0) {
            int sum = carry;
            if (temp1) {
                sum += temp1->data;
                temp1 = temp1->next;  // Move to the next node
            }
            if (temp2) {
                sum += temp2->data;
                temp2 = temp2->next;  // Move to the next node
            }
            Node* newNode = new Node(sum % 10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;
        }

        Node* result = reverse(dummyHead->next);
        delete dummyHead;

        // Remove leading zeros
        while (result != nullptr && result->data == 0) {
            Node* temp = result;
            result = result->next;
            delete temp;
        }

        return result == nullptr ? new Node(0) : result;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends