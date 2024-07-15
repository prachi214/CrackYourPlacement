class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string ans;
        while(true){
            char currtchar = 0;

            for(auto str: strs){

                if(i>=str.size()){
                    currtchar = 0;
                    break;
                }

                if(currtchar == 0){
                    currtchar = str[i];
                }

                else if(currtchar!=str[i]){
                    currtchar = 0;
                    break;
                }
            }

            if(currtchar == 0) break;

            ans.push_back(currtchar);
            i++;
        }
      return ans;  
    }

};