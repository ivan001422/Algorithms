# Алгоритм поиска в глубину (DFS)
# Работает с деревьями

DICT = { # Дерево-каталог
    'pics':'2001 summer.png',
    '2001':'winter.png space.png',
    'space.png':'',
    'winter.png':'',
    'summer.png':''
}

# Т.к в деревьях нет циклов, то можем не проверять узлы на повторы
def DFS(x): # Алгоритм сразу доходит до листовых узлов
    for i in DICT[x].split():
        if DICT[i] == '':
            print(i)
        else:
            DFS(i)

DFS('pics')
