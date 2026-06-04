// Find out how many times the array is rotated
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.
// Algorithm
// Think of the rotated sorted array as two sorted halves the rotation “break” point is where the smallest element lives. Using binary search, we can efficiently zoom in on this smallest element by comparing middle elements to the rightmost element. If the middle element is greater than the rightmost element, the rotation point is to the right. Otherwise, it's to the left or could be the middle itself. This way, we reduce the search space by half each time, getting the rotation count in O(log n).
// Imagine searching for the break in a long sorted belt by cutting it in halves repeatedly instead of scanning all the way through.
// Initialize low = 0 and high = n - 1.
// While low is less than high:
// Find mid index.
// If the element at mid is greater than the element at high, the rotation point is after mid, so update low = mid + 1.
// Else, the rotation point is at mid or before it, so update high = mid.
// When low meets high, that index is the rotation count (index of smallest element).
// Simple Line me Bolu last question me jaise min nikala tha vohi code chalega bas min ka index return kario vohi answer hota hai.
// Time Complexity: O(log n),The binary search halves the search space each iteration, where n is the size of the array.
// Space Complexity: O(1),Only a few variables are used regardless of input size, so constant extra space.
class Solution {
public:
    int findKRotation(vector<int>& nums) {
        int low =0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        int min_index=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[low]<=nums[high]){
                if(ans>nums[low]){
                    ans = nums[low];
                    min_index=low;
                }
                break;
            }
            if(nums[low]<=nums[mid]){
                //left half sorted
                if(ans>nums[low]){
                    ans = nums[low];
                    min_index=low;
                }
                low = mid+1;
            }
            else{
                //right half sorted
                if(ans>nums[mid]){
                    ans = nums[mid];
                    min_index=mid;
                }
                high=mid-1;
            }
        }
        return min_index;
    }
};