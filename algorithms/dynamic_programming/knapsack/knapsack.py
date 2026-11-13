costs = {
    'gitar':{'cost':1500, 'weight':1},
    'magnitofon':{'cost':3000, 'weight':4},
    'laptop':{'cost':2000, 'weight':3},
    'telephone':{'cost':2000, 'weight':1}
}

objects = [s for s in costs]

max_weight = 4
matrix = [[0] * (max_weight+1) for _ in range(len(costs))]

for obj_inx in range(len(objects)):
    object = objects[obj_inx]
    object_cost = costs[object]['cost']
    object_weight = costs[object]['weight']
    for w in range(1, max_weight+1):
        matrix[obj_inx][w] = matrix[obj_inx-1][w]

        if w >= object_weight:
            matrix[obj_inx][w] = max(matrix[obj_inx][w], object_cost + matrix[obj_inx-1][w-object_weight])

print(matrix[0])
print(matrix[1])
print(matrix[2])
print(matrix[3])
