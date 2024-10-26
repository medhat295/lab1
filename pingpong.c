/*
Ahmed Medhat
120210063
Question 3
PingPong
*/


#include "types.h"
#include "stat.h"
#include "user.h"



int main(int argc, char *argv[]) {
    int p1[2], p2[2];
    char recv_buf[5];

    pipe(p1); 
    pipe(p2); 

    if (fork() == 0) { 
        close(p1[1]); 
        close(p2[0]); 

        read(p1[0], recv_buf, 4); 
        recv_buf[4] = '\0';
        printf(1, "%d: received %s\n", getpid(), recv_buf);

        write(p2[1], "pong", 4); 

        close(p1[0]); 
        close(p2[1]); 
        exit();
    } else { 
        close(p1[0]); 
        close(p2[1]); 

        write(p1[1], "ping", 4); 

        read(p2[0], recv_buf, 4); 
        recv_buf[4] = '\0';
        printf(1, "%d: received %s\n", getpid(), recv_buf);

        close(p1[1]); 
        close(p2[0]); 
        wait(); 
        exit();
    }
}
