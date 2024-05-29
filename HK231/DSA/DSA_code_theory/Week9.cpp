// Question 1

/*
Write function binarysearch(T arr[],int left, int right, T k) to search key k in the ascending-sorted array arr with lower bound index left and upper bound index right using binary search method. The method return true if the key k is found in the array arr, otherwise it returns false. To make sure the function applying binary search, please print the values (followed by comma) compared to key k during searching process. The prototype of the function is as follows:
template <typename T>
bool binarysearch(T arr[], int left, int right, T k);   */


template <typename T>
bool binarysearch(T arr[], int left, int right, T k){
    if (left > right) return false;
    
    int mid = left + (right-left)/2;
    cout<<arr[mid]<<",";
    if (arr[mid]==k)return true;
    else if (arr[mid]<k){
        return binarysearch(arr,mid+1,right,k);
    }
    else {
        return binarysearch(arr,left,mid-1,k);
    }
}


// Question 2

/*

Write function binarysearch(T arr[],int n, T k) to search key k in the ascending-sorted array arr with n elements using binary search method. The method return the index of key k if the key is found in the array arr, or the index of the greatest value less than k if the key k is not found in the array arr, or ERROR if the key k is less than the least value in the array arr. To make sure that you are using binary search, please print the index of elements (followed by the comma) comparing during the searching before the result of the function.
The prototype of the function is as follows:
template <typename T>
int binarysearch(T arr[], int n, T k);   */

template <typename T>
int binarysearch(T arr[], int n, T k) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        cout << mid << ","; 
        if (arr[mid] == k) {
            return mid;
        } else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (high < 0) {
        return -1;
    } else {
       return high;
    }
}


// Question 3

/*
Write function dictionarySearch(T arr[],int left, int right, T k) to search key k in the ascending-sorted array arr with lower bound index left and upper bound index right using dictionary search method. The method return true if the key k is found in the array arr, otherwise it returns false. To make sure the function applying dictionary search, please print the values (followed by comma) compared to key k during searching process. The prototype of the function is as follows:
template <typename T>
bool dictionarySearch(T arr[], int left, int right, T k);   */

template <typename T>
bool dictionarySearch(T arr[], int left, int right, T k){
    if (left > right) return false;
    if (k > arr[right]) return false;
    if (k < arr[left]) return false;
        int n = right-left;
        int mid1 =round(((k-arr[left])/(double)(arr[right]-arr[left]))*n);
        int mid = left +mid1;

        cout << arr[mid] << ","; 

        if (arr[mid] == k) {
            return true; 
        }

        if (arr[mid] < k) {
            return dictionarySearch(arr,mid+1,right,k);
        } else {
            return dictionarySearch(arr,left,mid-1,k);
        }
}

// Question 4

/*
Write function jumpsearch(T arr[],int n, T k,int j) to search key k in the ascending-sorted array arr with size n using jump search method with j. The method return true if the key k is found in the array arr. To make sure the function applying jump search, please print the values compared to key k during searching process. These printed values are followed by commas. The prototype of the function is as follows:
template <typename T>
bool jumpsearch(T arr[], int n, T k, int j);   */

template <typename T>
bool jumpsearch(T arr[], int n, T k, int j){
    if (arr[0]>k){
        cout<<arr[0]<<",";
        return false;
    }
    int temp = 0;
    int prev = 0;
    while (true){
        cout<<arr[temp]<<",";
        prev = temp;
        temp = temp+j;
        if (temp >= n){
            temp = n;
            break;
        }
        else if (arr[temp]>k){
            cout<<arr[temp]<<",";
            break;
        }
        else if (arr[temp]==k){
            cout<<arr[temp]<<",";
            return true;
        }
    }
    for (int i =prev+1;i<temp;i++){
        cout<<arr[i]<<",";
        if (arr[i]>k)return false;
        if (arr[i]==k) return true;
    }
    return false;
}


// Question 5

/*
Implement an integer hash (with separate chaining) in class ChainingHash with three following elementary methods:
- insert: to Insert an integer key into a hash
- remove: to remove an integer key from a hash if found, otherwise throw exception "Not found!"
- search: to search a key in hash, return true if found, otherwise return false.
Assume that there is no duplicate key.
Initial code:
class ChainingHash {
private:
    int (*hash)(int);
    list<int> *data;
    int size;
    
public:
    ChainingHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    ChainingHash(int size, int (*hash)(int)) {
        this->hash = hash;
        this->size = size;
        this->data = new list<int>[size];
    }
    
    {{ STUDENT_ANSWER }}
    
    int count() {
        int total = 0;
        for (int i = 0; i < this->size; i++) {
            total += this->data[i].size();
        }
        return total;
    }
    
    void dump() {
        for (int i = 0; i < this->size; i++) {
            cout << "Slot " << i << ": " << this->data[i].size() << " element(s)" << endl;
        }
    }
};
Given some hash function:
int hashWith11(int key) {
    return key % 11;
}
int hashWith15(int key) {
    return key % 15;
}
int hashWith17(int key) {
    return key % 17;
}   */


void insert(int key) {
    this->data[hash(key)].push_back(key);
}

