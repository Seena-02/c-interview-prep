// TODO: Implement a basic TCP client (relevant for IoT cloud connectivity)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

// Basic socket workflow:
// 1. socket()    - Create socket file descriptor
// 2. connect()   - Connect to server
// 3. send/recv   - Exchange data
// 4. close()     - Clean up

// TODO: Implement a simple HTTP GET request
int http_get(const char* host, int port, const char* path, 
             char* response, size_t response_size) {
    int sockfd = -1;
    int result = -1;
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        goto cleanup;
    }
    
    // TODO: Resolve hostname to IP address using getaddrinfo()
    // TODO: Connect to server
    // TODO: Send HTTP request
    // TODO: Receive response
    
    result = 0;

cleanup:
    if (sockfd >= 0) close(sockfd);
    return result;
}

// TODO: Implement non-blocking connect with timeout
// This is important for embedded systems that can't block forever

// TODO: Implement a simple send/receive with timeout
// Using select() or poll()

// Interview questions:
// 1. What's the difference between TCP and UDP sockets?
// 2. What does SO_REUSEADDR do and when would you use it?
// 3. How do you handle partial send/recv?
// 4. What's the difference between blocking and non-blocking sockets?

// Embedded relevance:
// - TP-Link devices need to talk to cloud services
// - MQTT protocol runs over TCP
// - HTTP for firmware updates, status reporting

int main(void) {
    char response[4096];
    
    // Example: GET request to example.com
    // if (http_get("example.com", 80, "/", response, sizeof(response)) == 0) {
    //     printf("Response:\n%s\n", response);
    // }
    
    printf("TODO: Implement socket client\n");
    return 0;
}
