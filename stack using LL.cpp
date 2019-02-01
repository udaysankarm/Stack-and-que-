
#include<iostream>
#include "LL.cpp"//to include the linked list program
using namespace std;/*how to create a c++ header file*/

class stackLL//implementing stck								//STACK USING LINKED LIST
{
	public:
	Node *top;//variable to point to the top
	LinkedList ll;
	stackLL()//default constructor
	{
		top=ll.head;//assinging head to top
	}
	void push(int value)//push to add element in the top
	{
		ll.insertAt(1,value);//inserting at first position 
		top=ll.head;//modifying the top
	}
	void pop()//to delete the end element
	{
		ll.DeleteAt(1);//deleting the first element
		top=ll.head;//modifiying the top
	}
	bool isEmpty()//ckecking wheter it is emptyf 
	{
		if (top==NULL) // if it is empty
		return true;// it will return true
		return false;
	}
	int size()
	{
		return ll.countItems();//count function to count the number od elements
	}
	void topD()
	{
		if(top==NULL)// if the stck has no elements
		{
			cout<<"There are no elements in the stack\n";//print that the stck is empty 
		} 
		else
		cout<<top->data<<endl;//if it is not empty then return top data
	}
	void display()
	{
		ll.display();
	}
};
int main()
{
	stackLL s1;
	int i;
	for(i=0;i<5;i++)
	{
		s1.push(i);
	}
	cout<<s1.size()<<endl;
	s1.display();
	s1.pop();
	s1.display();
	cout<<s1.isEmpty();
	s1.pop();
	cout<<"^^^^^^^^^^^";
	s1.display();
	s1.topD();
	s1.display();
	s1.pop();
	s1.display();
	cout<<s1.size()<<endl;
	//s1.pop();
	s1.display();
	s1.push(6);
	s1.display();
	//s1.pop();
	s1.display();
	s1.pop();
	cout<<"^^^^^^^^^^^";
	s1.display();
	s1.topD();
	cout<<endl<<s1.isEmpty()<<endl;
	s1.push(67);
	s1.display();
	return 0;
}
