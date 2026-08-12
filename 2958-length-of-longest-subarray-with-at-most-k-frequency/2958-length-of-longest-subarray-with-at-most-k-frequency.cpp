class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int j = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            freq[nums[i]]++;

            while(j<n && freq[nums[i]] > k){
                freq[nums[j]]--;
                j++;
            }

            ans = max(ans,i-j+1);

        }

        return ans;
    }
};