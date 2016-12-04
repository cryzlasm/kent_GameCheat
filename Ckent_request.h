#pragma once
class Ckent_request
{
public:
	Ckent_request(void);
	~Ckent_request(void);
private:
	CURL *curl;
	CURLcode code;
	long retcode;
public:
	string request_ans(string requeststr);//«Î«Û
};

