#include<iostream>
#include<string>
using namespace std;


// class teacher{
//     // acess modifiers -> public that can be accesed outside class
//     // public->it can be accesed only within class
//     // by default private is implied in c++ 
    
//     private:
//     double sal ; //we made salary a private

//     public:
//     //constructer -> same name as class , called automatically , made in public only
//     //     teacher(){//non parametrized constructor(without parameters)
//     //     cout<<"Hi,I am constructor\n";
//     //     dept= "CSE";
//     // }
//     string name ;
//     string dept ;
//     string subject ;
//     teacher(string name , string dept , double sal){//parameterized constructor
//         this->name = name ;
//         this->dept =  dept;// this->  refer to the current object and one on the right refer to the parameter of the constructor
//         this->sal =  sal;
//     }
//     //copy constructor;
//     teacher(teacher &obj){//obj is always passed by refrence  , SHALOW COPY-> here is fine but , when dynamically memory(HEAP) is allocated then it give us problem
//         cout<<"Hi ,I am copy constructor\n";
//         this->name = obj.name; //for eg teacher t2(t1) means this->name will point to the object being created 
//         //and obj.name will point to the object that has been passed to the constructer
//         this->dept = obj.dept;
//         this->sal = obj.sal ;

//     }


//     void change_dept(string newdept){//methods or member functions
//         dept = newdept;
//     }
//     void set_salary(int s){//called setter function
//         //we can make a function that set the value of salary 
//         //and this function is public
//         sal = s ;
//     }
//     double get_salary(){//called getter function
//         return sal ;
//     }

// };
// // int main(){

// //     teacher t1("gavy","cse",1000);

// //     cout<<t1.dept<<endl ;


// //     teacher t2(t1);//while using default copy constructor we Can not use default copy constructor when we have defined our own copy constructer
// //     cout<<t2.dept<<endl;
// //     return 0 ;
// // }



// /*ENCAPSULATION: it is the wrapping up of data & member functions in a single unit called class
// we did encapsulation in the teacher class

// it helps in data hiding : we can use private and public with different data so we can use it to hide data 

// */

// /*
// CONSTRUCTOR = Special method invoked 
//               automaticially at the time of object creation

// */





// class student{
// public :

//     string name ;
//     float* cgpaptr ;
//     student(string name  , float cgpa){//this is constructor
//         this->name = name ;
//         cgpaptr = new float ;//dynamically allocating memory to the pointer
//         *cgpaptr = cgpa ;
//     }

//     student(student &s){//copy constructer
//         cout<<"HI  i am your copy constructor"<<endl;
//         this->name = s.name ;
//         //cgpaptr = new float ;//to alloacate a memory in the heap for the pointer
//         //THIS IS DEEP COPY
//         this->cgpaptr = s.cgpaptr;//this->cgpaptr IS SAME AS *cgpaptr
//     }

//     //lets make a distructor
//     // the default destructor deeallocates the static memory and is called itself
//     //however for a synamic memory allocation like that of a pointer the default one is not able to do so 
//     //so we make a custom destructor that deletes the dynamically allocated memory
    
//     //the "new" keyword is used to allocate a memory dynamically
//     //similarly "delete keyword" is used to delete a dynamically stored memory

//     //destructor-> called automatically after execution of the program
//         //have to write a '~' infront to tell it is a destructor
//     ~student(){
//         cout<<"Hi I delete everything.\n";
//         //to delete a dynamically allocated memory that we have assigned like in the copy constructor above
//         //we use:
//         delete cgpaptr;//if we don't use this then cgpaptr memory will not be cleared it can result in memory leak
//     }
    
//     void get_info(){
//         cout<<"nama: "<<name<<endl ;
//         cout<<"cgpa: "<<*cgpaptr<<endl ;
//     }
// };

/*
INHERITANCE : When properties and member functions of base class are passed on to the derived class.
private properties are never inherited

PROTECTED: if we want that the properties of a class be inherited but not and want them to be private then we make the protected
            means they can only be inherited
*/

// class person{
//     public:
//     string name ;
//     int age ;
//     person(string name , int age ){
//         cout<<"i am constructor of parent class\n";
//         this->name = name ;
//         this->age = age ;
//     }
// };

// /*
// first the parent class constructor is called and then lower class's constructors are called

// however for destructor first the destructor of child class is called then the upper class's 
// destructors are called

// */
// class student : public person{//: public person  written to inherit the properties of person class publically
//     //if we write private person then the public properties of person will be inherited but will become private in child class
//     //if the properties of parent class be protacted
//     //so if we inherit it with public/protacted mode then they will be protacted properties in derived class
//     //if we inherit them with private mode then they become private in derived class
//     //name,age,roll no
//     public:
//     int rollno ;
//     student(string name , int age ,int rollno): person(name , age){
//         cout<<"i am derived class's constructor\n";
//         this->rollno = rollno ;
//     }

