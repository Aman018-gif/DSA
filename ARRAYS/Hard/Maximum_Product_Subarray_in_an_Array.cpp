// Maximum Product Subarray in an Array
// Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.
// 1.Brute and Better - By Generating all the Sub Arrays.
// In the brute force method, we generate all possible subarrays and calculate the product of each subarray. We track the maximum product found among all. Use two nested loops, the outer loop picks the starting index of the subarray and the inner loop picks the ending index. For every subarray defined by start and end, calculate the product and update the maximum product if the current subarray's product is larger.
// Brute Force - Time Complexity: O(N^3), we check the product of all possible subarrays using three nested loops.
// Space Complexity: O(1), No extra space is used.
// Better Force - Time Complexity: O(N^2), we check the product of all possible subarrays using two nested loops.
// Space Complexity: O(1), No extra space is used.
 int maxProduct(vector<int>& nums) {
        // Initialize the answer with the first element
        int maxProd = nums[0];

        // Outer loop picks the starting index
        for (int i = 0; i < nums.size(); i++) {
            // Initialize current product to 1
            int prod = 1;

            // Inner loop picks the ending index
            for (int j = i; j < nums.size(); j++) {
                // Multiply current number to product
                prod *= nums[j];

                // Update maximum product if needed
                maxProd = max(maxProd, prod);
            }
        }

        // Return the result
        return maxProd;
    }
};
// 2.Optimal Approach
// The product of elements in a subarray can become large when there are positive numbers, but negative numbers and zeros make it tricky. A negative number can flip a large product into a negative one, but if we meet another negative later, the sign flips back to positive. Therefore, to capture all possible max products, we do two things:
// Traverse the array from left to right (prefix) to build cumulative product.
// Traverse the array from right to left (suffix) to catch subarrays ending at the back (helpful when max product is at the end or due to even negatives).
// Reset the product to 1 whenever a zero is found, as it breaks the subarray continuity.
// By comparing products in both directions at each step, we ensure we don’t miss any possible maximum.
// Time Complexity: O(N), every element of array is visited once.
// Space Complexity: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi= INT_MIN;
        int prefix=1;
        int suffix=1;
        for(int i=0;i<=nums.size()-1;i++){
            if(prefix==0) prefix =1;
            if(suffix==0) suffix =1;
            prefix*=nums[i];
            suffix*=nums[nums.size()-i-1];
            maxi = max(maxi,max(prefix,suffix));
        }
        return maxi;
    }
};