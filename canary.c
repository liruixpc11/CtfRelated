#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int g_client_fd;
char g_flag_buffer[512] = {0};

void send_all(int fd, const char *buffer, size_t length) {
    size_t bytes = 0;
    while (bytes < length) {
        ssize_t count = send(fd, buffer + bytes, length - bytes, 0);
        if (count <= 0) {
            return;
        }

        bytes += count;
    }
}

void client_handler() {
    char buffer[40] = {0};

    send_all(g_client_fd, "welcome!\n", 9);
    recv(g_client_fd, buffer, 0x40, 0);
    printf("received %s\n", buffer);
}

void send_flag() {
    send_all(g_client_fd, g_flag_buffer, sizeof(g_flag_buffer));
}

int main() {
    struct sockaddr_in server_addr = {
            .sin_family = AF_INET,
            .sin_addr.s_addr = htonl(INADDR_ANY),
            .sin_port = htons(5555),
    };

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listen_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(listen_fd, 10);

    while (1) {
        int client_fd = accept(listen_fd, NULL, NULL);
        if (client_fd == -1) {
            printf("accept failed\n");
            exit(1);
        }

        printf("new connction fd = %d\n", client_fd);

        int pid = fork();
        if (pid == 0) {
            g_client_fd = client_fd;
            break;
        } else {
            close(client_fd);
        }
    }

    client_handler();
    send_all(g_client_fd, "Message Received\n", 17);
    close(g_client_fd);
    g_client_fd = 0;

    return 0;
}