//*********************************************************
// Title: ͼ���㷨
// Author: Hu Tianzhen
// Email: 1003111694@qq.com
// Data: 2020/7/12.
//*********************************************************

#ifndef DATA_STRUCTURE_AND_ALGORITHM_GRAPH_H
#define DATA_STRUCTURE_AND_ALGORITHM_GRAPH_H
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Graph {
public:
    void insert(string, string);//����
    void print();//����ڽӱ�
    vector<string> topsort();//����ڽӱ�
private:
    unordered_map<int, vector<int>> adjacencylist;//�ڽӱ�
    vector<int> indegree;//�������
    unordered_map<string, int> node2index;//ֵ���ڲ���ŵĹ�ϣ��
    unordered_map<int, string> index2node;//�ڲ���ŵ�ֵ�Ĺ�ϣ��
    int node_num = 0;//�ڵ���
};

vector<string> Graph::topsort() {
    vector<string> topsort_result;
    queue<int> Q;//��������
    for (int i = 0; i < node_num; ++i) {
        if (indegree[i] == 0) Q.push(i);
    }
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        topsort_result.push_back(index2node[cur]);
        for (auto index : adjacencylist[cur]) {
            if (--indegree[index] == 0)
                Q.push(index);
        }
    }
    if (topsort_result.size() != node_num) {
        cout << "�л�" << endl;
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