class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1;
        int f2 = 1;
        int f3 = 1;
        while (n > 1) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
            n--;
        }
        return f3;
    }
};