// find 1st occurance starting index for given string

class Solution{
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
          int m = needle.size();

// needle str ko as haystack str m as sliding window compare kiya
          for (int i = 0; i<=(n-m); i++)
          {
          for (int j= 0; j<m; j++)
          {
            // 1st character match ni hua for needle str
         if (needle[j]!=haystack[i+j])
         {
          break;
         }
                 //   match
        if(j == m-1){
            return 1;
        }
         
          }

          
          }
        //   when needle str exist hi ni krta 1st str m
          return -1;
          
    }
};