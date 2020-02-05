#include <iostream>
#include <string>
#include <vector>
using namespace std;

//------------------------------------------------------------------------------------------------- Easy

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
        for(auto it=s.begin(); it!=s.end()-1; it++)
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