#include <iostream>
#include <vector>
using namespace std;

//------------------------------------------------------------------------------------------------- Easy
/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it
 * would be if it were inserted in order.
 * You may assume no duplicates in the array.
 */
#include <algorithm>
struct lc0035 { // E
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(!size) return 0;
        auto first = nums.begin();

        while(size) {
            auto half = size/2;
            auto mid = first + half;
#if 0      // lower_bound 1st element >= target
            if (*mid < target) {
                first = ++mid;
                size -= half+1;
            } else {
                size = half;
            }
#else       // upper_bound 1st element > target
            if (target < *mid) {
                size = half;
            } else {
                first = ++mid;
                size -= half+1;
            }
#endif
        }

        return first - nums.begin();

        //return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};


void main_lc0035(void)
{
    lc0035 solu;
    vector<int> nums {1,2,3,5,6};
    int target = 4;
    auto ans = solu.searchInsert(nums, target);
    cout << ans << endl;
}