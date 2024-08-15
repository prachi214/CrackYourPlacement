class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // make all eles equal to mid ele
       int midele = nums[nums.size()/2];
    //    this variable stores total count of operations
       int operations = 0;
       for(auto num: nums){
        operations+= abs(midele - num);
       }
       return operations;
    }
};