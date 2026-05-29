// Union of two sorted arrays
// Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.
// The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.
// Brute Force 
// using set
// TC O(n1logn1 + n2logn2 + n1 + n2) ---- (size of first set n1 logn1 for inserting into set similarly for n2logn2 and n1 + n2 for putting from set to uniion array for worst case both have all unquie elements)
// SC O(n1+n2) + O(n1+n2) first for solving using set and 2nd for returing the answer
// Optimal
// 2 Pointer Approach
// TC O(n1+n2) for travesing every element of both arrya onces
// SC O(n1+n2) + O(n1+n2) first for solving using set and 2nd for returing the answer
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2= nums2.size();
        int i =0;
        int j=0;
        vector<int>unionArr;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                if(unionArr.empty() || unionArr.back() != nums1[i]){
                    unionArr.push_back(nums1[i]);
                }
                i++;
            }
            else if(nums1[i]>nums2[j]){
                if(unionArr.empty() || unionArr.back() != nums2[j]){
                    unionArr.push_back(nums2[j]);
                }
                j++;
            }
        }
        while(i<n1){
            if(unionArr.empty() || unionArr.back() != nums1[i])
            {
            unionArr.push_back(nums1[i]);
            }
            i++;
        }
        while(j<n2){
            if(unionArr.empty() || unionArr.back() != nums2[j])
            {
            unionArr.push_back(nums2[j]);
            }
            j++;
        }
    return unionArr;
    }
};