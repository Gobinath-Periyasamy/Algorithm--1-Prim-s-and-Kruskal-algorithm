# CS6140W-Algorithm-1-Prim-s-and-Kruskal-algorithm
Implementation of Prim's and Kruskal algorithm.


CS6140W - Advanced Data Structures and Algorithms - Programming Assignment 1 - Prim's and Kruskal Algorithm.

Name : Gobinath Periyasamy

Roll Number : CS21M501

Registered Mail id : janu.gobi@gmail.com

Steps to Execute the Program:

1.  To Execute PrimsKruskalAlgo.exe to execute both Prim's and Krushkal Algorithm at a time, (or Else to execute PrimAlgo.exe or Krushkal.exe to execute separately)
2.  To Enter the Number of Vertices : Eg : 7
3.  To Enter Diagonal Elements for given number of Vertices. (For easy testing purpose, Please use the given sample values (given bullet number 5) to copy paste if needed)

    Eg :      
              
              Enter the Number of Vertices : 7

              Only the Diagonal Elements are enough to get stored
              
              Since the Undirected Graph Weights are Symmeteric

              Enter values for row : 1
              
              (1 2) : 25
              
              (1 3) : 0
              
              (1 4) : 0
              
              (1 5) : 0
              
              (1 6) : 5
              
              (1 7) : 0
              
              Enter values for row : 2
              
              (2 3) : 12
              
              (2 4) : 0
              
              (2 5) : 0
              
              (2 6) : 0
              
              (2 7) : 10
              
              Enter values for row : 3
              
              (3 4) : 8
              
              (3 5) : 0
              
              (3 6) : 0
              
              (3 7) : 0
              
              Enter values for row : 4
              
              (4 5) : 16
              
              (4 6) : 0
              
              (4 7) : 14
              
              Enter values for row : 5
              
              (5 6) : 20
              
              (5 7) : 18
              
              Enter values for row : 6
              
              (6 7) : 0
              
              Enter values for row : 7
              
4. Please refer the attached image files.
5. Diagonal weight values (without vertex):
    
    
25

0

0

0

5

0

12

0

0

0

10

8

0

0

0

16

0

14

20

18

0



The Sample Input and Output are : 

C:\Users\ALgorithms And Data Structure\primskruskal>g++ -o PrimsKruskalAlgo PrimsKruskalAlgo.cpp

C:\Users\ALgorithms And Data Structure\primskruskal>PrimsKruskalAlgo

*********************************************

* Created on Wed May 05 12:59:26 2022       *

* Name: Gobinath P                          *

* Roll No : CS21M501                        *

* Prim's Algorithm and Krushkal's Algorithm *

*********************************************

Enter the Number of Vertices : 7



Only the Diagonal Elements are enough to get stored

Since the Undirected Graph Weights are Symmeteric

Enter values for row : 1

(1 2) : 25

(1 3) : 0

(1 4) : 0

(1 5) : 0

(1 6) : 5

(1 7) : 0

Enter values for row : 2

(2 3) : 12

(2 4) : 0

(2 5) : 0

(2 6) : 0

(2 7) : 10

Enter values for row : 3

(3 4) : 8

(3 5) : 0

(3 6) : 0

(3 7) : 0

Enter values for row : 4

(4 5) : 16

(4 6) : 0

(4 7) : 14

Enter values for row : 5

(5 6) : 20

(5 7) : 18

Enter values for row : 6

(6 7) : 0

Enter values for row : 7





Array Table for Storing Edges' weights :



Destination |  1          2       3       4       5       6       7

-----------------------------------------------------------------------

Source Node1 |  99999   25      99999   99999   99999   5       99999

Source Node2 |  25      99999   12      99999   99999   99999   10

Source Node3 |  99999   12      99999   8       99999   99999   99999

Source Node4 |  99999   99999   8       99999   16      99999   14

Source Node5 |  99999   99999   99999   16      99999   20      18

Source Node6 |  5       99999   99999   99999   20      99999   99999

Source Node7 |  99999   10      99999   14      18      99999   99999





***********************************************

***********************************************

*              Prim's Algorithm               *

***********************************************

***********************************************

The weight of (1-6) is 5

The weight of (5-6) is 20

The weight of (4-5) is 16

The weight of (3-4) is 8

The weight of (2-3) is 12

The weight of (7-2) is 10



Given Vertex : 7

Given Edges : 9



******************************************************************************************

* The Total Weight of Min Spanning Tree using Prim's Algorithm is : 71

* Final Edges after Prim's Algorithm : 6

* Time Complexity of the Algorithm is O(V**2)

******************************************************************************************





***********************************************

***********************************************

*          Krushkal's Algorithm               *

***********************************************

***********************************************



Edge Table :



1       2       25

1       6       5

2       3       12

2       7       10

3       4       8

4       5       16

4       7       14

5       6       20

5       7       18



Minimum Cost Spanning Tree Edges



ACycle Min Edge 1 : (1,6)--->   5

ACycle Min Edge 2 : (3,4)--->   8

ACycle Min Edge 3 : (2,7)--->   10

ACycle Min Edge 4 : (2,3)--->   12

ACycle Min Edge 5 : (4,5)--->   16

ACycle Min Edge 6 : (5,6)--->   20





******************************************************************************************

* The Total Weight of Min Spanning Tree using Krushkal's Algorithm is : 71

* Final Edges after Krushkal's Algorithm : 6

* Time Complexity of the Algorithm is O(ElogV)

******************************************************************************************



