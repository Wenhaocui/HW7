#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <map>
#include <set>

class Graph {
public:
Graph(std::map<int, std::set<int>> &vertices) :
v_(vertices) {}
std::map<int, std::set<int>> v_;
//Q3
std::map<int,int> BFS_distance(int root);
std::map<int,std::vector<int>> BFS_path(int root);
std::vector<int> TopologicalSort(int root);
std::vector<bool> boolPath ();
private:
void DFS_helper_with_topo(int root, std::map<int, int> &marks, std::vector<int> &topo_list);

};


class Solution {
public:
 
};


#endif