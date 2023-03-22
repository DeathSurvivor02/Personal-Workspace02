package methods;
class Deque
{
	private:
		Node *head;
		Node *tail;
	public:
		Deque();
		void enqueueHead(string);
		void enqueueTail(string);
		string dequeueHead();
		string dequeueTail();
		string showHead();
		string showTail();
		string showAll();

};


Deque::Deque() //constructor
{
	head = tail = NULL;
}

void Deque::enqueueHead(string value) //enqueue
{
	Node *temp = new Node(value);
	if (head == NULL && tail == NULL) //check if empty
	{
		head  = tail = temp; //set head and tail to point to new node
	}
	else 
	{
		temp -> setNext(head); //set next pointer in temp to old head/dequeue
		head = temp; // set head to new node/head
	}
}
void Deque::enqueueTail(string value) //enqueue tail
{
	Node *temp = newNode(value);
	if (head ==NULL && tail ==NULL)
	{
		head = tail = temp; //set head and tail to point to new node
	}
	else
	{
		tail -> setNext(temp); //set next pointer in temp to old head
		tail = temp; //set tail to point to new nodeF
	}
}

string Deque::dequeueHead()
{
	string temp;
	of (head == NULL && tail == NULL)
	{
		return ("Deque is empty");
	}
	else
	{
		if (head == tail) //only 1 node
		{
			temp = head -> tail;
			delete head;
			head = tail = NULL;
			return temp;
		}
		else
		{
			temp = head -> getValue();
			Node *remove = head;
			head  = head-> getNext();
			delete remove;
			return temp;
		}
	}
}