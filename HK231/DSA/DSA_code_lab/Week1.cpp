/*---------------------------------------Array_List---------------------------------------------*/

// Question 1

/*

The prices of all cars of a car shop have been saved as an array called N. Each element of the array N is the price of each car in shop. A person, with the amount of money k want to buy as much cars as possible. 
Request: Implement function
buyCar(int* nums, int length, int k);
Where nums is the array N, length is the size of this array and k is the amount of money the person has. Find the maximum cars this person can buy with his money, and return that number.
Example:
nums=[90, 30, 20, 40, 50]; k=90; 
The result is 3, he can buy the cars having index 1, 2, 3 (first index is 0).
Note: The library iostream, 'algorithm' and using namespace std have been used. You can add other functions but you are not allowed to add other libraries. */


int buyCar(int* nums, int length, int k) {
    int *arr = new int[length];
    for (int i = 0;i<length;i++){
        arr[i]=nums[i];
    }
    for (int i = 0;i<length;i++){
        int temp = arr[i];
        int j;
        for(j = i-1;(j>=0)&&(temp<arr[j]);j-- ){
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
    int count=0;
    for (int i = 0;i<length;i++){
        if (k>=arr[i]){
            k = k -arr[i];
            count++;
        }
        else{
            break;
        }
    }
    delete [] arr;
    return count;
}


// Question 2

/*

Given an array of integers.
Your task is to implement a function with the following prototype:
bool consecutiveOnes(vector<int>& nums);
The function returns if all the 1s appear consecutively in nums. If nums does not contain any elements, please return true

Note:
- The iostream and vector libraries have been included and namespace std are being used. No other libraries are allowed.
- You can write helper functions.
- Do not use global variables in your code.  */


bool consecutiveOnes(vector<int>& nums) {
    if (nums.empty() == true) return true;
    int check = 0;
    for (int i = 0;i<nums.size();i++){
        if (check == 1){
            if (nums.at(i)==1)
            continue;
            else{
                check = 2;
            }
        }
        
        if (check == 2){
            if (nums.at(i)==1){
                return false;
            }
            else {continue;}
        }
        
        if(nums.at(i)==1)
        check = 1;
    }
    if (check == 0)return false;
    else return true;
}


// Question 3

/*

Given an array of integers.
Your task is to implement a function with following prototype:
int equalSumIndex(vector<int>& nums);
The function returns the smallest index i such that the sum of the numbers to the left of i is equal to the sum of the numbers to the right.
If no such index exists, return -1.

Note:
- The iostream and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.   */


int equalSumIndex(vector<int>& nums) {
    int sum=0;
    for (int i =0;i<nums.size();i++){
        sum+=nums.at(i);
    }
    int sumleft = 0;
    for (int i =0;i<nums.size();i++){
        if (sumleft==sum-sumleft-nums.at(i)) return i;
        else {
            sumleft+=nums.at(i);
        }
    }
    return -1;
}


// Question 4

/*

Given an array of strings.
Your task is to implement a function with following prototype:
int longestSublist(vector<string>& words);
The function returns the length of the longest subarray where all words share the same first letter.

Note:
- The iostream and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.   */


int longestSublist(vector<string>& words) {
    if (words.empty() == true)return 0;
    int i=0;
    int max = 1;
    int count;
    while (i<words.size()){
        string a =words.at(i);
        count = 1;
        i++;
        while (i<words.size()){
            if (a[0]!=words.at(i)[0]){
                if (count > max) max = count;
                break;}
            else{
                i++;
                count++;
            }
        }
    }
    if (count > max) max = count;
    return max;
}


// Question 5

/*

Implement methods ensureCapacity, add, size in template class ArrayList representing the array list with type T with the initialized frame. The description of each method is given in the code.
template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
    ~ArrayList(){ delete[] data; }
    void    add(T e);
    void    add(int index, T e);
    int     size();
    void    ensureCapacity(int index);
};   */



template<class T>
void ArrayList<T>::ensureCapacity(int cap){
   
    if (cap == capacity ){
        int newcapacity = capacity*1.5;
        T *arr = new T[newcapacity];
        for (int i = 0;i<count;i++){
            arr[i]=data[i];
        }
        delete [] data;
        data=arr;
        capacity = newcapacity;
    }
    
}

template <class T>
void ArrayList<T>::add(T e) {
    ensureCapacity(count+1);
    data[count++]=e;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    
        if (index<0||index>count)
            throw std::out_of_range("the input index is out of range!");
        else{
            ensureCapacity(count+1);
            for (int i = count-1;i>=index;i--){
                data[i+1]=data[i];
            }
            data[index]=e;
            count++;
        }
}

template<class T>
int ArrayList<T>::size() {
    return count;
    return 0;
}


// Question 6

/*

Implement methods removeAt, removeItem, clear in template class ArrayList representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
   ~ArrayList(){ delete[] data; }    
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
    void    ensureCapacity(int index);
};     */

template<class T>
T ArrayList<T>::removeAt(int index){
    
    if (index<0||index>=count)
        throw std::out_of_range("index is out of range");
    else{
        T temp = data[index];
        for (int i = index;i<count;i++){
            data[i]=data[i+1];
        }
        count--;
        return temp;
    }
    
}

template<class T>
bool ArrayList<T>::removeItem(T item){
    for (int i =0;i<count;i++){
        if (data[i]==item){
            removeAt(i);
            return true;
        }
    }
    return false;
}

template<class T>
void ArrayList<T>::clear(){
    if (data == NULL) return;
    delete []data;
    capacity = 5; count = 0; data = new T[5];
}



// Question 7

/*

Given an array of integers nums and a two-dimension array of integers operations.
Each operation in operations is represented in the form {L, R, X}. When applying an operation, all elements with index in range [L, R] (include L and R) increase by X.
Your task is to implement a function with following prototype:
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations);
The function returns the array after applying all operation in operations.

Note:
- The iostream, and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.   */

vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    vector<int> result = nums;
    int n = operations.size();
    for (int i =0;i<n;i++){
        vector<int> temp = operations.at(i);
        for (int j = temp.at(0);j<=temp.at(1);j++){
            result.at(j)=result.at(j)+temp.at(2);
        }
    }
    return result;
}



/*----------------------------------------OOP---------------------------------------------------*/

// Question 1

/*

In the coordinate plane, we have class Point to store a point with it's x-y coordinate.
Your task in this exercise is to implement functions marked with /*  * STUDENT ANSWER   */.
Note: For exercises in Week 1, we have #include <bits/stdc++.h> and using namespace std;  */


class Point
{
private:
    double x, y;

public:
    Point()
    {
        x =0;
        y =0;
    }

    Point(double x, double y)
    {
        this->x=x;
        this->y=y;
    }

    void setX(double x)
    {
        this->x = x;
    }

    void setY(double y)
    {
        this->y=y;
    }

    double getX() const
    {
       return x;
    }

    double getY() const
    {
        return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        double xA = pointA.getX(), yA = pointA.getY();
        
        return (double) sqrt((x-xA)*(x-xA) + (y-yA)*(y-yA));
    }
};

// Question 2
/*

In the coordinate plane, a circle is defined by center and radius.
Your task in this exercise is to implement functions marked with /*  * STUDENT ANSWER   */.
Note: you can use implemented class Point in previous question  */


class Point
{
   private:
    double x, y;
public:
    Point()
    {
        x =0;
        y =0;
    }

    Point(double x, double y)
    {
        this->x=x;
        this->y=y;
    }

    void setX(double x)
    {
        this->x = x;
    }

    void setY(double y)
    {
        this->y=y;
    }

    double getX() const
    {
       return x;
    }

    double getY() const
    {
        return y;
    }

    double distanceToPoint(const Point& pointA)
    {
        double xA = pointA.getX(), yA = pointA.getY();
        
        return (double) sqrt((x-xA)*(x-xA) + (y-yA)*(y-yA));
    }
};

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle():center(Point()){}

    Circle(Point center, double radius):center(center),radius(radius){}

    Circle(const Circle &circle):center(circle.center),radius(circle.radius){}
    
    void setCenter(Point point)
    {
        center = point;
    }

    void setRadius(double radius)
    {
        this->radius=radius;
    }

    Point getCenter() const
    {
        return center;
    }

    double getRadius() const
    {
        return radius;
    }
    
    void printCircle()
    {
        printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
    }
};


