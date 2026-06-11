// Find the Smallest Divisor Given a Threshold
// Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.
// Brute Force-Algorithm
// We will run a loop from 1 to max element of the array to check all possible divisors.
// To calculate the result, we will iterate over the given array using a loop. Within this loop, we will divide each element in the array by the current divisor, and sum up the obtained ceiling values.
// Inside the outer loop, If result <= threshold: We will return d as our answer.
// Finally, if we are outside the nested loops, we will return -1.
// Time Complexity: O(max(arr[])*N), where max(arr[]) = maximum element in the array, N = size of the array. We are using nested loops. The outer loop runs from 1 to max(arr[]) and the inner loop runs for N times.
// Space Complexity: O(1). No extra space used.
// Optimal Approach
// Algorithm
// Intuition
// We are going to use the Binary Search algorithm to optimize the approach.
// Space Complexity: O(1). No extra space used
// Optimal Approach-Approach
// First, check if the number of elements is already greater than the allowed limit. If so, no answer is possible, so return -1.
// Then, identify the largest number in the list.
// Start with two markers , one at the smallest possible number (1), and another at the largest number in the list.
// Use a loop to narrow down the range. In each step, find the number that is in the middle of the current range.
// Check if using this middle number as a divisor results in a total that is within the allowed limit. This is done using a helper that adds up the rounded-up results of each division.
// If the result is within the allowed limit, it means this number might work, but a smaller one could be better. So, look in the lower half of the current range.
// If the result is too large, it means this number is too small. So, look in the upper half of the range instead.
// Repeat this process until the range closes. The smallest number that works will be pointed to by the left marker, and that's the answer.
class Solution {
public:
    bool check(vector<int>& nums, int threshold,int divisor){
        int sum =0;
        for(int i=0;i<=nums.size()-1;i++){
            sum+=ceil((double)nums[i]/divisor);
            if(sum>threshold) return false;
        }
        if(sum<=threshold) return true;
        return false;

    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(nums,threshold,mid)) high = mid-1;
            else low = mid +1;
        }
        return low;
    }
};
// note :  if (arr.size() > limit) return -1;
// Time Complexity:O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array. We are applying binary search on our answers that are in the range of [1, max(arr[])]. For every possible divisor ‘mid’, we call the sumByD() function. Inside that function, we are traversing the entire array, which results in O(N).
// Space Complexity: O(1), no extra space is used.