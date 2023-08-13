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
    //else if (strncmp(request, "/user/data/analyze", strlen("/user/data/analyze")) == 0)
    //{
    //    // �����û����ݷ�������
    //    analyzeUserData(request);
    //}
	else if (strncmp(request, "/weather", strlen("/weather")) == 0) {
        // �����ȡ������������
        handleWeatherRequest();
    }
	else if (strncmp(request, "/network/test", strlen("/network/test")) == 0)
    {
        // �����������Ӳ�������
        handleNetworkConnectionTest();
    }
	else if (strncmp(request, "/data/updataAirData", strlen("/data/updataAirData")) == 0)
    {
        // �������ݿ��� �յ� �豸����Ϣ
        updateAirDeviceStatus(request);
    }
	else if (strncmp(request, "/data/updataLightData", strlen("/data/updataLightData")) == 0)
    {
        // �������ݿ��� �� �豸����Ϣ
        updateLightDeviceStatus(request);
    }
	else if (strncmp(request, "/data/updataHumidityData", strlen("/data/updataHumidityData")) == 0)
    {
        // �������ݿ��� ��ʪ�� �豸����Ϣ
        updateHumidityDeviceStatus(request);
    }
	else if (strncmp(request, "/data/time", strlen("/data/time")) == 0)
    {
        // �����豸 �� ʹ��ʱ����������
        analyzeDataTime(request);
    }
	else if (strncmp(request, "/data/airTotalPower", strlen("/data/airtotalPower")) == 0)
    {
        // ���� �յ� �豸 �� �ܺĵ��������
        analyzeDataAirTotalPower(request);
    }
	else if (strncmp(request, "/data/lightTotalPower", strlen("/data/lighttotalPower")) == 0)
    {
        // ���� �� �豸 �� �ܺĵ��������
        analyzeDataLightTotalPower(request);
    }
	else if (strncmp(request, "/data/humidityTotalPower", strlen("/data/humiditytotalPower")) == 0)
    {
        // ���� ��ʪ�� �豸 �� �ܺĵ��������
        analyzeDataHumidityTotalPower(request);
    }
	//else if (strncmp(request, "/data/averagePower", strlen("/data/averagePower")) == 0)
    //{
        // �����豸 ÿСʱ �ĵ��������
    //    analyzeDataAveragePower(request);
    //}
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
