#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        searchNearest(mat);
        return mat;
    }

    void searchNearest(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int row = 0; row < mat.size(); row++) {
            for (int col = 0; col < mat[0].size(); col++) {
                if (mat[row][col] == 0) {
                    visited[row][col] = true;
                    q.emplace(row, col);
                }
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int i = front.first, j = front.second;

            if (i+1 < n && j < m && !visited[i+1][j]) {
                mat[i+1][j] = mat[i][j] + 1;
                visited[i+1][j] = true;
                q.emplace(i+1, j);
            }
            if (i-1 >= 0 && j < m && !visited[i-1][j]) {
                mat[i-1][j] = mat[i][j] + 1;
                visited[i-1][j] = true;
                q.emplace(i-1, j);
            }
            if (i < n && j+1 < m && !visited[i][j+1]) {
                mat[i][j+1] = mat[i][j] + 1;
                visited[i][j+1] = true;
                q.emplace(i, j+1);
            }
            if (i < n && j-1 >= 0 && !visited[i][j-1]) {
                mat[i][j-1] = mat[i][j] + 1;
                visited[i][j-1] = true;
                q.emplace(i, j-1);
            }
        }
    }

};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 0, 1, 1}};
    mat = s.updateMatrix(mat);

    for (auto vec : mat) {
        for (auto num : vec) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}
