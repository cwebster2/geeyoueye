#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
 
struct hdr
{
	uint8_t opcode;
	uint32_t length;
};

int main(int argc, char **argv)
{
	int sock, ret, sent, side;
	struct sockaddr_in sin;
	struct hdr *h;
	char *picstart;
	char temp[50];
	char *pic;
        int fd;
	struct stat filenfo;

	fd = open(argv[1], O_RDONLY);
        if (fd < 0)
	{
	   perror("open");
	   exit(1);
	}
        side = 90 + atoi(argv[2]);
	fstat(fd, &filenfo);
        printf("%d Bytes read from file\n", filenfo.st_size);

	pic = malloc((filenfo.st_size)+8);
	h = (struct hdr*)pic;
	picstart = pic+sizeof(struct hdr);
	h->opcode = side;
	h->length = filenfo.st_size;
        read(fd, (picstart), filenfo.st_size);

	sock = socket(AF_INET, SOCK_STREAM, 0x6);
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_port = htons(9098);

	connect(sock, (struct sockaddr*)&sin, sizeof(sin));
        sent = 0;
	do {
	   ret = send(sock, (pic+sent), filenfo.st_size+sizeof(struct hdr)-sent, 0);
	   printf("send %d bytes\n", ret);
	   sent += ret;
	}while (ret > 0);
	printf("send %d bytes total\n", sent);

	h->opcode = 92;
	h->length = 0;
	send(sock, h, sizeof(struct hdr), 0);

	close(sock);
	close(fd);
	free(pic);

	return 0;
}
