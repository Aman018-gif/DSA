// 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// 1. Brute force 
// Generate all the triplets then check
TC - O(N^3) 
set <vector<int>>st;
for(int i =0;i<=n-1;i++){
    for(int k=i+1;j<-n-1;j++){
        for(int kj+1;k<=n-1;k++){
            if(arr[i]+arr[j]+arr[k]==0){
                vector<int>temp ={arr[i],arr[j],arr[k]};
                //for storing unquie
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
        }
    }
}
vector<vector<int>>ans(st.begin(),st.end());
return ans;
// 2.Better Approach
// Idea : Instead of 3rd loop 
// arr[k] = -(arr[i]+arr[j]); to find this in a hash map bt it can give same also so storing the rest
// TC - O(N^2*log(M))
// SC - O(N) + O(no of unqiue Triplets *2) (Worst Case)
set<vector<int>>st;
for(int i =0;i<=n-1;i++){
    set<int>hashset; //declaring here as want to empty after every iteration of i as for one fixed number as i done now new so new hash map
    for(int k=i+1;j<-n-1;j++){
        int third = -1*(arr[j]+arr[k]);
        if(hashset.find(third)1=hashset.end()){
            vector<int>temp = {arr[i],arr[j],arr[k]};
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        hashset.insert(num[j]);
    }}
// 3. Optimal Approach
// 1. Sort an Array 
// Then using 2 Pointer Approach
// For a Fixed i put j next to i and k at last calualte the sum if sum is less then 0 then we need more sum to move j and is more than 0 we need to reduced sum hence move k and if equals to 0 then store that triplet and move j and k until new found and also after one iteration move i to next if new element found next.
// TC - O(N*log(N)) + O(N^2) (one for sorting another one for 2 Loops)
// SC - O(no of unqiue triplets store) to return the answer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size()-1;i++){
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            while(k>j){
                if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) {
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};