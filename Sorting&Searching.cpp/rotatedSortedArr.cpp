class Solution {
public:

// find Pivot element index
int findPivotelement(vector<int>&nums){
    int s= 0 ;
    int n = nums.size();
    int e = n-1;
   int mid = s+ (e-s)/2;
   while(s<=e){
    if (s==e)
    {
       return s;
    }
    else if ((mid-1)>=0 && nums[mid]<nums[mid-1])
    {
       return mid-1;
    }

        else if ((mid+1)<n&& nums[mid]>nums[mid+1])
    {
       return mid;
    }
        else if (nums[s]<=nums[mid])
    {
      s = mid+1;
    }
    else
    {
        e = mid-1;
    }
  mid = s+ (e-s)/2;
   }
   return -1;
   
}
int findElement(vector<int>&nums, int s, int e, int target){
    int mid = s+ (e-s)/2;
    while (s<=e)
    {
        if (nums[mid] == target)
        {
          return mid;
        }
        else if (nums[mid]<target)
        {
          // right side jao;
            s = mid +1;
        }
        else
        {
           // left side jao
        e = mid - 1;
        }
        mid = s+ (e-s)/2;
    }
    return  -1;
    
}
    int search(vector<int>& nums, int target) {
        // ans will get pivotelementIndex
          int ans = findPivotelement(nums);
    int index = 0;
    int s = 0;
    int e = nums.size() - 1;
        //  when target is in A line
         if (nums[0]<=target && target<=nums[ans])
         {
            //  function call for finding target element index
          index =   findElement(nums,s,ans,target); 
         }
           //  when target is in B line
         else
         {
                //  function call for finding target element index
        index=  findElement(nums,ans+1,e,target);
         } 
        //  return target element index 
         return index;
    }
};