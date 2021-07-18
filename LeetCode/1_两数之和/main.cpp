#include <iostream>
#include <vector>
#include <map>
#include "utilbase.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i = 0; i < nums.size()-1; i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if( nums.at(i)+nums.at(j) == target )
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    vector<int> ret;


    // 测试1
    nums.clear();
    ret.clear();
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    UtilBase::showVector("输入", nums);
    ret = sol.twoSum(nums,9);
    UtilBase::showVector("输出", ret);

    // 测试2
    nums.clear();
    ret.clear();
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    UtilBase::showVector("输入", nums);
    ret = sol.twoSum(nums,6);
    UtilBase::showVector("输出", ret);

    // 测试3
    nums.clear();
    ret.clear();
    nums.push_back(3);
    nums.push_back(3);
    UtilBase::showVector("输入", nums);
    ret = sol.twoSum(nums,6);
    UtilBase::showVector("输出", ret);

    return 0;
}
