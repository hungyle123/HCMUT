// Question 1

/*

In this question, you have to perform rotate nodes on AVL tree. Note that:
- When adding a node which has the same value as parent node, add it in the right sub tree.
Your task is to implement function: rotateRight, rotateLeft. You could define one or more functions to achieve this task.
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void insert(const T &value);
int getBalance(Node*subroot){
    if(!subroot) return 0;
    return getHeightRec(subroot->pLeft)- getHeightRec(subroot->pRight);
}
Node* rotateLeft(Node* subroot)
{
//TODO: Rotate and return new root after rotate
};
Node* rotateRight(Node* subroot)
{
//TODO: Rotate and return new root after rotate
};

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};			*/


Node* rotateRight(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* left = root->pLeft;
    Node* leftr = left->pRight;
    
    left->pRight = root;
    root->pLeft = leftr;
    return left;
}

Node* rotateLeft(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* right = root->pRight;
    Node* rightl = right->pLeft;
    
    right->pLeft = root;
    root->pRight = rightl;
    return right;
}



// Question 2

/*

In this question, you have to perform add on AVL tree. Note that:
- When adding a node which has the same value as parent node, add it in the right sub tree.
Your task is to implement function: insert. The function should cover at least these cases:
+ Balanced tree
+ Left of left unbalanced tree
+ Right of left unbalanced tree
You could define one or more functions to achieve this task.
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void insert(const T &value)
    {
        //TODO
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};			*/

Node* rotateRight(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* left = root->pLeft;
    Node* leftr = left->pRight;
    
    left->pRight = root;
    root->pLeft = leftr;
    return left;
}

Node* rotateLeft(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* right = root->pRight;
    Node* rightl = right->pLeft;
    
    right->pLeft = root;
    root->pRight = rightl;
    return right;
}
Node* insertNode(Node* root, const T &value){ 
    //TODO 
    if (root == nullptr) { 
        Node*newNode = new Node(value); 
        return newNode; 
    }
    else if (root->data > value) 
        root->pLeft = insertNode(root->pLeft, value); 
    else if (root->data <= value) 
        root->pRight = insertNode(root->pRight, value); 
    
    int balance = getBalance(root); 
    
    if (balance > 1 && value < root->pLeft->data) 
        return rotateRight(root); 
    if (balance < -1 && value > root->pRight->data) 
        return rotateLeft(root); 
    if (balance > 1 && value > root->pLeft->data) { 
        root->pLeft = rotateLeft(root->pLeft); 
        return rotateRight(root); 
    }
    if (balance < -1 && value < root->pRight->data) {
        root->pRight = rotateRight(root->pRight); 
        return rotateLeft(root); 
    }
    return root; 
}
int getBalance(Node *N) { 
    if (N == nullptr) return 0; 
    return this->getHeightRec(N->pLeft) - this->getHeightRec(N->pRight); 
    
}
void insert(const T &value){ 
    //TODO 
    this->root = insertNode(this->root, value); 
}


// Question 3


/*

In this question, you have to perform add on AVL tree. Note that:
When adding a node which has the same value as parent node, add it in the right sub tree.
Your task is to implement function: insert. The function should cover at least these cases:
Balanced tree
Right of right unbalanced tree
Left of right unbalanced tree
You could define one or more functions to achieve this task.
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void insert(const T &value)
    {
        //TODO
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};

*/


Node* rotateRight(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* left = root->pLeft;
    Node* leftr = left->pRight;
    
    left->pRight = root;
    root->pLeft = leftr;
    return left;
}

Node* rotateLeft(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* right = root->pRight;
    Node* rightl = right->pLeft;
    
    right->pLeft = root;
    root->pRight = rightl;
    return right;
}
Node* insertNode(Node* root, const T &value){ 
    //TODO 
    if (root == nullptr) { 
        Node*newNode = new Node(value); 
        return newNode; 
    }
    else if (root->data > value) 
        root->pLeft = insertNode(root->pLeft, value); 
    else if (root->data <= value) 
        root->pRight = insertNode(root->pRight, value); 
    
    int balance = getBalance(root); 
    
    if (balance > 1 && value < root->pLeft->data) 
        return rotateRight(root); 
    if (balance < -1 && value > root->pRight->data) 
        return rotateLeft(root); 
    if (balance > 1 && value > root->pLeft->data) { 
        root->pLeft = rotateLeft(root->pLeft); 
        return rotateRight(root); 
    }
    if (balance < -1 && value < root->pRight->data) {
        root->pRight = rotateRight(root->pRight); 
        return rotateLeft(root); 
    }
    return root; 
}
int getBalance(Node *N) { 
    if (N == nullptr) return 0; 
    return this->getHeightRec(N->pLeft) - this->getHeightRec(N->pRight); 
    
}
void insert(const T &value){ 
    //TODO 
    this->root = insertNode(this->root, value); 
}


