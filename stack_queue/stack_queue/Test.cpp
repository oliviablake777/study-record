#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

#include"Stack.h"
#include"Queue.h"
#include"PriorityQueue.h"
int main()
{
	//priority_queue<int> pq;
	// 17:13¼ÌÐø
	bit::priority_queue<int, vector<int>, Greater<int>> pq;
	//bit::priority_queue<int> pq;
	pq.push(4);
	pq.push(1);
	pq.push(5);
	pq.push(7);
	pq.push(9);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	return 0;
}