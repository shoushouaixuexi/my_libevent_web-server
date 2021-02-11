#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <event2/bufferevent.h>
#include <event2/listener.h>
#include <event2/event.h>
#include "my_libevent_http.h"
//#include "libevent_http.h"

int main(int argc,char **argv){
    //命令行输入资源目录以及端口信息 注意顺序
    if(argc < 3)
    {
        printf("./event_http port path\n");
        return -1;
    }
    if(chdir(argv[2]) < 0) {
        printf("dir is not exists: %s\n", argv[2]);
        perror("chdir err:");
        return -1;
    }

    struct event_base *base;  //事件处理框架
    struct evconnlistener *listener; //监听套接字
    struct event *signal_event;  //信号事件（信号集成）
    //服务器地址信息结构体
    struct sockaddr_in sin;
    //创建事件处理框架
    base=event_base_new();
    if(!base){
        fprintf(stderr,"Could not init libevent!\n");
        return 1;
    }
    //初始化并绑定地址信息结构体
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(argv[1]));
    //创建监听的套接字，绑定、监听、接受连接请求
    listener=evconnlistener_new_bind(base,listener_cb,(void *)base,
    LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,-1,(struct sockaddr *)&sin,sizeof(sin));

    if(!listener){
        fprintf(stderr,"Could not create listener!\n");
        return 1;
    }
    //创建信号事件
    signal_event=evsignal_new(base,SIGINT,signal_cb,(void *)base);
    //创建信号事件不成功或在信号事件添加到事件处理框架失败
    if (!signal_event || event_add(signal_event, NULL)<0) 
    {
        fprintf(stderr, "Could not create/add a signal event!\n");
        return 1;
    }
    //事件主循环
    event_base_dispatch(base);

    //释放资源
    evconnlistener_free(listener);
    event_free(signal_event);
    event_base_free(base);
    printf("over! thank you");

    return 0;
}
