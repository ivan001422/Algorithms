# Размен монет

| Задача и подход | Реализация |
| --- | --- |
| Минимальное число монет: рекурсия без мемоизации | [min_coins_recursive.cpp](min_coins_recursive.cpp) |
| Минимальное число монет: мемоизация (top-down) | [min_coins_memoized.cpp](min_coins_memoized.cpp) |
| Минимальное число монет: итеративное ДП (bottom-up) | [min_coins_iterative.cpp](min_coins_iterative.cpp) |
| Восстановление набора монет минимального размера | [min_coins_with_path.cpp](min_coins_with_path.cpp) |
| Подсчёт комбинаций, порядок монет не важен | [count_combinations.cpp](count_combinations.cpp) |

Сумма и номиналы заданы в исходниках. `count_combinations.cpp` раньше назывался
`f2.py`, хотя содержал код C++; исправлено только имя и расширение файла.
Пустая заготовка `coin_solutionCNT_iter` заменена этим описанием раздела.

[К динамическому программированию](../README.md) · [К оглавлению](../../../README.md)
