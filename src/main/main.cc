#include "src/lib/solution.h"
#include <iostream>


int main() {
  //Q3
  std::map<int, std::set<int>> vertices{
  {0, {1,2}},
  {1, {3}},
  {2, {3}},
  {3, {}}
  // {4, {3}},
  // {5, {0}},
  // {6, {3}}
  };
  Graph g(vertices);
  std::map<int,int> distance = g.BFS_distance(0);
  for(auto it : distance){
    std::cout<<it.first<<"'s distance is " << it.second << std::endl;
  }

  //Q3
  std::map<int,std::vector<int>> path = g.BFS_path(0);
  for(auto it : path){
    std::cout<<it.first<<"'s path is ";
    for(auto it1 : it.second){
      std::cout<<it1<<" ";
    }
    std::cout << std::endl;
  }
  //Q4
  std::map<int, std::set<int>> vertices1{
  {7, {5,6}},
  {6, {4,3}},
  {5, {4,2}},
  {4, {}},
  {3, {1}},
  {2, {1}},
  {1, {0}},
  {0, {}}
  };
  Graph g1(vertices1);
  std::vector<int> topo = g1.TopologicalSort(7);
  for(auto it: topo){
    std::cout<<it<<" ";
  }
  std::cout << std::endl;
  std::map<int, std::set<int>> vertices2{
  {0, {1,4,5}},
  {1, {0,2,3}},
  {2, {1,3,8}},
  {3, {1,2}},
  {4, {0}},
  {5, {0,6}},
  {6, {5,7,8}},
  {7, {6,8}},
  {8, {2,6,7}},
  };

  Graph g2(vertices2);
  std::vector<bool> result = g2.boolPath();
  for(auto it: result){
    std::cout<<it<<" ";
  }
  std::cout << std::endl;
}

