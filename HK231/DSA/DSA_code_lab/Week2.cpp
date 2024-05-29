/*-----------------------------------------------Doubly_linlist--------------------------------*/

// Question 1

/*

Implement methods add, size in template class DLinkedList (which implements List ADT) representing the doubly linked list with type T with the initialized frame. The description of each method is given in the code.
template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};
In this exercise, we have include <iostream>, <string>, <sstream> and using namespace std.  */


template <class T>
void DLinkedList<T>::add(const T& e) {
    if (head == NULL && tail == NULL){
        Node * newnode = new Node(e);
        head = tail = newnode;
        count=1;
        return;
        
    }
    Node * newnode = new Node(e);
    newnode->previous = this->tail;
    tail->next = newnode;
    tail = newnode;
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    if (index <0 || index > this->count ) return;
    if (index ==0){
        if (head == NULL && tail==NULL)
        {
            Node * newnode = new Node(e);
            head = tail = newnode;
            count=1;
            return;
        }
        else {
            Node * newnode = new Node(e);
            newnode->next = head;
            head->previous = newnode;
            head = newnode;
            count++;
            return;
        }
    }
    if(index==count){
        this->add(e);
        return;
    }
    
    Node * temp = head;
    for (int i =0;i<index-1;i++){
        temp=temp->next;
    }
    Node * newnode = new Node(e);
    newnode->next = temp->next;
    temp->next->previous = newnode;
    temp->next = newnode;
    newnode->previous = temp;
    count++;
}

template<class T>
int DLinkedList<T>::size() {
    return this->count; 
}


// Question 2

/*
Implement methods get, set, empty, indexOf, contains in template class DLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};
In this exercise, we have include <iostream>, <string>, <sstream> and using namespace std.	*/


template<class T>
T DLinkedList<T>::get(int index) {
    Node * temp = head;
    while (index>0){
        temp=temp->next;
        index--;
    }
    return temp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    Node * temp = head;
    while (index>0){
        temp=temp->next;
        index--;
    }
    temp->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    if (head == NULL) return true;
    return false;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    int i =0;
    Node * temp = head;
    while (temp!= NULL){
        if (temp->data == item)
        return i;
         
        i++;
        temp=temp->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    Node * temp = head;
    while (temp!= NULL){
        if (temp->data == item)
        return true;
        temp=temp->next;
    }
    return false;
    
}



// Question 3

/*

Implement Iterator class in class DLinkedList. 
Note: Iterator is a concept of repetitive elements on sequence structures. Iterator is implemented in class vector, list in STL container in C++ (https://www.geeksforgeeks.org/iterators-c-stl/). Your task is to implement the simple same class with iterator in C++ STL container.
template <class T>
class DLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;
        
        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};
Please read example carefully to see how we use the iterator.    */


/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
{
    this->pList = pList;
        if (begin == true){
            if (this->pList != NULL){
                this->current = this->pList->head;
                this->index = 0;
            }
            else {
                this->current = NULL;
                this->index = -1;
            }
        }
        else {
            this->current = NULL;
            if (this->pList==NULL) this->index = 0;
            else this->index = this->pList->size();
        }
}

template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (this->current == NULL)
        throw std::out_of_range("Segmentation fault!");
    this->current->data = e;
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
    if (this->current == NULL)
        throw std::out_of_range("Segmentation fault!");
    return this->current->data;
}

