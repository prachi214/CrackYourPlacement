class Solution {
  public:
  
 bool checkSorted(vector<int>& arr, int size, int index) {
    //  base case
    if(index>=size) return true;
    // processing
    if(arr[index]>=arr[index-1]){
        // call recursion
       return checkSorted(arr,size,index+1);
      
    }
    else{
        // not sorted arr
        return false;
    }
 }
    bool arraySortedOrNot(vector<int>& arr) {
   int size = arr.size();
   int index = 1;
   bool isSorted = checkSorted(arr, size, index);
   return isSorted;
    }
};