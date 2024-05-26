#include <iostream>
#include <vector>
using namespace std;
void print_int(vector<int> array) {
    for (int i : array) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return findMaxSubArray(nums, 0, nums.size());
    }
    int findCross(vector<int>& nums, int start, int mid, int end) {
        int left_sum = -INT_MAX;
        int sum = 0;
        for (int i = mid - 1; i >= 0; i--) {
            sum += nums[i];
            left_sum = max(left_sum, sum);
        }
        int right_sum = -INT_MAX;
        sum = 0;
        for (int i = mid; i < end; i++) {
            sum += nums[i];
            right_sum = max(right_sum, sum);
        }
        return right_sum + left_sum;
    }
    int findMaxSubArray(vector<int>& nums, int start, int end) {
        if (end-start == 1) return nums[start];
        int compLeft = findMaxSubArray(nums, start, (start+end)/2);
        // cout << "compLeft: " << compLeft << endl;
        int compRight = findMaxSubArray(nums, (start+end)/2, end);
        // cout << "compRight: " << compRight << endl;
        int cross = findCross(nums, start, (start+end)/2, end);
        // cout << "cross: " << cross << endl;
        return max(max(compRight, compLeft), cross);
    }
};
// int main() {
//     Solution sol;
//     vector<int> v = {-2, 1};
//     int ans = sol.maxSubArray(v);
//     // cout << "ans: " << ans << endl;
// }