// Question 3

/*

In a game, we have class Character to store characters' data.
The class Character is declared as below:
class Character {
protected:
    int hp;
    int x;
    int y;
public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
};
Your task is to define the constructors and the methods of the class.

Note:
In this task, iostream library has been included, and namespace std is being used. No other libraries are allowed.  */


Character::Character() {
    x = 0;
    y = 0;
    hp= 0;
}

Character::Character(int hp, int x, int y) {
    this->x = x;
    this->y = y;
    this->hp = hp;
}

int Character::getHp() {
    return hp;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

int Character::getX() {
    return x;
}

void Character::setX(int x) {
    this->x = x;
}

int Character::getY() {
    return y;
}

void Character::setY(int y) {
    this->y=y;
}

int Character::getManhattanDistTo(Character* other) {
    int x1 = other->getX();
    int y1 = other->getY();
    return abs(x-x1)+abs(y-y1);
}


// Question 4

/*

Hoang is a K19 student studying at Bach Khoa University. He plans to write a book management software for the library. In the class design, Hoang has designed the class Book as follows:
class Book
{
private:
    char* title; 
    char* authors; 
    int publishingYear; 
public: 
   // some method
}
Your task in this exercise is to implement functions marked with /*  * STUDENT ANSWER   */.
Note: For exercises in Week 2, we have #include <bits/stdc++.h> and using namespace std;    */


class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
       publishingYear = 0;
       title = nullptr;
       authors = nullptr;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        this->title = new char(strlen(title));
        strcpy(this->title,title);
        
        this->authors = new char(strlen(authors));
        strcpy(this->authors, authors);
        this->publishingYear= publishingYear;
    }

    Book(const Book &book)
    {
        this->title = new char(strlen(title));
        strcpy(this->title,book.getTitle());
        
        this->authors = new char(strlen(authors));
        strcpy(this->authors, book.getAuthors());
        this->publishingYear= publishingYear;
    }
    
    void setTitle(const char* title)
    {
       this->title = new char(strlen(title));
       strcpy(this->title,title);
    }

    void setAuthors(const char* authors)
    {
        this->authors = new char(strlen(title));
        strcpy(this->authors,authors);
    }

    void setPublishingYear(int publishingYear)
    {
        this->publishingYear=publishingYear;
    }

    char* getTitle() const
    {
        return title;
    }

    char* getAuthors() const
    {
        return authors;
    }

    int getPublishingYear() const
    {
        return publishingYear;
    }

    ~Book()
    {
        delete title;
        delete authors;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};



