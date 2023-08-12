/* server.c - ��������ܺ��¼�ѭ��

-�¼����ʼ��

socket����
�ص���������
�¼��ַ�ѭ�� */

// ����libeventͷ�ļ�
#include <event2/event.h>
#include "api.c" 
#include "db.c"

// ����ͻ���HTTP����
void handleRequest(const char* request)
{
    // �����ͻ������󣬸���·��ѡ���Ӧ�Ĵ�����
    if (strncmp(request, "/user/register", strlen("/user/register")) == 0)
    {
        // �����û�ע������
        handleUserRegistration(request);
    }
    else if (strncmp(request, "/user/login", strlen("/user/login")) == 0)
    {
        // �����û���¼����
        handleUserLogin(request);
    }
    else if (strncmp(request, "/device/control", strlen("/device/control")) == 0)
    {
        // �����豸��������
        handleDeviceControl(request);
    }
    else if (strncmp(request, "/user/data/analyze", strlen("/user/data/analyze")) == 0)
    {
        // �����û����ݷ�������
        analyzeUserData(request);
    }
	else if (strncmp(request, "/weather", strlen("/weather")) == 0) {
        // �����ȡ������������
        handleWeatherRequest();
    }else if (strncmp(request, "/network/test", strlen("/network/test")) == 0)
    {
        // �����������Ӳ�������
        handleNetworkConnectionTest();
    }
    else
    {
        // ����·�����Ϸ������ش�����Ӧ
        handleException("Invalid request");
    }
}

void start_server() {
    // �¼����ʼ��
    struct event_base* base = event_base_new();

    // ����HTTP server
    struct evhttp* http_server = evhttp_new(base);
    evhttp_bind_socket(http_server, "0.0.0.0", 8080);

    // ������������
    evhttp_set_gencb(http_server, handle_request, NULL);

    // �¼��ַ�ѭ��
    event_base_dispatch(base);
}
