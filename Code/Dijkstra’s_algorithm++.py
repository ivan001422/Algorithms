import math

graph = {
    'пекин': {'питер': 30},
    'омск': {'пекин': 6},
    'питер': {'москва': 2, 'омск': 15},
    'амстердам': {'питер': 20, 'париж': 20},
    'москва': {'питер': 2, 'амстердам': 15},
    'лондон': {'москва': 5, 'амстердам': 40, 'париж': 4, 'воркута': 1},
    'париж': {},
    'воркута': {'лондон': 1}
}

INF = math.inf

costs = {node: INF for node in graph}
costs['пекин'] = 0

parents = {node: None for node in graph}
processed = set()

def find_lowest_cost_node(costs):
    min_cost = INF
    min_cost_node = None
    for node, node_cost in costs.items():
        if node_cost < min_cost and node not in processed:
            min_cost = node_cost
            min_cost_node = node
    return min_cost_node, min_cost

node, node_cost = find_lowest_cost_node(costs)
while node is not None:
    if node in graph:
        for neighbor, weight in graph[node].items():
            new_cost = node_cost + weight
            if new_cost < costs[neighbor]:
                costs[neighbor] = new_cost
                parents[neighbor] = node
    processed.add(node)
    node, node_cost = find_lowest_cost_node(costs)

# Восстановление пути
target = 'амстердам'
if parents[target] is not None:
    way = []
    now = target
    while now is not None:
        way.append(now)
        now = parents[now]
    print(way[::-1])
