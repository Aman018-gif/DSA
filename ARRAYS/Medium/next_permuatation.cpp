// Next Permutation
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integers.
// More formally, if all the permutations of the array are sorted in lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted order.
// If such arrangement is not possible (i.e., the array is the last permutation), then rearrange it to the lowest possible order (i.e., sorted in ascending order).
// You must rearrange the numbers in-place and use only constant extra memory.
// 1.Brute Force Approach
// Try out all Permutation Possible by recurssion and give next permuation from that.
// Simple 3 loop generate all the possible subarray and calculate sum return maxium sum. 
// TC - O(N!*N)
// SC - O(1)
// 2.Better Approach
// Using next_permutation from STL Library.
// 3.Optimal Approach
// 1.Longer Prefix Match to get the index i.
// 2.Find the least greatest element from that element at index i and swap them.
// 3. then the rest area we need min since sorted just reverse.
// TC - O(3N)
// SC - O(1) if considering the modification of array then O(N)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
    int n = nums.size();
        for(int i =n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index =i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
                return;
        }
        for(int i =n-1;i>index;i--){
            if(nums[i]>nums[index]){
            swap(nums[index],nums[i]);
            break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};