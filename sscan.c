#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
    int main(int argc, char *argv[]){
        struct sockaddr_in get;
	int porta, cnx, sock;
	porta = atoi(argv[2]);
	get.sin_family = AF_INET;
	get.sin_port = htons(porta);
	get.sin_addr.s_addr = inet_addr(argv[1]);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == -1){
	    perror("Não conectado.\n");
	    exit(EXIT_FAILURE);
	
	}
	else{
	    cnx = connect(sock, (struct sockaddr_in *)&get, sizeof(get));
	    if(cnx == -1){
	        perror("Porta fechada.\n");
		exit(EXIT_FAILURE);
	    }
	    else if(cnx == 0){
	        printf("Porta [%d] aberta!\n", porta);
	    }
	    else{
	        printf("code: %d", cnx);
	    
	    }
	}

        close(sock);
	close(cnx);
    
    
        return EXIT_SUCCESS;
    }
