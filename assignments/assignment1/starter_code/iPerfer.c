#include<stdio.h>
#include <stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<time.h>
#include<string.h>


int main(int argc, char *argv[]){
    if(strcmp(argv[1],"-s") == 0) {
        if (argc != 4) { printf("Error: missing or additional arguments \n"); }
        int serverport = atoi(argv[3]);
        if (serverport < 1024 || serverport > 65535) {
            printf("Error: port number must be in the range 1024 to 65535 \n");
        }

        int serverfd = 0, connectfd = 0;
        struct sockaddr_in server_addr, client_addr;
        int sin_size;
        int yes = 1;
        clock_t conn_start, conn_end;
        double total_time;
        char read_buffer[1000];
        int read_size;
        char finish_flag[1000];
        finish_flag[0] = 'F';
        char FIN_ACK[1000];
        FIN_ACK[0] = 'E';
        long double kbytes_received = 0;

        //create socket
        serverfd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverfd == -1) { printf("cannot create a socket! \n"); }
        puts("Socket created");

        //prepare
        server_addr.sin_family = AF_INET;
       	server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(atoi(argv[3]));
        if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            perror("Error: set socket option\n");
            exit(1);
        }

        //bind
        if (bind(serverfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) < 0) {
            printf("Error: bind failed \n");
            return 1;
        }
        puts("bind done \n");

        //listen
        listen(serverfd, 10);
        puts("waiting for connections \n");

        //accpet
        sin_size = sizeof(struct sockaddr_in);
        connectfd = accept(serverfd, (struct sockaddr *) &client_addr, &sin_size);
        if (connectfd < 0) { printf("accept failed \n"); }
        puts("Connection accepted \n");

        //start counting time
        conn_start = time(NULL);
        printf("connect time starts\n");

	double bytes;
        //receive & send and shutdown
        while(1){
            bytes = recv(connectfd,read_buffer,1000,0);
            //printf("%c\n", read_buffer[0]);
            kbytes_received += bytes/1000.0;
            if(!(strstr(read_buffer,"F") == NULL)){
                printf("FIN received!\n");
                send(connectfd, &FIN_ACK, 1000, 0);
                printf("FIN_ACK sent!\n");
                break;
            }
        }
        shutdown(serverfd,2);
        conn_end = time(NULL);
        printf("connect time ends\n");
        total_time = (double) (conn_end - conn_start);
        printf("received = %LG KB, rate = %LG Mbps", kbytes_received, (kbytes_received / 1000) / total_time * 8);
    }
    else if(strcmp(argv[1],"-c") == 0){
        if(argc != 8){printf("\n Error: missing or additional arguments \n");}
        int listenport = atoi(argv[5]);
        if (listenport < 1024 || listenport > 65535) {
            printf("Error: port number must be in the range 1024 to 65535 \n");
        }

        int sock;
        char data[1000];
        char finished_flag = 'F';
        char FIN_ACK = 'E';
        struct sockaddr_in server;

        //create socket
        sock = socket(AF_INET , SOCK_STREAM , 0);
        if (sock == -1)
        {
            printf("Could not create socket\n");
        }
        puts("Socket created\n");

        server.sin_addr.s_addr = inet_addr(argv[3]);
        server.sin_family = AF_INET;
        server.sin_port = htons(atoi(argv[5]));

        // connect to server
        if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
            perror("Error:connect failed \n");
            return 1;
        }
        puts("Connected \n");

        //send & receive and shutdown
        float kbytes_sent = 0;
	//long KB_sent = 0;
        int duration = atoi(argv[7]);
        memset(data,'0',sizeof(data));
        time_t start = time(NULL);
        time_t end = start + duration;
	double bytes;
        //while(time(NULL) < end){
            bytes = send(sock, &data, 1000, 0);
            kbytes_sent += (float)bytes/1000;
	    printf("%f %f\n",bytes, kbytes_sent);
	    //KB_sent = bytes_sent/1000;
            //printf("\nhahahhah\n");
        //}
        send(sock, &finished_flag, 1000, 0);
        printf("FIN sent!\n");
        printf("%f \n", kbytes_sent);
        if(recv(sock, &FIN_ACK, 1000, 0) == 1000){
            printf("%f \n", kbytes_sent);
            printf("FIN_ACK received!\n");
        }
        printf("%f \n", kbytes_sent);
        shutdown(sock,2);
        printf("%f \n", kbytes_sent);
        printf("sent = %f KB, rate = %f Mbps", kbytes_sent, (8 * kbytes_sent) / duration / 1000);
    }
}
