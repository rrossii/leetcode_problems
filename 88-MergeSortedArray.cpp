#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        } else if (m == 0) {
            nums1 = nums2;
            return;
        }

        vector<int> nums3;
        int ind1 = 0, ind2 = 0;
        while (ind1 < m && ind2 < n) {
            if (nums1[ind1] < nums2[ind2]) {
                nums3.emplace_back(nums1[ind1]);
                ind1++;
            } else {
                nums3.emplace_back(nums2[ind2]);
                ind2++;
            }
        }

        while (ind2 < n) {
            nums3.emplace_back(nums2[ind2]);
            ind2++;
        }
        while (ind1 < m) {
            nums3.emplace_back(nums1[ind1]);
            ind1++;
        }
        nums1 = nums3;
    }
};

int main() {
    Solution s;
//    vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    vector<int> nums1 = {-1, -1, 0, 0, 0, 0}, nums2 = {-1, 0};
//    vector<int> nums1 = {4, 5, 7, 9, 9, 0, 0, 0}, nums2 = {1, 10, 15};
//    vector<int> nums1 = {2, 0}, nums2 = {1};
//    vector<int> nums1 = {-1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0}, nums2 = {-1, -1, 0, 0, 1, 2};
    int m = 4, n = 2;
    s.merge(nums1, m, nums2, n);

    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}