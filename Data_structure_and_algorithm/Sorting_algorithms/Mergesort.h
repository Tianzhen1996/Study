//*********************************************************
// Title: ¹é²¢ÅÅÐò
// Author: ºúÌìèå
// Email: 1003111694@qq.com
// Data: 2020/6/28.
//*********************************************************

#ifndef PROJECT1_MERGESORT_H
#define PROJECT1_MERGESORT_H
#include <vector>
using namespace std;
void Mergesort(vector<int> &vec, vector<int> &nums, int Left, int Right){
    if(Right - Left < 1) return;
    int Mid = (Left + Right)/2;
    Mergesort(vec, nums, Left, Mid);
    Mergesort(vec, nums, Mid + 1, Right);
    int i = Left, j = Mid + 1, k = Left;
    while(i <= Mid && j <= Right){
        if(vec[i] < vec[j])
            nums[k++] = vec[i++];
        else
            nums[k++] = vec[j++];
    }
    if(i <= Mid) copy(vec.begin() + i, vec.begin() + Mid + 1, nums.begin() + k);
    if(j <= Right) copy(vec.begin() + j, vec.begin() + Right + 1, nums.begin() + k);
    copy(nums.begin() + Left, nums.begin() + Right + 1, vec.begin() + Left);
}
#endif //PROJECT1_MERGESORT_H
