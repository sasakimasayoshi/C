//214010 ���X�ؐ��`

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define BANME 100000000
#define TABLE_BYTES 70000000
//����͗p�ӂ��鐔�̕\�̑傫���͌��ߑł��ɂ��܂���������Ă�������!

// 1���ڂ̑f�������߂���۸���
int main() {
//���Ԍv��

clock_t start, finish;
start = clock();

//���̕\��2,3,5�̔{�������炩���ߏ����30������8bit�Ɉ��k�
//�׸ނ������Ă����Ԃ�f���Ƃ���
const int table_bytes = TABLE_BYTES;//���̕\����؏�̑傫��
const int table_capacity = table_bytes * 30;//���̕\�Ɏ��e�\�Ȑ�
const int cycle[8] = {1, 7, 11, 13, 17, 19, 23, 29};//�ޯĈʒu����2,3,5�̔{���ȊO�̐��ɕϊ�
const unsigned char hot[30] = {
0, 128, 0, 0, 0, 0, 0, 64, 0, 0,
0, 32, 0, 16, 0, 0, 0, 8, 0, 4,
0, 0, 0, 2, 0, 0, 0, 0, 0, 1
};//��L�̋t�ϊ��30�̏�]���瓖�Y�ޯĂ̈ʒu�������׸ނ�������char���擾����
unsigned char * table;//���̕\���߲��
if ((table = (unsigned char *)malloc(table_bytes * sizeof(char))) == NULL) {
printf("��؂��m�ۂł��܂���ł����\n");
exit(0);
}

unsigned char *p = table;
*p = 0x7f;//�ŏ���30��[0,1,1,1,1,1,1,1]
p++;
int h;
for (h = 1; h < table_bytes; h++) {
*p = 0xff;
p++;
}

int i;//��ۯ����񂷂Ƃ��Ɏg�p
int i_upto = (sqrt(table_capacity) / 30) + 1;//���e�\�ȍő吔�̕������܂Œ��ׂ�̂Ť��ۯ����͂���30����1
int j;//bit���񂷂Ƃ��Ɏg�p
int c;//cycleؽē�����
int n;
int jc_fact;//cycle[j]��cycle[c]�̐�
int f_block;//�׸ނ�܂�Ƃ�����ۯ��ԍ�
unsigned char f_hot;//�׸ނ�܂�Ƃ���ίĺ���
//8bit����ۯ����Ƃɉ񂵂Ă���
//�����7���画�肪�n�܂�̂Ŗ��Ȃ�
for (i = 0; i < i_upto; i++) {//i��ۯ���
p = table + i;//�߲�����ړ�
for (j = 0; j < 8; j++) {//��ۯ�����j�ޯĖ�
if (*p & (0x80 >> j)) {//�f�����׸ނ������c���Ă���Ȃ�
//�{��������
//cycle[c]��0?29�̂���2,3,5�̔{���łȂ���(1,7,11,13,17,19,23,29)�Ƃ���Ƥ
//n�̔{���̂���2,3,5�̔{���łȂ����̂� n * (30 * k + cycle[c]) = n * 30 * k + n * cycle[c] (k�͎��R��)�ƕ\���邩��
//�N�_��n*cycle[c]�Ƃ��Ĥn��ۯ����ƂɊY���ޯĂ�|����Ƃ�ec�ɂ��čs���΂悢�
//��������O�Ƃ���cycle[c]=1�̂Ƃ���k��0�łȂ�1����n�߂Ȃ���΂Ȃ�Ȃ��
//�������Ȃ��Ƃ�����̂͂߂�ǂ������̂ň�x�S���|���Ă��Ƃ���n��1�{���׸ނ����𗧂Ē����
//n = i * 30 + cycle[j]�Ȃ̂Ť���߂�{����
//n * cycle[c] = (i * 30 + cycle[j]) * cycle[c]
//�ƂȂ�
n = 30 * i + cycle[j];//�𓀂�������
for (c = 0; c < 8; c++) {//cycleؽĂ�c�Ԗ�
jc_fact = cycle[j] * cycle[c];//�v�Z�ʂ����炷���߂ɂ�����ƍH�v�
f_block = (i * cycle[c]) + (jc_fact / 30);//��ۯ��ʒu
f_hot = hot[(jc_fact % 30)];//�����bit�ʒu������������char
while (f_block < table_bytes) {
*(table + f_block) &= (~f_hot);//�׸ނ�܂�
f_block += n;
}
}
*p |= (0x80 >> j);//1�{�̂Ƃ��͑f���Ȃ̂ŕ����
}//�f���׸ނ������c���Ă���ꍇ�̏��������
}//bit���񂷏��������
}//��ۯ����񂷏��������

int cnt = 3;//�f��2,3,5�͂��łɔ����ς݂Ƃ��Ă���
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

finish = clock();//���Ԍv���I��

printf("%d�Ԗڂ̑f����%d�ł��\n", (BANME), n);
printf("���s����: %lf[s]\n",((double)(finish - start)/CLOCKS_PER_SEC));

}