template<class T>
void DLinkedList<T>::Iterator::remove() 
{
    /*
    * TODO: delete Node in pList which Node* current point to. 
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
    
    Node* curr = this->pList->head;
    if (this->current==this->pList->head) {

        this->index = -1;
        this->pList->count--;
        Node *temp = this->pList->head;
        this->pList->head = this->pList->head->next;
        
        if (this->pList->head) this->pList->head->previous = NULL;
        else this->pList->tail = NULL;
        delete temp;
        
        this->current = NULL;
        // this->current = new Node();
        // this->current->next = this->pList->head;
        // if (this->pList->head) this->pList->head->previous = this->current;
        return;
    }
    else {
        while ( curr->next != this->current) curr = curr->next;
        Node* temp = curr->next;
        this->current->next->previous = curr;
        curr->next = this->current->next;
        
        this->current = curr;
        this->index = this->index - 1;
        
        
        if (temp==this->pList->tail) {
            this->pList->tail = curr;
        }    
            
        this->pList->count--;
        
        delete temp;
    }
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
    if (this->index == iterator.index && this->current == iterator.current) return false;
    return true;
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
    if (this->index == -1){
        this->index++;
        this->current = this->pList->head;
        return *this;
    }
    
    this->current =this-> current->next;
    this->index++;
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
    if (this->index == -1){
        Iterator tmp = *this;
        this->index++;
        this->current = this->pList->head;
        return tmp;
    }
    Iterator tmp = *this;
    this->current = this->current->next;
    this->index++;
    
    return tmp;
}


// Question 4

/*

Implement methods removeAt, removeItem, clear in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item); 
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};
In this exercise, we have include <iostream>, <string>, <sstream> and using namespace std.   */


template <class T>
T DLinkedList<T>::removeAt(int index)
{
    if (index == 0){
        Node *temp = head;
        head = head->next;
        if (head) 
        head->previous = NULL;
        else tail = NULL;
        T a = temp->data;
        delete temp;
        count--;
        return a;
    }
    else if (index == count -1 ){
        Node *temp = tail;
        tail = tail->previous;
        if (tail)
        tail->next = NULL;
        else (head == NULL);
        T a = temp->data;
        delete temp;
        count--;
        return a;
    }
    else {
        Node *temp = head;
        while (index>1){
            temp=temp->next;
            index--;
        }
        Node *dele = temp->next;
        dele->next->previous=temp;
        temp->next=dele->next;
        T a = dele->data;
        delete dele;
        count--;
        return a;
    }
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    Node *temp = head;
    int i = 0;
    while (temp!=NULL){
        if (temp->data == item){
            this->removeAt(i);
            return true;
        }
        else {
            i++;
            temp = temp->next;
        }
    }
    return false;
    
}

template<class T>
void DLinkedList<T>::clear(){
    while (count != 0){
        this->removeAt(0);
    }
}


// Question 5

/*

In this exercise, we will use Standard Template Library List (click open in other tab to show more) to implement a Data Log. 
This is a simple implementation in applications using undo and redo. For example in Microsoft Word, you must have nodes to store states when Ctrl Z or Ctrl Shift Z to go back or forward.
DataLog has a doubly linked list to store the states of data (an integer) and iterator to mark the current state. Each state is stored in a node, the transition of states is depicted in the figure below. 
Your task in this exercise is implement functions marked with /*  * TODO   */.
class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }
    
    void printLog()
    {      
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};
Note: Normally, when we say a List, we talk about doubly linked list. For implementing a singly linked list, we use forward list.
We have include <iostream> <list> and using namespace std;  */

DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
    logList.push_back(0);
    currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
    logList.push_back(data);
    currentState = logList.begin();
}

void DataLog::addCurrentState(int number)
{
    /*
     * TODO: Increase the value of current state by number
     */
    *currentState = *currentState + number;
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
     *currentState = *currentState - number;
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the 
     *       currentState Iterator, we delete them all before creating a new state.
     */
    while (currentState != prev(logList.end(),1)){
        logList.pop_back();
    }
    logList.push_back(*currentState);
    currentState++; 
}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
    if (currentState != logList.begin())
    currentState--;
     
}

void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
     if (currentState != prev(logList.end(),1))
    currentState++;
}

// Question 6

/*

Given the head of a doubly linked list, two positive integer a and b where a <= b. Reverse the nodes of the list from position a to position b and return the reversed list

Note: the position of the first node is 1. It is guaranteed that a and b are valid positions. You MUST NOT change the val attribute in each node.

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

Constraint:
1 <= list.length <= 10^5
0 <= node.val <= 5000
1 <= left <= right <= list.length

Example 1:
Input: list = {3, 4, 5, 6, 7} , a = 2, b = 4
Output: 3 6 5 4 7

Example 2:
Input: list = {8, 9, 10}, a = 1, b = 3
Output: 10 9 8
*/

