class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        for(int i = nums.size()-1;i>=1;i--){
            bool swap_check=true;
            for(int j=0;j<=i-1;j++){
                if(nums[j]>nums[j+1]){
                    int c;
                    swap_check=false;
                    c= nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=c;
                }
            }
            if(swap_check) return nums;
        }
        return nums;     
    }
};
