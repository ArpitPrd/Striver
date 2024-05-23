#include <map>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> i(matrix.size(), 0), j(matrix.size(), 0);
        for (int l = 0; l < matrix.size(); l++) {
            for (int m = 0; m < matrix[0].size(); m++) {
                if (matrix[l][m] == 0) {
                    i[l] = 1;
                    j[m] = 1;
                }
            }
        }
        for (int l = 0; l < matrix.size(); l++) {
            if (i[l] == 1) {
                for (int m = 0; m < matrix[0].size(); m++) {
                    matrix[l][m] = 0;
                }
            }
        }
        for (int m = 0; m < matrix[0].size(); m++) {
            if (j[m] == 1) {
                for (int l = 0; l < matrix.size(); l++) {
                    matrix[l][m] = 0;
                }
            }
        }
    }
};
