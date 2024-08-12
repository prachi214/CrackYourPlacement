    class Solution {
public:
    
    string removeDuplicates(string s, int k) {
        //two pointer
        int i = 0, j = 0;
        vector<int>count(s.size());
        while(j<s.size()){
// inplace
        s[i] = s[j];
        // for new char coun reset
        count[i] = 1;

        if(i>0 && s[i] == s[i-1])
        count[i] += count[i-1];

// remove ele
        if(count[i] == k)
        i-= k;

        i++,j++;
        }
        return s.substr(0,i);
    }
};