# include <bits/stdc++.h>

using namespace std;

class Queue {
    int* arr;
    int start, end, curr_size, max_size;
    public:
    Queue() {
        arr = new int[50];
        start = -1;
        end = -1;
        curr_size = 0;
    }
    Queue(int len) {
        max_size = len;
        arr = new int[max_size];
        start = -1;
        end = -1;
        curr_size = 0;
    }
    void push(int x) {
        if(curr_size == max_size) {
            exit(1);
        }
        if(end == -1) {
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % max_size;
            arr[end] = x;
            curr_size++;
        }
    }
    int pop() {
        if(start == -1) {
            cout << "Queue Empty\nExiting..." << endl;
        }
        int tem = arr[start];
        if(curr_size == 1) {
            
        }
    }
};