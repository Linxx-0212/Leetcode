class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int d[n+1][m+1] = {};
        if (n*m == 0) {
            return n+m;
        }
        for(int i = 0; i < n+1;i++) {
            d[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            d[0][j] = j;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j++) {
                int left = d[i-1][j] + 1;
                int down = d[i][j-1] + 1;
                int left_down = d[i-1][j-1];
                if (word1[i-1] != word2[j-1]) {
                    left_down += 1;
                }
                d[i][j] = min(left,min(down,left_down));
            }
        }
        return d[n][m];
    }
};