This readme explains the epselon closure and nfa simulation component.

Follow the guidelines for input string and give input regular expression.
The program first gives output of corresponding nfa in form of 2-d array.
Then it asks for the state input to find its epselon closure. And then an input string to parse the nfa and return 0 if rejected and 1 if accepted. (Note: a state can only be a single character). 
The state character = ascii character of the (state index+ascii of '0'):
e.g. the integer states and their corresponding ascii characters. (it means for states 0-9 you can input numbers 0-9 to get epselon closure. But for states 10, 11, 12,... enter :, ;, <,..... so on). 
(char state= int state+'0';)

0 0
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 :
11 ;
12 <
13 =
14 >
15 ?
16 @
17 A
18 B
19 C
20 D
21 E
22 F
23 G
24 H
25 I
26 J
27 K
28 L
29 M
30 N
31 O
32 P
33 Q
34 R
35 S
36 T
37 U
38 V
39 W
40 X
41 Y
42 Z
43 [
44 \
45 ]
46 ^
47 _


