//*********************************************************
// Title: 图论算法
// Author: Hu Tianzhen
// Email: 1003111694@qq.com
// Data: 2020/7/12.
//*********************************************************

#ifndef DATA_STRUCTURE_AND_ALGORITHM_GRAPH_H
#define DATA_STRUCTURE_AND_ALGORITHM_GRAPH_H
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Graph {
public:
    void insert(string, string);//输入
    void print();//输出邻接表
    vector<string> topsort();//输出邻接表
private:
    unordered_map<int, vector<int>> adjacencylist;//邻接表
    vector<int> indegree;//入度数组
    unordered_map<string, int> node2index;//值到内部编号的哈希表
    unordered_map<int, string> index2node;//内部编号到值的哈希表
    int node_num = 0;//节点数
    int find_zero_indegree();//找入度为0的点，就是找入口呗
};

int Graph::find_zero_indegree() {
    vector<int>::iterator iter = find(indegree.begin(), indegree.end(), 0);
    if (iter == indegree.end())
        return -1;
    else {
        return iter - indegree.begin();
    }
}

vector<string> Graph::topsort() {
    vector<string> topsort_result;
    for (int i = 0; i < node_num; ++i) {
        int innode = find_zero_indegree();
        if (innode == -1) {
            cout << "有环";//还没输出全部的点就找不到入度为0的点了，说明有环
            break;
        }
        indegree[innode] = -1;//删去这个点，直接入度为-1就行了
        topsort_result.push_back(index2node[innode]);
        for (auto outnode : adjacencylist[innode]) {
            --indegree[outnode];
        }
    }
    return topsort_result;
}

void Graph::insert(string s1, string s2) {
    if (node2index.find(s1) == node2index.end()) {
        node2index[s1] = node_num;
        index2node[node_num] = s1;
        ++node_num;
        indegree.push_back(0);
    }
    if (node2index.find(s2) == node2index.end()) {
        node2index[s2] = node_num;
        index2node[node_num] = s2;
        ++node_num;
        indegree.push_back(0);
    }
    adjacencylist[node2index[s1]].push_back(node2index[s2]);
    ++indegree[node2index[s2]];
}

void Graph::print() {
    for (int i = 0; i < node_num; ++i) {
        cout << index2node[i] << ' ';
        for (int j = 0; j < adjacencylist[i].size(); ++j) {
            cout << index2node[adjacencylist[i][j]] << ' ';
        }
        cout << endl;
    }
}
#endif //DATA_STRUCTURE_AND_ALGORITHM_GRAPH_H
