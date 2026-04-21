/*
 * @lc app=leetcode id=3741 lang=cpp
 *
 * [3741] Minimum Distance Between Three Equal Elements II
 */

// @lc code=start
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp ;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        long long ans = LLONG_MAX;
        for(auto&p:mp){
            vector<int>&arr=p.second;
            if(arr.size()<3)continue;

            for(int i = 0; i + 2<arr.size(); i++){
                long long mindist = 2*(long long)(arr[i+2]-arr[i]);
                ans = min(ans,mindist);
            }
        }
        return ans==LLONG_MAX?-1:ans;
    }
};
// @lc code=end

