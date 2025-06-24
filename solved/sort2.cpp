# include <bits/stdc++.h>

using namespace std;

class sortt {
public:
    void merge(vector<int> &a, int lo, int mid, int hi) {
        vector<int> temp; // temporary array
        int l = lo, r = mid + 1; // starting index of left half of array and right half of array

        // storing elements in the temporary array in a sorted array

        while(l <= mid && r <= hi) {
            if(a[l] <= a[r]) {
                temp.push_back(a[l]);
                l++;
            }
            else {
                temp.push_back(a[r]);
                r++;
            }
        }

        // if elements on the left half are still left
        while(l <= mid) {
            temp.push_back(a[l]);
            l++;
        }

        // if elements on the right half are still left
        while(r <= hi) {
            temp.push_back(a[r]);
            r++;
        }
        
        // copying the sorted elements back to the original array
        for(int i = lo; i <= hi; i++) {
            a[i] = temp[i - lo];
        }
    }

    void mergesort(vector<int> &a,int lo, int hi) {

        if(lo >= hi) return;
        int mid = (lo + hi) / 2;
        mergesort(a, lo, mid);
        mergesort(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }

    void rbsort(int a[], int n) {
        if(n == 1) {
            return;
        }

        for(int j = 0; j < n - 1 ; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }

        rbsort(a, n - 1);
    }

    // void risort(int a[], int idx, int n) {
    //     if(idx == n) {
    //         return;
    //     }

    //     for(int j = idx; j >= 0; j--) {
    //         if(a[j + 1] < a[j]) {
    //             swap(a[j], a[j - 1]);
    //             // break;
    //         }
    //     }
    //     risort(a, idx + 1, n);
    // }
    int partition(vector<int> &a, int lo, int hi) {
        int pivot = a[hi];
        int i = lo, j = hi;

        while(i < j) {
            while(a[i] <= pivot && i <= hi - 1) {
                i++;
            }

            while(a[j] > pivot && j >= lo + 1) {
                j--;
            }

            if(i < j) swap(a[i], a[j]);
        }

        swap(a[lo], a[j]);
        return j;
    }

    void qsort(vector<int> &a, int lo, int hi) {
        // TODO: Implement Quick Sort
        if(lo < hi) {
            int pi = partition(a, lo, hi);
            qsort(a, lo, pi - 1);
            qsort(a, pi + 1, hi);
        }
    }
};

int main() {
    vector<int> a = {5, 2, 8, 1, 9, 3, 6, 7};
    sortt s;
    s.qsort(a, 0, a.size() - 1);
    cout << "Sorted array : ";
    for(int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
    return 0;
}