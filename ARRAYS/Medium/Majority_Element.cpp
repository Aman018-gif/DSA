// Majority Element
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// 1.Brute Force Approach
// Pick up an elements one by one and check count its occurence and then check whther it's occurs more than N/2 times or not?
// TC - O(N^2) 
// SC - O(1)
// 2.Better Approach
// Hashing Approach 
// TC - O(NlogN) + O(N) (One for Storing and another for checking the majority elements after iterating the map) 
// SC - O(N) (As using Hash Array)
// 3.Optimal Approach
// Moore's Voting Algorithm
// Idea: Pick up an element if it occur count++ if any other count-- if count==0 then in that part it can be majority element.
// So pick the first element do the idea discussed above and as soon as the count becomes 0 satring doing for the next element in the array if at you found the elemenbt then if the majority elements exists in the array it can be that otherwise no therefore first apply this then iterate the array and check that the element is majority element or not by iterating in the array.
// TC - O(N)
// SC - O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int cnt =0;
      int majorityElem = nums[0];
      for(int i=0;i<=nums.size()-1;i++){
        if(nums[i]==majorityElem) cnt++;
        else cnt--;
        if(!cnt){
            majorityElem = nums[i+1];
            cnt =0;
        }
      } 
    // this is final checking but since in the question it is given that The array is guaranteed to have a majority element. so not needed
    //   int final_check_cnt=0; 
    //   for(int i=0;i<=nums.size()-1;i++){
    //     if(nums[i]==majorityElem) final_check_cnt++;
    //   }
    // if(final_check_cnt>nums.size()/2) return majorityElem;
    // else return -1;
      return majorityElem;
    }
};