class Solution {
public:
    void moveZeroes(vector<int>& nums) {
          int size  = nums.size();
     int left = 0, right = size - 1, index  =0;
     while(index<=right){
        
        // if 0 occurs 
        if(nums[index] == 0){
            index++;
        }
        
        // if non zero eles exists 
               else if(nums[index] != 0){
                   swap(nums[index], nums[left]);
                   left++;
            index++;
        }
        
     }   
    }
};