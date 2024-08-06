class Solution
{
public:
    vector<int> findNse(vector<int> arr)
    {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            // only smaller
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPse(vector<int> arr)
    {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            // psee can be <= , avoiding duplicate  subarr
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        // for finding individual ele contribution in min sum for left subarr and right subarr

        // next smallest ele
        vector<int> nse = findNse(arr);
        // previous smaller equal ele
        vector<int> psee = findPse(arr);
        long long total = 0;
        long long mod = 1000000007;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {

            // substract indices

            // total subarr in left side where a[i] contributes in min sum
            int left = i - psee[i];
            // total subarr in right side where a[i] contributes in min sum
            int right = nse[i] - i;
            // total subarr with a[i] == arr[i] * left * right
            total = (total + (long long)arr[i] * left * right % mod) % mod;
        }
        return (int)total;
    }
};