// Question 5

/*

1.In the toy store, all toy has a price. Car toy has a price and color, Puzzle toy has a price and size. We have to implement class CarToy and class PuzzleToy which inherit from class Toy.
2.class ToyBox has a  pointer array to store a list of toys (up to 5 items including car and puzzle) and number of items in the box.
Your task is to implement two function addItem(…) in class ToyBox. If successfully added, the function returns the current number of toys in the box. If the box is full, return -1.    */


enum Color
{
    red,
    green,
    blue
};
enum Size
{
    small,
    medium,
    big
};

class Toy
{
protected:
    double price;

public:
    Toy(double price)
    {
        this->price = price;
    }

    virtual void printType() = 0;
    friend class ToyBox;
};

class CarToy : public Toy
{
private:
    Color color;

public:
    CarToy(double price, Color color) : Toy(price)
    {
        this->color = color;
    }

    void printType()
    {
        cout << "This is a car toy\n";
    }

    friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
    Size size;

public:
    PuzzleToy(double price, Size size) : Toy(price)
    {
        this->size = size;
    }

    void printType()
    {
        cout << "This is a puzzle toy\n";
    }

    friend class ToyBox;
};

class ToyBox
{
private:
    Toy* toyBox[5];
    int numberOfItems;

public:
    ToyBox()
    {
        numberOfItems = 0;
        for (int i = 0;i<5;i++){
            toyBox[i]= nullptr;
        }
        
    }
    
    int addItem(const CarToy& carToy)
    {
        if (numberOfItems == 5) return -1;
        else {
            toyBox[numberOfItems++] = new CarToy(carToy.price,carToy.color);
            
        }
        return numberOfItems;
    }
    
    int addItem(const PuzzleToy& puzzleToy)
    {
        if (numberOfItems == 5) return -1;
        else {
            toyBox[numberOfItems++] = new PuzzleToy(puzzleToy.price,puzzleToy.size);
        }
        return numberOfItems;
    }
    
    void printBox()
    {
        for (int i = 0; i < numberOfItems; i++)
            toyBox[i]->printType();
    }
};



/*-----------------------------------------Recursion-------------------------------------------*/
// Question 1
// Question 2

/*
Implement function 
void printArray(int n){}
to print 0, 1, 2, ..., n (n is positive integer and has no space at the end).
Please note that you can't using key work for, while, goto (even in variable names, comment).
For this exercise, we have #include <iostream> and using namespace std;   */

void printArray(int n)
{
    if (n==0) cout<<"0";
    else {printArray(n-1);
    cout<<", "<<n;}
}


// Question 3

/*

Given a positive number, print following a pattern without using any loop.
Input: n = 16
Output: 16, 11, 6, 1, -4, 1, 6, 11, 16 (has no space at the end)

Input: n = 10
Output: 10, 5, 0, 5, 10 (has no space at the end)
We basically first reduce 5 one by one until we reach a negative or 0. After we reach 0 or negative, we one add 5 until we reach n.
Note: Please note that you can't using key work for, while, goto (even in variable names, comment).
You can implement other recursive functions if needed.
For this exercise, we have #include <iostream> and using namespace std;   */

