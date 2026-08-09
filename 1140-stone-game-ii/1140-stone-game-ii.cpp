class Solution {
private:
    int dp[101][2][202];
    int rec(int idx,int M,bool turn, vector<int>& nums){
        if(idx == nums.size()) return 0;
        int n = nums.size();
        int ans;

        if(dp[idx][turn][M] != -1) return dp[idx][turn][M];
        if(turn){
            ans = INT_MIN;
            int nextScore = 0;
            for(int x = 1; idx+x <= n && x<=(2*M); x++){
                nextScore += nums[idx+x-1];
                ans = max(ans,nextScore + rec(idx+x,max(x,M),false,nums));
            }
        }
        else{
            ans = INT_MAX;
            for(int x = 1; x <= 2*M && idx+x <= n; x++){
                ans = min(ans,rec(idx+x,max(x,M),true,nums));
            }
        }

        return dp[idx][turn][M] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,1,true,piles);
    }
};