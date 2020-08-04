//*********************************************************
// Title: ¶ÑÅÅÐò
// Author: ºúÌìèå
// Email: 1003111694@qq.com
// Data: 2020/6/29.
//*********************************************************

#ifndef PROJECT1_HEAPSORT_H
#define PROJECT1_HEAPSORT_H
#include <vector>
using namespace std;
void percolatedown(vector<int> &vec, int pos, int N){
    int child;
    while(pos * 2 + 1 < N){
        child = pos * 2 + 1;//leftchild
        if(child + 1 < N && vec[child + 1] > vec[child]){
            ++ child;
        }
        if(vec[pos] < vec[child]){
            swap(vec[pos], vec[child]);
        }
        else break;
        pos = child;
    }
}

void Heapsort(vector<int> &vec, int heapnum, int N){
    for(int pos = N / 2 - 1; pos >= 0; --pos){
        percolatedown(vec, pos, N);
    }
    for(int tail = N - 1; tail > N - heapnum; --tail) {
        swap(vec[0], vec[tail]);
        percolatedown(vec, 0, tail);
    }
}
#endif //PROJECT1_HEAPSORT_H
