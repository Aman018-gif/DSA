class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans = nums[0];
        int freq = mpp[ans];
        for(auto it:mpp){
            if(it.second>freq){
                freq = it.second;
                ans = it.first;
            }
            else if(it.second==freq){
                if(ans>it.first){
                ans = it.first;
                }
            }
        }
        return ans;
    }
};



// Highest Occurring Element in an Array
// Given an array nums of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them.
// Example 1
// Input: nums = [1, 2, 2, 3, 3, 3]
// Output: 3
// Explanation: The number 3 appears the most (3 times). It is the most frequent element.