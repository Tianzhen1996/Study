//*********************************************************
// Title: Bucket sort
// Author: Hu Tianzhen
// Email: 1003111694@qq.com
// Data: 2020/7/8.
//*********************************************************

#ifndef PROJECT1_BUCKET_SORT_H
#define PROJECT1_BUCKET_SORT_H
#include <vector>
using namespace std;
void Bucket_sort(vector<int> &vec, int N){
    for(int i = 0; i < N - 1; ++i){
        int index = i;
        for(int j = i + 1; j < N; ++j){
            if(vec[index] > vec[j]){
                index = j;
            }
        }
        if(index != i){
            int tmp = vec[i];
            vec[i] = vec[index];
            vec[index] = tmp;
        }
    }
}
#endif //PROJECT1_BUCKET_SORT_H
