class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final;

        int ind1 = 0, ind2 = 0 , indF = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        
        while (ind1 < n1 && ind2 < n2){
            if (nums1[ind1] < nums2[ind2]){
                final.push_back(nums1[ind1]);
                ind1 ++;
            } else {
                final.push_back(nums2[ind2]);
                ind2 ++;
            }
        }

        while (ind1 < n1) 
            final.push_back(nums1[ind1++]);
        while (ind2 < n2) 
            final.push_back(nums2[ind2++]);

        if ((n1 + n2) % 2 == 0){

            return float(final[(n1+n2)/2] + final[(n1+n2-1)/2])/2;
        } else {
            return float(final[(n1+n2-1)/2]);
        }
    }
};