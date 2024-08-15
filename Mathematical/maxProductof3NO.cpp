class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // The maximum product of three numbers can be either:
        //  The product of the three largest numbers
        // or The product of the two smallest numbers (both could be negative) and the largest number
        return max(nums[n-1] * nums[n-2] * nums[n-3], nums[0] * nums[1] * nums[n-1]);
    }
};