//     ~student(){
//         cout<<"i am destructor of student\n";
//     }
//     void getinfo(){
//         cout<<name<<endl;
//         cout<<age<<endl;
//         cout<<rollno<<endl;
//     }

// };

/*
//MULTILEVEL INHERITANCE

class person{
    public:
    string name ;
    int age ;
};

class student: public person{
    public:
    int rollno ;
};

class grad_student: public student{
    public:
    string research_area ;
    grad_student(string name , int age , int rollno , string research_area){
        this->name = name ;
        this->age = age ;
        this->rollno = rollno ;
        this-> research_area = research_area ;
    }
    void get_info(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<rollno<<endl;
        cout<<research_area<<endl;
        cout<<"this->name: "<<this->name<<endl ;
    }
};
*/

/*
//multiple inheritance
class student{
    public:
    string name ;
    int age ;
    int rollno ;
};

class teacher{
    public:
    string subject ;
    int salary ;
};

class TA : public student , public teacher{
    public:
     TA(string name , int age , int rollno , string subject , int salary){
        this->name = name ;
        this->age = age ;
        this->rollno = rollno;
        this->subject = subject ;
        this->salary = salary ;
     }
     void getInfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<rollno<<endl;
        cout<<subject<<endl;
        cout<<salary<<endl;
     }
};
*/
/*
//hirarchy inheritance

class person{
    public :
    string name ;
    int age ;
};

class student : public person{
    public :
    int rollno ;
};

class teacher : public person{
    public:
    string subject ;
};


*/



//polymorphism
/*
compile time : we know at the time of complilation that what will be the output eg: constructor overloading , 
function overloading(like constructor overloading same name function names but different parameters) , 
operator overloading(you can learn from internet);

run time : dynamic polymorphism , eg : function overriding -> inheritance a parent function is overridden by child function
                                        i.e. if both functions are same(completely same) then child's function will be called 
                                        if the object of parent class is created then the function of parent class is called
                                        if the object of child class is created then the function of child class is called
                                        , virtual function 


*/


// class student{
//     public:
//     string name ;
//     int age ;
//     student(string name , int age){
//         this->name = name ;
//         this->age = age ;
//     }

//     void change(string name){
//         this->name = name ;
//     }
//     void change(int age){
//         this->age = age ;
//     }
//     //example of function overloading same name but different parameters
//     void getinfo(){
//         cout<<name<<endl;
//         cout<<age<<endl;
//     }
// };



// class animal{
// public:
//     virtual void s(){
//         cout<<"animal speaks";

//     }
// };

// class dogs : public animal{
//     public :
//     void s(){
//         cout<<"dog barks";
//     }
// };

// class puppy : public dogs{
// public :
//     void s(){
//         cout<<"puppy wines";
//     }
// };


// /*
// abstract : written before class 
//         (make a objectless class) only a blueprint to be used by other classes for inheritance 


// */

// class shape{
//     virtual void draw() = 0 ;//pure virtual fucntion and makes the class abstract by itself
// };

// class circle{
// public:
//     void draw(){
//         cout<<"circle is drawn\n";
//     }
// };



// static keyword : it is created only once and can be intialized only one in a life time
//                    for a class a static varible is shared by all the objects of that class


void fun(){
    static int a  = 0 ;
    cout<<"a : "<<a<<endl ;
    a++;
}


class A{
    public :
    static int a;
    void ai(){
        a++;
        cout<<"a is "<<a<<endl ;
    }
};
int main(){
    A a1;
    A a2;
    A a3;
    a1.a = 0 ;
    
    a1.ai();
        a1.ai();
        a1.ai();
    a2.ai();
        a2.ai();
        a2.ai();
    a3.ai();
        a3.ai();
        a3.ai();

    return 0 ;
}








// class gavy{
//     public:

//     string name ;
//     int age ;
//     int salary ;
//     int selfworth ;

//     gavy(string name , int age , int salary , int selfworth){
//         cout<<"Hi i am constructor \n";
//         this->name = name ;
//         this->age = age ;
//         this->salary=salary ;
//         this->selfworth = selfworth ;
//     }
//     gavy(gavy &a){
//         // this->name = a.name ;
//         // this->age = a.age ;
//     }
//     void get_info(){
//         cout<<name<<" "<<age<<" "<<salary<<" "<<selfworth<<endl;
//     }

// };

// int main(){
//     gavy a("gurkirat",18,250000,10000000);
//     a.get_info();
//     gavy b(a);
//     b.salary = 1500000;
//     b.selfworth = 999999;
//     b.get_info();
//     return 0 ;
// }