void printPattern(int n) 
{ 
    if (n<=0)cout<<n;
    else {cout<<n<<" ";
    printPattern(n-5);
    cout<<" "<<n;}
}


// Question 4

/*
Implement function
int findMax(int* arr, int length){}
to find the largest element using recursion (with length is the number of elements in integer array arr).
Please note that you can't using key work for, while, goto (even in variable names, comment).
For this exercise, we have #include <iostream> and using namespace std;   */

int findMax(int* arr, int length)
{
    if (length == 1) return arr[length-1];
    else {
        int a =findMax(arr,length-1);
        if (a>arr[length-1]) return a;
        else return arr[length-1];
        
    }
    
}


// Question 5

/*

Implement function 
bool isPalindrome(string str){}
to check if the given non empty string is palindrome, else not palindrome using recursion.
In test case, for extra point, we will have some palindrome sentences (All remaining test cases are words).

Please note that you can't using key work for, while, goto (even in variable names, comment).
For this exercise, we have #include <iostream>, #include <string.h> and using namespace std;   */

string white(string& a,int n){
    int i = a.length()-n;
    if (n == 0) return "";
    else if (a[i]== ' ') return white(a,n-1);
    else
    return a[i]+white(a,n-1);
}
bool isPalindrome(string str, int i = 0) 
{ 
    int n = str.length();
    str = white(str,n);
    if (i > n/2)return true;
    else 
    return str[i] == str[str.length()-i-1] && isPalindrome(str, i+1) ;
}


// Question 6

/*

Give two positive integers a and b, implement function
int findGCD(int a, int b){}
to find GCD (Greatest Common Divisor) of a and b using recursion.
Please note that you can't using key work for, while, goto (even in variable names, comment).
For this exercise, we have #include <iostream> and using namespace std;   */


int findGCD(int a, int b)
{
    if (a==0)return b;
    else if (b==0)return a;
    else{
    if (a >= b)    
       return findGCD(a-b,b);
    else return findGCD(a,b-a);}
}


// Question 7

/*

String s contains lowercase letters, digits, "(" and ")", satisfying the following rules:
- Two digits cannot be adjacent.
- Two "(" cannot be adjacent.
- One "(" and one ")" cannot be adjacent.
- After any digit, there must be "(".
- The quantities of "(" and ")" are equal.
Change string s until new string t created, t contains only lowercase letters. These are changing rules:
- Sub-strings with form "n(p)", can change to "pp...p" (n times p), where n is a digit and p is a string.
- If p still contains "(", ")" or digits, continue to implement the above changing method.  
Request: Implement function 
expand(string s);
Where s is a string with the above form; return the result is a string containing only lowercase letters.
Example:
- String "2(ab3(cde)x)" changes into "abcdecdecdexabcdecdecdex".
- String "2(x0)3(z)" changes into "xxzzz".
Note: In this exercise, libraries iostream, string and using namespace std; have been used. You can add other functions for your answer, but you are not allowed to add other libraries.  */


string expand(string s) {                   //2(3(x)ab)
    int found = s.find('_');
    
    if (s=="") return "";
    
    else if (s[0] >= '0' && s[0] <= '9') {
        int num = 0;
        if (s!="" && s[0] >= '0' && s[0] <= '9') {
            num = num*10 + s[0]-'0'; s = s.substr(1);
        }
        if (s!="" && s[0] >= '0' && s[0] <= '9') {
            num = num*10 + s[0]-'0'; s = s.substr(1);
        }
        if (s!="" && s[0] >= '0' && s[0] <= '9') {
            num = num*10 + s[0]-'0'; s = s.substr(1);
        }
        
        string tmp = expand(s.substr(1));
        return expand("_" + to_string(num) + tmp);
    }
    
    else if (found != -1) {
        int under = s.find('_');
        string head = s.substr(0,under);
        s = s.substr(under + 1);
        
        int num = 0;
        if (s!="" && s[0] >= '0' && s[0] <= '9') {
            num = num*10 + s[0]-'0'; s = s.substr(1);
        }
        if (s!="" && s[0] >= '0' && s[0] <= '9') {
            num = num*10 + s[0]-'0'; s = s.substr(1);
        }
        if (s!="" && s[0] >= '0' && s[0] <= '9') {
            num = num*10 + s[0]-'0'; s = s.substr(1);
        }
        
        int brack = s.find(')');
        if (num==0)
            return head + s.substr(brack+1);
        if (num==1) 
            return head + s.substr(0, brack) + s.substr(brack+1);
            
        return expand(head + s.substr(0, brack) + "_" + to_string(num-1) + s);
    }
    
    return s[0] + expand(s.substr(1));
}



