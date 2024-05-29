/*---------------------------------------------Binary-Search-Tree----------------------------------*/

// Question 1

/*

In this question, you have to perform add and delete on binary search tree. Note that:
- When deleting a node which still have 2 children, take the inorder successor (smallest node of the right sub tree of that node) to replace it.
- When adding a node which has the same value as parent node, add it in the left sub tree.
Your task is to implement two functions: add and deleteNode. You could define one or more functions to achieve this task.
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    //Helping function
    void add(T value){
        //TODO
    }
   
    void deleteNode(T value){
        //TODO
    }
    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
    }
    
    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};      */


void add(T value){
    if (root == nullptr){
        root = new Node(value);
        return;
    }
    
    Node *find = root;
    while(true){
        if (value >= find->value){
            if (find->pRight == nullptr)
            break;
            else {
                find = find->pRight;
            }
        }
        else {
            if (find->pLeft == nullptr)
            break;
            else {
                find = find->pLeft;
            }
        }
    }
    if (value >= find->value){
        find->pRight = new Node(value);
    }
    else {
        find->pLeft = new Node(value);
    }
}
Node* dele(Node* root,T val)
{
    if (root == nullptr)
        return root;

    if (root->value > val) {
        root->pLeft = dele(root->pLeft, val);
        return root;
    }
    else if (root->value < val) {
        root->pRight = dele(root->pRight, val);
        return root;
    }
    
    if (root->pLeft == NULL) {
        Node* temp = root->pRight;
        delete root;
        return temp;
    }
    else if (root->pRight == NULL) {
        Node* temp = root->pLeft;
        delete root;
        return temp;
    }
 
    else {
        Node* succParent = root;
        Node* succ = root->pRight;
        while (succ->pLeft != NULL) {
            succParent = succ;
            succ = succ->pLeft;
        }
 
        if (succParent != root)
            succParent->pLeft = succ->pRight;
        else
            succParent->pRight = succ->pRight;

        root->value = succ->value;

        delete succ;
        return root;
    }
}
void deleteNode(T value){
    root = dele(root,value);
}




// Question 2

/*

Class BSTNode is used to store a node in binary search tree, described on the following:
class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};
Where val is the value of node, left and right are the pointers to the left node and right node of it, respectively. If a repeated value is inserted to the tree, it will be inserted to the left subtree.
Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position. For example:
int arr[] = {0, 10, 20, 30};
auto root = BSTNode::createBSTree(arr, arr + 4);
is equivalent to
auto root = new BSTNode(0);
root->addNode(10);
root->addNode(20);
root->addNode(30);
Request: Implement function:
vector<int> levelAlterTraverse(BSTNode* root);
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the values of the nodes in each level, alternating from going left-to-right and right-to-left..
Example:
Given a binary search tree in the following:

In the first level, we should traverse from left to right (order: 3) and in the second level, we traverse from right to left (order: 4, 0). After traversing all the nodes, the result should be [3, 4, 0, 2, 1].
Note: In this exercise, the libraries iostream, vector, stack, queue, algorithm and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.    */


vector<int> levelAlterTraverse(BSTNode* root) {
    vector<int> result;
    if (root == nullptr) return result;
    queue<BSTNode *> qu;
    qu.push(root);
    bool check = true;
    while(!qu.empty()){
        vector<int> temp;
        int size = qu.size();
        for (int i=0; i<size; i++){
            BSTNode *node = qu.front();
            qu.pop();
            
            if (check) 
                temp.push_back(node->val);
            else
                temp.insert(temp.begin(),node->val);
            
            if (node->left != nullptr) qu.push(node->left);
            if (node->right != nullptr) qu.push(node->right);
        }   
        check = !check;
        result.insert(result.end(), temp.begin(), temp.end());
    }
    return result;
}



// Question 3

/*

Class BSTNode is used to store a node in binary search tree, described on the following:
class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};
Where val is the value of node, left and right are the pointers to the left node and right node of it, respectively. If a repeated value is inserted to the tree, it will be inserted to the left subtree.
Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position. For example:
int arr[] = {0, 10, 20, 30};
auto root = BSTNode::createBSTree(arr, arr + 4);
is equivalent to
auto root = new BSTNode(0);
root->addNode(10);
root->addNode(20);
root->addNode(30);
Request: Implement function:
int kthSmallest(BSTNode* root, int k);
Where root is the root node of given binary search tree (this tree has n elements) and k satisfy: 1 <= k <= n <= 100000. This function returns the k-th smallest value in the tree.
Example:
Given a binary search tree in the following:

With k = 2, the result should be 1.
Note: In this exercise, the libraries iostream, vector, stack, queue, algorithm, climits and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.     */


