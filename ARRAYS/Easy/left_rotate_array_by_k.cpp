// Left Rotate Array by K Places
// Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.
// Brute force apporach is like done for one place do it store in another array
// TC O(N+d)
// SC O(N)
// optimal 
// TC O(2N)
// SC O(1)
class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());

    }
};