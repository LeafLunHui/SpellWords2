#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

//设置字体颜色
void setColor(unsigned short ForeColor, unsigned short BackGroundColor) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取当前窗口句柄

	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10); //设置颜色

}

//设置光标位置
void SetPos(int x, int y) {

	COORD pos;

	HANDLE handle;

	pos.X = x;

	pos.Y = y;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(handle, pos);

}

char c[50];

//随机字符错误检测模块
int ErrorCheck(char x[50]) {
	int i, right = 0;
	for (i = 0; i <= 49; i++) {
		if (c[i] == x[i]) {
			right++;
		} else {
			printf("你输入的第 %d 个字符 %c 出现错误\n", (i + 1), x[i]);
		}
	}
	return right;
}

//此处随机生成字符模块。
char * characterGenerator() {
	int i;
	for (i = 0; i <= 49; i++) {
		if (rand() % 3 == 1) {
			//小写字母生成
			c[i] = (rand() % 25) + 'a';
		} else if (rand() % 3 == 2) {
			//大写字母生成
			c[i] = (rand() % 25) + 'A';
		} else {
			//数字生成
			c[i] = (rand() % 9) + '0';
		}
	}
	return c;
}

//单词储存区域
char english1[][30] = {"setion", "base", "sheet", "company", "correspond", "author", "found", "accord", "paragraph", "given", "adult", "recent", "million", "effect", "energy", "professor", "career", "economic", "actually", "quality", "percent", "focus", "item", "essay", "economy"};
char chinese1[][100] = {"部门，部分", "以...为基础", "床单", "公司,陪伴", "相一致,符合", "作者", "创建创办", "一致，符合，协议，条约", "段落", "指定的", "成年的，成年人", "近来的，新近的", "一百万", "结果，效应", "能源，精力", "教授", "生涯，职业", "经济的，经济上的", "实际上，事实上", "质量，优质的，高质量的", "百分率,百分比", "集中", "一件商品，项目", "文章，短文", "经济,经济结构"};

char english2[][30] = {"blank", "likely", "comprehension", "system", "statement", "researcher", "identify", "learning", "improve", "benefit", "self", "disease", "consumer", "design", "concern", "tend", "reduce", "memory", "textbook", "view", "process", "lack", "centre", "average", "power"};
char chinese2[][100] = {"空白的", "可能的(like的演变形式)", "理解力", "系统", "申明", "研究人员", "确认", "学习", "改进", "益处", "自我，个性", "病，疾病", "消费者,用户", "设计,构思;旨在，意欲，", "担心，忧虑。", "往往会，常常就;趋向，趋势", "减少，缩小", "记忆力", "课本，教材", "把...视为;以...看待;观点,看法", "处理;过程,进程", "缺乏,短缺", "中心", "平均的,普通的", "驱动，推动"};

char english3[][30] = {"mail", "device", "amount", "challenge", "growth", "translation", "tax", "pressure", "firm", "major", "type", "limit", "security", "employee", "affect", "global", "contain", "select", "digital", "position", "decade", "graduate", "rate", "data", "access"};
char chinese3[][100] = {"邮箱", "装置,设备", "数量，数额", "挑战，难题", "成长,增加", "翻译", "税款,税", "心理压力", "商行，公司", "主要的，主修", "类型", "限制，限定;限度", "保护措施,安全工作", "受雇员，雇员", "影响", "全球的,整体的", "包含，容纳", "选择,挑选", "数字的,数码的", "安装，安置", "十年", "毕业", "评估评价", "数据，资料", "进入,使用"};

char english4[][30] = {"department", "individual", "apply", "opportunity", "decline", "impact", "lower", "innovation", "death", "case", "academic", "professional", "effort", "involve", "damage", "derive", "demand", "current", "measure", "alcohol", "advance", "prove", "attack", "financial", "goal"};
char chinese4[][100] = {"(学校的)系,(医院的)科", "个人;单独的，个别的", "使用，应用;申请，请求", "机会，时机", "减少，下降，衰落，衰退", "有影响，有作用；巨大影响，巨大作用", "减少，降低；更低的", "创造，创新", "死亡，灭亡", "情况,侦查的案情,调查的案件", "学术的，学业的", "职业的,专业的", "努力，试图", "包含,需要,牵连，涉及", "损坏，破坏；损害，伤害", "起源于，来自;从...获得", "强烈要求,需求", "当前的，现在的", "估量，判定", "酒精，乙醇", "进步，发展", "证明，证实", "发作，侵袭", "财政的,金融的", "目标,目的"};

