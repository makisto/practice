#include <iostream>

using namespace std;
	
void DFS(int ** graph, int n, bool * visited, int comps_col, int * cc, int ver)
{
	visited[ver] = true;
	cc[ver] = comps_col;
	for (int i = 0; i < n; i++)
	{
		if ((graph[ver][i]) && (!visited[i]))
		{
			DFS(graph, n, visited, comps_col, cc, i);		
		}
	}
}

void solve(int ** graph, int n, int * cc, bool * visited, int comps_col)
{
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;		
	}
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			comps_col++;
			DFS(graph, n, visited, comps_col, cc, i);	
		}	
	}
	cout << "Количество компонент связности - " << comps_col << endl;
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
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = 0;	
		}
	}
	return graph;
}

void printMatrix(int ** graph, int n)
{
	cout << "Матрица смежности графа: " <<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}	
}

void fixmatrix(int n, int ** graph)
{
	int z1, z2;

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
		
	graph[z1][z2] = 1 - graph[z1][z2];
	graph[z2][z1] = graph[z1][z2];	
}

int main()
{	
	int comps_col = 0;
	int ** graph;
	bool * visited;
	int * cc;
	int n, g, z;
		 		
	m:cout << "Количество вершин - ";
	cin >> n;
	if((n <= 1) || (n > 50))
	{
		cout << "Неверные данные!" << endl;
		goto m;
	}
						
	visited = new bool[n];
	cc = new int[n];
	
	graph = fillMatrix(n);

 	while(g != 4)
 	{
 		system("CLS");
 		printMatrix(graph, n);
 		cout << "1 - Изменение количества вершин" << endl;
 		cout << "2 - Вывод компонент связности" << endl;
 		cout << "3 - Изменение элементов матрицы" << endl;
 		cout << "4 - Выход" << endl;
 		cin >> g;
 	 	switch(g)
	 	{
	 	    case 1:
				goto m;
			case 2:
				solve(graph, n, cc, visited, comps_col);
				system("PAUSE");
				break;
			case 3:
				fixmatrix(n, graph);
				break;
			default:
				break;	
		}	
	}
		
	return 0;
}