void arr(BSTNode*root, vector<int>&a){
    if(root==NULL) return;
    a.push_back(root->val);
    
    arr(root->left,a);
    arr(root->right,a);
} 
int kthSmallest(BSTNode* root, int k) {
    // STUDENT ANSWER
    vector<int> result;
    BSTNode *run=root;
    arr(run,result);
    sort(result.begin(),result.end());
    return result[k-1];
}

// Question 4

/*

Class BTNode is used to store a node in binary search tree, described on the following:
class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};
Where val is the value of node (non-negative integer), left and right are the pointers to the left node and right node of it, respectively.
Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position. For example:
int arr[] = {0, 10, 20, 30};
auto root = BSTNode::createBSTree(arr, arr + 4);
is equivalent to
auto root = new BSTNode(0);
root->addNode(10);
root->addNode(20);
root->addNode(30);
Request: Implement function:
int rangeCount(BTNode* root, int lo, int hi);
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements), lo and hi are 2 positives integer and lo ≤ hi. This function returns the number of all nodes whose values are between [lo, hi] in this binary search tree.
More information:
- If a node has val which is equal to its ancestor's, it is in the right subtree of its ancestor.
Example:
Given a binary search tree in the following:

With lo=5, hi=10, all the nodes satisfied are node 9, 7, 8; there fore, the result is 3.
Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.      */


void Count(BTNode* root, int lo, int hi, int &count) {
    if (root == nullptr) return;
    
    if (root->val>=lo && root->val <=hi) count++;
    Count(root->left,lo,hi,count);
    Count(root->right,lo,hi,count);
}

int rangeCount(BTNode* root, int lo, int hi) {
    if (root == nullptr) return 0;
    int count = 0;
    Count(root,lo,hi,count);
    return count;
}



// Question 5

/*

Class BSTNode is used to store a node in binary search tree, described on the following:
class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};
Where val is the value of node, left and right are the pointers to the left node and right node of it, respectively. If a repeated value is inserted to the tree, it will be inserted to the left subtree.
Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position. For example:
int arr[] = {0, 10, 20, 30};
auto root = BSTNode::createBSTree(arr, arr + 4);
is equivalent to
auto root = new BSTNode(0);
root->addNode(10);
root->addNode(20);
root->addNode(30);
Request: Implement function:
int singleChild(BSTNode* root);
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the number of single children in the tree.
More information:
- A node is called a single child if its parent has only one child.
Example:
Given a binary search tree in the following:

There are 2 single children: node 2 and node 3.
Note: In this exercise, the libraries iostream and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.           */


void single(BSTNode* root,int &count) {
    if (root == nullptr) return;
    if((root->left != nullptr && root->right == nullptr)||(root->left == nullptr && root->right != nullptr))
    count++;
    
    single(root->left,count);
    single(root->right,count);
}
int singleChild(BSTNode* root) {
    if (root == nullptr) return 0;
    int count =0;
    single(root,count);
    return count;
}



// Question 6

/*

Class BSTNode is used to store a node in binary search tree, described on the following:
class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};
Where val is the value of node, left and right are the pointers to the left node and right node of it, respectively. If a repeated value is inserted to the tree, it will be inserted to the left subtree.
Also, a static method named createBSTree is used to create the binary search tree, by iterating the argument array left-to-right and repeatedly calling addNode method on the root node to insert the value into the correct position. For example:
int arr[] = {0, 10, 20, 30};
auto root = BSTNode::createBSTree(arr, arr + 4);
is equivalent to
auto root = new BSTNode(0);
root->addNode(10);
root->addNode(20);
root->addNode(30);
Request: Implement function:
BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi);
Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the binary search tree after deleting all nodes whose values are outside the range [lo, hi] (inclusive).
Example:
Given a binary search tree in the following:

With lo = 7 and hi = 10, the result should be:

Note: In this exercise, the libraries iostream and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.            */


BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    if (root == nullptr) return nullptr;
    
    if (root->val > hi) return subtreeWithRange(root->left,lo,hi);
    if (root->val < lo) return subtreeWithRange(root->right,lo,hi);
    
    root->left = subtreeWithRange(root->left,lo,hi);
    root->right = subtreeWithRange(root->right,lo,hi);
    return root;
}


// Question 7


/*

Given class BinarySearchTree, you need to finish method find(i) to check whether value i is in the tree or not; method sum(l,r) to calculate sum of all all elements v in the tree that has value greater than or equal to l and less than or equal to r.
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    void add(T value) ;
    // STUDENT ANSWER BEGIN
 
    // STUDENT ANSWER END
};              */


bool find(T i) {
    Node *temp = root;
    if (temp == nullptr)
    return false;
    while (temp != nullptr){
        if (temp->value == i) return true;
        
        if (temp->value <= i)
            temp = temp->pRight;
        else
            temp = temp->pLeft;
    }
    return false;
    
}
void sumver2(Node *root,T l, T r,T &sum) {
    if (root == nullptr) return;
    
    if (root->value >= l && root->value <= r) sum = sum + root->value;
    sumver2(root->pLeft,l,r,sum);
    sumver2(root->pRight,l,r,sum);
}
T sum(T l, T r) {
    T temp = 0;
    sumver2(root,l,r,temp);
    return temp;
}


// Question 8

/*

Given class BinarySearchTree, you need to finish method getMin() and getMax() in this question.
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    void add(T value) ;
    // STUDENT ANSWER BEGIN
 
    // STUDENT ANSWER END
};
*/


T getMin() {
   if (root == nullptr) return 0;
   Node *temp = root;
   while (temp->pLeft != nullptr)
        temp = temp->pLeft;
    return temp->value;
    
}

T getMax() {
   if (root == nullptr) return 0;
   Node *temp = root;
   while (temp->pRight != nullptr)
        temp = temp->pRight;
    return temp->value;
    
}


/*-----------------------------------Binary-Tree--------------------------------*/

// Question 1
/*
Given a Binary tree, the task is to traverse all the nodes of the tree using Breadth First Search algorithm and print the order of visited nodes (has no blank space at the end)
#include<iostream>
#include<string>
#include<queue>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    // STUDENT ANSWER END
};
You can define other functions to help you.       */


void BFS()
{
    if (root == nullptr) return;
    queue<Node*> qu;
    qu.push(root);
    bool first = true;
    while(!qu.empty()){
        Node * temp = qu.front();
        qu.pop();
        if (first){
            cout<<temp->value;
            first = false;
        }
        else {
            cout<<" "<<temp->value;
        }
        
        if (temp->pLeft!= nullptr){
            qu.push(temp->pLeft);
        }
        if (temp->pRight!= nullptr){
            qu.push(temp->pRight);
        }
    }
 
}


// Question 2

/*

Class BTNode is used to store a node in binary tree, described on the following:
class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};
Where val is the value of node (non-negative integer), left and right are the pointers to the left node and right node of it, respectively.
Request: Implement function:
int longestPathSum(BTNode* root);
Where root is the root node of given binary tree (this tree has between 1 and 100000 elements). This function returns the sum of the largest path from the root node to a leaf node. If there are more than one equally long paths, return the larger sum.
Example:
Given a binary tree in the following:

The longest path from the root node to the leaf node is 1-4-7-4-2, so return the sum of this path, is 18.
Explanation of function createTree: The function has three parameters. The first two parameters take in an array containing the parent of each Node of the binary tree, and the third parameter takes in an array representing the respective values of the Nodes. After processing, the function will construct the binary tree and return the address of the root Node. Note that the root Node is designated with a parent value of -1.
Example:
int arr[] = {-1,0,0,2,2};
int value[] = {3,5,2,1,4};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
arr[0]=-1 means the Node containing the value value[0]=3 will be the root Node. Also, since arr[1]=arr[2]=0, it implies that the Nodes containing the values value[1]=5 and value[2]=2 will have the Node containing the value value[0]=3 as their parent. Lastly, since arr[3]=arr[4]=2, it means the Nodes containing the values value[3]=1 and value[4]=4 will have the Node with the value value[2]=2 as their parent. Final tree of this example are shown in the figure above.
Note that whichever Node appears first in the arr sequence will be the left Node, and the TestCase always ensures that the resulting tree is a binary tree.

Note: In this exercise, the libraries iostream, utility, queue, stack and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.       */


