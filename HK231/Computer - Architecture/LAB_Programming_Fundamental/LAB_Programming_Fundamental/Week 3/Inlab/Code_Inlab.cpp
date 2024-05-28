/*_______________________________________Linked_list_________________________________________*/

// Question 1

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
node *createLinkedList(int n)
{
  node *newnode = new node;
  node *p =new node;
  newnode = NULL;
  int input;
  for (int i = 1;i <=n;i++){
      cin >> input;
      node *temp = new node;
      temp->data = input;
      temp->next = NULL;
    if (newnode == NULL){
        newnode = temp;
    }
    else {
        p = newnode;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
  }
  return newnode;
}
void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}
int main()
{
  int n = 0;
  cin >> n;
  if (n > 0)
  {
    node *head = createLinkedList(n);
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }
  return 0;
}


// Question 2

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

node *insertNode(node *head, node *newNode, int position)
{
    int i =1;
  if (position > 0){
      node *p = new node;
      p = head;
      while (p->next != NULL) {
          if (i == position-1){
              newNode->next= p->next;
              p->next = newNode;
              goto end;
          }
          p = p->next;
          i++;
      }
      newNode->next = p->next;
      p->next = newNode;
  }
  end: return head;
  
}
void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  node *newNode = new node();
  cin >> newNode->data;
  int position = 0;
  cin >> position;
  head = insertNode(head, newNode, position);
  print(head);
  return 0;
}


// Question 3

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

void replace(node* head, int position, int value)
{
  node *p = new node;
  p = head;
  int i= 0;
  while (p->next != NULL){
      if (i == position){
      p->data = value;
      break;
      }
      p = p->next;
      i++;
  }
}
void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout<<endl;
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  print(head);
  int pos, val;
  cin>>pos>>val;
  replace(head, pos, val);
  print(head);
  return 0;
}


// Question 4

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

int searchLinkedList(node* head, int key)
{
    int check = -1,i =0;
    node *p = new node;
    p = head;
    if (p -> data == key) {
        check = 0;
        goto end;
    }
    while (p->next != NULL) {
        if (p->data == key ){
            check = i;
            goto end;
        }
        p = p ->next;
        i++;
    }
    if (p -> data == key) {
        check = i;
    }
end:  return check;
}
void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  print(head);
  int m;
  cin>>m;
  cout<<searchLinkedList(head,m);
  return 0;
}


/*____________________________________________OOP___________________________________________*/

// Question 1

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array(){
        delete[] p;
    }
    void print();
private:
    int size;
    T * p;
};

template <typename T>
 Array<T>::Array(int size, T iniValue){
     this -> size = size;
    T *mangmoi = new T[size];
    for (int i = 0;i<size;i++){
        mangmoi[i]=iniValue;
    }
    p = mangmoi;
}


// Question 2


class ClockType
{
   public:
      void setTime(int, int, int);
      void printTime() const;
      void incrementSeconds();
      void incrementMinutes();
      void incrementHours();
      ClockType(int, int, int);
      ClockType();

   private:
      int hr;
      int min;
      int sec;
};

void ClockType::printTime() const
{
   if (hr < 10)
      cout << "0";
   cout << hr << ":";
   if (min < 10)
      cout << "0";
   cout << min << ":";
   if (sec < 10)
      cout << "0";
   cout << sec;
}

void ClockType::incrementSeconds(){
    sec = sec +1;
    if (sec == 60) 
    {sec = 0;
    min = min +1;
    }
    if (min == 60) 
    {
        min = 0;
        hr = hr +1;
    }
    if (hr == 24) 
    {
        hr = 0;
    }
}
void ClockType::incrementMinutes(){
    min = min +1;
    if (sec == 60) 
    {sec = 0;
    min = min +1;
    }
    if (min == 60) 
    {
        min = 0;
        hr = hr +1;
    }
    if (hr == 24) 
    {
        hr = 0;
    }
}

void ClockType::incrementHours(){
    hr = hr +1;
    if (sec == 60) 
    {sec = 0;
    min = min +1;
    }
    if (min == 60) 
    {
        min = 0;
        hr = hr +1;
    }
    if (hr == 24) 
    {
        hr = 0;
    }
}


