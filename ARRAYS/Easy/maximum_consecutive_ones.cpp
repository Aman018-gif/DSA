// Maximum Consecutive Ones
// Given a binary array nums, return the maximum number of consecutive 1s in the array.
// A binary array is an array that contains only 0s and 1s.
// Optimal Approach
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int max_one=0;
        for(int i=0;i<=nums.size()-1;i++){
            if(nums[i]==1)
                cnt++;
            else
                cnt=0;
            max_one=cnt>max_one?cnt:max_one;
        }
        return max_one;
    }
};