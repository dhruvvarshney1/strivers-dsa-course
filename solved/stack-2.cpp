#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int val;
    node* next;

    node() {
        next = nullptr;
        val = 0; // Initialize to 0 instead of NULL
    }

    node(int n, node* ptr) {
        val = n;
        next = ptr;
    }

    node(int num) {
        val = num;
        next = nullptr;
    }
};

class Stack {
    node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int x) {
        node* tem = new node(x);
        tem->next = top;
        top = tem;
        size++;
        cout << "Element pushed: " << x << '\n';
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty! Cannot pop.\n";
            return -1;
        }

        int num = top->val;
        node* tem = top;
        top = top->next;
        delete tem;
        size--;

        cout << "Element popped: " << num << '\n';
        return num;
    }

    int Top() {
        if (top == nullptr) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->val;
    }

    int Size() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {

    // Redirecting standard input and output to files using freopen()
    // if (!freopen("input.txt", "r", stdin)) {
    //     perror("Failed to reopen stdin");
    //     return 1;
    // }

    // if (!freopen("output.txt", "w", stdout)) {
    //     perror("Failed to reopen stdout");
    //     return 1;
    // }
    
    Stack s;

    int choice, value;

    while (true) {
        cout << "\n===== Stack Operations Menu =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Top\n";
        cout << "4. Display Size\n";
        cout << "5. Check if Empty\n";
        cout << "6. Exit\n";
        
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                value = s.Top();
                if (value != -1)
                    cout << "Top element is: " << value << '\n';
                break;

            case 4:
                cout << "Current stack size: " << s.Size() << '\n';
                break;

            case 5:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;

            case 6:
                cout << "Exiting...\n";
                exit(0);

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}