// Question 4

/*

In this question, you have to perform add on AVL tree. Note that:
- When adding a node which has the same value as parent node, add it in the right sub tree.
Your task is to implement function: insert. You could define one or more functions to achieve this task.
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void insert(const T &value)
    {
        //TODO
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};			*/


Node* rotateRight(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* left = root->pLeft;
    Node* leftr = left->pRight;
    
    left->pRight = root;
    root->pLeft = leftr;
    return left;
}

Node* rotateLeft(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* right = root->pRight;
    Node* rightl = right->pLeft;
    
    right->pLeft = root;
    root->pRight = rightl;
    return right;
}
Node* insertNode(Node* root, const T &value){ 
    //TODO 
    if (root == nullptr) { 
        Node*newNode = new Node(value); 
        return newNode; 
    }
    else if (root->data > value) 
        root->pLeft = insertNode(root->pLeft, value); 
    else if (root->data <= value) 
        root->pRight = insertNode(root->pRight, value); 
    
    int balance = getBalance(root); 
    
    if (balance > 1 && value < root->pLeft->data) 
        return rotateRight(root); 
    if (balance < -1 && value >= root->pRight->data) 
        return rotateLeft(root); 
    if (balance > 1 && value >= root->pLeft->data) { 
        root->pLeft = rotateLeft(root->pLeft); 
        return rotateRight(root); 
    }
    if (balance < -1 && value < root->pRight->data) {
        root->pRight = rotateRight(root->pRight); 
        return rotateLeft(root); 
    }
    return root; 
}
int getBalance(Node *N) { 
    if (N == nullptr) return 0; 
    return this->getHeightRec(N->pLeft) - this->getHeightRec(N->pRight); 
    
}
void insert(const T &value){ 
    //TODO 
    this->root = insertNode(this->root, value); 
}


// Question 5

/*

In this question, you have to perform delete in AVL tree - balanced, L-L, R-L, E-L. Note that: 
- Provided insert function already.
Your task is to implement function: remove to perform re-balancing (balanced, left of left, right of left, equal of left). You could define one or more functions to achieve this task.
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void remove(const T &value)
    {
        //TODO
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};			*/


int getBalance(Node *N) { 
    if (N == nullptr) return 0; 
    return this->getHeightRec(N->pLeft) - this->getHeightRec(N->pRight); 
    
}
Node * maxValueNode(Node* node) 
{ 
    Node* current = node; 
 
    /* loop down to find the leftmost leaf */
    while (current->pRight != nullptr) 
        current = current->pRight; 
 
    return current; 
}
Node* deleteNode(Node* root, T key) 
{ 
    if (root == NULL) 
        return root; 

    // in left subtree 
    if ( key < root->data ) 
        root->pLeft = deleteNode(root->pLeft, key); 
 
    // in right subtree 
    else if( key > root->data ) 
        root->pRight = deleteNode(root->pRight, key); 
 
    else
    { 
        // node with only one child or no child 
        if( (root->pLeft == nullptr) ||
            (root->pRight == nullptr) ) 
        { 
            Node *temp = root->pLeft ? root->pLeft : root->pRight; 
 
            // No child case 
            if (temp == nullptr) 
            { 
                temp = root; 
                root = nullptr; 
            } 
            else // One child case 
            *root = *temp; 
            delete temp;
        } 
        else
        { 
            Node* temp = maxValueNode(root->pLeft); 
            root->data = temp->data; 
            root->pLeft = deleteNode(root->pLeft, 
                                     temp->data); 
        } 
    } 

    if (root == nullptr) 
    return root; 
 
    int balance = getBalance(root); 
 
    if (balance > 1 && getBalance(root->pLeft) >= 0) 
        return rotateRight(root); 
 
    if (balance > 1 && getBalance(root->pLeft) < 0) 
    { 
        root->pLeft = rotateLeft(root->pLeft); 
        return rotateRight(root); 
    } 
 
    // Right Right Case 
    if (balance < -1 && getBalance(root->pRight) <= 0) 
        return rotateLeft(root); 
 
    // Right Left Case 
    if (balance < -1 && getBalance(root->pRight) > 0) 
    { 
        root->pRight = rotateRight(root->pRight); 
        return rotateLeft(root); 
    } 
 
    return root; 
} 
void remove(const T &value){
   root = deleteNode(root,value);
    
}


