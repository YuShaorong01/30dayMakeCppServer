#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);//����socket��TCPЭ��

    struct sockaddr_in serv_addr;//��������ַ
    bzero(&serv_addr, sizeof(serv_addr));//��ʼ��
    serv_addr.sin_family = AF_INET;//IPv4
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//������IP
    serv_addr.sin_port = htons(8888);//�������˿�

    bind(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr));//��socket����������ַ

    listen(sockfd, SOMAXCONN);//����socket
    
    struct sockaddr_in clnt_addr;//�ͻ��˵�ַ
    socklen_t clnt_addr_len = sizeof(clnt_addr);//�ͻ��˵�ַ����
    bzero(&clnt_addr, sizeof(clnt_addr));//��ʼ��

    int clnt_sockfd = accept(sockfd, (sockaddr*)&clnt_addr, &clnt_addr_len);//���ܿͻ�������

    printf("new client fd %d! IP: %s Port: %d\n", clnt_sockfd, inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));//��ӡ�ͻ�����Ϣ
    return 0;
}