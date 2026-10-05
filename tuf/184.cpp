#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	//your code goes here
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> colored(n, -1);
        bool answer = recur(mp, 0, colored, n, m);
        return answer;
    }

    bool isSafe(vector<int>& edges, int color, vector<int>& colored){
        for(int i = 0; i < edges.size(); i++){
            if(colored[edges[i]] == color)  return false;
        }
        return true;
    }

    bool recur(unordered_map<int, vector<int>>& graph, int vertex, vector<int>& colored, int n, int m){
        if(vertex == n)  return true;

        for(int i = 0; i < m; i++){
            if(isSafe(graph[vertex], i, colored)){
                colored[vertex] = i;
                if(recur(graph, vertex + 1, colored, n, m)) return true;
                colored[vertex] = -1;
            }
        }
        return false;
    }
};