// Question 8

/*

Give a positive integer x, implement recursive function
void printHailstone(int number){}
to print the Hailstone Sequence of a given number upto 1 (no space at the end).
Hailstone Sequences follow these rules: 
If a number is even, divide it by 2 
If a number is odd, multiply it by 3 and add 1.
Example:
 If number = 5. 5 is odd number so next number is 5*3 + 1 = 16. 16 is even number so next number is 16/2 = 8...
 Finally, we get Hailstone sequence: 5 16 8 4 2 1.
You can find more information at: https://diendantoanhoc.net/topic/89145-d%C3%A3y-s%E1%BB%91-hailstone/
Note: Please note that you can't using key work for, while, goto (even in variable names, comment).
You can implement other recursive functions if needed.
For this exercise, we have #include <iostream> and using namespace std;  */


void printHailstone(int number)
{
    if (number == 1){cout<<"1";
    return;}
    if(number % 2 == 1) {
        cout<< number<<" ";
    printHailstone(number*3+1);
    }
    else {
        cout<< number<<" ";
    printHailstone(number/2);
    }
}



// Question 9

/*

Function
int myArrayToInt(char* str, int n){}
takes a string str (which represents an positive decimal number), n is the number of elements in the string as arguments and returns its value.
Please note that you can't using key work for, while, goto (even in variable names, comment)
For this exercise, we have #include <iostream>, #include <string.h> and using namespace std;
*/


int myArrayToInt(char *str, int n) 
{ 
    if (n == 1) return (int)(str[0]-'0');
    return (int)(str[0]-'0')*pow(10,n-1)+myArrayToInt(str+1,n-1);
    
}


// Question 10

/*

Give two positive integers a and b, implement function
int findLCM(int a, int b){}
to find LCM (Lowest Common Multiple) of a and b using recursion.
Please note that you can't using key work for, while, goto (even in variable names, comment).
For this exercise, we have #include <iostream> and using namespace std;  */


int findGCD(int a, int b)
{
    if (a==0)return b;
    else if (b==0)return a;
    else{
    if (a >= b)    
       return findGCD(a-b,b);
    else return findGCD(a,b-a);}
}
int findLCM(int a, int b)
{
    return (a/findGCD(a,b))*b;
}


// Question 11

/*

Given a string s consisting only of '(' and ')'.
Your task is to implement a function with following prototype:
int mininumBracketAdd(string s);
The function returns the mininum number of brackets needed to be inserted to s so that the brackets are balanced.

More info:
A sequence of brackets is balanced when there are no unmatched brackets.
Example: ()(()) is balanced, but ))() is not.

Note:
- The iostream library has been used and namespace std is being used. No other libraries are allowed.
- Using loop keywords (for, while, do) are not allowed, even in comments and variable names.
- You can write helper functions.  */


void deletebracket(string& s) {
    if (s.find("()") != string::npos) deletebracket(s.replace(s.find("()"),2,""));
    else return ;
}
int mininumBracketAdd(string s) {
    deletebracket(s);
     return s.length();
}

// Question 12

/*

Given a string s representing a sentence consisting only of a-z and A-Z and space character.
Your task is to implement a function with following prototype:
string reverseSentence(string s);
The function returns the reverse sentence of sentence s.
The testcases ensure that there is only one space character between two adjacent words, and the sentences do not begin or end with any space characters.

Note:
- The iostream library has been used and namespace std is being used. No other libraries are allowed.
- Using loop keywords (for, while, do) are not allowed, even in comments and variable names.
- You can write helper functions.   */

string reverseSentence(string s) {
    if (s.find_last_of(" ")==string::npos) return s;
    int i = s.find_last_of(" ");
    string a = s.substr(i+1,s.length()-1-i);
    s.replace(i,s.length()-i,"");
    return a+" " +reverseSentence(s);
    
}

// Question 13

/*

Given a string, implement function
int strLen(char* str){}
to calculate length of the string using recursion.
Please note that you can't using key work for, while, goto (even in variable names, comment).
For this exercise, we have #include <iostream> and using namespace std;   */


int strLen(char* str)     
{ 
    if (*str=='\0') return 0;
    return 1 + strLen(str+1);
} 


/*--------------------------------------------------Single-Linklist--------------------------------*/


// Question 1

