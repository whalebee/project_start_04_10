#include <stdio.h>
#include <string.h>
#include <stdlib.h>




#pragma region 仙瑛敗呪 10->2 痕発 蟹袴走人 交 main採歳
// start
#include "header.h"

void intToBin(int);

int main()
{
	// 廃越 鞠蟹食~?
	int input = 0, chk = 0;
	printf("2遭呪稽 痕発拝 10遭呪研 脊径馬室推 : ");

	while (chk != 1)
	{
		chk = scanf("%d", &input);
	}
	intToBin(input);



	return 0;
}





#pragma endregion


#pragma region getchar
// start
#include "header.h"



int main()
{
	// 獄遁淫恵 脊窒径 庚切

	char input = 0, input2 = 0, dummy = 0;

	printf("庚切研 脊径馬室推 : ");
	input = (char)getchar();	// getchar fn receives return as int type, auto-type transformed
	printf("%c", input);

	puts("");
	do {
		dummy = (char)getchar();
	} while (dummy != '\n');	// while for evade the enter

	input2 = (char)getchar();	// do u think get typing here? omg
	printf("%c", input2);


	return 0;
}




#pragma endregion


#pragma region 獄遁淫恵 脊窒径 庚切
// start
#include "header.h"

int main()
{
	// 獄遁淫恵 脊窒径 庚切

	char input = 0, input2 = 0, dummy = 0, input3 = 0, input4 = 0;

	printf("庚切研 脊径馬室推 : ");
	input = (char)getchar();	// getchar fn receives return as int type, auto-type transformed
	printf("getchar() : %c", input);
	puts("");

	// putchar
	printf("putchar() : %d", putchar((int)input)); // putchar澗 ASCII稽 鋼発背層陥

	puts("");
	/*
	do {
		dummy = (char)getchar();
	} while (dummy != '\n');	// while for evade the enter
	*/


	input2 = (char)getchar();	// do u think get typing here? omg
	printf("getchar() : %c", input2);
	puts("");


	input3 = (char)_getch(); // _getch fn is only!! print you did typing
	printf("_getch() : %c", input3);
	puts("");


	input4 = (char)_getche(); // who are u ?
	printf("_getche() : %c", input4);
	puts("");




	return 0;
}



#pragma endregion


#pragma region 獄遁淫恵 脊窒径 庚切伸 fgets
// start
#include "header.h"



int main()
{
	char input[10];
	int dummy = 0; // int稽 閤聖暗績

	// stdin : 妊層脊径獄遁 (閤焼神澗 員聖 走舛背爽澗 切軒拭 stdin戚 床昔 依)
	fgets(input, sizeof(input), stdin);
	printf("%s \n", input); // 9鯵税 衣引亜 蟹神惟 喫

	printf("獄遁拭 害焼赤澗 鎧遂ぞぞ : ");
	do {
		dummy = getchar(); // 獄遁拭 赤澗暗 亜閃人跡
		printf("%c ", dummy);
	} while (dummy != '\n');

	return 0;
}




#pragma endregion


#pragma region 獄遁淫恵 脊窒径 庚切伸 scanf
// start
#include "header.h"



int main()
{
	char input[10];
	int dummy = 0, chk = 0; // int稽 閤聖暗績

	chk = scanf("%[^\n]s", input);
	printf("%s \n", input);

	printf("獄遁拭 害焼赤澗 鎧遂ぞぞ : ");
	do {
		dummy = getchar(); // 獄遁拭 赤澗暗 亜閃人跡
		printf("%c ", dummy);
	} while (dummy != '\n');

	return 0;
}




#pragma endregion


#pragma region puts人 fputs
// start
#include "header.h"



