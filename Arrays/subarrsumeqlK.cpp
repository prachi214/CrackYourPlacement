class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        // Map to store the cumulative frequency of prefix sums
        std::unordered_map<long long, int> preSumMap;
        long long sum = 0;
        int count = 0;

        // Initialize the map with 0 sum having one count
        preSumMap[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            // Calculate the prefix sum till index i
            sum += nums[i];

            // If the (current sum - k) is found in the map, 
            // it means there exists a subarray whose sum is k
            if (preSumMap.find(sum - k) != preSumMap.end()) {
                count += preSumMap[sum - k];
            }

            // Update the map with the current sum
            preSumMap[sum]++;
        }

        return count;
    }
};