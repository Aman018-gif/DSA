// Left Rotate Array by One
// Given an integer array nums, rotate the array to the left by one.
// Note: There is no need to return anything, just modify the given array.
// TC O(N) & SC O(1) 
class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int temp = nums[0];
        for(int i=1;i<=nums.size()-1;i++){
            nums[i-1]=nums[i];
        }
        nums[nums.size()-1]=temp;

    }
};