void sumOfLongRootToLeafPath(BTNode* root, int sum,int len, int& maxlen, int& maxsum)
{
    if (root == nullptr) {
        if (maxlen < len) {
            maxlen = len;
            maxsum = sum;
        } else if (maxlen == len && maxsum < sum)
            maxsum = sum;
        return;
    }

    sumOfLongRootToLeafPath(root->left, sum + root->val,len + 1, maxlen, maxsum);
 
    sumOfLongRootToLeafPath(root->right, sum + root->val,len + 1, maxlen, maxsum);
}
int longestPathSum(BTNode* root) {
    if (root == nullptr) return 0;
    int maxsum = -1e9;
    int maxlen = 0;
    sumOfLongRootToLeafPath(root, 0, 0, maxlen, maxsum);
    return maxsum;
}


// Question 3

/*

Class BTNode is used to store a node in binary tree, described on the following:
class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};
Where val is the value of node (non-negative integer), left and right are the pointers to the left node and right node of it, respectively.
Request: Implement function:
int lowestAncestor(BTNode* root, int a, int b);
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the lowest ancestor node's val of node a and node b in this binary tree (assume a and b always exist in the given binary tree).
More information:
- A node is called as the lowest ancestor node of node a and node b if node a and node b are its descendants.
- A node is also the descendant of itself.
- On the given binary tree, each node's val is distinguish from the others' val
Example:
Given a binary tree in the following:

- The lowest ancestor of node 4 and node 5 is node 2.
Explanation of function createTree: The function has three parameters. The first two parameters take in an array containing the parent of each Node of the binary tree, and the third parameter takes in an array representing the respective values of the Nodes. After processing, the function will construct the binary tree and return the address of the root Node. Note that the root Node is designated with a parent value of -1.
Example:
int arr[] = {-1,0,0,2,2};
int value[] = {3,5,2,1,4};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
arr[0]=-1 means the Node containing the value value[0]=3 will be the root Node. Also, since arr[1]=arr[2]=0, it implies that the Nodes containing the values value[1]=5 and value[2]=2 will have the Node containing the value value[0]=3 as their parent. Lastly, since arr[3]=arr[4]=2, it means the Nodes containing the values value[3]=1 and value[4]=4 will have the Node with the value value[2]=2 as their parent. Final tree of this example are shown in the figure above.
Note that whichever Node appears first in the arr sequence will be the left Node, and the TestCase always ensures that the resulting tree is a binary tree.

Note: In this exercise, the libraries iostream, stack, queue, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.          */


