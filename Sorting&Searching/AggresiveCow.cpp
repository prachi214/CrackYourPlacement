

class Solution {
public:


bool ifPossible(vector<int>stalls,int n,int k, int mid){
    
    int c =1;
    int pos = stalls[0];
 
    
    for(int i =1;i<n;i++){
        
        int diff = stalls[i]  - pos;
        
        if(diff>=mid){
            c++;
    pos = stalls[i];
            
          if(c==(k))  {
               
             
               return true;
            }
        }
    }
    return false;
    
}

    int solve(int n, int k, vector<int> &stalls) {
    
    sort(stalls.begin(), stalls.end());
     int start = 0;

     int end = stalls[stalls.size()-1] - stalls[0];
     int mid = start + (end - start)/2;
     int ans = -1;
     
     while(start<=end){
         if(ifPossible(stalls,n,k,mid)){
       
             ans = mid;
             start = mid +1;
         }
         else{
             end = mid - 1;
         }
         mid = start + (end - start)/2;
     }
     return ans;
    }
};