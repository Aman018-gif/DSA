class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        for(int i=0;i<=nums.size()-1;i++){
            int j=i;
            while(j>0 && (nums[j-1]>nums[j])){
                int temp;
                temp = nums[j-1];
                nums[j-1]=nums[j];
                nums[j]=temp;
                j--;
            }
        }
        return nums;
    }
};
