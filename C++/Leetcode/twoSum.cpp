#include<vector>
#include<iostream>
#include<algorithm>


class Solution {
    public:
    std::vector<int> twoSum(std::vector<int> &nums, int taget){
         std::vector<int> result;

         for(auto it = nums.begin(); it != nums.end(); ++it){
            auto it1 = std::find(it+1, nums.end(), taget - *it);
            if(it1 != nums.end()){
                result.push_back(it - nums.begin());
                result.push_back(it1 - nums.begin());
                break;
            }
         }
        return result;
    }
};