#include <iostream>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------------------------------------------------- Easy

/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * Note: For the purpose of this problem, we define empty string as valid palindrome.
 */
struct lc0125 {
    bool isPalindrome(string s) {
        if(s.empty()) return true;

        int l = 0, r = s.size()-1;
        while(l<r) {
            if(!isalnum(s[l])) l++;
            else if(!isalnum(s[r])) r--;
            else {
                if(tolower(s[l++]) != tolower(s[r--])) return false;
            }
        }
        return true;
    }
};

void main_lc0125() {
    lc0125 solu;
    string s {"A man, a plan, a canal: Panama"};
    cout << solu.isPalindrome(s);
}


/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 */
#include <deque>
#include <unordered_map>
struct lc0020 {
    bool isValid(string s) {
        if(s.size()%2) return false;
    deque<char> stack;
    unordered_map<char,char> tbl {{'(',')'}, {'[',']'}, {'{','}'}};
        for(auto chr:s) {
            if(chr=='(' || chr=='[' || chr=='{')
                stack.push_front(chr);
            else {
                if (chr != tbl[stack.front()]) return false;
                stack.pop_front();
            }
        }
        if(!stack.empty()) return false;
    return true;
    }
};

void main_lc0020(void)
{
    lc0020 solu;
    //string s {"()[]{}"};
    string s {"(("};
    auto ans = solu.isValid(s);
    cout << ans << endl;
}

/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 */
struct lc0014 {
    string longestCommonPrefix(vector<string>& strs) {
    string ans {};
        if(strs.empty()) return ans;
    string s = strs.front();
    int i=0;
        for(auto chr:s) {
            for(auto str:strs)
                if (chr != str[i]) return ans;
            i++;
            ans += chr;
        }
    return ans;
    }
};

void main_lc0014(void)
{
    lc0014 solu;
    vector<string> strs {"flower","flow","flight"};
    for(auto str:strs)
        cout << str << " ";
    auto ans = solu.longestCommonPrefix(strs);
    cout << endl << ans << endl;
}

/*
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 */
#include <unordered_map>
struct lc0013 {
    int romanToInt(string s) {
    unordered_map<char,int> tbl {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
    int ans = 0;
        for(auto it=s.begin(); it!=prev(s.end()); it++)
            (tbl[*it] < tbl[*(it+1)]) ? ans -= tbl[*it] : ans += tbl[*it];
        ans += tbl[*(s.end()-1)];
    return ans;
    }
};

void main_lc0013(void)
{
    lc0013 solu;
    string s {"MCMXCIV"};
    cout << s << endl;
    auto ans = solu.romanToInt(s);
    cout << ans << endl;
}