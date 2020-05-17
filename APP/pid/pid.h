#ifndef PID_H
#define PID_H

#include "main.h"
#include "system.h"


#ifdef  __PID_GLOBALS   //�䶨������Լ���c�ļ���
#define __PID_EXT
#else
#define __PID_EXT extern
#endif

enum PID_MODE
{
    PID_POSITION = 0,
    PID_DELTA
};

typedef struct
{
    uint8_t mode;
    //PID ������
    fp32 Kp;
    fp32 Ki;
    fp32 Kd;

    fp32 max_out;  //������
    fp32 max_iout; //���������

    fp32 set;
    fp32 fdb;

    fp32 out;
    fp32 Pout;
    fp32 Iout;
    fp32 Dout;
    fp32 Dbuf[3];  //΢���� 0���� 1��һ�� 2���ϴ�
    fp32 error[3]; //����� 0���� 1��һ�� 2���ϴ�

} PidTypeDef;
extern void PID_Init(PidTypeDef *pid, u8 mode, const fp32 PID[3], fp32 max_out, fp32 max_iout);
extern fp32 PID_Calc(PidTypeDef *pid, fp32 ref, fp32 set, u8 sign);
extern void PID_clear(PidTypeDef *pid);

#endif
