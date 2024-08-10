class Solution
{

    vector<int> nextSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            // nextsmaller ele ka index push
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    // prev Smaller
    vector<int> prevSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            //   // previoussmaller ele ka index push
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next = nextSmaller(heights, n);
        vector<int> prev = prevSmaller(heights, n);
        //  IMP -> next ele index cann't be -ve
        for (int i = 0; i < next.size(); i++)
        {
            if (next[i] == -1)
            {
                next[i] = next.size();
            }
        }

        int maxArea = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int length = heights[i];
            int width = next[i] - prev[i] - 1;
            int currArea = length * width;
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {

        vector<vector<int>> v;
        int r = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < r; i++)
        {
            vector<int> t;
            for (int j = 0; j < col; j++)
            {
                // convert char to integer value
                t.push_back(matrix[i][j] - '0');
            }
            // push 1d into each row
            v.push_back(t);
        }
        int area = largestRectangleArea(v[0]);
        for (int i = 1; i < r; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                //    curr row update
                if (v[i][j])
                {
                    v[i][j] += v[i - 1][j];
                }
                else
                {
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};