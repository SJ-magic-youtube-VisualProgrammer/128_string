/************************************************************
■string の使い方
	http://stlalv.la.coocan.jp/string.html
	
■C++ 関数やクラスを個別にusingする方法【using宣言、エイリアス宣言】
	https://marycore.jp/prog/cpp/using-std-explicitly/
************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>

using std::string;
using std::endl;

/************************************************************
************************************************************/
void print_string(string& str);

/******************************
******************************/
int main(){
	/********************
	********************/
	printf(">----------\n");
	char ch_Name[] = "Nobu\0Saijo";
	for(int i = 0; i < 10; i++){
		if(ch_Name[i] == '\0'){
			printf("[%d] zero\n", i);
		}else{
			printf("[%d] %c\n", i, ch_Name[i]);
		}
	}
	printf("\n%s : %d\n", ch_Name, (int)strlen(ch_Name));
	
	/********************
	********************/
	string str_test = "Nobu\0Saijo";
	print_string(str_test);
	
	/********************
	********************/
	printf(">----------\n");
	std::vector<char> chars{ 'N', 'o', 'b', 'u', '\0', 'S', 'a', 'i', 'j' , 'o' };
	printf("vector.begin() = %c\n", *chars.begin());
	printf("vector.end() = %c\n", *(chars.end() - 1));
	string str_test2(chars.begin(), chars.end());
	print_string(str_test2);
	
	/********************
	********************/
	string str_message = "Nobu.Saijo";
	
	printf("%p\n", &str_message[0]);
	printf("%p\n", &(str_message.c_str()[0]));
	
	print_string(str_message);
	
	str_message[4] = '\0';
	print_string(str_message);
	
	return 0;
}

/******************************
******************************/
void print_string(string& str){
	printf(">----------\n");
	
	printf("len of str = %d\n", (int)str.length());
	std::cout << str << endl;
	printf("\n");
	
	printf("len of char[] = %d\n", (int)strlen(str.c_str()));
	printf("%s\n", str.c_str());
	printf("\n");
	
	for(int i = 0; i < str.length(); i++){
		printf("[%d] ", i);
		if(str.c_str()[i] == '\0'){
			printf("zero\n");
		}else{
			printf("%c\n", str.c_str()[i]);
		}
	}
}

