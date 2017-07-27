#include"server.h"

int main()
{
	int sockfd,new_fd;
	struct sockaddr_in my_address;			    // ���ص�ַ��Ϣ 
	struct sockaddr_in their_address;			// �����ߵ�ַ��Ϣ 
	int sin_size;

	WSADATA ws;
	WSAStartup(MAKEWORD(2,2), &ws);			     //��ʼ��windows Socket dll

	sockfd = socket(AF_INET, SOCK_STREAM, 0);    //����socket

	my_address.sin_family = AF_INET;             //Э��������INET
	my_address.sin_port = htons(8080);           //�󶨶˿�8080
	my_address.sin_addr.s_addr = INADDR_ANY;     //����IP

	bind(sockfd, (sockaddr*)&my_address, sizeof(sockaddr));

	listen(sockfd, 5);  //����
	std::cout<<"����..."<<std::endl;

	sin_size=sizeof(sockaddr_in);
	new_fd=accept(sockfd, (sockaddr*)&their_address, &sin_size);

	Message msg;
	int numbytes = recv(new_fd, (char*)&msg, sizeof(msg), 0);
	std::cout<<"�������Կͻ��˵���Ϣ��"<<msg.nummsg<<std::endl;

	msg.nummsg = 120;
	send(new_fd, (const char*)&msg, sizeof(msg), 0);
	std::cout<<"�������"<<std::endl;

	closesocket(sockfd);
	closesocket(new_fd);

	system("pause");
	return 0;
}