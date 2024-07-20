class Solution {
public:
    bool isValid(string s) {
        // store brackets as key and value in map
    unordered_map<char, char> bracketMap = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    
    stack<char> stk;

    for (char c : s) {
        if (bracketMap.find(c) != bracketMap.end()) {
            // If the stack is not empty and the top of the stack matches the corresponding key value 
            if (!stk.empty() && stk.top() == bracketMap[c]) {
                // Pop the matched opening bracket from the stack
                stk.pop(); 
            } else {
// If curr char ki value(in map) and top of stack char is not matched
                return false; 
            }
        } else {
            // If the character is an opening bracket, push it onto the stack
            stk.push(c);
        }
    }

    // If the stack is empty, means Valid Parentheses
    return stk.empty();

    }
};