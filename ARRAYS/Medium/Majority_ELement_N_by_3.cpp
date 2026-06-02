// Majority Element
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// 1.Brute Force Approach
// Pick up an elements one by one and check count its occurence and then check whther it's occurs more than N/2 times or not?
// But can be optimized like we know at max 2 element can be there maintain a list as soon as 2 found stop searching and also while checking if any element found >n/3 times add it there only do not wait for its enitre count.
// TC - O(N^2) 
// SC - O(1)
list =[]
for (int i = 0; i < nums.size(); i++) {
    if (list.size() == 0 || list[0] != nums[i]) {

        int cnt = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == nums[i]) {
                cnt++;
            }
        }

        if (cnt > (int)nums.size() / 3) {
            list.add(nums[i]);
        }

        if (list.size() == 2) {
            break;
        }
    }
}
// 2.Better Approach
// Hashing Approach 
// TC - O(NlogN) + O(N) (One for Storing and another for checking the majority elements after iterating the map) 
// SC - O(N) (As using Hash Array)
// 3.Optimal Approach
// Moore's Voting Algorithm
// Idea: Pick up an element if it occur count++ if any other count-- if count==0 then in that part it can be majority element.
// So pick the first element do the idea discussed above and as soon as the count becomes 0 satring doing for the next element in the array if at you found the elemenbt then if the majority elements exists in the array it can be that otherwise no therefore first apply this then iterate the array and check that the element is majority element or not by iterating in the array.
// This was for n/2 for 3 we simulate the exact same but tackle the edge cases 
// TC - O(2N)
// SC - O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;
        for(int i=0;i<=nums.size()-1;i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1 =1;
                el1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0;
        cnt2=0;
        vector<int>final_ans;
        int mini = (int)(nums.size()/3) +1;
        for(int i=0;i<=nums.size()-1;i++){
            if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
        }
        if(cnt1>=mini) final_ans.push_back(el1);
        if(cnt2>=mini) final_ans.push_back(el2);
        sort(final_ans.begin(),final_ans.end());
     return final_ans;
    }
};