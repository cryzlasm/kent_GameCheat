//�����ж����ڣ����ڳ�ʼ�����󶨴��ڲ���
#pragma once

#define NUM_ishome			pow(9 , 2)
#define NUM_isneartour		pow(18 , 2)
#define NUM_isneartour1		pow(38 , 2)
#define NUM_isnearenemy0	pow(800 , 2)
#define NUM_tour_stay1		pow(5 , 2)
#define NUM_tour_stay2		pow(10 , 2)
#define NUM_isdanger		pow(10 , 2)
enum d_kent_home
{
	kent_home_left,
	kent_home_right,
	kent_home_normal_up,
	kent_home_normal_down,
};
enum d_kent_stage
{
	Kent_waiting,
	Kent_matching,
	Kent_selceting,
	Kent_loading,
	Kent_ingame,
	kent_overing,
};
enum d_kent_windowstate//
{
	Kent_unavailable,
	Kent_login_waiting,
	Kent_login_inuse,
	Kent_login_unavailable,
	Kent_login_needresize,
	Kent_game_waiting,
	Kent_game_inuse,
	Kent_game_unavailable,
	Kent_connect_waiting,
	Kent_connect_inuse,
	Kent_connect_needresize,
};
enum d_isstart_state
{
	Kent_start_waiting,
	Kent_start_gotoselect,
	Kent_start_over,
	Kent_start_match,
	Kent_start_none,
};
enum d_isgameover_state
{
	gameover_win,
	gameover_lose,
	gameover15_win,
	gameover15_lose,
	gameover_none,
};
enum d_game_state{
	Kent_game_none,
	Kent_game_init,
	Kent_game_occupy,
	Kent_game_attack,
	Kent_game_die,
};
enum d_game_mouse_shape
{
	mouse_shape_unknow,
	mouse_shape_normal,
	mouse_shape_attack,
	mouse_shape_needoccupy,
	mouse_shape_occupied,
};
class kent_windows
{
public:
	//�ⲿ�������
#ifdef _kent_foreground_
	Cdm_basis *dm;
#elif defined _kent_background_new_
	CTSPlugInterFace *dm;
#elif defined _kent_background_
	Idmsoft *dm;
#endif
	Kent_log *Kent_log_instance;
	//windows���
	long Hwnd_login,Hwnd_game;
	long Hwnd_connect;
	//����ѡ��
	d_kent_windowstate iswindows;//��ǰ�ٿصĴ���״̬
	d_kent_stage kent_stage_now;//��ǰ״̬
	d_kent_stage kent_stage_last;//��һ��״̬

	//·������
	CString kent_gamepath;//��Ϸ·���Լ�����
public:
	kent_windows();
	~kent_windows();
	bool kent_windows_init(void);
	bool identity_windows(void);
	bool kent_getwindowstate(void);
	bool kent_bind_window(void);
	bool gamestage_ctrl(void);
	bool Kent_do_start(void);
	bool Kent_do_select(void);
	bool Kent_do_gameover(void);
	void collapse_detect();
	void reconnect_protect();
	void han_reconnect_protect();
private:
	bool isingame(void);
	bool isstart(void);
	bool isselect(void);
	bool isloading(void);
	bool isgameover(void);
	void restart_windows_init();
	void restart_whole_game();
	CString file_name(CString thefile);
	//���˯��
	//bool Kent_rnd_delay(int kent_time);
private:
	//�󶨲���ʧ�ܴ���
	int bind_fail_cnt;
	//����Ϊ��Ϸ״̬
	bool isingame_num;
	d_isstart_state isstart_num;
	bool isselect_num;
	bool isloading_num;
	d_isgameover_state isgameover_num;
	CTime script_time;//��ʱ
	CTime start_time;

	//��ʱ������ʱ
	CTime Kent_game_inuse_time;//��ʱ
	CTime Kent_login_inuse_time;//��ʱ
	CTime Kent_connect_inuse_time;//��ʱ

	bool m_IsSmallWindow;
/*************��Ϸ���***************/
public:
	long error_code;
	int win_num,lose_num;
	d_kent_home kent_home;
private:
	CPoint location,location_last;
	CPoint danger1,danger2;
	CPoint myhome_loc,armyhome_loc;
	vector<CPoint> addr_skill,tour1,tour2,tour_stay;
	int target,stay_which_tour;
	bool occupy;
	vector<CString> attack,add_order;
	vector<CString> mouse_shapes_store_normal,mouse_shapes_store_needoccupy,mouse_shapes_store_attack,mouse_shapes_store_occupied;
	bool kent_normal_started;//�ж��Ѿ���ʼ
	bool kent_distort_started;//�ж��Ѿ���ʼ
	vector<CPoint> kent_bat_blue,kent_bat_red,kent_hero_blue,kent_hero_red;
	CPoint nearest_anmy;
public:
	d_game_state game_state,game_state_last;
	bool do_first_add;
public:
	bool get_location();
	bool gettourloc(CPoint location);
	d_game_mouse_shape get_mouseshape();
	bool screen_lock(bool lock);
	bool isbuypanel();
	bool iscold(long i);
	bool isdanger();
	bool isinprocess();
	bool isdie();
	bool isinitial();
	bool ishealth();
	bool isneedadd();
	bool ismove();
	int nearesttour();
	bool isenemyexist();
	bool isneedback(int last_tour);
	bool isbeside_protect_tour();
	bool game_buy();
	bool game_add_skill();
	int kent_strtoi(CString data_in);
	bool iscanselect();
	bool kent_TerminateProcess(CString strProcessName);//�رս���
	void cipher_input(CString input_string);
	CPoint kent_search_str(int x1,int y1,int x2,int y2,CString search_str,CString para,double blur_rate,int correct_num);
	void game_go_forward();
	void game_go_backward();
	void game_go_home();
	bool is_near_myhome();
	vector<CPoint> get_batman_blue();
	vector<CPoint> get_heros_blue();//�Ѿ�
	vector<CPoint> get_batman_red();
	vector<CPoint> distort_get_batman_blue();
	vector<CPoint> distort_get_batman_red();
	int get_safe_dis(vector<CPoint> item);//��ȡ��ȫ����
	int distort_get_safe_dis(vector<CPoint> item);//��ȡ��ȫ����
	int colosseum_get_safe_dis(vector<CPoint> item);//��ȡ��ȫ����
	void game_do_lasthit();//����

	CPoint get_nearest_anmy();
	CPoint distort_get_nearest_anmy();//Ť������
	void game_normal_attack();
	void colosseum_normal_attack();
	bool game_is_tour_exist();
	bool game_is_need_assist(CPoint nearest_anmy);
	bool colosseum_is_need_assist();
public:
	bool game_data_init();
	bool game_detect();
	bool game_init();
	bool game_tour_occupy();
	bool game_tour_standby();
	bool game_attack();
	bool game_die();
	//����ս��
	void game_do_normal();
	//Ť������
	void game_do_distort();
	//Ť������
	void game_do_colosseum();
public:
	void kent_get_now_ip_satge();
	bool isneedchangeqq();
};
