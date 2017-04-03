#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};
Node *root;

queue < Node* > q;
vector < Node* > v[100];
map < Node*, int >dist;

void insert(Node *node, int val)
{
    //cout << val;
    if(node == NULL)
    {
        node = new Node;
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        root = node;
        cout << "root inserted\n";

    }
    else
    {
        //cout << "#";
        if(val<node->val)
        {
            if(node->left == NULL)
            {
                cout << "left inserted\n";
                Node *left = new Node;
                left->val = val;
                left->left = NULL;
                left->right = NULL;
                node->left = left;
            }
            else
                insert(node->left, val);
        }
        else
        {
            if(node->right == NULL)
            {
                cout << "right insert \n";
                Node *right = new Node;
                right->val = val;
                right->left = NULL;
                right->right = NULL;
                node->right = right;
            }
            else
                insert(node->right, val);
        }
    }
}

int findlength(Node *node)
{
    if(node == NULL)
        return 0;

    return 1+ max(findlength(node->left), findlength(node->right));
}

void printtree(Node *node)
{
    if(node != NULL)
    {
        //cout << node->val;
        printtree(node->left);
        cout << node->val << " ";
        printtree(node->right);
    }

}

void printbfs(Node *current)
{

    q.push(current);
    //cout << current->val;
    dist[current] = 0;
    v[0].push_back(current);

    while(!q.empty())
    {
        Node *temp = q.front();
        //cout << temp->val << " ";;
        q.pop();
        if(temp->left != NULL)
        {
            dist[temp->left] = dist[temp] + 1;
            v[dist[temp->left]].push_back(temp->left);
            q.push(temp->left);

        }
        if(temp->right != NULL)
        {
            dist[temp->right] = dist[temp] + 1;
            v[dist[temp->right]].push_back(temp->right);
            q.push(temp->right);
        }
    }

}

int main()
{
    root = NULL;
    insert(root, 50);
    insert(root, 10);
    insert(root, 50);
    insert(root, 100);
    insert(root, 25);
    insert(root, 35);
    insert(root, 20);
    insert(root, 1);


    printtree(root);
    cout << "\nlength is\n";
    cout << findlength(root)-1 << endl;

    printbfs(root);

    for(int i=0;i<(findlength(root));i++)
    {

        for(int j=0;j<v[i].size();j++)
        {

            cout << v[i][j]->val << " ";
        }
        cout << endl;
    }

    //cout << root;
    return 0;
}
