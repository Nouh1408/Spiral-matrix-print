#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();

        int sr = 0, er = m - 1, sc = 0, ec = n - 1;
        int count = 0;

        while (sr <= er && sc <= ec) {
            for (int i = sc; i <= ec; i++) {
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            if (count == m * n) return ans;
            for (int i = sr; i <= er; i++) {
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            if (count == m * n) return ans;
            for (int i = ec; i >= sc; i--) {
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            if (count == m * n) return ans;

            for (int i = er; i >= sr; i--) {
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
            if (count == m * n) return ans;
        }
        return ans;
    }
};

int main() {
    int m, n;

    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;


    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the matrix elements row by row:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution solution;
    vector<int> result = solution.spiralOrder(matrix);


    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
