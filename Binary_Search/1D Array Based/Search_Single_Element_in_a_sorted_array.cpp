// Search Single Element in a sorted array
// Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.
// The array is sorted, and all elements except one appear exactly twice. If we observe carefully, every pair starts at even index and ends at odd index when the array is still balanced (i.e., before the unique element is encountered).

// But once the unique element is inserted, this pairing pattern breaks and the shift happens after that unique element. So we can use this pattern to cut the search space in half using binary search:
// If the pairing is proper (i.e., arr[mid] == arr[mid ^ 1]), then the unique (non-duplicate) element lies in the right half.
// If the pairing breaks (i.e., arr[mid] != arr[mid ^ 1]), then the unique element lies in the left half.
// This leads us to an O(log n) solution by binary eliminating half of the array every step.
// Check if the array has only one element, return that element.
// Check if the first element is not equal to the second return the first.
// Check if the last element is not equal to the second last return the last.
// Set two pointers: low = 1, high = n - 2 (excluding boundary elements).
// Run a loop while low ≤ high:
// Find mid = (low + high) / 2.
// If arr[mid] ≠ arr[mid - 1] and arr[mid] ≠ arr[mid + 1], return arr[mid].
// Check if mid is part of a correct pair:
// If mid is even and arr[mid] == arr[mid + 1], or
// If mid is odd and arr[mid] == arr[mid - 1],
// Then the unique element lies to the right, so move low = mid + 1.
// Otherwise, move high = mid - 1.
// If no unique element is found (theoretically unreachable), return -1.
// Time Complexity: O(logN), N = size of the given array ,as we are basically using the Binary Search algorithm.
// Space Complexity: O(1) as we are not using any extra space.
// Yani Apn ne phele edge cases alag se if se handle kar liye aur search space 1 se n-2  ke bich se start kia aur ab bas algo lgaya jisme agar mid ko check kia ki voh single hai kya nhi toh phir apn ne dekha ki voh middle double form me 2 baar jo arrah ahi voh (odd , even) index se hai toh apn ne bola yeh mid abhi right half me hai single element ke aur apn ko left me search krna chiaye aur vice a versa agar (even , odd) me hai toh.
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            if (nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } 
            else { // nums[mid] == nums[mid + 1]
                if (mid % 2 == 0) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};