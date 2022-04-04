USRCS = bitwise_operations.c conversion_utils.c
UOBJS = $(USRCS:%.c=%.o)
CLIENTSRC = client.c
CLIENTOBJ = $(CLIENTSRC:%.c=%.o)
SERVERSRC = server.c
SERVEROBJ = $(SERVERSRC:%.c=%.o)

%.o:%.c
	gcc -ggdb -fsanitize=address -c $^ -L. -lft
client: $(CLIENTOBJ) $(UOBJS)
	gcc -ggdb -fsanitize=address $(CLIENTOBJ) $(UOBJS) -L. -lft -o client 
server: $(SERVEROBJ) $(UOBJS) 
	gcc -ggdb -fsanitize=address $(SERVEROBJ) $(UOBJS) -L. -lft -o server 
all: client server
	# ./server
clean:
	rm -f $(UOBJS) $(CLIENTOBJ) $(SERVEROBJ)
fclean: clean
	rm -f server client
re: fclean all
