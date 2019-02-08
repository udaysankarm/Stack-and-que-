#include<iostream>
using namespace std;
class Node // each circles
{
	public:
	//data
	int data;
	//pointer to point ot next element
	Node *nxt;
	Node()
	{
		nxt=NULL;
	}
};

class LinkedList
{
	public:
	//head
	Node *head;
	Node *last;
	LinkedList()
	{
		head=NULL;
		last=NULL;
	}
	//insert
	void insert(int value)
	{
		//creating the new object
		Node *temp=new Node;
		//assinging the value to the new memory location
		temp->data=value;  
		//we need to assingn the pointing variable of last to the new object created
		//if it is the first element 
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			last->nxt=temp;
		}
		last=temp;
	}
	//display
	void display()
	{
		Node *current;//current stores the address of the current node
		current = head; //initializing current
		while(current!=NULL)// loop to swipe throughj the link list 
		{
			cout<<current->data<<"-> ";//printing the data in each
			current=current->nxt;//modifing the current node
		}
		cout<<"NULL"<<endl;
	}
	//insertAT
	void insertAt(int pos,int value)
	{
		Node *temp=new Node;// dynamically creating the memory for new node
		temp->data=value;//storing value in the new node
		if(pos >1)//if insertion is not at the first position
		{
			int i=1; //control variable
			Node *current=head;
			while(i<pos-1)//loop acessing each element
			{
				current=current->nxt;//acessing the next element
				if(current==NULL)
				{
					cout<<"\nThat many elements are not present in the linked list\n";
					break;
				}
				i++;//increamenting i		
			}
			if(current!=NULL)
			{
				temp->nxt=current->nxt;//storing the adress of (pos+1)th element in the new node
				current->nxt=temp;//storing the address of new node in (pos-1)th position
				if(temp->nxt==NULL)
				{
					last=temp;
				}
			}
		}
		if(pos==1)
		{
			temp->nxt=head;
			head=temp;
			if(head->nxt==NULL)
			last=head;
		}
	}
	//delete
	void Delete()
	{
		Node *current=head; //curent acceces each node
		if(head==NULL)
		{
			cout<<"Deletion is not permitted since the data structure has no remaining elements\n";
		}
		else if(head->nxt==NULL)
			{
				delete head;//if deletion of last element is occuring
				head=NULL;
				last=NULL;
			}
		else
		{
			while(current->nxt->nxt!=NULL)//loop to search fro end of linklist
			{
				current=current->nxt;//going to the next element
			}	
				Node*p=last;
				current->nxt=NULL;//making the current element the last 
				last->data=NULL; //erasing the value at the node that is to be deleted
				delete p;//delete last element
				last=current;// modifing last to the now location
		}
	}
	void DeleteAt(int pos)
	{
		if(pos==1)
		{
			Node *p=head;
			if(head==NULL)
			{
				cout<<"\nThis deletion is not permitted since there is no remaining element is the data structure\n";
			}
			else 
			{
				if(head==last)// if head is the last element then last have to be modified deleting head
				{
				last=NULL;
				}
				head=head->nxt;
				delete p;
			}
		}
		else
		{
			Node *current,*temp;
			int i=1;
			current=head;
			while(i<pos-1)
			{
				current=current->nxt;
				i++;
			}
			temp=current;
			delete current->nxt;
			current->nxt=temp->nxt->nxt;
		}
	}
	int countItems()
	{
		int i=0;
		Node*current=head;
		while(current!=NULL)
		{
			current=current->nxt;
			i++;
		}
		return i;
	}
};
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
class Stack // our stack class
{
	public:
	Node* top;// top
	queueLL X,Y; // our que used to implement the stack
	Stack() //default constructor
	{
		top=NULL;
	}
	void Insert(int VAL)//insert function
	{
		X.Enqueue(VAL);// insering
		top=X.end;//asinging top
	}
	void Delete()//delet function
	{
		if(X.size()>0)
		{
			while(X.size()>1)
			{
				Y.Enqueue(X.start->data);
				X.Dequeue();
			}
			X.Dequeue();
			while(Y.size()>0)
			{
				X.Enqueue(Y.start->data);
				Y.Dequeue();
			}
			top=X.end;
		}
		else
		cout<<"Deletion not permitted since the stack has no elements has ";
	}
	void Display()
	{
		X.display();
	}

};
int  main()
{
	Stack P;
	for(int i=0;i<8;i++)
	{
		P.Display();
		P.Insert(i);
		cout<<endl<<P.top->data;
	}
	P.Display();
	P.Delete();
	P.Display();
	P.Delete();
	P.Display();
	P.Delete();
	P.Display();
	P.Delete();
	P.Display();
	P.Delete();
	P.Display();
	return 0;
}
