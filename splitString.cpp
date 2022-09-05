/************************************************************
■string の使い方
	http://stlalv.la.coocan.jp/string.html
	
■C++ 文字列クラス std::string 入門
	http://vivi.dyndns.org/tech/cpp/string.html
	
	contents
		某氏からコメントを頂いた： 末尾に \0 が無い実装も仕様上はありだそうである。

■std::string の途中に null 文字が含まれている場合の処理
	https://secret-garden.hatenablog.com/entry/2016/04/14/004729
	
■C++ 関数やクラスを個別にusingする方法【using宣言、エイリアス宣言】
	https://marycore.jp/prog/cpp/using-std-explicitly/
************************************************************/
#include <stdio.h>
#include <iostream>

using std::string;
using std::endl;

/************************************************************
************************************************************/
enum{
	MAX_UDP_MSGS = 5, // separatorでsplitした結果の数
};

int SplitString(string src, char separater, string *dst, int MaxMessages);

/************************************************************
************************************************************/

/******************************
******************************/
int main(){
	string str_Message = "Button|9|Saijo|Nobuhiro|Michael|Jackson";
	
	// string UdpMsgs[MAX_UDP_MSGS] = {"\0"};
	string UdpMsgs[MAX_UDP_MSGS]; // 特に初期化は不要のようだが、一応Loopで初期化するのがいいだろう。
	
	for(int i = 0; i < MAX_UDP_MSGS; i++){
		UdpMsgs[i] = ""; // 初期化
	}
	/********************
	********************/
	int Num_dst = SplitString(str_Message, '|', UdpMsgs, MAX_UDP_MSGS);
	printf("> Num split messages : %d\n", Num_dst);
	
	for(int i = 0; i < Num_dst; i++){
		printf("[%d] = %s\n", i, UdpMsgs[i].c_str());
	}
	printf("\n");
	
	/********************
	********************/
	printf("> check by string\n");
	string str_cmp = "Button";
	// str_cmp += '\0';
	// if(UdpMsgs[0] == "Button"){
	if(UdpMsgs[0] == "Button\0"){
	// if(UdpMsgs[0] == string("Button\0")){
	// if(UdpMsgs[0] == str_cmp){
		int KeyId = atoi(UdpMsgs[1].c_str()); // 一応、数字 取り出す例
		printf("Pressed = %d\n", KeyId);
	}else{
		printf("not match\n");
		printf("%d\n", UdpMsgs[0].length());
		for(int i = 0; i < UdpMsgs[0].length(); i++){
			if(UdpMsgs[0][i] == '\0')	printf("[%d] : zero\n", i);
			else						printf("[%d] : %c\n", i, UdpMsgs[0][i]);
		}
	}
	
	printf("> check by char[]\n");
	if(strcmp(UdpMsgs[0].c_str(), "Button") == 0){
		int KeyId = atoi(UdpMsgs[1].c_str()); // 一応、数字 取り出す例
		printf("Pressed = %d\n", KeyId);
	}else{
		printf("not match\n");
	}
	
	fflush(stdout);
	
	return 0;
}


/******************************
description
	簡単のため、separaterは、一文字のみの対応となります。
	ofSplitString()より不便ですが、上手く使いこなしてください。
	
return
	Num of splitted messages.
	
	実際は、"separatorの数 + 1". 
	separator間、或いは最後のseparator後にmessageが入ってないことも考えられるが、この時は、「空のmessageが入っていた」とcountすることとする。
******************************/
int SplitString(string src, char separater, string *dst, int MaxMessages){
	/********************
	********************/
	for(int i = 0; i < MaxMessages; i++){
		dst[i] = ""; // 初期化
	}
	
	/********************
	********************/
	int index = 0;
	int src_length = (int)src.length();
	if(src_length <= 0) return 0;
	
	/********************
	********************/
	for (int i = 0; i < src_length; i++) {
		char tmp = src[i];
		if ( tmp == separater ) {
			dst[index] += '\0'; // 気を効かしたつもりで、これをやるとNG.
			
			index++;
			if(MaxMessages <= index) return MaxMessages; // range over. maxまで格納してreturn.
		}else{
			dst[index] += tmp;
		}
	}
	dst[index] += '\0'; // 気を効かしたつもりで、これをやるとNG.
	
	/********************
	********************/
	return index + 1;
}
