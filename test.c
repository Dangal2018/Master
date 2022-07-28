//#include "matrix.h"
//#include <stdlib.h>
//void main()
//{
//	REAL a[3 * 3] = { 1,2,3,6,5,5,8,7,2 };
//	REAL b[3 * 3] = { 1,2,3,6,5,4,3,2,1 };
//	MATRIX *A = NULL, *B = NULL, *C = NULL, *D = NULL, *E = NULL, *Z = NULL, *invA = NULL, *m = NULL;
//	ERROR_ID errorID = _ERROR_NO_ERROR;
//	REAL trace;
//	STACKS S;
//
//	init_stack(&S);
//
//	Z = creat_zero_matrix(3, 3, &errorID, &S);
//	print_matrix(Z, "Z");
//
//	E = creat_eye_matrix(3, &errorID, &S);
//	print_matrix(E, "E");
//
//	A = creat_matrix(3, 3, &errorID, &S);
//	A->p = a;
//	print_matrix(A, "A");
//
//	B = creat_matrix(3, 3, &errorID, &S);
//	B->p = b;
//	print_matrix(B, "B");
//
//	C = creat_matrix(3, 3, &errorID, &S);
//	D = creat_matrix(3, 3, &errorID, &S);
//	invA = creat_matrix(3, 3, &errorID, &S);
//
//	errorID = matrix_add(A, B, C);
//	errorID = matrix_subtraction(A, B, C);
//	errorID = matrix_multiplication(A, B, C);
//
//	errorID = matrix_transpose(A, D);
//	print_matrix(D, "D");
//
//	errorID = matrix_trace(A, &trace);
//
//	errorID = matrix_inverse(A, invA);
//	print_matrix(invA, "invA");
//
//	m = creat_multiple_matrices(3, 3, 2, &errorID, &S);
//	m[0].p = a;
//	m[1].p = b;
//
//	free_stack(&S);
//	system("pause");
//}
#pragma warning(disable:4996)
#include "matrix.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#ifndef _CLOCK_T_DEFINED  
typedef long clock_t;
#define _CLOCK_T_DEFINED  
#endif   

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

double start, end, cost;		//运行时间测试
int cnt = 0;
struct Point {
	double x;
	double y;
}p;
//CSV读写
char* remove_quoted(char *str)
{
	int length = strlen(str);
	char *result = malloc(length + 1);
	int index = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] != '\"') {
			result[index] = str[i];
			index++;
		}
	}
	result[index] = '\0';
	return result;
}

char* get_field(char *line, int num)
{
	char *tok;
	tok = strtok(line, ",");
	for (int i = 1; i != num; i++) {
		tok = strtok(NULL, ",");
	}
	char *result = remove_quoted(tok);
	return result;
}