/*
struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};
*/
void reverseoriginal(ListNode* tmpA,ListNode* tmpB){
    //first reverse
    ListNode* prev = NULL;
    ListNode* curr =tmpA;
    ListNode* next =tmpA->right;
    
    while (curr != NULL){
        next =curr->right;
        curr->right=prev;
        prev = curr;
        curr = next;
    }
    
    
    //second reverse
    
    prev = NULL;
    curr =tmpB;
    next =tmpB->left;
    
    while (curr != NULL){
        next =curr->left;
        curr->left=prev;
        prev = curr;
        curr = next;
    }
    return; 
}
ListNode* reverse(ListNode* head, int a, int b) {
    if(a==b) return head;
    
    int i = 1;
    ListNode* tmpA = head;
    
    while(i != a){
        tmpA = tmpA->right;
        i++;
    }
    
    int j = i;
    ListNode* tmpB = tmpA;
    
    while(j!=b){
        tmpB = tmpB->right;
        j++;
    }
    if (a == 1){
        reverseoriginal(tmpA,tmpB);
        return tmpB;
    }
    
    ListNode* tmpL = tmpA->left;
    ListNode* tmpR = tmpB->right;
    
    if(tmpA->left != nullptr) tmpA->left->right = nullptr;
    if(tmpB->right !=nullptr) tmpB->right->left = nullptr;
    
    tmpA->left = nullptr;
    tmpB->right = nullptr;

    reverseoriginal(tmpA,tmpB);
    
    tmpL->right = tmpB;
    tmpB->left = tmpL;
    
    tmpR->left = tmpA;
    tmpA->right = tmpR;
    
    return head;
}


/*----------------------------------------------Queue----------------------------------*/


// Question 1
/*

[Eng] Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.
Your task is to implement interleaveQueue function.
stack and queue are included.
[Vie] Cho 1 hàng đợi có số lượng phần tử là số chẵn, sắp xếp lại các phần tử theo quy tắc xen kẽ phần tử ở nửa đầu và nửa sau của hàng đợi.
Sinh viên cần hiện thực hàm interleaveQueue.
Thư viện stack và queue đã được thêm vào.     */


