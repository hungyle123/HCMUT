// Question 1

/*
Write function count to return the number of nodes in a binary tree? The prototype of the function is as follows:
template <typename E>
int count(BNode<E> * root);
where BNode is defined in lecture slides.
Your code starts at line 40.   */


template <typename E>
int count(BNode<E> * root){
    if (root == nullptr) return 0;
    else return 1 + count(root->left()) + count(root->right());
}


// Question 2

/*
Write function height to return the height of a binary tree? The prototype of the function is as follows:
template <typename E>
int height(BNode<E> * root);
where BNode is defined in lecture slides.
Your code starts at line 40.    */

template <typename E>
int height(BNode<E> * root){
    if (root == nullptr) return 0;
    return 1 + max(height(root->left()),height(root->right()));
}


// Question 3

/*
Write function BSTsearch to look up a value val in the binary search tree root and return the node of the binary search tree whose value is the searching key val? This function returns NULL if there is no node whose value is val. The function also prints the value (followed by a comma) in the BST compared to the searching key val during the searching process. Your code starts at line 48. The prototype of the function is as follows:
template <typename E>
BNode<E>* BSTsearch(BNode<E> * root,E val);
where BNode is defined in lecture slides.
Your code starts at line 50.   */

template <typename E>
BNode<E>* BSTsearch(BNode<E> * root,E val){
    if (root == nullptr ) return nullptr;

    else{
        if (root->element() > val){
            cout<<root->element()<<",";
            return BSTsearch(root->left(),val);
        }
        else if (root->element()<val){
            cout<<root->element()<<",";
            return BSTsearch(root->right(),val);
        }
        else {
            cout<<root->element()<<",";
            return root;
        }
    }
    return nullptr;
}


// Question 4

/*
Write function LNRtraversal to travel in LNR manner on a binary tree root to conduct function f for each traversed node? The prototype of the function is as follows:
template <typename E>
void LNRtraversal(BNode<E> * root, void (*f)(E));
where BNode is defined in lecture slides.
Your code starts at line 40.   */


template <typename E>
void LNRtraversal(BNode<E> * root, void (*f)(E)){
    if (root == nullptr) return;
    LNRtraversal(root->left(),f);
    f(root->element());
    LNRtraversal(root->right(),f);
}


// Question 5

/*

Write function BFtraversal to travel on a binary tree root in breadth-first manner to conduct function f for each traversed node? Class Queue with concrete class LQueue and class Stack with concrete class AStack have been provided for your convenience. Your code starts at line 195. The prototype of the function is as follows:
template <typename E>
void BFtraversal(BNode<E> * root, void (*f)(E));
where BNode is defined in lecture slides.
Your code starts at line 200.    */

template <typename E>
void BFtraversal(BNode<E> * root, void (*f)(E)){
    if (root == nullptr) return;
    Queue<BNode<E>*> * qu = new LQueue<BNode<E>*>;
    qu->enqueue(root);
    while(qu->length()!= 0){
        BNode<E>* temp = qu->dequeue();
            f(temp->element());

           
           if (temp->left() != nullptr) {
               qu->enqueue(temp->left());
           }

           
           if (temp->right() != nullptr) {
               qu->enqueue(temp->right());
           }
    }
    delete qu;
}


// Question 6

/*
Write function BSTinsert to insert a new node into the binary search tree root and return the root of the binary search tree with new node added? Your code starts at line 48. The prototype of the function is as follows:
template <typename E>
BNode<E>* BSTinsert(BNode<E> * root,E val);
where BNode is defined in lecture slides.
Your code starts at line 50.   */


template <typename E>
BNode<E>* BSTinsert(BNode<E> * root,E val){
    if (root == nullptr) return new BNode<E>(val);
    BNode<E>*temp = root;
    BNode<E>*prev = nullptr;
    while(temp != nullptr){
        if (temp->element()<=val){
            prev = temp;
            temp = temp->right();
        }
        else {
            prev = temp;
            temp = temp->left();
        }
    }
    if (prev->element()<=val){
            prev->setRight(new BNode<E>(val));
        }
    else {
            prev->setLeft(new BNode<E>(val));
        }
    return root;
}


