// Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// It has 2 variation 
// A).In this you have given an Array and target value you only have to tell by adding 2 elemets can you hit the target or not bool function either Yes or No?.
// B).In this you have given an Array and target value you only have to tell by the index of the elements by which the desired sum is obtained it is guranteed that the sum is possible.
// 1.Brute Force Approach
// Pick up an element and check it with all the other element whether the sum is obtained or not from it repeat it for all the element.
// TC - O(N^2)
// This can be optimized by starting the 2nd loop from i+1 not from stating why to check fot the elements pair already checked.
// 2.Better Approach
// Hashing Approach 
// TC - O(2logN) (For ordered map) 
// SC - O(N) (As using Hash Array)
// Also note this is optimal for 2nd variation
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        for(int i=0;i<=nums.size()-1;i++){
            int check = target - nums[i];
            if(mpp.find(check) != mpp.end()) return {i,mpp[check]};
            mpp[nums[i]]=i;
        }
        return {};
    }
};
// 3.Optimal Approach
// Only for variation 1
// Using Greedy and 2 Pointer Approach
// First Sort the array keep a left pointer onto the first element and the right pointer at the last element calculate the sum if the sum is less than the target we want more sum hence move left pointer to right if more than target then we want less hence move right pointer to the left. Once you get the result return true else false.
// TC - O(N) + O(NLogN) (Sorting)
// SC - O(1) (if considering destoring of array then O(N))
bool twosum(vector<int>& nums,int target){
    int left=0;
    int right = nums.size()-1;
    sort(nums.begin(),nums,end());
    while(left<right){
        if(nums[left]+nums[right]<target){
            left++;
        }
        else if(nums[left]+nums[right]>target){
            right--;
        }
        return true;
    }
    return false;
}
 