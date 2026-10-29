
class Solution {
public:
    int search(vector<int>& arr, int tar) {
        return binarySearch(arr, 0, arr.size() - 1, tar);
    }

    int binarySearch(vector<int>& arr, int si, int ei, int tar) {
        if (si > ei) {
            return -1;
        }

        int mid = si + (ei - si) / 2;

        if (arr[mid] == tar) {
            return mid;
        }

        // Left half is sorted
        if (arr[si] <= arr[mid]) {
            if (arr[si] <= tar && tar < arr[mid]) {
                return binarySearch(arr, si, mid - 1, tar);
            } else {
                return binarySearch(arr, mid + 1, ei, tar);
            }
        }
        // Right half is sorted
        else {
            if (arr[mid] < tar && tar <= arr[ei]) {
                return binarySearch(arr, mid + 1, ei, tar);
            } else {
                return binarySearch(arr, si, mid - 1, tar);
            }
        }
    }
};
