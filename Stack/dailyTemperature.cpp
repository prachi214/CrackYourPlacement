class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> s;

        for (int i = 0; i < n; ++i)
        {
           while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int index = s.top();
                s.pop();
                answer[index] = i - index; //  the number of days
            }
            s.push(i); // Push current index to the stack
        }
         return answer;
    }
};