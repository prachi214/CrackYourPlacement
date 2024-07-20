// Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
    // Step 1: Initialize slow anf fast pointer
    int slow = nums[0];
    int fast = nums[0];
    
    // Step 2: Move slow i time and fast 2i times to find the intersection point
    do {
      slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Step 3: Find the  duplicate number in  cycle 
    fast = nums[0];
    while (slow != fast) {
     slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
    }
};