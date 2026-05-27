#include<bits/stdc++.h>
class Solution {
public:
    int fun(vector<int>& nums,int low,int high){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i<j){
            while(i <=high-1 && pivot>=nums[i]) i++;
            while(j>=low+1 && pivot<nums[j])j--;
            if(i<j) swap(nums[i],nums[j]);
        }
        swap(nums[low],nums[j]);
        return j;
    }

    void qs(vector<int>& nums,int low,int high){
         if(low<high){
            int partition_index = fun(nums,low,high);
            qs(nums,low,partition_index-1);
            qs(nums,partition_index+1,high);
         }
    }

    vector<int> quickSort(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
        return nums;
    }
};
