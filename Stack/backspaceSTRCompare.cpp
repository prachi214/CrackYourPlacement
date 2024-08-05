class Solution
{
public:
    string isStringEqual(string &str)
    {
        stack<char> st;
        for (auto ch : str)
        {
            if (ch == '#')
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(ch);
            }
        }

        string result;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        //  reverse
        reverse(result.begin(), result.end());
        return result;
    }

    bool backspaceCompare(string s, string t)
    {
        return isStringEqual(s) == isStringEqual(t);
    }
};