/*
Class LLNode is used to store a node in a singly linked list, described on the following:
class LLNode {
    public:
        int val;
        LLNode* next;
        LLNode();
        LLNode(int val, LLNode* next);
}
Where val is the value of node, next is the pointer to the next node.
Request: Implement function:
LLNode* addLinkedList(LLNode* l0, LLNode* l1);
Where l0, l1 are two linked lists represented positive integers, each node is a digit, the head is the least significant digit (the value of each node is between 0 and 9, the length of each linked list is between 0 and 100000). This function returns the linked list representing the sum of the two integers.
Example:
Given l0 = [2, 3] (representing 32) and l1 = [1, 8] (representing 81). The result would be l0 = [3, 1, 1] (representing 32 + 81 = 113).
Note:
In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std are used. You can write helper functions and classes. Importing other libraries is allowed, but not encouraged, and may result in unexpected errors.    */


LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    if (l0==NULL && l1 == NULL){
        return NULL;
    }
    queue<int> qu;
   qu.push((l0->val+l1->val)%10);
    int remainder = (l0->val+l1->val >= 10) ? 1:0;
    l0=l0->next;
    l1=l1->next;
    while (l0 != NULL && l1 != NULL){
        qu.push((l0->val+l1->val+remainder)%10);
        
        if (l0->val+l1->val+remainder >= 10) remainder = 1;
        else remainder = 0;
        l0 = l0->next;
        l1 = l1->next;
    }
    while (l0 != NULL){
        qu.push((l0->val+remainder)%10);
        if (l0->val+remainder >= 10) remainder = 1;
        else remainder = 0;
        l0 = l0->next;
    }
     while (l1 != NULL){
        qu.push((l1->val+remainder)%10);
        if (l1->val+remainder >= 10) remainder = 1;
        else remainder = 0;
        l1 = l1->next;
    }
    if (remainder == 1) {
        qu.push(1);
    }
    LLNode* head = new LLNode;
    head->val = qu.front();
    qu.pop();
    head->next = NULL;
    LLNode* temp = head;
    while (qu.size()>0){
        LLNode* newNode = new LLNode;
        newNode->val = qu.front();
        qu.pop();
        newNode->next = NULL;
        temp->next = newNode;
        temp=temp->next;
    }
    return head;
}



// Question 2

/*

Polynomials is an important application of arrays and linked lists. A polynomial is composed of different terms where each of them holds a coefficient and an exponent. A polynomial p(x) is the expression in variable x which is in the form (anxn + an-1xn-1 + .... + a1x+ a0), where an, an-1, ...., a0 fall in the category of real numbers and 'n' is the non-negative integer, which is called the degree of polynomial.

Example: 10x2 + 26x, here 10 and 26 are coefficients and 2, 1 is its exponential value.

Points to keep in Mind while working with Polynomials:
- The sign of each coefficient and exponent is stored within the coefficient and the exponent itself.
- The storage allocation for each term in the polynomial must be done in descending order of their exponent.
In this question, complete SLinkedList class is included. You should use this class to complete your Polynomial class with initialized frame as following. This task is implement insertTerm to insert a term into a polynomial.

class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};  */


void Polynomial::insertTerm(const Term& term) {
    double coe = term.coeff;
    int ex = term.exp;
    
    this->insertTerm(coe, ex);
}

void Polynomial::insertTerm(double coeff, int exp) {
    int coe = 0;

    for (int i = 0; i<terms->size(); i++) {
        Term get = terms->get(i);
        if (get.exp == exp) {
            coe = get.coeff;
            terms->removeAt(i);
        }
    }
    
    if (coe + coeff == 0) return;
    
    Term put(coe + coeff, exp);
    if (terms->size()==0) {terms->add(put); return;}

    for (int it = 0; it<terms->size(); it++) {
        Term get = terms->get(it);
        if (get.exp < exp) {
            terms->add(it, put);
            return;
        }
    }
    
    terms->add(put);
}



// Question 3

/*

Implement Iterator class in class SLinkedList. 
Note: Iterator is a concept of repetitive elements on sequence structures. Iterator is implemented in class vector, list in STL container in C++ (https://www.geeksforgeeks.org/iterators-c-stl/). Your task is to implement the simple same class with iterator in C++ STL container.
Please read example and testcase carefully.
template <class T>
class SLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
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
        friend class SLinkedList<T>;
    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(SLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};         */


