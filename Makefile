USRCS = bitwise_operations.c conversion_utils.c
UOBJS = $(USRCS:%.c=%.o)
CLIENTSRC = client.c
CLIENTOBJ = $(CLIENTSRC:%.c=%.o)
SERVERSRC = server.c
SERVEROBJ = $(SERVERSRC:%.c=%.o)
HEADERS = $(wildcard *.h)

%.o:%.c
	gcc -ggdb -c $^ -L. -lft
all: libft.a client server 
	./server
client: $(CLIENTOBJ) $(UOBJS) libft.a 
	gcc -ggdb $(CLIENTOBJ) $(UOBJS) -L. -lft -o client 
git:
	git add $(CLIENTSRC) $(SERVERSRC) $(USRCS) Makefile $(HEADERS) ./libft
server: $(SERVEROBJ) $(UOBJS) libft/libft.a 
	gcc -ggdb $(SERVEROBJ) $(UOBJS) -L. -lft -o server 
libft.a:
	make -C libft bonus
	mv libft/libft.a ./
clean:
	rm -f $(UOBJS) $(CLIENTOBJ) $(SERVEROBJ)
fclean: clean
	rm -f server client
re: fclean all
.PHONY: libft/libft.a libft