/*
    Author: Dhruv Varshney
    Date - 2025/06/22
    Time - 12:45:34
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
// UTILS
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef stack<int> sti;
typedef deque<int> dqi;

const int mod = 7 + 1e9;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
        {
            return image;
        }
        int original_color = image[sr][sc];

        int m = image.size(), n = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == original_color)
                {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};
