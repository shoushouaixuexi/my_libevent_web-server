#epoll #web
基于epoll的web服务器
两个文件，分别为内网和外网测试，内网较简单，方式如下：
内网测试 gcc *.c编译 ./a.out port Documentsfile 运行,如./a.out 8989 /home/jay/Documents
使用浏览器访问127.0.0.1:8989/

#libevent
基于libevent的web服务器，简单的实现了对浏览器的资源请求处理以及html页面的发送等过程，使用方法清阅读
文档：libevent
链接：http://note.youdao.com/noteshare?id=447e46c4724db5ce6407993490655bdd  查看一些我的笔记以及安装说明