//随机字符区域
void RandSpell() {
	char a[50];
	while (1) {
		setColor(3, 0);
		time_t start, end;
		start = time(NULL);
		printf("正在生成50个字符...");
		sleep(1);
		printf("\n请输入:");
		setColor(12, 0);
		printf("%s", characterGenerator());
		setColor(3, 0);
		printf("\n");
		printf("请打字:");
		setColor(12, 0);
		scanf("%s", a);
		setColor(3, 0);
		int k;
		k = strlen(a);
		if (k == 50) {
			int time_a;
			end = time(NULL);
			time_a = difftime(end, start);
			double word = 0;
			word = (50.0 / time_a) * 60;
			printf("\n你的打字速度是 %lf 个每分\n", word);
		} else {
			memset(a, 0, sizeof(a));
			printf("输入格式错误，请重新输入:\n");
		}

		printf("你的正确个数是 %d ", ErrorCheck(a));
		int exit1;
		printf("\n如果你想继续进行随机字符拼写的话请输入1,退出的话请按别的数字键：");
		scanf("%d", &exit1);
		if (exit1 != 1) {
			break;
		}
	}
}

//英语单词拼写区域
void EnglishSpell() {
	while (1) {
		int Jump;
		setColor(6, 0);
		int sel;
		char * jianru;
		sel = rand() % 25;
		int Suiji;
		Suiji = rand() % 4;
		if (Suiji == 0) {
			jianru = (char *)malloc(strlen(english1[sel]));
			printf("请稍等，正在加载,可能稍有卡顿\n");
			do {
				sleep(1);
				printf("请输入");
				setColor(12, 0);
				printf("%s", chinese1[sel]);
				setColor(6, 0);
				printf("的英文:");
				setColor(12, 0);
				scanf("%s", jianru);
				setColor(6, 0);
				if (strcmp(jianru, english1[sel]) == 0) {
					setColor(2, 0);
					printf("\n正确!");
					setColor(6, 0);
					break;
				} else {
					setColor(4, 0);
					printf("错误!");
					setColor(6, 0);
					printf("\n请重新输入，如果需要知晓答案则输入1,否则输入其他值：");
					setColor(12, 0);
					scanf("%d", &Jump);
					setColor(6, 0);
					if (Jump == 1) {
						printf("该单词为: ");
						setColor(12, 0);
						printf("%s", english1[sel]);
						setColor(6, 0);
						break;
					}
				}
			} while (strcmp(jianru, english1[sel]) != 0);
			free(jianru);
			int escape;
			printf("\n如果需要继续拼写字母的话请输入1，否则输入其他数字:");
			setColor(12, 0);
			scanf("%d", &escape);
			setColor(6, 0);
			if (escape != 1) {
				break;
			}
		} else if (Suiji == 1) {
			jianru = (char *)malloc(strlen(english2[sel]));
			printf("请稍等，正在加载,可能稍有卡顿\n");
			do {
				sleep(1);
				printf("请输入");
				setColor(12, 0);
				printf("%s", chinese2[sel]);
				setColor(6, 0);
				printf("的英文:");
				setColor(12, 0);
				scanf("%s", jianru);
				setColor(6, 0);
				if (strcmp(jianru, english2[sel]) == 0) {
					setColor(2, 0);
					printf("\n正确!");
					setColor(6, 0);
					break;
				} else {
					setColor(4, 0);
					printf("错误!");
					setColor(6, 0);
					printf("\n请重新输入，如果需要知晓答案则输入1,否则输入其他值：");
					setColor(12, 0);
					scanf("%d", &Jump);
					setColor(6, 0);
					if (Jump == 1) {
						printf("该单词为: ");
						setColor(12, 0);
						printf("%s", english2[sel]);
						setColor(6, 0);
						break;
					}
				}
			} while (strcmp(jianru, english2[sel]) != 0);
			free(jianru);
			int escape;
			printf("\n如果需要继续拼写字母的话请输入1，否则输入其他数字:");
			setColor(12, 0);
			scanf("%d", &escape);
			setColor(6, 0);
			if (escape != 1) {
				break;
			}
		} else if (Suiji == 2 ) {
			jianru = (char *)malloc(strlen(english3[sel]));
			printf("请稍等，正在加载,可能稍有卡顿\n");
			do {
				sleep(1);
				printf("请输入");
				setColor(12, 0);
				printf("%s", chinese3[sel]);
				setColor(6, 0);
				printf("的英文:");
				setColor(12, 0);
				scanf("%s", jianru);
				setColor(6, 0);
				if (strcmp(jianru, english3[sel]) == 0) {
					setColor(2, 0);
					printf("\n正确!");
					setColor(6, 0);
					break;
				} else {
					setColor(4, 0);
					printf("错误!");
					setColor(6, 0);
					printf("\n请重新输入，如果需要知晓答案则输入1,否则输入其他值：");
					setColor(12, 0);
					scanf("%d", &Jump);
					setColor(6, 0);
					if (Jump == 1) {
						printf("该单词为: ");
						setColor(12, 0);
						printf("%s", english3[sel]);
						setColor(6, 0);
						break;
					}
				}
			} while (strcmp(jianru, english3[sel]) != 0);
			free(jianru);
			int escape;
			printf("\n如果需要继续拼写字母的话请输入1，否则输入其他数字:");
			setColor(12, 0);
			scanf("%d", &escape);
			setColor(6, 0);
			if (escape != 1) {
				break;
			}
		} else if (Suiji == 3) {
			jianru = (char *)malloc(strlen(english4[sel]));
			printf("请稍等，正在加载,可能稍有卡顿\n");
			do {
				sleep(1);
				printf("请输入");
				setColor(12, 0);
				printf("%s", chinese4[sel]);
				setColor(6, 0);
				printf("的英文:");
				setColor(12, 0);
				scanf("%s", jianru);
				setColor(6, 0);
				if (strcmp(jianru, english4[sel]) == 0) {
					setColor(2, 0);
					printf("\n正确!");
					setColor(6, 0);
					break;
				} else {
					setColor(4, 0);
					printf("错误!");
					setColor(6, 0);
					printf("\n请重新输入，如果需要知晓答案则输入1,否则输入其他值：");
					setColor(12, 0);
					scanf("%d", &Jump);
					setColor(6, 0);
					if (Jump == 1) {
						printf("该单词为: ");
						setColor(12, 0);
						printf("%s", english4[sel]);
						setColor(6, 0);
						break;
					}
				}
			} while (strcmp(jianru, english4[sel]) != 0);
			free(jianru);
			int escape;
			printf("\n如果需要继续拼写字母的话请输入1，否则输入其他数字:");
			setColor(12, 0);
			scanf("%d", &escape);
			setColor(6, 0);
			if (escape != 1) {
				printf("\n下次再见!");
				break;
			}
		}
	}
}

