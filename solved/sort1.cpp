# include <bits/stdc++.h>

using namespace std;
class sortt {
public:
    void ssort(vector<int> &a) {
        int n = a.size();
        for(int i = 0; i < n ; i++) {
            int min = INT_MAX, pos;
            for(int j = i; j < n; j++) {
                if(a[j] < min) {
                    min = a[j];
                    pos = j;
                }
            }
            swap(a[i], a[pos]);
        }
        cout << "Sorted array using selection sort: ";
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }

    void bsort(vector<int> &a) {
        int n = a.size();
        for(int i = 0; i < n ; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    

        cout << "Sorted array using bubble sort: ";
        for(int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    void isort(vector<int> &a) {
        int n = a.size();
        for(int i = 0; i < n ; i++) {
            int j = i;
            while(j > 0) {
                if(a[j - 1] > a[j]) {
                    swap(a[j], a[j - 1]);
                }
                j--;
            }
        }

        cout << "Sorted array using insertion sort: ";
        for(int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
};

int main() {
    vector<int> a = {13, 46, 24, 52, 20, 9};
    sortt s;
    s.isort(a);
}