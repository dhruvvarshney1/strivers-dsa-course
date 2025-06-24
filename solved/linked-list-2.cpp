# include <bits/stdc++.h>
using namespace std;

class node {
public:
    int dat;
    node* next;
    node* back;

    // Constructor1
    node(int dat1, node* next1, node* back1) {
        dat = dat1;
        next = next1;
        back = back1;
    }

    // Constructor2
    node(int dat2) {
        dat = dat2;
        next = nullptr;
        back = nullptr;
    }

    // Constructor3
    node(int dat3, node* next3) {
        dat = dat3;
        next = next3;
        back = nullptr;
    }
};

class dll {
public:
    node* constDll(vector<int> &a) {

        node* head = new node(a[0]);

        node* it = head;

        for(int i = 1; i < a.size() ; i++) {

            node* tem = new node(a[i], nullptr, it);

            it->next = tem;

            it = tem;
        }

        return head;
    }

    node* printDll(node * head) {

        node* tem = head;

        while(tem != NULL) {
            cout << tem->dat << ' ';
            tem = tem -> next;
        }

        // cout << '\n';
    }

    node* insertNode(node* head, int p, int x) {

        if(p == 0) {
            node* tem = new node(x, head, nullptr);
            return tem;
        }

        node* it = head;

        for(int i = 0; i < p - 1 ; i++) {
            it = it -> next;
        }
        node* tem = new node(x, it-> next, it);
        it->next = tem;

        return head;
    }

    node* delNode(node* head, int p) {

        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        if(p == 0) {
            head = head -> next;
            return head;
        }

        node* it = head;

        for(int i = 0; i < p - 1 ; i++) {
            it = it -> next;
        }

        if(!it->next->next) {
            it->next = nullptr;
            return head;
        }

        it->next = it->next->next;
        (it->next->next)->back = it;

        return head;
    }

    node* reverseDll(node* head) {

        // Method 1: Time : O(2n), Space : O(n)

        // stack<int> rev;
        // node* it = head;
        // while(it != nullptr) {
        //     rev.push(it->dat);
        //     it = it->next;
        // }
        // it = head;
        // while(it != nullptr) {
        //     it->dat = rev.top();
        //     it = it->next;
        //     rev.pop();
        // }
        // return head;

        // Method 2: Time : 

        node* it = head, *temp = nullptr, *newhead = nullptr;
        while(it != nullptr) {

            temp = it->back;

            it->back = it->next;

            it->next = temp;

            newhead = it;

            it = it->back;
        }
        return newhead;
    }

};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
    }
    dll d;
    node* head = d.constDll(a);
    
    // int p, x;
    // cin >> p >> x;
    // head = d.insertNode(head, p, x);

    head = d.reverseDll(head);
    d.printDll(head);
    return 0;
}

