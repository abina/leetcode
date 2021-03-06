class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersections;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 == 0 || n2 == 0) {
            return intersections;
        }
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0, j = 0; i < n1 && j < n2;) {
            if (nums1[i] == nums2[j]) {
                if (intersections.empty() || nums1[i] != intersections.back()) {
                    intersections.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return intersections;
    }
};

