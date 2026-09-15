class Solution {
    int binarysearch(vector<int>& nums, int target, int low, int high) {
        if (low > high) {
            return -1;
        }

        int mid = (low + high) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            return binarysearch(nums, target, low, mid - 1);
        }
        else {
            return binarysearch(nums, target, mid + 1, high);
        }
    }

public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        int mid = binarysearch(nums, target, low, high);

        if (mid != -1) {
            return mid;
        }

        int t1 = target;
        bool i = true;
        int ans = mid;

        while (i) {
            t1 = t1 - 1;

            if (nums[low] > t1) {
                break;
            }

            ans = binarysearch(nums, t1, low, high);

            if (ans != -1) {
                i = false;
            }
        }

        if (!i) {
            return ans + 1;
        }

        // Reset t1 to target
        t1 = target;
        i = true;

        while (i) {
            t1 = t1 + 1;

            if (nums[high] < t1) {
                i = false;
                break;
            }

            ans = binarysearch(nums, t1, low, high);

            if (ans != -1) {
                i = false;
            }
        }

        if (!i) {
            return ans;
        }

        if (nums[0] > target) {
            ans = 0;
        }
        else if (nums[high] < target) {
            ans = high + 1;
        }

        return ans;
    }
};