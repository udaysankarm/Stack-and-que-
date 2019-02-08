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
	int topD()
	{
		if(top==NULL)// if the stck has no elements
		{
			cout<<"There are no elements in the stack\n";//print that the stck is empty 
		} 
		else
		return top->data;//if it is not empty then return top data
	}
	void display()
	{
		ll.display();
	}
};
class queue //
{
	public:
	stackLL A,B;
	Node *front,*end;
	
 	void Enqueue(int Val)
	{
		if(A.isEmpty())
		{
			A.push(Val);
			front=A.top;
		}
		else
		{
			A.push(Val);
			end=A.top;
		}
	}
	void Dequeue()
	{
		if(A.isEmpty())
		{
			cout<<"\n The deletion is not permitted since there are no remaing elements in the queue";
		}
		else
		{
				while(!A.isEmpty())
				{
					B.push(A.topD());
					A.pop();
				}
				B.pop();
				while(!B.isEmpty())
				{
					A.push(B.topD());
					B.pop();
				}
		}
	}
	void display()
	{
		A.display();
	}
	bool isempty()
	{
		A.isEmpty();
	}
	int SIZE()
	{
		A.size();
	}
	int Top()
	{
		return end->data;
	}
};
int main()
{
	queue D;
	for(int i=0;i<7;i++)
	{
		D.display();
		D.Enqueue(i);
	}
	D.display();
	cout<<D.SIZE()<<endl;
	cout<<D.front->data<<endl;
	cout<<D.end->data<<endl;
	D.Dequeue();
	D.display();
	cout<<D.SIZE()<<endl;
	D.Dequeue();
	D.display();
	cout<<D.SIZE()<<endl;
	D.Dequeue();
	D.display();
	cout<<D.SIZE()<<endl;
	D.Dequeue();
	D.display();
	cout<<D.SIZE()<<endl;
	D.Dequeue();
	D.display();
	cout<<D.SIZE()<<endl;
	D.Dequeue();
	D.display();
	cout<<D.SIZE()<<endl;
	D.Dequeue();
	D.display();
	D.Enqueue(78);
	D.display();
	cout<<endl<<D.isempty();
	cout<<D.SIZE()<<endl;
	return 0;
}
