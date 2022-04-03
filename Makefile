USRCS = bitwise_operations.c conversion_utils.c
UOBJS = $(USRCS:%.c=%.o)
CLIENTSRC = client.c
CLIENTOBJ = $(CLIENTSRC:%.c=%.o)
SERVERSRC = server.c
SERVEROBJ = $(SERVERSRC:%.c=%.o)

%.o:%.c
	gcc -c $^ 
client: $(CLIENTOBJ) $(UOBJS)
	gcc $(CLIENTOBJ) $(UOBJS) libft.a -o client 
server: $(SERVEROBJ) $(UOBJS) 
	gcc $(SERVEROBJ) $(UOBJS) libft.a -o server 
all: client server
clean:
	rm -f $(UOBJS) $(CLIENTOBJ) $(SERVEROBJ)
fclean: clean
	rm -f server client
re: fclean all
