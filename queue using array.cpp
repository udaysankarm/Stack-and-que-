#include<iostream>
using namespace std;

class QueueARR
{
	public:
	int end,start;// end to indicate the position of end variable
	int *a;// pointer to point to the array a 
	QueueARR() //constructor
	{
		a=NULL;
		end=-1;
		start=0;
	}	
	void Enqueue(int val) //Enqueue function
	{
		end++;//increamenting end
		int *b=new int[end+1]; // creating a new array with size one more. b is a endorary array
		int i;
		*(b+end)=val; // storing the value in the last location of new array
		for(i=0;i<end;i++)
		*(b+i)=*(a+i); //copying the old elements to the new array
		delete [] a;//deleting the previous array
		a=new int[end+1];// creating a new arry with increamented size
		for(i=0;i<=end;i++)
		*(a+i)=*(b+i);// copying all the elements from b to a
		delete  [] b;// deleting the endorary array b
		
	}
	void Dequeue()
	{
		if(IsEmpty())// if there are no elements present in the queue
		cout<<"This deletion is not permitted sice there are no elements present in the queue\n";
		else
		{
			if(start==end)// if it has only one element
			{
			start=0;//making start 0
			end=-1;//end one
			delete [] a;//deleting a
			}
			else
			start++;// if it contains  is non empty then increament
		}
	}
	void Display()// function to display the size of array
	{
		int i;
		if(IsEmpty())//condition to check whether the queue is empty or not
			cout<<"The queue is empty\n"; // 
		else
		{
			for(i=end;i>=start;i--)// printing the array that is the queue
			cout<<*(a+i)<<"->";
			cout<<"NULL"<<endl;
		}
	}
	int size()//function to retun size of array
	{
		return end-start+1;//printing the size of the array
	}
	bool IsEmpty()// function to check whether the function is empty or not
	{
		if(end==-1)
		return true;
		return false; 
	}
	int topD()//function to return the end of the queue
	{
		return *(a+end);	// displaying the end element
	}
};
int main()
{
	QueueARR A;
	for(int j=0;j<6;j++)
	{
		A.Display();
		A.Enqueue(j);
	}
	A.Display();
	A.Display();
	A.Enqueue(89);
	A.Display();
	A.Enqueue(67);
	A.Display();
	A.Dequeue();
	A.Display();
	A.Dequeue();
	A.Display();
	A.Dequeue();
	A.Display();
	A.Dequeue();
	A.Display();
	A.Dequeue();
	A.Display();
	A.Dequeue();
	A.Display();
	A.Dequeue();
	A.Display();
	A.Dequeue();
	A.Display();
	A.Dequeue();
	A.Display();
	cout<<A.size()<<endl;
	cout<<A.topD();
	return 0;
}
