class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;  

        for (int i = 0; i < tokens.size(); i++) {
            // If the token is a number, push it onto the stack
            if (isdigit(tokens[i][0]) || (tokens[i].size() > 1 && isdigit(tokens[i][1]))) {
                s.push(stoi(tokens[i]));
            } else {
                // pop the last two numbers from the stack
                int val1 = s.top(); s.pop();
                int val2 = s.top(); s.pop();

           
                switch (tokens[i][0]) {
                    case '+':
                        s.push(val2 + val1);
                        break;
                    case '-':
                        s.push(val2 - val1);
                        break;
                    case '*':
                        s.push(val2 * val1);
                        break;
                    case '/':
                        s.push(val2 / val1);
                        break;
                }
            }
        }
        return s.top();  
    }
};
