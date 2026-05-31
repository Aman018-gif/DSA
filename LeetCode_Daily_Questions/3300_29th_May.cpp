// 3300. Minimum Element After Replacement With Digit Sum
// You are given an integer array nums.

// You replace each element in nums with the sum of its digits.

// Return the minimum element in nums after all replacements.

class Solution {
public:
    int numberdigitsum(int n){
        int sum =0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        for(int i=0;i<=nums.size()-1;i++){
            nums[i]=numberdigitsum(nums[i]);
        }
        return *min_element(nums.begin(),nums.end());
    }
};