// Question 3

#include<iostream>
using namespace std;

class Integer {
    private: 
    int val;
    public:
    Integer(int a){
        val = a;
    }
    Integer(Integer* a){
       this-> val = a -> val;
    }
    void print();
    Integer operator+( Integer& a){
        Integer res(this->val + a.val);
        return res;
    }
    Integer operator+(int a){
        Integer res(this->val + a);
        return res;
    }
};

void Integer::print() {
    cout << this->val << endl;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer* t = new Integer(z);
    Integer c(t);
    
    a.print(); b.print();
    (a + b + c + 4).print();
    
    delete t;
    return 0;
}


// Question 4

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();
    void print();
    
    Array(const Array<T> & other); // Copy Constructor
    
private:
    int size;
    T * p;
};

template <typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "") << this->p[i];
    }
    cout << endl;
}

template<typename T>
Array<T>:: Array(const Array<T> & other){
    this->size = other.size;
    T *newarr = new T[other.size];
    for (int i = 0;i<other.size;i++){
        newarr[i]=other.p[i];
    }
    this->p = newarr;
}


// Question 5

#include <iostream>
#include <string.h>

using namespace std;

template<class T> class Cell {
protected:
    T infor;
public:
    void set(T _infor) { this->infor = _infor; };
    T* get() { return this->infor; };
};

enum Color {White, Yellow, Black, Red, Blue};
template<class T>
class ColoredCell: public Cell<T> {
    private:
    Color color;
    public:
    void setColor(Color a) {
        color = a;
    }
    Color getColor(){
        return color;
    }
    T* get() {
        if (color == White)
        return NULL;
        else return &(this->infor);
    }
};

int main () {
    int test, c;
    cin >> test >> c;
    ColoredCell<int>* a = new ColoredCell<int>();
    switch (test)
    {
    case 1:
        a->setColor(Color(c));
        cout << int(a->getColor());
        break;
    case 2:
        a->setColor(Color(c));
        a->set(10);
        if (a->get() == NULL) cout << "null" << endl;
        else cout << *(a->get());
    default:
        break;
    }
    return 0;
}


// Question 6


class ClockType
{
public:
    void setTime(int, int, int);
    bool equalTime(const ClockType&) const;
    ClockType(int, int, int);
    ClockType();

private:
    int hr;
    int min;
    int sec;
};

bool ClockType::equalTime(const ClockType& a) const {
    if ((this->hr==a.hr)&&(this->min==a.min)&&(this->sec==a.sec))
    return true;
    else return false;
}


// Question 7

// string.h is included

class Book {
    char* name;
public:
    Book(const char*);
    ~Book();
    
    void display();
    char* getName();
};

void Book::display() {
    cout << "Book: " << this->name << endl;
}

char* Book::getName() {
    return this->name;
}


Book::Book(const char* a){
    int size = strlen(a);
    char *newname = new char[size+1];
    for (int i=0;i<size;i++){
        newname[i]=a[i];
    }
    newname[size]='\0';
    name = newname;
}
Book::~Book(){
    delete[] name;
}


// Question 8

#include <iostream>
using namespace std;

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    Array(const Array<T> & other); // Copy constructor
    Array<T> & operator=(const Array<T> & other){
        cout<<"Call assignment operator"<<endl;
        T *newarr =new T[other.size];
    for (int i = 0;i<other.size;i++){
        newarr[i]=other.p[i];
    }
    delete[] this->p;
    this->size = other.size;
    this->p=newarr;
    
    }; // Copy assignment operator
    
    void print();

private:
    int size;
    T * p;
};

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "")
            << this->p[i];
    }
    cout << endl;
}

template<typename T>
Array<T>::Array(const Array<T> & other){
    cout<<"Call copy constructor"<<endl;
    this->size = other.size;
    T *newarr =new T[other.size];
    for (int i =0;i <other.size;i++){
        newarr[i]=other.p[i];
    }
    this->p = newarr;
}