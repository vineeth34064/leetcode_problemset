#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) { // O(n) time, O(n) space
        int n = nums.size();
        if (n < 3) {
            return -1;
        }

        vector<int> left_min(n, INT_MAX);
        for (int i = 1; i < n; ++i) {
            left_min[i] = min(left_min[i-1], nums[i-1]);
        }

        vector<int> right_min(n, INT_MAX);
        for (int i = n - 2; i >= 0; --i) {
            right_min[i] = min(right_min[i+1], nums[i+1]);
        }

        int minimum = INT_MAX;
        bool isfound = false;

        // Iterate through each element as a potential middle element 'nums[j]'
        for (int j = 1; j < n - 1; ++j) {
            if (nums[j] > left_min[j] && nums[j] > right_min[j]) {
                int current_sum = left_min[j] + nums[j] + right_min[j];
                minimum = min(minimum, current_sum);
                isfound = true;
            }
        }

        return isfound ? minimum : -1;
    }
};

int main(){
    int numssize;
    cin>>numssize;
    vector<int>nums(numssize);
    for(int i = 0; i < nums.size(); i++){
        cin>>nums[i];
    }

    Solution sol;
    int sum = sol.minimumSum(nums);
    cout << sum << endl;

    return 0;
}
