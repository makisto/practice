#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
	
void DFS(int ** graph, int n, bool * visited, int ccNum, int * cc, int st)
{
	//cout << st + 1 << " ";
	visited[st] = true;
	cc[st] = ccNum;
	for (int r = 0; r < n; r++)
	{
		if ((graph[st][r]) && (!visited[r]))
		{
			DFS(graph, n, visited, ccNum, cc, r);		
		}
	}
}

void solve(int ** graph, int n, int * cc, bool * visited, int ccNum)
{
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			ccNum++;
			DFS(graph, n, visited, ccNum, cc, i);	
		}	
	}
	cout << "���������� ��������� ��������� - " << ccNum << endl;	
}

int main()
{
	srand(time(NULL));
	int ccNum = 0;
	int n;
	m:system("CLS");
	cout << "���������� ������ - ";
	cin >> n;
	
	int ** graph = new int * [n];
	for(int i = 0; i < n; i++)
	{
		graph[i] = new int[n];
	}
	
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i == j)
			{
				graph[i][j] = 0;	
			}
			else
			{
				graph[i][j] = rand() % 2;
				if((graph[i][j] == 1) && (graph[j][i] == 0))
				{
					graph[j][i] = 1;
				}
				if((graph[i][j] == 0) && (graph[j][i] == 1))
				{
					graph[j][i] = 0;
				}
			}
		}
	}
	
	bool * visited = new bool[n];
	int * cc = new int[n];
	
	cout << "������� ��������� �����: " <<endl;
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		for (int j = 0; j < n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	solve(graph, n, cc, visited, ccNum);
	for(int i = 0; i < n; i++)
	{
		cout << i + 1 << " ������� - " << cc[i]  << " ���������� " << endl;
	}
	system("pause");
	goto m;
	return 0;
}
