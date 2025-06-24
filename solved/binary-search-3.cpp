# include <bits/stdc++.h>

using namespace std;

int mySqrt(int n) {
    int lo = 0, hi = n / 2;
    while(lo <= hi) {
        int mid = lo + (hi - 1) / 2;

        if(mid*mid == n) {
            return mid;
        }
        else if(mid * mid < n) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return -1;
}