void print_point_info(struct Point *p)
{
	//printf("%lf\t%lf\n", p->x,p->y);
}
//
int main() {
	REAL* y = (REAL *)malloc(sizeof(REAL)*2048);
	FILE *fp = fopen("jc.csv", "r");
	if (fp == NULL) {
		fprintf(stderr, "fopen() failed.\n");
		exit(EXIT_FAILURE);
	}

	char row[80];
	char *token;

	//fgets(row, 80, fp);
	//char *header_1 = get_field(strdup(row), 1);
	//char *header_2 = get_field(strdup(row), 2);
	//printf("%s\t%s", header_1, header_2);
	
	char *tmp;
	struct Point p;
	while (fgets(row, 80, fp) != NULL) {
		tmp = get_field(strdup(row), 1);
		p.x = atof(tmp);
		tmp = get_field(strdup(row), 2);
		p.y = atof(tmp);
		print_point_info(&p);
		y[cnt] = p.y;
		cnt++;

	}
	//printf("%d\n", cnt);
	fclose(fp);
	end = clock();
	cost = (end - start) / CLOCKS_PER_SEC;
	printf("get_csv :%.4lf(sec)\n", cost);

	REAL lambda = 100;
	///*REAL a[3 * 3] = { 1,3,4,2,1,2,1,2,3};
	//REAL b[3 * 2] = { 2,1,-1,-2,2,1 };*/
	REAL dssn = -2333333.0;
	MATRIX *A = NULL, *B = NULL, *C = NULL, *D = NULL, *E = NULL, *Z = NULL, *invA = NULL, *m = NULL;
	MATRIX *D1 = NULL, *D2_0 = NULL, *D3_0 = NULL, *D0_0 = NULL, *tmpD0_0 = NULL, *tmpZ = NULL, *D0_0T, *spZ,*WY, *Y,*valueAbstract, *expValues,*Z2, *res, *diagE;//*dssn;
	ERROR_ID errorID = _ERROR_NO_ERROR;
	//REAL trace;
	STACKS S;
	init_stack(&S);
	/*A = creat_matrix(3, 3, &errorID, &S);
	//A->p = a;
	//print_matrix(A, "A");
	//
	//B = creat_matrix(3, 2, &errorID, &S);
	//B->p = b;
	//print_matrix(B, "B");
	//invA = creat_matrix(3, 3, &errorID, &S);
	//errorID = matrix_inverse(A, invA);
	//print_matrix(invA, "invA");
	//errorID = solve_matrix_equation_by_lup_decomposition(A, B);
	//print_matrix(B, "B");
	//C = creat_matrix(3, 2, &errorID, &S);
	//errorID = matrix_multiplication(A, B, C);
	//print_matrix(C, "C");*/

	//INTEGER L = 10;
	////scanf("%d", &L);
	///*int L;
	//scanf("%d", &L);*/
	////REAL y[L * 1] = { 10,15,27,36,17,21,25,13,16,9 };
	//REAL* y = (REAL *)malloc(sizeof(REAL)*L);
	//for (int i = 0; i < cnt; i++) printf("%lf\n", y[i]);
	start = clock();
	REAL ysum = 0;
	REAL* eV = (REAL *)malloc(sizeof(REAL)*cnt);
	REAL* diage = (REAL *)malloc(sizeof(REAL)*cnt*cnt);
	for (int i = 0; i < cnt; i++)		for (int j = 0; j < cnt; j++)		diage[i*cnt + j] = 0;		//memset(diage,0,sizeof(diage));
	for (int i = 0; i < cnt; i++)		ysum += y[i];
	REAL maxcV2; 
	REAL* d1 = (REAL *)malloc(sizeof(REAL)*cnt*(cnt - 2));
	REAL* d2_0 = (REAL *)malloc(sizeof(REAL)*cnt*(cnt - 2));
	REAL* d3_0 = (REAL *)malloc(sizeof(REAL)*cnt*(cnt - 2));
	for (int i = 0; i < cnt; i++) {							//memset([d1,d2_0,d3_0],0,sizeof([d1,d2_0,d3_0]));
		for (int j = 0; j < cnt - 2; j++) {
			d1[i*(cnt - 2) + j] = 0;
			d2_0[i*(cnt - 2) + j] = 0;
			d3_0[i*(cnt - 2) + j] = 0;
		}
	}
	for (int i = 0; i < (cnt-2); i++) d1[i*(cnt-1)]		 =   1;
	for (int i = 0; i < (cnt-2); i++) d2_0[(cnt-1)*i+(cnt-2)]   =  -2;
	for (int i = 0; i < (cnt-2); i++) d3_0[(cnt-1)*i + 2*(cnt-2)]   =   1;

	D1 = creat_matrix(cnt, cnt-2, &errorID, &S);		
	D2_0 = creat_matrix(cnt, cnt - 2, &errorID, &S);
	D3_0 = creat_matrix(cnt, cnt - 2, &errorID, &S);
	D0_0 = creat_matrix(cnt, cnt - 2, &errorID, &S);
	tmpD0_0 = creat_matrix(cnt, cnt - 2, &errorID, &S);
	E = creat_eye_matrix(cnt, &errorID, &S);
	D0_0T = creat_matrix(cnt - 2, cnt, &errorID, &S);
	tmpZ = creat_matrix(cnt, cnt, &errorID, &S);
	spZ = creat_matrix(cnt, cnt, &errorID, &S);
	Y = creat_matrix(cnt, 1, &errorID, &S);
	WY = creat_matrix(cnt, 1, &errorID, &S);
	Z = creat_matrix(cnt, 1, &errorID, &S);
	valueAbstract = creat_matrix(cnt, 1, &errorID, &S);
	expValues = creat_matrix(cnt, 1, &errorID, &S);
	Z2 = creat_matrix(cnt, 1, &errorID, &S);
	res = creat_matrix(cnt, 1, &errorID, &S);
	diagE = creat_matrix(cnt, cnt, &errorID, &S);
	end = clock();
	cost = (end - start) / CLOCKS_PER_SEC;
	printf("alloc: %.4lf(sec)\n", cost);
	D1->p = d1;									//D1
	//print_matrix(D1, "D1");
	D2_0->p = d2_0;								//D2_0
	//print_matrix(D2_0, "D2_0");
	D3_0->p = d3_0;								//D3_0
	//print_matrix(D3_0, "D3_0");
	end = clock();
	cost = (end - start) / CLOCKS_PER_SEC;
	printf("setvalue: %.4lf(sec)\n", cost);
	errorID = matrix_add(D1, D2_0, tmpD0_0);	
	//print_matrix(tmpD0_0, "tmpD0_0");
	end = clock();
	cost = (end - start) / CLOCKS_PER_SEC;
	printf("add1: %.4lf(sec)\n", cost);
	errorID = matrix_add(tmpD0_0, D3_0, D0_0);	//D0_0 = D1+D2_0+D3_0
	//print_matrix(D0_0, "D0_0");
	//print_matrix(E, "E");
	end = clock();
	cost = (end - start) / CLOCKS_PER_SEC;
	printf("add2: %.4lf(sec)\n", cost);
	errorID = matrix_transpose(D0_0, D0_0T);	//D0_0T = D0_0'
	//print_matrix(D0_0T, "D0_0T");
	end = clock();
	cost = (end - start) / CLOCKS_PER_SEC;
	printf("tranpose: %.4lf(sec)\n", cost);
	errorID = matrix_multiplication(D0_0, D0_0T, tmpZ);	//tmpZ = D0_0 * D0_0T
	//print_matrix(tmpZ, "tmpZ");
	end = clock();
	cost = (end - start) / CLOCKS_PER_SEC;
	printf("Matmul: %.4lf(sec)\n", cost);
	int loop = 6;
	for (int i = 0; i < loop; i++) {
		//if (abs(dssn) < 0.001 * ysum) break;
		maxcV2 = -23333333 , dssn = 0 ;
		printf("----------------------loop %d--------------------------------\n", i);
		//print_matrix(E, "E-before");
		errorID = matrix_addex(tmpZ, E, spZ, lambda);
		end = clock();
		cost = (end - start) / CLOCKS_PER_SEC;
		printf("addex %d: %.4lf(sec)\n",i, cost);
		//print_matrix(spZ, "spZ");						//spZ = lambda * tmpZ + Eye
		Y->p = y;										//Y
		//print_matrix(Y, "Y");
		errorID = matrix_multiplication(E, Y, WY);		//WY = Eye * Y
		end = clock();
		cost = (end - start) / CLOCKS_PER_SEC;
		printf("Matmul %d: %.4lf(sec)\n", i, cost);
		//print_matrix(WY, "WY");
		Z = WY;											//Z = WY
		errorID = solve_matrix_equation_by_lup_decomposition(spZ, Z);	//Z = spZ\WY
		end = clock();
		cost = (end - start) / CLOCKS_PER_SEC;
		printf("LU %d: %.4lf(sec)\n", i, cost);
		//print_matrix(Z, "Z");
		errorID = matrix_subtraction(Y, Z, valueAbstract);			//valueAbstract = Y - Z ;
		//print_matrix(valueAbstract, "ValueAbstract");
		for (int i = 0; i < cnt; i++) {
			if (valueAbstract->p[i] < 0) {
				dssn += fabs(1. * valueAbstract->p[i]);
				//printf("%f    ", valueAbstract->p[i]);
			}
		}
		//printf("dssn %d: %lf\n", i, dssn);
		for (int i = 0; i < cnt; i++) {
			if (valueAbstract->p[i] < 0)
			{
				eV[i] = 1.0*exp(1.* i* fabs(valueAbstract->p[i]) / (dssn));
				maxcV2 = max(maxcV2, valueAbstract->p[i]);
			}
			else
				eV[i] = 0;
		}
		eV[0] = 0.05;
		eV[cnt - 1] = eV[0];
		expValues->p = eV;
		//print_matrix(expValues, "eV");
		memset(diage, 0, sizeof(diage));
		for (int i = 0; i < cnt; i++) {
				diage[i*(cnt+1)] = eV[i];
			}
		diagE->p = diage;
		E = diagE;
		Z2 = Z;
		errorID = matrix_subtraction(Y, Z2, res);
		print_matrix(res, "res");
	}
	end = clock();
	cost = (end - start) / CLOCKS_PER_SEC;
	printf("%.4lf(sec)\n", cost);
	system("pause");
}
