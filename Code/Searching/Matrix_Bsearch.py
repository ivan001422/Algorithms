# Бинарный поиск в отсортированной матрице

matrix = [ # Отсортированная матрица по столбцам и строкам.
    [1,  2,  3,  4 ],
    [5 , 6 , 7 , 8 ],
    [9 , 10, 11, 12],
    [13, 14, 15, 16],
]

y = 4 # Высота матрицы
x = 4 # Ширина матрицы


def search_sorted_matrix_2d(matrix, target):

    h, w = len(matrix), len(matrix[0])

    # Начинаем с верхнего правого угла
    h_inx, w_inx = 0, w - 1

    while h_inx < h and w_inx >= 0:

        if matrix[h_inx][w_inx] == target:
            return matrix[h_inx][w_inx]

        elif matrix[h_inx][w_inx] < target:
            # Все элементы в этой строке слева меньше текущего
            # Значит target может быть только в строках ниже
            h_inx += 1
        else:
            # Все элементы в этом столбце ниже больше текущего
            # Значит target может быть только в столбцах левее
            w_inx -= 1

    return False

# Тест
print(search_sorted_matrix_2d(matrix , 8))
