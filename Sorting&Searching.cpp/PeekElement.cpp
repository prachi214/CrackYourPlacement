class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int start = 0;
      int end = arr.size()-1;
      int mid = start+ (end-start)/2;
      int ans = 0;
      // if write start<=end then loop goes in infinite condition

      while(start<end){
        // hm peak element ke left m h

          if(arr[mid]<arr[mid+1]){
            //   right m jao
            start= mid+1;
          }
             // we are on eithier peek element index or right side of peek element
          else{
              ans= mid;
              // if I write here end = mid-1 so in this case my peek element will lose because in this condition I can also stand on peek element means my mid can be equal to peek element index
              end = mid;
          }
          mid = start+ (end-start)/2;
      }
      // returns Peek element 
      return arr[ans];

            // returns Peek element  index
    //   return ans;
    }
};