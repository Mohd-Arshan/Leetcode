class Solution {
    int dp[365];
    int rec(int idx,vector<int>& days,vector<int>& costs){
        if(idx == days.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int next = idx;
        while(next<days.size() && days[next] < days[idx] + 1) next++;
        int case1 = costs[0] + rec(idx+1, days, costs);
        
        next = idx;
        while(next<days.size() && days[next] < days[idx] + 7) next++;
        int case2 = costs[1] + rec(next, days, costs);

        next = idx;
        while(next<days.size() && days[next] < days[idx] + 30) next++;
        int case3 = costs[2] + rec(next, days, costs);

        return dp[idx] = min({case1,case2,case3});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return rec(0,days,costs);
    }
};