bool findPath(BTNode* root, vector<int>& path, int k)
{
    if (root == NULL)
        return false;
    path.push_back(root->val);
 
    if (root->val == k)
        return true;
 
    if (((root->left != nullptr) && findPath(root->left, path, k))|| ((root->right != nullptr) && findPath(root->right, path, k)))
        return true;
 
    path.pop_back();
    return false;
}
int lowestAncestor(BTNode* root, int a, int b) {
    vector<int> path1, path2;
    findPath(root, path1, a);
    findPath(root, path2, b);
 
    int i;
    for (i = 0; i < (int)path1.size() && i < (int)path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}


// Question 4

/*

Class BTNode is used to store a node in binary tree, described on the following:
class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};
Where val is the value of node (integer, in segment [0,9]), left and right are the pointers to the left node and right node of it, respectively.
Request: Implement function:
int sumDigitPath(BTNode* root);
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the sum of all digit path numbers of this binary tree (the result may be large, so you must use mod 27022001 before returning).
More information:
- A path is called as digit path if it is a path from the root node to the leaf node of the binary tree.
- Each digit path represents a number in order, each node's val of this path is a digit of this number, while root's val is the first digit.
Example:
Given a binary tree in the following:

All of the digit paths are 3-5, 3-2-1, 3-2-4; and the number reprensted by them are 35, 321, 324, respectively. The sum of them (after mod 27022001) is 680.
Explanation of function createTree: The function has three parameters. The first two parameters take in an array containing the parent of each Node of the binary tree, and the third parameter takes in an array representing the respective values of the Nodes. After processing, the function will construct the binary tree and return the address of the root Node. Note that the root Node is designated with a parent value of -1.
Example:
int arr[] = {-1,0,0,2,2};
int value[] = {3,5,2,1,4};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
arr[0]=-1 means the Node containing the value value[0]=3 will be the root Node. Also, since arr[1]=arr[2]=0, it implies that the Nodes containing the values value[1]=5 and value[2]=2 will have the Node containing the value value[0]=3 as their parent. Lastly, since arr[3]=arr[4]=2, it means the Nodes containing the values value[3]=1 and value[4]=4 will have the Node with the value value[2]=2 as their parent. Final tree of this example are shown in the figure above.
Note that whichever Node appears first in the arr sequence will be the left Node, and the TestCase always ensures that the resulting tree is a binary tree.
Note: In this exercise, the libraries iostream, queue, stack, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.        */



int sumDigit(BTNode* root,int value) {
    value = (value*10 + root->val)% 27022001;
    if (root->left == nullptr && root->right==nullptr){
        return value;
    }
    
    if (root->left == nullptr){
        return sumDigit(root->right,value);
    }
    else if (root->right == nullptr){
        return sumDigit(root->left,value);
    }
    else {
        return (sumDigit(root->left,value) + sumDigit(root->right,value))%27022001;
    }
}

int sumDigitPath(BTNode* root) {

    return sumDigit(root,0);
}


// Question 5

/*

Given a Binary tree, the task is to count the number of nodes with two children
#include<iostream>
#include<string>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    // STUDENT ANSWER END
};
You can define other functions to help you.     */


int count2(Node *root)
{
    if (root == nullptr) return 0;
    
    if (root->pLeft != nullptr && root->pRight != nullptr){
        return 1 + count2(root->pLeft)+count2(root->pRight);
    }
    else return count2(root->pLeft)+count2(root->pRight);

}
int countTwoChildrenNode()
{
    return count2(root);
}


// Question 6

/*

Given class BinaryTree, you need to finish methods getHeight(), preOrder(), inOrder(), postOrder().
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN 
        
    // STUDENT ANSWER END
};			*/


int height(Node *root){
    if (root == nullptr) return 0;
    return 1 +max(height(root->pLeft),height(root->pRight));
}

int getHeight() {
    return height(root);
    
}
string pre(Node *root){                     //nho luc copy paste các hàm thì nhớ chỉnh in post 
    string b = "";                          //check kĩ các câu pen 5% ngay từ check đầu
    b = b + to_string(root->value)+" ";
    if (root->pLeft != nullptr){
        b = b + pre(root->pLeft);
    }
    if (root->pRight != nullptr){
        b = b + pre(root->pRight);
    }
    return b;
}
string preOrder() {
    return pre(root);
    
}
string in(Node *root){
    string b = "";
    if (root->pLeft != nullptr){
        b = b + in(root->pLeft);
    }
    b = b + to_string(root->value)+" ";
    if (root->pRight != nullptr){
        b = b + in(root->pRight);
    }
    return b;
}
string inOrder() {
    return in(root);
}
string post(Node *root){
    string b = "";
    if (root->pLeft != nullptr){
        b = b + post(root->pLeft);
    }
    if (root->pRight != nullptr){
        b = b + post(root->pRight);
    }
    b = b + to_string(root->value)+" ";
    return b;
}
string postOrder() {
    return post(root);
    
}



// Question 7

/*

Given a Binary tree, the task is to calculate the sum of leaf nodes. (Leaf nodes are nodes which have no children)
#include<iostream>
#include<string>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }
    //Helping functions
    int sumOfLeafs(){
        //TODO
     }
};
You can write other functions to achieve this task.		*/

int sumleaf(Node *root){
    if (root==nullptr) return 0;
    if (root->pLeft==nullptr && root->pRight==nullptr) return root->value;
    else return sumleaf(root->pLeft)+sumleaf(root->pRight);
}
int sumOfLeafs(){
    return sumleaf(root);
    
}


/*--------------------------------------------Sorting---------------------------------*/


// Question 1
/*
Implement static methods Partition and QuickSort in class Sorting to sort an array in ascending order. 
#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static T* Partition(T* start, T* end) ;
public:
    static void QuickSort(T* start, T* end) ;
};
#endif /* SORTING_H */


*/


static T* Partition(T* start, T* end) {
    T* i = start;
    T* j = end;
    T pivot = *start;
    do {
        while((i<j)&&(*(++i)<pivot));
        while((i<j)&&(*(--j) >= pivot));
        
        T temp = *i;
        *i = *j;
        *j = temp;
        
    } while (i<j);
        T temp = *i;
        *i = *j;
        *j = temp;
        
    
        T tmp = *start;
        *start = *(j-1);
        *(j-1) = tmp;
        
       cout<<(int)(j-1-start)<<" ";
    return j;
}
static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if (end <= start) return;
    
    T* spilt = Partition(start,end);
    
    QuickSort(start,spilt-1);
    QuickSort(spilt,end);
}


