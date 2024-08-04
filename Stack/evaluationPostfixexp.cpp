class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> s;
        for (int i = 0; i < S.size(); ++i)
        {
            // check char is digit or not
            if (isdigit(S[i]))
            // -0, bcoz convert  char digit to its integer ASCII value
                s.push(S[i] - '0');

// char is operator
            else
            {
                // 1st operand
                int val1 = s.top();
                s.pop();
                   // 2nd operand
                int val2 = s.top();
                s.pop();

                switch (S[i])
                {
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