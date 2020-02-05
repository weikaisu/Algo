#include <iostream>
using namespace std;

//------------------------------------------------------------------------------------------------- Easy

/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 */
#include <vector>
struct lc0053 {
public:
    int maxSubArray(vector<int>& nums) {

        if(!nums.size()) return 0;
        if(nums.size()==1) return *nums.begin();

    int sCurr, sPre1=nums[0], max_val=nums[0];
        for(auto it=nums.begin()+1; it!=nums.end(); it++) {
            sCurr   = max(*it+sPre1, *it);
            max_val = max(max_val, sCurr);
            sPre1 = sCurr;
        }
    return max_val;
    }
};

void main_lc0053(void)
{
    lc0053 solu;
    //vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums {-1, -2};
    auto ans = solu.maxSubArray(nums);
    cout << ans << endl;
}