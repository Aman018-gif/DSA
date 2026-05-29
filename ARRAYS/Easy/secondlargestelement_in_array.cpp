// Second Largest
// Brtue force 
// sort it and travese array from back way stop at that element as son as find different from nums[n-1];
// TC O(NlogN) in worst case  O(NlogN+N)

// better approach 
// find largest as in prev question in O(N) and then again run but check if slar is not equal to largest 
// TC is (2N)
//optimal one TC O(N)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
        int largest = nums[0];
        int secondLargest = -1;
        for(int i=0;i<=nums.size()-1;i++){
            if(nums[i]>largest){
                secondLargest = largest;
                largest = nums[i];
            }
            if(nums[i]<largest && nums[i]>secondLargest){
                secondLargest = nums[i];
            }
        }
        return secondLargest;
      
    }
};