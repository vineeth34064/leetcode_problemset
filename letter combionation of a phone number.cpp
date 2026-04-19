/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
       vector<string>result;
       if(digits.size()==0)return result;

         vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};   
        result.push_back("");
        for(int i = 0; i < digits.size(); i++){
            vector<string>temp;
            string value = mapping[digits[i]-'0'];
            for(int k = 0; k < result.size(); k++){
            for(int j = 0; j < value.size(); j++){
                    temp.push_back(result[k]+value[j]);
                }
            }
            result = temp;
        }
        return result;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
       vector<string>result;
       if(digits.size()==0)return result;

         vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};   
        result.push_back("");
        for(int i = 0; i < digits.size(); i++){
            vector<string>temp;
            string value = mapping[digits[i]-'0'];
            for(int k = 0; k < result.size(); k++){
            for(int j = 0; j < value.size(); j++){
                    temp.push_back(result[k]+value[j]);
                }
            }
            result = temp;
        }
        return result;
    }
};
// @lc code=end

