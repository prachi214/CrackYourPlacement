//Longest Repeating Character Replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxlen = 0, maxfq = 0;
           vector<int>hash(26, 0);
        while (r < s.size()) {
            // stores frequency of char of str
            hash[s[r] - 'A']++;
            // for getting longest substr length
               maxfq = max(maxfq, hash[s[r] - 'A']);
            //    not valid segment
            if ((r - l + 1) - maxfq > k) {
                // shrink down window
                hash[s[l] - 'A']--;
                l++;
            }
            // when (r - l + 1) - maxfq<= k), valid segment
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};