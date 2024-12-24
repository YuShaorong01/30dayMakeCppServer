#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);//创建socket，TCP协议

    struct sockaddr_in serv_addr;//服务器地址
    bzero(&serv_addr, sizeof(serv_addr));//初始化
    serv_addr.sin_family = AF_INET;//IPv4
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//服务器IP
    serv_addr.sin_port = htons(8888);//服务器端口

    bind(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr));//绑定socket到服务器地址

    listen(sockfd, SOMAXCONN);//监听socket
    
    struct sockaddr_in clnt_addr;//客户端地址
    socklen_t clnt_addr_len = sizeof(clnt_addr);//客户端地址长度
    bzero(&clnt_addr, sizeof(clnt_addr));//初始化

    int clnt_sockfd = accept(sockfd, (sockaddr*)&clnt_addr, &clnt_addr_len);//接受客户端连接

    printf("new client fd %d! IP: %s Port: %d\n", clnt_sockfd, inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));//打印客户端信息
    return 0;
}