void interleaveQueue(queue<int>& q){
    queue<int> q1;
    queue<int> q2;
    int n = q.size();
    for (int i =0;i<n/2;i++){
        q1.push(q.front());
        q.pop();
    }
    for (int i =0;i<n/2;i++){
        q2.push(q.front());
        q.pop();
    }
    for (int i =0;i<n/2;i++){
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
}


// Question 2

/*

Research queue which is implemented in C library at http://www.cplusplus.com/reference/queue/queue/. You can use library queue in c++ for this question.
Using queue, complete function bool isBipartite(vector<vector<int>> graph) to determine if a graph is bipartite or not (the graph can be disconnected). In caat https://en.wikipedia.org/wiki/Bipartite_graph.
You can use below liberaries in this question.
#include <iostream>
#include <vector>
#include <queue>      */


bool isBipartite(vector<vector<int>> graph) {
    
    int vertex = graph.size();
    // if (vertex <= 1) return false;
    
    int** G = new int*[vertex];
    for (int i = 0;i<vertex;i++){
        G[i] = new int[vertex];
    }
    
    for (int i = 0;i<vertex;i++){
        for (int j = 0;j<vertex;j++){
            G[i][j]=0;}}
    for (int i = 0;i<vertex;i++){
        vector<int> temp = graph[i];
      
        for (int j = 0;j<vertex;j++){
            if (temp.size()==0) break;
            int a = temp.front();
            temp.erase(temp.begin());
            G[i][a] = 1;

        }
    }
    
    int * colorArr = new int[vertex];
    for (int i = 0; i < vertex; ++i)
        colorArr[i] = -1;
        
    int i =0;
while(i<vertex){ 
    int index = -1;
    for (int j =0;j<vertex;j++){
        if (colorArr[j]==-1)
        {
            index = j;
            break;
        }
    }
    if (index == -1) break;
    queue <int> q;
    q.push(index);
    colorArr[index]=0;
while (!q.empty())
    {
        int u = q.front();
        q.pop();
  
        if (G[u][u] == 1)
        return false;
        for (int v = 0; v < vertex; v++)
        {
        
            if (G[u][v] && colorArr[v] == -1)
            {
                
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
  
            
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    i++;
}   
    return true;

}


// Question 3
/*

Research queue which is implemented in C library at: http://www.cplusplus.com/reference/queue/queue/. You can use library queue in c++ for this question.
Using queue, complete function void bfs(vector<vector<int>> graph, int start) to traverse all the nodes of the graph from given start node using Breadth First Search algorithm and data structure queue, and print the order of visited nodes. 
You can use below liberaries in this question.
#include <iostream>
#include <vector>
#include <queue>     */


void bfs(vector<vector<int>> graph, int start) {
	int numVertices = graph.size();
	bool *visited = new bool[numVertices]; 
    for(int i = 0; i < numVertices; i++) 
        visited[i] = false; 

    queue<int> myQueue; 
    bool isFirst = true;
    visited[start] = true; 
    myQueue.push(start); 

    while(!myQueue.empty()) 
    { 
        start = myQueue.front();
        if (isFirst) {
            cout << start;
            isFirst = false;
        }
        else cout << " " << start;
        myQueue.pop(); 

        int outDegree = graph[start].size();
        for (int j = 0; j < outDegree; ++j) 
        { 
            int temp = graph[start][j];
            if (!visited[temp]) 
            { 
                visited[temp] = true; 
                myQueue.push(temp); 
            } 
        }
    }
    delete[] visited;
}


// Question 4

/*

Implement all methods in class Queue with template type T. The description of each method is written as comment in frame code.

#ifndef QUEUE_H
#define QUEUE_H
#include "DLinkedList.h"
template<class T>
class Queue {
protected:
    DLinkedList<T> list;
public:
    Queue() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};

#endif /* QUEUE_H */

You can use all methods in class DLinkedList without implementing them again. The description of class DLinkedList is written as comment in frame code.
template <class T>
class DLinkedList 
{
public:
    class Node;     //forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList() ;
    ~DLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    T removeAt(int index);
    bool removeItem(const T& removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T& e);
    int indexOf(const T& item);
    bool contains(const T& item);
};
*/


void push(T item) {
    list.add(item);
}

T pop() {
    T temp = list.get(0);
    list.removeAt(0);
    return temp;
        
}

T top() {
    T temp = list.get(0);

    return temp;
}

bool empty() {
    if (list.size()==0) return true;
    else return false;
        
}

int size() {
    return list.size();
        
}

void clear() {
    list.clear();
    
}


// Question 5

/*

A nice number is a positive integer that contains only 2's and 5's.
Some nice numbers are: 2, 5, 22, 25, 52, 55, ...
Number 2 is the first nice number.
Given an integer N, return the Nth nice number.
Note: iostream, vector, queue are already included for you.

Constraint:
1 <= n <= 10^6

Example 1:
Input:
n = 5
Output:
52

Explanation:
The sequence of nice numbers is 2, 5, 22, 25, 52, 55, ...
The 5th number in this sequence is 52

Example 2:
Input:
n = 10000
Output:
2255522252225
*/


// iostream, vector and queue are included
// You can write helper methods

long long nthNiceNumber(int n) {
    queue<long long> qu;
    qu.push(2);
	    qu.push(5);
	    n-=1;
	    while(n--){
	        long long x=qu.front();
	        qu.pop();
	        qu.push(x*10+2);
	        qu.push(x*10+5);
	    }
	return qu.front();
}



// Question 6

/*

Given a n*m grid where each cell in the grid can have a value of 0, 1 or 2, which has the following meaning:
1. Empty cell
2. This cell contains a fresh apple
3. This cell contains a rotten apple
After 1 second, the cell with rotten apple will rot all fresh apples in all the cells adjacent to it (i.e the cells (x+1, y), (x-1, y), (x, y+1), (x, y-1))
Determine the minimum time (in seconds) required to rot all apples. If this cannot be done, return -1.
Note: iostream, vector, and queue are already included.

Constraint:
1 <= n, m <= 500

Hint: Have you ever heard about breadth-first-search?

Example 1:
Input: grid = {{2,2,0,1}}
Output: -1
Explanation:
The grid is
2 2 0 1
The apple at (0, 3) cannot be rotten

Example 2:
Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation:
The grid is
0 1 2
0 1 2
2 1 1
Apples at positions (0,2), (1,2), (2,0)
will rot apples at (0,1), (1,1), (2,2) and (2,1) after 1 second.
*/


// iostream, vector and queue are included
// Hint: use breadth-first-search
bool issafe(int i, int j,int R,int C)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}
int secondsToBeRotten(vector<vector<int>>& v) {
    int R = v.size();
    int C = v[0].size();
        bool changed = false;
    int no = 2;
    while (true) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
 
                // Rot all other oranges present at
                // (i+1, j), (i, j-1), (i, j+1), (i-1, j)
                if (v[i][j] == no) {
                    if (issafe(i + 1, j,R,C)
                        && v[i + 1][j] == 1) {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j + 1,R,C)
                        && v[i][j + 1] == 1) {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i - 1, j,R,C)
                        && v[i - 1][j] == 1) {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j - 1,R,C)
                        && v[i][j - 1] == 1) {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }
 
        // if no rotten orange found it means all
        // oranges rottened now
        if (!changed)
            break;
        changed = false;
        no++;
    }
 
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
 
            // if any orange is found to be
            // not rotten then ans is not possible
            if (v[i][j] == 1)
                return -1;
        }
    }
 
    // Because initial value for a rotten
    // orange was 2
    return no - 2;
}



