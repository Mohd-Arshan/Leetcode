class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> square;
        for(int k=1; k*k<=1e5; k++){
            square.push_back(k*k);
        }
        vector<vector<int>> dp(n+1,vector<int>(2));
        dp[0][0] = false;
        dp[0][1] = true;

        bool turn = true;
        for(int i=1; i<=n; i++){

            dp[i][0] = false;
            for(int it:square){
                if(i - it < 0) break;
                dp[i][0] = (dp[i][0] || dp[i-it][1]);
            }

            dp[i][1] = true;
            for(int it:square){
                if(i-it < 0) break;
                dp[i][1] = (dp[i][1] && dp[i-it][0]);
            }
        }

        return dp[n][0];
    }
};