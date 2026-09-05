class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n =nums2.size();
        int total =(m+n+1)/2;
        int cut1 =(m+1)/2;
        int cut2 =total-cut1;
        while(true) {
         int left1;
            int right1;
            int left2;
            int right2;

            // nums1 boundaries
            if (cut1 == 0)
                left1 = INT_MIN;
            else
                left1 = nums1[cut1 - 1];

            if (cut1 == m)
                right1 = INT_MAX;
            else
                right1 = nums1[cut1];

            // nums2 boundaries
            if (cut2 == 0)
                left2 = INT_MIN;
            else
                left2 = nums2[cut2 - 1];

            if (cut2 == n)
                right2 = INT_MAX;
            else
                right2 = nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((m + n) % 2 == 1)
                    return max(left1, left2);

        return    (max(left1, left2) + min(right1, right2)) / 2.0;
        }
        else if(left1>right2){
            cut1--;
            cut2++;
        }
        else {
            cut1++;
            cut2--;
        }


        }
    }
};