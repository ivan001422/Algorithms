# Algorithms

Учебные реализации алгоритмов на Python, C и C++. Примеры сгруппированы
по темам; реализации одной задачи на разных языках лежат рядом.

## Навигация

| Тема | Содержание |
| --- | --- |
| [Основы C++](basics/cpp/README.md) | Ввод и вывод, типы данных, псевдонимы типов и макросы |
| [Сортировки](algorithms/sorting/README.md) | Пузырьковая, выбором, быстрая, слиянием, подсчётом и поразрядная |
| [Поиск](algorithms/searching/README.md) | Бинарный поиск, поиск ближайшего числа и поиск в матрице |
| [Графы](algorithms/graphs/README.md) | BFS, DFS, алгоритм Дейкстры и изоморфизм |
| [Перебор с возвратом](algorithms/backtracking/README.md) | Перестановки, подмножества и задача о N ферзях |
| [Комбинаторика](algorithms/combinatorics/README.md) | Подсчёт расстановок двух ферзей |
| [Динамическое программирование](algorithms/dynamic_programming/README.md) | Монеты, рюкзак, пути, подпоследовательности, строки и битовые маски |
| [Жадные алгоритмы](algorithms/greedy/README.md) | Раздел для будущих реализаций |
| [Оценка сложности](theory/complexity/README.md) | O-нотация, ограничения и стоимость операций |
| [Инверсии](theory/sorting/inversions.md) | Связь инверсий с сортировкой |

## Структура

```text
algorithms/
├── sorting/
├── searching/
├── graphs/
├── backtracking/
├── combinatorics/
├── dynamic_programming/
│   ├── coin_change/
│   ├── knapsack/
│   ├── grid_paths/
│   ├── sequences/
│   ├── strings/
│   ├── elevator_bitmask.cpp
│   └── rod_cutting.py
└── greedy/
basics/
└── cpp/
theory/
├── complexity/
└── sorting/
```

## Запуск

Каждый исходный файл — самостоятельный пример со своим набором данных
или вводом из stdin. Единой точки входа нет. Для Python достаточно Python 3
без сторонних пакетов. Для C/C++ нужен компилятор; команды ниже используют GCC.
В некоторых примерах C++ есть массивы переменной длины — расширение GCC.

Команды выполняются из корня репозитория.

Python:

```bash
python3 algorithms/sorting/bubble_sort.py
```

C++:

```bash
mkdir -p build
g++ -std=c++17 -O2 algorithms/sorting/quick_sort.cpp -o build/quick_sort
./build/quick_sort
```

C:

```bash
mkdir -p build
gcc -std=c11 -O2 algorithms/searching/binary_search.c -o build/binary_search
./build/binary_search
```

Поиск ближайшего числа (бывший `Project/project_1.py`):

```bash
python3 algorithms/searching/nearest_binary_search.py <<'EOF'
5 5
1 3 5 7 9
2 4 8 1 6
EOF
```

Ожидаемый вывод:

```text
1
3
7
1
5
```

`algorithms/sorting/bubble_sort.cpp` использует Windows API (`windows.h`)
и не собирается обычным Linux-компилятором. Остальные исходники тоже являются
учебными примерами; их наличие в каталоге не означает, что все они проверены.

## Добавление примеров

- Выбирайте каталог по теме алгоритма, а не по языку реализации.
- Используйте латинские имена в `snake_case` и расширение языка: `.py`, `.c`, `.cpp`.
- Реализации одной задачи на разных языках называйте одинаково: `lis.py`, `lis.cpp`.
- Вариант алгоритма уточняйте в имени: `min_coins_memoized.cpp`, `min_coins_with_path.cpp`.
- Условия задач и пояснения храните в исходнике или README соответствующей темы,
  общую теорию — в `theory/`. Обновляйте навигацию при добавлении новой темы.
- Результаты сборки складывайте в `build/`.
