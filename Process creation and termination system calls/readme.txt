# abdul_2020485
Name := Abdul Aziz
roll number:-2020485
hello!

problem statement:-
The  exercise deals using process creation system call, fork(). You need to
write a program that spawns a child process, using the fork() system call. The
child process reads a CSV file, presented with the assignment, that has (fake)
student IDs and grades of various assignments. This child process computes the
average score of each assignment across students of section ‘A’, and thereafter
prints the details of these assignments (of section ‘A’, i.e.). The parent process
does the same operation, on the same CSV file but for assignments given to
students of section ‘B’.
The parent process must wait for the child process to terminate, by using the
system call waitpid(). The child process must call the exit() system callonce
its execution ends.
Now create a separate program which repeats exactly the same steps as
above, but uses threads using pthread create() and pthread join(). For
the program that uses threads, once the averages are computed, also compute
the average score of each assignment across the sections by reusing the result
obtained by the two threads.

You would require to refer to the manpages for various system calls men-
tioned.



steps to compile:-
first open the assingment folder
make sure you are in same same which contain makefile. 
then open terminal 
them in terminal type
    "make all"
it will make all the files reqired 
then type
    "make run"
to run the required program





for fork alone:-
then type ./q1fork
then this will show you results 

for thread alone:-  
then type ./q1thread
this will show the results

Process for q1thread:
here thread header file use.


I made two array, A and B which are initialized with zero. 
A[i]=sum of assignment(i+1) marks for section A; i belongs (0,6)
B[i]=sum of assignment(i+1) marks ; i belongs (0,6)
Then I opened Student record.CSV Using open command.
 The open command takes to argument. First is the path of the file. Second is the type which it's opened. 
The open also returns FP, which is of type int. 
After that, I initialized a while loop, which does not end, until the full file is read. 
Read the file. I used read syscall. 
The read syscall takes file descriptor as one of its arguments. 
I take the character one by one and concatenate in it in a line. Later. I checked if I am at the end of the line, if true, then I checked if I'm in which section and then by increasing its value of A[index] and B[index], 
the strtokk break the line at "," and store it in value later atoi used to convert it in int.
So, at the end of the while loop, our array of A and B. Got, filled with assignments marks. 
later I created P_thread t1 and t2
then I passed it in pthread_create, passing the t1, null, function, and argument. here I gave array A and then Array B as the argument.
pthread_join ends the thread and return thread function result, In this I stored average of all assignment of given section.
the second call do the same.




how files are written q1fork:
-> first of all I opened the student_result.csv using open syscall it takes file path and flag 
-> then i used the read syscall which take argument int 
	fd: file descriptor
	buf: buffer to read data from	
	cnt: length of buffer
it read the data then store in line , if line gets '\n then it enter the loop we use strtok the break line at "," then check sec and storing it that selection assignment array 
after every iteration we  make line balnk again meanwhile increasing and counting the number of student in section A and B respectively 
after that I called the fork() which return 0 if child ,i also returned -1 if fork do not work , Fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork()
then in if i checked if its child if yes then i called the average function calculating one by one and its return the answer 
in the else section i first checked waitpid Wait for a specific child process to end to check if the child is finished . 
waitpid take the id of child in parameter i
then section B average score per assingment is calculated . 



SYSCALLS USED :-              
open :-	Used to Open the file for reading takes fielname  and mode as its parameter 
close :-used to close the fil take  file descriptor as parameter
read :-From the file indicated by the file descriptor fd, the read() function reads cnt bytes of input into the memory area takes fd , buffer and buffer lenght as argumnts.
fork:- Fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call it return int type it and takes no arguments.
waitpid() :-waitpid() is used to wait for a process to finish and taked id of child as argument with status .
thread_create :-Creates a new thread within a process , takes 4 arguments.The first argument is a pointer to thread_id which is set by this function.The second argument specifies attributes. The third argument is name of function to be executed for the thread to be created.The fourth argument is used to pass arguments to the function.
thread_join:-used to ensure thread is terminated and also return value of fucntion thread has taken takes 2 arguments
