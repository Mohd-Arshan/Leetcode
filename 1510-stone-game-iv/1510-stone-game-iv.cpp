class Solution {
private:
    int dp[100001][2];
    bool rec(int n,bool turn, vector<int>& square){
        if(n==0) return !turn;

        if(dp[n][turn] != -1) return dp[n][turn];
        bool ans;
        if(turn){
            ans = false;
            for(int it:square){
                if(it>n) break;

                ans = ans || rec(n-it,false,square);
            }
        }
        else{
            ans = true;

            for(int it:square){
                if(it>n) break;

                ans = ans && rec(n-it,true,square);
            }
        }

        return dp[n][turn] = ans;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int> square;
        for(int k=1; k*k<=1e5; k++){
            square.push_back(k*k);
        }

        memset(dp,-1,sizeof(dp));
        return rec(n,true,square);
    }
};