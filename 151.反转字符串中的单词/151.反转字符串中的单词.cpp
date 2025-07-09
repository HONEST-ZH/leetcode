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
        typedef struct word{
            int index;
            int len;
        }word;
        //遍历字符串，找到第一个不为空格的字符的位置并记录起始索引，递增记录len直到下次遇到空格
        std::vector<word> words;
        int charflag = 0,blankflag = 0,i = 0;
        word temp = {0, 0};
        for (i;i< s.size();i++){//注意字符串长度的问题，末尾有/0的休止符号，是s[s.size]正好是休止符    
            if (s[i] != ' ') {
                //第一次遇到非空的字符，记录索引（word起始位置），设置初始长度，置位charflag，重置blankflag
                if (charflag == 0){
                    temp.index = i;
                    temp.len = 1;
                    charflag = 1;
                    blankflag = 0;
                }
                //之后遇到，递增word长度技术
                else{
                    temp.len++;
                }
            }
            else{
                //第一次遇到空格，且temp已被声明将temp中已有的值保存到words中，重置temp,置位blankflag，重置charflag
                if ((blankflag == 0) && (temp.len !=0)){
                   //std::cout << "temp.index: " << temp.index << ", temp.len: " << temp.len << std::endl;
                   words.push_back(temp);
                   temp = {0, 0};
                   blankflag = 1;
                   charflag = 0;
                }
                //遇到多个空格啥也不干
                else{  
                    continue;
                }
            }
        }
        //如果最后一个字符不是空格，temp中仍有值，保存到words中
        if (temp.len != 0) {
            //std::cout << "temp.index: " << temp.index << ", temp.len: " << temp.len << std::endl;
            words.push_back(temp);
        }
            
        //使用vector的reverse函数逆序迭代器输出res
        std::string res;
        for (auto it = words.rbegin(); it != words.rend(); ++it) {
            res += s.substr(it->index, it->len);
            if (it + 1 != words.rend()) res += ' ';
        }
        return res;
    }
};
//"  hello world  "\n
// @lc code=end