template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * IF begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * ELSE begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
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
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}   

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
    // if (current == NULL){
    //     throw std::out_of_range("Segmentation fault!");
    // }
    // if (this->current == this->pList->head){
    //     this->current = NULL;
    //     this->index = -1;
    //     this->pList->removeAt(0);
    // }
    // else {
    //     this->index--;
    //     Node *temp = this->pList->head;
    //     while (temp->next!=this->current){
    //         temp = temp->next;
    //     }
    //     this->current=temp;
    //     Node *del = this->current->next;
    //     this->current->next = this->current->next->next;
    //     delete del;
    // }
    if (this->current==NULL) throw std::out_of_range("Segmentation fault!");
    
    Node* curr = this->pList->head;
    if (this->current==this->pList->head) {
        this->current = NULL;
        this->index = -1;
        this->pList->removeAt(0);
    }
    else {
        while ( curr->next != this->current) curr = curr->next;
        Node* del = curr->next;
        
        this->current = curr;
        this->index = this->index - 1;
        
        curr->next = del->next;
        if (del==this->pList->tail) this->pList->tail = curr;
        this->pList->count -= 1;
        
        delete del;
    }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (this->current == NULL)
        throw std::out_of_range("Segmentation fault!");
    this->current->data = e;
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (this->current == NULL)
        throw std::out_of_range("Segmentation fault!");
    return this->current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
    if (this->index == iterator.index && this->current == iterator.current) return false;
    return true;
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (this->current == NULL) 
          throw std::out_of_range("Segmentation fault!");
    
    this->current =this-> current->next;
    this->index++;
    return *this;
    
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
    //Node* nail = this->current;
    
    Iterator tmp = *this;
    this->current = this->current->next;
    this->index++;
    
    return tmp;
}



// Question 4

/*

Class LinkedList is used to represent single linked list, described as the following:
class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
void partition(int k);
};
In this class; head, tail and size are the pointers of the first element, the last element and size of linked list.
Request: Implement function 
void LinkedList::partition(int k);
To rearrange elements in this linked list by this way: split all elements of this linked list to 3 groups include: group I (the value  of each element is smaller than k), group II (the value of each element is equal to k) and group III (the value of each element is larger than k); after that, move group I to the head  of linked list, group II is after group I and group III is after group II. Note that the orders of the elements of each group are unchanged.
Example:
- The given linked list: 10->55->45->42->50
- k=45
In this case, group I includes elements with value 10 and 42, group II includes elements with 45 and group III includes elements with value 55 and 50. Rearrange by above way,  this linked list will become 10->42->45->55->50 (the orders of th elements in each group is unchanged: 10 before 42 and 55 before 50). 
Note: In this exercise, libraries iostream, sstream and using namespace std; have been used. You can add other functions for your answer, but you are not allowed to add other libraries.       */


void LinkedList::partition(int k) {
    Node * newhead = new Node;
    newhead =  NULL;
    Node * temp = newhead;
    Node * curr = head;
    while  (curr != NULL){
        if (curr->value < k){
        Node * newnode = new Node(curr->value,NULL);
        if (newhead == NULL){
            newhead = newnode;
            temp = newhead;
        }
        else {
            temp->next = newnode;
            temp = temp->next;
        }}
        curr = curr->next;
    }
    
    curr = head;
    while (curr != NULL){
        if (curr->value == k){
        Node * newnode = new Node(curr->value,NULL);
        if (newhead == NULL){
            newhead = newnode;
            temp = newhead;
        }
        else {
            temp->next = newnode;
            temp = temp->next;
        }}
        curr = curr->next;
    }
    curr = head;
      while (curr != NULL){
        if (curr->value > k){
        Node * newnode = new Node(curr->value,NULL);
        if (newhead == NULL){
            newhead = newnode;
            temp = newhead;
        }
        else {
            temp->next = newnode;
            temp = temp->next;
        }}
        curr = curr->next;
    }
    
    while (head != NULL){
        curr = head;
        head = head->next;
        delete curr;
    }
    head = newhead;
    tail = temp;
}


// Question 5

/*

Implement methods add, size in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e);
    void    add(int index, T e);
    int     size();
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
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};     */

template <class T>
void SLinkedList<T>::add(const T& e) {
    
    Node * newnode = new Node;
    newnode->data = e;
    newnode->next = NULL;
    if (head==NULL){
        head = newnode;
        tail = newnode;
        count++;
        return;
    }
    tail->next = newnode;
    tail = tail->next;
    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    Node * curr = head;
    for (int i =0;i<index-1;i++){
        curr = curr->next;
    }
    Node * newnode = new Node;
    newnode->data = e;
    if (head==NULL){
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
        count++;
        return;
    }
    if (index == 0){
        newnode->next = head;
        head = newnode;
        count++;
        return;
    }
    if (index == count){
        newnode->next = NULL;
        tail->next = newnode;
        tail = tail->next;
        count++;
        return;
    }
    newnode->next =  curr->next;
    curr->next = newnode;
    count++;
}

