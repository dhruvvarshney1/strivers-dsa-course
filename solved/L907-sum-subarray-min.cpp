# include <bits/stdc++.h>
using namespace std;

const int mod = 7 + 1e9;
# define int long long

int sumSubarrayMins_suboptimal(vector<int> &a) {

    int n = a.size(), sum = 0;

    for(int i = 0; i < n; i++) {
        int mini = INT_MAX;
        for(int j = i; j < n ; j++) {
            mini = min(a[j], mini);
            sum = (sum + mini) % mod;
        }
    }

    return sum;
}

vector<int> nseIdx(vector<int>& a) {
    int n = a.size();
    stack<int> s;
    vector<int> res(n);
    
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if(s.empty()) res[i] = n;
        else res[i] = s.top();
        
        s.push(i);
    }
    
    return res;
}

vector<int> pseIdx(vector<int>& a) {
    int n = a.size();
    stack<int> s;
    vector<int> res(n);
    
    for(int i = 0; i < n; i++) {
        while(!s.empty() && a[s.top()] > a[i]) {
            s.pop();
        }
        if(s.empty()) res[i] = -1;
        else res[i] = s.top();
        
        s.push(i);
    }
    
    return res;
}

int sumSubarrayMins(vector<int> &a) {
    int n = a.size();
    int sum = 0;
    
    vector<int> pse = pseIdx(a);
    vector<int> nse = nseIdx(a);
    
    for(int i = 0; i < n; i++) {
        int l = i - pse[i];
        int r = nse[i] - i;
        sum = (sum + (l * r * a[i]) % mod) % mod;
    }
    
    return sum;
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = sumSubarrayMins(a);
    cout << ans;
    
    return 0;
}
