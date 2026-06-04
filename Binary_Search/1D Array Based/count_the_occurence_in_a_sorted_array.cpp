Count Occurrences in a Sorted Array
You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.
Return the count of occurrences of target in the array.
// same last question me jaise First aur Last Occurence nikali thi bas vohi nikalan ahia 
// Count = Last - First + 1;
class Solution {
public:
    int countOccurrences(vector<int>& nums, int target) {
        auto check = lower_bound(nums.begin(),nums.end(),target);
        if(check == nums.end()|| *check !=target) return -1;
        int lowerbound = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int upperbound = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        upperbound--;
        int count = upperbound-lowerbound+1;
        return count;;

    }
};


