class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int freq[3] = {0,0,0};

        for(int ele:stones){
            freq[ele % 3]++;
        }

        if(freq[0] % 2 == 0) return min(freq[1],freq[2]) >= 1;

        return abs(freq[1] - freq[2]) >= 3;
    }
};