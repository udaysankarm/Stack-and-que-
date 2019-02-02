#include<iostream>
using namespace std;

class stackARR
{
	public:
	int top;// top to indicate the position of top variable
	int *a;// pointer to point to the array a 
	stackARR() //constructor
	{
		a=NULL;
		top=-1;
	}	
	void push(int val) //push function
	{
		top++;//increamenting top
		int *b=new int[top+1]; // creating a new array with size one more. b is a temporary array
		int i;
		*(b+top)=val; // storing the value in the last location of new array
		for(i=0;i<top;i++)
		*(b+i)=*(a+i); //copying the old elements to the new array
		delete [] a;//deleting the previous array
		a=new int[top+1];// creating a new arry with increamented size
		for(i=0;i<=top;i++)
		*(a+i)=*(b+i);// copying all the elements from b to a
		delete  [] b;// deleting the temporary array b
		
	}
	void pop()
	{
		if(IsEmpty())// if there are no elements present in the stack
		cout<<"This deletion is not permitted sice the stack is empty\n";
		else
		{
			top--;//decreamenting top
			if(IsEmpty())//checking whether the stack is empty or not
			a=NULL;
		}
	}
	void Display()// function to display the size of array
	{
		int i;
		if(IsEmpty())//condition to check whether the stack is empty or not
			cout<<"The stack is empty\n"; // 
		else
		{
			for(i=top;i>=0;i--)// printing the array
			cout<<*(a+i)<<"->";
			cout<<"NULL"<<endl;//printing the end NULL
		}
	}
	int size()//function to retun size of array
	{
		cout<<top+1<<endl;//printing the size of the array
	}
	bool IsEmpty()// function to check whether the function is empty or not
	{
		if(top==-1)
		return true;
		return false; 
	}
	int topD()//function to display the value at top of the stack
	{
		return *(a+top);	// displaying the top element
	}
};
int main()
{
	stackARR A;
	for(int j=0;j<7;j++)
	A.push(j);
	A.push(58);
	A.push(63);
	A.pop();
	A.Display();
	cout<<"$$$"<<*(A.a+A.top)<<endl;
	A.Display();
	A.pop();
	A.Display();
	A.pop();
	A.Display();
	A.pop();
	A.Display();
	A.pop();
	A.Display();
	A.pop();
	A.Display();
	A.pop();
	A.Display();
	A.pop();
	A.Display();
	A.pop();
	A.Display();
	A.pop();
	A.Display();
	cout<<endl<<A.IsEmpty()<<endl;
	for(int j=0;j<7;j++)
	A.push(j);
	cout<<A.topD()<<endl;
	A.Display();
	return 0;
}
