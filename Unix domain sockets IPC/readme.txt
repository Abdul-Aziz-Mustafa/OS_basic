Problem Statement-The goal of this  exercise is to develop a better understanding of the Linux
interprocess communication mechanisms. This would require you to write two
programs P1 and P2. The first program P1 needs to generate an array of 50
random strings (of characters) of fixed length each. P1 then sends a group of
five consecutive elements of the array of strings to P2 along with the ID’s of
the strings, where the ID is the index of the array corresponding to the string.
The second program P2 needs to accept the received strings, and send back
the highest ID received back to P1 to acknowledge the strings received. The
program P2 simply prints the ID’s and the strings on the console. On receiving
the acknowledged packet, P1 sends the next five strings, with the string elements
starting from the successor of the acknowledged ID.

The above mechanism needs to be implemented using three different tech-
niques: (i) Unix domain sockets, (ii) FIFOs, and (iii) message passing queues.

Please note that you may NOT make assumptions about the reliability of the in-
terprocess communication mechanism, unless they are guaranteed by the mech-
anism itself.





First of open the folder in terminal then type make 
after that open two terminals side by side 
then run ./q2 after that then ./q1

you will see string recieving at speed of 1 seconds

//EXPLANATION of msgqueue
I used two structs one to send message string other to send the indexes
Then i used the key to match.
then i also created an array of string of size 50 populated with random string.
then i opened a while loop started sending message and indexes in 5 size using for loop 

In the mqrec.c I used a loop to reciecve the data sended one by one then used a variable max to store max index sent here.

after that i sent back the max index back to mq.c using msgsend
that mq.c recieves that message and update the index atrting to send next 5 message string the process continues undit last of indexes recieved
////
First of open the folder socket in terminal then type make 
after that open two terminals side by side 
then run ./server after that then ./client

//EXPLANATION of socket 
In this i made a cleint and server here cleint sent data and server recieves it retrive the max index and send it back to cleint 
here i first assingened some common port and ip address 
then in while loop i i send data in packet of 5 along with indexes and index used htonl and ntohl to send integers some common socket conpects are used here like listen connect bind
recv and send is used to send and revcieve the respected data

//EXPLANATION of FIFO
First of open the folder pipes in terminal then type make 
after that open two terminals side by side 
then run ./sender after that then ./rec


first of all i made random array of string of size 50 and used it to send the data
i created two fucntion recieve and send recieve function receives the  data then open the mkfifo file which i named sum and then read the data while the sender open the mkfifo write to it same thing happens in pipe2.c all things happens in a while loop 