void remove(int key) {
    int index = hash(key);
    list<int>::iterator it;
    for (it = data[index].begin();it != data[index].end();it++) {
        if (*it == key) {
            data[index].erase(it);
            return;
        }
    }
    throw "Not found!";
}

bool search(int key) {
    int index = hash(key);
    list<int>::iterator it;
    for (it = data[index].begin();it != data[index].end();it++) {
        if (*it == key) {
            return true;
        }
    }
    return false;
}



/*----------------------------------------OPTIONAL_CODE------------------------------------*/

// Question 1

/*

Define class FrequentSearch that must include at least the following methods:
constructor FrequentSearch(T* arr,int n): arr is the searched array, n is its size;
destructor ~FrequentSearch(): to remove any dynamic data.
bool search(T key): searches the key in the searched array and returns true it found. This function also counts the frequent of a searched key and moves the key up so that the elements of the searched array are in the descending order of the searched count. If two elements with the same searched count, the one which is most recently searched stays before the other.
void print(): prints all the elements of the searched array (element followed by a comma)   
*/

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
struct Element {
    T value;
    int frequency;
    int timestamp;

    Element(T value, int timestamp) : value(value), frequency(0), timestamp(timestamp) {}
};

template <typename T>
class FrequentSearch {
private:
    std::vector<Element<T> > arr;
    int currentTime;

public:
    FrequentSearch(T* inputArr, int n) : currentTime(0) {
        for (int i = 0; i < n; i++) {
            arr.push_back(Element<T>(inputArr[i], currentTime++));
        }
    }

    ~FrequentSearch() {
        arr.clear();
    }

    bool search(T key) {
        for (int i = 0; i <(int)arr.size(); i++) {
            if (arr[i].value == key) {
                arr[i].frequency++;
                arr[i].timestamp = currentTime++;
                std::sort(arr.begin(), arr.end(), [](Element<T> a, Element<T> b) {
                    if (a.frequency == 0 && b.frequency == 0)
                    return false;
                    else if (a.frequency == b.frequency) {
                        return a.timestamp > b.timestamp;
                    }
                    return a.frequency > b.frequency;
                });
                return true;
            }
        }
        return false;
    }

    void print() {
        for (int i = 0; i <(int)arr.size(); i++) {
            cout << arr[i].value << ",";
        }

    }
};



// Question 2

/*

Implement an integer hash (with open addressing) in class HashTable with three following methods: 
- insert: to insert an integer key into a hash, return inserted slot position, otherwise throw exception runtime_error("Overflow!"). If the key has been in the hash table, please throw runtime_error("Duplicate key: "+to_string(key))
- remove: to remove an integer key from a hash if found, otherwise throw exception runtime_error("Not found!")
- search: to search a key in hash, return slot position if found, otherwise return -1.

Initial code:
enum STATUS_TYPE {NIL, NON_EMPTY, DELETED};
class OpenHash {
private:
    int (*hp)(int, int);
    STATUS_TYPE* status;
    int* data;
    int size;
    
public:
    OpenHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    OpenHash(int size, int (*hp)(int, int)) {
        this->hp = hp;
        this->size = size;
        this->data = new int[size];
        this->status = new STATUS_TYPE[size];
        for (int i = 0; i < size; i++) {
            this->status[i] = NIL;
        }
    }
    
    {{ STUDENT_ANSWER }}
    
    void dump() {
        for (int i = 0; i < this->size; i++) {
            if (this->status[i] != NON_EMPTY)
                cout << "Slot " << i << ": Empty" << endl;
            else cout << "Slot " << i << ": " << this->data[i] << endl;
        }
    }
};
Given some hash function:
int linearProbing(int key, int i) {
    return ((key % 11) + i) % 11;
}

int quadraticProbing(int key, int i) {
    return ((key % 11) + i + 3 * i * i) % 11;
}

int doubleHashing(int key, int i) {
    int h1 = key % 11;
    int h2 = 1 + (key % 10);
    return (h1 + i * h2) % 11;
}  */


int insert(int key) {
     for (int i = 0; i < size; i++) {
        int pos = hp(key, i);
        if (status[pos] == NON_EMPTY) {
            if (data[pos] == key) {
                throw runtime_error("Duplicate key: " + to_string(key));
            }}}
    
    
    for (int i = 0; i < size; i++) {
        int pos = hp(key, i);
        if (status[pos] == NON_EMPTY) {
            if (data[pos] == key) {
                throw runtime_error("Duplicate key: " + to_string(key));
            }
        } else {
            data[pos] = key;
            status[pos] = NON_EMPTY;
            return pos;
        }
    }
    throw runtime_error("Overflow!");
}

void remove(int key) {
    for (int i = 0; i < size; i++) {
        int pos = hp(key, i);
        if (status[pos] == NON_EMPTY && data[pos] == key) {
            status[pos] = DELETED;
            return;
        }
    }
    throw runtime_error("Not found!");
}

int search(int key) {
    for (int i = 0; i < size; i++) {
        int pos = hp(key, i);
        if (status[pos] == NON_EMPTY && data[pos] == key) {
            return pos;
        } else if (status[pos] == NIL) {
            return -1;
        }
    }
    return -1;
}