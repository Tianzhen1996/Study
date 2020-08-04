//*********************************************************
// Title: 最简单的快排
// Author: 胡天桢
// Email: 1003111694@qq.com
// Data: 2020/6/25.
//*********************************************************
#ifndef PROJECT1_QUICKSORT_H
#define PROJECT1_QUICKSORT_H
#include <vector>
using namespace std;
void quicksort(vector<int> &vec, int Left, int Right){
    if(Right - Left < 1) return;
    swap(vec[Left],vec[Right]);
    int i = Left,j = Right - 1;
    while(i<=j){
        while(i<=j && vec[i]<vec[Right])
            ++i;
        while(i<=j && vec[j]>vec[Right])
            --j;
        if(i<j){
            swap(vec[i],vec[j]);
        }
    }
    swap(vec[i],vec[Right]);
    quicksort(vec,Left,i-1);
    quicksort(vec,i+1,Right);
}
#endif //PROJECT1_QUICKSORT_H
