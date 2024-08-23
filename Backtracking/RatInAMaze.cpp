class Solution {
public:

//a function that will handle all the below mentioned possibilities:
//posssiblity hai
	//-> path closed
	//out if bound 
	// check is pos is already visited
    bool isSafe(int newx, int newy, vector<vector<int>> &mat, int row, int col, vector<vector<bool>> &visited) {
   	if(
		(newx >=0 && newx <row) &&
		(newy >=0 && newy < col) &&
		mat[newx][newy] == 1 &&
		visited[newx][newy] == false
		) {
		return true;
		}
	else {
		return false;
	}
    }


    void findAllPaths(vector<vector<int>> &mat, int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited, vector<string> &paths) {
        // Base case

        //destination coordinates are [row-1], [col-1]
        if (srcx == row - 1 && srcy == col - 1) {
            	//reached destination
            paths.push_back(output);
            return;
        }

        // UP
        int newx = srcx - 1;
        int newy = srcy;
        if (isSafe(newx, newy, mat, row, col, visited)) {
            	//mark visited
            visited[newx][newy] = true;
            output.push_back('U');
            	//call recursion
            findAllPaths(mat, row, col, newx, newy, output, visited, paths);
            	//backtracking
            output.pop_back();  
            visited[newx][newy] = false;
        }

        // RIGHT
        newx = srcx;
        newy = srcy + 1;
        if (isSafe(newx, newy, mat, row, col, visited)) {
            	//mark visited
            visited[newx][newy] = true;
            output.push_back('R');
            	//call recursion
            findAllPaths(mat, row, col, newx, newy, output, visited, paths);
            	//backtracking
            output.pop_back();
            visited[newx][newy] = false;
        }

        // DOWN
        newx = srcx + 1;
        newy = srcy;
        if (isSafe(newx, newy, mat, row, col, visited)) {
            		//mark visited
            visited[newx][newy] = true;
            output.push_back('D');
            	//call recursion
            findAllPaths(mat, row, col, newx, newy, output, visited, paths);
            	//backtracking
            output.pop_back();
            visited[newx][newy] = false;
        }

        // LEFT
        newx = srcx;
        newy = srcy - 1;
        if (isSafe(newx, newy, mat, row, col, visited)) {
            	//mark visited
            visited[newx][newy] = true;
            output.push_back('L');
            	//call recursion
            findAllPaths(mat, row, col, newx, newy, output, visited, paths);
            	//backtracking
            output.pop_back();
            visited[newx][newy] = false;
        }
    }

    vector<string> findPath(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<string> paths;
        if (mat[0][0] == 0 || mat[row - 1][col - 1] == 0) {
			// If start or end is blocked, no paths
            return paths;  
        }

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        visited[0][0] = true;

        string output = "";
        findAllPaths(mat, row, col, 0, 0, output, visited, paths);

        return paths;
    }
};
