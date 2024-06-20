Given the following CFG <br>
  E -> E & T <br>
  E -> E % T <br>
  E -> F! <br>
  F -> F < T <br>
  F -> F > T <br>
  F -> t | f <br>
  T -> (E) | t | f <br>
Write a program to trace an input string given by the user. Save it as Prog1 and upload it here. Test your program with the following input strings: <br>
(1) t&(f%t)$ <br>
(2) t<f!$ <br>
(3) t>(t<f)$ <br>
Show the content of the stack after each match. 
