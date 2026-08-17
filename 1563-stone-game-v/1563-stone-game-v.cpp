class Solution {
    int dp[501][501];
private:
    int rec(int low, int high,vector<int>& pre){
        if(low >= high) return 0;

        int maxScore = 0;
        int currScore = 0;

        if(dp[low][high] != -1) return dp[low][high];

        for(int i=low; i<high; i++){
            int left = pre[i+1] - pre[low];
            int right = pre[high] - pre[i+1];

            if(left > right) currScore = right + rec(i+1, high, pre);
            else if(right > left) currScore = left + rec(low,i+1, pre);
            else currScore = left + max(
                    rec(low, i+1, pre),
                    rec(i+1, high, pre)
                );

            maxScore = max(maxScore, currScore);
        }

        return dp[low][high] = maxScore;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pre(n+1);
        pre[0] = 0;

        for(int i=0; i<n; i++){
            pre[i+1] = pre[i] + stoneValue[i];
        }    

        memset(dp,-1,sizeof(dp));
        return rec(0,n,pre);
    }
};