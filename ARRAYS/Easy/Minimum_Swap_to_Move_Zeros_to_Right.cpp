// Minimum Swaps to Move Zeros to End
// You are given an integer array nums.
// In one operation, you can choose any two distinct indices i and j and swap nums[i] and nums[j].
// Return an integer denoting the minimum number of operations required to move all 0s to the end of the array.

 class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int count_swap =0;
        int i=0;
        int j= nums.size()-1;
        while(j>i){
            if(nums[i]==0 && nums[j] !=0){
                swap(nums[i],nums[j]);
                count_swap++;
                i++;
                j--;
            }
            else if(nums[j]==0 && nums[i] !=0){
                i++;
                j--;
            }
            else if(nums[i]==0 && nums[j] ==0){
                j--;
            }
            else
                i++;
        }
        return count_swap;
    }
};