class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int f[len],maxx;
        f[0] = nums[0];
        maxx = nums[0];
        for (int i = 1; i < len; i++) {
            f[i] = max(nums[i], f[i-1]+nums[i]);
            maxx = max(f[i],maxx);
        }
        return maxx;
    }
};