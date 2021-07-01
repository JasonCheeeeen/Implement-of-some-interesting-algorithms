# Implement of some interesting algorithms
There have four interesting algorithms including LCSS, Floyd-Warshall, Dijkstra and 8-puzzle problem by BFS.</br>
All of them were implemented by C++.</br>

## LCSS
* Input:
1. number of test data</br>
2. first string</br>
3. second string</br>

* Output:</br>
length of same substring.

* Sample input:</br>
3</br>
aabbacd</br>
aabacab</br>
mississippi</br>
ispim</br>
1123123</br>
111233</br>

* Sample output:</br>
5</br>
4</br>
5</br>

## Floyd-Warshall
* Input:
1. (int) m, n where m is total edges and n is total vertices.</br>
2. m numbers of weight for edges, like (a b 3) means it needs three points from a to b.</br>

* Output:</br>
two dimensional metrix which contain weight from each vertice to others vertices.</br>
if vertice cannot connect to one vertices, represent it "INF".</br>

* Sample input:</br>
5 9                                           
a b 3</br>
a c 8</br>
b d 1</br>
a e -4</br> 
c b 4</br>
b e 7</br>
d c -5</br>
d a 2</br>
e d 6</br>

* Sample output:</br>
0  1 -3  2 -4</br>
3  0 -4  1 -1</br>
7  4  0  5  3</br>
2 -1 -5  0 -2</br>
8  5  1  6  0</br>

## Dijkstra
* Input:
1. two vertices including stant and goal.</br>
2. (int) m which means numbers of edge.</br>
3. m numbers of weight for edges, like (a b 3) means it needs three points from a to b.</br>

* Output:</br>
length from start vertice to goal vertice.</br>

* Sample input:</br>
s d</br>
10</br>
s a 6</br>
s c 3</br>
a c 4</br>
a b 2</br>
b d 1</br>
c a 2</br>
c b 3</br>
c d 5</br>
d a 1</br>
d b 5</br>

* Sample output:</br>
7</br>

## 8-puzzle problem by BFS
* Input:
1. three lines of numbers(0~8) which represent the original state.</br>
2. three lines of numbers(0~8) which represent the goal state.</br>
* Output:</br>
the procedure of searching goal by BFS.</br>

* Sample output:</br>
<font color="#000066">1 2 3</font></br>
<font color="#000066">7 8 4</font></br>
<font color="#000066">0 6 5</font></br>
<font color="#660066">1 2 3</font></br>
<font color="#660066">8 0 4</font></br>
<font color="#660066">7 6 5</font></br>

* Sample output:</br>
<font color="#00dd00">1 2 3</font></br>
<font color="#00dd00">7 8 4</font></br>
<font color="#00dd00">0 6 5</font></br>
<font color="#0000dd">1 2 3</font></br>
<font color="#0000dd">0 8 4</font></br>
<font color="#0000dd">7 6 5</font></br>
<font color="#dddd00">1 2 3</font></br>
<font color="#dddd00">7 8 4</font></br>
<font color="#dddd00">6 0 5</font></br>
<font color="#006666">0 2 3</font></br>
<font color="#006666">1 8 4</font></br>
<font color="#006666">7 6 5</font></br>
<font color="#660066">1 2 3</font></br>
<font color="#660066">8 0 4</font></br>
<font color="#660066">7 6 5</font></br>