int main()
{
	char input[10], dummy = 0;
	char chk = 0;

	// input拭 脊径
	chk = fgets(input, sizeof(input), stdin);

	puts(input); // 鯵楳(\n)戚 赤製
	fputs(input, stdout); // 鯵楳(\n)戚 蒸製 

	printf("%s \n", input);

	/*
	printf("希耕拭 害精 依精 : ");
	do {
		dummy = getchar();
		printf("%c ", dummy);
	} while (dummy != '\n');
	*/


	/* ぱ.ぱ 耕刃
	脊径
	getchar()		// 庚切莫 (庚切 廃 鯵)
	fgets()			// 庚切伸


	窒径
	puts()
	fputs()

	*/

	return 0;
}




#pragma endregion


#pragma region 敗呪 古鯵痕呪 掻拭辞税 敗舛引 背衣聖 是廃 敗呪級 (strcpy, strncpy 去)
// start
#include "header.h"



int main()
{
	char test[5];
	// test = "Hi"; // 戚暗 訊 照鞠澗走 持唖背坐 -> 壕伸戚虞辞
	// fn_string1拭 赤澗 str = "Hi"; 澗 訊 鞠壱 剰澗 訊 照鞠澗走


	char str[] = "Hello"; // 脊径廃 越切 呪 + 1 幻級嬢走走 ~
	printf("main size : %d \n", sizeof(str));
	printf("%p \n", str);
	fn_string(str);
	fn_string1(str);
	printf("main 敗呪 窒径 板 : %s \n", str);
	printf("%p \n", str);



	return 0;
}




#pragma endregion


#pragma region 庚切伸 搾嘘人 庚切伸拭辞 庚切伸 達奄
// start
#include "header.h"



int main()
{
	char str1[32] = "Hello, World!";
	char str2[32] = "Hello, C!";
	char str3[32] = "banana";


	// strstr 庚切伸拭辞 庚切伸達奄 -> 敗呪稽 皐
	char find_str[32] = "World";
	char* result = NULL;

	result = strstr(str1, find_str);
	if (result != NULL)
	{
		printf("%s 戚 舘嬢亜 赤革推 \n", result);
	}
	else
	{
		printf("達澗惟 蒸革遂");
	}


	fn_str1_cmp(str1, str2);

	puts(" ");

	fn_str1_ncmp(str1, str2);

	fn_strchr(str3);




	return 0;
}



#pragma endregion


#pragma region 庚切伸 姥歳 奄沙 鯵割
// start
#include "header.h"



int main()
{
	// 庚切伸 姥歳

	char str1[] = "Hello World Welcome C Programming";
	char* result = NULL;

	result = strtok(str1, " ");

	while (result != NULL)
	{
		printf("%s \n", result);
		result = strtok(NULL, " "); // 因拷企重 #生稽 馬壱 粛生檎 是税 庚切伸拭亀 #聖 隔嬢醤背.
	}

	printf("%s", str1); // 庚切伸 切端亜 郊餓嬢獄顕

	return 0;
}




#pragma endregion


#pragma region 庚切伸 搾嘘人 掩戚域至
// start
#include "header.h"



int main()
{
	// 庚切伸税 搾嘘人 掩戚 域至
	char str1[16] = "I'm 25years old";
	char str2[16] = { '\0', };

	char pattern[] = "0123456789";

	size_t sIndex = 0, sLength = 0;

	// strlen : 壕伸税 掩戚亜 焼艦虞 庚切伸税 掩戚
	printf("sizeof : %d, strlen : %d \n", sizeof(str1), strlen(str1));

	sIndex = strcspn(str1, pattern);
	// sIndex澗 strcspn : 庚切伸 str1引 pattern聖 搾嘘馬食 pattern拭 背雁馬澗 庚切亜 蟹尽聖 凶猿走税 呪研 鋼発
	// i'm 因拷猿走, 2猿走 神檎 4研 鋼発馬惟 喫

	// printf("%d \n", sIndex);

	if (sIndex > 0 && strlen(str1) != sIndex)
	{
		// str1 + sIndex研 馬檎 庚切伸 str1拭辞 25years old研 災君神惟 鞠壱
		// 災君紳 庚切伸引 pattern聖 搾嘘梅聖 凶
		// pattern 庚切伸拭 背雁馬澗 庚切亜 2鯵戚糠稽 sLength澗 2研 企脊馬惟 喫
		sLength = strspn(str1 + sIndex, pattern);
		if (sLength > 0)
		{
			// 庚切伸 str2拭陥亜 str1+sIndex -> 25years old税 雌殿税 庚切伸聖 sLength幻鏑(2幻鏑) 差紫
			strncpy(str2, str1 + sIndex, sLength);
			printf("蟹澗 %s詞脊艦陥. \n", str2);
		}

	}
	else
	{
		printf("達澗 鳶渡戚 蒸柔艦陥.");
	}

	return 0;
}




