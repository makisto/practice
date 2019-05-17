#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;
	
void DFS(int ** graph, int n, bool * visited, int ccNum, int * cc, int st)
{
	visited[st]= true;
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
	cout << "Количество компонент связности - " << ccNum << endl;
	for(int i = 0; i < n; i++)
	{
		cout << i + 1 << " вершина - " << cc[i]  << " компонента " << endl;
	}	
}

int ** fillMatrix(int n)
{
	int ** graph = new int * [n];
	for(int i = 0; i < n; i++)
	{
		graph[i] = new int[n];
	}
	
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = 0;	
		}
	}
	return graph;
}

void printMatrix(int ** graph, bool * visited, int n)
{
	cout << "Матрица смежности графа: " <<endl;
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		for (int j = 0; j < n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}	
}

int countSteps(int n)
{
	int step = 0;
	
	for(int i = n - 1; i >= 1; i--)
	{
		step += i;
	}

	return step;
}

int main()
{
	srand(time(NULL));
	
	int ccNum = 0;
	int ** graph;
	bool ** vis;
	bool * visited;
	int * cc;
	int n;
	int g;
	int z;
		 		
	m:cout << "Количество вершин - ";
	cin >> n;
	if((n <= 1) || (n > 1000))
	{
		cout << "Неверные данные!" << endl;
		goto m;
	}
	
	vis = new bool*[n];
	for(int i = 0; i < n; i++)
	{
		vis[i] = new bool[n];
		for(int j = 0; j < n; j++)
		{
			vis[i][j] = false;	
		}	
	}		
	
	visited = new bool[n];
	cc = new int[n];
	
	graph = fillMatrix(n);
	
 	m1:printMatrix(graph, visited, n);
	solve(graph, n, cc, visited, ccNum);
	
	cout << "Изменить количество вершин?" << endl;
	cin >> g;
	switch(g)
	{
		case 0:
			system("cls");
			goto m;
		default:
			break;
	}
	
    int k = 0;
	int z1, z2;
	m2:cout << "Кол - во элементов?" << endl;
	cin >> z;
	if((z < 0) || (z > countSteps(n)))
	{
		cout << "Неверные данные" << endl;
		goto m2;
	}
	
	while(k < z)
	{
		m3:cout << "Строка - ";
		cin >> z1;
		cout << "Столбец - ";
		cin >> z2;
		if((z1 < 1) || (z1 > n) || (z2 < 1) || (z2 > n))
		{
			cout << "Введите данные заново" << endl;
			goto m3;
		}
		if(z1 == z2)
		{
			cout << "Петли недопустимы!Введите данные заново" << endl;
			goto m3;
		}
		
		z1--;
		z2--;
		if(vis[z1][z2] == true)
		{
			cout << "Эта вершина уже была изменена!" << endl;
			goto m3;
		}
		
		graph[z1][z2] = 1 - graph[z1][z2];
		graph[z2][z1] = graph[z1][z2];	
		vis[z1][z2] = vis[z2][z1] = true;
		k++;		
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			vis[i][j] = false;	
		}	
	}
	
	system("pause");
	system("cls");
	goto m1;
	return 0;
}
