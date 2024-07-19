

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
   bool ifPossibleSol(int A[], int N, int M,int mid){
       
       int i = 0, c= 1, pageSum = 0;
       
       for(i=0;i<N;i++){
          
              //   if book pages > min no. of pages
    
    if(A[i] >mid){
        
        return false;
        
    }
    
    if(A[i] + pageSum > mid){
        
        // kitni books allote ki uska count
        
        c++;
        
        // min no of pages ki book allote ho chuki h , ab next student ko book do
        
        pageSum = 0;
        pageSum+= A[i];
        
        // when book has given more then total no. of students
        
        if(c>M){
            return false;
        }
        
    }
        
        // continue book do students ko ans add pages
        
        else{
            pageSum+= A[i];
        }
        
       }
        return true;
       

   
   }
    
    int findPages(int A[], int N, int M) 
    {
     
    //  when total students our greater from total no. of books
    
     if(M>N){
         return -1;
     }
     
    //  apply BS
    
    // Create search space
     
     int start  = 0;
     int end = accumulate(A,A+N,0);
     int ans = -1;
     int mid = (start + end)>>1;
     
     while(start<=end){
         
       if(ifPossibleSol(A,N,M,mid)){
           
        //   store min ans
        ans = mid;
        // move left
        end = mid - 1;
       }
       
       else{
           
           start = mid + 1;
       }
       
          mid = (start + end)>>1;
     }
     
     return ans;
    }
};