// Question 2

/*

Implement static methods Merge and MergeSort in class Sorting to sort an array in ascending order. The Merge method has already been defined a call to method printArray so you do not have to call this method again to print your array.
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
        /*TODO*/
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
       /*TODO*/
    }
};
#endif /* SORTING_H */			*/


static void merge(T* left, T* middle, T* right){
    int n = right- left+1;
    T* newarr = new T[n];
    T* l = left;
    T* r = middle;
    for (int i = 0;i<n;i++){
        if (l == middle){
            newarr[i] = *r;
            r++;
        }
        else if (r == right+1){
            newarr[i] = *l;
            l++;
        }
        else{
            if (*l < *r){
                newarr[i] = *l;
                l++;
            }
            else {
                newarr[i] = *r;
                r++;
            }
        }
    }
    for (int i = 0;i<n;i++){
        left[i]=newarr[i];
    }
    delete newarr;
    Sorting::printArray(left, right);
}
static void mergeSort(T* start, T* end){
     if (end-start == 0) return;
    
    int k = (int)(end-start)/2 + 1;
    T *middle = start+k;
    mergeSort(start,middle-1);
    mergeSort(middle,end);
    
    merge(start,middle,end);
}


// Question 3

/*

The best way to sort a singly linked list given the head pointer is probably using merge sort.
Both Merge sort and Insertion sort can be used for linked lists. The slow random-access performance of a linked list makes other algorithms (such as quick sort) perform poorly, and others (such as heap sort) completely impossible. Since worst case time complexity of Merge Sort is O(nLogn) and Insertion sort is O(n^2), merge sort is preferred. 
Additionally, Merge Sort for linked list only requires a small constant amount of auxiliary storage.
To gain a deeper understanding about Merge sort on linked lists, let's implement mergeLists and mergeSortList function below
Constraints:
0 <= list.length <= 10^4
0 <= node.val <= 10^6
Use the nodes in the original list and don't modify ListNode's val attribute. 
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

// Merge two sorted lists
ListNode* mergeSortList(ListNode* head);

// Sort an unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head);
*/


ListNode* mergeLists(ListNode* a, ListNode* b) {
    if (a == nullptr && b == nullptr)
    return nullptr;
    
    ListNode * head = new ListNode(0);
    ListNode * temp = head;
    while (true){
        if (a == nullptr &&  b == nullptr){
            break;
        }
        else if (a == nullptr){
            temp->next = b;
            b = b->next;
            temp = temp->next;
            temp->next = nullptr;
        }
        else if (b == nullptr){
            temp->next = a ;
            a = a->next;
            temp = temp->next;
            temp->next = nullptr;
        }
        else {
            if (a->val < b->val){
                temp->next = a ;
                a = a->next;
                temp = temp->next;
                temp->next = nullptr;
            }
            else {
                temp->next = b;
                b = b->next;
                temp = temp->next;
                temp->next = nullptr;
            }
        }
    }
    temp = head;
    head = head->next;
    delete temp;
    return head;
    
}

