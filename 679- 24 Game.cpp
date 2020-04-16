#include <bits/stdc++.h>

using namespace std;


vector<double> ops(double x, double y) {
    vector<double> result;

    result.push_back(y - x);
    result.push_back(x - y);
    result.push_back(x + y);
    result.push_back(x * y);
    if(y != 0)
        result.push_back(x / y);
    if(x != 0)
        result.push_back(y / x);
    return result;
}
bool check(double a) {
    int x = a-24.0;
    if(x<0.0)
        x = -1 * x;
    return (x<=0.01);
}

void display(vector<double>& A) {
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
bool backtracker(vector<double> &A) {
    display(A);
    if(A.size() == 1)
        return check(A[0]);
    for(int i=0; i < A.size(); i++) {
        for(int j = i + 1; j < A.size(); j++) {
            vector<double> B(A.size() - 1);
            int index = 0;
            for(int k = 0; k < A.size(); k++) {
                if(k == i || k == j)
                    continue;
                B[index++] = A[k];
            }
            for(double x: ops(A[i], A[j])) {
                B[A.size()-2] = x;
                if(backtracker(B))
                    return true;
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int>& nums) {
    vector<double> arr(nums.size());
    for(int i = 0; i < nums.size(); i++) {
        arr[i] = nums[i];
    }
    return backtracker(arr);
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(7);
    if(judgePoint24(nums)){
        cout << "SUCCESS";
        return 0;
    }
    cout << "FAILURE";
    return 0;
}
