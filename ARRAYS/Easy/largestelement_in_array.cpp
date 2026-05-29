// Largest Element
// brute force sort it and return nums[n-1]; TC O(NlogN)
//optimal solution in O(N) TC
class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largest= nums[0];
        for(int i=0;i<=nums.size()-1;i++){
            if(nums[i]>largest) largest = nums[i];
        }
        return largest;
    }
};