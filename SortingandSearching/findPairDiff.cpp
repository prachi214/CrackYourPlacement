class Solution {
public:
    bool bs(vector<int>& arr, int start, int target) {
        int end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                return true;
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }

    int findPair(int n, int x, std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            // Avoid counting duplicates
            if (i > 0 && arr[i] == arr[i - 1]) {
                continue;
            }
            if (bs(arr, i + 1, arr[i] + x) || bs(arr, i + 1, arr[i] - x)) {
                return 1;
            }
        }
        return -1;
    }
};

