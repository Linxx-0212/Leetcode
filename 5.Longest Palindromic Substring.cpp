class Solution {
public:
   string longestPalindrome(string s) {
        int max = 0;
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            for(int l = i, h = i, t = 1; t <= 2; t++) {
                if(s[l] == s[h]) {
                    while(l-1 >= 0 && h+1 < s.length() && s[l-1] == s[h+1]) {l--;h++;}
                    if(h-l+1 > max) {
                        max = h-l+1;
                        res = s.substr(l, max);
                    }
                }
                l = i;
                h = i+1;
            }
        }
        return res;
    }
};