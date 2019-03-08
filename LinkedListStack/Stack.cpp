#include "Stack.h"

Stack::Stack(int val)
{
	this->Push(val);
}

Stack::Stack(const Stack & source)
{
	*this = source;
}

Stack::~Stack()
{
	delete pNextElement;
}

Stack & Stack::operator=(const Stack & source)
{
	delete pNextElement;
	pNextElement = nullptr;

	if (source.pNextElement != nullptr)
	{
		*pNextElement = *(source.pNextElement);
	}
	val = source.val;
	initialized = source.initialized;
	return *this;
}

void Stack::Push(int val)
{
	if (!initialized)
	{
		this->val = val;
		initialized = true;
	}
	else if (pNextElement == nullptr)
		pNextElement = new Stack(val);
	else
		pNextElement->Push(val);
}

int Stack::Pop()
{
	int returnValue;
	if (pNextElement != nullptr)
	{
		returnValue = pNextElement->Pop();
		if (!pNextElement->isInitialized())
		{
			delete pNextElement;
			pNextElement = nullptr;
		}
	}
	else
	{
		returnValue = this->val;
		initialized = false;
	}
	return returnValue;
}

int Stack::Size() const
{
	if (initialized)
	{
		int s = 0;
		(pNextElement == nullptr) ? s = 1 : s = 1 + pNextElement->Size();
		return s;
	}
	else return 0;
}

bool Stack::Empty() const
{
	return !initialized;
}

bool Stack::isInitialized() const
{
	return initialized;
}
