def binary_search(arr , target):

    low = 0
    hight = len(arr) - 1

    while low <= hight:
        point = (low + hight) // 2
        guess = arr[point]

        if guess == target:
            return point

        elif guess > target:
            hight = point - 1

        else:
            low = point + 1

    return None


# Тест
print(binary_search([1, 2, 3 , 4 , 5] , 4))


'''-----------Информация о бинарном поиске-----------

1) Время выполнения: O(log n).
2) Работает только с отсортированными массивами.
3) Выведет None при отсутствии цели в нашем массиве.

'''
