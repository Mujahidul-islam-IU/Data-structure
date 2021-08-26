#include <iostream>
#define CAPACITY 5
using namespace std;
 class stack{
	 int top;
	 public:
	 int Astack[CAPACITY];
	 stack(){
		 top=-1;
	 }
	 void push(int x);
	 int pop();
	 int peek();
	 void print();

 };
void stack:: push(int x)
{
	if(top>= CAPACITY-1){
		cout<< "Stack overflow!"<<endl;
	}
	else{
		top= top+1;
		Astack[top]=x;
		cout<<"the item is:  "<< x<<endl;
			}
}
int stack:: pop(){
	if(top >= 0){
            int value = Astack[top];
            top--;
      return value;


	}
	cout<<"stack is empty"<<endl;
	return -1;
}
int stack:: peek(){
	if(top>=0){
		return Astack[top];
	}
	cout<<"stack is empty"<<endl;
	return -1;
}
void stack:: print(){
	int i;
	cout<<"the stack is:  ";
	for (i=0 ;i<CAPACITY; i++){
		cout <<  Astack[i]<< " " ;

	}
	cout << endl;
}
int main(){

   stack s;
   s.pop();
   s.push(10);
   s.push(20);
    s.push(30);
   s.push(40);
   s.push(50);
   s.push(100);
   s.print();
  cout<<"removed item is: "<< s.pop()<<endl;
   cout<<"removed item is: "<< s.pop()<<endl;
   cout<<"the top item is: "<< s.peek()<<endl;
   s.print();
   s.push(67);
    s.push(77);
   s.print();
     cout<<"the top item is: "<< s.peek()<<endl;


}
