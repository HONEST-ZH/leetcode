/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::vector<std::string> words;
        int n = s.size();
        int i = 0;
        while (i < n) {
            // 跳过前导空格
            while (i < n && s[i] == ' ') ++i;
            if (i >= n) break;
            int j = i;
            while (j < n && s[j] != ' ') ++j;
            words.push_back(s.substr(i, j - i));
            i = j;
        }
        std::string result;
        for (int k = words.size() - 1; k >= 0; --k) {
            result += words[k];
            if (k != 0) result += ' ';
        }
        return result;
    }
};
//"  hello world  "\n
// @lc code=end

