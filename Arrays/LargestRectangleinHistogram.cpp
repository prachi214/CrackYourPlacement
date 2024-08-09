class Solution
{
public:
    vector<int> nextSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        // ACCORDING TO  Question definition when ele is not found then return -1 that's by -1 se initialize
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
};