/*----------------------------------Source.cpp-------------------------------------*/
#include"Header.h"

/*------------------------------Singly Linked List---------------------------------*/

singlyLinkedList* Head_Singly = NULL;
int counterSingly = 0;

singlyLinkedList::singlyLinkedList()
{
	data = 0; next = NULL;
}

singlyLinkedList::singlyLinkedList(int n)
{
	data = n; next = NULL;
}

singlyLinkedList::singlyLinkedList(int n, singlyLinkedList* p)
{
	data = n; next = p;
}

singlyLinkedList::~singlyLinkedList()
{
	singlyLinkedList* currentNode = Head_Singly, * nextNode = Head_Singly;
	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
}

void singlyLinkedList::insertAtFront_Singly(int dataVar)
{
	counterSingly++;
	singlyLinkedList* newNode = new singlyLinkedList();
	newNode->data = dataVar;
	newNode->next = Head_Singly;
	Head_Singly = newNode;
}

void singlyLinkedList::insertAtBack_Singly(int dataVar)
{
	singlyLinkedList* newNode = new singlyLinkedList();
	newNode->data = dataVar; newNode->next = NULL;
	if (counterSingly == 0)
	{
		Head_Singly = newNode;
	}
	else
	{
		singlyLinkedList* temp = Head_Singly;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	counterSingly++;
}

void singlyLinkedList::insertAtPos_Singly(int pos, int dataVar)
{
	counterSingly++;
	singlyLinkedList* newNode = new singlyLinkedList();
	newNode->data = dataVar; newNode->next = NULL;
	singlyLinkedList* tempNext = Head_Singly;
	singlyLinkedList* tempPrev = Head_Singly;
	for (size_t listIndex = 0; listIndex < pos - 1; listIndex++)
	{
		if (listIndex != 0)
		{
			tempPrev = tempPrev->next;
		}
		tempNext = tempNext->next;
	} newNode->next = tempNext; tempPrev->next = newNode;
}

void singlyLinkedList::insertAfterPos_Singly(int pos, int dataVar)
{
	counterSingly++;
	singlyLinkedList* newNode = new singlyLinkedList();
	newNode->data = dataVar; newNode->next = NULL;
	singlyLinkedList* tempNext = Head_Singly;
	singlyLinkedList* tempPrev = Head_Singly;
	for (size_t listIndex = 0; listIndex < pos; listIndex++)
	{
		if (listIndex != 0)
		{
			tempPrev = tempPrev->next;
		}
		tempNext = tempNext->next;
	} newNode->next = tempNext; tempPrev->next = newNode;
}

void singlyLinkedList::deleteNode_Singly(int pos)
{
	counterSingly--;
	singlyLinkedList* tempNext = Head_Singly;
	singlyLinkedList* tempPrev = Head_Singly;
	for (size_t listIndex = 0; listIndex < pos - 1; listIndex++)
	{
		if (listIndex != 0)
		{
			tempPrev = tempPrev->next;
		}
		tempNext = tempNext->next;
	} tempPrev->next = tempNext->next; delete tempNext;
}

singlyLinkedList* singlyLinkedList::reverseRecursive_singly(singlyLinkedList* &head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	singlyLinkedList* newHead = reverseRecursive_singly(head->next);
	head->next->next = head;
	head->next = NULL;
	
	return newHead;

}

void singlyLinkedList::printNodes_Singly()
{
	cout << " Printing Singly Linked List: ";
	singlyLinkedList* temp = Head_Singly;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	} cout << endl;
}

void singlyLinkedList::destroyList_Singly()
{
	counterSingly = 0;
	singlyLinkedList* temp = Head_Singly;
	while (temp != NULL)
	{
		Head_Singly = temp->next;
		delete temp;
		temp = Head_Singly;
	}
}

/*------------------------------Doubly Linked List---------------------------------*/

doublyLinkedList* Head_Doubly = NULL;
int counterDoubly = 0;