// Question 7

/*

Given an array of integers.
Your task is to implement a function with following prototype:
int sumOfMaxSubarray(vector<int>& nums, int k);
The function returns the sum of the maximum value of every consecutive subarray of nums with fixed length k.

Note:
- The iostream, vector, queue and deque libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions and classes.

*/

int sumOfMaxSubarray(vector<int>& nums, int k) {
   if (k== 0) return 0;
   
   int n = nums.size();
   if (k > n ) k = n;
   queue<int> qu;
   int sum = 0, maxi = -1e9;
   
   for (int i =0;i<k;i++){
       qu.push(nums[i]);
       maxi = max(maxi, nums[i]);
   }
   
   sum += maxi;
   for (int i = 1; i+k-1<n;i++){
       qu.pop();
       qu.push(nums[i+k-1]);
       maxi = max(maxi, nums[i+k-1]);
       if (maxi == nums[i-1]){
           maxi = qu.front();
           for (int j = 0;j<qu.size();j++){
               maxi = max(maxi,qu.front());
               qu.push(qu.front());
               qu.pop();
           }
       }
       sum += maxi;
   }
   return sum;
}


/*----------------------------------------------Stack-------------------------------------------*/

// Question 1

/*

You are keeping score for a basketball game with some new rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.
At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the operation you must apply to the record, with the following rules:
A non-negative integer x (from 0 to 9) - record a new score of x
'+' - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
'D' - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
'C' - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Finally, return the sum of all scores in the record.
For example:
ops = "52CD+"
'5' - add to the record. Record now is [5]
'2' - add to the record. Record now is [5,2]
'C' - invalid the previous score (2). Record now is [5]
'D' - Record new score that is double of previous score (5*2). Record now is [5,10]
'+' - Record a new score that is the sum of the previous two scores. Record now is [5,10,15]
Return the sum: 5+10+15 = 30


*/



