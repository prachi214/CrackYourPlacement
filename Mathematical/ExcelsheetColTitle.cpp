class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber){
            columnNumber--;
            res+= (char)('A'+ columnNumber%26);
            columnNumber/=26;
        }
        // reverse
        reverse(res.begin(), res.end());
        return res;
    }
};