class Solution {
public:

int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        // using 2 pointer
        int top = 0, down = n - 1;

        while (top < down) {
            // does the top know down
            if (mat[top][down] == 1) {
                // top is not celebrity
                top += 1;
            } else {
                // down is not the celebrity
                down -= 1;
            }
        }

        // top == down now, check if this person is a celebrity
        int candidate = top;

        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // A celebrity knows no one, and everyone knows the celebrity
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                    return -1;
                }
            }
        }
        return candidate;
    }
};