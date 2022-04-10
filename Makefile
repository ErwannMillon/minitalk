USRCS = bitwise_operations.c
UOBJS = $(USRCS:%.c=%.o)
CLIENTSRC = client.c
CLIENTOBJ = $(CLIENTSRC:%.c=%.o)
SERVERSRC = server.c
SERVEROBJ = $(SERVERSRC:%.c=%.o)
HEADERS = $(wildcard *.h)
CFLAGS = -Wall -Werror -Wextra

%.o:%.c
	gcc $(CFLAGS) -c $^ -lft
all: libft.a client server 
	./server
client: $(CLIENTOBJ) $(UOBJS) libft.a 
	gcc $(CFLAGS) $(CLIENTOBJ) $(UOBJS) -lft -o client 
git:
	git add $(CLIENTSRC) $(SERVERSRC) $(USRCS) Makefile $(HEADERS) ./libft
server: $(SERVEROBJ) $(UOBJS) libft/libft.a 
	gcc $(CFLAGS) $(SERVEROBJ) $(UOBJS) -lft -o server 
libft.a:
	make -C libft bonus
	mv libft/libft.a ./
clean:
	rm -f $(UOBJS) $(CLIENTOBJ) $(SERVEROBJ)
fclean: clean
	rm -f server client
re: fclean all
.PHONY: libft/libft.a libft