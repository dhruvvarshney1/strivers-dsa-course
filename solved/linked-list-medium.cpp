# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
typedef ListNode node;

class optimal {
public:
    node* constll(std::vector<int> &a) {
        node* head = new node(a[0]);
        node* it = head;
        for(int i = 1; i < a.size(); i++) {
            it->next = new node(a[i]);
            it = it->next;
        }
        return head;
    }
    node* middleNode(node* head) {

        // Method 1:

        ll len = 0;
        node* it = head;
        while(it != nullptr) {
            len++;
            it = it->next;
        }
        ll flag = (len / 2) + 1;
        it = head;
        while(--flag) {
            it = it->next;
        }
        return it;

        // Method 2:

        // node* fas = head, *slo = head;
        // while(fas != nullptr && fas->next != nullptr) {
        //     fas = fas->next->next;
        //     slo = slo->next;
        // }
        // return slo;
    }
    node* reverseLL(node* head) {

        // Method 1: Iterative

        // node* it = head, *prev = nullptr;
        // while(it != nullptr) {

        //     node* front = it->next;
        //     it->next = prev;
        //     prev = it;
        //     it = front;

        // }

        // return prev;

        // Method 2: Recursive

        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        node* newhead = reverseLL(head->next);

        node* temp = head->next;

        temp->next = head;

        head->next = nullptr;

        return newhead;
    }
    bool hasCycle(node* head) {

        node* fas = head, *slo = head;

        while(fas->next != nullptr && fas != nullptr) {
            fas = fas->next->next;
            slo = slo->next;

            if(fas == slo) {
                return true;
            }
        }
        return false;
    }
    node* detectCycle(node* head) {
        node* slo = head, *fas = head;

        while(fas != nullptr && fas->next != nullptr) {
            fas = fas->next->next;
            slo = slo->next;

            if(fas == slo) {
                slo = head;

                while(slo != fas) {
                    slo = slo->next;
                    fas = fas->next;
                } 
                return slo;
            }
        }
        return nullptr;
    }
    int loopNodes(node* head) {
        node* slo = head, *fas = head;
        int c = 1;
        while(slo != nullptr && slo->next != nullptr) {

            fas = fas->next;
            slo = slo->next->next;

            if(fas == slo) {
                node* flag = slo->next;
                while(slo != flag) {
                    flag = flag->next;
                    c++;
                }
                return c;
            }
        }
        return 0;
    }
    bool isPalindrome(node* head) {
        node* fas = head, *slo = head;

        while(fas != nullptr && fas->next != nullptr) {
            fas = fas->next->next;
            slo = slo->next;
        }
        node* it = slo,*prev = nullptr;
        while(it != nullptr) {
            node* fr = it->next;
            it->next = prev;
            prev = it;
            it = fr;
        }
        fas = head;
        while(fas != slo) {
            if(prev->val != fas->val) {
                return false;
            }
            prev = prev->next;
            fas = fas->next; 
        }
        return true;
    }
    node* oddevenList(node* head) {
        node* fas = head, *slo = head;
        node* temp1 = nullptr, *temp2 = nullptr;


    }
    node* popNth_back(node* head, int n) {
        node* slo = head, *fas = head;

        while(n--) {
            fas = fas->next;
        }
        while(fas != nullptr && fas->next != nullptr) {
            fas = fas->next;
            slo = slo->next;
        }
        slo->next = slo->next->next;
        return head;
    }
    node* deleteMiddle(node* head) {
        node* fas = head, *slo = head;
        fas = fas->next->next;
        while(fas->next != nullptr && fas != nullptr) {
            fas = fas->next->next;
            slo = slo->next;
        }
        slo->next = slo->next->next;
        return head;
    }
    node* sortLL(node* head) {
        // Implement Merge sort 
    }
    node* yPoint(node* head1, node* head2) {
        node* i1 = head1, *i2 = head2;
        while(i1 != i2) {
            i1 = (!i1)? head2 : i1->next;
            i2 = (!i2)? head1 : i2->next;
        }
        return i1;
    }
    node* addOne(node* head) {
        node* p = reverseLL(head);
        if(p->val != 9) {
            p->val++;
        }
        else {
            node* i = p;
            while(i->val == 9) {
                i->val = 0;
                i = i->next;
            }
            i->val++;
        }
        head = reverseLL(p);
        return head;
    }
    node* add2num(node* l1, node* l2) {
        
    }
};

