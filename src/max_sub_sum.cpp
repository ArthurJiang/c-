#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

struct Result {
    int sum;
    int start;
    int end;
};

Result maxSubSum (const vector<int> &arr) {
    int curSum = 0, maxSum = 0, start = 0, end = 0, mid = 0;

    for (int i = 0; i < arr.size(); i++) {
        curSum += arr[i];

        if (curSum > maxSum) {
            maxSum = curSum;
            if (mid != 0) {
                start = mid;
            }

            end = i;
        }

        if (curSum < 0) {
            curSum = 0;
            mid = i + 1;
        }
    }

    Result r;
    r.sum = maxSum;
    r.start = start;
    r.end = end;

    return r;
}

int main() {
    int tmp1[8] = {4, -3, 5, -2, -1, 2, 6, -2};
    vector<int> a1(tmp1, tmp1 + 8);
    Result r1 = maxSubSum(a1);
    cout << "Sum: " << r1.sum << " Start: " << r1.start << " End: " << r1.end << endl;
    assert(r1.sum == 11);
    int tmp2[6] = {-2, 11, -4, 13, -5, -2};
    vector<int> a2(tmp2, tmp2 + 6);
    Result r2 = maxSubSum(a2);
    cout << "Sum: " << r2.sum << " Strat: " << r2.start << " End: " << r2.end << endl;
    assert(r2.sum == 20);
    return 0;
}