//单词学习区域
void EnglishLook() {
	setColor(8, 0);
	int lookWhere, lookWhich, Jump;
	printf("\n----正在开启单词学习模式----");
	sleep(1);
	printf("\n请按下除了ESC之外的任意键以开始学习");
	while (_getch() != 27) {
		lookWhere = rand() % 4;
		lookWhich = rand() % 25;
		if (lookWhere == 0) {
			printf("\n请问是否认识单词:" );
			setColor(6, 0);
			printf("%s", english1[lookWhich]);
			setColor(8, 0);
			printf("\n认识请按1,不认识请输入其他数字键:");
			setColor(12, 0);
			scanf("%d", &Jump);
			setColor(8, 0);
			if (Jump != 1) {
				printf("\n该单词的意思为:");
				setColor(12,0);
				printf("%s",chinese1[lookWhich]);
				setColor(8,0);
			}
		} else if (lookWhere == 1) {
			printf("\n请问是否认识单词:" );
			setColor(6, 0);
			printf("%s", english2[lookWhich]);
			setColor(8, 0);
			printf("\n认识请按1,不认识请输入其他数字键:");
			setColor(12, 0);
			scanf("%d", &Jump);
			setColor(8, 0);
			if (Jump != 1) {
				printf("\n该单词的意思为:");
				setColor(12,0);
				printf("%s",chinese2[lookWhich]);
				setColor(8,0);
			}
		} else if (lookWhere == 2) {
			printf("\n请问是否认识单词:" );
			setColor(6, 0);
			printf("%s", english3[lookWhich]);
			setColor(8, 0);
			printf("\n认识请按1,不认识请输入其他数字键:");
			setColor(12, 0);
			scanf("%d", &Jump);
			setColor(8, 0);
			if (Jump != 1) {
				printf("\n该单词的意思为:");
				setColor(12,0);
				printf("%s",chinese3[lookWhich]);
				setColor(8,0);
			}
		} else if (lookWhere == 3) {
			printf("\n请问是否认识单词:" );
			setColor(6, 0);
			printf("%s", english4[lookWhich]);
			setColor(8, 0);
			printf("\n认识请按1,不认识请输入其他数字键:");
			setColor(12, 0);
			scanf("%d", &Jump);
			setColor(8, 0);
			if (Jump != 1) {
				printf("\n该单词的意思为:");
				setColor(12,0);
				printf("%s",chinese4[lookWhich]);
				setColor(8,0);
			}
		}
		printf("\n如果需要继续学习下去的话请按出ESC的任意键");
	}
}

//主程序
int main() {
	system("title 打字+单词拼写+认知系统-(V-0.3)");
	system("color 8b");
	int Select = 0;
	srand((unsigned)time(NULL));
	int ErrorCheck(char x[50]);
	//输入模块
	printf("-----------------正在加载打字&单词拼写&认知系统-(V-0.3)----------------\n");
	system("color 0b");
	sleep(1);
	printf("如果你想进入随机字符拼写请输入1\n进入单词拼写输入2\n(目前单词库含量有100个四级英语单词)\n如果想进入单词学习请输入3\n退出请输入其他任意数字:");
	setColor(12, 0);
	scanf("%d", &Select);
	if (Select == 1) {
		RandSpell();
	} else if (Select == 2) {
		EnglishSpell();
	} else if (Select == 3) {
		EnglishLook();
	}
	printf("\n----------------------程序结束------------------------\n");
	system("pause");
	return 0;
}
