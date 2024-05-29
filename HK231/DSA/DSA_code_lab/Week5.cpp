// Question 1

/*

Implement function
int binarySearch(int arr[], int left, int right, int x)
to search for value x in array arr using recursion.
After traverse an index in array, we print out this index using cout << "We traverse on index: " << index << endl;
Note that middle of left and right is floor((right-left)/2) */


int binarySearch(int arr[], int left, int right, int x)
{
    if (left > right) return -1;
 
    int mid = left + (right-left)/2;
    cout<<"We traverse on index: "<<mid<<endl;
    if (arr[mid]==x){
        return mid;
    }
        
    if (arr[mid]<x){
        left = mid+1;
        return binarySearch(arr,left,right,x);
    }
    else {
        right = mid-1;
        return binarySearch(arr,left,right,x);
    }

}


// Question 2

/*

Implement functions: Peek, Pop, Size, Empty, Contains to a maxHeap. If the function cannot execute, return -1.
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};
//Your code goes here			*/


template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
   if (count == 0) return true;
   return false;
}

template<class T>
T Heap<T>::peek(){
    if (count > 0)
    return elements[0];
    else return -1;
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i = 0; i < count; i++) {
        if (elements[i] == item) {
            return true;
        }
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (count > 0) {
        elements[0] = elements[count - 1];
        count--;
        reheapDown(0);
        return true;
    } else {
        return false;
    }
}


// Question 3

/*

Implement function push to push a new item to a maxHeap. You also have to implement ensureCapacity and reheapUp to help you achieve that.
template
class Heap{
protected:
    T *elements;
    int capacity;
    int count;
    
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete []elements;
    }
    void push(T item);
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]";
    }
    
private:
    void ensureCapacity(int minCapacity); 
    void reheapUp(int position);
};
// Your code here		*/


