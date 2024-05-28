/*_____________________________________Linked list____________________________________*/

// Question 1

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

bool isEqual(node *head1, node *head2)
{
  int i = 0;
  int Check = 1;
  while ((head1->next != nullptr) && (head2->next != nullptr)) {
      if (head1->data != head2->data ){
          Check = 0;
          break;
      }
      head1 = head1->next;
      head2 = head2->next;
      i++;
  }
  if ((Check == 1)&&((head1->next == nullptr)&&(head2->next == nullptr))&&(head1->data == head2->data ))
 
    return true;
    else return false;
}
int main()
{
  int n = 0;
  cin>> n;
  node *head1 = createLinkedList(n);
  int m = 0;
  cin>> m;
  node *head2 = createLinkedList(m);
  cout << isEqual(head1, head2) << endl;
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

int countNode(node* head)
{
    int i =1;
  while (head->next != nullptr)
  {
      head = head->next;
    i++;
  }
  return i;
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
  cout<<endl;
  cout<<countNode(head);
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
node *createLinkedList(int n)
{
  node *headnew = new node;
  headnew =nullptr;
  int input;
  for (int i = 0 ; i<n;i++){
      cin >>input;
      node *p = new node;
        p->data = input;
        p->next = headnew;
        headnew = p;
      
  }
  return headnew;
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


/*____________________________________________OOP___________________________________________*/

// Question 1

class Integer {
    private:
    int val;
    public:
    Integer(int a){
            val=a;
    }
    void setValue(int a){
        val = a;
    }
    int getValue(){
        return val;
    }
};


// Question 2

class ClockType
{
public:
    ClockType(int, int, int);
    ClockType();    
    void printTime() const;
    void setTime(int, int, int);
    
    void getTime(int&, int&, int&) const;
    

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

void ClockType:: getTime(int& a, int& b, int& c) const {
    a = hr;
    b = min;
    c = sec;
}


// Question 3


class Room {
    private:
    double length,breadth,height;
    public:
    Room(double a, double b ,double c){
        length = a;
        breadth = b;
        height = c;
    }
    double calculateArea(){
        return (length*breadth);
    }
    double calculateVolume(){
        return (length*breadth*height);
    }
};


//Question 4

template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    void setAt(int idx, const T & value);
    T getAt(int idx);
    T& operator[](int idx);
    
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
T &Array<T>::operator[](int idx){
      if ((idx>=0)&&(idx<size))
    return p[idx];
    else p[idx] = -1;
}


// Question 5


class ClockType
{
public:
    ClockType();
      
    void setTime(int, int, int);
    void printTime() const;

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

void ClockType::setTime(int a, int b, int c) {
    if ((a >= 0)&&(a<24))
    hr = a ;
    else hr =0;
    if ((b >= 0)&&(b<60))
    min = b;
    else min =0;
    if ((c >= 0)&&(c<60))
    sec = c;
    else sec = 0;
}

// Question 6

class ClockType
{
   public:
      ClockType(int, int, int); //constructor with parameters
      ClockType(); //default constructor
      
      void printTime() const;

   private:
      int hr;
      int min;
      int sec;
};

void ClockType::printTime() const { 
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

ClockType::ClockType(int a, int b, int c){
           if ((a >= 0)&&(a<24))
             hr = a ;
    else hr =0;
    if ((b >= 0)&&(b<60))
    min = b;
    else min =0;
    if ((c >= 0)&&(c<60))
    sec = c;
    else sec = 0;
      } 
ClockType::ClockType(){
          hr = 0;
          min =0;
          sec = 0;
      } 


// Question 7

#include<iostream>

using namespace std;

class Course {
    private:
        int ID;
        int numOfStudent;
        int numOfTeacher;
        int numOfTA;
    public:
        void getinfo();
        void getinfo2();
        void disinfo();
};

void Course::getinfo() {
   cout << "ID: ";
   cin >> ID;
   cout << "Number of Students: ";
   cin >> numOfStudent;
   cout << "Number of Teachers: ";
   cin >> numOfTeacher;
   cout << "Number of TAs: ";
   cin >> numOfTA;
}
void Course::getinfo2() {
   cin >> ID;
   cin >> numOfStudent;
   cin >> numOfTeacher;
   cin >> numOfTA;
}

void Course::disinfo()
{
   cout<<endl;
   cout<< "CourseID = "<< ID << endl;
   cout<< "Number of student = " << numOfStudent << endl;
   cout<< "Number of teacher = " << numOfTeacher << endl;
   cout<< "Number of TA = " << numOfTA<< endl;
}


int main() {
    int n;
    cin >>n;
    Course* coursenew = new Course[n];
    
     for (int i = 0;i< n;i++){
     coursenew[i].getinfo();}
    for (int i = 0;i< n;i++){
     coursenew[i].getinfo2();
     coursenew[i].disinfo();}
    return 0;
}