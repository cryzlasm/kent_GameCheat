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
string Ckent_request::request_ans(string requeststr)//返回字符串
{
	string content;
	if(!curl){//无效curl错误
		content = "err:curl is invalid";
		return(content);
	}

	code = curl_easy_setopt(curl, CURLOPT_URL, requeststr.c_str());//设置连接
	if(code != CURLE_OK){
		content = "err:";
		content += curl_easy_strerror(code);
		return(content);
	}
	
    code = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);//接受重定向
    if (code != CURLE_OK)
    {
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
    }

	code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);//设置回调函数
	if(code != CURLE_OK){
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
	}
	
    code = curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);//设置最后一个参数
    if (code != CURLE_OK)
    {
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
    }

	code = curl_easy_setopt(curl, CURLOPT_TIMEOUT, 8);//8秒超时
    if (code != CURLE_OK)
    {
		content = "err:";
		content += curl_easy_strerror(code);
        return(content);
    }

	code = curl_easy_perform(curl);//执行
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