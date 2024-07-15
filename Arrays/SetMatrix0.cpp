
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1;
        // row size
        int n = matrix.size();
        // col size
        int m = matrix[0].size();

        // step 1: // marking part

        // we are using for colunm hash arr = matrix[0][variable]
        // We are using for ROW hash arr = matrix[VARIABLE][0]
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // mark i-th row:
                    matrix[i][0] = 0;

                    // mark j-th column:
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        // Step 2: Mark with 0 from (1,1) to (n-1, m-1), // after marking iterate without 0th row and col,  bcs  if we  start to convert 1  as 0 for marked values it can impact entire matrix result that's way we leave this row and col now
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    // check for col & row:
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // step 3: Finally mark the 1st col & then 1st row:

        // for 0th row
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }
        // for 0th col
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};