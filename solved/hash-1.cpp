#include <bits/stdc++.h>
// Hash using integer array
using namespace std;

int32_t main() {
    string s;
    cin >> s;
    // Build a hash table to count the occurrences of each character
    int hashh[256] = {0};

    for(int i = 0; i < s.size() ; i++) {
        hashh[s[i]]++;
    }
    int q;
    cin >> q;
    while(q--) {
        char ch;
        cin >> ch;
        cout << hashh[ch] << endl;
    }
}