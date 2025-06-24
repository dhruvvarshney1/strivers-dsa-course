# include <bits/stdc++.h>

using namespace std;


class fix {
public:
    // Function to decide the priorities of the operand
    int priority(char ch) {
        if(ch == '^') return 4;
        if(ch == '|' || ch == '&') return 3;
        if(ch == '*' || ch == '/') return 2;
        if(ch == '+' || ch == '-') return 1;
        return 0;
    }
    //Function to check if the character is a operator
    bool isOperator(char ch) {
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
        return false;
    }
    // Function to convert from infix to postfix
    string infix_to_postfix(string s) {
        stack<char> st;
        string ans;
        for(int i = 0; i < s.length() ; i++) {

            if(s[i] == ' ') continue;

            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
                ans += s[i];
            }
            else if(s[i] == '(') st.push('(');
            else if(s[i] == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();                 
                }
                st.pop();
            }
            else {
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
    // Function to convert from infix to prefix 
    string infix_to_prefix(string s) {

        // Step 1:
        reverse(s.begin(), s.end());

        // Step 2:
        stack<char> st;
        string ans;
        for(int i = 0; i < s.length() ; i++) {

            if(s[i] == ' ') continue;

            // Checking Reverse Brackets
            if(s[i] == '(') s[i] = ')';
            else if(s[i] == ')') s[i] = '(';

            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
                ans += s[i];
            }
            else if(s[i] == '(') st.push('(');
            else if(s[i] == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();                 
                }
                st.pop();
            }
            else {
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        // Step 3:
        reverse(ans.begin(), ans.end());

        return ans;
    }
    // Function to convert from postfix to infix
    string postfix_to_infix(string s) {
        stack<string> st;
        for(int i = 0; i < s.length(); i++) {
            if(isalnum(s[i])) {
                string str(1, s[i]);
                st.push(str);
            }

            if(isOperator(s[i])) {
                string s1 = st.top();st.pop();
                string s2 = st.top();st.pop();
                string tem = "(" + s2 + s[i] + s1 + ")";
                st.push(tem);
            }
        }
        reverse(st.top().begin(), st.top().end());
        return st.top();
    }
    // Function to convert from prefix to infix
    string prefix_to_infix(string s) {
        stack<string> st;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(isalnum(s[i])) {
                string str(1, s[i]);
                st.push(str);
            }

            if(isOperator(s[i])) {
                string s1 = st.top();st.pop();
                string s2 = st.top();st.pop();
                string tem = "(" + s1 + s[i] + s2 + ")";
                st.push(tem);
            }
        }
        return st.top();
    }
    // Function to convert from postfix to prefix
    string postfix_to_prefix(string s) {
        stack<string> st;
        for(int i = 0; i < s.length() ; i++) {
            if(isalnum(s[i])) {
                string str(1, s[i]);
                st.push(str);
            }
            else if(isOperator(s[i])) {
                if(st.size() < 2) {
                    // Handle invalid expression
                    return "Invalid Expression";
                }
                string s1 = st.top();st.pop();
                string s2 = st.top();st.pop();
                st.push(s[i] + s2 + s1);
            }
        }

        if(st.size() == 1) {
            return st.top();
        } else {
            return "Invalid Expression";
        }
    }
    // Function to convert from prefix to postfix
    string prefix_to_postfix(string s) {
        stack<string> st;
        for(int i = s.length() - 1; i >= 0 ; i--) {
            if(isalnum(s[i])) {
                string str(1, s[i]);
                st.push(str);
            }
            else if(isOperator(s[i])) {
                string s1 = st.top();st.pop();
                string s2 = st.top();st.pop();
                st.push(s1 + s2 + s[i]);
            }
        }
        return st.top();
    }
};

int main() {
    string s;
    getline(cin, s);
    fix f;
    string ans = f.prefix_to_postfix(s);
    cout << ans;
}