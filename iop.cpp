#include <iostream>
#include <conio.h>
using namespace std;
#define max 5

class Cqueue
{
private:
	int arr[max];

public:
	int front;
	int rear;
	void makeCqueue()
	{
		front = rear = -1;
	}
	int checkEmpty()
	{
		if (rear == front)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int checkFull()
	{
		if (front == (rear + 1) % max)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void Enqueue()
	{
		if (checkFull() == 1)
		{
			cout << "Queue is Full" << endl;
		}
		else
		{
			int n;
			cout << "Enter a Element: ";
			cin >> n;
			rear = (rear + 1) % max;
			arr[rear] = n;
		}
	}
	void Dequeue()
	{
		if (checkEmpty() == 1)
		{
			cout << "Queue is Empty" << endl;
		}
		else
		{
			int n;
			front = (front + 1) % max;
			n = arr[front];
			cout << n << " is deleted succesfully!" << endl;
		}
	}
	void Traverse()
	{
		if (checkEmpty() == 1)
		{
			cout << "Nothing to Display" << endl;
		}
		else
		{
			cout << "Queue: ";
			for (int i = (front + 1) % max; i != rear; i = (i + 1) % max)
			{
				cout << arr[i] << ", ";
			}
			cout << arr[rear] << endl
				 << front << rear;
		}
	}
};

int main()
{
	Cqueue object;
	int choice;
	int ch;

	cout << "1. Make Empty" << endl;
	cout << "2. Check Empty" << endl;
	cout << "3. Check Full" << endl;
	cout << "4. Enqueue" << endl;
	cout << "5. Dequeue" << endl;
	cout << "6. Traverse" << endl;
	cout << "7. Exit" << endl;
Again:
	cout << "Choose the operations:" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		object.makeCqueue();
		cout << "The Queue is Empty now" << endl;
		goto Again;

	case 2:
		if (object.checkEmpty() == 1)
		{
			cout << "Queue is Empty" << endl;
			goto Again;
		}
		else
		{
			cout << " Queue is not Empty" << endl;
			goto Again;
		}

	case 3:
		if (object.checkFull() == 1)
		{
			cout << "Queue is Full" << endl;
			goto Again;
		}
		else
		{
			cout << "Queue is not full" << endl;
			goto Again;
		}

	case 4:
		object.Enqueue();
		goto Again;

	case 5:
		object.Dequeue();
		goto Again;

	case 6:
		object.Traverse();
		goto Again;

	case 7:
		break;

	default:
		cout << "Invalid Choice!" << endl;
		goto Again;
	}
	return 0;
}