//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool viable(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &visited, int n) {
          return ((x >= 0) && (x < n) && (y >= 0) && (y < n) && (visited[x][y] == 0) && (matrix[x][y] == 1));
    }
    void solve(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> visited, int n, string path, vector<string> &result) {
        // base case
        if((x == n-1) && (y == n-1)) {
            result.push_back(path);
            path.clear();
            return;
        }
        
        visited[x][y] = 1;
        
        // down
        int xC = x+1;
        int yC = y;
        if(viable(xC, yC, matrix, visited, n)) {
            path.push_back('D');
            solve(xC, yC, matrix, visited, n, path, result);
            path.pop_back();
        }
        
        // up
        xC = x-1;
        yC = y;
        if(viable(xC, yC, matrix, visited, n)) {
            path.push_back('U');
            solve(xC, yC, matrix, visited, n, path, result);
            path.pop_back();
        }
        
        // left
        xC = x;
        yC = y-1;
        if(viable(xC, yC, matrix, visited, n)) {
            path.push_back('L');
            solve(xC, yC, matrix, visited, n, path, result);
            path.pop_back();
        }
        
        // right
        xC = x;
        yC = y+1;
        if(viable(xC, yC, matrix, visited, n)) {
            path.push_back('R');
            solve(xC, yC, matrix, visited, n, path, result);
            path.pop_back();
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        vector<string> result;
        
        if(matrix[0][0] == 0)
            return result;
            
        string path = "";
        
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        solve(0, 0, matrix, visited, n, path, result);
        
        return result;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends