#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cerrno>
#include <sys/stat.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <fcntl.h>

#define PORT_ 6823

/*
* Необходимо реализовать клиент-серверное приложение под Linux. 
* Клиент - программа, запускаемая из консоли. 
* Сервер - демон, корректно завершающийся по сигналам SIGTERM и SIGHUP. 
* Клиент должен передать содержимое текстового файла через TCP. 
* Сервер должен принять и сохранить в файл.
*/

int Daemon();

void sig_catcher(int sig);

int main(int argc, char **argv) {

    int pid;
    pid = fork();

    if (pid == -1) {
        printf("Start Daemon Error: %s\n", strerror(errno));
        return -1;
    } else if (!pid) {
        umask(0);
        setsid();
        Daemon();

    } else {
        return 0;
    }
}

int Daemon() {
    int serv_socket_fd = 0;
    char buffer[1024];
    socklen_t client_len;
    char *file_path = "output";
    int filefd = 0;
    ssize_t read_return = 0;

    struct sockaddr_in client_name{};
    socklen_t size = sizeof(client_name);
    int client_socket_fd = 0;

    struct sockaddr_in name{};
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = INADDR_ANY;
    name.sin_port = htons(PORT_);

    serv_socket_fd = socket(PF_INET, SOCK_STREAM, 0);

    if (bind(serv_socket_fd, (struct sockaddr *) &name, sizeof(name)) == -1) {
        perror("bind");
        _exit(EXIT_FAILURE);
    }

    int errVal = listen(serv_socket_fd, 5);
    if (errVal == -1) {
        printf("Unable to listen\n");
    }

    for (;;) {
        signal(SIGHUP, sig_catcher);
        signal(SIGTERM, sig_catcher);

        client_len = sizeof(client_name);
        puts("waiting for client");
        client_socket_fd = accept(serv_socket_fd, (struct sockaddr *) &name, &client_len);

        filefd = creat(file_path, O_RDWR | O_CREAT | O_TRUNC | S_IRWXO | S_IRWXU);
        if (filefd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        do {
            puts("read");
            read_return = read(client_socket_fd, buffer, sizeof(buffer));
            strncat(buffer, "\0", 1);

            printf("%zd, %s, '\n'", read_return, "read_return");
            if (read_return == 0)
                break;
            if (read_return == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            if (write(filefd, buffer, read_return) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        } while (read_return > 0);
        close(filefd);
        close(client_socket_fd);
    }
}

void sig_catcher(int sig) {
    switch (sig) {
        case SIGHUP:
            puts("hang up signal catched");
            _exit(0);

        case SIGTERM:
            puts("exit signal catched");
            _exit(0);

        default:
            _exit(EXIT_FAILURE);
    }
}