int baseballScore(string ops){
    stack<int> st;
    int n = ops.length();
    for (int i =0;i<n;i++){
        if (ops[i]=='C'){
            st.pop();
        }
        else if (ops[i]=='D'){
            int a = st.top();
            st.push(a*2);
        }
        else if (ops[i]=='+'){
            int a1 = st.top();
            st.pop();
            int a2 = st.top();
            st.pop();
            st.push(a2);
            st.push(a1);
            st.push(a1+a2);
        }
        else {
            st.push((int)(ops[i]-'0'));
        }
    }
    int result =0;
            while (!st.empty()){
                result = result + st.top();
                st.pop();
            } 
    return result;
}


// Question 2

/*

Implement all methods in class Stack with template type T. The description of each method is written as comment in frame code.

#ifndef STACK_H
#define STACK_H
#include "DLinkedList.h"
template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};

#endif

You can use all methods in class DLinkedList without implementing them again. The description of class DLinkedList is written as comment in frame code.
template <class T>
class DLinkedList 
{
public:
    class Node;     //forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList() ;
    ~DLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    T removeAt(int index);
    bool removeItem(const T& removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T& e);
    int indexOf(const T& item);
    bool contains(const T& item);
};				*/


void push(T item) {
    list.add(0,item);
}

T pop() {
    T temp = list.get(0);
    list.removeAt(0);
    return temp;
        
}

T top() {
    return list.get(0);
        
}

bool empty() {
    if (list.size() == 0) return true;
    return false;
        
}

int size() {
    return list.size();
        
}

void clear() {
    list.clear();
}


// Question 3

/*

Given an array nums[] of size N having distinct elements, the task is to find the next greater element for each element of the array
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist a next greater of a element, the next greater element for it is -1

Note: iostream, stack and vector are already included

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9

Example 1:
Input:
nums = {15, 2, 4, 10}
Output:
{-1, 4, 10, -1}

Example 2:
Input:
nums = {1, 4, 6, 9, 6}
Output:
{4, 6, 9, -1, -1}
*/


vector<int> nextGreater(vector<int>& arr){
    stack<int> stk;
    int size = arr.size();
    for (int i = size -1 ; i >= 0; --i) stk.push(arr[i]);
    for (int i = 0; i < size- 1; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
        if (arr[j] > stk.top() ) {
            arr[i] = arr[j]; break;
            
        }
        else
        {
        if (j == size -1 ) arr[i] = -1;
        }
        }
        stk.pop();
    }
    arr[arr.size()-1] = -1;
    return arr;
}


// Question 4

/*

Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.
Postfix expression: The expression of the form “a b operator” (ab+) i.e., when a pair of operands is followed by an operator.
For example: Given string S is  "2 3 1 * + 9 -". If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
Requirement: Write the function to evaluate the value of postfix expression.     */


int evaluatePostfix(string expr){
    stack<int> st;
    int len = expr.length();
    int num = 0;
    int checkso = 0;
    for (int i = 0;i<len;i++){
        if (expr[i]==' ') {
            if (checkso == 0)
            continue;
            else {
                st.push(num);
                checkso = 0;
                num =0;}
            }
        else if (expr[i]=='+'){
            int a2 = st.top();
            st.pop();
            int a1 = st.top();
            st.pop();
            st.push(a1+a2);
        }
        else if (expr[i]=='-'){
            int a2 = st.top();
            st.pop();
            int a1 = st.top();
            st.pop();
            st.push(a1-a2);
        }
        else if (expr[i]=='*'){
            int a2 = st.top();
            st.pop();
            int a1 = st.top();
            st.pop();
            st.push(a1*a2);
        }
        else if (expr[i]=='/'){
            int a2 = st.top();
            st.pop();
            int a1 = st.top();
            st.pop();
            st.push(a1/a2);
        }
        else {
            checkso = 1;
            num = num*10 + (int)(expr[i]-'0');
        }
    }
    return st.top();
}


