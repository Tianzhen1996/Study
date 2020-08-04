//*********************************************************
// Title: 三数中值快排
// Author: 胡天桢
// Email: 1003111694@qq.com
// Data: 2020/6/29.
//*********************************************************

#ifndef PROJECT1_QUICKSORT2_H
#define PROJECT1_QUICKSORT2_H
#include <vector>
using namespace std;
//插入排序（辅助）
void Insertionsort(vector<int> &vec, int Left, int Right){
    for(int i = Left + 1; i <= Right ; ++i){
        int j = i;
        int tmp = vec[i];
        while(j > Left && vec[j - 1] > tmp){
            vec[j] = vec[j - 1];
            -- j;
        }
        vec[j] = tmp;
    }
}

//三数中值分割
int Median3(vector<int> &vec, int Left, int Right){
    int Mid = (Left + Right) / 2;
    if(vec[Left] > vec[Mid])
        swap(vec[Left], vec[Mid]);
    if(vec[Left] > vec[Right])
        swap(vec[Left], vec[Right]);
    if(vec[Mid] > vec[Right])
        swap(vec[Mid], vec[Right]);
    swap(vec[Mid], vec[Right - 1]);
    return vec[Right - 1];
}

//快排
void quicksort(vector<int> &vec, int Left, int Right){
    if(Left + 3 <= Right){
        int P = Median3(vec, Left, Right);//枢纽元
        int i = Left, j = Right - 1;
        while(i<j){
            while(vec[++i] < P);
            while(vec[--j] > P);
            if(i<j)
                swap(vec[i],vec[j]);
        }
        swap(vec[i],vec[Right-1]);
        quicksort(vec, Left, i-1);
        quicksort(vec, i + 1, Right);
    }
    else Insertionsort(vec, Left, Right);//小于等于3个数就直接用插入排序
}
#endif //PROJECT1_QUICKSORT2_H
