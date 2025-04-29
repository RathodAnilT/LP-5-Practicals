#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

class Solution {
public:
    void parallelBubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int phase = i % 2;
            #pragma omp parallel for
            for (int j = phase; j < n - 1; j += 2) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) cin >> nums[i];

    Solution sol;

    double start = omp_get_wtime();
    sol.parallelBubbleSort(nums);
    double end = omp_get_wtime();

    cout << "Sorted array:\n";
    for (int x : nums) cout << x << " ";
    cout << "\nTime taken: " << (end - start) << " seconds\n";

    return 0;
}
