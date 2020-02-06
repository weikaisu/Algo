#include <iostream>
using namespace std;

//------------------------------------------------------------------------------------------------- Easy

/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
struct lc0070 {
    int climbStairs(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;

        int nM0=0, nM1=2, nM2=1;
        for(int i=3; i<=n; i++) {
            nM0 = nM1 + nM2 ;
            nM2=nM1; nM1=nM0;
        }
        return nM0;

        // recursive way
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

void main_lc0070(void) {
    lc0070 solu;
    int n = 4;
    auto ans = solu.climbStairs(n);
    cout << ans << endl;
}

/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 */
#include <vector>
struct lc0053 {
    int maxSubArray(vector<int>& nums) {

        if(!nums.size()) return 0;
        if(nums.size()==1) return *nums.begin();

    int sCurr, sPre1=nums[0], max_val=nums[0];
        for(auto it=next(nums.begin()); it!=nums.end(); it++) {
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
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    //vector<int> nums {-1, -2};
    auto ans = solu.maxSubArray(nums);
    cout << ans << endl;
}