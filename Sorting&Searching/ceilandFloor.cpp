// finding ceil and floor in a arr

class Solution {
public:
    int findFloor(vector<int>& arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                ans = arr[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findCeil(vector<int>& arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = arr[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> getFloorAndCeil(int x, vector<int>& arr) {
        int n = arr.size();
           sort(arr.begin(), arr.end());
        int f = findFloor(arr, n, x);
        int c = findCeil(arr, n, x);
        vector<int> ans;
        ans.push_back(f);
        ans.push_back(c);
        return ans;
    }
};