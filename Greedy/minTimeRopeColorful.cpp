class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int sum = 0;

        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i-1]) {
                // Add the minimum time between the current and previous balloon to the sum
                sum += min(neededTime[i], neededTime[i-1]);
                
                // Ensure the larger time remains for further comparisons
                if (neededTime[i] > neededTime[i-1]) {
                    neededTime[i-1] = neededTime[i];
                }
            }
        }

        return sum;
    }
};
