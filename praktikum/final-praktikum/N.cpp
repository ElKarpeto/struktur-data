#include <bits/stdc++.h>
using namespace std;

struct AVLNode
{
    int data, power;
    AVLNode *left, *right;
    int height;
};

struct AVL
{
    AVLNode *_root;
    unsigned _size;

private:
    AVLNode *_avl_createNode(int value, int power)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->power = power;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode *_search(AVLNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int _max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    AVLNode *_insert_AVL(AVLNode *node, int value, int power)
    {

        if (node == NULL)
            return _avl_createNode(value, power);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value, power);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value, power);

        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);

        return node;
    }

    AVLNode *_findMinNode(AVLNode *node)
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode *_remove_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return node;
        if (value > node->data)
            node->right = _remove_AVL(node->right, value);
        else if (value < node->data)
            node->left = _remove_AVL(node->left, value);
        else
        {
            AVLNode *temp;
            if ((node->left == NULL) || (node->right == NULL))
            {
                temp = NULL;
                if (node->left == NULL)
                    temp = node->right;
                else if (node->right == NULL)
                    temp = node->left;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_AVL(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);

        return node;
    }

    void _inorder(AVLNode *node)
    {
        if (node)
        {
            _inorder(node->left);
            printf("%d ", node->data);
            _inorder(node->right);
        }
    }

public:
    void init()
    {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->data == value)
            return true;
        else
            return false;
    }

    void insert(int value, int power)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value, power);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder()
    {
        this->_inorder(_root);
    }
};

void BFS(AVLNode *root, string name, string element, string region, int power)
{
    if (root == NULL)
        return;

    int kekuatan = power;

    queue<pair<AVLNode *, int>> q;

    q.push(make_pair(root, 0));

    vector<vector<pair<int, int>>> level;
    while (!q.empty())
    {
        int len = q.size();

        vector<pair<int, int>> nodeLevel;
        for (int i = 0; i < len; i++)
        {
            AVLNode *curr = q.front().first;
            int lev = q.front().second;
            q.pop();

            nodeLevel.push_back(make_pair(curr->data, curr->power));

            if (curr->left != NULL)
                q.push(make_pair(curr->left, lev + 1));
            if (curr->right != NULL)
                q.push(make_pair(curr->right, lev + 1));
        }
        level.push_back(nodeLevel);
    }

    for (int i = level.size() - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            cout << "Final Stage:";
            cout << "\n";
            cout << "Final Boss " << region << "_" << level[i][i].first << ": " << level[i][i].second;
            cout << "\n";
            break;
        }

        int karakter = 65;
        int counter = 1;
        cout << "Stage " << level.size() - i << ":";
        cout << "\n";
        for (auto &node : level[i])
        {
            cout << "Monster " << (char)karakter++ << node.first << "_" << level.size() - i << "_" << counter++ << ": " << node.second;
            cout << "\n";
        }
    }

    cout << "Result:";
    cout << "\n";

    for (int i = level.size() - 1; i >= 0; --i)
    {
        int totalPower = 0;
        for (auto &node : level[i])
        {
            totalPower += node.second;
        }

        if (kekuatan % 2 == 0)
        {
            kekuatan += kekuatan * 8 / 100;
        }
        else
        {
            kekuatan += kekuatan * 15 / 100;
        }
        kekuatan -= totalPower;
        if (kekuatan < 0)
        {
            cout << name << " kalah dan mati di Region " << region << " pada ";
            if (i == 0)
            {
                cout << "Final Stage";
                cout << "\n";
            }
            else
            {
                cout << "Stage " << level.size() - i;
                cout << "\n";
            }
            return;
        }
    }
    cout << name << " menang melawan Final Boss dan memenangkan game di Honkai Star Rail\nRegion " << region;
    cout << "\n";
}

int main(int argc, char **argv)
{
    string nama, element, region;
    int countMonster, power;

    cin >> nama >> countMonster >> element >> power >> region;

    AVL tree;

    tree.init();

    int key, powerMonster;
    while (countMonster--)
    {
        cin >> key >> powerMonster;
        tree.insert(key, powerMonster);
    }

    cout << "*****************************************************************************";
    cout << "\n";
    cout << "Honkai Star Rail Region " << region << "\n";
    cout << "Trailblazer : " << nama << "\n";
    cout << "Element : " << element << " - " << power << "\n";
    cout << "----------------------------------------------------------------------------";
    cout << "\n";
    BFS(tree._root, nama, element, region, power);
    cout << "*****************************************************************************";
    cout << "\n";

    return 0;
}