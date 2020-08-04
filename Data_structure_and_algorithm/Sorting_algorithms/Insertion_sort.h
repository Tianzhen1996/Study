//*********************************************************
// Title: 插入排序
// Author: 胡天桢
// Email: 1003111694@qq.com
// Data: 2020/6/29.
//*********************************************************

#ifndef PROJECT1_INSERTION_SORT_H
#define PROJECT1_INSERTION_SORT_H
#include <vector>
using namespace std;
void Insertion_sort(vector<int> &vec, int N){
    for(int i = 1; i < N ; ++i){
        int j = i;
        int tmp = vec[i];
        while(j > 0 && vec[j - 1] > tmp){
            vec[j] = vec[j - 1];
            -- j;
        }
        vec[j] = tmp;
    }
}
#endif //PROJECT1_INSERTION_SORT_H
