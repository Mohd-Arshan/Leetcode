class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // solution combine and sorting O((m+n)log(m+n))
        // merging part of merge sort O(m+n)
        // O(log(m+n))???

        int m = nums1.size();
        int n = nums2.size();

        if(m>n) return findMedianSortedArrays(nums2,nums1);

        int half = (m+n+1)/2;

        int low = 0;
        int high = m;

        while(low<=high){
            int i = low + (high - low)/2;
            int j = half - i;

            int aLeft = (i==0)?INT_MIN:nums1[i-1];
            int aRight = (i==m)?INT_MAX:nums1[i];
            int bLeft = (j==0)?INT_MIN:nums2[j-1];
            int bRight = (j==n)?INT_MAX:nums2[j];

            if(aLeft <= bRight && bLeft <= aRight){
                if((m+n)%2 != 0) return max(aLeft, bLeft);
                else return ((double)max(aLeft,bLeft) + min(aRight,bRight)) / 2.0;
            }
            else if(aLeft>bRight) high = i -1;
            else low = i + 1;
        }

        return 0.0;

    }
};