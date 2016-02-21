// song.c ��Զ��

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("��Զ��", ({ "song yuanqiao", "song" }));
	set("nickname", "�䵱����");
	set("long", 
		"������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
		"����һ���ɸɾ����Ļ�ɫ���ۡ�\n"
		"���������ʮ�������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
	set("gender", "����");
	set("age", 61);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 400000);
	set("score", 70000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 80);
	set_skill("dodge", 85);
	set_skill("tiyunzong", 60);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
//	set_skill("taiji-jian", 60);
	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
//	map_skill("parry", "taiji-jian");
//	map_skill("sword", "taiji-jian");

	create_family("�䵱��", 2, "����");

	set("inquiry", ([
		"�ؼ�" : (: ask_me :),
	]));

	set("book_count", 1);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.zhen" :),
		(: exert_function, "recover" :),
	}) );

	setup();
//	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0) {
		command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ�ƶ�����������ˡ�");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
	add("book_count", -1);
	ob = new(__DIR__"force_book");
	ob->move(this_player());
	return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}