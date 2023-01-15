class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) 
    {
      vector<vector<int>> matrix(n + 2, vector<int>(n + 2, 0));
        vector<vector<int>> row(n + 2, vector<int>(n + 2, 0));
        vector<vector<int>> col(n + 2, vector<int>(n + 2, 0));
        for (auto i : q) {
            int a = i[0];
            int b = i[1];
            int c = i[2];
            int d = i[3];
            row[a][b]++;
            row[c + 1][b]--;
            col[a][d + 1]--;
            col[c + 1][d + 1]++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                row[j][i] += row[j - 1][i];
                col[j][i] += col[j - 1][i];
            }
        }
        for (int i = 0; i < n; i++) {
            matrix[i][0] = row[i][0] + col[i][0];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[j][i] += matrix[j][i - 1] + row[j][i] + col[j][i];
            }
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) res[i][j] = matrix[i][j];
        return res;
    }
};