void doublyLinkedList::insertAtFront_Doubly(int dataVar)
{
	counterDoubly++;
	doublyLinkedList* newNode = new doublyLinkedList();
	newNode->data = dataVar; newNode->next = NULL; newNode->prev = NULL;
	if (Head_Doubly == NULL)
	{
		Head_Doubly = newNode;
	}
	else
	{
		Head_Doubly->prev = newNode;
		newNode->next = Head_Doubly;
		Head_Doubly = newNode;
		newNode->prev = NULL;
	}
}

void doublyLinkedList::insertAtPos_Doubly(int pos, int dataVar)
{
	if (pos <= counterDoubly)
	{
		counterDoubly++;
		doublyLinkedList* newNode = new doublyLinkedList();
		newNode->data = dataVar; newNode->next = NULL; newNode->prev = NULL;
		doublyLinkedList* temp = Head_Doubly;
		for (size_t listIndex = 0; listIndex < pos - 1; listIndex++)
		{
			temp = temp->next;
		}
		newNode->prev = temp; newNode->next = temp->next;
		temp->next = newNode; temp = newNode->next; temp->prev = newNode;
	}
}

void doublyLinkedList::destroyList_Doubly()
{
	counterDoubly = 0;
	doublyLinkedList* temp = Head_Doubly;
	while (temp != NULL)
	{
		Head_Doubly = temp->next;
		delete temp;
		temp = Head_Doubly;
	}
}

void doublyLinkedList::printNodes_Doubly()
{
	cout << " Printing Doubly Linked List: ";
	doublyLinkedList* temp = Head_Doubly;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		if (temp->next != NULL)
		{
			temp = temp->next;
		}
		else
		{
			break;
		}
	} cout << "\n Backward: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		if (temp->prev != NULL)
		{
			temp = temp->prev;
		}
		else
		{
			break;
		}
	} cout << endl;
}

/*------------------------------ Circular Linked List---------------------------------*/

int counter_Circular = 0;

circularLinkedList::circularLinkedList()
{
	data = 0; next = NULL;
}

circularLinkedList::circularLinkedList(int n)
{
	data = n; next = NULL;
}

circularLinkedList::~circularLinkedList()
{
	/*singlyLinkedList* currentNode = Head_Singly, * nextNode = NULL;
	while (currentNode != NULL)
	{
		nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
	delete Head_Singly;*/
}

bool circularLinkedList::insertAtBegin(int dataVar)
{
	counter_Circular++;
	circularLinkedList* newNode = new circularLinkedList();
	newNode->data = dataVar; newNode->next = Tail_Circular;
	circularLinkedList* temp = Head_Circular;
	if (temp == NULL)
	{
		Head_Circular = newNode;
		newNode->prev = Head_Circular;
		newNode->next = Tail_Circular;
		Tail_Circular = Head_Circular;
	}
	else
	{
		Head_Circular = newNode; newNode->prev = Head_Circular;
		temp->prev = newNode; newNode->next = temp;
		Tail_Circular = Head_Circular;
	}
	return true;
}

bool circularLinkedList::insertAtEnd(int dataVar)
{
	circularLinkedList* newNode = new circularLinkedList();
	newNode->data = dataVar; newNode->next = Tail_Circular;
	circularLinkedList* temp = Head_Circular;
	if (temp == NULL)
	{
		Head_Circular = newNode;
		newNode->prev = Head_Circular;
		newNode->next = Tail_Circular;
		Tail_Circular = Head_Circular;
	}
	else if (counter_Circular == 1)
	{
		newNode->next = Tail_Circular; newNode->prev = temp;
		temp->next = newNode;
		Tail_Circular = Head_Circular;
	}
	else
	{
		for (size_t index = 0; index < counter_Circular - 1; index++)
		{
			temp = temp->next;
		}
		newNode->next = Tail_Circular; newNode->prev = temp;
		temp->next = newNode;
		Tail_Circular = Head_Circular;
	}
	counter_Circular++;
	return true;
}

bool circularLinkedList::isEmpty()
{
	if (Head_Circular == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void circularLinkedList::printNodes_Circular()
{
	circularLinkedList* temp = this->Head_Circular;
	for (size_t index = 0; index < counter_Circular * 2; index++)
	{
		cout << temp->data << " ";
		temp = temp->next;
	} cout << endl;
}


/*----------------------------------Source.cpp-------------------------------------*/
