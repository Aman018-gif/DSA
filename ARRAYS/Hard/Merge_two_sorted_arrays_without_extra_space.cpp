// Merge two sorted arrays without extra space
// Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.
//  = n-1;Merge both the arrays into a single array sorted in non-decreasing order.
// The final sorted array should be stored inside the array nums1 and it should be done in-place.
// nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s.
// nums2 has a length of n.
// 1.Brute Force normal Appraoch We use to do it but it require 3rd array.
// 2. Optimal Appraoch 1 -
// Keep one pointer at last element of 1st Array and 2nd at the very first of 2nd array comapre if in !st array number is bigger swap and as soon as the codition becomes false stop and now sort both the array.
// TC - O(min(n,m)) + O(nlogn) + O(mlogm) (Worst Case + Sort 1st Array + Sort Array 2)
// Sc - O(1)
int left =n-1;
int right = 0;
while(left>=0 && right<m){
    if(arr1[left]>arr2[right]){
        swap(arr1[left],arr2[right]);
        left--;
        right++;
    }
    else{
        break;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}
// 3. Optimal Appraoch 2
// Called GAP Method ( from Shell Sort)
// GAP is the ceil of sum of size of both the array.
// Here we keep left on 1st element of the !st array and right from the GAP Distance Away and check and Swap and after the iteration we reduced the gap by ceil of gap/2 repeat until gap >0 or when gap ==1 stop as it's then always stays at 1.
// TC - O(log2(n+m))+O(n+m) (First for the outer while loop log2 because GAP/2 and the 2nd one is for inner while loop)
// SC - O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int length = (n+m);
        int gap = length/2 + length%2;
        while(gap>0){
        int left = 0;
        int right = left+gap;
            while(right<length){
                if(left<n && right >=n){
                    //arr1 and arr2
                    if(nums1[left]>nums2[right-n]){
                        swap(nums1[left],nums2[right-n]);
                    }
                }
                else if(left>=n){
                    // arr 2 and arr2
                    if(nums2[left-n]>nums2[right-n]){
                        swap(nums2[left-n],nums2[right-n]);
                    }
                }
                else{
                    // arr 1 and arr1
                    if(nums1[left]>nums1[right]){
                        swap(nums1[left],nums1[right]);
                    }
                }
                left++;
                right++;
            }
            if(gap==1) break;
            gap = gap/2 + gap%2;
        }
        //question is till here 
        // this we are doing as we ned to add elements of nums2 in num1 at last to return the answer.
       for(int i=0;i<=m-1;i++){
        nums1[n+i]=nums2[i];
       } 
    }
};