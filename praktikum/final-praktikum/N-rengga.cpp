#include <bits/stdc++.h>
using namespace std;

struct AVLNode
{
    int data;
    int power;
    AVLNode *left, *right;
    int height;
};

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

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
        AVLNode *newParent = pivotNode->left;
        pivotNode->left = newParent->right;
        newParent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParent->height = _max(_getHeight(newParent->left), _getHeight(newParent->right)) + 1;

        return newParent;
    }

    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParent = pivotNode->right;
        pivotNode->right = newParent->left;
        newParent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParent->height = _max(_getHeight(newParent->left), _getHeight(newParent->right)) + 1;

        return newParent;
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

    void _bfsFromBottom(AVLNode *node, string name, string element, string region, int power)
    {
        if (node == NULL)
            return;

        int curr = power;
        queue<pair<AVLNode *, int>> q;
        q.push({node, 0});

        vector<vector<pair<int, int>>> levels;

        while (!q.empty())
        {
            int size = q.size();
            vector<pair<int, int>> levelNodes;
            for (int i = 0; i < size; ++i)
            {
                AVLNode *current = q.front().first;
                int level = q.front().second;
                q.pop();
                levelNodes.push_back({current->data, current->power});
                if (current->left)
                    q.push({current->left, level + 1});
                if (current->right)
                    q.push({current->right, level + 1});
            }
            levels.push_back(levelNodes);
        }
        // cout << levels.size();

        for (int i = levels.size() - 1; i >= 0; --i)
        {
            if (i == 0)
            {
                printf("Final Stage:\n");
                for (auto &node : levels[i])
                    cout << "Final Boss " << region << "_" << node.first << ": " << node.second << endl;
                break;
            }
            printf("Stage %ld:\n", levels.size() - i);
            int counter = 1;
            int ascii = 65;
            for (auto &node : levels[i])
            {
                printf("Monster %c%d_%ld_%d: %d\n", (char)ascii++, node.first, levels.size() - i, counter++, node.second);
            }
            // printf("\n");
        }
        puts("Result:");
        for (int i = levels.size() - 1; i >= 0; --i)
        {
            int enemysum = 0;
            for (auto &node : levels[i])
            {
                enemysum += node.second;
            }

            if (curr % 2 == 0)
            {
                curr += curr * 8 / 100;
                // cout << curr << "-" << enemysum << "=";
                // printf("%d\n", curr);
            }
            else
            {
                curr += curr * 15 / 100;
                // cout << curr << "-" << enemysum << "=";
                // printf("%d\n", curr);
            }
            curr -= enemysum;
            // cout << curr << endl;
            if (curr < 0)
            {
                cout << name << " kalah dan mati di Region " << region << " pada ";
                if (i == 0)
                {
                    printf("Final Stage\n");
                }
                else
                {
                    printf("Stage %ld\n", levels.size() - i);
                }
                return;
            }
        }
        cout << name << " menang melawan Final Boss dan memenangkan game di Honkai Star Rail\nRegion " << region << endl;
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
        return temp != NULL && temp->data == value;
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
        _inorder(_root);
        printf("\n");
    }

    void bfsFromBottom(string name, string element, string region, int power)
    {
        _bfsFromBottom(_root, name, element, region, power);
    }
};

int main(int argc, char const *argv[])
{
    AVL set;
    set.init();
    string name, element, region;
    int n, data, power;
    cin >> name >> n >> element >> power >> region;
    for (int i = 0; i < n; i++)
    {
        int enemypower;
        cin >> data >> enemypower;
        set.insert(data, enemypower);
    }
    printf("*****************************************************************************\n");
    cout << "Honkai Star Rail Region " << region << "\n";
    cout << "Trailblazer : " << name << "\n";
    cout << "Element : " << element << " - " << power << "\n";
    printf("----------------------------------------------------------------------------\n");
    set.bfsFromBottom(name, element, region, power);
    printf("*****************************************************************************");
    return 0;
}
