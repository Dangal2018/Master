#pragma once
/*******************************************************************************
*     File Name :                        matrix.h
*     Library/Module Name :              MatrixComputation
*     Author :                           Marc Pony(marc_pony@163.com)
*     Create Date :                      2021/6/28
*     Abstract Description :             ���������ͷ�ļ�
*******************************************************************************/

#ifndef  __MATRIX_H__
#define  __MATRIX_H__

/*******************************************************************************
* (1)Debug Switch Section
*******************************************************************************/


/*******************************************************************************
* (2)Include File Section
*******************************************************************************/
#include "common.h"


/*******************************************************************************
* (3)Macro Define Section
*******************************************************************************/


/*******************************************************************************
* (4)Struct(Data Types) Define Section
*******************************************************************************/


/*******************************************************************************
* (5)Prototype Declare Section
*******************************************************************************/

void print_matrix(MATRIX* a, STRING string);

/**********************************************************************************************
Function: creat_matrix
Description: ��������
Input: ��������rows������columns
Output: �����ָ��errorID��ջָ��S
Input_Output: ��
Return: ����ָ��
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
MATRIX* creat_matrix(_IN INTEGER rows, _IN INTEGER columns, _OUT ERROR_ID* errorID, _OUT STACKS* S);


/**********************************************************************************************
Function: creat_multiple_matrices
Description: �����������
Input: ��������rows������columns������count
Output: �����ָ��errorID��ջָ��S
Input_Output: ��
Return: ����ָ��
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
MATRIX* creat_multiple_matrices(_IN INTEGER rows, _IN INTEGER columns, _IN INTEGER count, _OUT ERROR_ID* errorID, _OUT STACKS* S);


/**********************************************************************************************
Function: creat_zero_matrix
Description: ���������
Input: ��������rows������columns
Output: �����ָ��errorID��ջָ��S
Input_Output: ��
Return: ����ָ��
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
MATRIX* creat_zero_matrix(_IN INTEGER rows, _IN INTEGER columns, _OUT ERROR_ID* errorID, _OUT STACKS* S);


/**********************************************************************************************
Function: creat_eye_matrix
Description: ������λ����
Input: ��������rows������columns
Output: �����ָ��errorID��ջָ��S
Input_Output: ��
Return: ����ָ��
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
MATRIX* creat_eye_matrix(_IN INTEGER n, _OUT ERROR_ID* errorID, _OUT STACKS* S);


/**********************************************************************************************
Function: matrix_add
Description: ����A + ����B = ����C
Input: ����A,����B
Output: ����C
Input_Output: ��
Return: �����
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
ERROR_ID matrix_add(_IN MATRIX* A, _IN MATRIX* B, _OUT MATRIX *C);

/**********************************************************************************************
Function: matrix_subtraction
Description: ����A - ����B = ����C
Input: ����A,����B
Output: ����C
Input_Output: ��
Return: �����
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
ERROR_ID matrix_subtraction(_IN MATRIX* A, _IN MATRIX* B, _OUT MATRIX* C);


/**********************************************************************************************
Function: matrix_multiplication
Description: ����˷�C = A * B
Input: ����A,����B
Output: ����C
Input_Output: ��
Return: �����
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
ERROR_ID matrix_multiplication(_IN MATRIX* A, _IN MATRIX* B, _OUT MATRIX* C);


/**********************************************************************************************
Function: matrix_inverse
Description: ��������
Input: ����A
Output: ����A�������
Input_Output: ��
Return: �����
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
ERROR_ID matrix_inverse(_IN MATRIX* A, _OUT MATRIX* invA);


/**********************************************************************************************
Function: matrix_transpose
Description: ����ת��
Input: ����A
Output: ����A��ת��
Input_Output: ��
Return: �����
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
ERROR_ID matrix_transpose(_IN MATRIX* A, _OUT MATRIX* transposeA);


/**********************************************************************************************
Function: matrix_trace
Description: ����ļ�
Input: ����A
Output: ����A�ļ�
Input_Output: ��
Return: �����
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
ERROR_ID matrix_trace(_IN MATRIX* A, _OUT REAL* trace);


/**********************************************************************************************
Function: lup_decomposition
Description: n��n�о���LUP�ֽ�PA = L * U
Input: n��n�о���A
Output: n��n�������Ǿ���L��n��n�������Ǿ���U��n��n���û�����P
Input_Output: ��
Return: �����
Author: Marc Pony(marc_pony@163.com)
�ο���https://zhuanlan.zhihu.com/p/84210687
***********************************************************************************************/
ERROR_ID lup_decomposition(_IN MATRIX* A, _OUT MATRIX* L, _OUT MATRIX* U, _OUT MATRIX* P);


/**********************************************************************************************
Function: solve_matrix_equation_by_lup_decomposition
Description: LUP�ֽ����󷽳�AX=B,����AΪn��n�о���BΪn��m�о���XΪn��m�д������(д������B)
Input: n��n�о���A
Output: ��
Input_Output: n��m�о���B(��n��m�д������X)
Return: �����
Author: Marc Pony(marc_pony@163.com)
***********************************************************************************************/
ERROR_ID solve_matrix_equation_by_lup_decomposition(_IN MATRIX* A, _IN_OUT MATRIX* B);
/**********************************************************************************************
Function: matrix_addex
Description: lambda * ����A + ����B = ����C
Input: ,lambda,����A,����B
Output: ����C
Input_Output: ��
Return: �����
Author: Dangal
***********************************************************************************************/
ERROR_ID matrix_addex(_IN MATRIX* A, _IN MATRIX* B, _OUT MATRIX *C,REAL lambda);
#endif
