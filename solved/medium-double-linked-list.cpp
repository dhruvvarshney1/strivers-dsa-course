// Include header files
# include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
    node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class solution {
    public:

    void deleteAllOccurOfX(struct node** head_ref, int x) {
        struct node* temp = *head_ref;
        struct node* prev = NULL;
        while (temp != NULL && temp->data == x) {
            *head_ref = temp->next;
            free(temp);
            temp = *head_ref;
        }
        while (temp != NULL) {
            while (temp != NULL && temp->data != x) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) return;
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } 
    }
};

int main() {

}