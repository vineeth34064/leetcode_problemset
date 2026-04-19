/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0,j = 0;
        int maxdistance = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] > nums2[j]){
                i++;
            }else{
                maxdistance = max(maxdistance,j-i);
                j++;
            }
        }
        return maxdistance;
    }
};
// @lc code=end

