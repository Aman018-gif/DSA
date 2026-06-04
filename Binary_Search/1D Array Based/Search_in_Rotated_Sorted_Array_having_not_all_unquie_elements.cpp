// Search Element in Rotated Sorted Array II
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.
// Intuition
// First, we identify the sorted half of the array.
// Once found, we determine if the target is located within this sorted half
// If not, we eliminate that half from further consideration.
// Conversely, if the target does exist in the sorted half, we eliminate the other half.
// We basically compare arr[mid] with arr[low] and arr[high] in the following way:
// If arr[low] <= arr[mid]: In this case, we identified that the left half is sorted.
// If arr[mid] <= arr[high]: In this case, we identified that the right half is sorted.
// Same as previous Questio just due to duplicated an edge case need to handle 
// where element at low mid high are same till this happen we need to trim the search space.
// Time Complexity: O(logN) for the best and average case. O(N/2) for the worst case. Here, N = size of the given array.
// Space Complexity: O(1), no extra space used
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size()-1;
        while(low<=high){
            int mid= low + (high - low)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low = low+1;
                high=high-1;
                continue;
            }
            //left sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target){
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //right sorted
            else{
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;
                }
                else{
                    high = mid -1;
                }
            }
        }
        return false;
    }
};