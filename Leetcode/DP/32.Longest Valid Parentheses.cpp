class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(),0);
        int maxx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i-1>=0) {
                if (s[i] == ')') {
                    if (s[i-1] =='(') {
                        if(i-2>0) {
                            dp[i] += dp[i-2];
                        }
                        dp[i] += 2;
                    }
                    else {
                        if(i-dp[i-1]-1 >=0) {
                            if (s[i-dp[i-1] - 1] =='(') {
                                if(i-dp[i-1]-2>0) {
                                    dp[i] += dp[i-dp[i-1]-2];
                                }
                                dp[i] +=dp[i-1]+2;
                            }
                        }
                    }
                }
            }
            if (dp[i] > maxx)
                maxx = dp[i];
        }
        return maxx;
    }
};