// Question 7

/*
Write function BSTdelete to delete the first node of the binary search tree root whose value is val and return the root of the binary search tree with the node deleted? If there is no node whose value is val, the root of the current BST is returned. Your code starts at line 48. The prototype of the function is as follows:
template <typename E>
BNode<E>* BSTdelete(BNode<E> * root,E val);
where BNode is defined in lecture slides.
Your code starts at line 50.     */

template <typename E>
BNode<E>* BSTdelete(BNode<E> * root,E val){
    if (root == nullptr) return root;
    
    BNode<E>*temp = root;
    BNode<E>*prev = nullptr;
    while(temp != nullptr){
        if (temp->element()<val){
            prev = temp;
            temp = temp->right();
        }
        else if (temp->element()>val) {
            prev = temp;
            temp = temp->left();
        }
        else {
            break;
        }
    }
    if (temp == nullptr) return root;
    else{
        if (temp->isLeaf()){
            delete temp;
            if (prev == nullptr) return nullptr;
            
            if (prev->element()<val){
            prev->setRight(nullptr);
            }
            else if (prev->element()>val) {
            prev->setLeft(nullptr);
            }
            return root;
        }
        else if (temp->right() == nullptr){
            if (prev->element()<val){
            prev->setRight(temp->left());
            }
            else if (prev->element()>val) {
            prev->setLeft(temp->left());
            }
            return root;
        }
        BNode<E>* leftmost = temp->right();
        BNode<E>* prev2 = temp;
        while (leftmost->left()!= nullptr){
            prev2 = leftmost;
            leftmost = leftmost->left();
        }
        temp->setElement(leftmost->element());
        if(leftmost->isLeaf()){
            delete leftmost;
            if (prev2 == temp){
                temp->setRight(nullptr);
            }
            else{prev2->setLeft(nullptr);}
            return root;
        }
        else{
            leftmost->setElement(leftmost->right()->element());
            delete leftmost->right();
            leftmost->setRight(nullptr);
            return root;
        }
    }
}


// Question 8

/*
Write function isBST to check if the binary tree root is a binary search tree or not? Note an empty binary tree is not a BST. The prototype of the function is as follows:
template <typename E>
bool isBST(BNode<E> * root);
where BNode is defined in lecture slides.
Your code starts at line 40.    */

template <typename E>
bool isBST(BNode<E> * root){
    if (root == nullptr) return false;
    
    /* false if the max of the left is > than us */
    if (root->left() != nullptr && maxValue(root->left()) >= root->element())
        return false;
 
    /* false if the min of the right is <= than us */
    if (root->right() != nullptr && minValue(root->right()) < root->element())
        return false;
 
    /* false if, recursively, the left or right is not a BST
     */
    if (root->left() != nullptr && !isBST(root->left()))
        return false;
    if (root->right() != nullptr && !isBST(root->right()))
        return false;
    
 
    /* passing all that, it's a BST */
    return true;
}
template <typename E>
E maxValue(BNode<E> * root)
{
    
    E value = root->element();
    if (root->left()==nullptr && root->right()==nullptr)
    return value;
    if (root->left()!=nullptr && root->right()==nullptr){
    E leftMax = maxValue(root->left());
    return max(value,leftMax);
    }
    if (root->left()==nullptr && root->right()!=nullptr){
    E rightMax = maxValue(root->right());
    return max(value,rightMax);
    }
    E leftMax = maxValue(root->left());
    E rightMax = maxValue(root->right());
    return max(value, max(leftMax, rightMax));
}
template <typename E> 
E  minValue(BNode<E> * root)
{
    E value = root->element();
    if (root->left()==nullptr && root->right()==nullptr)
    return value;
    if (root->left()!=nullptr && root->right()==nullptr){
    E leftmin = minValue(root->left());
    return min(value,leftmin);
    }
    if (root->left()==nullptr && root->right()!=nullptr){
    E rightmin = minValue(root->right());
    return min(value,rightmin);
    }
    E leftmin = minValue(root->left());
    E rightmin = minValue(root->right());
    return min(value, min(leftmin, rightmin));
}