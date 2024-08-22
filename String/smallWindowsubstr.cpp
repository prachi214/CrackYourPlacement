class Solution {
public:
    string smallestWindow(string s, string p) {
        // map
        vector<int> hash(256, 0);
        int l = 0, r = 0, minLen = INT_MAX;
        int sIndex = -1;
        int n = s.size();
        int m = p.size();
        int cnt = 0;

     
        for (int i = 0; i < m; i++) {
            // preinsert occurance of chars
            hash[p[i]]++;
        }

// traverse str
        while (r < n) {
            // when occurance  is +ve
            if (hash[s[r]] > 0) {
                // p str char in s str
                cnt++;
            }
            hash[s[r]]--;
            r++;

// it can be a possible ans
            while (cnt == m) {
                if (r - l < minLen) {
                    minLen = r - l;
                    sIndex = l;
                }
                hash[s[l]]++;
                // reinserted into map
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }

        return sIndex == -1 ? "-1" : s.substr(sIndex, minLen);
    }
};


