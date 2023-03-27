#include <iostream>
using namespace std;

struct SkewHeap
{
	int data;
	SkewHeap* left;
	SkewHeap* right;
};

SkewHeap* newNode(int x)
{
	SkewHeap* p = new SkewHeap();
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

SkewHeap* mergeHeap(SkewHeap* h1, SkewHeap* h2)
{
	if (!h1) return h2;

	if (!h2) return h1;

	if (h1->data > h2->data) swap(h1, h2);

	swap(h1->left, h1->right);

	h1->left = mergeHeap(h2, h1->left);

	return h1;
}

SkewHeap* insert(SkewHeap* sh, int x)
{
	SkewHeap* node = newNode(x);

	sh = mergeHeap(sh, node);

	return sh;
}

void nhap(SkewHeap*& sh)
{
	int x;
	do
	{
		cout << "\n Nhap Gia Tri: "; cin >> x;
		if (x == -99) break;
		sh = insert(sh, x);
	} while (1);
}

void xuat(SkewHeap* sh)
{
	if (!sh) return;
	cout << " " << sh->data;
	xuat(sh->left);
	xuat(sh->right);
}

SkewHeap* deleteHeap(SkewHeap* sh)
{
	if (sh == NULL)
	{
		cout << "\n Skew Heap Rong ! ";
		return NULL;
	}

	SkewHeap* left = sh->left;

	SkewHeap* right = sh->right;

	SkewHeap* merged = mergeHeap(left, right);

	delete sh;

	return merged;

}

void displayMenu()
{
	cout << "\n\n\t\t-----------------------" << endl;
	cout << "\n\n\t\t1. Nhap Gia Tri " << endl;
	cout << "\n\n\t\t2. Xuat Gia Tri " << endl;
	cout << "\n\n\t\t3. Tron Cay " << endl;
	cout << "\n\n\t\t4. Xoa Goc Cua Cay " << endl;
	cout << "\n\n\t\t0. Thoat Chuong Trinh " << endl;
	cout << "\n\n\t\t-----------------------" << endl;
	cout << "\n\n\t\t Nhap 1 So Nguyen De Thuc Thi: ";
}

int main()
{
	SkewHeap* sh = NULL;
	int choice;
	bool isRunning = true;
	while (isRunning)
	{
		displayMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			nhap(sh);
			break;
		case 2:
			system("cls");
			xuat(sh);
			break;
		case 3:
			system("cls");
			SkewHeap * sh1;
			SkewHeap* node;
			sh1= NULL;
			cout << "\n Nhap Cay Thu Nhat: ";
			nhap(sh);
			cout << "\n Nhap Cay Thu Hai: ";
			nhap(sh1);
			node = mergeHeap(sh, sh1);
			xuat(node);
			break;
		case 4:
			system("cls");
			SkewHeap * deletePrt;
			deletePrt = deleteHeap(sh);
			xuat(deletePrt);
			sh = deletePrt;
			break;
		case 0:
			system("cls");
			isRunning = false;
			break;
		default: 
			cout << " Lua Chon Khong Hop Le, xin vui long nhap lai! " << endl;
			break;
		}
	}
	return 0;
}


