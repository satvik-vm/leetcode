#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define N 100
#define INF 15000000

using namespace std;

struct edge{
    int src, dest;
    int wt;
};

vector<pair<int, int>> directededges[N];

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void addedge(vector<int> edge){
    directededges[edge[0]-1].push_back(make_pair(edge[1], edge[2]));
}

void check(int src){
    cout << "----CHECK----" << endl;
    for(auto node2 : directededges[src-1]){
        cout << node2.first << " " << node2.second << endl;
    }
}

int *calculate(int src, int vertexnum){
    bool visited[vertexnum];
    for(int i = 0;i < vertexnum;i++){
        visited[i] = false;
    }
    int *distance = new int[vertexnum];
    for(int i = 0;i < vertexnum;i++){
        distance[i] = INF;
    }
    visited[src-1] = true;
    distance[src-1] = 0;
    queue<int> q;
    q.push(src);
    check(3);
    while(!q.empty()){
        int source = q.front();
        q.pop();
        for(auto destination : directededges[source-1]){
            cout <<"BEFORE IF : " << source << " " << destination.first << endl;
            cout <<"DATA : " << distance[destination.first-1] << " " << distance[source-1] + destination.second << " " << visited[destination.first-1] << endl;
            if(distance[destination.first-1] > distance[source-1] + destination.second){
                cout << "THIS IS VISITED " << source << " " << destination.first << endl << endl;
                distance[destination.first-1] = distance[source-1] + destination.second;
                q.push(destination.first);
            }
            visited[destination.first-1] = true;
        }
    }
    quickSort(distance, 0, vertexnum-1);
    for (int i = 0; i < vertexnum;i++){
        cout << distance[i] << " ";
    }
    cout << endl;
    return distance;
}

//k is souce and n is number of nodes
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    for(int i = 0;i < times.size();i++){
        addedge(times[i]);
    }
    int *dis = calculate(k, n);
    // for(int i = 0;i < n;i++){
    //     cout << dis[i] << " ";
    // }
    // cout << endl;
    int ans;
    if(dis[n-1] == INF) ans = -1;
    else    ans = dis[n-1];
    return ans;
}

int main(){
    vector<vector<int>> times; //= [[2,1,1], [2,3,1], [3,4,1]];
    int  n = 2, k = 1;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(1);
    times.push_back(temp);
    temp.clear();
    // temp.push_back(2);
    // temp.push_back(3);
    // temp.push_back(1);
    // times.push_back(temp);
    // temp.clear();
    // temp.push_back(3);
    // temp.push_back(4);
    // temp.push_back(1);
    // times.push_back(temp);
    // temp.clear();
    int ans = networkDelayTime(times, n, k);
    // check(k);
    cout << ans << endl;
}