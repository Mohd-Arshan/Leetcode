class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xo = 0;
        bool hasNoZero = false;

        for(int x:nums){
            xo ^= x;

            if(x != 0) hasNoZero = true;
        }

        if(xo != 0) return n;
        if(hasNoZero) return n-1;
        return 0;
    }
};