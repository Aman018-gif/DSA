// Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.
// 1.Brute Force Approach
// Simple 2 loop for every number from 1 to N check if it appears onces or not 
// TC - O(N^2) 
// SC - O(1)
// 2.Better Approach
// Hashing Approach 
// Declare the Hash Array of size max element in the array + 1
// TC - O(3N) (One for finding the maximum element, one for pre computing the freqency of the elements in the hash array and last one for checking which have frequency one (in this loop can be run either max number of time or total array size time whic will be lesser time running loop depends on input)) 
// SC - O(N) (As using Hash Array)
// 3.Optimal Approach
// a). Using Sum Approach 
// Using XOR Approach
// TC - O(N)
// SC - O(1)
class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int XOR=0;
        for(int i=0;i<=nums.size()-1;i++){
            XOR ^= nums[i];
        }
        return XOR;
    }
};