// Sort and unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head) {
    if (head->next == nullptr)
    return head;
    
    
    ListNode *temp =head;
    int count = 0;
    while (temp != nullptr){
        count++;
        temp=temp->next;
    }
    int k = count/2-1;
    temp = head;
    while (k != 0){
        k--;
        temp = temp->next;
    }
    ListNode *curr = temp;
    temp = temp->next;
    curr->next = nullptr;
    
    return mergeLists(mergeSortList(head),mergeSortList(temp));
}

// Question 4

/*

Implement static methods merge, InsertionSort and TimSort in class Sorting to sort an array in ascending order. 
merge is responsible for merging two sorted subarrays. It takes three pointers: start, middle, and end, representing the left, middle, and right portions of an array. 
InsertionSort is an implementation of the insertion sort algorithm. It takes two pointers, start and end, and sorts the elements in the range between them in ascending order using the insertion sort technique.
TimSort is an implementation of the TimSort algorithm, a hybrid sorting algorithm that combines insertion sort and merge sort. It takes two pointers, start and end, and an integer min_size, which determines the minimum size of subarrays to be sorted using insertion sort. The function first applies insertion sort to small subarrays, prints the intermediate result, and then performs merge operations to combine sorted subarrays until the entire array is sorted.

#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int  size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }
    static void merge(T* start, T* middle, T* end) ;
public:
    static void InsertionSort(T* start, T* end) ;
    static void TimSort(T* start, T* end, int min_size) ;
};
#endif /* SORTING_H */		*/


static void merge(T* start, T* middle, T* end) {
   int n = end - start;
    T* newarr = new T[n];
    T* l = start;
    T* r = middle;
    for (int i = 0;i<n;i++){
        if (l == middle){
            newarr[i] = *r;
            r++;
        }
        else if (r == end){
            newarr[i] = *l;
            l++;
        }
        else{
            if (*l < *r){
                newarr[i] = *l;
                l++;
            }
            else {
                newarr[i] = *r;
                r++;
            }
        }
    }
    for (int i = 0;i<n;i++){
        start[i]=newarr[i];
    }
    delete newarr;
}

static void InsertionSort(T* start, T* end) {
    int n = end -start;
    for (int i = 1; i<n;i++){
        T temp = start[i];
        int j;
        for (j = i-1; j>=0 && start[j]>temp;j--){
            start[j+1]=start[j];
        }
        start[j+1]=temp;
    }
}

static void TimSort(T* start, T* end, int min_size) {
    int n = end -start;
    T * first = start;
    for (int i = 0;i<n;i += min_size){
        if (i+min_size<n){
            InsertionSort(first,first+min_size);
            first = first +min_size;
        }
        else InsertionSort(first,end);
    }
    cout<<"Insertion Sort: ";
    printArray(start,end);
    
    
    first = start;
    T * after = end;
    int count = 0;
    for (int gap = min_size; gap < n; gap*=2){
        first = start;
        for (int j = 0; j < n; j+=2*gap){
        T* mid = first + gap;
        
        if (j + gap >= n) mid = end - 1;
        
        if (j + 2 * gap < n)
        {after = first + 2 * gap;}
        else after = end ;
       
        merge(first, mid, after);
        cout << "Merge " << ++count << ": ";
        printArray(start,end);
        first += 2 * gap;
        }
    }

            
}


// Question 5

/*

A hotel has m rooms left, there are n people who want to stay in this hotel. You have to distribute the rooms so that as many people as possible will get a room to stay.
However, each person has a desired room size, he/she will accept the room if its size is close enough to the desired room size.
More specifically, if the maximum difference is k, and the desired room size is x, then he or she will accept a room if its size is between x - k and x + k
Determine the maximum number of people who will get a room to stay.

input:
vector<int> rooms: rooms[i] is the size of the ith room
vector<int> people: people[i] the desired room size of the ith person
int k: maximum allowed difference. If the desired room size is x, he or she will accept a room if its size is between x - k and x + k

output:
the maximum number of people who will get a room to stay.

Note: The iostream, vector and algorithm library are already included for you.

Constraints:
1 <= rooms.length, people.length <= 2 * 10^5
0 <= k <= 10^9
1 <= rooms[i], people[i] <= 10^9

Example 1:

Input:
rooms = {57, 45, 80, 65}
people = {30, 60, 75}
k = 5
Output:
2

Explanation:
2 is the maximum amount of people that can stay in this hotel.
There are 3 people and 4 rooms, the first person cannot stay in any room, the second and third person can stay in the first and third room, respectively

Example 2:

Input:
rooms = {59, 5, 65, 15, 42, 81, 58, 96, 50, 1}
people = {18, 59, 71, 65, 97, 83, 80, 68, 92, 67}
k = 1000
Output:
10			*/