// Question 5

/*

A Maze is given as 5*5 binary matrix of blocks and there is a rat initially at the upper left most block i.e., maze[0][0] and the rat wants to eat food which is present at some given block in the maze (fx, fy). In a maze matrix, 0 means that the block is a dead end and 1 means that the block can be used in the path from source to destination. The rat can move in any direction (not diagonally) to any block provided the block is not a dead end.
Your task is to implement a function with following prototype to check if there exists any path so that the rat can reach the food or not:
bool canEatFood(int maze[5][5], int fx, int fy);
Template:
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>using namespace std;
class node {
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;
  
        // Initially direction
        // set to 0
        dir = 0;
    }
};
Some suggestions: 
- X : x coordinate of the node
- Y : y coordinate of the node
- dir : This variable will be used to tell which all directions we have tried and which to choose next. We will try all the directions in anti-clockwise manner starting from up.
If dir=0 try up direction.
If dir=1 try left direction.
If dir=2 try down direction.
If dir=3 try right direction.         */


bool canEatFood(int maze[5][5], int fx, int fy){
    bool visited[5][5];
    for (int i=0;i<5;i++){
        for (int j = 0;j<5;j++){
            visited[i][j]=true;
        }
    }

    int i = 0, j = 0;
     
    stack<node> st;
     
    node temp(i, j);
     
    st.push(temp);
    
    while (!st.empty()){
        temp = st.top();
        int d = temp.dir;
        i = temp.x, j = temp.y;
 
        temp.dir++;
        st.pop();
        st.push(temp);
        
        if (i == fx && j == fy) {
            return true;
        }
        
        if (d == 0) {
            if (i - 1 >= 0 && (maze[i - 1][j] &&
                                    visited[i - 1][j])) {
                node temp1(i - 1, j);
                visited[i - 1][j] = false;
                st.push(temp1);
            }
        }
        else if (d == 1) {
            if (j - 1 >= 0 && (maze[i][j - 1] &&
                                    visited[i][j - 1])) {
                node temp1(i, j - 1);
                visited[i][j - 1] = false;
                st.push(temp1);
            }
        }
        else if (d == 2) {
            if (i + 1 < 5 &&( maze[i + 1][j] &&
                                    visited[i + 1][j])) {
                node temp1(i + 1, j);
                visited[i + 1][j] = false;
                st.push(temp1);
            }
        }
        else if (d == 3) {
            if (j + 1 < 5 &&( maze[i][j + 1] &&
                                    visited[i][j + 1])) {
                node temp1(i, j + 1);
                visited[i][j + 1] = false;
                st.push(temp1);
            }
        }
        else {
            visited[temp.x][temp.y] = true;
            st.pop();
        }
    }
    return false;

    
}



// Question 6

/*

Given a string S of characters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
We repeatedly make duplicate removals on S until we no longer can.
Return the final string after all such duplicate removals have been made.
Included libraries: vector, list, stack      */


string removeDuplicates(string S){
    stack<char> st;
    int i =1;
    st.push(S[0]);
    int n = S.length();                     //abbaca
    while (i <n){
        if (st.empty()) st.push(S[i]);
        else if (S[i]==st.top()){
            S = S.replace(i-1,2,"");
            st.pop();
            i--;
            n=S.length();
            continue;
        }
        else st.push(S[i]);
        i++;
        n = S.length();
    }
    return S;
}


// Question 7

/*

Phiên bản tiếng Anh:
The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of the stock’s price for each day.
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than its price on the given day, plus 1 (for itself).
For example: take the stock's price sequence [100, 80, 60, 70, 60, 75, 85]. (See image above)
The given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 60 is smaller than 80 so the span is 1, 70 is greater than 60 so the span is 2 and so on.
Hence the output will be [1, 1, 1, 2, 1, 4, 6].

Requirement. Write a program to calculate the spans from the stock's prices.
Input. A list of whitespace-delimited stock's prices read from standard input.
Output. A list of space-delimited span values printed to standard output.
*/


