#include <iostream>
using namespace std;

/*
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical
 * lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with
 * x-axis forms a container, such that the container contains the most water.
 */
#include <vector>
struct lc011 { // M
    int maxArea(vector<int>& height) {
        int max_val = 0;

        return max_val;
    }

    int maxArea_slow(vector<int>& height) {
        int max_val = 0;
        for(auto i=0; i<height.size()-1; i++)
            for(auto j=i+1; j<height.size(); j++) {
                int area=(j-i)*(min(height[i], height[j]));
                max_val = max(max_val, area);
            }
        return max_val;
    }
};

void main_lc011(void)
{
    lc011 solu;
    vector<int> height {1,8,6,2,5,4,8,3,7};
    auto ans = solu.maxArea(height);
    cout << ans << endl;
}

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
#include <vector>
#include <unordered_map>
struct lc001 { // E
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
    };

    vector<int> twoSum_slow(vector<int>& nums, int target) {
        for(auto i=0; i<nums.size()-1; i++)
            for(auto j=i+1; j<nums.size(); j++)
                if(nums[i]+nums[j]==target)
                    return {i, j};
        return {-1, -1};
    };
};

void main_lc001(void)
{
    /*
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
    */
    lc001 solu;
    vector<int> nums {2, 7, 11, 15};
    auto ans = solu.twoSum_slow(nums, 22);

    for(auto e:ans) cout<< e << " ";
}