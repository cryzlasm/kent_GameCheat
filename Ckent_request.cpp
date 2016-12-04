#include "stdafx.h"
#include "Ckent_request.h"
#include "curl\curl.h"


long writer(void *data, int size, int nmemb, string &content);


Ckent_request::Ckent_request(void)
{
	curl = curl_easy_init();
}
Ckent_request::~Ckent_request(void)
{
	if(curl){
		curl_easy_cleanup(curl);
	}
}
string Ckent_request::request_ans(string requeststr)//�����ַ���
{
	string content;
	if(!curl){//��Чcurl����
		content = "err:curl is invalid";
		return(content);
	}

	code = curl_easy_setopt(curl, CURLOPT_URL, requeststr.c_str());//��������
	if(code != CURLE_OK){
		content = "err:";
		content += curl_easy_strerror(code);
		return(content);
	}
	
    code = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);//�����ض���
    if (code != CURLE_OK)
    {
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
    }

	code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);//���ûص�����
	if(code != CURLE_OK){
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
	}
	
    code = curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);//�������һ������
    if (code != CURLE_OK)
    {
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
    }

	code = curl_easy_setopt(curl, CURLOPT_TIMEOUT, 8);//8�볬ʱ
    if (code != CURLE_OK)
    {
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
    }

	code = curl_easy_perform(curl);//ִ��
	if(code != CURLE_OK){
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
	}
	
    code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE , &retcode);
	if(code != CURLE_OK || retcode != 200){
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
	}

	return content;
}
long writer(void *data, int size, int nmemb, string &content)
{
    long sizes = size * nmemb;
    string temp((char*)data,sizes);
    content += temp;
    return sizes;
}