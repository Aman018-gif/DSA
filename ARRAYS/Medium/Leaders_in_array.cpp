// Leaders in an Array
// Given an integer array nums, return a list of all the leaders in the array.
// A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.
// 1.Brute Force Approach
// Check for Each elemnets whether all elements whther all to it's right are smaller or not?
// TC - O(N^2)
// SC - O(1)
// 2.Optimal Approach
// Idea: If an Element is greater than the largest element present to it's right then it is a leader in the array.
// TC - O(N)
// SC - O(1)
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      vector<int>ans;
      int maxi = INT_MIN;
      int n = nums.size();
      for(int i =n-1;i>=0;i--){
        if(nums[i]>maxi){
            ans.push_back(nums[i]);
        }
        maxi=max(maxi,nums[i]);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};