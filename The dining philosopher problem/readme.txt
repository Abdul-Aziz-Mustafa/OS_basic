problem statement:-

The dining philosopher problem is a classic problem in deadlock management. The
problem can be described briefly as follows. There is a round table around which a
total of five philosophers are sitting. There are also a total of five plates in front of the
philosophers and five forks, one each beside each plate. A philosopher can only eat if
s/he can get two forks lying beside the plate. The philosophers do not have any means
of communicating with each other to control access to their forks. A situation where
none of the philosophers is able to eat because they are all able to access a single fork
(but not both) is called deadlock. The goal is to design a protocol of choosing the
forks among the dining philosophers so that no deadlock occurs.
1. Write a C program to solve a modified version of dining philosopher problem
involving five philosophers, each having a plate and a fork to his/her left and
another on the right.

2. Assume that the philosophers need to access only a single fork to eat. In ad-
dition to the forks, the philosophers also need have access to any one of the

four sauce bowls kept in the center of the table and accessible to all. Is a
deadlock possible? If so, write a C program that implements the deadlock-free
solution. The philosophers could be represented by threads. You need to ensure
that your solution is free of deadlocks, i.e. it should be designed such that it
avoids/prevents deadlocks.
3. Now assume that the philosophers need both the forks to eat AND the sauce
bowls to eat. Write another program to implement the deadlock-free solution
of this version of the problem.






-------Readme file for  ---------
->First, open your terminal and open the directory in which our solutions are present.
->Then on terminal type make to compile this file, and you will get the executable file name.
->The run the executable by then  ./diningx' (x belongs 1 2 3) command .
->Code run successfully


<Code Explanation part 1>
   
Here I created the one semaphores one for the spoon , spoon one is binary semaphore.
Then I created 5 threads resembling each philosopher and set a room limit ti four so that only 4 philosopher could enter at a time.
I create the function pointer void * philosopher(void *num).
pass philospher function pointer in it with their respective arguments.
In philosopher funtion
we lock semaphore for left then right spoons, and then after eating we unlock all the semaphore . Here  eating() function used for eating .
also, giving a sleep time of 2 sec 
after all the step we just destroy the semaphore which was created before.


<Code Explanation part 2>
In this part it is clear that thre is no deadlock condition becuse in critical condition, even 4 philosophers can eat 
we can use a bowl variable and then start decreasing every time philospher enter and increse when philosopher exit



<Code Explanation part 3>
   
Here i created the two semaphores one for the spoon and othre for bowl ,spoon one is binary semohor
then i created 5 thread resembling each philospher and set room limit to 4 so that only 4 philosopher could enter at a time.
I create the function pointer void * philosopher(void *num).
pass philospher function pointer in it with their respective arguments.
In philosopher funtion
we lock semphore  for left then right spoons and 1 bowl and then after eating we unlock all the semaphore . Here  eating() function used for eating .
also giving a sleep time of 2 sec 
after all the step we just destroy the semaphore  which was created before.