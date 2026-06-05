// Peak element in Array
// Problem Statement: Given an array of length N, peak element is defined as the element greater than both of its neighbors. Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i]. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.
// 1. Brute Force -  TC - O(N) SC- O(1)  Traverse the whole array and apply the required conditions.
// 2. Optimal Approach - Algorithm
// To optimize our solution even further, we can use binary search algorithm. The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
// To know how to eliminate the half efficiently, we can clearly notice a striking distinction between the left and right halves of the peak element in the array. The left half of the peak element has an increasing order whereas the right half of the peak element has a decreasing order. 
// Thus we know that if current element is greater than its left neighbour, we are in the left half and if our current element is greater than its right neighbour then we are in the right half. If we know the half that we are in currently, we can eliminate it to find our peak element.
// In addition to the two cases above, we can have two more cases. One, where the current element itself is the peak or where the current element is a common point where a decreasing sequence ends and an increasing sequence begins. In either cases we can eliminate any of the halves, as the other half will also contain a peak element.
// Initialize the search space to the full range of the array.
// Find the middle index of the current search range.
// Check if the middle element is greater than its right neighbor.
// If yes, then a peak must exist in the left half (including mid), so shrink the right bound.
// Otherwise, the peak must lie in the right half (excluding mid), so shift the left bound.
// Continue until the search space converges to a single element.
// This final position is the index of a peak element.
// Time Complexity: O(log N), we reduce the search space to half at every step using binary search.
// Space Complexity: O(1), constant additional space is used.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low =1;
        int high = n-2;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid]>nums[mid-1]){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return -1;
    }
};