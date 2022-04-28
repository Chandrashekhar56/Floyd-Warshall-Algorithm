#include <bits/stdc++.h>
using namespace std;
#define totalVertices 4
#define Infinite 99999
void result(int distance[][totalVertices]);
void function_of_floyd_Warshall(int graph[][totalVertices])
{
	int distance[totalVertices][totalVertices], x, y, z;

	for (x = 0; x < totalVertices; x++)
		for (y = 0; y < totalVertices; y++)
			distance[x][y] = graph[x][y];

	for (z = 0; z < totalVertices; z++)
    {
		for (x = 0; x < totalVertices; x++)
		{
			for (y = 0; y <totalVertices; y++)
			{
				if (distance[x][y] > (distance[x][z] + distance[z][y])&& (distance[z][y] != Infinite && distance[x][z] != Infinite))
					distance[x][y] = distance[x][z] + distance[z][y];
			}
		}
	}
	result(distance);
}
void result(int distance[][totalVertices])
{
	cout << "distances between all vertices \n";
	for (int x = 0; x < totalVertices; x++)
	{
		for (int y = 0; y < totalVertices; y++)
        {
			if (distance[x][y] == Infinite)
			cout <<"INF"<<"\t";
			else
			cout <<distance[x][y]<<"\t";
		}
		cout << endl;
	}
}
int main()
{
	int graph_for_floyd_Warshall[totalVertices][totalVertices] = { { 0, 4, Infinite, 8},
                                                                       { Infinite, 0, 2, Infinite },
                                                                       {Infinite, Infinite, 0, 1 },
                                                                       { Infinite, Infinite, Infinite, 0 }
                                                                     };
	function_of_floyd_Warshall(graph_for_floyd_Warshall);
	return 0;
}

