class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long mindiff = INT_MAX;
        // Use two pointers
        int i = 0, j = m - 1;
        // sliding window
        while (j < n)
        {
            long long diff = a[j] - a[i];
            mindiff = min(mindiff, diff);
            // expand window
            i++;
            j++;
        }
        return mindiff;
    }
};