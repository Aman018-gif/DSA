// Remove duplicates from sorted array
// Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once.
// Return the number of unique elements in the array.
// Brute force suing set and then placing it back in array 
// TC O(NlogN +N) NlogN ofr scaning the array N and then insert in set using insert function in logN then another N for putiing back in array 
// SC using a set O(N)

// Optimal here using 2 Pointer apporach 
// TC O(N) and SC O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=0;j<=nums.size()-1;j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};