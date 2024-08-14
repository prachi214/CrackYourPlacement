class Solution
{
public:
    // Directions array to move in the 8 possible directions (up, down, left, right, and 4 diagonals)
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    int countLiveNeighbors(vector<vector<int>> &board, int row, int col, int m, int n)
    {
        int liveNeighbors = 0;
        for (auto dir : directions)
        {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            // Check boundaries
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n)
            {
                // Check if the neighbor is live
                if (board[newRow][newCol] == 1)
                {
                    liveNeighbors++;
                }
            }
        }
        return liveNeighbors;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> newBoard = board;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int liveNeighbors = countLiveNeighbors(board, i, j, m, n);

                // given rules of the Game of Life
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
                {
                    // Cell dies
                    newBoard[i][j] = 0;
                }
                if (board[i][j] == 0 && liveNeighbors == 3)
                {
                    // Cell becomes live
                    newBoard[i][j] = 1;
                }
            }
        }

        // Update the original board to the new state
        board = newBoard;
    }
};