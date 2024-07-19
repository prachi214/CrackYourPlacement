class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // store occurance of remainders
    unordered_map<int, int> remainderMap;
        int sum = 0;
        int count = 0;

        // Initialize the map with 0 remainder having one count
        remainderMap[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
         
            sum += nums[i];

            //  remainder 
            int remainder = ((sum % k) + k) % k;

            // If the remainder is found in the map, it means there exists a subarray
            // whose sum is divisible by k
            if (remainderMap.find(remainder) != remainderMap.end()) {
                count += remainderMap[remainder];
            }

            // key which is remainder amd their occurance as value
            remainderMap[remainder]++;
        }

        return count;
    }
};