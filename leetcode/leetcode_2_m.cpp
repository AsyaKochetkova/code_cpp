/*Given an integer array nums, return an array answer such that answer[i] is equal 
to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.*/
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int general_l = 1, general_r = 1;
        std::vector<int> left(nums.size(),1);
        std::vector<int> right(nums.size(),1);
        std::vector<int> answer(nums.size(),1);
        for(int i=0; i<nums.size();i++){
            left[i] = general_l;
            general_l *= nums[i];       

            right[nums.size()-i-1] = general_r;
            general_r *= nums[nums.size()-i-1];
        }

        for(int i=0; i<nums.size();i++){
            answer[i]= left[i]*right[i];
        }
        return answer;
    }
};

int main(){

    std::vector<int> nums{-1,1,0,-3,3};
    std::vector<int> res;
    Solution smth;
    res = smth.productExceptSelf(nums);
    for(int i=0; i<nums.size(); i++){
        std::cout << res[i] << " ";
    }
    return 0;
}