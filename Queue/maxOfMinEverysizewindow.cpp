class Solution
{
public:
    // Function to find the maximum of minimums for every window size
    vector<int> maxOfMin(int arr[], int n)
    {
        // Arrays to store indices of the previous and next smaller elements
        vector<int> left(n), right(n);

        //  array to store the maximum of minimums for every window size
        // Initialize it with 0, till n+1 bcoz last index is n-1, which is n
        vector<int> ans(n+1, 0);

        // Previous Smaller Element
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {

            while (!dq.empty() && arr[dq.back()] >= arr[i])
                dq.pop_back();
            
            // If deque is empty, it means there's no smaller element to the left, so store -1
            // Otherwise, store the index of the previous smaller element
            left[i] = dq.empty() ? -1 : dq.back();

            // Push the current index into the deque
            dq.push_back(i);
        }

        // Clear the deque for  reuse
        dq.clear();

        //  Next Smaller Element
        for (int i = n - 1; i >= 0; i--)
        {

            while (!dq.empty() && arr[dq.back()] >= arr[i])
                dq.pop_back();
            
            // If deque is empty, it means there's no smaller element to the right, so store n (out of bounds)
            // Otherwise, store the index of the next smaller element
            right[i] = dq.empty() ? n : dq.back();

            // Push the current index into the deque
            dq.push_back(i);
        }

        // ans array with the maximum of minimums for each window size
        for (int i = 0; i < n; i++)
        {
            //length of the window where arr[i] is the minimum
            int len = right[i] - left[i] - 1;

            // For this window size,  maximum of minimums
            ans[len] = max(ans[len], arr[i]);
        }

        // remaining parts
        // Ensure that for each smaller window size, the value is at least as large as the value for the next larger window size
        for (int i = n - 1; i >= 1; i--)
            ans[i] = max(ans[i], ans[i + 1]);

        // Remove the first element (window size 0)
        ans.erase(ans.begin());

        return ans;
    }
};