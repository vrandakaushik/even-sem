#include <iostream>
using namespace std;

// Generic Programming - Ignore 

class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(){
        next = NULL;
    }

};

class LinkedList{
    // Head + Circles inside linked with each other
    public:
    // Head -> Node type ptr
    Node * head;
    Node * tail;

    // Construct
    LinkedList(){
        head = NULL;
        tail = NULL;
    } 
    // Circles inside linked with each other
    // Rules how circles will be linked


// for counting the elements
    void count(){
	Node *current = head;
	int i=1;
	while(current->next!=NULL){
	current= current->next;
	i++;
	}
    cout<<"number of nodes : "<< i<<endl;

    }





    // Insert
    void insert(int value){
       // If 1st Node is added
       Node * temp = new Node; 
       // Insert value in the node
       temp->data = value;
       // 1st Node only.
       if(head == NULL){
            head = temp;
       }
       // Any other Node only.
       else{
            tail->next = temp;
       }
       tail = temp;
    } 

    void insertAt(int pos, int value){
        // Reach the place before the pos
	if(pos!=1){
		Node * current = head;
		int i =1;
		while(i < pos-1){
		    i++;
		    current = current->next;
		}

		// Create a node
		Node * temp = new Node;
		temp -> data = value;


		// Moving ptrs like magic ! if not head
		temp->next = current->next;
		current->next = temp;
	}        
	 
       // Update the code for 1st position
	else{
	Node *temp=new Node;
	
	temp->next=head;
	head=temp;
	head-> data = value;
	}
   	 }

    // Deletion of last element
    void delet(){
        // store the tail in temp
        Node * temp = tail;
        // before tail has to point to null
        Node * current = head;
        while(current->next != tail){
            current = current->next;
        }
        current->next = NULL; 

        // update tail
        tail = current;
        // delete temp
         delete temp;
    }


    //to delete at a given place 

    void deletAt(int a){
  if(a!=1){
        // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < a-1){
            i++;
            current = current->next;
        }

        // store the deleted node in temp
        Node * temp = current->next;

        // Moving ptrs like magic ! if not head
        current->next=temp->next;

	//delete temp
	delete temp;
        
        // Update the code for 1st position
  }
  
  else{
	//store head in temp
  	Node *temp = head;

  	//make new head
  	head=head->next;

  	//delete previous head
  	delete temp;
  }


    }


    // Display
    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout << endl;
    }
};


int main(){
    LinkedList l1;
	//for assigning the values
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.display();
    l1.delet();			//for deleting the last node
	cout<<"after deleting ,now it looks like : ";
    l1.display();
    l1.insertAt(2,6);		//for inserting at 2nd position the value 6
	cout<<"after inserting ,now it looks like : ";
    l1.display();
    l1.insertAt(1,7);		//for insertion at head
    l1.display();
    l1.deletAt(2);		//for deleting a particular node
	cout<<"after deleting,now it looks like : ";
    l1.display();
    l1.deletAt(1);		//for deletion at head
	cout<<"after dleting,now it looks like : ";
    l1.display();
    l1.count();
    return 0;
}