template<class T>
int SLinkedList<T>::size() {
    return count;
}



// Question 6

/*

Implement methods get, set, empty, indexOf, contains in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList(): head(NULL), tail(NULL), count(0);
    ~SLinkedList() { };
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
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
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
}; 			*/


template<class T>
T SLinkedList<T>::get(int index) {
    if (index < 0 || index >= count) return -1;
    Node * cur = head;
    for (int i = 0;i<index;i++){
        cur=cur->next;
    }
    return cur->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    if (index < 0 || index >= count) return ;
    Node * cur = head;
    for (int i = 0;i<index;i++){
        cur=cur->next;
    }
    cur->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    if (head == NULL) return true;
    return false;
    
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    Node * cur = head;
    int i;
    for (i = 0;i<size();i++){
        if (cur->data == item) return i;
        cur=cur->next;
    }
    return -1;
    
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
   Node * cur = head;
    int i;
    for (i = 0;i<size();i++){
        if (cur->data == item) return true;
        cur=cur->next;
    }
    return false;
    
}



// Question 7

/*

Implement methods removeAt, removeItem, clear in template class SLinkedList (which implements List ADT) representing the singly linked list with type T with the initialized frame. The description of each method is given in the code.
template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e);
    void    add(int index, T e);
    int     size();
    bool    empty();
    int     size();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
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
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};			*/


template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= count) return -1;
    Node * cur = head;
    if (index == 0) {
        T temp = cur->data;
        head=head->next;
        delete cur;
        count--;
        if (count == 0){
            tail=NULL;
        }
        return temp;
    }
    
    for (int i = 0;i<index-1;i++){
        cur=cur->next;
    }
  
    if (index == count-1){
        T temp = tail->data;
        Node * dl = tail;
        tail = cur;
        tail->next = NULL;
        delete dl;
        count--;
        if (count == 0){
                head=tail=NULL;
        }
        return temp;
    }

    T temp = cur->next->data;
    Node * dl = cur->next;
    cur->next=cur->next->next;
    delete dl;
    count--;
    if (count == 0){
            head=tail=NULL;
        }
    return temp;
    
} 

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    Node * cur = head;
    if (cur->data == item ){
        head=head->next;
        delete cur;
        count--;
        if (count == 0){
            head=tail=NULL;
        }
        return true;
    }
    int i;
    for (i = 0;i<size();i++){
        if (cur->data == item) {
            removeAt(i);
            return true;
        }
            
        cur=cur->next;
    }
    
    return false;
    
}

template<class T>
void SLinkedList<T>::clear(){
    Node *cur =head;
    while (head!=NULL){
        cur = head;
        head = head->next;
        delete cur;
    }
    
    
    count = 0;
}


// Question 8

/*

Class LLNode representing a node of singly linked lists is declared as below:
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
}
Given a singly linked list head node.
Your task is to implement a function with following prototype:
LLNode* reverseLinkedList(LLNode* head);
The function returns head node of the reversed singly linked list.

Note:
- The iostream library has been included and namespace std is being used. No other libraries are allowed.
- The constructors and methods of class LLNode have been defined fully so you do not need to redefine them.
- You can write helper functions.    */

LLNode* reverseLinkedList(LLNode* head) {
    if (head == NULL ) return NULL;
    LLNode * prev = NULL;
    LLNode * curr = head;
    LLNode * nextnode = head->next;
    while (curr != NULL){
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    head = prev;
    return head;
}



// Question 9

/*

Class LLNode representing a node of singly linked lists is declared as below:
class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
}
Given a singly linked list head node and a integer k.
Your task is to implement a function with following prototype:
LLNode* rotateLinkedList(LLNode* head, int k);
The function returns head node of the rotated singly linked list obtained after rotate the linked list to the right by k places.

Note:
- The iostream library has been used and namespace std is being used. No other libraries are allowed.
- The constructors and methods of class LLNode have been defined fully so you do not need to redefine them.
- You can write helper functions.    */

LLNode* taile(LLNode* head){
    LLNode* curr = head;
    while (curr->next!=NULL){
        curr=curr->next;
    }
    return curr;
}
int count(LLNode* head){
    int coun=1;
    LLNode* curr = head;
    while (curr->next!=NULL){
        curr=curr->next;
        coun++;
    }
    return coun;
}
LLNode* rotateLinkedList(LLNode* head, int k) {
    if (head == NULL) return NULL;
    k =count(head)- k%count(head);
    LLNode* curr = head;
    
    for (int i = k-1;i>0;i--){
    curr =curr->next;
    }
    taile(head)->next=head;
    head=curr->next;
    curr->next = NULL;
    return head;
}