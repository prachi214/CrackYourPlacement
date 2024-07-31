class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string temp = "";
        int size = s.size();
        bool wordStarted = false;
        for (int i = size - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                temp += s[i];
                wordStarted = true;
            } else {
                if (wordStarted) {
                    reverse(temp.begin(), temp.end());
                    if (!result.empty()) {
                        result += " ";
                    }
                    result += temp;
                    temp = "";
                    wordStarted = false;
                }
            }
        }
        if (wordStarted) {
            reverse(temp.begin(), temp.end());
            if (!result.empty()) {
                result += " ";
            }
            result += temp;
        }
        return result;
    }
};