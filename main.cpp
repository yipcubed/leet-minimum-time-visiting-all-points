#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/minimum-time-visiting-all-points/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int cost = 0;
    int px = points[0][0];
    int py = points[0][1];
    int nx, ny, diagx, diagy;
    for (int i = 1; i < points.size(); ++i) {
      nx = points[i][0];
      ny = points[i][1];
      diagx = abs(nx - px);
      diagy = abs(ny - py);
      cost += min(diagx, diagy);
      cost += abs(diagx - diagy);
      px = nx;
      py = ny;
    }
    return cost;
  }
};

void test1() {
  vector<vector<int>> v1{vector<int>{1, 1}, vector<int>{3, 4}, vector<int>{-1, 0}};

  cout << "7 ? " << Solution().minTimeToVisitAllPoints(v1) << endl;
}

void test2() {

}

void test3() {

}