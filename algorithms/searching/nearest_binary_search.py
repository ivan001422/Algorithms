''' 

Реализуйте алгоритм приближенного бинарного поиска.

Входные данные
В первой строке входных данных содержатся числа N
 и K
(0<N,K<100001). Во второй строке задаются N
чисел первого массива, отсортированного по неубыванию, а в третьей строке – K
чисел второго массива. Каждое число в обоих массивах по модулю не превосходит 2⋅(10 ** 9).

Выходные данные
Для каждого из K
чисел выведите в отдельную строку число из первого массива, наиболее близкое к данному. Если таких несколько, выведите меньшее из них.

Примеры
Входные данные
5 5
1 3 5 7 9 
2 4 8 1 6 
Выходные данные
1
3
7
1
5

'''

def binary_search(arr, target):
    n = len(arr)

    # Граничные случаи
    if target <= arr[0]:
        return arr[0]
    if target >= arr[-1]:
        return arr[-1]

    low, high = 0, n - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return arr[mid]
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    # После выхода из цикла:
    # arr[high] < target < arr[low]

    # Сравниваем расстояния
    diff_low = arr[low] - target
    diff_high = target - arr[high]

    if diff_low < diff_high:
        return arr[low]
    elif diff_high < diff_low:
        return arr[high]
    else:
        # Если расстояния равны, возвращаем меньший
        return arr[high]



a , b = input().split()

a , b = int(a) , int(b)

arr1 = [int(s) for s in input().split()]
arr2 = [int(s) for s in input().split()]

for i in arr2:
    print(binary_search(arr1 , i))
