import math

graph = {

}

graph['start'] = {} # Записываем все узлы.
graph['start']['a'] = 6 # Для каждого узла заполняем информацию о соседях и веса ребра.
graph['start']['b'] = 2

graph['a'] = {}
graph['a']['end'] = 1

graph['b'] = {}
graph['b']['a'] = 3
graph['b']['end'] = 5

graph['end'] = {}

costs = { # Здесь мы записываем ВСЕ ВОЗМОЖНЫЕ ЦЕНЫ МАРСШРУТОВ ДО УЗЛОВ.
    'start':0, # Необязательно и даже нежелательно
    'a':6, # Можем сразу дойти из 'страта' -> устанавливаем цену
    'b':2, # Можем сразу дойти из 'страта' -> устанавливаем цену
    'end':math.inf # Не можем сразу дойти из 'страта' -> устанавливаем цену inf
}

parents = { # Здесь мы записываем ВСЕХ ВОЗМОЖНЫХ РОДИТЕЛЕЙ УЗЛОВ.
    'a':'start',
    'b':'start',
    'end':None,
    'start':None #
}

processed = set() # Храним тут уже обработанные узлы

def find_lowest_cost_node(costs): # Находит нужный миннимальный узел в costs
    lowest_cost = math.inf
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost_node = node
            lowest_cost = cost
    return lowest_cost_node

node = find_lowest_cost_node(costs) # Находим минимальный узел в costs
# Миннимальный элемент позволяет проходить граф по порядку
while node is not None: # Веренет None когда все узлы будут в processed

    cost = costs[node] # Находим цену текущего узла
    neighbors = graph[node] # Находим соседей текущего узла

    for n in neighbors.keys(): # Перебераем всех соседей текущего узла
        new_cost = cost + neighbors[n] # Цена до соседа из n

        if costs[n] > new_cost: # Если эта цена меньше указанной в costs, то:
            costs[n] = new_cost # Меняем цену на меньшую
            parents[n] = node # Обновляем родителя

    processed.add(node) # Закидываем узел в обработанные
    node = find_lowest_cost_node(costs) # Находим новый узел для следующей итерации цикла

# Восстанавление марсшрута
if parents['end'] is None:
    print("Путь не найден!")
else:
    # восстановление пути
    way = []
    now = 'end'
    while now is not None:
        way.append(now)
        now = parents[now]
    print(way[::-1])
    print(costs['end'])
