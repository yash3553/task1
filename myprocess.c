#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int ports[] = {4040};
    for (int i = 0; i < 2; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(ports[i]);
        addr.sin_addr.s_addr = inet_addr("1.1.1.1");
        printf("Trying port %d...\n", ports[i]);
        int res = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
        if (res == 0) {
            printf("Connected to port %d\n", ports[i]);
        } else {
            perror("connect failed");
        }
        close(sock);
    }
    return 0;
}
