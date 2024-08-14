class Solution {
public:

    void generateP(int openBrackets, int closeBrackets, int n, string current, vector<string>& ans) {
        // Base case: if open and close brackets both  == n
        if (openBrackets == n && closeBrackets == n) {
            ans.push_back(current);
            return;
        }
        
        // If the number of open brackets is less than `n`
        if (openBrackets < n) {
            generateP(openBrackets + 1, closeBrackets, n, current + "(", ans);
        }
        
        // If the number of close brackets is less than the number of open brackets
        if (closeBrackets < openBrackets) {
            generateP(openBrackets, closeBrackets + 1, n, current + ")", ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateP(0, 0, n, "", ans);
        return ans;
    }
};
