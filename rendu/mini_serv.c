#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "stdlib.h"
#include "stdio.h"

int		max_fd = 0, id = 0, arr_id[1024];
fd_set	actual_set, read_set, write_set;
char	buff_send[65536 * 2], buff_read[65536 * 2], arr_str[1024][1024];

void	ft_exit_error(char *str) {
	write(2, str, strlen(str));
	exit(1);
}

void	ft_send_message(int sender_fd, char *msg) {
	for (int receiver_fd = 3; receiver_fd <= max_fd; receiver_fd++) {
		if (FD_ISSET(receiver_fd, &write_set) && receiver_fd != sender_fd) {
			send(receiver_fd, msg, strlen(msg), 0);
		}
	}
}

void	ft_register_client(int connfd) {
	max_fd = connfd > max_fd ? connfd : max_fd;
	arr_id[connfd] = id++;
	FD_SET(connfd, &actual_set);
	sprintf(buff_send, "server: client %d just arrived\n", arr_id[connfd]);
	ft_send_message(connfd, buff_send);
}

void	ft_disconnect_client(int fd) {
	sprintf(buff_send, "server: client %d just left\n", arr_id[fd]);
	ft_send_message(fd, buff_send);
	FD_CLR(fd, &actual_set);
	close(fd);
}

void	ft_send_big_message(int count, int fd) {
	for (int i = 0, j = 0; i < count; i++, j++) {
		arr_str[fd][j] = buff_read[i];
		if (arr_str[fd][j] == '\n') {
			arr_str[fd][j] = '\0';
			sprintf(buff_send, "client: %d: %s\n", arr_id[fd], arr_str[fd]);
			ft_send_message(fd, buff_send);
			j = -1;
		}
	}
}

int main(int argc, char **argv) {
	int	sockfd, connfd;
	socklen_t	len;
	struct	sockaddr_in servaddr, cli;

	if (argc != 2) {
		ft_exit_error("Wrong number of arguments\n");
	}

	// socket create and verification
	// AF_INET      IPv4 Internet protocols
	// SOCK_STREAM: TCP
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		ft_exit_error("Fatal error\n");
	}
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
		ft_exit_error("Fatal error\n");
	}
	if (listen(sockfd, 10) != 0) {
		ft_exit_error("Fatal error\n");
	}
	len = sizeof(cli);
	max_fd = sockfd;
	FD_ZERO(&actual_set);
	FD_SET(sockfd, &actual_set);

	// server run
	while (1) {
		read_set = write_set = actual_set;

		// wait and add new connection
		if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) < 0) {
			continue ;
		}
		for (int fd = 3; fd <= max_fd; fd++) {
			if (FD_ISSET(fd, &read_set)) {

				// connect new client
				if (fd == sockfd) {

					// wait and extract new connection
					connfd = accept(sockfd, (struct sockaddr *) &cli, &len);
					if (connfd < 0) {
						continue;
					} else {
						ft_register_client(connfd);
						break;
					}

					// disconnect or send
				} else {

					// check connection
					int count = recv(fd, buff_read, 65536 * 2, 0);

					if (count <= 0) {
						ft_disconnect_client(fd);
						break;
					} else {
						ft_send_big_message(count, fd);
						break;
					}
				}
			}
		}
	}
}
