class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int c = 0;
            int l = 0, h = nums.size() - 1;
            vector<int>brr;
            brr = nums;
   int x= 0,y=0;
            sort(brr.begin(), brr.end());
         
            while(l<h){
            int sum = brr[l] + brr[h];
                if(sum == target){
                    break;
                }
                else if(sum>target){
                    h--;
                }
                else{
                    l++;
                }
            }

            for(int i= 0;i<size;i++){

                if(nums[i] == brr[l] && c<1){
                    x = i;
                    c++;
                }
                else if(nums[i] == brr[h] ){
                    y = i;
                }
            }
            vector<int>ans;
            ans.push_back(x);
              ans.push_back(y);
return ans;

    }
};