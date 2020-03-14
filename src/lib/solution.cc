#include "solution.h"
#include <iostream>
#include <queue>

//Q3
std::map<int,int> Graph::BFS_distance(int root) {
  std::map<int, int> marks;
  std::queue<int> q;
  q.push(root);
  std::map<int,int> distance;
  marks[root] = 1;
  while (!q.empty()) {
    int cur = q.front();
    int cur_dis = distance[cur];
    q.pop();
    for (auto &n : v_[cur]) {
    if (!marks[n]) {
      distance[n] = cur_dis + 1;
       marks[n] = 1;
       q.push(n);
     }
   }
 }
return distance; // distances or paths
}

//Q3
std::map<int,std::vector<int>> Graph::BFS_path(int root) {
  std::map<int, int> marks;
  std::queue<int> q;
  q.push(root);
  std::map<int,std::vector<int>> path;
  marks[root] = 1;
  path[root].push_back(root);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto &n : v_[cur]) {
    if (!marks[n]) {
       marks[n] = 1;
       path[n] = path[cur];
       path[n].push_back(n);
       q.push(n);
     }
   }
 }
return path; // distances or paths
}
//Q4
void Graph::DFS_helper_with_topo(int root, std::map<int, int> &marks, std::vector<int> &topo_list){
  marks[root] = 1;
  for (const int child : v_[root]) {
    if (marks[child] != 1) { 
      DFS_helper_with_topo(child, marks, topo_list);
    } 
  }
  topo_list.push_back(root); 
}
std::vector<int> Graph::TopologicalSort(int root) { 
  std::vector<int> topo_list;
  std::map<int, int> marks;
  DFS_helper_with_topo(root, marks, topo_list);
  std::reverse(topo_list.begin(),topo_list.end());
  return topo_list; 
}

//Q5
std::vector<bool> Graph::boolPath (){
  int n = v_.size()-1;
  // for(auto it :v_){
  //   if(n < it.first){
  //     n =it.first;
  //   }
  // }
  std::map<int,int> start = BFS_distance(0);
  std::map<int,int> end = BFS_distance(n);
  std::vector<bool> result;
  for(int i=0; i<n; i++){
    if(start[i] + end[i] == start[0] + end[0]) {
      result.push_back(true);
    }else{
      result.push_back(false);
    }
  }
  return result;
}