#include <iostream>
#include <vector>
using namespace std;
void print_int(vector<int> array) {
    for (int i : array) {
        cout << i << " ";
    }
    cout << endl;
}

void print_bool(vector<bool> array) {
    for (bool i : array) {
        cout << i << " ";
    }
    cout << endl;
}


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int m = nums[nums.size()-1];
        int j = nums.size()-1;
        for (j = nums.size()-1; j>=0; j--) {
            if (nums[j] < m) {
                break;
            }
            m = max(m , nums[j]);
        }
        // print_bool(greater);
        // print_int(nums);
        // cout << "j: " << j << endl;
        if (j >= 0) {
            sort(nums.begin() + j + 1, nums.end());
            int loc = lower_bound(nums.begin() + j + 1, nums.end(), nums[j])-nums.begin();
            while (nums[loc] == nums[j]) loc++;
            // cout << "loc: " << loc << endl;
            swap(nums[j], nums[loc]);
            sort(nums.begin() + j + 1, nums.end());
            // print_int(nums);
            return;
        }
        reverse(nums.begin(), nums.end());
        // print_int(nums);
    }
};

int main() {
    Solution sol;
    vector<int> v = {1, 2, 3};
    sol.nextPermutation(v);
}