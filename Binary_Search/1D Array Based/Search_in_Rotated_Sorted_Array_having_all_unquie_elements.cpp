// Search Element in a Rotated Sorted Array
// Problem Statement: Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is rotated at some pivot point that is unknown. Find the index at which k is present and if k is not present return -1.
// In a rotated sorted array, the entire array is no longer fully sorted ,but an important property still holds: in every part of the array you look at, one side will always be sorted. This means either the left portion or the right portion of the array will be in increasing order. That’s the key idea we use to find the target efficiently.
// Why Binary Search Still Works:
// In normal binary search, we rely on the entire array being sorted to decide whether to go left or right. But in this case, we adapt it slightly we don't require the whole array to be sorted, just identify which part is sorted in the current range. Once we know which part is sorted, we check if the target lies inside that sorted section. If it does, we discard the other half. If not, we discard the sorted half and search the remaining half. No matter how the array was rotated, the sorted structure on at least one side of any middle point always helps us narrow down where to look next. This lets us avoid scanning the whole array like in brute force, and instead bring down the number of checks to logarithmic time.
// Start by looking at the middle element of the array.
// Check if this middle element is the target if yes, return its index immediately.
// Now figure out which half of the array (left side or right side) is sorted.
// If the left part is sorted:
// Check if the target number falls within the range of that sorted part.
// If it does, discard the right half and continue the search in the left part.
// If it doesn’t, discard the left half and search in the right side.
// If the right part is sorted:
// Do the same check if the target is in that sorted part.
// If yes, discard the left side and search in the right.
// If not, discard the right and continue with the left.
// Repeat this process of eliminating half the array until the target is found or the search space is empty.
// Time Complexity: O(log N),We eliminate half of the search space in each iteration using binary search.
// Space Complexity: O(1),We use only a few variables (low, high, mid) no extra space used.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size()-1;
        while(low<=high){
            int mid= low + (high - low)/2;
            if(nums[mid]==target) return mid;
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
        return -1;
    }
};