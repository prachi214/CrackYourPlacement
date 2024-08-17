class Solution {
public:
    string removeKdigits(string num, int k) {
          stack<char> st;
        int n = num.size();
        string res;

        for (int i = 0; i < n; i++) {
            // Remove greater elements from the stack
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // When given number with sorted digits
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if (st.empty()) return "0";

        // Collecting the stack into the result string
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        // Reverse the result string to get the correct order
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }

        // If the result is empty or all zeros
        if (start == res.size()) return "0";

        return res.substr(start);  // Return the final result
    
    }
};