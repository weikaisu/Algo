#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------------------------------------------------- Easy

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