#pragma endregion


#pragma region atoi 敗呪
// start
#include "header.h"



int main()
{
	char str1[] = "10";
	// printf("%d \n", str1[0]);
	printf("%d \n", atoi(str1) * 5); // 10 * 5 = 50

	return 0;
}



#pragma endregion


#pragma region 庚切伸 森薦 1腰
// start
#include "header.h"



int main()
{
	// 1腰
	char season[10] = { '\0', };

	// end 刊牽檎 魁
	while (1)
	{
		printf("-------- 4域箭 掻 廃 域箭 識澱 (曽戟澗 end) : ");
		scanf("%s", season);

		if (strcmp(season, "砂") == 0)
		{
			printf("砂拭澗 鯵蟹軒 \n");
		}
		else if (strcmp(season, "食硯") == 0)
		{
			printf("食硯拭澗 舌耕 \n");
		}
		else if (strcmp(season, "亜聖") == 0)
		{
			printf("亜聖拭澗 坪什乞什 \n");
		}
		else if (strcmp(season, "移随") == 0)
		{
			printf("移随拭澗 古鉢 \n");
		}
		else if (strcmp(season, "end") == 0)
		{
			printf("end脊径生稽 奏戟 \n"); // 奏戟亜 更醤 奏戟亜せせせせ
			break;
		}
		else
		{
			printf("??? 陥獣 脊径 \n");
		}
	}



	return 0;
}




#pragma endregion


#pragma region 庚切伸 森薦 2腰 刃失
// start
#include <stdio.h>

int main()
{
	char last_name[10] = "\0";
	char first_name[10] = "\0";
	char full_name[20] = "\0";

	int chk_l = 0, chk_f = 0;


	printf("失聖 脊径馬室推. \n");
	chk_l = scanf("%s", last_name);

	printf("戚硯聖 脊径馬室推. \n");
	chk_f = scanf("%s", first_name);

	// 瓜戚 cpy嬢醤馬蟹?
	// cpy 澗 =, cat精 +, cmp澗 == 虞壱 左檎 吃 牛
	strcpy(full_name, last_name);

	// strcat(full_name, " "); -> 廃越稽 承暗檎 照 句酔澗惟 蟹精 牛

	strcat(full_name, first_name);


	printf("失誤 : %s", full_name);

	return 0;
}




#pragma endregion


//識持還戚 廃 暗櫛 搾汁馬奄 凶庚拭 魚稽 湿室獄穿精 旋走 省畏社 !!
#pragma region 庚切伸 森薦 3腰 ( 銚団凶庚拭 敗呪亀 差紫背身 )
// start
#include "header.h"

void test3(char str1[], char str2[]);

int main()
{
	char str1[10] = "Hello";
	char str2[10] = "Wolrd";

	test3(str1, str2);
	printf("%s %s \n", str1, str2);

	return 0;
}

void test3(char str1[], char str2[])
{
	char temp[10] = "\0";
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);

	// printf("%s %s \n", str1, str2);
}

#pragma endregion


#pragma region 庚切伸 森薦 1腰 湿室獄穿
// start
#include "header.h"