template<class T>
void Heap<T>::push(T item){
    ensureCapacity(count + 1);
    elements[count] = item;
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (minCapacity > capacity) {
        int newCapacity = capacity * 2;
        T* newElements = new T[newCapacity];
        for (int i = 0; i < count; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }
}

template<class T>
void Heap<T>::reheapUp(int position){
    int parent = (position - 1) / 2;
    T bottom = elements[position];
    while (position > 0 && elements[parent] < bottom) {
        elements[position] = elements[parent];
        position = parent;
        parent = (parent - 1) / 2;
    }
    elements[position] = bottom;
}


// Question 4

/*

Implement function
int interpolationSearch(int arr[], int left, int right, int x)
to search for value x in array arr using recursion.
After traverse to an index in array, before returning the index or passing it as argument to recursive function, we print out this index using cout << "We traverse on index: " << index << endl;
Please note that you can't using key work for, while, goto (even in variable names, comment).	*/


int interpolationSearch(int arr[], int left, int right, int x)
{
    if (left > right) return -1;
    if ((x > arr[right])||(x <arr[left])) return -1;
    int n = right-left;
    int mid = ((x-arr[left])/(double)(arr[right]-arr[left]))*n;
    int index = left + mid;
    
    cout<<"We traverse on index: " << index << endl;
     if (arr[index] == x) {
            return index; 
        }

        if (arr[index] < x) {
            return  interpolationSearch(arr,index+1,right,x);
        } else {
            return  interpolationSearch(arr,left,index-1,x);
        }
}


// Question 5

/*

Given an array which the elements in it are random. Now we want to build a Max heap from this array. Implement functions Reheap up and Reheap down to heapify element at index position. We will use it to build a heap in next question.
To keep things simple, this question will separate the heap array, not store it in the class heap
void reheapDown(int maxHeap[], int numberOfElements, int index);
void reheapUp(int maxHeap[], int numberOfElements, int index);		*/

void reheapDown(int maxHeap[], int numberOfElements, int index) {
    int parent = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < numberOfElements && maxHeap[leftChild] > maxHeap[parent]) {
        parent = leftChild;
    }

    if (rightChild < numberOfElements && maxHeap[rightChild] > maxHeap[parent]) {
        parent = rightChild;
    }

    if (parent != index) {
        swap(maxHeap[index], maxHeap[parent]);
        reheapDown(maxHeap, numberOfElements, parent);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index) {
    if (index == 0) {
        return;
    }

    int parent = (index - 1) / 2;

    if (maxHeap[index] > maxHeap[parent]) {
        swap(maxHeap[index], maxHeap[parent]);
        reheapUp(maxHeap, numberOfElements, parent);
    }
}


// Question 6 
/*

In computer science, a jump search or block search refers to a search algorithm for ordered lists. The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps or skipping some elements in place of searching all elements. For example, suppose we have an array arr[] of size n and block (to be jumped) size m. Then we search at the indexes arr[0], arr[m], arr[2m]…..arr[km] and so on. Once we find the interval (arr[km] < x < arr[(k+1)m]), we perform a linear search operation from the index km to find the element x. The optimal value of m is √n, where n is the length of the list.

In this question, we need to implement function jumpSearch with step √n to search for value x in array arr. After searching at an index, we should print that index until we find the index of value x in array or until we determine that the value is not in the array.
int jumpSearch(int arr[], int x, int n)		*/

int jumpSearch(int arr[], int x, int n) {
    if (arr[0] > x) {
        //cout << "0 ";
        return -1;
    }
    
    int temp = 0;
    int prev = 0;
    int j = sqrt(n);
    while (true) {
        if (temp >= n) {
            temp = n;
            break;
        } else if (arr[temp] > x) {
            cout<< temp<<" ";
            break;
        } else if (arr[temp] == x) {
            cout << temp;
            return temp;
        }
        cout << temp << " ";
        prev = temp;
        temp = temp + j;
    }
    for (int i = prev + 1; i <= temp; i++) {
        if (arr[i] > x) return -1;
        cout << i << " ";
        if (arr[i] == x) return i;
    }
    return -1;
    
}


// Question 7

/*
Given an array of distinct integers, find if there are two pairs (a, b) and (c, d) such that a+b = c+d, and a, b, c and d are distinct elements. If there are multiple answers, you can find any of them.
Some libraries you can use in this question:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>
Note: The function checkAnswer is used to determine whether your pairs found is true or not in case there are two pairs satistify the condition. You don't need to do anything about this function.		*/

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
   // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
    map<int,pair<int, int>> sumMap;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (sumMap.find(sum) != sumMap.end()) {
                pair1 = {arr[i], arr[j]};
                pair2 = sumMap[sum];
                return true;
            } else {
                sumMap[sum] = {arr[i], arr[j]};
            }
        }
    }
    return false;
}

// Question 8

/*

Implement method remove to remove the element with given value from a maxHeap, clear to remove all elements and bring the heap back to the initial state.  You also have to implement method getItem to help you. Some given methods that you don't need to implement again are push, printHeap, ensureCapacity, reheapUp, reheapDown.
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

// Your code here
*/

template<class T>
int Heap<T>::getItem(T item) {
    if (this->count == 0) return -1;
    for (int i=0; i<count; i++){
        if (elements[i]==item) return i;
    }
    return -1;
    
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    if (index<0) return;
    elements[index] = elements[count-1];
    count--;
    for (int i = count-1;i>=0;i--){
        reheapDown(i);
    }
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
     delete[] this->elements;
    this->count = 0;
    this->elements = new T[capacity];
}


// Question 9
/*

Your task is to implement heap sort (in ascending order) on an unsorted array.
#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <queue>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    //Helping functions go here
    static void heapSort(T* start, T* end){
        //TODO
        Sorting<T>::printArray(start,end);
    }
    
};
#endif /* SORTING_H */		*/


static void swap(T &a, T &b) {
		int temp = a;
		a = b;
		b = temp;
	}

