#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(TestQ31, HandlesTestQ31) {
  std::map<int, std::set<int>> vertices{
  {0, {1,2,5}},
  {1, {0,2,3}},
  {2, {0,1,3}},
  {3, {1,2,4,6}},
  {4, {3}},
  {5, {0}},
  {6, {3}}
  };
  Graph g(vertices);
  std::map<int,int> distance = g.BFS_distance(0);
  std::map<int,int> expected  = { {0, 0}, {1, 1}, {2, 1}, {3, 2}, {4, 3}, {5, 1}, {6, 3} };
  EXPECT_EQ(distance, expected);
}

TEST(TestQ32, HandlesTestQ32) {
  std::map<int, std::set<int>> vertices{
  {0, {1,2,5}},
  {1, {0,2,3}},
  {2, {0,1,3}},
  {3, {1,2,4,6}},
  {4, {3}},
  {5, {0}},
  {6, {3}}
  };
  Graph g(vertices);
  std::map<int,std::vector<int>> path = g.BFS_path(0);
  std::map<int,std::vector<int>> expected  = { {0, {0}},
   {1, {0, 1}}, {2, {0, 2}}, {3, {0, 1, 3}}, {4, {0, 1, 3, 4}},
    {5, {0, 5}}, {6, {0, 1, 3, 6}} };
  EXPECT_EQ(expected, path);
}

TEST(TestQ4, HandlesTestQ4) {
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
  std::vector<int> expected = {7, 6, 3, 5, 4, 2, 1, 0};
  EXPECT_EQ(topo, expected);
}

TEST(TestQ5, HandlesTestQ5) {
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
  testing::internal::CaptureStdout();
  std::vector<bool> result = g2.boolPath();
  for(auto it: result){
    std::cout<<it<<" ";
  }
  std::string output = testing::internal::GetCapturedStdout();
  
  std::string expected = "1 1 1 0 0 1 1 0 ";
  EXPECT_EQ(output, expected);
}