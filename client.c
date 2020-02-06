//客户端主程序 by tu98tu
#include "comm.h"

int main()
{
    int msgid = getMsgQueue();

    char buf[1024] = {0};
    while(1)
    {
        printf("Please Enter# ");
        fflush(stdout);
        
		//注示：读取 by lijinting
        ssize_t s = read(0, buf, sizeof(buf));
        if(s > 0)
        {
            buf[s-1]=0;
            sendMsgQueue(msgid, CLIENT_TYPE, buf);
            if(strcasecmp("quit", buf) == 0)
                break;
            printf("send done, wait recv...\n");
        }

        recvMsgQueue(msgid, SERVER_TYPE, buf);
        printf("server# %s\n", buf);
    }
    return 0;
}