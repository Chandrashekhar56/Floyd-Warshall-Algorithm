totalVertices = 4
Infinite= 99999
def function_of_floyd_Warshall(graph):
	distance = list(map(lambda x: list(map(lambda y: y, x)), graph_for_floyd_Warshall))
	for z in range(totalVertices):
		for x in range(totalVertices):
			for y in range(totalVertices):
				distance[x][y] = min(distance[x][y],distance[x][z] +distance[z][y])
	result(distance)


def result(distance):
    print ("shortest distances between all vertices")
    for x in range(totalVertices):
        for y in range(totalVertices):
            if(distance[x][y] == Infinite):
                print ("INF",end=" ")
            else:
                print ((distance[x][y]),end=" ")
            if y == totalVertices-1:
                print ()

		
graph_for_floyd_Warshall = [[0, 4, Infinite, 8],
	 [Infinite, 0, 2, Infinite],
	 [Infinite, Infinite, 0, 1],
	 [Infinite, Infinite, Infinite, 0]
	]
function_of_floyd_Warshall(graph_for_floyd_Warshall)
