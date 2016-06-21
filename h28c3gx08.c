//214010 佐々木正義

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define BANME 100000000
#define TABLE_BYTES 70000000
//今回は用意する数の表の大きさは決め打ちにしました｡許してください!

// 1億個目の素数を求めるﾌﾟﾛｸﾞﾗﾑ
int main() {
//時間計測

clock_t start, finish;
start = clock();

//数の表は2,3,5の倍数をあらかじめ消し､30周期で8bitに圧縮｡
//ﾌﾗｸﾞが立っている状態を素数とする｡
const int table_bytes = TABLE_BYTES;//数の表のﾒﾓﾘ上の大きさ
const int table_capacity = table_bytes * 30;//数の表に収容可能な数
const int cycle[8] = {1, 7, 11, 13, 17, 19, 23, 29};//ﾋﾞｯﾄ位置から2,3,5の倍数以外の数に変換
const unsigned char hot[30] = {
0, 128, 0, 0, 0, 0, 0, 64, 0, 0,
0, 32, 0, 16, 0, 0, 0, 8, 0, 4,
0, 0, 0, 2, 0, 0, 0, 0, 0, 1
};//上記の逆変換｡30の剰余から当該ﾋﾞｯﾄの位置だけのﾌﾗｸﾞが立ったcharを取得する
unsigned char * table;//数の表のﾎﾟｲﾝﾀ
if ((table = (unsigned char *)malloc(table_bytes * sizeof(char))) == NULL) {
printf("ﾒﾓﾘを確保できませんでした｡\n");
exit(0);
}

unsigned char *p = table;
*p = 0x7f;//最初の30個は[0,1,1,1,1,1,1,1]
p++;
int h;
for (h = 1; h < table_bytes; h++) {
*p = 0xff;
p++;
}

int i;//ﾌﾞﾛｯｸを回すときに使用
int i_upto = (sqrt(table_capacity) / 30) + 1;//収容可能な最大数の平方根まで調べるので､ﾌﾞﾛｯｸ数はその30分の1
int j;//bitを回すときに使用
int c;//cycleﾘｽﾄ内を回す
int n;
int jc_fact;//cycle[j]とcycle[c]の積
int f_block;//ﾌﾗｸﾞを折るときのﾌﾞﾛｯｸ番号
unsigned char f_hot;//ﾌﾗｸﾞを折るときのﾎｯﾄｺｰﾄﾞ
//8bitのﾌﾞﾛｯｸごとに回していく
//初回も7から判定が始まるので問題ない
for (i = 0; i < i_upto; i++) {//iﾌﾞﾛｯｸ目
p = table + i;//ﾎﾟｲﾝﾀを移動
for (j = 0; j < 8; j++) {//ﾌﾞﾛｯｸ中のjﾋﾞｯﾄ目
if (*p & (0x80 >> j)) {//素数のﾌﾗｸﾞが生き残っているなら
//倍数を消す
//cycle[c]を0?29のうち2,3,5の倍数でない数(1,7,11,13,17,19,23,29)とすると､
//nの倍数のうち2,3,5の倍数でないものは n * (30 * k + cycle[c]) = n * 30 * k + n * cycle[c] (kは自然数)と表せるから､
//起点をn*cycle[c]として､nﾌﾞﾛｯｸごとに該当ﾋﾞｯﾄを倒す作業を､各cについて行えばよい｡
//ただし例外としてcycle[c]=1のときはkは0でなく1から始めなければならない｡
//が､そんなことをするのはめんどくさいので一度全部倒してあとからnの1倍のﾌﾗｸﾞだけを立て直す｡
//n = i * 30 + cycle[j]なので､求める倍数は
//n * cycle[c] = (i * 30 + cycle[j]) * cycle[c]
//となる｡
n = 30 * i + cycle[j];//解凍した結果
for (c = 0; c < 8; c++) {//cycleﾘｽﾄのc番目
jc_fact = cycle[j] * cycle[c];//計算量を減らすためにちょっと工夫｡
f_block = (i * cycle[c]) + (jc_fact / 30);//ﾌﾞﾛｯｸ位置
f_hot = hot[(jc_fact % 30)];//特定のbit位置だけが立ったchar
while (f_block < table_bytes) {
*(table + f_block) &= (~f_hot);//ﾌﾗｸﾞを折る｡
f_block += n;
}
}
*p |= (0x80 >> j);//1倍のときは素数なので復活｡
}//素数ﾌﾗｸﾞが生き残っている場合の処理おわり
}//bitを回す処理おわり
}//ﾌﾞﾛｯｸを回す処理おわり

int cnt = 3;//素数2,3,5はすでに発見済みとしている
unsigned char bits;
p = table;
for (i = 0; ; i++) {
bits = *p;
bits = (bits & 0x55) + ((bits >> 1) & 0x55);
bits = (bits & 0x33) + ((bits >> 2) & 0x33);
bits = (bits + (bits >> 4)) & 0x0f;
cnt += bits;
if (cnt >= BANME) {
cnt -= bits;
break;
}
p++;
}
for (j = 0; j < 8; j++) {
if (*p & (0x80 >> j)) {
cnt++;
if (cnt == BANME) {
break;
}
}
}
n = i * 30 + cycle[j];

finish = clock();//時間計測終了

printf("%d番目の素数は%dです｡\n", (BANME), n);
printf("実行時間: %lf[s]\n",((double)(finish - start)/CLOCKS_PER_SEC));

}