# Computer Science exam implemented in C

## Middle term exam 
During this course, there was the possibility to attend a middle term exam, where the rpblem to be solved was described as following:
It was defined a **path** inside a matrix as a sequence of coordinates `(x, y)` of known length,  
where:
- `x` = row index  
- `y` = column index  
Indices start from 0.  

The path is represented using the following structure:
`typedef struct {int x, y;} Punto;`

The exercise requires the implementation of functions to:
1. Print a path,
2. Clean invalid points from a path,
3. Convert a path into a string by extracting characters from a given matrix.

In the main function, the string str must be printed, and with the provided values the output will be BRAVO.


## Written exam 
This was the rest of the exam, comprehending two exercise with data structure:

### Exercise 2 — Customer Points Aggregation

During this exercise, a linked list was provided to represent the points collected by customers after several purchases.  
Each node contains a **customer code** and a **score** obtained during a transaction.  
Since the same customer (same code) can appear multiple times in the list, the goal is to **aggregate** all the points of each customer and generate a new list where each code appears **exactly once**.

The list is represented using the following structure:
```c
typedef struct nodo {
    char codice[100];
    int punteggio;
    struct nodo *next;
} nodo;
typedef nodo *Lista;
```

The exercise requires the implementation of a function to:

- Traverse the input list,
- Identify all nodes with the same customer code,
- Sum their scores,
- Build a **new list** containing each unique code only once,
- Leave the original list unchanged.

The function to be implemented is:
```c
Lista Aggrega(Lista lista);
```

With the provided data in the main file, the resulting aggregated list will contain the following elements (order may vary):

```
(c1, 764) ---> (c2, 882) ---> (c3, 834) ---> (c4, 634) ---> (c5, 661) ---> ---|
```



### Exercise 3 — Minimum Average Path in a Binary Tree

In this exercise, a **binary tree** was given, where each node stores an integer value.  
The goal is to find, among all possible **root-to-leaf paths**, the one that has the **minimum average value** of its nodes.

The tree is represented using the following structure:
```c
typedef struct t {
    int val;
    struct t *left, *right;
} Nodo;
typedef Nodo *Tree;
```

The exercise requires the implementation of a function to:

- Explore all paths from the root to the leaves,
- Compute, for each path, the average of the node values,
- Return the **minimum average** among all computed paths.

The function to be implemented is:
```c
float costoMinimoMedio(Tree T);
```

A recursive auxiliary function is strongly recommended, passing along:
- the **current sum** of node values, and
- the **number of visited nodes** in the current path.

With the provided trees, the program must print:

```
Il percorso in T1 con media di valori minima ha media: 6.333333
Il percorso in T2 con media di valori minima ha media: 6.500000
Il percorso in T3 con media di valori minima ha media: 3.000000
```
