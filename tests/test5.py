def floyd_warshall(graph, V):
    dist = [float('inf')] * (V * V)

    # Initialize distances with graph values
    for i in range(V):
        for j in range(V):
            if i == j:
                dist[i * V + j] = 0
            elif graph[i * V + j] != 0:
                dist[i * V + j] = graph[i * V + j]

    # Update distances
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i * V + k] + dist[k * V + j] < dist[i * V + j]:
                    dist[i * V + j] = dist[i * V + k] + dist[k * V + j]

    return dist

def print_distances(dist, V):
    print("Shortest distances between every pair of vertices:")
    for i in range(V):
        for j in range(V):
            print(dist[i * V + j], end=" ")
        print()

# Test case
graph = [
    0, 5, 0, 10,
    0, 0, 3, 0,
    0, 0, 0, 1,
    0, 0, 0, 0
]
V = 4

result = floyd_warshall(graph, V)
print_distances(result, V)
