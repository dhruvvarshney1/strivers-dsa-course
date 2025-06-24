# include<bits/stdc++.h>
using namespace std;

class solution {
    public:
    bool isValid(string s) {
        stack<char> ds;
        for(char ch : s) {
            if(ch == '[' || ch == '{'|| ch == '(') {
                ds.push(ch);
            }
            else {
                if(ds.empty()) return false;
                char tp = ds.top();
                ds.pop();
                if((tp == '(' && ch == ')') || (tp == '{' && ch == '}') || (tp == '[' && ch == ']')) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return ds.empty();
    }
};

int main() {
    solution sol;
    int _t = 1;
    cin >> _t;
    while(_t--) {
        string s;
        cin >> s;
        cout << sol.isValid(s) << '\n';
    } 
    return 0;
}