class intution {
public:
    node* constll(std::vector<int> &a) {
        node* head = new node(a[0]);
        node* it = head;
        for(int i = 1; i < a.size(); i++) {
            it = it->next;
            it->val = a[i];
        }
        return head;
    }
    node* reverseLL(node* head) {

        stack<int> r;
        node* it = head;

        while(it != nullptr) {
            r.push(it->val);
            it = it->next;
        }

        it = head;
        while(it != nullptr) {
            it->val = r.top();
            r.pop();
            it = it->next;
        }

        return head;
    }
    bool hasCycle(node* head) {
        unordered_map<node*, int> hsh;
        
        node* it = head;

        while(it != nullptr) {
            hsh[it]++;
            it = it->next;

            if(hsh[it] > 1) {
                return true;
                break;
            }
        }
        return false;
    }
    node* detectCycle(node* head) {
        unordered_map<node*, int> hsh;
        
        node* it = head;

        while(it != nullptr) {
            hsh[it]++;
            it = it->next;

            if(hsh[it] > 1) {
                return it;
            }
        }
        return nullptr;
    }
    bool isPalindrome(node* head) {
        deque<int> dq;
        
        for (node* it = head; it != nullptr; it = it->next) {
            dq.push_back(it->val);
        }
        
        // Check for palindrome
        while (dq.size() > 1) {
            if (dq.front() != dq.back()) {
                return false;
            }
            dq.pop_front();
            dq.pop_back();
        }
        
        return true;
    } 
    node* popNth_back(node* head, int n) {
        node* it = head;
        int len = 0;
        while(it != nullptr) {
            len++;
            it = it->next;
        }
        int x = len - n;
        it = head;
        while(x--) {
            it = it->next;
        }
        return it;
    }
    node* sortLL(node* head) {
        vector<int> u;
        for(node* it = head;it != nullptr;it = it->next) {
            u.push_back(it->val);
        }

        sort(u.begin(), u.end());
        int i = 0;
        for(node* it = head; it != nullptr ;it = it->next) {
            it->val = u[i++];
        }
        return head;
    }
    node* segregate(node* head) {
        node* ze = nullptr, *on = nullptr, *tw = nullptr, *it = head;
        if (!head || !head->next) return head;
        while(it != nullptr) {
            if(ze == nullptr && it->val == 0) {
                ze = it;
            }
            if(on == nullptr && it->val == 1) {
                on = it;
            }
            if(tw == nullptr && it->val == 2) {
                tw = it;
            }
            if(tw && on && ze) {
                break;
            }
            it = it->next;
        }
        it = head;
        node* tz = ze, *to = on,*tt = tw; 
        while(it != nullptr) {
            if(it != ze && it->val == 0) {
                tz->next = it;
                tz = tz->next;
            }
            if(it != on && it->val == 1) {
                to->next = it;
                to = to->next;
            }
            if(it != tw && it->val == 2) {
                tt->next = it;
                tt = tt->next;
            }
            it = it->next;
        }
        // After traversing and separating nodes:
        // terminate last sublist explicitly
        tt->next = nullptr;

        // Connect zero list to one list or two list if one list is empty
        if (ze) {
            tz->next = on ? on : tw;
        }

        // Connect one list to two list
        if (on) {
            to->next = tw;
        }

        return ze;
    }
    node* yPoint1(node* headA, node* headB) {
        for(node* it = headA; it != nullptr ;it = it->next) {
            for(node* jt = headB; jt != nullptr; jt = jt->next) {
                if(it == jt) {
                    return it;
                }
            }
        }
        return nullptr;
    }
    node* yPoint2(node* headA, node* headB) {
        unordered_map<node*,int> hsh;
        for(node* i = headA; i != nullptr ; i = i->next) {
            hsh[i]++;
        }
        for(node* j = headB; j != nullptr ; j = j->next) {
            hsh[j]++;
            if(hsh[j] > 1) {
                return j;
            }
        }
        return nullptr;
    }
};
