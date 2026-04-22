/*
 * @lc app=leetcode id=2452 lang=cpp
 *
 * [2452] Words Within Two Edits of Dictionary
 */

// @lc code=start
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;

        for(auto&p:queries){
            for(auto&d:dictionary){
                int difference = 0;
                  for(int i = 0; i < p.size(); i++){
                    if(p[i]!=d[i])difference++;
                    if(difference > 2)break;
                }
                if(difference<=2){
                    ans.push_back(p);
                    break;
                }            
            }
        }
        return ans;
    }
};
// @lc code=end
