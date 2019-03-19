Input: 
Firstly if we want to give only a single alphabet as regex then we should give it as
1. , (b), (c)
 Note that a,b,c is not a valid input
If we want to give union then 
(A+B)           where A and B are valid substring
If we want to give concatenation then 
(A.B)           where A and B are valid substring
If we want to give Kleene star then 
A*           where A is valid substring
Some examples of valid input:
((((a)+(b))+((c)+(d))).(e))
((a)+(b))
(a)*
(((a)*.(b)*).(a))
(((a)+(b)).(c))*
(((a).(b)).(a))
((a)*.(b))
((a).(b))
Some wrong inputs:
((a))*
a+b
a.b






Output:
We will get number of states and the adjacency matrix
If there is adj[i][j] = 0 at an entry of adjacency matrix then there is no edge between node i and node j.
If there is adj[i][j] = e at an entry of adjacency matrix then there is epsilon transition between node i and node j.
If there is adj[i][j] = “a” at an entry of adjacency matrix then edge between node i and node j. Node i will go to node j after seeing “a”


Note: Do not include ‘e’ in the regular expression because we are considering “e” as epsilon.