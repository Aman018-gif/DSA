// Sort an array of 0's 1's and 2's
// Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.
// The sorting must be done in-place, without making a copy of the original array.

// 1.Brute Force Approach
// Use any exisiting Sorting Algorithm (like Merge Sort)
// TC - O(Nlog(N)) 
// SC - O(N)
// 2.Better Approach
// Count Approach
// Kepp 3 Variables (cnt0,cnt1,cn2)
// Iterate through array and update them such that cnt0 contains number of 0 in the array and so on. 
// Then again run a loop or iterate the array and update starting cnt0 elements as 0, next cnt1 elements to 1 and last cnt2 elements to 2.
// TC - O(2N)
// SC - O(1)
// 3.Optimal Approach
// Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid =0;
        int high =nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }       
    }
};

// TC - O(N) (mid to high is the unsorted protion in either of the step this part is shrinking therefore we can say that at each step we are sorting exactly one element so at worst case if all the elements in the array in the array is unsorted then the TC would be O(N))
// SC - O(1)