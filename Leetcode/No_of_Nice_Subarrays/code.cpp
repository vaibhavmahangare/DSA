// Given an array of integers nums and an integer k. 
// A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.


// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int subarrOddCount = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % 2 == 1) {
                    subarrOddCount++;
                }
                if (subarrOddCount == k) {
                    count++;
                }
                // If the number of odd elements exceeds k, we don't need to continue further
                if (subarrOddCount > k) {
                    break;
                }
            }
        }
        
        return count;
    }
};
