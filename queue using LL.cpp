
#include<iostream>
#include"LL.cpp"
using namespace std;

class queueLL//implementing queue
{
	public:
	Node *end;//variable to point to the top
	Node *start;
	LinkedList ll;
	queueLL()//default constructor
	{
		end=ll.head;;//assinging head to top
		start=ll.last;
	}
	void	Enqueue(int value)// add element in the end
	{
		ll.insertAt(1,value);//inserting at first position 
		end=ll.head;//modifying the top
		start=ll.last;
	}
	void Dequeue()//to delete the end element
	{
		ll.Delete();
		start=ll.last;
		end=ll.head;
	}
	bool isEmpty()//ckecking wheter it is emptyf 
	{
		if (end==NULL)
		return true;
		return false;
	}
	int size()
	{
		return ll.countItems();
	}
	void endD()//function to display the end element of the data structure
	{
		if(end==NULL)
		{
			cout<<"!!!!!!! The data structure is empty !!!!!!!\n ";
		}
		else
		cout<<"The end element is :"<<end->data<<endl;
	}
	void display()
	{
		ll.display();
	}
	void startD()
	{
		if(start==NULL)
		{
			cout<<"!!!!!!! The data structure is empty !!!!!!!\n ";
		}
		else
		cout<<"The start element is :"<<start->data<<endl;
	}
	
};
/*int main()
{
	queueLL A;
	for(int i=0;i<5;i++)
	A.Enqueue(i);
	A.endD();
	A.display();
	A.Dequeue();
	A.display();
	A.Dequeue();
	A.display();
	cout<<A.size()<<endl;
	A.Enqueue(67);
	A.display();
	A.endD();
	A.startD();
	A.Enqueue(87);
	A.display();
	A.Dequeue();
	A.display();
	A.endD();
	A.startD();
	A.Dequeue();
	A.display();
	A.endD();
	A.startD();
	A.Dequeue();
	A.Dequeue();
	A.Dequeue();
	A.display();
	A.endD();
	A.startD();
	A.display();
	return 0;
}*/
