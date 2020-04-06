#include<iostream>
using namespace std;

int ar[100];




void MaxHeapify(int idx, int N)
{
	int leftChild = 2 * idx;
	int rightChild = 2 * idx + 1;
	int largestIndex = idx;
	
	if (leftChild <= N && ar[leftChild] > ar[idx])
		largestIndex = leftChild;
	if (rightChild <= N && ar[rightChild] > ar[largestIndex])
		largestIndex = rightChild;
	
	if (largestIndex != idx)
	{
		ar[idx] = ar[idx] ^ ar[largestIndex];
		ar[largestIndex] = ar[idx] ^ ar[largestIndex];
		ar[idx] = ar[idx] ^ ar[largestIndex]; 

		MaxHeapify(largestIndex, N);
	}

}



void BuildMaxHeap(int N)
{
	for (int I = N / 2; I >= 1; I--)
		MaxHeapify(I, N);
}



int main()
{
	int N;
	cin >> N;

	for (int I = 1; I <= N; I++)
		cin >> ar[I];

	BuildMaxHeap(N);

	return 0;
}


/*
7
6 4 5 3 2 0 1
*/