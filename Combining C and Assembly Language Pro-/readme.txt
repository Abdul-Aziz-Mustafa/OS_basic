problem Statement:-
This second exercise is aimed to serve two objectives – writing assembly lan-
guage programs and secondly to help combine a C program with and assembly

language function. You need to do the following:
1. Write a program with three functions A(), B() and C().
2. A() should call B() passing a 64-bit integer as an argument.
3. B() should interpret that as a 8-byte ASCII string and print individual
characters on screen. You need to call the write() system call from

assembly language using the syscall instruction, passing appropriate ar-
guments.

4. Modify the stack in the function B() in such a way that when B() executes
the ret instruction, it jumps to a third function C(). C() must also be
written in C. This MUST happen without an explicit call to function C().
A mere ret from B, should pass the control to function C() instead of
A(). Finally, the function C() needs to terminate the program by using
the exit() system call.
5. You ofcourse also need a main() function from where the program starts.
The C file with the main() function could also have the function A() (i.e.,
main() could call A()).
6. The functions A(), B() and C() need to be in three different files. You
may use printf() or write() functions to display which function you are
in.





steps to compile:-
first open the assingment folder
make sure you are in same same which contain makefile. 
then open terminal ("make sure you have nasm compiler) 
them in terminal type
    "make all"
it will make all the files reqired 
then type
    "make run"
to run the required program

///////////////////////////////////////////
In this question I created  three files 2 c program  and 1 .asm program

A_function is c program and have main in it
it also have a fuction having llong long int data type this function call a function from c_function.asm and pass lonf long int parameter
here extern used to call that function from asm 

B_fucntion is .asm file 

Section data has string which have length of 45 and the screen name is welcome 
.BSS section has a a data type of 8 bit and  address label is at strv. 
Has global which is name of function B_function also it called the C_function  using extern command 
Now in B_function I push the C_function in stack and then move the argument of the C function in strv 
RAX,1  is used for writing on screen 
RDI,1 is used for writing on screen 
Move RDX is 45 because it is size of welcome label 
Then we wrote strv  e on the screen using   mov rax,1  || mov rdi,1  and who are rdx,1 which is size of strv 
then return 

C_function is c program 
  it just print a statement and then exit 
