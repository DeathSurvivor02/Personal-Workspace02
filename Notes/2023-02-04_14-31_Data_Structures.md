# Dynamic memory allocation

	* [1]: Obtain and release memory during program execution
	* [2]: Create and remove nodes


# Operator [new]
	*[1]: Takes type of object to create
	*[2]: Returns pointer to newly created object
	*[3]: Returns bad_alloc if not enough memory 


[e.g.]
	Node *newPtr = new Node(10); [figure 1]
[note] 10 is the node's object data 

[figure_2]
	Node::Node(int val)
	{
		data = val;
		NextPtr = NULL;
	}

[figure_3]
	Node *newPtr;
	newPtr = new Node(10);

#Operator [delete]

	*[1]: Deallocates memory allocated by [new], calls destructor
	*[2]: Memory returned to system, can be used in future
	*[3]: Pointer is not deleted, only the space it points to 

[e.g.]
[figure_4]	delete newPtr;

[Note]	Note: newPtr continues to be a valid variable - only the data space is released

## 																	[center]Linked Lists

	* Collection of self-referential class objects (nodes) connected by pointers (links)
	
	* Accessed using pointer to find first node of the list
		* Subsequent nodes accessed using the links in each node
  	
	* Link in last node is NULL (zero)
		* Indicates end of list 
  	
  	* Data stored dynamically
		* Nodes created as necessary
		* Node can have data of any type 


# Types of linked lists

[red]	Singly linked list (used in example)
	* Pointer to first node
	* Node-to-node travel is in one direction
	* Null-terminated

[red] Circular, singly-linked
	* As above, but last node points back to the first
	* No Null_termination

[red] Doubly-linked list
	* Each node has a forward and backwards pointer
	* Traverses forward or backwards
	* Previous pointer of first node points to NUL
	* Next pointer of last node pointers to NULL

![alt text] (Notes\Node Pointers)

[red] Circular, double-linked
	As above, but first and last node joined
<font style = 'blue'> 
## 														[center] Queues 
# Characteristics:
1. Like waiting in line
2. Nodes are added to the back ([bold]tail)
3. Nodes are removed from the front ([bold]head)
4. First in, first out (FIFO) data structure
5. Insertion is called [red][bold] Enqueue
6. Removal is called [red][bold] Dequeue
</font>


# Applications
	* Print spooling
		* Documents wait in queue until printer is available
	* Packets on network
	* File requests from server

# Typical Operations:

[blue] dequeue  - Remove and return the Object from the front of queue or return an error if the queue is empty

[blue] enqueue - Inserts an object at the rear of the queue

[blue] isEmpty -  Returns a boolean indicating whether the queue is empty

[blue] front - Return the Object at the front of the queue without removing the object. If the queue is empty, return an error.

[blue] size -  Return the number of Objects in the queue.


##								[center] Double-Ended Queues

# Characteristics

   * Nodes are added to both the back ([bold] tail) and to the front ([bold] head) 
   * Nodes are removed from both the tail and the head
   * not First-in, first-out (FIFO) data structures
   * Insertion is also called [bold] Enqueue
   * Removal is also called [bold] Dequeue


[NB] Do not confuse Deque with Dequeue

# Operations

[bold] [blue] 	insertFirst	-	Inserts an object at the end of the deque
				insertLast	-	Inserts an object at the rear of the deque
				removeFirst	-	Removes and returns the  object at the front of the deque
				removeLast	-	Removes and returns the object at the from the rear of the deque
				First/Last 	-	Returns the first/last Object in the deque without removing the Object
				isEmpty -	Returns a boolean indicating whether the deque is empty or not
				size	-	Returns the number of objects in the deque

# Characteristics
   * Like an ordinary queue
   * Has a head and a tail
   * Elements are [red] ONLY [bold] removed from front (dequeue)
   * Elements are ordered so that the item with the highest priority is always the first
   * When an item is inserted (enqueue) the order must be maintained
   * Said to be an ascending-priority queue if the item with the smallest key has the highest priority
   * Said to be a descending-priority queue if the item with the lowest key has the highest priority

## 					[bold] Stacks
   *  	Nodes are added and/or removed from the top
         * Constrained version of linked list
         * like a stack of plates
    * Last in, First out (LIFO) data structure
    * Last element (bottom) of the stack points to NULL

# Stack Operations

	Push: add node to top
	Pop: Remove node from top

# Summary

### Queue
  	* Lists which employ a first-in, first-out concept
  	* Nodes are removed only from the head and nodes are inserted only at the tail

### Priority Queue
  	* A lists which imposes a sorted priority on the elements so that the elements with the highest priority is always at the head of the list.
  	* This sorting is done whenever the new element is added to the list
  	* nodes are removed only from the head - i.e. the node with the highest priority 

### Stack
  	* A lists which employs a last in first out concept. Nodes are added and removed only from the top of the structure

### Deque (Double-Ended Queue)

  	* A double ended queue is a list which permits insertion and deletion at both the head and tail of the list.
  	* Insertion and deletion are only permitted at the two ends.


## 												[bold] List ADT
[Example]

	class Node
	{
		private:
			string Value; //This is the data part - it contains the payload
			Node* Next; //This contains the address of the next node

		public:
			Node(void) { Value = ""; Next = NULL;}
			Node(string Vx) { Value = Vx; Next = NULL;}

			//Define the accessor member functions...

			string getValue(void){ return Value;}
			Node* getNext(void) {return Next;}

			//Define the mutators...
			void setValue(string Vx) { Value = Vx;}
			void setNext(Node* Nx) { Value = Nx;}


	};

	class LinkedList
	{
		private:
			Node* Head;
			public
				//constructor function
				LinkedList(void) {Head = NULL;}

				//mutator or setfunction
				void addNode(string);
				void addBegin(string);
				void addEnd(string);
				void delNode(string);

				//accessor get functions
				string getBegin(void);
				string getEnd(void);
				bool find(string);
				void showNodes(void);
				int isEmpty(void);
	};

	void LinkedList::addBegin(string Vx)
	{
		Node* Cur = Head;
		Head = new Node(Vx);
		Head -> setNext(Cur);
	}

	void LinkedList::addEnd(string Vx)
	{
		Node* Cur;
		if (Head == NULL)
		{
			Head = new Node(Vx);
		}
		else
		{
			for (Cur = Head; Cur -> getNext(); Cur = Cur->getNext()); //since the for statement end with a ; only the incrementing part is executed
			Cur -> setNext(new Node(Vx));
		}
	}
	
	void LinkedList::delNode(string Vx)
	{
		Node* Cur;
		Node* Prev;

		cout << "\nDeleting..." << Vx << "...\n";


		//This is a special case-- an empty linked list
		if (Head == NULL)
		{
			return; //It's Ok to return from a void
		}

		//Removing the first node is a spacial case...
		if (Head -> getValue() == Vx)
		{
			Cur = Head;
			Head = Head->getNext();
			delete  Cur;
			return;
		}
		//Normal case.. removing the second through to the last node...
		Prev = Head;
		for (Cur = Prev -> getNext(); Cur != NULL && strcmp(Cur->getValue(), Vx); )
		{
			Cur = Cur->getNext(); //walk down through the list
			Prev = Prev->getPrev();
		}
		if (Cur == NULL)
		{
			cout << Vx << "was not found in the list..." << endl;
		}
		else //you found the value
		{
			Prev -> setNext(Cur -> getNext());
			delete Cur;
		}
	}