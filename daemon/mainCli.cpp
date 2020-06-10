#include <cstdio>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>

void sendFile(int socket_fd, const char *text);

int main(int argc, char *const argv[]) {

    struct sockaddr_in name{};
    char *socket_name = nullptr;
    const char *file = nullptr;
    long server_port = 0;
    int socket_fd;
    in_addr_t in_addr;

    if (argc > 1) {
        file = argv[1];
        if (argc > 2) {
            socket_name = argv[2];
//            if (argc > 3) {
//                server_port = strtol(argv[3], nullptr, 10);
//                puts("full");
//            }
        }
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    in_addr = inet_addr(socket_name);
    if (in_addr == -1) {
        exit(EXIT_FAILURE);
    }
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = in_addr;
    name.sin_port = htons(6823);

    int er = connect(socket_fd, (const sockaddr *) (&name), sizeof(sockaddr_in));
    if (er == -1) {
        perror("connect failure");
        return EXIT_FAILURE;
    }
    sendFile(socket_fd, file);
    close(socket_fd);

    return 0;

}

void sendFile(int socket_fd, const char *text) {

    FILE *file = fopen(text, "r");
    char *buffer[1024]{};
    ssize_t er;

    while (!feof(file)) {
        size_t b = fread(buffer, sizeof(char), sizeof(buffer), file);

        printf("bytes read: %zu \n", b);

        if (b != 0) {
            er = write(socket_fd, buffer, b);
            puts("succes");
        }
        if (er == -1)
            puts("oops");

    }
}
