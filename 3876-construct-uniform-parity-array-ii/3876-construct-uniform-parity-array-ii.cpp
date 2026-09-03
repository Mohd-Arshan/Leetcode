class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        
        int n = nums.size();
        int st = *min_element(nums.begin(),nums.end());

        if(st%2 != 0) return true;
     
        for(int num:nums){
            if(num == st) continue;
            else if(num%2 !=0 ) return false;
        }

        return true;
    }
};