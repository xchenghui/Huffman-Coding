#include<iostream>
#include<vector>
using namespace std;

void InsertionSort(vector<int> &A)
{
	for(int j = 1; j < A.size(); j++)
	{
		int key = A[j];
		
		int i = j-1;
		
		while(i >=0 && A[i]> key)
		{
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = key;
	}
	for(int z = 0; z<A.size(); z++)
	{
		cout<<A[z]<<endl;
	}
}



int main()
{
	vector<int> a;
	a.push_back(10);
	a.push_back(1);
	a.push_back(9);
	a.push_back(6);
	a.push_back(2);
	a.push_back(36);
	a.push_back(8);
	a.push_back(39);
	a.push_back(39);
	a.push_back(39);
	InsertionSort(a);
	system("pause");
	return 0;
}
