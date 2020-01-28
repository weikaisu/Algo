#include <iostream>
using namespace std;

/*
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical
 * lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with
 * x-axis forms a container, such that the container contains the most water.
 */
#include <vector>
struct lc0011 { // M
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

void main_lc0011(void)
{
    lc0011 solu;
    vector<int> height {1,8,6,2,5,4,8,3,7};
    auto ans = solu.maxArea(height);
    cout << ans << endl;
}

/*
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */
#include <vector>
struct lc0026 { // E
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ptr_slow = 1, ptr_fast = 1;
        int pre_val = nums.front();

        while (ptr_fast < nums.size()) {
            if (pre_val == nums[ptr_fast])
                n--;
            else
                nums[ptr_slow++] = nums[ptr_fast];
            pre_val = nums[ptr_fast++];
        }
        return n;
    }
};

void main_lc0026(void)
{
    lc0026 solu;
    vector<int> nums {0,0,1,1,1,2,2,3,3,4};
    auto ans = solu.removeDuplicates(nums);
    cout << ans << endl;
    for(auto num:nums) cout << num << ' ';
}

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
#include <vector>
#include <unordered_map>
struct lc0001 { // E
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

void main_lc0001(void)
{
    /*
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
    */
    lc0001 solu;
    vector<int> nums {2, 7, 11, 15};
    auto ans = solu.twoSum_slow(nums, 22);

    for(auto e:ans) cout<< e << " ";
}