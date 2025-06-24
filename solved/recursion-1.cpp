# include<bits/stdc++.h>

using namespace std;

void printNos(int n) {
    if(n == 0) {
        return;
    }

    cout << n << ' ';
    printNos(n - 1);
}

void repeatNtimes(string s, int n) {
    if(n == 0) {
        return;
    }

    repeatNtimes(s, n - 1);

    cout << s << '\n';
}

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

void arrayReverse(int a[], int s, int e) {
    if(s > e) return;
    swap(a[s], a[e]);
    arrayReverse(a, s + 1, e - 1);
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
    }
    arrayReverse(a, 0, n - 1);
    for(int i = 0; i < n ; i++) {
        cout << a[i] << ' ';
    }
}