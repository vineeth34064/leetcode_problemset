/*
 * @lc app=leetcode id=2515 lang=cpp
 *
 * [2515] Shortest Distance to Target String in a Circular Array
 */

// @lc code=start
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int countahead = 0;
        int countbehind = 0;
        if(words[startIndex]==target)return 0;
        int n = words.size();
        bool foundtarget = false;
        for(int i  = 1; i < n; i++){
            if(words[(startIndex+i)%n]==target){
                foundtarget = true;
                countahead = i;
                break;
            }
        }
        if(!foundtarget)return -1;
        for(int i = 1; i < n; i++){
            if(words[(startIndex+n-i)%n]== target){
                countbehind = i;
                break;
            }
        }
        if(!foundtarget)return -1;
        return min(countahead,countbehind);
    }
};
// @lc code=end