vector<int> stock_span(const vector<int>& ns) {
    vector<int> result;
    result.push_back(1);
    //vector<int> temp;
    //temp.push_back(ns[0]);
    for (int i = 1;i< (int)ns.size();i++){
        int j = i-1;
        int count = 1;
        while (j>=0){
            if (ns[j]<ns[i])
            count++;
            else break;
            j--;
        }
        result.push_back(count);
    }
    return result;
}


// Question 8

/*

Given a string s containing just the characters '(', ')', '[', ']', '{', and '}'. Check if the input string is valid based on following rules:
1.Open brackets must be closed by the same type of brackets.
2.Open brackets must be closed in the correct order.
For example:
String "[]()" is a valid string, also "[()]".
String "[])" is not a valid string.
Your task is to implement the function
bool isValidParentheses (string s){
    /*TODO*/
}
Note: The library stack of C++ is included.    */


bool isValidParentheses (string s){
    stack<char> st;
    int n = s.length();
    int i=1;
    st.push(s[0]);
    while (i<n){
        if (s[i]=='{'||(s[i]=='['||s[i]=='(')){
            st.push(s[i]);
        }
        else{
            if (st.empty()) 
            return false;
            else if (s[i]=='}'){
                if (st.top() != '{') return false;
                else st.pop();
            }
            else if (s[i]==']'){
                if (st.top() != '[') return false;
                else st.pop();
            }
            else if (s[i]==')'){
                if (st.top() != '(') return false;
                else st.pop();
            }
        }
        i++;
    }
    return (st.empty());
}



/*------------------------------------------Sort-Part1------------------------------------------*/



// Question 1
/*

Implement method bubbleSort() in class SLinkedList to sort this list in ascending order. After each bubble, we will print out a list to check (using printList). 
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList()
    {
      this->head = nullptr;
      this->tail = nullptr;
      this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    void bubbleSort();
};    */


template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (count <= 1) {
        return;}
    int checksort = 0;
    for (int i = 0;i<count - 1;i++){
        Node * curr = head;
        for (int j =1;j<count - i;j++){
            Node * nex = curr->next;
            if (curr->data > nex->data){
                T a = curr->data;
                curr->data = nex->data;
                nex->data = a;
                checksort = 1;
            }
            curr = nex;
            nex = nex->next;
        }
        if(checksort == 0)
        break;
        printList();
        checksort = 0;
    }
    
}


// Question 2

/*

Implement static method selectionSort in class Sorting to sort an array in ascending order.  After each selection, we will print out a list to check (using printArray). 
#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end);
};      */


template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    T* current = start;
    while(current != end-1){
        T* walker = current+1;
        T* smallest = current;
        while(walker != end){
            if(*walker < *smallest) smallest = walker;
            walker++;
        }
        T tmp = *smallest;
        *smallest = *current;
        *current = tmp;
        current++;
        Sorting<T>::printArray(start,end);
    }
}



// Question 3

/*

Implement static methods sortSegment and ShellSort in class Sorting to sort an array in ascending order. 
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
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

public:
    // TODO: Write your code here
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total);
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases);
};
#endif /* SORTING_H */      */


// TODO: Write your code here

static void sortSegment(T* start, T* end, int segment, int k) {
    int current = segment + k;
    int size = end - start;
    while (current < size) {
        T tmp = start[current];
        int step = current - k;
    while (step >= 0 && start[step] > tmp) {
        start[step + k] = start[step];
        step -= k;
    }
    start[step + k] = tmp;
    current += k;
    //indexNode += k;
    }
}


static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    // TODO
    // Note: You must print out the array after sorting segments to check whether your algorithm is true.
    int index = num_phases - 1;
    while (index >= 0) {
        int segment = 0;
        while (segment < num_segment_list[index]) {
            sortSegment(start, end, segment, num_segment_list[index]);
            segment++;
        }
        cout << num_segment_list[index] << " segments: ";
        Sorting<T>::printArray(start, end);
        index--;
    }
}