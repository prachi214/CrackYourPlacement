class Solution {
public:

    void findProduct(vector<long long int>& nums, vector<long long int>& result, int n, int current_index, long long int& left_product, long long int& right_product) {
        
        // base case
        
        if (current_index >= n) {
            return;
        }

// process part

        result[current_index] *= left_product;
        result[n - current_index - 1] *= right_product;

        left_product *= nums[current_index];
        right_product *= nums[n - current_index - 1];

// recursive call

        findProduct(nums, result, n, current_index + 1, left_product, right_product);
    }


    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> result(n, 1);
        
        // Initialize left and right pointer
        long long int left_product = 1;
        long long int right_product = 1;

        findProduct(nums, result, n, 0, left_product, right_product);

        return result;
    }
};