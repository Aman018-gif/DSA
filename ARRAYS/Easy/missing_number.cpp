// Find missing number
// Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.
// 1.Brute Force Approach
// Simple 2 loop for every number from 1 to N check if exists or not 
// TC - O(N^2) (Worst Case (Hypothetical)) 
// SC - O(1)
// 2.Better Approach
// Hashing Approach 
// TC - O(2N) (One for SToring and another for checking which have frequency zero) 
// SC - O(N) (As using Hash Array)
// 3.Optimal Approach
// a). Using Sum Approach 
// Sum = ((N(N+1))/2)
// Iterate the array and calulate the sum of array and store in S2
// missing_value = Sum - S2;
// TC - O(N)
// SC - O(1)
// b). Using XOR Approach
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR1 =0;
        int XOR2 =0;
        for(int i =0;i<=nums.size()-1;i++){
            XOR2 ^= nums[i];
            XOR1 ^= (i+1);
        }
        int missingNumber = XOR1 ^ XOR2;
        return missingNumber;
    }
};


// Note: In 2 Optimal Approach i.e. Sum and XOR Approach which is Better?
// Lets take N = 10^5
// Sum = ((10^5(10^5+1))/2) = Approach 10^10 which cannot be stored in int (overflow) need to store in long hence will take a slightly more space while storing.
// XOR value cannot exceed the largest values i.e. if N = 10^5 then XOR cannot be greater than 10^5;
// Hence XOR Approach is better than Sum Approach.