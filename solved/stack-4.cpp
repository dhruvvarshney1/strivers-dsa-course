# include<bits/stdc++.h>
using namespace std;

class MinStack {

    stack<pair<int, int>> st;
    int min_val;
    public:
        MinStack() {
            min_val = INT_MAX;
        }
        
        void push(int val) {
            if(st.empty()) {
                min_val = val;+
            }
            if(val < min_val) {
                min_val = val;
            }
            st.push({val, min_val});
        }
        
        void pop() {
            st.pop()
        }
        
        int top() {
            if(st.empty()) return -1;

            return st.top();
        }
        
        int getMin() {
            return min_val;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */