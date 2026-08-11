class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int len = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]+1) break;
            sum += nums[i];
        }

        unordered_set<int> s(nums.begin(),nums.end());

        while(true){
            if(!s.count(sum)) return sum;
            sum++;
        }

        return -1;
    }
};