static void reHeapDown(T* start, T* end, int index)
{
	int size = end - start;
	int largest = index; 
	int l = 2 * index + 1; 
	int r = 2 * index + 2; 

	if (l < size && start[l] > start[largest])
		largest = l;

	if (r < size && start[r] > start[largest])
		largest = r;

	if (largest != index) {
		swap(start[index], start[largest]);
		reHeapDown(start, end, largest);
	}
}

static void heapSort(T* start, T* end)
{
    // TODO
	int size = end - start;
	for (int i = size / 2 - 1; i >= 0; i--)
		reHeapDown(start, end, i);

	for (int i = size - 1; i > 0; i--) {
		swap(start[0], start[i]);
		reHeapDown(start, start + i, 0);
	}
	Sorting<T>::printArray(start, end);
}


// Question 10 
/*

Cho template của class PrinterQueue có 2 phương thức bắt buộc:
1. addNewRequest(int priority, string fileName)
Phương thức đầu tiên sẽ thêm 1 file vào danh sách hàng đợi của máy in (bao gồm độ ưu tiên và tên file). Test case sẽ có tối đa 100 file cùng lúc trong hàng đợi
2. print()
Phương thức thứ hai sẽ in tên file kèm xuống dòng và xóa nó ra khỏi hàng đợi. Nếu không có file nào trong hàng đợi, phương thức sẽ in ra "No file to print" kèm xuống dòng.
PrinterQueue tuân theo các quy tắc sau:
fileName có độ ưu tiên cao nhất sẽ được in trước.
Các fileName có cùng độ ưu tiên sẽ in theo thứ tự FIFO (First In First Out) order.
Nhiệm vụ của bạn là hiện thực class PrinterQueue thỏa mãn các yêu cầu dữ liệu trên
Lưu ý: Bạn có thể thay đổi mọi thứ, thêm thư viện cần thiết ngoại trừ thay đổi tên class, prototype của 2 public method bắt buộc.
Giải thích testcase 1: File goodbye.pdf có độ ưu tiên là 2 và được thêm vào sớm hơn file goodnight.pdf (độ ưu tiên = 2) nên sẽ được in trước, sau đó đến file goodnight.pdf và cuối cùng là hello.pdf có độ ưu tiên thấp nhất (1)      */


#include <vector>
#include <algorithm>

class store{
      public:
      int x;
      string y;
};
class PrinterQueue
{
    vector<store> qu;
public:
    // your methods
    void addNewRequest(int priority, string fileName)
    {
        qu.push_back({priority,fileName});
    }

    void print()
    {
        int n = qu.size();
        if (n == 0){
            cout<<"No file to print"<<endl;
            return;
        }
        int max = qu[0].x;
        int j =0;
        for (int i = 0;i<n;i++){
            if (qu[i].x>max){
                max = qu[i].x;
                j = i;
            }
        }
        
        cout<<qu[j].y<<endl;
        qu.erase(qu.begin()+j);
    }
};


// Question 11
/* Given an array of non-negative integers. Each time, we can take the smallest integer out of the array, multiply it by 2, and push it back to the array.
Request: Implement function:
int leastAfter(vector<int>& nums, int k);
Where nums is the given array (the length of the array is between 1 and 100000). This function returns the smallest integer in the array after performing the operation k times (k is between 1 and 100000).
Example:
Given nums = [2, 3, 5, 7].
In the 1st operation, we take 2 out and push back 4. The array is now nums = [3, 4, 5, 7].
In the 2nd operation, we take 3 out and push back 6. The array is now nums = [4, 5, 6, 7].
In the 3rd operation, we take 4 out and push back 8. The array is now nums = [5, 6, 7, 8].
With k = 3, the result would be 5.
Note:
In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std are used. You can write helper functions and classes. Importing other libraries is allowed, but not encouraged, and may result in unexpected errors.		*/

int leastAfter(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    for (int i = 0; i < k; i++) {
        int smallest = pq.top();
        pq.pop();
        pq.push(smallest * 2);
    }
    return pq.top();
}