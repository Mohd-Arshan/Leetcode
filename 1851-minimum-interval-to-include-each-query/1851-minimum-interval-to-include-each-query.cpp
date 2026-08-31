class Solution {
    typedef pair<int,int> pii;
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int q = queries.size();

        ranges::sort(intervals);

        vector<pii> map;
        for(int i = 0; i<q; i++) map.push_back({queries[i],i});

        priority_queue<pii,vector<pii>,greater<pii>>heap;

        ranges::sort(map);
        vector<int> ans(q,-1);

        int i = 0;

        for(auto [x,idx] :map){
            
            while(i<n && intervals[i][0] <= x){
                int l = intervals[i][0];
                int r = intervals[i][1];
                int range = (r-l+1);
                heap.push({range,r});
                i++;
            }

            while(!heap.empty() && x > heap.top().second){
                heap.pop();
            }

            if(!heap.empty()){
                ans[idx] = heap.top().first;
            }
        }

        return ans;
    }
};