#pragma once

class Stack
{
public:
	Stack() = default;
	Stack(int val);
	Stack(const Stack& source);
	~Stack();
	Stack& operator= (const Stack& source);
public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	bool initialized = false;
	int val = 0;
	Stack* pNextElement = nullptr;
private:
	bool isInitialized() const;
};