class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = {}

    def add_node(self, value):
        self.nodes.add(value)

    def add_edge(self, from_node, to_node, weight):
        self.edges.setdefault(from_node, []).append((to_node, weight))

def dijkstra(graph, start):
    visited = {start: 0}
    path = {}

    nodes = set(graph.nodes)

    while nodes:
        min_node = None
        min_dist = float('inf')
        for node in nodes:
            if node in visited and visited[node] < min_dist:
                min_node = node
                min_dist = visited[node]

        if min_node is None:
            break

        nodes.remove(min_node)
        current_weight = visited[min_node]

        for edge in graph.edges.get(min_node, []):
            neighbor, weight = edge
            weight += current_weight
            if neighbor not in visited or weight < visited[neighbor]:
                visited[neighbor] = weight
                path[neighbor] = min_node

    return visited, path

def shortest_path(graph, start, end):
    distances, paths = dijkstra(graph, start)
    path = []
    while end:
        path.append(end)
        end = paths.get(end)
    return distances

def print_distances_between_pairs(graph):
    nodes = list(graph.nodes)
    nodes.sort()
    for i in range(len(nodes)):
        for j in range(i+1, len(nodes)):
            start_node = nodes[i]
            end_node = nodes[j]
            shortest_path_result, distance_result = shortest_path(graph, start_node, end_node)
            print(f"Distance from {start_node} to {end_node}: {distance_result[end_node]}")

def main():
    graph = Graph()
    graph.add_node("A")
    graph.add_node("B")
    graph.add_node("C")
    graph.add_node("D")
    graph.add_node("E")
    graph.add_node("F")
    graph.add_edge("A", "B", 4)
    graph.add_edge("A", "C", 2)
    graph.add_edge("B", "C", 5)
    graph.add_edge("B", "D", 10)
    graph.add_edge("C", "D", 3)
    graph.add_edge("C", "E", 8)
    graph.add_edge("D", "E", 2)
    graph.add_edge("D", "F", 6)
    graph.add_edge("E", "F", 1)

    start_node = "A"
    end_node = "F"

    shortest_path_result, distance_result = shortest_path(graph, start_node, end_node)
    print("Shortest Path:", shortest_path_result)
    print("Shortest Distance:", distance_result[end_node])

    print("\nDistances between pairs of edges:")
    print_distances_between_pairs(graph)

if __name__ == "__main__":
    main()
