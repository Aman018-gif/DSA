// Floor and Ceil in Sorted Array
// Problem Statement: ou're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x
// Algorithm
// Ceil
// We will declare the 2 pointers and an ‘ans’ variable initialized to -1(If we don’t find any index, we will return -1).
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
// Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
// Case 1 - If arr[mid] >= x: This condition means that the index arr[mid] may be an answer. So, we will update the ‘ans’ variable with arr[mid] and search in the left half if there is any smaller number that satisfies the same condition. Here, we are eliminating the right half.
// Case 2 - If arr[mid] < x: In this case, arr[mid] cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
// Floor
// We will declare the 2 pointers and an ‘ans’ variable initialized to -1(If we don’t find any index, we will return -1).
// Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
// Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
// Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
// Case 1 - If arr[mid] <= x: The index arr[mid] is a possible answer. So, we will store it and will try to find a larger number that satisfies the same condition. That is why we will remove the left half and try to find the number in the right half.
// Case 2 - If arr[mid] > x: arr[mid] is definitely not the answer and we need a smaller number. So, we will reduce the search space to the left half by removing the right half.
// DEkh Ceil toh Lower_boudn ke index wala element type bas floor ke liye vohi code thoda chnage karke likhna hai
// Time Complexity:O(logN), where N = size of the given array. We are using the Binary Search algorithm
// Space Complexity: O(1). No extra space used
class Solution{
public:
    int getCeil(vector<int> nums, int target) {
        int ans =-1;
        int low =0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                ans = nums[mid];
                high = mid-1;
                }
            else low = mid+1;
        }
        return ans;
    }

    int getFloor(vector<int> nums, int target) {
        int ans =-1;
        int low =0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<=target){
                ans = nums[mid];
                low = mid+1;
                }
            else
                high = mid-1;
        }
        return ans;
    }

    vector<int> getFloorAndCeil(vector<int> nums, int target) {
        return {getFloor(nums,target),getCeil(nums,target)};
    }
};