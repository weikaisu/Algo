#include <iostream>
using namespace std;

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
#include <vector>
#include <unordered_map>
struct lc001 {
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        for (auto i=0; i<nums.size(); i++)
            table[nums[i]]=i;
        for(auto i=0; i<nums.size(); i++) {
            int diff = target - nums[i];
            if(table.count(diff) && table[diff] != i)
                return {i, table[diff]};
        }
        return {-1, -1};
    }
};

void main_lc001(void)
{
    /*
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
    */
    vector<int> nums {2, 7, 11, 15}, ans;
    lc001 solu;
    ans = solu.twoSum(nums, 22);

    for(auto e:ans) cout<< e << " ";
}