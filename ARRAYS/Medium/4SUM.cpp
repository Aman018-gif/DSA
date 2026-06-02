// 4Sum
// ck icon
// Companies
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.
// Note ; All Brute Better and Optimal in same patter as in 3SUM 
// 1. Brute Force 
// TC - O(N^4)
// 2.Better Approach
// TC - O(N^3*log(N))
// SC - O(N) + O(no of unquie Quards *2)
// 3. Optimal Approach 
// TC - O(N^3)
// SC -O(no of unquie Quards)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i=0;i<=n-1;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<=n-1;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l =n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                        while(k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};