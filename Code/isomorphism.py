from itertools import permutations


matrix = [
    '3 6',
    '4 5 6',
    '1 4 5',
    '2 3 6',
    '2 3',
    '1 2 4'
]

graph = [
    'e f',
    'e c',
    'e b',
    'b e',
    'b c',
    'b d',
    'd b',
    'd a',
    'a d',
    'a c',
    'a f',
    'f a',
    'f e',
    'c e',
    'c b',
    'c a'
]

let = 'abcdef'

for var in permutations(let):
    dict = {l:i for i, l in enumerate(var)}

    FLAG = True
    for i in graph:
        x,y = i.split()

        xi = dict[x]
        yi = dict[y]

        if str(xi+1) not in matrix[yi] or str(yi+1) not in matrix[xi]:
            FLAG = False; break

    if FLAG:
        print(var)

