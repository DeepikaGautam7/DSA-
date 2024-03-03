#include <iostream>
#define max 10
using namespace std;
class List
{
private:
	int arr[max];

public:
	int index = -1;
	void makeEmpty()
	{
		index = -1;
		cout << "The list is empty now!" << endl;
	}

	int checkEmpty()
	{
		if (index == -1)
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
		if (index == max - 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void insert()
	{
		if (checkFull() == 1)
		{
			cout << "The List is Full." << endl;
		}
		else
		{
			index++;
			int n;
			char a;
			cout << "Enter the element to insert: ";
			cin >> n;
			arr[index] = n;
			cout << "Do You want to insert more?(Y/N) ";
			cin >> a;
			if (a == 'Y' || a == 'y')
			{
				insert();
			}
			else
				return;
		}
	}

	void Delete()
	{
		if (checkEmpty() == 1)
		{
			cout << "The List is empty";
		}
		else
		{
			int deleted;
			int position;
			cout << "Enter the Position to delete: ";
			cin >> position;
			deleted = arr[position - 1];
			for (int i = position - 1; i < index; i++)
			{
				arr[i] = arr[i + 1];
			}
			cout << deleted << " from position " << position << " is deleted Successfully!" << endl;
			index--;
		}
	}

	void Traverse()
	{
		if (checkEmpty() == 1)
		{
			cout << "Nothing to Display!!" << endl;
		}
		else
		{
			cout << "List: ";
			for (int i = 0; i <= index; i++)
			{
				cout << arr[i] << ", ";
			}
			cout << endl;
		}
	}
};
int main()
{
	List object;
	int choice;
	char a;
Again:
	cout << "Choose from the option:" << endl;
	cout << "1. Make Empty List" << endl;
	cout << "2. Check Empty" << endl;
	cout << "3. Check Full" << endl;
	cout << "4. Insert on List" << endl;
	cout << "5. Delete from List" << endl;
	cout << "6. Traverse the List" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		object.makeEmpty();
		cout << "Do You want to perform other activities?(Y/N) ";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto Again;
		}
		else
			break;

	case 2:
		if (object.checkEmpty() == 1)
		{
			cout << "The List is empty" << endl;
		}
		else
			cout << "The list is not empty" << endl;
		cout << "Do You want to perform other activities?(Y/N) ";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto Again;
		}
		else
			break;
	case 3:
		if (object.checkFull() == 1)
		{
			cout << "The List is Full" << endl;
		}
		else
			cout << "The list is not Full" << endl;
		cout << "Do You want to perform other activities?(Y/N) ";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto Again;
		}
		else
			break;
	case 4:
		object.insert();
		cout << "Do You want to perform other activities?(Y/N) ";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto Again;
		}
		else
			break;
	case 5:
		object.Delete();
		cout << "Do You want to perform other activities?(Y/N) ";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto Again;
		}
		else
			break;
	case 6:
		object.Traverse();
		cout << "Do You want to perform other activities?(Y/N) ";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			goto Again;
		}
		else
			break;
	default:
		cout << "Wrong Choice Try Again!";
		goto Again;
	}
	return 0;
}
