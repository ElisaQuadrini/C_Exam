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

The project requires the implementation of functions to:
1. Print a path,
2. Clean invalid points from a path,
3. Convert a path into a string by extracting characters from a given matrix.

In the main function, the string str must be printed, and with the provided values the output will be BRAVO.