int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    
    sort(rooms.begin(),rooms.end());
    sort(people.begin(),people.end());
    int roomIndex=0;
    int peopleIndex=0;
    int res=0;
    while(roomIndex<rooms.size()&&peopleIndex<people.size()){
        int roomSize=rooms[roomIndex];
        int desiredSize=people[peopleIndex];
        if(roomSize>=desiredSize-k&&desiredSize+k>=roomSize){
            res++;
            peopleIndex++;
            roomIndex++;
        }
        else if(roomSize<desiredSize-k){
            roomIndex++;
        }
        else{
            peopleIndex++;
        }
    }
    return res;
}


// Question 6

/*

Given a list of distinct unsorted integers nums.
Your task is to implement a function with following prototype:
int minDiffPairs(int* arr, int n);
This function identify and return all pairs of elements with the smallest absolute difference among them. If there are multiple pairs that meet this criterion, the function should find and return all of them.

Note: Following libraries are included: iostream, string, algorithm, sstream		*/


string minDiffPairs(int* arr, int n){
    string result= "";
    if (n==0) return result;
    sort(arr,arr+n);
    int minimum = arr[1]-arr[0];
    
    for (int i = 0;i<n-1;i++){
        
            int temp = arr[i+1]-arr[i];
            
            if (temp < minimum) minimum = temp;
        
    }
    
    bool first = true;
    for (int i = 0;i<n-1;i++){
            int temp = arr[i+1]-arr[i];
            
            if (temp == minimum) {
                if (first == true){
                result = result+"(" + to_string(arr[i])+", " +to_string(arr[i+1])+")";
                first = false;
                }
                else {
                result = result+", "+"(" + to_string(arr[i])+", " +to_string(arr[i+1])+")";    
                }
            }
        
    }
    return result;
}


// Question 7

/*

Print the elements of an array in the decreasing frequency order while preserving the relative order of the elements.
Students are not allowed to use map/unordered map.
iostream, algorithm libraries are included.      */

void sortByFrequency(int arr[], int n){
    int *temp = new int[n];
    int *frequency = new int[n];
    int k = 0;
    for (int i = 0;i<n;i++){
        if(find(temp,temp+k,arr[i])-temp != k){
            continue;
        }
        else{
            temp[k]=arr[i];
            frequency[k]=count(arr,arr+n,arr[i]);
            k++;
        }
    }

    int i = 0;
    
    while(i<n){
        int max = 0;
        int j = 0;
        for (int k = 0;k<n;k++){
            if (frequency[k] > max) {
                max = frequency[k];
                j = k;
            }
        }
        frequency[j] = 0;
        
        while(max > 0){
            arr[i] = temp[j];
            i++;
            max--;
        }
    }
}


// Question 8
/*

Given a list of points on the 2-D plane (points[] with n elements) and an integer k. Your task in this exercise is to implement the closestKPoints function to find K closest points to the given point (des_point) and print them by descending order of distances.
Prototype of closestKPoints:
void closestKPoints(Point points[], int n, Point& des_point, int k);
Note: The distance between two points on a plane is the Euclidean distance.
Template:
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Point{
   public:
   int x, y;
   Point(int x = 0, int y = 0){
      this->x = x;
      this->y = y;
   }
   void display(){
      cout << "("<<x<<", "<<y<<")";
   }
};		*/

class pot{
    public:
    Point a;
    int distance;
};
bool compare(pot a, pot b){
        return a.distance < b.distance;
    }
void closestKPoints(Point points[], int n, Point &des_point, int k){
    vector<pot> result;
    for (int i=0;i<n;i++){
    result.push_back({points[i],(points[i].x-des_point.x)*(points[i].x-des_point.x)+(points[i].y-des_point.y)*(points[i].y-des_point.y)});
    }
    sort(result.begin(),result.end(),compare);
    for (int i = 0;i<min(k,n);i++){
        result[i].a.display();
        cout<<endl;
    }
}


