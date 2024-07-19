// logic is same like painter partition problem

class Solution {
public:
    bool ifPossibleSol(vector<int>& nums, int n, int k, long long mid) {
        int c = 1;
        long long timeSum = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > mid) {
                return false;
            }

            if(nums[i] + timeSum > mid) {
                c++;
                timeSum = nums[i];

                if(c > k) {
                    return false;
                }
            } else {
                timeSum += nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long start = 0;
        int n = nums.size();
        long long end = accumulate(nums.begin(), nums.end(), static_cast<long long>(0));

        long long mid = start + (end - start) / 2;
        long long ans = -1;

        while(start <= end) {
            if(ifPossibleSol(nums, n, k, mid)) {
                ans = mid;
                // we have to find the minimum time
                end = mid - 1;
            } else {
                start = mid + 1;
            }

            mid = start + (end - start) / 2;
        }
        return ans;
    }
};
