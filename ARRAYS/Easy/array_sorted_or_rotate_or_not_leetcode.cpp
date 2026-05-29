// Check if Array Is Sorted and Rotated
// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        k = nums.size()-k;
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
    }
    bool sorted(vector<int>& nums){
        for(int i=1;i<=nums.size()-1;i++){
            if(nums[i]<nums[i-1]) return false;
        }
        return true;
    }
    bool check(vector<int>& nums) {
      if(sorted(nums)) return true;
      for(int i = 0; i<=nums.size()-1;i++){
        rotate(nums,1);
        if(sorted(nums)) return true;
      }
      return false;
    }
};
