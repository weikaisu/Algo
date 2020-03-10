#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addListNode(ListNode* head, int val)
{
    ListNode* root;
    while(head->next) head=head->next;
    head->next = new ListNode(val);
    return root;
}

void printListNode(ListNode* head)
{
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }
    cout << endl;
}

//------------------------------------------------------------------------------------------------- Medium

/*
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical
 * lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with
 * x-axis forms a container, such that the container contains the most water.
 */
#include <vector>
#include <algorithm>
struct lc0011 { // M
    int maxArea(vector<int>& height) {
        int max_val = 0;
        auto it_front = height.begin(), it_end = prev(height.end());
        while(it_front < it_end){
            max_val = max(max_val, (int)(it_end-it_front) * min(*it_front, *it_end));
            if (*it_front<*it_end) it_front++;
            else it_end--;
        }
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

//------------------------------------------------------------------------------------------------- Easy

/*
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 */
struct lc0136 {
    int singleNumber(vector<int>& nums) {
        // any number xor with itself is zero
        int res = 0;
        for(auto num:nums)
            res ^= num;
        return res;
    }
};

void main_lc0136() {
    lc0136 solu;
    vector<int> nums {4,1,2,1,2};
    cout << solu.singleNumber(nums) << endl;
}

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and
 * sell one share of the stock multiple times).
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 */
struct lc0122 {
    int maxProfit(vector<int>& prices) {
        int prf = 0;
        for(auto i=1; i<prices.size(); i++)
            prf += max(prices[i]-prices[i-1], 0);
        return prf;
    }
};

void main_lc0122() {
    lc0122 solu;
    vector<int> prices {7,1,5,3,6,4};
    cout << solu.maxProfit(prices);
}


/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 */
struct lc0121 {
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN * -1;
        int prf = 0;
        for(auto price:prices) {
            buy = max(buy, price * -1);
            prf = max(prf, price+buy);
        }
        return prf;
    }
};

void main_lc0121() {
    lc0121 solu;
    vector<int> prices {7,1,5,3,6,4};
    cout << solu.maxProfit(prices);
}


/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 */
#include <unordered_set>
struct lc0083 { // E
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *node = head;
        while(node!=nullptr && node->next!=nullptr){
            if(node->val == node->next->val) {
                ListNode *dup = node->next;
                node->next = node->next->next;
                delete dup;
            }
            else
                node = node->next;
        }
        return head;
    }

    ListNode* deleteDuplicates_slow(ListNode* head) {
        if(head==nullptr) return head;
    unordered_set<int> tbl;
    ListNode *nodeCur = head, *nodePre = nullptr;
        while(nodeCur!=nullptr){
            if(!tbl.count(nodeCur->val)) {
                tbl.insert(nodeCur->val);
                nodePre = nodeCur;
                nodeCur = nodeCur->next;
            }else{
                nodePre->next = nodeCur->next;
                delete nodeCur;
                nodeCur = nodePre->next;
            }
        }
        return head;
    }
};

void main_lc0083(void)
{
    lc0083 solu;
    ListNode* lst = new ListNode(1);
    addListNode(lst, 1);
    addListNode(lst, 1);
    //addListNode(lst, 2);
    //addListNode(lst, 3);
    //addListNode(lst, 3);
    printListNode(lst);
    auto ans = solu.deleteDuplicates(lst);
    printListNode(ans);
}

/*
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

struct lc0027 { // E
    int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
        if (!n) return n;

    int ptr_slow = 0, ptr_fast = 0;
        while (ptr_fast < nums.size()) {
            if (nums[ptr_fast] == val)
                n--;
            else
                nums[ptr_slow++] = nums[ptr_fast];
            ptr_fast++;
        }
    return n;
    }
};

void main_lc0027(void)
{
    lc0027 solu;
    vector<int> nums {0,1,2,2,3,0,4,2};
    int val = 2;
    auto ans = solu.removeElement(nums, val);
    cout << ans << endl;
    for(auto num:nums) cout << num << ' ';
}

/*
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */
#include <vector>
struct lc0026 { // E
    int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
        if (!n) return n;

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
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */
struct lc0021 {
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1||!l2) return l1 ? l1:l2;
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

void main_lc0021(void)
{
    lc0021 solu;
    ListNode* lst1 = new ListNode(1);
    addListNode(lst1, 2);
    addListNode(lst1, 4);
    printListNode(lst1);

    ListNode* lst2 = new ListNode(1);
    addListNode(lst2, 3);
    addListNode(lst2, 4);
    printListNode(lst2);

    auto ans = solu.mergeTwoLists(lst1, lst2);
    printListNode(ans);
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