class Solution {
public:
    int calculate(string s) {
     stack<int> numbers;
    char currentOp = '+';
    int currentNumber = 0;
for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
if (isdigit(ch)) {
            currentNumber = currentNumber * 10 + (ch - '0');
        }
if ((!isdigit(ch) && ch != ' ' ) || i == s.length() - 1) {
            if (currentOp == '+') {
                numbers.push(currentNumber);
            } else if (currentOp == '-') {
                numbers.push(-currentNumber);
            } else if (currentOp == '*') {
                int top = numbers.top();
                numbers.pop();
                numbers.push(top * currentNumber);
            } else if (currentOp == '/') {
                int top = numbers.top();
                numbers.pop();
                numbers.push(top / currentNumber);
            }
            currentOp = ch;
            currentNumber = 0;
        }
    }
int result = 0;
    while (!numbers.empty()) {
        result += numbers.top();
        numbers.pop();
    }
return result;   
    }
};