// 08-17-2023
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> minDirection(vector<vector<int>>& mat) {
    int m = mat.size();     // rows
    int n = mat[0].size();  // cols
    vector<vector<int>> result(m, vector<int>(n, 0));   // result matrix
    queue<pair<int, int>> q;    // stores the location where 0s are found

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                // if the current element is 0, set the corresponding element in the result matrix to 0
                result[i][j] = 0;
                // and push its location into 'q'
                q.push({i, j});
            } else {
                // if the current element is 1, set the corresponding element in the result matrix to -1
                // to indicate that it needs to be updated later
                result[i][j] = -1;
            }
        }
    }

    // define the possible directions to move from the current cell (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        auto curr = q.front();  // get the front element of 'q'
        q.pop();
        int r = curr.first;
        int c = curr.second;

        for (const auto& dir : directions) {
            // for each direction, calculate the new row and column indices
            int newR = r + dir.first;
            int newC = c + dir.second;

            // check if the new indices are within the matrix boudaries and if the cell was not visited before
            if (newR >= 0 && newR < m && newC >= 0 && newC < n && result[newR][newC] == -1) {
                result[newR][newC] = result[r][c] + 1;
                q.push({newR, newC});
            }
        }
    }
    return result;
}

int main() {
    // vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result = minDirection(mat);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
