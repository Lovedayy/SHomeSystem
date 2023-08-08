/* server.c - ��������ܺ��¼�ѭ��

-�¼����ʼ��

socket����
�ص���������
�¼��ַ�ѭ�� */

// ����libeventͷ�ļ�
#include <event2/event.h>

void handle_request(struct evhttp_request* req, void* arg) {
    // ��ȡ����·��������·�ɱ�ѡ������
    // ִ�д���������ȡ��Ӧ����
    // ������Ӧ���ݸ��ͻ���
}

void start_server() {
    // �¼����ʼ��
    struct event_base* base = event_base_new();

    // ����HTTP server
    struct evhttp* http_server = evhttp_new(base);
    evhttp_bind_socket(http_server, "0.0.0.0", 8000);

    // ������������
    evhttp_set_gencb(http_server, handle_request, NULL);

    // �¼��ַ�ѭ��
    event_base_dispatch(base);
}
