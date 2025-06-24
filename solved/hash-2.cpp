# include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<int,int> hsh;
    int n;
    cin >> n;
    int array[n];
    for(int i = 0; i < n; i++){
        cin >> array[i];
        hsh[array[i]]++;
    }
    for(auto it : hsh){
        cout << it.first << " " << it.second << '\n';
    }
    int q;
    cin >> q;
    while(q--) {
        int num;
        cin >> num;
        cout << hsh[num] << '\n';
    }
}

// On average, unordered_map<int,int> takes O(1) to fetch and on worst it takes O(N) to fetch
// Whereas on map<int,int> takes O(log N) to fetch any kind of case.