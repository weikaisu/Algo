
#include <iostream>
#include <vector>

using namespace std;

struct _my_sort {
    vector<int> _nums {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    void show_nums(vector<int> nums) {
        for (auto num:nums)
            cout << num << ", ";
    }

    /*
     * 其觀念是將資料分成"已排序"和"未排序"兩個部分，並且依照順序從"未排序"中尋找最大(最小)值，加入到"已排序"資料的最後端。
     * 一直執行到排序結束也就是"未排序"資料為空的時候。
     * https://dotblogs.com.tw/ace_dream/2016/01/04/selectionsort
     */
    void select_sort(vector<int> &nums) {
        auto begin=nums.begin(), end=nums.end();
        for(auto &num:nums) {
            auto sub_min=min_element(begin++, end);
            swap(num, *sub_min);
            if(begin==end) break;
        }
    }

    void insertion_sort(vector<int> &nums) {
        auto begin = nums.begin(), end = nums.begin();
        bool first = true;
        for(auto num:nums ) {
            if(first) { first=false; continue; }
            auto pos = upper_bound(begin, end++, num);
            move(pos,end,pos+1);
            *pos=num;
        }
    }
};

void main_my_sort(void)
{
    _my_sort my_sort;
    vector<int> nums(my_sort._nums);
    //my_sort.select_sort(nums);
    my_sort.insertion_sort(nums);
    my_sort.show_nums(nums);
}