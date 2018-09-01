#include<iostream>

using namespace std;

int Hash(int n)
{
	return n % 7;
}

struct Node
{
	int val = -1;
	Node *next = NULL;
};

bool Insert(Node*arr[], int key)
{
	int k = Hash(key);
	Node *p = arr[k];
	while (p&&p->next)
		p = p->next;
	if (p)
	{
		p->next = new Node;
		p->next->val = key;
	}
	else
	{
		arr[k] = new Node;
		arr[k]->val = key;
	}
	return 1;
}

void Delete(Node*arr[], int key)
{
	int k = Hash(key);

	Node *p = arr[k];
	Node *parent = arr[k];
	while (p&&p->val != key)
		{
				parent = p;
				p = p->next;
		}
	if (!p)
	    {
				cout << "not found";
				return;
		}
		else
		{
			if (p == arr[k])
				arr[k] = arr[k]->next;
			else
			{
				parent->next = p->next;
			    delete p;
			}
	     }
	
}

bool search(Node*arr[], int key)
{
	int k = Hash(key);
	Node*p = arr[k];
	while (p&&p->val != key)
		p = p->next;
	if (!p)
	{
		cout << "not found";
		return 0;
	}
	else
	{
		cout << "found";
		return 1;
	}
}

int main()
{
	int array[] = { 15,11,27,8 };
	Node*arr[7];
	for (int i = 0; i < 7; i++)
		arr[i] = NULL;
	for (auto c : array)
		Insert(arr, c);
	Delete(arr, 8);
	cout<<search(arr, 8);
	system("pause");
}