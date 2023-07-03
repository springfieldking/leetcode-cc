#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 入度表
        int* inDegree = new int[numCourses];
        // 邻接表
        set<int> * adj = new set<int>[numCourses];

        // 初始化入度表0
        for(int i = 0; i < numCourses; i++) {
            inDegree[i] = 0;
        }

        // 根据先决条件prerequisites, 创建度信表和邻接表
        // prerequisites = [[a1, b1],[a2, b2]...]
        for(auto & p : prerequisites) {
            // p[1] -> p[0]
            inDegree[p[0]] ++; // p[0] 加一
            adj[p[1]].insert(p[0]); // 邻接表添加一条边
        }
       
        // 先把入度为0课程添加到队列中
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

         // 开始bfs流程
        int cnt = 0;
        vector<int> results;
        while (!q.empty()) {
            // 出队列计数
            int v = q.front();
            q.pop();
            cnt ++;
            results.push_back(v);
            // 把邻接点加入队列
            for(auto & beg : adj[v] ) {
                if(--inDegree[beg] == 0)
                    q.push(beg);
            }
        }

        delete[] inDegree;
        delete[] adj;
        if(cnt < numCourses)
            results.clear();
        return results;
    }
};