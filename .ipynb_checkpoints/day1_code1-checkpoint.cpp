#include <iostream>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> i(matrix.size(), 0), j(matrix.size(), 0);
        if (!matrix.size()) return;
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool firstrow = false;
        bool firstcol = false;
        for (int j = 0; j < cols; j++) {
            if (matrix[0][j] == 0) {
                firstrow = true;
                break;
            }
        }
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                firstcol = true;
                break;
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < rows; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < cols; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstrow) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstcol) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> v = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution sol;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    sol.setZeroes(v);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}