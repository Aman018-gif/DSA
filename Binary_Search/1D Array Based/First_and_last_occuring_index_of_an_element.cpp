// Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto check = lower_bound(nums.begin(),nums.end(),target);
        if(check == nums.end()|| *check !=target) return {-1,-1};
        int lowerbound = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int upperbound = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {lowerbound,upperbound-1};
    }
};

//direct implement without using lower and upper bound 
// find last index of key using binary search
int solve(int n, int key, vector<int>& v) {
  // initialize search bounds and result
  int start = 0;
  int end = n - 1;
  int res = -1;

  // binary search loop
  while (start <= end) {
    // compute mid safely
    int mid = start + (end - start) / 2;
    // when match found, store index and move right
    if (v[mid] == key) {
      res = mid;
      start = mid + 1;
    }
    // when key is smaller, move left
    else if (key < v[mid]) {
      end = mid - 1;
    }
    // otherwise move right
    else {
      start = mid + 1;
    }
  }
  // return last occurrence or -1
  return res;
}