#makefile 

target = my_http_server
$(target):my_libevent_http.c main.c
	gcc -o $@ $^ -g -levent

.PHONY:clean
clean:
	-rm -f $(target)
