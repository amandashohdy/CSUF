Given the following CFG
    E -> E & T
    E -> E % T
    E -> F!
    F -> F < T
    F -> F > T
    F -> t | f
    T -> (E) | t | f
Write a program to trace an input string given by the user. Save it as Prog1 and upload it here. Test your program with the following input strings: 
(1) t&(f%t)$
(2) t<f!$
(3) t>(t<f)$
Show the content of the stack after each match. 
