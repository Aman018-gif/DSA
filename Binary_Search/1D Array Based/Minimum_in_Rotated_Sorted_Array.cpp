// Minimum in Rotated Sorted Array
// Problem Statement:
// Given an integer array arr of size N, sorted in ascending order (with distinct values), the array is rotated at any index which is unknown. Find the minimum element in the array.
// Optimal Approach
// Algorithm
// In a rotated sorted array, the smallest element represents the point of rotation. It is the only element that is smaller than its previous element. Since the array is sorted in two segments, we can use binary search to efficiently find this pivot point. By comparing the middle element with the rightmost element in the current search space, we can determine which half of the array contains the minimum element.
// Initialize pointers to the start and end of the array.
// While start is less than end, calculate the middle index.
// If the middle element is greater than the rightmost element, move the start to mid + 1.
// Else, move the end to mid (because mid can be the minimum).
// When the loop ends, start will point to the minimum element.
// Simple sorted half dekho jo sorted half mile usme se min nikal agar left half sorted hai toh uska min nums[low] kykui sorted hai similary agar right half sorted hai toh nums[mid] kyuki vhi sorted hai.
// Bas Yehi Karna Hai Tereko Smja!!
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[low]<=nums[high]){
                ans = min(ans,nums[low]);
                break;
            }
            if(nums[low]<=nums[mid]){
                //left half sorted
                ans = min(ans,nums[low]);
                low = mid+1;
            }
            else{
                //right half sorted
                ans = min(ans, nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};