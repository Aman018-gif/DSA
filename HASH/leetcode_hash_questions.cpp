class Solution {
public:
	int validate(int i,int k,vector<int>&nums,vector<long>&prefix) {
		int target =nums[i];
		int left=0;
		int right =i;
		int best=i;
		while(left<=right) {
			int mid = (left+right)/2;
			long count = i - mid +1;
			long sumfinal = count * target;
			int sumorg = prefix[i]-prefix[mid]+nums[mid];
			int operationsrequired = sumfinal - sumorg;
			if(operationsrequired > k) {
				left =mid+1;
			}
			else {
				best = mid;
				right =mid -1;
			}

		}
		return i-best+1;
	}


	int maxFrequency(vector<int>& nums, int k) {
		sort(nums.begin(),nums.end());
		vector<long>prefix;
		prefix.push_back(nums[0]);
		for(int i=1; i<nums.size(); i++) {
			prefix.push_back(nums[i]+prefix.back());
		}
		int output=0;
		for(int i=0; i<nums.size(); i++) {
			output = max(output,validate(i,k,nums,prefix));
		}
		return output;
	}
};


// 1838. Frequency of the Most Frequent Element

// The frequency of an element is the number of times it occurs in an array.

// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

// Return the maximum possible frequency of an element after performing at most k operations.

 

// Example 1:

// Input: nums = [1,2,4], k = 5
// Output: 3
// Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
// 4 has a frequency of 3.