# include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
public:
    // Constructor with given node
    node(int n, node* ptr) {
        data = n;
        next = ptr;
    }

    // Constructor with given value
    node(int num) {
        data = num;
        next = nullptr;
    }
};

class linklist {
public:
    node* convArrtoLL(vector<int> &w) {
        node* head = new node(w[0]);
        node * itr = head;
        for(int i = 1; i < w.size() ; i++) {
            itr -> next = new node(w[i]); // Highlight of the code
            itr = itr -> next;
        }
        return head;
    }

    node* pushBack(node* q, int x) {
        node* temp = q;
        while(temp -> next != nullptr) {
            temp = temp -> next;
        }
        temp -> next = new node(x);
        return q;
    }

    void deleteNode(node* one) {
        one->data=one->next->data;
        one->next=one->next->next;
    }

    int linkedSize(node* head) {
        int l = 0;
        node* temp = head;
        while(temp != nullptr) 
        {
            l++;
            temp = temp -> next;
        }
        return l;
    }

    bool findVal(node* head, int x) {
        node* temp = head;
        while(temp != nullptr) {
            if(temp -> data == x) {
                return true;
            }
            temp = temp -> next;
        }
        return false;
    }
}; 

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
    }
    linklist ll;
    node* head = ll.convArrtoLL(a);
    
    head = ll.pushBack(head, k);

    // node* temp = head;
    // while(temp != nullptr) {
    //     cout << temp -> data << ' ';
    //     temp = temp -> next;
    // }

    cout << ll.linkedSize(head) << '\n';
    cout << ll.findVal(head, k);
    return 0;
}
