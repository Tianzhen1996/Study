//*********************************************************
// Title: √∞≈›≈≈–Ú
// Author: Hu Tianzhen
// Email: 1003111694@qq.com
// Data: 2020/7/8.
//*********************************************************

#ifndef PROJECT1_BUBBLE_SORT_H
#define PROJECT1_BUBBLE_SORT_H
#include <vector>
using namespace std;
void Bubble_sort(vector<int> &vec, int N){
    for(int i = 1; i < N ; ++i){
        for(int j = 0; j < N - i; ++j){
            if(vec[j] > vec[j+1]){
                int tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }
}
#endif //PROJECT1_BUBBLE_SORT_H