int main()
{
	char input[5] = { '\0', };
	char* season[2][4] = {
		{"砂", "食硯", "亜聖", "移随"},
		{"鯵蟹軒", "舌耕", "坪什乞什", "古鉢"}
	};


	int chk = 0;
	printf("域箭誤 脊径, end 脊径獣 曽戟");
	while (chk = scanf_s("%s", input, sizeof(input)), strcmp(input, "end") != 0)
	{
		int i = 0;
		for (i = 0; i < 4; i++)
		{
			if (strcmp(input, season[0][i]) == 0)
			{
				puts(season[1][i]);
				break;
			}
		}

		if (i >= 4)
		{
			puts("砂, 食硯, 亜聖, 移随 掻拭 脊径背");
		}
	}

	return 0;
}




#pragma endregion


#pragma region 庚切伸 森薦 2腰 湿室獄穿
// start
#include "header.h"



int main()
{
	char last_name[10] = "\0";
	char first_name[10] = "\0";
	char full_name[20] = "\0";

	puts("失引 戚硯聖 唖唖 脊径馬慧");

	gets_s(last_name, sizeof(last_name));
	gets_s(first_name, sizeof(first_name)); // first_name拭 紫戚綜幻鏑 閤焼神慧


	strcpy(full_name, last_name);
	strcat(full_name, first_name);

	printf("%s", full_name);

	return 0;
}



#pragma endregion


#pragma region 督析 脊窒径 石奄&床奄&背薦
// start
#include "header.h"



int main()
{
	//督析 神蚤 : fopen()
	FILE* p_file = fopen("test.txt", "at");

	char read[50];
	char haha[50];
	int chk = 0;

	if (NULL != p_file)
	{
		printf("督析 伸奄 失因 ! \n");

		// 督析 床奄
		// fputs("督析床奄", p_file);
		// fscanf(p_file, "%[^\n]s", read);
		// fprintf(p_file, "Hello");		// mode拭 魚虞 陥牽惟 潤像, at檎 戚嬢床壱 wt檎 気嬢床壱 ~
		chk = scanf("%s", haha);
		fprintf(p_file, haha);


		// 督析 石奄
		/*
		while (!feof(p_file)) // feof 敗呪澗 督析税 魁拭 亀含馬檎 0戚 焼観 葵聖 鋼発, enter研 鯵楳庚切稽 昔縦馬食 匝郊嘩
		{
			fgets(read, sizeof(read), p_file); // 因拷猿走 乞砧 石嬢身
			printf("%s", read);
		}
		*/

		// fscanf澗 匝郊嘩戚 蒸製 -> 益掘辞 [^\n] 隔嬢捜 -> 益隈希艦 戚雌背像
		/*
		while (EOF != fscanf(p_file, "%[^\n]s", &read))
		{
			printf("%s", read);
		}
		*/




		// 督析適稽綜 : fclose()
		fclose(p_file);
	}
	else
	{
		printf("ERR(%d) : %s \n", errno, strerror(errno));
	}

	return 0;
}




#pragma endregion


#pragma region 督析 脊窒径 石奄人 床奄税 是帖 戚疑 敗呪 ( 耕刃 )
// start
#include "header.h"



int main()
{
	FILE* p_file = fopen("test.txt", "rt"); // at稽 馬檎 戚雌馬惟 蟹人辞 rt 石奄 穿遂生稽 乞球研 郊嘩
	char read[50];

	if (NULL != p_file)
	{
		fgets(read, sizeof(read), p_file);
		printf("%s", read);

		fgets(read, sizeof(read), p_file);
		printf("%s", read);

		fseek(p_file, 5, SEEK_SET);	// SEEK_SET 固 坦製生稽 !
		fgets(read, sizeof(read), p_file);
		printf("%s", read);

	}
	else
	{
		printf("ERR(%d) : %s \n", errno, strerror(errno));
	}

	return 0;
}



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





