template<class T>
class SLList
{
public:
	SLList();

	void Create(int size);
	void AddBack(T data);
	void AddFront(T data);
	void AddTo(int index, T data);

	void Clean();
	void RemoveFront();
	void RemoveBack();
	void RemoveAt(int index);
	
	int FindIndexOf(T data);
	int GetSize() { return size; };
	T& operator[](const int index);



	~SLList();
private:
	template <class T>
	class Node
	{
	public:
		Node *pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node<T> *head;

};

template<class T>
SLList<T>::SLList()
{
	size = 0;
	head = nullptr;
}

template<class T>
void SLList<T>::Create(int size)
{
	if(size == 1)
	{
		head = new Node<T>(T());
	}
	else if (size > 1)
	{
		for (int i = 0; i < size; i++)
		{
			this->AddBack(T());
		}
	}
	else if (size <= 0) 
	{
		throw std::exception("uncorrect size!");
	}
}

template<class T>
void SLList<T>::AddBack(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	size++;
}

template<class T>
void SLList<T>::AddFront(T data)
{	
	this->AddBack(T());
	for (int i = size - 1; i > 0; i--)
	{
		this->operator[](i) = this->operator[](i - 1);
	}
	head->data = data;
}

template<class T>
void SLList<T>::AddTo(int index, T data)
{
	if (index < size)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			int counter = 0;
			Node<T> *current = this->head;

			while (current != nullptr)
			{
				if (counter == index)
				{
					this->AddBack(T());

					for (int i = this->size - 1; i > index; i--)
					{
						this->operator[](i) = this->operator[](i-1);
					}

					current->data = data;
					break;
				}
				else
				{
					current = current->pNext;
					counter++;
				}
			}
		}
	}
	else
	{
		throw std::exception("index > size!!!");
	}

}

template<class T>
void SLList<T>::Clean()
{
	while (size)
	{
		RemoveFront();
	}
}

template<class T>
void SLList<T>::RemoveFront()
{
	Node<T> *temp = this->head;
	head = head->pNext;
	delete temp;
	size--;
}

template<class T>
void SLList<T>::RemoveBack()
{
	Node<T> *current = this->head;
	Node<T> *previos = nullptr;
	while (current->pNext != nullptr)
	{
		previos = current;
		current = current->pNext;
	}

	previos->pNext = nullptr;

	delete current;
	size--;
}

template<class T>
void SLList<T>::RemoveAt(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::exception("uncorrect index");
	}
	else if (index == 0)
	{
		this->RemoveFront();
	}
	else
	{
		int counter = 0;
		Node<T> *current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				for (int i = index; i < this->size - 1; i++)
				{
					this->operator[](i) = this->operator[](i + 1);
				}
				
				this->RemoveBack();
				break;
			}
			else
			{
				current = current->pNext;
				counter++;
			}
		}
	}
	
}

template<class T>
int SLList<T>::FindIndexOf(T data)
{
	int index = 0;
	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (current->data == data)
		{
			return index;
		}
		else
		{
			current = current->pNext;
			index++;
		}
	}
	
}

template<class T>
T& SLList<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}

}

template<class T>
SLList<T>::~SLList()
{

}