// Question 6

/*

In this question, you have to perform delete on AVL tree. Note that: 
- Provided insert function already.
Your task is to implement two functions: remove. You could define one or more functions to achieve this task.
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void remove(const T &value)
    {
        //TODO
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};			*/

int getBalance(Node *N) { 
    if (N == nullptr) return 0; 
    return this->getHeightRec(N->pLeft) - this->getHeightRec(N->pRight); 
    
}
Node * maxValueNode(Node* node) 
{ 
    Node* current = node; 
 
    /* loop down to find the leftmost leaf */
    while (current->pRight != nullptr) 
        current = current->pRight; 
 
    return current; 
}
Node* deleteNode(Node* root, T key) 
{ 
    if (root == NULL) 
        return root; 

    // in left subtree 
    if ( key < root->data ) 
        root->pLeft = deleteNode(root->pLeft, key); 
 
    // in right subtree 
    else if( key > root->data ) 
        root->pRight = deleteNode(root->pRight, key); 
 
    else
    { 
        // node with only one child or no child 
        if( (root->pLeft == nullptr) ||
            (root->pRight == nullptr) ) 
        { 
            Node *temp = root->pLeft ? root->pLeft : root->pRight; 
 
            // No child case 
            if (temp == nullptr) 
            { 
                temp = root; 
                root = nullptr; 
            } 
            else // One child case 
            *root = *temp; 
            delete temp;
        } 
        else
        { 
            Node* temp = maxValueNode(root->pLeft); 
            root->data = temp->data; 
            root->pLeft = deleteNode(root->pLeft, 
                                     temp->data); 
        } 
    } 

    if (root == nullptr) 
    return root; 
 
    int balance = getBalance(root); 
 
    if (balance > 1 && getBalance(root->pLeft) >= 0) 
        return rotateRight(root); 
 
    if (balance > 1 && getBalance(root->pLeft) < 0) 
    { 
        root->pLeft = rotateLeft(root->pLeft); 
        return rotateRight(root); 
    } 
 
    // Right Right Case 
    if (balance < -1 && getBalance(root->pRight) <= 0) 
        return rotateLeft(root); 
 
    // Right Left Case 
    if (balance < -1 && getBalance(root->pRight) > 0) 
    { 
        root->pRight = rotateRight(root->pRight); 
        return rotateLeft(root); 
    } 
 
    return root; 
} 
void remove(const T &value){
   root = deleteNode(root,value);
    
}


// Question 7

/*

In this question, you have to search and print inorder on AVL tree. You have o implement functions: search and printInorder to complete the task. Note that:
- When the tree is null, don't print anything. 
- There's a whitespace at the end when print the tree inorder in case the tree is not null.
- When tree contains value, search return true.
#include <iostream>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}

    void printInorder(){
        //TODO
    }

    bool search(const T &value){
        //TODO
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};			*/

void printinorder(Node *root){
    if (root == nullptr) return;
    
    if (root->pLeft != nullptr) {
        printinorder(root->pLeft);
    }
    cout << root->data << " ";
    if (root->pRight != nullptr) {
        printinorder(root->pRight);
    }
}
void printInorder(){
    //TODO
    printinorder(root);
} 
bool search(const T &value){
    //TODO
    Node* ptr = root;
    while (true) {
        if (ptr == nullptr) return false;
        if (ptr->data == value) return true;
        else {
            if (value > ptr->data)
                ptr = ptr->pRight;
            if (value < ptr->data)
        ptr = ptr->pLeft;
        }
    }
}