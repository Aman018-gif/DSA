// Maxiumum SubArray (Kadane's Algorithm)
// Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.
// 1.Brute Force Approach
// Try out all sub Arrays Possible and get it's sum.
// Simple 3 loop generate all the possible subarray and calculate sum return maxium sum. 
// TC - O(N^3)
// SC - O(1)
// 2.Better Approach
// The Brute Force Approach can be optimized to TC O(N^2) by removing the inner most loop as the sum caluation in every iteration sum prev plus the next elemets so why to iterate whole array again.
// TC - O(N^2)
// SC - O(1)
// 3.Optimal Approach
// Kadane's Algorithm
// Traverse the array maintaining a running sum: if it drops below zero, reset the sum to zero and mark the next index as your new start. Whenever the current sum exceeds your overall max, update max and record the subarray boundaries by setting answer_start = start and answer_end = current_index
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum =0;
        for(int i=0;i<=nums.size()-1;i++){
            sum+=nums[i];
            maxi = max(maxi,sum);
            if(sum<0) sum =0;
        }
        return maxi;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum =0;
        int start =0;
        int ans_start=-1;
        int ans_end=-1;
        for(int i=0;i<=nums.size()-1;i++){
            if(sum==0) start =i;
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
                ans_start=start;
                ans_end=i;
            }
            if(sum<0) sum =0;
        }
        return maxi;
    }
};