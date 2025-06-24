# include <bits/stdc++.h>

using namespace std;

const int mod = 7 + 1e9;

typedef vector<int> vi;
class solution {
    public:
    int majorElement(vector<int> &a) {
        int n = a.size(), c = 0;
        unordered_map<int,  int> hsh;
        for(int i = 0; i < n ; i++) {
            hsh[a[i]]++;
        }

        for(auto pair : hsh) {
            if(pair.second > (n / 2)) {
                return pair.first;
            }
        }
        return -1;
    }
    
    // Kadane 's Algorithm
    int maxSubArray(vector<int> &a) {
        int n = a.size(), best = 0, sum = 0;
        for(int i = 0; i < n ; i++) {
            sum = max(a[i], sum + a[i]);
            best = max(best, sum);
        }

        return best;
    }
};

class slow {
    public:
    int majorElement(vector<int> &a) {
        int n = a.size(), c1 = 0, elem = a[0];
        for(int i = 0; i < n ; i++) {
            if(a[i] == elem) c1++;
            else c1--;
        }
        int c2 = 0;
        for(int i = 0; i < n ; i++) {
            if(a[i] == elem) c2++;
        }
        if(c2 > (n / 2)) {
            return elem;
        }
        else return -1;
    }
};
int main() {
    int n;
    cin >> n;
    vi a(n);
    for(auto x : a) {
        cin >> x;
    }
    slow s;
    int ans = s.majorElement(a);
    cout << "Answer: " << ans << '\n';
}