// Check if the Array is Sorted II
// Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.


class Solution{	
	public:
		bool isSorted(vector<int>& nums){
			//your code goes here
            for(int i=1;i<nums.size()-1;i++){
                if(nums[i]<nums[i-1]) return false;
            }
            return true;
		}
};