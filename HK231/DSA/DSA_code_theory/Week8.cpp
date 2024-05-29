// Question 1

/*
Based on class List defined on page 98 to implement a min heap used for heap sort, write function template <typename E> void reheapDown(List<E> &L, int heapsize, int startpos).
reheapDown: the element at the startpos is compared to its children and swapped with the smaller child if it is greater than the smaller child. This process is repeated until it is smaller or equal to the smaller child or it is put in the leaf.
Your code starts from line 79.    */

template <typename E> 
void reheapDown(List<E> &L, int heapsize, int startpos){
    if (heapsize > L.length()) throw std::out_of_range("Heap size cannot be greater than the length of the list");
    
    while(startpos < heapsize){
    L.moveToPos(startpos);
    E start = L.getValue();
    int child1 = startpos*2 + 1;
    int child2 = startpos*2 + 2;
    if (child1 >= heapsize && child2 >= heapsize){
        return;
    }
    else if (child2 >= heapsize && child1 < heapsize){
        L.moveToPos(child1);
        E valuechild1 = L.getValue();
        if (start > valuechild1){
            L.remove();
            //L.prev();
            L.insert(start);
            L.moveToPos(startpos);
            L.remove();
           // L.prev();
            L.insert(valuechild1);
            startpos = child1;
        }
        else{
            break;
        }
        
    }
    else if (child1 >= heapsize && child2 < heapsize){
        L.moveToPos(child2);
        E valuechild2 = L.getValue();
        if (start > valuechild2){
            L.remove();
            //L.prev();
            L.insert(start);
            L.moveToPos(startpos);
            L.remove();
            //L.prev();
            L.insert(valuechild2);
            startpos = child2;
        }
        else{
            break;
        }
        
    }
    else if (child1 < heapsize && child2 < heapsize){
        L.moveToPos(child1);
        E valuechild1 = L.getValue();
        L.moveToPos(child2);
        E valuechild2 = L.getValue();
        if (valuechild2 <valuechild1)
        {
            child1 = child2;
            valuechild1 = valuechild2;
        }
        L.moveToPos(child1);
        if (start > valuechild1){
            L.remove();
            //L.prev();
            L.insert(start);
            L.moveToPos(startpos);
            L.remove();
            //L.prev();
            L.insert(valuechild1);
            startpos = child1;
        }
        else{
            break;
        }
        
    }
    
    }
}



// Question 2

/*

Based on class List defined on page 98 to implement function  template <typename E> void makeHeap(List<E> &L) which makes the list L become a min heap. Function template <typename E> void reheapDown(List<E> &L, int heapsize, int startpos) is given for your convenience.
Your code starts from line 120.   */


template <typename E> 
void makeHeap(List<E> &L) {
    int max = L.length()-1;
    //int i = 1;
    while(max>=0){
    reheapDown(L,L.length(),max);
    max--;
    }    
}


// Question 3

/*
Based on class List defined on page 98, write function template <typename E> void heapSort(List<E> &L) to sort the list L in descending order. Functions template <typename E> void makeHeap(List<E> &L) and template <typename E> void reheapDown(List<E> &L, int heapsize, int startpos) are provided for your convenience.
Your code starts from line 79.   */

template <typename E> 
void heapSort(List<E> &L){
    makeHeap(L);
    
    int end = L.length()-1;
    while(end>0){
        L.moveToStart();
        E x1 = L.getValue();
        L.moveToPos(end);
        E x2 =L.getValue();
        L.remove();
        L.insert(x1);
        L.moveToStart();
        L.remove();
        L.insert(x2);
        reheapDown(L,end,0);
        end--;
        
    }
    
}

// Question 4

/*
Given the data structures of a binary search tree as follows:
template <typename E>
class BNode {
public:
E key;
BNode<E>* left;
BNode<E>* right;
        BNode(E v,BNode<E>* l = NULL,BNode<E>* r=NULL):key(v),left(l),right(r){}
}
and 
template <typename E>
class BST {
private:
BNode<E>* root;
public:
       BST(BNode<E> r):root(r){};
}
Write method void printGreatestSmaller(E key) for class BST to print in the greatest keys v of  a node in the BST such that v < key
Your code starts at line 24.    */

void printGreatestSmaller(E key){
    BNode<E> *curr = nullptr;
    BNode<E> *temp = root;
    while (temp != nullptr ){
        if (temp->key < key){
            if(curr == nullptr){
                curr = temp;
            }
            else{
                if (temp->key > curr->key){
                    curr = temp;
                }
            }
        }
        
        if (key>temp->key)
        temp = temp->right;
        else temp = temp->left;
    }
    if (curr != nullptr) cout<<curr->key;
}


// Question 5

/*
Write function LargestSmaller to print the largest key in the binary search tree from root travel which is smaller than the input key? The prototype of the function is as follows:
template <typename E>
void LargestSmaller(BNode<E> * root, E key);
where BNode is defined in lecture slides.
Your code starts at line 40.   */


template <typename E>
void LargestSmaller(BNode<E> * root, E key){
    BNode<E> *curr = nullptr;
    BNode<E> *temp = root;
    while (temp != nullptr ){
        if (temp->element() < key){
            if(curr == nullptr){
                curr = temp;
            }
            else{
                if (temp->element() > curr->element()){
                    curr = temp;
                }
            }
        }
        
        if (key>temp->element())
        temp = temp->right();
        else temp = temp->left();
    }
    if (curr != nullptr) cout<<curr->element();
}