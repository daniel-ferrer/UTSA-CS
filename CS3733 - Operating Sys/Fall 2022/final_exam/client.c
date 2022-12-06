#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>

#define port 8080
#define MAX 80

static volatile sig_atomic_t sigreceived = 0;

void my_signal_handler(int signo) 
{ 
    sigreceived = 1; 
    printf("CTRL-C has been received\n");
} 

void func(int socket) 
{ 
    int n, userInput; 
    char buff[MAX], output[MAX]; 
    char *userInputID = (char *)malloc((MAX)*sizeof(char));

    memset((char*)&buff, 0, sizeof(buff));
    if(userInput != 1 || userInput != 2) 
    { 
        printf("Enter '1' to GETSALARY ID or Enter '2' to STOP:\n"); 
        scanf("%d", &userInput); 
        buff[0] = '\0'; 
    }
    
    if(userInput == 1) 
    { 
        strcpy(buff, "GETSALARY "); 

        printf("Enter an Employee ID: "); 
        scanf("%s", userInputID); 

        strncat(buff, userInputID, 6); 
        printf("Client Request: %s\n", buff); 

        write(socket, buff, sizeof(buff)); 

        output[0] = '\0';
        printf("%s\n", buff);
        memset((char *)&buff, 0, sizeof(buff));
        n = read(socket, buff, sizeof(buff));
        
        while(n > 0) 
        { 
            strncat(output, buff, n); 
            
            if(buff[n] == '\0') 
            { 
                break; 
            } 
            n = read(socket, buff, sizeof(buff)); 
        } 
        printf("Server Response: %s\n", output);
    } 
    else if(userInput == 2) 
    { 
        printf("Client Request: 'STOP'");
        buff[0] = '\0'; 
        strcpy(buff, "STOP"); 
        write(socket, buff, sizeof(buff)); 
        close(socket); 
        printf("[-] Connection Closing ...\n\n"); 
    } 
    else
    {
        fprintf(stdout, "ERROR: Please enter 1 or 2\n");
    } 
    return;
}

main(argc, argv)
    int     argc;
    char    *argv[];
{
  struct  sockaddr_in sad; /* structure to hold an IP address     */
  int     clientSocket;    /* socket descriptor                   */ 
  struct  hostent  *ptrh;  /* pointer to a host table entry       */
  int     n;

  sigset_t blockedmask, oldmask, unblockedmask;

  printf("[...]Client waiting for SIGINT Ctrl-C\n");

  int signum = SIGUSR1;

  sigprocmask(SIG_SETMASK, NULL, &blockedmask);
  sigprocmask(SIG_SETMASK, NULL, &unblockedmask); 
  sigaddset(&blockedmask, signum); 
  sigdelset(&unblockedmask, signum); 
  sigprocmask(SIG_BLOCK, &blockedmask, &oldmask); 
  signal(SIGINT, my_signal_handler);
  
  while(sigreceived == 0) 
  { 
      sigsuspend(&unblockedmask); 
  } 

  sigprocmask(SIG_SETMASK, &oldmask, NULL);

  /* Create a socket. */

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  if(clientSocket < 0)  
  { 
      fprintf(stderr, "[-] Socket creation failed\n"); 
      exit(1);
  }
  /* Connect the socket to the specified server. */

  memset((char *)&sad,0,sizeof(sad)); /* clear sockaddr structure */
  sad.sin_family = AF_INET;           /* set family to Internet     */ 
  sad.sin_addr.s_addr = inet_addr("129.115.27.205");
  sad.sin_port = htons((u_short)port);
  
  if (connect(clientSocket, (struct sockaddr *)&sad, sizeof(sad)) < 0) {
    fprintf(stderr,"[-] connect failed\n");
    exit(-1);
  } 
  printf("[+] Client-Server Connection Established\n"); 
  func(clientSocket);
  return;
}