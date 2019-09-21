class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        long long res = 1;
        int j = 1;
        for(int i=n+1;i<=m+n;i++) {
            res *= i;
            while(j<=m && res%j==0)
                res/=j,j++;
        }
        return res;
    }
};