class Solution {
private:

struct Node{
    int pre = 0;
    int suf = 0;
    int maxLen = 0;
    char leftChar = '0';
    char rightChar = '0';
};

vector<Node> segTree;

Node merge(Node& L,Node& R, int leftLen, int rightLen){
    Node res;

    res.leftChar = L.leftChar;
    res.rightChar = R.rightChar;
    res.pre = L.pre;
    res.suf = R.suf;

    if(L.pre == leftLen && L.rightChar == R.leftChar){
        res.pre = L.pre + R.pre;
    }

    if(R.suf == rightLen && R.leftChar == L.rightChar){
        res.suf = L.suf + R.suf;
    }

    res.maxLen = max(L.maxLen, R.maxLen);

    if(L.rightChar == R.leftChar){
        res.maxLen = max(res.maxLen, L.suf + R.pre);
    }

    return res;
}

void buildSegTree(int i, int left, int right, string& s){
    if(left == right){
        segTree[i] = {1, 1, 1, s[left], s[right]};
        return;
    }

    int mid = left + (right - left) / 2;
    buildSegTree(2 * i + 1, left, mid, s);
    buildSegTree(2 * i + 2, mid + 1, right, s);

    segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - left + 1 , right - mid);
}

void updateSegTree(int i, int left, int right, int pos, char ch){
    if(left == right){
        segTree[i] = {1, 1, 1, ch, ch};
        return;
    }

    int mid = left + (right - left) / 2;

    if(pos <= mid) updateSegTree(2 * i + 1, left, mid, pos, ch);
    else updateSegTree(2 * i + 2, mid + 1, right, pos, ch);

    segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - left  + 1 , right - mid);
}
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        segTree.assign(4 * n, Node());

        buildSegTree(0, 0, n-1, s);

        int k = queryCharacters.size();
        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            updateSegTree(0, 0, n-1, pos, ch);

            ans[i] = segTree[0].maxLen;
        }

        return ans;
    }
};