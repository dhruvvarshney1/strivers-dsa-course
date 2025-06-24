#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision_suboptimal(vector<int> &a) {
    if (a.size() == 0) return {}; // Handle empty input.

    bool flag = true; // Flag to check if collisions are still happening.
    vector<int> res;

    while (flag) {
        flag = false; // Assume no collisions will happen in this iteration.
        res.clear();  // Clear the result vector for this iteration.

        for (int i = 0; i < a.size(); i++) {
            // Check for collision between two asteroids moving in opposite directions.
            if (i < a.size() - 1 && a[i] > 0 && a[i + 1] < 0) {
                flag = true; // A collision occurred.

                // Resolve collision based on absolute values.
                if (abs(a[i]) > abs(a[i + 1])) {
                    res.push_back(a[i]); // Right-moving asteroid survives.
                } else if (abs(a[i]) < abs(a[i + 1])) {
                    res.push_back(a[i + 1]); // Left-moving asteroid survives.
                }
                // If both have the same absolute value, both are destroyed (do nothing).
                i++; // Skip the next asteroid since it was part of the collision.
            } else {
                res.push_back(a[i]); // No collision, add the asteroid to the result.
            }
        }

        a = res; // Update the input vector with the result of this iteration.
    }

    return res;
}

vector<int> asteroidCollision(vector<int> &a) {
    
}
int main() {
    int _t = 1;
    // cin >> _t;
    while (_t--) {
        int n;
        cin >> n;
        vector<int> asteroid(n);
        
        // Correctly read input into the vector.
        for (int i = 0; i < n; i++) {
            cin >> asteroid[i];
        }

        vector<int> result = asteroidCollision(asteroid);

        for (int x : result) {
            cout << x << ' ';
        }
    }
}
