/*_____________________________________Linked_list_________________________________________*/

// Question 1

#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly
int countnode(node *head){
    node *p = new node;
    p =head;
    int coun = 1;
    while (p->next != NULL){
        coun++;
        p = p->next;
    }
    return coun;
}
node* evenThenOddLinkedList(node *head)
{
    
  node *newhead = new node;
  newhead =NULL;
  node *newnext = new node;
  newnext = newhead;
  node *p = new node;
  p = head;
  int lentlist = countnode(head);
  for (int i = 0; i <lentlist;i++){
      
      if (p->data % 2 == 0){
          if (newnext == NULL){
              node *newn = new node;
              newn->data = p->data;
              newhead = newn;
              newnext = newhead;
          }
        else{  node *newn = new node;
          newn->data = p->data;
          newnext->next = newn;
          newnext =newn;}
      }
       p = p->next;
  }
p = head;
  for (int i = 0; i <lentlist;i++){
      
      if (p->data % 2 == 1){
          if (newnext == NULL){
              node *newn = new node;
              newn->data = p->data;
              newhead = newn;
              newnext = newhead;
          }
        else{  node *newn = new node;
          newn->data = p->data;
          newnext->next = newn;
          newnext =newn;}
      }
       p = p->next;
  }
  return newhead;
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
  head = evenThenOddLinkedList(head);
  print(head);
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
void mergeList(node* head1, node* head2)
{
  node *p =new node;
  p =head1;
  while (p->next != NULL){
      p = p->next;
  }
  p->next = head2;
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
  int m;
  cin>>m;
  node *head1 = createLinkedList(m);
  mergeList(head, head1);
  print(head);
  return 0;
}


/*_______________________________________________OOP______________________________*?


// Question 1

template <class T> 
class Array2D {
private:
	int r;
	int c;
	T** arr;
    void init(int _r, int _c) {
        r = _r;
        c = _c;
        arr = new T* [r];
        for (int i = 0; i < r; ++i) {
            arr[i] = new T[c];
        }
    }
public:
    Array2D(int a,int b){
       init(a,b);
    }
    Array2D(int a,int b,T value){
        init(a,b);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                arr[i][j] = value;
            }
        }
    }
    ~Array2D(){
        for (int i = 0;i<r;i++){
            delete[] arr[i];
        }
        delete[] arr;
    }
    Array2D* operator * (const Array2D & a){
        if (c != a.r)
        return NULL;
        
            Array2D *newone = new Array2D(r,a.c);
            for (int i =0; i< r;i++){
                for (int j =0;j<a.c;j++){
                    newone->arr[i][j] =0;
                    for (int m =0; m <c;m++){
                    newone->arr[i][j] =newone->arr[i][j] + arr[i][m] * a.arr[m][j];
                    }
                }
            }
            return newone;
        
    }
    
    T* operator[] (int i) {
        return this->arr[i];
    }

    int getR() {return this->r;}
    int getC() {return this->c;}
    
    void disp() {
        for (int i = 0; i < this->r; i++) {
            for (int j = 0; j < this->c; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// Question 2

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    void setAt(int idx, const T & value);
    T getAt(int idx);
    
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
void Array<T>:: setAt(int idx, const T & value){
    if ((idx < 0)||(idx >=size))
    {
        throw -1;
    }
    else {
        p[idx] = value;
    }
}
template<typename T>
T Array<T>:: getAt(int idx){
    if ((idx < 0)||(idx >=size))
    {
        throw -1;
    }
    else {
        return p[idx];}
}


// Question 3

#include <iostream>

using namespace std;

class Coordinate{
    private:
    float x;
    float y;
    public:
    Coordinate(float a, float b){
        x = a;
        y = b;
    }
    void setX(float a){
        x = a;
    }
    float getX(){
        return x;
    }
    void setY(float a){
        y = a;
    }
    float getY(){
        return y;
    }
    float distanceTo(Coordinate & a){
        return abs(x - a.x) + abs(y - a.y);
    }
};

int main () {
    float Xa, Xb, Ya, Yb;
    cin >> Xa >> Xb >> Ya >> Yb;
    Coordinate a(1,2);
    Coordinate b(0,1);
    cout << a.distanceTo(b) << endl;
    a.setX(Xa); a.setY(Ya);
    b.setX(Xb); b.setY(Yb);
    cout << abs(a.getX() - b.getX()) + abs(a.getY() - b.getY()) << endl;
    cout << a.distanceTo(b) << endl;
    cout << abs(Xa - Xb) + abs(Ya - Yb);
    return 0;
}