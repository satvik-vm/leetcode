#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left = NULL, *right = NULL;
};

vector<TreeNode *> leaves;
unordered_map<TreeNode *, int> dis;

void calculateDistance(TreeNode *node)
{
    //set dis[root] = 0 at deeepestLeavesSum
    if(node->left != NULL) {
        dis[node->left] = dis[node] + 1;
        calculateDistance(node->left);
    }
    if(node->right != NULL) {
        dis[node->right] = dis[node] + 1;
        calculateDistance(node->right);
    }
}

int deepestLeavesSum(TreeNode *root)
{
    dis[root] = 0;
    calculateDistance(root);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left == NULL && node->right == NULL)
        {
            leaves.push_back(node);
        }
        else if (node->left != NULL)
        {
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            q.push(node->right);
        }
        // cout << dis[node] << " "<< node->val <<endl;
    }
    int maximum = 0, result = 0;
    for(auto leaf : leaves){
        maximum = max(maximum, dis[leaf]);
    }
    for(auto leaf : leaves){
        if(dis[leaf] == maximum){
            result += leaf->val;
        }
    }
    return result;
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 6;
    TreeNode *r1 = new TreeNode;
    TreeNode *l1 = new TreeNode;
    root->right = r1;
    root->left = l1;
    r1->val = 7;
    l1->val = 8;
    TreeNode *r2 = new TreeNode;
    TreeNode *l2 = new TreeNode;
    r2->val = 7;
    l2->val = 2;
    l1->right = r2;
    l1->left = l2;
    TreeNode *r3 = new TreeNode;
    TreeNode *l3 = new TreeNode;
    r3->val = 3;
    l3->val = 1;
    r1->right = r3;
    r1->left = l3;
    TreeNode *l4 = new TreeNode;
    l2->left = l4;
    l4->val = 9;
    TreeNode *l5 = new TreeNode;
    r2->left = l5;
    l5->val = 1;
    TreeNode *r5 = new TreeNode;
    r2->right = r5;
    r5->val = 4;
    TreeNode *r6 = new TreeNode;
    r6->val = 5;
    r3->right = r6;
    int result = deepestLeavesSum(root);
    cout << result << endl;
}
