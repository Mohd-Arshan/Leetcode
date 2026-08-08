class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> suffix(m,0);
        int c = 0;
        int j = n-1;

        for(int i=m-1; i>=0; i--){
            suffix[i] = c;

            if(j >= 0 && word1[i] == word2[j]){
                c++;
                j--;
            }
        }

        vector<int> ans;
        j = 0;
        bool flag = false;
        for(int i = 0; i<m && j<n; i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!flag && suffix[i] >= n-1-j){
                ans.push_back(i);
                j++;
                flag = true;
            }

            if(j == n) return ans;
        }

        return {};

    }
};