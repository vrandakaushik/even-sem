#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node * next;
	Node(){
	next = NULL;
	}
};

class Circular{
	public:
	Node * head;
	Circular(){
		head = NULL;
	}


// for insert
void insert(int value){
       // If 1st Node is added
       Node * temp = new Node; 
       // Insert value in the node
       temp->data = value;
       // 1st Node only.
       if(head == NULL){
            head = temp;
       }
      else{ 
        Node * current = head;
        while(current->next != head)
           current = current->next;
           current->next = temp;
        }
        temp->next = head;
} 





//insertAt	
void insertAt(int pos, int value){
        // at place before reqd position
	if(pos!=1){
        Node * current = head;
        int i =1;
        while(i < pos-1){
            i++;
            current = current->next;
        }

        // Create a Node
        Node * temp = new Node;
        temp -> data = value;


        // Moving ptrs like magic ! if not head
        temp->next = current->next;
        current->next = temp;
	}        

	else{

	Node *temp=new Node;
	temp->next=head;


	head=temp;


	head-> data = value;
	}
}




//fordelete

void delet(){
	    Node *temp;
            Node * current = head;
            while(current->next->next != head)
                current = current->next;
            temp = current->next;

            // update 
	    current->next=head;        
            // delete temp
            delete temp;
    }




//for deleteAt
void deletAt(int a){
  	if(a!=1){
        // Reach the place before the pos
        Node * current = head;
        int i =1;
        while(i < a-1){
            i++;
            current = current->next;
        }

        // store the deleted Node in temp
        Node * temp = current->next;

        // Moving ptrs like magic ! if not head
        current->next=temp->next;

	//delete temp
	delete temp;
        }
  
 	 else{
 	 Node *temp = head;
  	 head=head->next;
  	 delete temp;
 	 }


}




//for display
void display(){
	Node * current =head;
	 if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head){

	 // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
	
	
        // Printing the last element
        cout << current -> data ;
        cout << endl;
    }

	


// for count items
 void countItems(){
 
	Node *current = head;
	int i=1;
		
	while(current->next!=head){
	i++;
	current= current->next;
	}
    	cout << "the number of elements in circular linked list are - "<<i<<endl;
  	  }

};


int main(){
	Circular circular;
	for(int i= 1; i < 7; i++){
	circular.insert(i);	
	}
	circular.display();
	circular.countItems();
	circular.insertAt(2,12);
	circular.display();
	circular.delet();
	circular.display();
	circular.deletAt(2);
	circular.display();

}


	
