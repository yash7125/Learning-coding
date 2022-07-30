#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void yk()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5 + 1;

void max_heapify(int cur_index, int *arr, int n)
{
	int left = 2*cur_index;
	int right = 2*cur_index + 1;

	int largest = cur_index;

	//left child
	if(left <= n && arr[left] > arr[largest])
	{
		largest = left;
	}
	//right child
	if(right <= n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if(largest != cur_index)
	{
		swap(arr[largest], arr[cur_index]);
		max_heapify(largest, arr, n);
	}

	return;

}

void min_heapify(int cur_index, int *arr, int n)
{
	int left = 2*cur_index;
	int right = 2*cur_index + 1;

	int smallest = cur_index;

	if(left <= n && arr[left] < arr[smallest])
	{
		smallest = left;
	}
	if(right <= n && arr[right] < arr[smallest])
	{
		smallest = right;
	}

	if(smallest != cur_index)
	{
		swap(arr[cur_index], arr[smallest]);
		min_heapify(smallest, arr, n);
	}

}

void push(int val, int *arr, int n)
{
	arr[n + 1] = val;
	int cur = n + 1;

	while(cur > 1 && arr[cur / 2] < arr[cur])
	{
		swap(arr[cur], arr[cur / 2]);
		cur /= 2;
	}
}

void pop(int *arr, int n)
{
	if(arr[1] == -1) return;

	swap(arr[1], arr[n]);
	arr[n] = -1;
	n--;
	max_heapify(1, arr, n);
}

int top(int *arr)
{
	int n = sizeof(arr) / sizeof(int);
	if(arr[1] == -1) return -1;

	return arr[1];
}

int main() 
{	
	yk();

	int n;
	cin >> n;
	int arr[N];
	memset(arr,-1,sizeof(arr));

	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	max_heapify(1, arr, n);

	for(int i = n / 2; i >= 1; i--)
	{
		max_heapify(i, arr, n);
	}

	int heap_size = n;

	//heap sort
	// for(int i = n; i >= 2; i--)
	// {
	// 	swap(arr[1], arr[i]);
	// 	heap_size--;
	// 	max_heapify(1, arr, heap_size);
	// }

	push(9, arr, n);
	n++;
	for(int i = 1; i <= n + 1; i++)
	{
		cout << arr[i] << " ";
	} cout << '\n';

	pop(arr, n);

	for(int i = 1; i <= n + 1; i++)
	{
		cout << arr[i] << " ";
	} cout << '\n';

	// for(int i = 1; i <= n; i++)
	// {
	// 	cout << arr[i] << " ";
	// } cout << '\n';

	// for(int i = n / 2; i >= 1; i--)
	// {
	// 	min_heapify(i, arr, n);
	// }

	// for(int i = 1; i <= n; i++)
	// {
	// 	cout << arr[i] << " ";
	// } cout << '\n';

	return 0;
}
