/******************************************************************************

                  ��Ȩ���� (C), 2005-2015, ���ҵ���ͨ�����õ缼���ֹ�˾

 ******************************************************************************
  �� �� ��   : gbnx_32_api.c
  �� �� ��   : ����
  ��    ��   : liming
  ��������   : 2013��10��17��
  ����޸�   :
  ��������   : GB/T XXXX.32 2013 ��3-2����  ������Ч����ն�ͨ��Э�����api ʵ��Դ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��10��17��
    ��    ��   : liming
    �޸�����   : �����ļ�

******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "gbnx_32_api.h"

#if TC_CFG_NAME
#define NAME(name) name
#else
#define NAME(name)
#endif

// ���Կ���
#define TC_DBG
// #undef  TC_DBG           // ��ʽ��ʱȥ������ע��

#ifdef TC_DBG
#define TCDBG(format,...) printf("File: "__FILE__", Line: %d: "format"\n", __LINE__, ##__VA_ARGS__)

/*****************************************************************************
 �� �� ��  : stcGetErr
 ��������  : ���ش������������
 �������  : ��
 �������  : ��
 �� �� ֵ  : char
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��30�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
char * stcGetErr(eTcErr eErr)
{
    char *pStr = NULL;
    switch(eErr)
    {
        case TC_OK:
            pStr = "TC_OK";
            break;

        case TC_ERR_NULL:
            pStr = "TC_ERR_NULL";
            break;

        case TC_ERR_OUTRNG:
            pStr = "TC_ERR_OUTRNG";
            break;

        case TC_ERR_NONE:
            pStr = "TC_ERR_NONE";
            break;

        case TC_ERR_IO:
            pStr = "TC_ERR_IO";
            break;

        case TC_ERR_RES:
            pStr = "TC_ERR_RES";
            break;

        case TC_ERR_INIT:
            pStr = "TC_ERR_INIT";
            break;

        case TC_ERR_PARA:
            pStr = "TC_ERR_PARA";
            break;

        case TC_ERR_FN:
            pStr = "TC_ERR_FN";
            break;

        case TC_ERR_PN:
            pStr = "TC_ERR_PN";
            break;

        case TC_ERR_ADDR:
            pStr = "TC_ERR_ADDR";
            break;

        case TC_ERR_CTRL:
            pStr = "TC_ERR_CTRL";
            break;

        case TC_ERR_0x10:
            pStr = "TC_ERR_0x10";
            break;

        case TC_ERR_A2CS:
            pStr = "TC_ERR_A2CS";
            break;

         case TC_ERR_AFN:
            pStr = "TC_ERR_AFN";
            break;

        case TC_ERR_UNCOMP:
            pStr = "TC_ERR_UNCOMP";
            break;

        case TC_ERR_0x68:
            pStr = "TC_ERR_0x68";
            break;

        case TC_ERR_PROTO:
            pStr = "TC_ERR_PROTO";
            break;

        case TC_ERR_CS:
            pStr = "TC_ERR_CS";
            break;

        case TC_ERR_0x16:
            pStr = "TC_ERR_0x16";
            break;

        case TC_ERR_LOGIC:
            pStr = "TC_ERR_LOGIC";
            break;

        case TC_ERR_PACK:
            pStr = "TC_ERR_PACK";
            break;

        case TC_ERR_PFC:
            pStr = "TC_ERR_PFC";
            break;

        case TC_ERR_TIMEOUT:
            pStr = "TC_ERR_TIMEOUT";
            break;

        case TC_ERR_PRM:
            pStr = "TC_ERR_PRM";
            break;

        case TC_ERR_TEAM:
            pStr = "TC_ERR_TEAM";
            break;

         default:
            pStr = "Unkown Err";
            break;
    }

    return pStr;
}
#endif

/*******************************************************
 *  ȫ�ֲ�����Ϣ
 *  �ṩ�������� �� Pn���͡����������Ĺ�ϵӳ��
 *
{*////
BOOL      g_bTcInit = FALSE;             // Э���Ƿ��ʼ��
eTcRole   g_eTcRole = TC_ROLE_UNKOWN;    // ���
UINT8     g_ucTcPermitDelayMinutes = 0;  // ����ʱ��

// ����֡���к� �� ��Ӧ֡���к�
#if TC_CFG_SPT_TML
UINT8     g_ucTcPseq = 0;                // ����֡���к�
UINT8     g_ucTcRseq = 0;                // ��Ӧ֡���к�
#endif


#if TC_CFG_SPT_CON
UINT8     g_aucTcPw[TC_PW_LEN] = {0};    // ��Ϣ��֤�� ������վ����������������
#endif

#if TC_CFG_SPT_TML
sTcEc     g_sTcEc;                       // �¼������� ��������֧��
#endif

#if TC_CFG_ENCRYPT
peTcEncryptFunc   g_peTcEncryptFunc = NULL;  // ���ܽӿ�
peTcDecryptFunc   g_peTcDecryptFunc = NULL;  // ���ܽӿ�
#endif
///*}


/*******************************************************
 *  ������Ϣ��
 *  �ṩ�������� �� Pn���͡����������Ĺ�ϵӳ��
 *
{*////
const sTcmdInfor gtc_cmdinfor[] =
{
    /*******************************
     *  (0) ȷ��/���ϣ�AFN=00H��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *
    {*///  
    // ����
    {TCMD_AFN_0_F1_ALL_OK_DENY,      TC_DIR_C2T, TC_PN_P0,  etc_trans_afn00f1, NAME("ȫ��ȷ��/���ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ����ȷ��/����")},
    {TCMD_AFN_0_F1_ALL_OK_DENY,      TC_DIR_T2C, TC_PN_P0,  etc_trans_afn00f1, NAME("ȫ��ȷ��/���ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ����ȷ��/����")},
    
    // ����
    {TCMD_AFN_0_F2_ONE_BY_ONE,       TC_DIR_T2C, TC_PN_P0,  etc_trans_afn00f2, NAME("�����ݵ�Ԫ��ʶȷ�Ϻͷ��ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ�������ȷ��/����")},
    ///*}

    /*******************************
     *  (1) ��λ���AFN=01H)
     *
     *  ����: AFN 00H ȷ��/����
     *  ����: ������
     *  ����: ��Ҫ
     *
    {*///
    {TCMD_AFN_1_F1_HARD_INIT,        TC_DIR_C2T, TC_PN_P0,  NULL,              NAME("Ӳ����ʼ��")},
    {TCMD_AFN_1_F2_DATA_INIT,        TC_DIR_C2T, TC_PN_P0,  NULL,              NAME("��������ʼ��")},
    {TCMD_AFN_1_F3_FACTORY_RESET,    TC_DIR_C2T, TC_PN_P0,  NULL,              NAME("������ȫ����������ʼ�������ָ����������ã�")},
    {TCMD_AFN_1_F4_PARA_INIT,        TC_DIR_C2T, TC_PN_P0,  NULL,              NAME("����������ϵͳ��վͨ���йصģ���ȫ����������ʼ��")},
    {TCMD_AFN_1_F5_DATA_CLEAR,       TC_DIR_C2T, TC_PN_P0,  etc_trans_afn01f5, NAME("ָ����������")},

     ///*}

    /*******************************
     *  (2) ��·�ӿڼ�⣨AFN=02H��
     *
     *  ����: ������ F1 F2 F3
     *  ����: ������ F4
     *  ����: ����Ҫ
     *
    {*///
    {TCMD_AFN_2_F1_LOG_IN,           TC_DIR_T2C, TC_PN_P0,  NULL, NAME("��¼")},
    {TCMD_AFN_2_F2_LOG_OUT,          TC_DIR_T2C, TC_PN_P0,  NULL, NAME("�˳���¼")},
    {TCMD_AFN_2_F3_HEART_BEAT,       TC_DIR_T2C, TC_PN_P0,  NULL, NAME("����")},
    {TCMD_AFN_2_F4_LINK_OK,          TC_DIR_C2T, TC_PN_P0,  NULL, NAME("ȷ��(��¼/�˳�/����)")},
    ///*}
    
    /*******************************
     *  (4) ���ò���(AFN=04H��
     *
     *  ����: AFN 00H ȷ��/����
     *  ����: ������
     *  ����: ��Ҫ
     *
    {*///
    // ��1   pn:p0
    {TCMD_AFN_4_F1_CON_IP_PORT,      TC_DIR_C2T, TC_PN_P0,  etc_trans_afn04f1,    NAME("�����뽻���ն�IP��ַ�Ͷ˿�")},
    {TCMD_AFN_4_F2_TML_UP_CFG,       TC_DIR_C2T, TC_PN_P0,  etc_trans_afn04f2,    NAME("����ն�����ͨ�Ų�������")},
    {TCMD_AFN_4_F3_TML_AUTH_PARA,    TC_DIR_C2T, TC_PN_P0,  etc_trans_afn04f3,    NAME("����ն�����ͨ����Ϣ��֤��������")},
    {TCMD_AFN_4_F4_TML_STATE_INPUT,  TC_DIR_C2T, TC_PN_P0,  etc_trans_afn04f4,    NAME("״̬���������")},
    {TCMD_AFN_4_F5_TML_EVENT_CFG,    TC_DIR_C2T, TC_PN_P0,  etc_trans_afn04f5,    NAME("�¼���¼����")},

    // ��3   pn:�����
    {TCMD_AFN_4_F17_FREZ_TASK_PARA,  TC_DIR_C2T, TC_PN_TK,  etc_trans_afn04f17,   NAME("����������������")},

    // ��4   pn:�������
    {TCMD_AFN_4_F25_ELEC_MP_CFG,     TC_DIR_C2T, TC_PN_MP,  etc_trans_afn04f25,   NAME("�������������ò���")},
    {TCMD_AFN_4_F26_ELEC_MP_BASE,    TC_DIR_C2T, TC_PN_MP,  NULL,    NAME("�����������������")},
    {TCMD_AFN_4_F27_ELEC_LMIT_PARA,  TC_DIR_C2T, TC_PN_MP,  NULL,    NAME("������������ֵ����")},
    {TCMD_AFN_4_F28_ELEC_LMIT_FACTR, TC_DIR_C2T, TC_PN_MP,  NULL,    NAME("�����������ܹ�����������")},
    {TCMD_AFN_4_F29_ELEC_FIX_HARM,   TC_DIR_C2T, TC_PN_MP,  NULL,    NAME("����������г��������Խ�޶�ֵ")},
    {TCMD_AFN_4_F30_ELEC_FLASH,      TC_DIR_C2T, TC_PN_MP,  NULL,    NAME("��������������Խ�޲���")},

    // ��5   pn:�������
    {TCMD_AFN_4_F33_NELC_MP_CFG,     TC_DIR_C2T, TC_PN_MP,  NULL,    NAME("�ǵ������������ò���")},
    {TCMD_AFN_4_F34_NELC_MP_PARA,    TC_DIR_C2T, TC_PN_MP,  NULL,    NAME("�ǵ����������������")},
    {TCMD_AFN_4_F35_NELC_MP_LMIT,    TC_DIR_C2T, TC_PN_MP,  NULL,    NAME("�ǵ���������Խ�޲���")},
    ///*}
   
    /*******************************
     *  (5) ��������(AFN=05H��
     *
     *  ����: AFN 00H ȷ��/����
     *  ����: ������
     *  ����: ��Ҫ
     *
    {*///
    // ��1  pn:p0
    {TCMD_AFN_5_F1_CHECK_TIME,        TC_DIR_C2T, TC_PN_P0,  etc_trans_afn05f1,     NAME("Уʱ����")},
    {TCMD_AFN_5_F2_FREZ_TEMP,         TC_DIR_C2T, TC_PN_P0,  etc_trans_afn05f2,     NAME("��ʱ������������")},
    {TCMD_AFN_5_F3_AUTO_SAY_ON,       TC_DIR_C2T, TC_PN_P0,  NULL,                  NAME("���������ϱ�")},
    {TCMD_AFN_5_F4_AUTO_SAY_OFF,      TC_DIR_C2T, TC_PN_P0,  NULL,                  NAME("��ֹ�����ϱ�")},
    {TCMD_AFN_5_F5_NX_MODEL_ACT,      TC_DIR_C2T, TC_PN_P0,  etc_trans_afn05f5,     NAME("��Чģ����Ч")},
    {TCMD_AFN_5_F6_NX_MODEL_CLR,      TC_DIR_C2T, TC_PN_P0,  etc_trans_afn05f6,     NAME("��Чģ�����")},
    {TCMD_AFN_5_F7_RQ_RESPN_ACT,      TC_DIR_C2T, TC_PN_P0,  etc_trans_afn05f7,     NAME("������Ӧ��Ϣ��Ч")},
    {TCMD_AFN_5_F8_RQ_RESPN_CLT,      TC_DIR_C2T, TC_PN_P0,  etc_trans_afn05f8,     NAME("������Ӧ��Ϣ���")},

    // ��2  pn:�����
    {TCMD_AFN_5_F9_REPT_FREZ_ON,      TC_DIR_C2T, TC_PN_TK,  NULL,     NAME("������ʱ�ϱ�������������")},
    {TCMD_AFN_5_F10_REPT_FREZ_OFF,    TC_DIR_C2T, TC_PN_TK,  NULL,     NAME("ֹͣ��ʱ�ϱ�������������")},

    // ��3  pn:p0
    {TCMD_AFN_5_F17_REMOTE_OFF,       TC_DIR_C2T, TC_PN_P0,  etc_trans_afn05f17,     NAME("ң����բ")},
    {TCMD_AFN_5_F18_REMOTE_ON,        TC_DIR_C2T, TC_PN_P0,  etc_trans_afn05f18,     NAME("�����բ")},
    ///*}

    /*******************************
     *  (6) �����֤����ԿЭ��(AFN=06H��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *
    {*///
    // ����
    {TCMD_AFN_6_F1_ID_AUTH_Q,         TC_DIR_T2C, TC_PN_P0,  NULL,     NAME("�����֤����")},
    {TCMD_AFN_6_F2_ID_AUTH_A,         TC_DIR_T2C, TC_PN_P0,  NULL,     NAME("�����֤��Ӧ")},
    {TCMD_AFN_6_F3_RAND_Q,            TC_DIR_T2C, TC_PN_P0,  NULL,     NAME("ȡ���������")},
    {TCMD_AFN_6_F4_RAND_A,            TC_DIR_T2C, TC_PN_P0,  NULL,     NAME("ȡ�������Ӧ")},

    // ����
    {TCMD_AFN_6_F1_ID_AUTH_Q,         TC_DIR_C2T, TC_PN_P0,  NULL,     NAME("�����֤����")},
    {TCMD_AFN_6_F2_ID_AUTH_A,         TC_DIR_C2T, TC_PN_P0,  NULL,     NAME("�����֤��Ӧ")},
    {TCMD_AFN_6_F3_RAND_Q,            TC_DIR_C2T, TC_PN_P0,  NULL,     NAME("ȡ���������")},
    {TCMD_AFN_6_F4_RAND_A,            TC_DIR_C2T, TC_PN_P0,  NULL,     NAME("ȡ�������Ӧ")},
    ///*}

    /*******************************
     *  (9) ��ѯ����(AFN=0AH��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *
    {*///
    /** { ���� **/
    // ��1   pn:p0
    {TCMD_AFN_A_F1_CON_IP_PORT,       TC_DIR_T2C, TC_PN_P0,  etc_trans_afn04f1,   NAME("�����뽻���ն�IP��ַ�Ͷ˿�")},
    {TCMD_AFN_A_F2_TML_UP_CFG,        TC_DIR_T2C, TC_PN_P0,  etc_trans_afn04f2,   NAME("����ն�����ͨ�Ų�������")},
    {TCMD_AFN_A_F3_TML_AUTH_PARA,     TC_DIR_T2C, TC_PN_P0,  etc_trans_afn04f3,   NAME("����ն�����ͨ����Ϣ��֤��������")},
    {TCMD_AFN_A_F4_TML_STATE_INPUT,   TC_DIR_T2C, TC_PN_P0,  etc_trans_afn04f4,   NAME("״̬���������")},
    {TCMD_AFN_A_F5_TML_EVENT_CFG,     TC_DIR_T2C, TC_PN_P0,  etc_trans_afn04f5,   NAME("�¼���¼����")},

    // ��2   pn:p0
    {TCMD_AFN_A_F11_TML_SPRT_EVENT,   TC_DIR_T2C, TC_PN_P0,  etc_trans_afn10f11,   NAME("�ն�֧�ֵ��¼���¼��Ϣ")},
    {TCMD_AFN_A_F12_ELEC_MP_INFO,     TC_DIR_T2C, TC_PN_P0,  etc_trans_afn10f12,   NAME("�����õ�����������Ϣ")},
    {TCMD_AFN_A_F13_NELC_MP_INFO,     TC_DIR_T2C, TC_PN_P0,  etc_trans_afn10f13,   NAME("�����÷ǵ�����������Ϣ")},
    {TCMD_AFN_A_F14_TML_PROTO_SPRT,   TC_DIR_T2C, TC_PN_P0,  etc_trans_afn10f14,   NAME("����˿�֧�ֵ�ͨ��Э����Ϣ")},
    {TCMD_AFN_A_F15_TML_MODEL_VERSION,TC_DIR_T2C, TC_PN_P0,  etc_trans_afn10f15,   NAME("�ն��ڸ�����ģ�����Ӳ���汾��Ϣ")},
    {TCMD_AFN_A_F16_TML_VERSION,      TC_DIR_T2C, TC_PN_P0,  etc_trans_afn10f16,   NAME("�ն���Ӳ���汾��Ϣ")},

    // ��3   pn:����ն˺�
    {TCMD_AFN_A_F17_FREZ_TASK_PARA,   TC_DIR_T2C, TC_PN_P0,  etc_trans_afn04f17,   NAME("����������������")},

    // ��4   pn:�������
    {TCMD_AFN_A_F25_ELEC_MP_CFG,      TC_DIR_T2C, TC_PN_MP,  etc_trans_afn04f25,   NAME("�������������ò���")},
    {TCMD_AFN_A_F26_ELEC_MP_BASE,     TC_DIR_T2C, TC_PN_MP,  etc_trans_afn04f26,   NAME("�����������������")},
    {TCMD_AFN_A_F27_ELEC_LMIT_PARA,   TC_DIR_T2C, TC_PN_MP,  etc_trans_afn04f27,   NAME("������������ֵ����")},
    {TCMD_AFN_A_F28_ELEC_LMIT_FACTR,  TC_DIR_T2C, TC_PN_MP,  etc_trans_afn04f28,   NAME("�����������ܹ�����������")},
    {TCMD_AFN_A_F29_ELEC_FIX_HARM,    TC_DIR_T2C, TC_PN_MP,  etc_trans_afn04f29,   NAME("����������г��������Խ�޶�ֵ")},
    {TCMD_AFN_A_F30_ELEC_FLASH,       TC_DIR_T2C, TC_PN_MP,  etc_trans_afn04f30,   NAME("��������������Խ�޲���")},

    // ��5   pn:�ǵ����������
    {TCMD_AFN_A_F33_NELC_MP_CFG,      TC_DIR_T2C, TC_PN_MP,  etc_trans_afn04f33,   NAME("�ǵ������������ò���")},
    {TCMD_AFN_A_F34_NELC_MP_PARA,     TC_DIR_T2C, TC_PN_MP,  etc_trans_afn04f34,   NAME("�ǵ����������������")},
    {TCMD_AFN_A_F35_NELC_MP_LMIT,     TC_DIR_T2C, TC_PN_MP,  etc_trans_afn04f35,   NAME("�ǵ���������Խ�޲���")},
    /** } ���� **/

    /** { ���� **/
    // ��1   pn:p0
    {TCMD_AFN_A_F1_CON_IP_PORT,       TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("�����뽻���ն�IP��ַ�Ͷ˿�")},
    {TCMD_AFN_A_F2_TML_UP_CFG,        TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("����ն�����ͨ�Ų�������")},
    {TCMD_AFN_A_F3_TML_AUTH_PARA,     TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("����ն�����ͨ����Ϣ��֤��������")},
    {TCMD_AFN_A_F4_TML_STATE_INPUT,   TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("״̬���������")},
    {TCMD_AFN_A_F5_TML_EVENT_CFG,     TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("�¼���¼����")},

    // ��2   pn:p0
    {TCMD_AFN_A_F11_TML_SPRT_EVENT,   TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("�ն�֧�ֵ��¼���¼��Ϣ")},
    {TCMD_AFN_A_F12_ELEC_MP_INFO,     TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("�����õ�����������Ϣ")},
    {TCMD_AFN_A_F13_NELC_MP_INFO,     TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("�����÷ǵ�����������Ϣ")},
    {TCMD_AFN_A_F14_TML_PROTO_SPRT,   TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("����˿�֧�ֵ�ͨ��Э����Ϣ")},
    {TCMD_AFN_A_F15_TML_MODEL_VERSION,TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("�ն��ڸ�����ģ�����Ӳ���汾��Ϣ")},
    {TCMD_AFN_A_F16_TML_VERSION,      TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("�ն���Ӳ���汾��Ϣ")},

    // ��3   pn:����ն˺�
    {TCMD_AFN_A_F17_FREZ_TASK_PARA,   TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("����������������")},

    // ��4   pn:�������
    {TCMD_AFN_A_F25_ELEC_MP_CFG,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�������������ò���")},
    {TCMD_AFN_A_F26_ELEC_MP_BASE,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�����������������")},
    {TCMD_AFN_A_F27_ELEC_LMIT_PARA,   TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("������������ֵ����")},
    {TCMD_AFN_A_F28_ELEC_LMIT_FACTR,  TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�����������ܹ�����������")},
    {TCMD_AFN_A_F29_ELEC_FIX_HARM,    TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("����������г��������Խ�޶�ֵ")},
    {TCMD_AFN_A_F30_ELEC_FLASH,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��������������Խ�޲���")},

    // ��5   pn:�ǵ����������
    {TCMD_AFN_A_F33_NELC_MP_CFG,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�ǵ������������ò���")},
    {TCMD_AFN_A_F34_NELC_MP_PARA,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�ǵ����������������")},
    {TCMD_AFN_A_F35_NELC_MP_LMIT,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�ǵ���������Խ�޲���")},
    /** } ���� **/
    ///*}
  
    /*******************************
     *  (10) ����(��ʱ�ϱ�)��������(AFN=0CH��
     *
     *  ����: ���ݲ�ͬ����,�ֱ�������1�����ݺ�����2���������б��Ľ���Ӧ��
     *  ����: ������
     *  ����: ����Ҫ
     *
    {*///
    // ��1   pn:p0
    {TCMD_AFN_C_F1_FREZ_TEMP,         TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("������ʱ��������Ķ�������")},

    // ��2   pn:�����
    {TCMD_AFN_C_F9_FREZ_AUTO,         TC_DIR_C2T, TC_PN_TK,  NULL,  NAME("���󣨶�ʱ�ϱ���������������")},
    {TCMD_AFN_C_F9_FREZ_AUTO,         TC_DIR_T2C, TC_PN_TK,  NULL,  NAME("���󣨶�ʱ�ϱ���������������")},
    ///*}
    
    /*******************************
     *  (11) ����ʵʱ����(AFN=0DH��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *
    {*///
    /** { ���� **/
    // ��1   pn:p0
    {TCMD_AFN_D_F1_CLOCK,             TC_DIR_T2C, TC_PN_P0,  NULL,   NAME("����ʱ��")},
    {TCMD_AFN_D_F2_PARA_STATE,        TC_DIR_T2C, TC_PN_P0,  NULL,   NAME("����״̬")},
    {TCMD_AFN_D_F3_EVENT_1,           TC_DIR_T2C, TC_PN_P0,  NULL,   NAME("��Ҫ�¼���������ǰֵ")},
    {TCMD_AFN_D_F4_EVENT_2,           TC_DIR_T2C, TC_PN_P0,  NULL,   NAME("һ���¼���������ǰֵ")},
    {TCMD_AFN_D_F5_EVENT_STATE,       TC_DIR_T2C, TC_PN_P0,  etc_trans_afn13f5,   NAME("�¼�״̬��־")},
    {TCMD_AFN_D_F6_POWR_TIMES,        TC_DIR_T2C, TC_PN_P0,  NULL,   NAME("�ϵ����")},

    // ��2   pn:p0
    {TCMD_AFN_D_F9_STATE,             TC_DIR_T2C, TC_PN_P0,  NULL,   NAME("״̬������λ��־")},

    // ��3   pn:����������� 
    {TCMD_AFN_D_F17_POWR_HAVE_T,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("���й�����")},
    {TCMD_AFN_D_F18_POWR_NONE_T,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("���޹�����")},
    {TCMD_AFN_D_F19_DEMD_TIME_D,      TC_DIR_T2C, TC_PN_MP,  etc_trans_afn13f19,   NAME("���������������ʱ��")},
    {TCMD_AFN_D_F20_DEMD_TIME_M,      TC_DIR_T2C, TC_PN_MP,  etc_trans_afn13f19,   NAME("���������������ʱ��")},
    {TCMD_AFN_D_F21_FACTR_T,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�ܹ�������")},
    {TCMD_AFN_D_F22_FACTR_A,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A�๦������")},
    {TCMD_AFN_D_F23_FACTR_B,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B�๦������")},
    {TCMD_AFN_D_F24_FACTR_C,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C�๦������")},

    // ��4   pn:�����������
    {TCMD_AFN_D_F25_POWR_HAVE_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���й�����")},
    {TCMD_AFN_D_F26_POWR_HAVE_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���й�����")},
    {TCMD_AFN_D_F27_POWR_HAVE_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���й�����")},
    {TCMD_AFN_D_F28_POWR_NONE_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���޹�����")},
    {TCMD_AFN_D_F29_POWR_NONE_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���޹�����")},
    {TCMD_AFN_D_F30_POWR_NONE_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���޹�����")},

    // ��5   pn:�����������
    {TCMD_AFN_D_F33_POWR_HAVE_FRTH,   TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�������й��ܵ���ʾ��")},
    {TCMD_AFN_D_F34_POWR_HAVE_BACK,   TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�������й��ܵ���ʾ��")},
    {TCMD_AFN_D_F35_POWR_NONE_FRTH,   TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�������޹��ܵ���ʾ��")},
    {TCMD_AFN_D_F36_POWR_NONE_BACK,   TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�������޹��ܵ���ʾ��")},

    // ��6 pn:�����������
    {TCMD_AFN_D_F41_VOLT_A,           TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ѹ")},
    {TCMD_AFN_D_F42_VOLT_B,           TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ѹ")},
    {TCMD_AFN_D_F43_VOLT_C,           TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ѹ")},
    {TCMD_AFN_D_F44_VANGL_A,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ѹ��λ��")},
    {TCMD_AFN_D_F45_VANGL_B,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ѹ��λ��")},
    {TCMD_AFN_D_F46_VANGL_C,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ѹ��λ��")},
    {TCMD_AFN_D_F47_VOLT_UBL,         TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("��ѹ��ƽ���")},
    {TCMD_AFN_D_F48_CIRCLE_V,         TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�ܲ�")},

    // ��7 pn:�����������
    {TCMD_AFN_D_F49_ELEC_A,           TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A�����")},
    {TCMD_AFN_D_F50_ELEC_B,           TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B�����")},
    {TCMD_AFN_D_F51_ELEC_C,           TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C�����")},
    {TCMD_AFN_D_F52_ELEC_M,           TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�����ߵ���")},
    {TCMD_AFN_D_F53_EANGL_A,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A�������λ��")},
    {TCMD_AFN_D_F54_EANGL_B,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B�������λ��")},
    {TCMD_AFN_D_F55_EANGL_C,          TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C�������λ��")},
    {TCMD_AFN_D_F56_ELEC_UBL,         TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("������ƽ���")},

    // ��8 pn:�����������
    {TCMD_AFN_D_F57_VDMAX_A_TIME,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("��A���ѹ����ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F58_VDMAX_B_TIME,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("��B���ѹ����ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F59_VDMAX_C_TIME,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("��C���ѹ����ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F60_IDMAX_A_TIME,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("��A���������ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F61_IDMAX_B_TIME,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("��B���������ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F62_IDMAX_C_TIME,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("��C���������ֵ�ͷ���ʱ��")},

    // ��9 pn:�����������
    {TCMD_AFN_D_F65_VDPP_TIME_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F66_VDPP_TIME_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F67_VDPP_TIME_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F68_VDNN_TIME_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F69_VDNN_TIME_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F70_VDNN_TIME_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ѹԽ���������ۼ�ʱ��")},

    // ��10 pn:�����������
    {TCMD_AFN_D_F73_VMPP_TIME_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F74_VMPP_TIME_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F75_VMPP_TIME_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F76_VMNN_TIME_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F77_VMNN_TIME_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F78_VMNN_TIME_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ѹԽ���������ۼ�ʱ��")},

    // ��11  pn:�����������
    {TCMD_AFN_D_F81_VABR_TOTL_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ѹ�ܻ�����")},
    {TCMD_AFN_D_F82_VABR_TOTL_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ѹ�ܻ�����")},
    {TCMD_AFN_D_F83_VABR_TOTL_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ѹ�ܻ�����")},
    {TCMD_AFN_D_F84_EABR_TOTL_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A������ܻ�����")},
    {TCMD_AFN_D_F85_EABR_TOTL_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B������ܻ�����")},
    {TCMD_AFN_D_F86_EABR_TOTL_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C������ܻ�����")},

    // ��12 pn:�����������
    {TCMD_AFN_D_F89_VABR_OOD_A,       TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ѹ��λ�����")},
    {TCMD_AFN_D_F90_VABR_EVN_A,       TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ѹż�λ�����")},
    {TCMD_AFN_D_F91_VABR_OOD_B,       TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ѹ��λ�����")},
    {TCMD_AFN_D_F92_VABR_EVN_B,       TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ѹż�λ�����")},
    {TCMD_AFN_D_F93_VABR_OOD_C,       TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ѹ��λ�����")},
    {TCMD_AFN_D_F94_VABR_EVN_C,       TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ѹż�λ�����")},

    // ��13 pn:�����������
    {TCMD_AFN_D_F97_EABR_OOD_A,       TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A�������λ�����")},
    {TCMD_AFN_D_F98_EABR_EVN_A,       TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A�����ż�λ�����")},
    {TCMD_AFN_D_F99_EABR_OOD_B,       TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B�������λ�����")},
    {TCMD_AFN_D_F100_EABR_EVN_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B�����ż�λ�����")},
    {TCMD_AFN_D_F101_EABR_OOD_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C�������λ�����")},
    {TCMD_AFN_D_F102_EABR_EVN_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C�����ż�λ�����")},

    // ��14 pn:�������
    {TCMD_AFN_D_F105_TFW_HAVE,        TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�ܻ����й�����")},
    {TCMD_AFN_D_F106_TFW_NONE,        TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�ܻ����޹�����")},
    {TCMD_AFN_D_F107_THW_HAVE,        TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("��г���й�����")},
    {TCMD_AFN_D_F108_THW_NONE,        TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("��г���޹�����")},

    // ��15 pn:�����������
    {TCMD_AFN_D_F113_HARM_VOLT_A,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A��N��г����ѹ")},
    {TCMD_AFN_D_F114_HARM_VOLT_B,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B��N��г����ѹ")},
    {TCMD_AFN_D_F115_HARM_VOLT_C,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C��N��г����ѹ")},
    {TCMD_AFN_D_F116_HARM_ELEC_A,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A��N��г������")},
    {TCMD_AFN_D_F117_HARM_ELEC_B,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B��N��г������")},
    {TCMD_AFN_D_F118_HARM_ELEC_C,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C��N��г������")},

    // ��16 pn:�����������
    {TCMD_AFN_D_F121_HARM_VINC_A,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A��N��г����ѹ������")},
    {TCMD_AFN_D_F122_HARM_VINC_B,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B��N��г����ѹ������")},
    {TCMD_AFN_D_F123_HARM_VINC_C,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C��N��г����ѹ������")},
    {TCMD_AFN_D_F124_HARM_EINC_A,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A��N��г������������")},
    {TCMD_AFN_D_F125_HARM_EINC_B,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B��N��г������������")},
    {TCMD_AFN_D_F126_HARM_EINC_C,     TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C��N��г������������")},

    // ��17 pn:�����������
    {TCMD_AFN_D_F129_FLS_SHRT_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A���ʱ����")},
    {TCMD_AFN_D_F130_FLS_SHRT_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B���ʱ����")},
    {TCMD_AFN_D_F131_FLS_SHRT_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C���ʱ����")},
    {TCMD_AFN_D_F132_FLS_LONG_A,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("A�೤ʱ����")},
    {TCMD_AFN_D_F133_FLS_LONG_B,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("B�೤ʱ����")},
    {TCMD_AFN_D_F134_FLS_LONG_C,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("C�೤ʱ����")},

    // ��18 pn:�ǵ����������
    {TCMD_AFN_D_F137_NELC_VALUE,      TC_DIR_T2C, TC_PN_MP,  NULL,   NAME("�ǵ�����")},
    /** } ���� **/

    /** { ���� **/
    // ��1   pn:p0
    {TCMD_AFN_D_F1_CLOCK,             TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("����ʱ��")},
    {TCMD_AFN_D_F2_PARA_STATE,        TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("����״̬")},
    {TCMD_AFN_D_F3_EVENT_1,           TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("��Ҫ�¼���������ǰֵ")},
    {TCMD_AFN_D_F4_EVENT_2,           TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("һ���¼���������ǰֵ")},
    {TCMD_AFN_D_F5_EVENT_STATE,       TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("�¼�״̬��־")},
    {TCMD_AFN_D_F6_POWR_TIMES,        TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("�ϵ����")},

    // ��2   pn:p0
    {TCMD_AFN_D_F9_STATE,             TC_DIR_C2T, TC_PN_P0,  NULL,   NAME("״̬������λ��־")},

    // ��3   pn:����������� 
    {TCMD_AFN_D_F17_POWR_HAVE_T,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("���й�����")},
    {TCMD_AFN_D_F18_POWR_NONE_T,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("���޹�����")},
    {TCMD_AFN_D_F19_DEMD_TIME_D,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�������������ʱ��")},
    {TCMD_AFN_D_F20_DEMD_TIME_M,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�������������ʱ��")},
    {TCMD_AFN_D_F21_FACTR_T,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�ܹ�������")},
    {TCMD_AFN_D_F22_FACTR_A,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A�๦������")},
    {TCMD_AFN_D_F23_FACTR_B,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B�๦������")},
    {TCMD_AFN_D_F24_FACTR_C,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C�๦������")},

    // ��4   pn:�����������
    {TCMD_AFN_D_F25_POWR_HAVE_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���й�����")},
    {TCMD_AFN_D_F26_POWR_HAVE_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���й�����")},
    {TCMD_AFN_D_F27_POWR_HAVE_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���й�����")},
    {TCMD_AFN_D_F28_POWR_NONE_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���޹�����")},
    {TCMD_AFN_D_F29_POWR_NONE_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���޹�����")},
    {TCMD_AFN_D_F30_POWR_NONE_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���޹�����")},

    // ��5   pn:�����������
    {TCMD_AFN_D_F33_POWR_HAVE_FRTH,   TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�������й��ܵ���ʾ��")},
    {TCMD_AFN_D_F34_POWR_HAVE_BACK,   TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�������й��ܵ���ʾ��")},
    {TCMD_AFN_D_F35_POWR_NONE_FRTH,   TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�������޹��ܵ���ʾ��")},
    {TCMD_AFN_D_F36_POWR_NONE_BACK,   TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�������޹��ܵ���ʾ��")},

    // ��6 pn:�����������
    {TCMD_AFN_D_F41_VOLT_A,           TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ѹ")},
    {TCMD_AFN_D_F42_VOLT_B,           TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ѹ")},
    {TCMD_AFN_D_F43_VOLT_C,           TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ѹ")},
    {TCMD_AFN_D_F44_VANGL_A,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ѹ��λ��")},
    {TCMD_AFN_D_F45_VANGL_B,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ѹ��λ��")},
    {TCMD_AFN_D_F46_VANGL_C,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ѹ��λ��")},
    {TCMD_AFN_D_F47_VOLT_UBL,         TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��ѹ��ƽ���")},
    {TCMD_AFN_D_F48_CIRCLE_V,         TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�ܲ�")},

    // ��7 pn:�����������
    {TCMD_AFN_D_F49_ELEC_A,           TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A�����")},
    {TCMD_AFN_D_F50_ELEC_B,           TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B�����")},
    {TCMD_AFN_D_F51_ELEC_C,           TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C�����")},
    {TCMD_AFN_D_F52_ELEC_M,           TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�����ߵ���")},
    {TCMD_AFN_D_F53_EANGL_A,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A�������λ��")},
    {TCMD_AFN_D_F54_EANGL_B,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B�������λ��")},
    {TCMD_AFN_D_F55_EANGL_C,          TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C�������λ��")},
    {TCMD_AFN_D_F56_ELEC_UBL,         TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("������ƽ���")},

    // ��8 pn:�����������
    {TCMD_AFN_D_F57_VDMAX_A_TIME,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��A���ѹ����ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F58_VDMAX_B_TIME,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��B���ѹ����ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F59_VDMAX_C_TIME,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��C���ѹ����ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F60_IDMAX_A_TIME,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��A���������ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F61_IDMAX_B_TIME,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��B���������ֵ�ͷ���ʱ��")},
    {TCMD_AFN_D_F62_IDMAX_C_TIME,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��C���������ֵ�ͷ���ʱ��")},

    // ��9 pn:�����������
    {TCMD_AFN_D_F65_VDPP_TIME_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F66_VDPP_TIME_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F67_VDPP_TIME_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F68_VDNN_TIME_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F69_VDNN_TIME_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F70_VDNN_TIME_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ѹԽ���������ۼ�ʱ��")},

    // ��10 pn:�����������
    {TCMD_AFN_D_F73_VMPP_TIME_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F74_VMPP_TIME_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F75_VMPP_TIME_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F76_VMNN_TIME_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F77_VMNN_TIME_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ѹԽ���������ۼ�ʱ��")},
    {TCMD_AFN_D_F78_VMNN_TIME_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ѹԽ���������ۼ�ʱ��")},

    // ��11  pn:�����������
    {TCMD_AFN_D_F81_VABR_TOTL_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ѹ�ܻ�����")},
    {TCMD_AFN_D_F82_VABR_TOTL_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ѹ�ܻ�����")},
    {TCMD_AFN_D_F83_VABR_TOTL_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ѹ�ܻ�����")},
    {TCMD_AFN_D_F84_EABR_TOTL_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A������ܻ�����")},
    {TCMD_AFN_D_F85_EABR_TOTL_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B������ܻ�����")},
    {TCMD_AFN_D_F86_EABR_TOTL_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C������ܻ�����")},

    // ��12 pn:�����������
    {TCMD_AFN_D_F89_VABR_OOD_A,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ѹ��λ�����")},
    {TCMD_AFN_D_F90_VABR_EVN_A,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ѹż�λ�����")},
    {TCMD_AFN_D_F91_VABR_OOD_B,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ѹ��λ�����")},
    {TCMD_AFN_D_F92_VABR_EVN_B,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ѹż�λ�����")},
    {TCMD_AFN_D_F93_VABR_OOD_C,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ѹ��λ�����")},
    {TCMD_AFN_D_F94_VABR_EVN_C,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ѹż�λ�����")},

    // ��13 pn:�����������
    {TCMD_AFN_D_F97_EABR_OOD_A,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A�������λ�����")},
    {TCMD_AFN_D_F98_EABR_EVN_A,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A�����ż�λ�����")},
    {TCMD_AFN_D_F99_EABR_OOD_B,       TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B�������λ�����")},
    {TCMD_AFN_D_F100_EABR_EVN_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B�����ż�λ�����")},
    {TCMD_AFN_D_F101_EABR_OOD_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C�������λ�����")},
    {TCMD_AFN_D_F102_EABR_EVN_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C�����ż�λ�����")},

    // ��14 pn:�������
    {TCMD_AFN_D_F105_TFW_HAVE,        TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�ܻ����й�����")},
    {TCMD_AFN_D_F106_TFW_NONE,        TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�ܻ����޹�����")},
    {TCMD_AFN_D_F107_THW_HAVE,        TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��г���й�����")},
    {TCMD_AFN_D_F108_THW_NONE,        TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("��г���޹�����")},

    // ��15 pn:�����������
    {TCMD_AFN_D_F113_HARM_VOLT_A,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A��N��г����ѹ")},
    {TCMD_AFN_D_F114_HARM_VOLT_B,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B��N��г����ѹ")},
    {TCMD_AFN_D_F115_HARM_VOLT_C,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C��N��г����ѹ")},
    {TCMD_AFN_D_F116_HARM_ELEC_A,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A��N��г������")},
    {TCMD_AFN_D_F117_HARM_ELEC_B,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B��N��г������")},
    {TCMD_AFN_D_F118_HARM_ELEC_C,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C��N��г������")},

    // ��16 pn:�����������
    {TCMD_AFN_D_F121_HARM_VINC_A,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A��N��г����ѹ������")},
    {TCMD_AFN_D_F122_HARM_VINC_B,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B��N��г����ѹ������")},
    {TCMD_AFN_D_F123_HARM_VINC_C,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C��N��г����ѹ������")},
    {TCMD_AFN_D_F124_HARM_EINC_A,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A��N��г������������")},
    {TCMD_AFN_D_F125_HARM_EINC_B,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B��N��г������������")},
    {TCMD_AFN_D_F126_HARM_EINC_C,     TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C��N��г������������")},

    // ��17 pn:�����������
    {TCMD_AFN_D_F129_FLS_SHRT_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A���ʱ����")},
    {TCMD_AFN_D_F130_FLS_SHRT_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B���ʱ����")},
    {TCMD_AFN_D_F131_FLS_SHRT_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C���ʱ����")},
    {TCMD_AFN_D_F132_FLS_LONG_A,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("A�೤ʱ����")},
    {TCMD_AFN_D_F133_FLS_LONG_B,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("B�೤ʱ����")},
    {TCMD_AFN_D_F134_FLS_LONG_C,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("C�೤ʱ����")},

    // ��18 pn:�ǵ����������
    {TCMD_AFN_D_F137_NELC_VALUE,      TC_DIR_C2T, TC_PN_MP,  NULL,   NAME("�ǵ�����")},
    /** } ���� **/
    ///*}

    /*******************************
     *  (13) ���������ϱ����¼���¼(AFN=0EH��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *
    {*///
    // ����
    {TCMD_AFN_E_F1_EVENT_1,           TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("������Ҫ�¼�")},
    {TCMD_AFN_E_F2_EVENT_2,           TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("����һ���¼�")},
    {TCMD_AFN_E_F3_EVENT_S,           TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("����ָ���¼�")},

    // ����
    {TCMD_AFN_E_F1_EVENT_1,           TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("������Ҫ�¼�")},
    {TCMD_AFN_E_F2_EVENT_2,           TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("����һ���¼�")},
    {TCMD_AFN_E_F3_EVENT_S,           TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("����ָ���¼�")},
    ///*}

    /*******************************
     *  (14) �ļ�����(AFN=0FH��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *
    {*///
    // ����
    // ��1   pn:p0/����ն˺�
    {TCMD_AFN_F_F1_SOFT_DOWN,         TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("�������")},
    {TCMD_AFN_F_F2_SOFT_LEFT,         TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("������ظ����ݶν���ʧ�ܱ�־��ѯ")},

    // ��2   pn:p0/����ն˺�
    {TCMD_AFN_F_F9_NXMD_DOWN,         TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("��Чģ������")},
    {TCMD_AFN_F_F10_NXMD_LEFT,        TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("��Чģ�����ظ����ݶν���ʧ�ܱ�־��ѯ")},

    // ��3   pn:p0/����ն˺�
    {TCMD_AFN_F_F17_REQS_DOWN,        TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("������Ӧ��Ϣ����")},
    {TCMD_AFN_F_F18_REQS_LEFT,        TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("��Чģ�����ظ����ݶν���ʧ�ܱ�־��ѯ")},

    // ����
    // ��1   pn:p0/����ն˺�
    {TCMD_AFN_F_F1_SOFT_DOWN,         TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("�������")},
    {TCMD_AFN_F_F2_SOFT_LEFT,         TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("������ظ����ݶν���ʧ�ܱ�־��ѯ")},

    // ��2   pn:p0/����ն˺�
    {TCMD_AFN_F_F9_NXMD_DOWN,         TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("��Чģ������")},
    {TCMD_AFN_F_F10_NXMD_LEFT,        TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("��Чģ�����ظ����ݶν���ʧ�ܱ�־��ѯ")},

    // ��3   pn:p0/����ն˺�
    {TCMD_AFN_F_F17_REQS_DOWN,        TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("������Ӧ��Ϣ����")},
    {TCMD_AFN_F_F18_REQS_LEFT,        TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("��Чģ�����ظ����ݶν���ʧ�ܱ�־��ѯ")},
    ///*}

    /*******************************
     *  (15) ����ת��(AFN=11H��
     *
     *  ����: ������
     *  ����: ������
     *  ����: ����Ҫ
     *
    {*///
    // ����
    {TCMD_AFN_10_F1_TRANSMIT,          TC_DIR_T2C, TC_PN_P0,  NULL,  NAME("͸��ת��")},

    // ����
    {TCMD_AFN_10_F1_TRANSMIT,          TC_DIR_C2T, TC_PN_P0,  NULL,  NAME("͸��ת��")},
    ///*}

    /*******************************
     *  (16) �������
     *
     *  �ڴ�֮����չ
     *  ����: ����Ҫ
     *
    {*///
    {TCMD_AFN_FN_MAX,                 TC_DIR_UNKOWN, TC_PN_P0,  NULL, NAME("�������ֵ")}
    ///*}
};
///*}
    
/*****************************************************************************
 �� �� ��  : TC_FREE
 ��������  : �ͷ�malloc������ڴ�ռ�
 �������  : UINT8 *pBuf
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��22��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
#define  TC_FREE(pBuf)\
if(pBuf != NULL)\
{\
    free(pBuf);\
    pBuf = NULL;\
}

/*****************************************************************************
 �� �� ��  : eTcGetCmdInfor
 ��������  : ͨ���������ͺͱ��ķ����ø������Ӧ�������Ϣ
 �������  : eTcmd eCmd           
             eTcDir eDir          
             sTcmdInfor* psInfor  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��10��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr eTcGetCmdInfor(eTcmd eCmd, eTcDir eDir, sTcmdInfor* psInfor)
{
    INT32 i   = 0;
    INT32 Num = 0;

    if(!psInfor)
    {
        #ifdef TC_DBG
        TCDBG("eTcGetCmdInfor() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    Num = sizeof(gtc_cmdinfor) / sizeof(sTcmdInfor);

    for(i = 0; i < Num; i++)
    {
        if(gtc_cmdinfor[i].eCmd == eCmd && gtc_cmdinfor[i].eDir == eDir)
        {
            psInfor->eCmd  = eCmd;
            psInfor->eDir  = eDir;
            psInfor->ePn   = gtc_cmdinfor[i].ePn;
            psInfor->pFunc = gtc_cmdinfor[i].pFunc;
            
            #if TC_CFG_NAME
            psInfor->pName = gtc_cmdinfor[i].pName;
            #endif
            
            return TC_OK;
        }
    }

    return TC_ERR_NONE;
}

/*****************************************************************************
 �� �� ��  : uctc_get_bcd_0
 ��������  : ���һ��char�������ݵ�BCD��λ
 �������  : UINT8 ucData
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 uctc_get_bcd_0(UINT8 ucData)
{
    return (ucData % 10);
}

/*****************************************************************************
 �� �� ��  : uctc_get_bcd_1
 ��������  : ���һ��char�������ݵ�BCD��λ
 �������  : UINT8 ucData
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��1�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 uctc_get_bcd_1(UINT8 ucData)
{
    return (ucData / 10);
}

/*****************************************************************************
 �� �� ��  : etc_bcd_to_str
 ��������  : ������Ϊlen��BCD��תΪ2*len�����ַ���
 �������  : const UINT8 *pbcd
             UINT8 *pstr
             INT32 len
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��31�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_bcd_to_str(const UINT8* pbcd, UINT8* pstr, INT32 len)
{
    INT32 i  = 0, j  = 0;
    UINT8 c1 = 0, c0 = 0;

    if(!pstr || !pbcd)
    {
        #ifdef TC_DBG
        TCDBG("etc_bcd_to_str() para pointer is null");
        #endif
        return TC_ERR_NULL;
    }

    if(len < 0)
    {
        #ifdef TC_DBG
        TCDBG("etc_bcd_to_str() para error");
        #endif
        return TC_ERR_PARA;
    }

    for(i = len - 1,j = 0; i >= 0; i--)
    {
        c0 = pbcd[i] & 0xF;
        c1 = (pbcd[i] >> 4) & 0xF;
        if(c1 >= 0 && c1 <= 9)
        {
            pstr[j++] = c1 + '0';
        }
        else
        {
            pstr[j++] = c1 + 'A';
        }

        if(c0 >= 0 && c0 <= 9)
        {
            pstr[j++] = c0 + '0';
        }
        else
        {
            pstr[j++] = c0 + 'A';
        }
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_str_to_bcd
 ��������  : ������Ϊlen���ַ���ת��ΪBCD ����Ϊ len/2
 �������  : const UINT8 *pstr
             UINT8  *pbcd
             INT32   len
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��31�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_str_to_bcd(const UINT8* pstr, UINT8* pbcd, INT32 len)
{

    UINT8 tmpValue;
    INT32 i;
    INT32 j;
    INT32 m;
    INT32 sLen;

    if(!pstr || !pbcd)
    {
        #ifdef TC_DBG
        TCDBG("etc_str_to_bcd() para pointer is null");
        #endif
        return TC_ERR_NULL;
    }

    if(len < 0)
    {
         #ifdef TC_DBG
         TCDBG("etc_str_to_bcd() para error");
         #endif
         return TC_ERR_PARA;
    }

    sLen = len;

    for(i = 0; i < sLen; i++)
    {
        if((pstr[i] < '0')
        ||((pstr[i] > '9') && (pstr[i] < 'A'))
        ||((pstr[i] > 'F') && (pstr[i] < 'a'))
        ||(pstr[i] > 'f'))
        {
            sLen=i;
            break;
        }
    }

    sLen = ((sLen <= (len * 2)) ?  sLen : sLen * 2);
    memset((void *)pbcd, 0x00, len);

    for(i = sLen-1, j = 0, m = 0; (i>=0) && (m<len); i--, j++)
    {
        if((pstr[i] >= '0') && (pstr[i] <= '9'))
        {
            tmpValue = pstr[i] - '0';
        }
        else if((pstr[i] >= 'A') && (pstr[i] <= 'F'))
        {
            tmpValue = (pstr[i] - 'A' + 0x0A);
        }
        else if((pstr[i] >= 'a') && (pstr[i] <= 'f'))
        {
            tmpValue = (pstr[i] - 'a' + 0x0A);
        }
        else
        {
            tmpValue = 0;
        }

        if((j%2) == 0)
        {
            pbcd[m] = tmpValue;
        }
        else
        {
            pbcd[m++] |= (tmpValue << 4);
        }

        if((tmpValue == 0) && (pstr[i] != '0'))
        {
            break;
        }
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_address
 ��������  : ��ַ���û������֡�����ݽṹת������
 �������  : eTcTrans eTrans         
             sTcAddress *psAddr_u    
             sTcAddress_f *psAddr_f  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��10��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_address(eTcTrans eTrans, sTcAddress *psAddr_u, sTcAddress_f *psAddr_f)
{
    if(!psAddr_u || !psAddr_f)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_address() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(TC_TRANS_U2F == eTrans)
    {
        if(0 == psAddr_u->ulTmlAddress)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_address() contrator address error!");
            #endif
            return TC_ERR_ADDR;
        }

        if(psAddr_u->ucConAddress > TC_MST_ADDR_MAX ||
           psAddr_u->ucConAddress < TC_MST_ADDR_MIN)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_address() master address error!");
            #endif
            return TC_ERR_ADDR;
        }

        (void)etc_str_to_bcd((UINT8*)(psAddr_u->acRegionCode), (UINT8*)(psAddr_f->acRegionCode), TC_REGN_LEN);

        psAddr_f->ulTmlAddress = psAddr_u->ulTmlAddress;

        psAddr_f->ucConAddress = (psAddr_u->ucConAddress << 1);
        if (TRUE == psAddr_u->bTeam)
        {
            psAddr_f->ucConAddress |= 0x01;
        }
        else
        {
            psAddr_f->ucConAddress &= 0xFE;
        }
    }
    else if(TC_TRANS_F2U == eTrans)
    {
        (void)etc_bcd_to_str((UINT8*)(psAddr_f->acRegionCode), (UINT8*)(psAddr_u->acRegionCode), TC_A1_LEN);

        psAddr_u->ulTmlAddress = psAddr_f->ulTmlAddress;
        psAddr_u->bTeam        = (psAddr_f->ucConAddress & 0x01) ? TRUE : FALSE;
        psAddr_u->ucConAddress = (psAddr_f->ucConAddress >> 1) & 0x7F;
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_address() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_get_prm
 ��������  : ���ĳ����Ӧ�õ�prmֵ
 �������  : eTcDir eDir  
             eTcAFN eAfn  
             BOOL bAuto      �Ƿ�Ϊ�����ϱ�
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��28��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcPRM etc_get_prm(eTcDir eDir, eTcAFN eAfn, BOOL bAuto)
{
    eTcPRM  ePrm = TC_PRM_UNKWON;

    if(eDir == TC_DIR_C2T)
    {
        switch ( eAfn )
        {
            case TC_AFN_00_CONF :
            case TC_AFN_02_LINK :
                ePrm = TC_PRM_P2A;
                break;
                
            case TC_AFN_01_RSET :
            case TC_AFN_04_SETP :
            case TC_AFN_05_CTRL :
            case TC_AFN_06_AUTH :
            case TC_AFN_10_GETP :
            case TC_AFN_12_ASKT :
            case TC_AFN_13_ASKR :
            case TC_AFN_14_ASKE :
            case TC_AFN_15_FILE :
            case TC_AFN_16_DATA:
                ePrm = TC_PRM_A2P;
                break;
          
            default:
                ePrm = TC_PRM_UNKWON;
                break;
        }
    }
    else
    {

        switch ( eAfn )
        {
            case TC_AFN_00_CONF :
            case TC_AFN_01_RSET :
            case TC_AFN_04_SETP :
            case TC_AFN_05_CTRL :
            case TC_AFN_06_AUTH :
            case TC_AFN_10_GETP :
            case TC_AFN_12_ASKT :
            case TC_AFN_13_ASKR :
            case TC_AFN_14_ASKE :
            case TC_AFN_15_FILE :
            case TC_AFN_16_DATA:
                ePrm = TC_PRM_P2A;
                break;
                
            case TC_AFN_02_LINK :
                ePrm = TC_PRM_A2P;
                break;
          
            default:
                ePrm = TC_PRM_UNKWON;
                break;
        }
    }
   
    return ePrm;
}
/*****************************************************************************
 �� �� ��  : etc_trans_ctrl
 ��������  : �������û������֡�����ݽṹת������
 �������  : eTcTrans eTrans

 �������  : sTctrl* puCtrl
             UINT16* pfCtrl

 �� �� ֵ  : eTcErr
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_ctrl(eTcTrans eTrans, sTctrl* puCtrl, UINT16* pfCtrl)
{
    UINT8  ucTmp   = 0;
    UINT16 usfCtrl = 0;

    if(!puCtrl || !pfCtrl)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_ctrl() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    // �û���ת��Ϊ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        (puCtrl->eDir == TC_DIR_C2T) ? (usfCtrl &= 0x7FFF) : (usfCtrl |= 0x8000);
        (puCtrl->ePRM == TC_PRM_A2P) ? (usfCtrl |= 0x4000) : (usfCtrl &= 0xBF00);

        ucTmp = puCtrl->ucPSEQ;
        if(ucTmp > TC_PSEQ_MAX)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_ctrl() ucPSEQ is out range! ucPSEQ = %d", ucTmp);
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            usfCtrl |= (ucTmp << 8);
        }

        ucTmp = puCtrl->ucRSEQ;
        if(ucTmp > TC_RSEQ_MAX)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_ctrl() ucRSEQ is out range! ucRSEQ = %d", ucTmp);
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            usfCtrl |= (ucTmp << 4);
        }

        // Fcode
        ucTmp = (UINT8)(puCtrl->eFcode);

        if(ucTmp > TC_FCD_MAX)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_ctrl() eFcode is out range! eFcode = %d", ucTmp);
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            usfCtrl |= ucTmp;
        }

        *pfCtrl = usfCtrl;
    }
    // ֡��ת��Ϊ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        usfCtrl = *pfCtrl;
        puCtrl->eDir   = (usfCtrl & 0x8000) ? TC_DIR_T2C : TC_DIR_C2T;
        puCtrl->ePRM   = (usfCtrl & 0x4000) ? TC_PRM_A2P : TC_PRM_P2A;
        puCtrl->ucPSEQ = (usfCtrl & 0x1F00) >> 8;
        puCtrl->ucRSEQ = (usfCtrl & 0xF0)   >> 4;
        puCtrl->eFcode =  (eTcFcode)(usfCtrl & 0xF);
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_ctrl() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_get_fcode
 ��������  : ���ĳ�����Ӧ�ķ�װ֡�Ĺ�����
 �������  : eTcmd eCmd
             eTcDir eDir
             eTcPRM ePRM
 �������  : eTcFcode * peFcode

 �� �� ֵ  : eTcFcode
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_get_fcode(eTcmd eCmd, eTcDir eDir, eTcPRM ePRM, eTcFcode * peFcode)
{
    eTcErr   eRet   = TC_OK;
    eTcAFN   eAFN   = TC_AFN_NULL;
    eTcFcode eFcode = TC_FCD_MAX;

    if(eDir != TC_DIR_T2C && eDir != TC_DIR_C2T)
    {
        #ifdef TC_DBG
        TCDBG("etc_get_fcode() para eDir is error");
        #endif
        return TC_ERR_PARA;
    }

    if(ePRM != TC_PRM_A2P && ePRM != TC_PRM_P2A)
    {
        #ifdef TC_DBG
        TCDBG("etc_get_fcode() para ePRM is error");
        #endif
        return TC_ERR_PARA;
    }

    switch(eCmd)
    {
        // ��¼
        case TCMD_AFN_2_F1_LOG_IN:
        if(ePRM == TC_PRM_A2P && eDir == TC_DIR_T2C)
        {
            eFcode = TC_FCD_LOG_IN;
        }
        else
        {
            eRet = TC_ERR_LOGIC;
        }
        break;

        // �˳�
        case TCMD_AFN_2_F2_LOG_OUT:
        if(ePRM == TC_PRM_A2P && eDir == TC_DIR_T2C)
        {
            eFcode = TC_FCD_LOG_OUT;
        }
        else
        {
            eRet = TC_ERR_LOGIC;
        }
        break;

        // ����
        case TCMD_AFN_2_F3_HEART_BEAT:
        if(ePRM == TC_PRM_A2P && eDir == TC_DIR_T2C)
        {
            eFcode = TC_FCD_HEART_BEAT;
        }
        else
        {
            eRet = TC_ERR_LOGIC;
        }
        break;

        // ��·������ȷ��
        case TCMD_AFN_2_F4_LINK_OK:
        if(ePRM == TC_PRM_P2A && eDir == TC_DIR_C2T)
        {
            eFcode = TC_FCD_LINK_OK;
        }
        else
        {
            eRet = TC_ERR_LOGIC;
        }
        break;
        
        default:
        eAFN = eTcGetCmdAfn(eCmd);
        if(TC_DIR_C2T == eDir)
        {
            // M2S A2P
            if(TC_PRM_A2P == ePRM)
            {
                switch(eAFN)
                {
                    case TC_AFN_00_CONF:
                    case TC_AFN_01_RSET:
                    case TC_AFN_04_SETP:
                    case TC_AFN_05_CTRL:
                        eFcode = TC_FCD_CONF;
                        break;

                    case TC_AFN_06_AUTH:
                    case TC_AFN_10_GETP:
                    case TC_AFN_12_ASKT:
                    case TC_AFN_13_ASKR:
                    case TC_AFN_14_ASKE:
                         eFcode = TC_FCD_ASK;
                         break;

                    case TC_AFN_15_FILE:
                    case TC_AFN_16_DATA:
                         eFcode = TC_FCD_NOTI;
                         break;

                    default:
                         eRet = TC_ERR_LOGIC;
                         break;
                }
            }
            // M2S P2A
            else
            {
                switch(eAFN)
                {
                    case TC_AFN_00_CONF:
                    case TC_AFN_01_RSET:
                    case TC_AFN_04_SETP:
                    case TC_AFN_05_CTRL:
                         eFcode = TC_FCD_CONF;
                         break;

                    case TC_AFN_06_AUTH:
                    case TC_AFN_10_GETP:
                    case TC_AFN_12_ASKT:
                    case TC_AFN_13_ASKR:
                    case TC_AFN_14_ASKE:
                         eFcode = TC_FCD_ASK;
                         break;

                    case TC_AFN_15_FILE:
                    case TC_AFN_16_DATA:
                         eFcode = TC_FCD_NOTI;
                         break;
                        
                    default:
                         eRet = TC_ERR_LOGIC;
                         break;
                }
            }
        }
        else
        {
            // S2M A2P
            if(TC_PRM_A2P == ePRM)
            {
                switch(eAFN)
                {
                    case TC_AFN_00_CONF:
                    case TC_AFN_01_RSET:
                    case TC_AFN_04_SETP:
                    case TC_AFN_05_CTRL:
                        eFcode = TC_FCD_CONF;
                        break;

                    case TC_AFN_06_AUTH:
                    case TC_AFN_10_GETP:
                    case TC_AFN_12_ASKT:
                    case TC_AFN_13_ASKR:
                    case TC_AFN_14_ASKE:
                        eFcode = TC_FCD_ASK;
                        break;

                    case TC_AFN_15_FILE:
                    case TC_AFN_16_DATA:
                        eFcode = TC_FCD_NOTI;
                        break;

                    default:
                        eRet = TC_ERR_LOGIC;
                        break;
                }
            }
            // S2M P2A
            else
            {
                switch(eAFN)
                {
                    //case TC_AFN_01_RSET:
                    //case TC_AFN_04_SETP:
                    //case TC_AFN_05_CTRL:
                    
                    case TC_AFN_00_CONF:
                         eFcode = TC_FCD_OK;
                         break;

                    case TC_AFN_06_AUTH:
                    case TC_AFN_10_GETP:
                    case TC_AFN_12_ASKT:
                    case TC_AFN_13_ASKR:
                    case TC_AFN_14_ASKE:
                         eFcode = TC_FCD_ASK;
                         break;

                    case TC_AFN_15_FILE:
                    case TC_AFN_16_DATA:
                         eFcode = TC_FCD_NOTI;
                         break;
                    
                    default:
                         eRet = TC_ERR_LOGIC;
                         break;

                }
            }
        }

        break;
    }

    // �������
    *peFcode = eFcode;
    return eRet;
}

/*****************************************************************************
 �� �� ��  : etc_get_ctrl
 ��������  : ��÷�װ֡���û������������
 �������  : eTcTrans eTrans

 �������  : sTcAc* psAc
             UINT8* pucAc

 �� �� ֵ  : eTcErr
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_get_ctrl(eTcAFN eAFN, eTcDir eDir, eTcPRM ePRM, sTctrl *psCtrl)
{
    if(!psCtrl)
    {
        #ifdef TC_DBG
        TCDBG("etc_get_ctrl() para pointer is null");
        #endif
        return TC_ERR_NULL;
    }

    if(TC_DIR_C2T != eDir && TC_DIR_T2C != eDir)
    {
        #ifdef TC_DBG
        TCDBG("etc_get_ctrl() eDir para error");
        #endif
        return TC_ERR_PARA;
    }

    if(TC_PRM_A2P != ePRM && TC_PRM_P2A != ePRM)
    {
        #ifdef TC_DBG
        TCDBG("etc_get_ctrl() ePRM para error");
        #endif
        return TC_ERR_PARA;
    }

    psCtrl->eDir   = eDir;
    psCtrl->ePRM   = ePRM;
    //psCtrl->ucPSEQ =

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_ac
 ��������  : Ӧ�ÿ�����AC �û������֡�����ݽṹת������
 �������  : eTcTrans eTrans

 �������  : sTcAc* psAc
             UINT8* pucAc

 �� �� ֵ  : eTcErr
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��12��10��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_ac(eTcTrans eTrans, sTcAc* puAc, UINT8* pfAc)
{
    UINT8 ucTmp = 0;
    UINT8 ucfAc = 0;

    if(!puAc || !pfAc)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_ac() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    // �û���ת��Ϊ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // tp
        if(TRUE == puAc->bTp)
        {
            ucfAc |= 0x80;
        }

        // ec
        if(TRUE == puAc->bEc)
        {
            ucfAc |= 0x40;
        }

        // afn
        switch(puAc->eAfn)
        {
            case TC_AFN_00_CONF:
            case TC_AFN_01_RSET:
            case TC_AFN_04_SETP:
            case TC_AFN_05_CTRL:
            case TC_AFN_06_AUTH:
            case TC_AFN_10_GETP:
            case TC_AFN_12_ASKT:
            case TC_AFN_13_ASKR:
            case TC_AFN_14_ASKE:
            case TC_AFN_15_FILE:
            case TC_AFN_16_DATA:

                 ucfAc |= (UINT8)(puAc->eAfn);
                 break;

            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_ac() eFcode is out range! eFcode = %d", puAc->eAfn);
                #endif
                return TC_ERR_OUTRNG;
            //break;
        }

        // �������
        *pfAc = ucfAc;

    }
    // ֡��ת��Ϊ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        ucfAc = *pfAc;

        // tp
        puAc->bTp = (ucfAc & 0x80) ? TRUE : FALSE;

        // ec
        puAc->bEc = (ucfAc & 0x40) ? TRUE : FALSE;

        // afn
        ucTmp = ucfAc & 0xF;
        switch(ucTmp)
        {
            case TC_AFN_00_CONF:
            case TC_AFN_01_RSET:
            case TC_AFN_04_SETP:
            case TC_AFN_05_CTRL:
            case TC_AFN_06_AUTH:
            case TC_AFN_10_GETP:
            case TC_AFN_12_ASKT:
            case TC_AFN_13_ASKR:
            case TC_AFN_14_ASKE:
            case TC_AFN_15_FILE:
            case TC_AFN_16_DATA:

                 puAc->eAfn = (eTcAFN)ucTmp;
                 break;

            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_ac() eFcode is out range! eFcode = %d", ucTmp);
                #endif
                return TC_ERR_OUTRNG;
            //break;
        }
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_ac() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : ucTcGetCmdFn
 ��������  : ��������FN
 �������  : eTcmd eCmd
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��8�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8  ucTcGetCmdFn(eTcmd eCmd)
{
    UINT8 ucFn;
    ucFn = (UINT8)(eCmd & 0xFF);
    return ucFn;
}

/*****************************************************************************
 �� �� ��  : eTcGetCmdAfn
 ��������  : ͨ�������ֻ�ȡ�����Ӧ��AFN
 �������  : eTcmd eCmd
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��5��21�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcAFN eTcGetCmdAfn(eTcmd eCmd)
{
    eTcAFN eAfn;
    UINT32 ulCmd = 0;
    UINT8  ucAfn = 0;
    ulCmd = (UINT32)eCmd;
    ucAfn = (UINT8)((ulCmd & 0x0000FF00) >> 8);
    eAfn  = (eTcAFN)ucAfn;
    switch(eAfn)
    {
        case TC_AFN_00_CONF:
        case TC_AFN_01_RSET:
        case TC_AFN_04_SETP:
        case TC_AFN_05_CTRL:
        case TC_AFN_06_AUTH:
        case TC_AFN_10_GETP:
        case TC_AFN_12_ASKT:
        case TC_AFN_13_ASKR:
        case TC_AFN_14_ASKE:
        case TC_AFN_15_FILE:
        case TC_AFN_16_DATA:
            break;

        default:
            eAfn = TC_AFN_NULL;
            break;
    }

    return eAfn;
}

/*****************************************************************************
 �� �� ��  : btc_same_team_pn
 ��������  : �ж�һ����8��Ԫ�ص�Pn����,���8��Pn�Ƿ�����ͬһ����Ϣ����
             ������ЧPn
             �������ͬһ��,�����ȡ��
 �������  : UINT16 *pUsPn8
 �������  : ��
 �� �� ֵ  : ��ͬһ�鷵����
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL btc_same_team_pn(UINT16 *pUsPn8, UINT8* pucDa2)
{
    if(!pUsPn8)
    {
        return FALSE;
    }

    UINT16 usPn[8]   = {0};
    UINT8  ucTeam[8] = {0}; // ÿ��Pn��Ӧ����Ϣ����
    INT32  nPnNum    = 0;   // ��ЧPn�ĸ���
    INT32  i         = 0;
    BOOL   bP0       = FALSE;

    // �ж��Ƿ���P0
    bP0 = btc_is_p0(pUsPn8);
    if(TRUE == bP0)
    {
        if(pucDa2 != NULL)
        {
           *pucDa2 = 0;
        }

        return TRUE;
    }

    for(i = 0; i < 8; i++)
    {
        if(TC_PN_NONE == pUsPn8[i])
        {
            // �Ϸ�,������Ч��ֵ
        }
        else if(pUsPn8[i] < TC_PN_MIN || pUsPn8[i] > TC_PN_MAX)
        {
            #ifdef TC_DBG
            TCDBG("btc_same_team_pn() Pn para err!");
            #endif
            return FALSE;
        }
        // ����һ��Ϊ0���������
        else if(0 == pUsPn8[i])
        {
            return FALSE;
        }
        else
        {
            usPn[nPnNum++] = pUsPn8[i];
        }
    }

    if(0 == nPnNum)
    {
        // ������Ч��ֵ,�������û������,Ҳ��Ϊ����һ��
        return FALSE;
    }
    else if(1 == nPnNum)
    {
        //*pucTeam = (usPN[0] - 1) / 8  + 1;
        //return TRUE;
    }
    else
    {
        for(i = 0; i < nPnNum; i++)
        {
            ucTeam[i] = (usPn[i] - 1) / 8  + 1;
        }

        for(i = 1; i < nPnNum; i++)
        {
            if(ucTeam[i] != ucTeam[0])
            {
                return FALSE;
            }
        }
    }

    if(pucDa2 != NULL)
    {
       *pucDa2 = (usPn[0] - 1) / 8  + 1;
    }

    return TRUE;
}


/*****************************************************************************
 �� �� ��  : btc_is_p0
 ��������  : �ж�һ��Pn�Ƿ�Ϊ0, ��P0
 �������  : UINT16 *pUsPn8
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL btc_is_p0(UINT16 *pUsPn8)
{
    if(!pUsPn8)
    {
        return FALSE;
    }

    INT32 i = 0;
    for(i = 0; i < TC_PN_INDEX_MAX; i++)
    {
        if(pUsPn8[i] != 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}

/*****************************************************************************
 �� �� ��  : uctc_get_pn_team
 ��������  : ���1��Pn��Ӧ����Ϣ�����
 �������  : UINT16 usPn  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 uctc_get_pn_team(UINT16 usPn)
{
    UINT8 ucTeam;

    if(0 == usPn)
    {
        return 0;
    }

    ucTeam = (usPn - 1)/8 + 1;
    return ucTeam;
}

/*****************************************************************************
 �� �� ��  : uctc_get_pn8_team
 ��������  : ���8��Pn��Ӧ����Ϣ�����
 �������  : UINT16 *pusPn
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 uctc_get_pn8_team(UINT16 *pusPn)
{
    if(!pusPn)
    {
        return 0xFF;
    }

    BOOL bP0;
    bP0 = btc_is_p0(pusPn);
    if(TRUE == bP0)
    {
        return 0;
    }

    int i = 0;
    UINT8 ucTeam;
    for(i = 0; i < 8; i++)
    {
        if(pusPn[i] != TC_PN_NONE)
        {
           ucTeam  = uctc_get_pn_team(pusPn[i]);
           return ucTeam;
        }
    }

    return 0xFF;
}

/*****************************************************************************
 �� �� ��  : btc_in_pn8
 ��������  : �ж�ĳһ��pn�Ƿ���һ��8��pn��
 �������  : UINT16 usPn
             UINT16 *pusPn8
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��17�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL btc_in_pn8(UINT16 usPn, UINT16 *pusPn8)
{
    if((!pusPn8) || (usPn > TC_PN_MAX))
    {
        return FALSE;
    }

    INT32 i = 0;

    for(i = 0; i < 8; i++)
    {
        if(usPn == pusPn8[i])
        {
            return TRUE;
        }
    }

    return FALSE;
}

/*****************************************************************************
 �� �� ��  : btc_same_team_fn
 ��������  : �ж�һ����8��Ԫ�ص�Fn����,���8��Fn�Ƿ�����ͬһ����Ϣ����
             ������ЧFn
             �������ͬһ��,�����ȡ��
 �������  : UINT16 *pUcFn8
 �������  : ��
 �� �� ֵ  : ��ͬһ�鷵����
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��6�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL btc_same_team_fn(UINT8  *pUcFn8, UINT8* pucDt2)
{
    if(!pUcFn8)
    {
        return FALSE;
    }

    UINT8  ucFn[8]   = {0};
    UINT8  ucTeam[8] = {0}; // ÿ��Pn��Ӧ����Ϣ����
    INT32  nFnNum    = 0;   // ��ЧPn�ĸ���
    INT32  i         = 0;

    #if 0
    #ifdef TC_DBG
    TCDBG("[in]btc_same_team_fn()");
    for(i = 0; i < 8; i++)
    {
        printf("fn[%d] = %d\n", i, (UINT8)pUcFn8[i]);
    }
    #endif
    #endif

    for(i = 0; i < 8; i++)
    {
        if(TC_FN_NONE == pUcFn8[i])
        {
            // �Ϸ�,������Ч��ֵ
        }
        else if(pUcFn8[i] < TC_FN_MIN || pUcFn8[i] > TC_FN_MAX)
        {
            #ifdef TC_DBG
            TCDBG("btc_same_team_fn() Fn para err!");
            #endif
            return FALSE;
        }
        else
        {
            ucFn[nFnNum++] = pUcFn8[i];
        }
    }

    if(0 == nFnNum)
    {
        // ������Ч��ֵ,�������û������,Ҳ��Ϊ����һ��
        return FALSE;
    }
    else if(1 == nFnNum)
    {
        //*pucTeam = (usPN[0] - 1) / 8  + 1;
        //return TRUE;
    }
    else
    {
        for(i = 0; i < nFnNum; i++)
        {
            ucTeam[i] = (ucFn[i] - 1) / 8 ;
        }

        for(i = 1; i < nFnNum; i++)
        {
            if(ucTeam[i] != ucTeam[0])
            {
                return FALSE;
            }
        }
    }

    if(pucDt2 != NULL)
    {
        *pucDt2 = (ucFn[0] - 1) / 8;
    }

    return TRUE;
}


/*****************************************************************************
 �� �� ��  : uctc_get_fn_team
 ��������  : ���һ��fn��Ӧ����Ϣ����
 �������  : UINT8 ucFn
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 uctc_get_fn_team(UINT8 ucFn)
{
    UINT8 ucTeam = 0;

    // �ж��Ƿ��ǺϷ���Fn
    if(ucFn == TC_FN_NONE)
    {
        ucTeam = 0xFF;
    }
    else
    {
        if(ucFn > TC_FN_MAX || ucFn < TC_FN_MIN)
        {
            ucTeam = 0xFF;
            #ifdef TC_DBG
            TCDBG("uctc_get_fn_team() Fn para err!");
            #endif
        }
        else
        {
            ucTeam = (ucFn - 1)/8 ;
        }
    }

    return ucTeam;
}

/*****************************************************************************
 �� �� ��  : uctc_get_fn_bit
 ��������  : ���һ��Fn��Ӧĳ��Ϣ�����е�bitֵ
 �������  : UINT8 ucFn
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��12�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 uctc_get_fn_bit(UINT8 ucFn)
{
    UINT8 ucBit = 0;

    // �ж��Ƿ��ǺϷ���Fn
    if(ucFn == TC_FN_NONE)
    {
        ucBit = 0xFF;
    }
    else
    {
        if(ucFn > TC_FN_MAX || ucFn < TC_FN_MIN)
        {
            ucBit = 0xFF;
            #ifdef TC_DBG
            TCDBG("uctc_get_fn_bit() Fn para err ucFn = %d!", ucFn);
            #endif
        }
        else
        {
            ucBit = (0x01 << ((ucFn - 1) % 8));
        }
    }

    return ucBit;
}


/*****************************************************************************
 �� �� ��  : uctc_get_fn8_team
 ��������  : ���8��fn��Ӧ����Ϣ����
 �������  : UINT8 *pucFn
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 uctc_get_fn8_team(UINT8 *pucFn)
{
    if(!pucFn)
    {
        return 0xFF;
    }

    INT32      i = 0;
    UINT8 ucTeam = 0xFF;

    for(i = 0 ;i < 8; i++)
    {
        if(pucFn[i] != TC_FN_NONE)
        {
            ucTeam = uctc_get_fn_team(pucFn[i]);
            break;
        }
    }

    return ucTeam;
}


/*****************************************************************************
 �� �� ��  : btc_in_fn8
 ��������  : �ж�ĳһ��fn�Ƿ���һ��8��fn��
 �������  : UINT8 ucFn
             UINT8 *pucFn8
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��17�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL btc_in_fn8(UINT8 ucFn, UINT8 *pucFn8)
{
    if((ucFn < TC_FN_MIN) || (!pucFn8) || (ucFn > TC_FN_MAX))
    {
        return FALSE;
    }

    INT32 i = 0;

    for(i = 0; i < 8; i++)
    {
        if(ucFn == pucFn8[i])
        {
            return TRUE;
        }
    }

    return FALSE;
}

/*****************************************************************************
 �� �� ��  : etc_pnfn_to_dadt
 ��������  : ���ݵ�Ԫ��ʶת������
 �������  : sTcPnFn* psPnFn
             sTcDaDt* psDaDt
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��30�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_pnfn_to_dadt(sTcPnFn* psPnFn, sTcDaDt* psDaDt)
{
    INT32  i           = 0;
    UINT8  ucDa1       = 0;
    UINT8  ucDa2       = 0;
    UINT8  ucDt1       = 0;
    UINT8  ucDt2       = 0;
    const UINT8 ucMask = 0x01;
    UINT8  ucShit      = 0;  // λ�Ƹ���
    BOOL   bSameTeam   = FALSE;
    BOOL   bPn0        = FALSE;

    // �������
    if(!psPnFn || !psDaDt)
    {
        #ifdef TC_DBG
        TCDBG("etc_pnfn_to_dadt() para pointer is null !");
        #endif
        return TC_ERR_NULL;
    }

    // �ж�Pn �Ƿ���ͬһ����
    bSameTeam = btc_same_team_pn(psPnFn->usPn, &ucDa2);
    if(FALSE == bSameTeam)
    {
        #ifdef TC_DBG
        TCDBG("etc_pnfn_to_dadt() Pn is not in a same team!");
        #endif
        return TC_ERR_TEAM;
    }

    // �ж�Fn �Ƿ���ͬһ����
    bSameTeam = btc_same_team_fn(psPnFn->ucFn, &ucDt2);
    if(FALSE == bSameTeam)
    {
        #ifdef TC_DBG
        TCDBG("etc_pnfn_to_dadt() Fn is not in a same team!");
        #endif
        return TC_ERR_TEAM;
    }

    // ��װ Da1
    bPn0 = btc_is_p0(psPnFn->usPn);
    if(TRUE == bPn0)
    {
         ucDa1 = 0;
    }
    else
    {
        for(i = 0; i < TC_PN_INDEX_MAX; i++)
        {
            if(TC_PN_NONE != psPnFn->usPn[i])
            {
                ucShit = (psPnFn->usPn[i] - 1) % 8;
                ucDa1 |= (ucMask << ucShit);
            }
        }
    }

    // ��װDt1
    for(i = 0; i < TC_FN_INDEX_MAX; i++)
    {
        if(TC_FN_NONE != psPnFn->ucFn[i])
        {
            ucShit = (psPnFn->ucFn[i] - 1) % 8;
            ucDt1 |= (ucMask << ucShit);
        }
    }

    // ���Ϸ���fn pn ��װ�� DaDt
    psDaDt->ucDA1 = ucDa1;
    psDaDt->ucDA2 = ucDa2;
    psDaDt->ucDT1 = ucDt1;
    psDaDt->ucDT2 = ucDt2;

    return TC_OK;
}


/*****************************************************************************
 �� �� ��  : etc_dadt_to_pnfn
 ��������  : ���ݱ�ʶ��Ԫת������
 �������  : sTcDaDt* psDaDt
             sTcPnFn* psPnFn
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��7��30�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_dadt_to_pnfn(sTcDaDt* psDaDt, sTcPnFn* psPnFn)
{
    INT32  i      = 0;
    UINT16 usPn   = 0;
    UINT8  ucFn   = 0;
    UINT8  ucMask = 0x01;
    UINT8  ucTmp  = 0;

    if(!psPnFn || !psDaDt)
    {
        #ifdef TC_DBG
        TCDBG("etc_dadt_to_pnfn() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    #if 0
    #ifdef TC_DBG
    TCDBG("[in]etc_dadt_to_pnfn()");
    TCDBG("ucDA1 = 0x%X", psDaDt->ucDA1);
    TCDBG("ucDA2 = 0x%X", psDaDt->ucDA2);
    TCDBG("ucDT1 = 0x%X", psDaDt->ucDT1);
    TCDBG("ucDT2 = 0x%X", psDaDt->ucDT2);
    #endif
    #endif

    // ��������ʼ��
    memset(psPnFn, 0, sizeof(sTcPnFn));

    // Fn
    if(psDaDt->ucDT2 > 30)
    {
        #ifdef TC_DBG
        TCDBG("etc_dadt_to_pnfn() para out of range! ucDT2 = %d", psDaDt->ucDT2);
        #endif
        return TC_ERR_OUTRNG;
    }
    else
    {
        for(i = 0; i < 8; i++)
        {
            ucTmp = ucMask << i;
            if(psDaDt->ucDT1 & ucTmp)
            {
                ucFn = ((psDaDt->ucDT2) * 8) + i + 1;
            }
            else
            {
                ucFn = TC_FN_NONE;
            }

            psPnFn->ucFn[i] = ucFn;
        }
    }

    // P0
    if(0 == psDaDt->ucDA2)
    {
        if(0 == psDaDt->ucDA1)
        {
            for(i = 0; i < 8; i++)
            {
               psPnFn->usPn[i] = 0;
            }
        }
        else
        {
           #ifdef TC_DBG
           TCDBG("etc_dadt_to_pnfn() para err!");
           #endif
           return TC_ERR_PARA;
        }
    }
    // Pn
    else
    {
        for(i = 0; i < 8; i++)
        {
            ucTmp = ucMask << i;
            if(psDaDt->ucDA1 & ucTmp)
            {
                usPn = (psDaDt->ucDA2-1) * 8 + i + 1;
            }
            else
            {
                usPn = TC_PN_NONE;
            }

            psPnFn->usPn[i] = usPn;
        }
    }

    #if 0
    #ifdef TC_DBG
    TCDBG("[out]etc_dadt_to_pnfn()");
    BOOL bP0 = bmt_is_p0(psPnFn->usPn);
    if(bP0 == TRUE)
    {
         TCDBG("usPn = 0");
    }
    else
    {
        for(i = 0; i < 8; i++)
        {
            if(psPnFn->usPn[i] == TC_PN_NONE)
            {
               TCDBG("Pn[%d] = NONE", i+1);
            }
            else
            {
               TCDBG("Pn[%d] = %d", i+1, psPnFn->usPn[i]);
            }
        }
    }

    for(i = 0; i < 8; i++)
    {
        if(psPnFn->ucFn[i] == TC_FN_NONE)
        {
            TCDBG("Fn[%d] = NONE", i+1);
        }
        else
        {
            TCDBG("Fn[%d] = %d", i+1, psPnFn->ucFn[i]);
        }
    }
    #endif
    #endif

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_add_cmdpn
 ��������  : ����*pucNumCmdPn��sTcmdPn�������һ���µ�
             ����Ѿ�����һ��ͬ����������PN��,�����
             ������Ӻ����,����������
 �������  : sTcmdPn* psCmdPn
             UINT8 *pucNumCmdPn
             sTcmdPn sNewCmdPn
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_add_cmdpn(sTcmdPn* psCmdPn,sTcmdPn sNewCmdPn, UINT8 *pucNumCmdPn)
{
    INT32 i   = 0;
    UINT8 ucN = 0;
    
    if(!psCmdPn || !pucNumCmdPn)
    {
        #ifdef TC_DBG
        TCDBG("etc_add_cmdpn() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    ucN = *pucNumCmdPn;

    for (i = 0; i < ucN; i++)
    {
        if(sNewCmdPn.eCmd == psCmdPn[i].eCmd)
        {
            if(sNewCmdPn.usPn == psCmdPn[i].usPn)
            {
                return TC_OK;
            }
        }
    }

    // û���ҵ�ͬ���������һ���µĽ�����
    psCmdPn[ucN].eCmd = sNewCmdPn.eCmd;
    psCmdPn[ucN].usPn = sNewCmdPn.usPn;

    *pucNumCmdPn = (ucN + 1);

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_pnfn_to_cmdpn
 ��������  : ʵ��ucNumPnFn ��sTcPnFn�ṹ���� �� sTcmdPn �ṹ���ݵ�ת��
             �����ת�����������
 �������  : eTcAFN eAfn
             sTcPnFn* psPnFn
             UINT8 ucNumPnFn

 �������  : sTcmdPn* psCmdPn
             UINT8 *pucNumCmdPn
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_pnfn_to_cmdpn(eTcAFN eAfn, sTcPnFn* psPnFn, UINT8 ucNumPnFn,   sTcmdPn* psCmdPn, UINT8 *pucNumCmdPn)
{
    UINT8   ucFn  = 0;
    UINT8   ucAFN = 0;
    UINT16  usCmd = 0;
    INT32   i     = 0;
    INT32   j     = 0;
    INT32   k     = 0;
    eTcmd   eCmd  = TCMD_AFN_F_UNKOWN;
    eTcErr  eRet  = TC_OK;
    sTcDaDt sDaDt;
    sTcmdPn sNew;
    
    if(!psPnFn || !psCmdPn || !pucNumCmdPn)
    {
        #ifdef TC_DBG
        TCDBG("etc_pnfn_to_cmdpn() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    switch(eAfn)
    {
        case TC_AFN_00_CONF:
        case TC_AFN_01_RSET:
        case TC_AFN_04_SETP:
        case TC_AFN_05_CTRL:
        case TC_AFN_06_AUTH:
        case TC_AFN_10_GETP:
        case TC_AFN_12_ASKT:
        case TC_AFN_13_ASKR:
        case TC_AFN_14_ASKE:
        case TC_AFN_15_FILE:
        case TC_AFN_16_DATA:

            ucAFN = (UINT8)eAfn;
            break;

        default:
            #ifdef TC_DBG
            TCDBG("etc_pnfn_to_cmdpn() para err!");
            #endif
            return TC_ERR_PARA;
            //break;

    }

    for(i = 0; i < ucNumPnFn; i++)
    {
        eRet = etc_pnfn_to_dadt(&(psPnFn[i]), &sDaDt);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_pnfn_to_cmdpn() etc_pnfn_to_dadt  err %d", eRet);
            #endif
            return eRet;
        }

        // p0�����
        if(0 == sDaDt.ucDA1 && 0 == sDaDt.ucDA2)
        {
            sNew.usPn = 0;

            for(j = 0; j < 8; j++)
            {
                if(sDaDt.ucDT1 & (0x01 << j))
                {
                    ucFn  = (sDaDt.ucDT2 * 8) + j + 1;
                    usCmd = (UINT16)(ucAFN << 8 | ucFn);
                    eCmd  = (eTcmd)usCmd;
                    sNew.eCmd = eCmd;
                    (void)etc_add_cmdpn(psCmdPn ,sNew,pucNumCmdPn);
                }
            }
        }
        else
        {
            for(k = 0; k < 8; k++)
            {
                if(sDaDt.ucDA1 & (0x01 << k))
                {
                    sNew.usPn = ((sDaDt.ucDA2-1) * 8 + k + 1);
                    for(j = 0; j < 8; j++)
                    {
                        if(sDaDt.ucDT1 & (0x01 << j))
                        {
                            ucFn  = (sDaDt.ucDT2 * 8) + j + 1;
                            usCmd = (UINT16)(ucAFN << 8 | ucFn);
                            eCmd  = (eTcmd)usCmd;
                            sNew.eCmd = eCmd;
                            (void)etc_add_cmdpn(psCmdPn ,sNew,pucNumCmdPn);
                        }
                    }
                }
            }
        }
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_cmdpn_to_pnfn
 ��������  : ʵ�ֽ�ucNumCmdPn��sTcmdPn���� ת����sTcPnFn����
             �����ת����ĸ���pucNumPnFn
 �������  : eTcAFN eAfn
             sTcPnFn* psPnFn
             UINT8 *pucNumPnFn
             sTcmdPn* psCmdPn
             UINT8  ucNumCmdPn
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_cmdpn_to_pnfn(eTcAFN eAfn, sTcPnFn* psPnFn, UINT8 *pucNumPnFn, sTcmdPn* psCmdPn, UINT8  ucNumCmdPn)
{
    UINT8   ucTeamPn     = 0xFF;
    UINT8   ucTeamPnBase = 0xFF;
    UINT8   ucTeamFn     = 0xFF;
    UINT8   ucTeamFnBase = 0xFF;
    UINT8   ucFn         = 0;
    UINT8   ucNumPnFn    = 0;
    UINT16  usPn         = 0;
    INT32   i            = 0;
    INT32   j            = 0;
    INT32   k            = 0;
    INT32   FnIndex      = 0;
    INT32   PnIndex      = 0;
    INT32   nPos         = 0;
    BOOL    bFind        = FALSE;
    BOOL    bInFn8       = FALSE;
    eTcmd   eCmd         = TCMD_AFN_F_UNKOWN;
    eTcAFN  eCmdAfn      = TC_AFN_NULL;
    
    if(!psPnFn || !psCmdPn || !pucNumPnFn)
    {
        #ifdef TC_DBG
        TCDBG("pucNumPnFn() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    for(i = 0; i < ucNumCmdPn; i++)
    {
        eCmd    = psCmdPn[i].eCmd;
        usPn    = psCmdPn[i].usPn;
        ucFn    = ucTcGetCmdFn(eCmd);
        eCmdAfn = eTcGetCmdAfn(eCmd);

        if(eCmdAfn != eAfn)
        {
            #ifdef TC_DBG
            TCDBG("etc_cmdpn_to_pnfn() cmd is not is a same Afn eCmdAfn = %d  eAfn = %d",eCmdAfn, eAfn);
            #endif
            return TC_ERR_TEAM;
        }

        nPos = ucNumPnFn;

        // ��ʼ��PnFn��
        for(k = 0; k < 8; k++)
        {
            psPnFn[nPos].ucFn[k] = TC_FN_NONE;
            psPnFn[nPos].usPn[k] = TC_PN_NONE;
        }

        for(j = 0; j < ucNumPnFn; j++)
        {
            // �ҵ���nDataPos���ҵ���λ��
            // ���ж�Pn�Ƿ���ͬһ��
            ucTeamPn     = uctc_get_pn_team(usPn);
            ucTeamPnBase = uctc_get_pn8_team(psPnFn[j].usPn);

            if(ucTeamPn == ucTeamPnBase)
            {
                // ���ж�Fn�Ƿ�����ͬһ����
                ucTeamFn     = uctc_get_fn_team(ucFn);
                ucTeamFnBase = uctc_get_fn8_team(psPnFn[j].ucFn);

                if(ucTeamFn == ucTeamFnBase)
                {
                    bInFn8 = btc_in_fn8(ucFn, psPnFn[j].ucFn);
                    if(TRUE == bInFn8)
                    {
                         bFind = TRUE;
                         nPos  = j;
                         break;
                    }
                }
            }
        }

         // δ�ҵ�������һ��
        if(FALSE == bFind)
        {
            ucNumPnFn  += 1;
        }

        if(0 == usPn)
        {
            PnIndex = 0;

            for(k = 0; k < 8; k++)
            {
                psPnFn[nPos].usPn[k] = 0;
            }
        }
        else
        {
            PnIndex = (usPn - 1) % 8;
            psPnFn[nPos].usPn[PnIndex] =  usPn;
        }

        FnIndex = (ucFn - 1) % 8;
        psPnFn[nPos].ucFn[FnIndex] = ucFn;

        // ����δ�ҵ�״̬
        bFind = FALSE;

    }

    *pucNumPnFn = ucNumPnFn;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_dadt_to_cmdpn
 ��������  : ʵ��ucNumDaDt ��sTcDaDt�ṹ���� �� sTcmdPn �ṹ���ݵ�ת��
             �����ת����ĸ���
 �������  : eTcAFN eAfn
             sTcDaDt* psDaDt
             UINT8 ucNumDaDt
             sTcmdPn* psCmdPn
             UINT8 *pucNumCmdPn
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_dadt_to_cmdpn(eTcAFN eAfn, sTcDaDt* psDaDt, UINT8 ucNumDaDt, sTcmdPn* psCmdPn, UINT8 *pucNumCmdPn)
{
    UINT8   ucFn  = 0;
    UINT8   ucAFN = 0;
    UINT16  usCmd = 0;
    INT32   i     = 0;
    INT32   j     = 0;
    INT32   k     = 0;
    eTcmd  eCmd  = TCMD_AFN_F_UNKOWN;
    sTcDaDt sDaDt;
    sTcmdPn sNew;
    
    if(!psDaDt || !psCmdPn || !pucNumCmdPn)
    {
        #ifdef TC_DBG
        TCDBG("etc_dadt_to_cmdpn() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    switch(eAfn)
    {
        case TC_AFN_00_CONF:
        case TC_AFN_01_RSET:
        case TC_AFN_04_SETP:
        case TC_AFN_05_CTRL:
        case TC_AFN_06_AUTH:
        case TC_AFN_10_GETP:
        case TC_AFN_12_ASKT:
        case TC_AFN_13_ASKR:
        case TC_AFN_14_ASKE:
        case TC_AFN_15_FILE:
        case TC_AFN_16_DATA:

            ucAFN = (UINT8)eAfn;
            break;

         default:
            #ifdef TC_DBG
            TCDBG("etc_pnfn_to_cmdpn() para err!");
            #endif
            return TC_ERR_PARA;
            //break;

    }

    for(i = 0; i < ucNumDaDt; i++)
    {
        sDaDt.ucDA1 = psDaDt[i].ucDA1;
        sDaDt.ucDA2 = psDaDt[i].ucDA2;
        sDaDt.ucDT1 = psDaDt[i].ucDT1;
        sDaDt.ucDT2 = psDaDt[i].ucDT2;

        // p0�����
        if(0 == sDaDt.ucDA1 && 0 == sDaDt.ucDA2)
        {
            sNew.usPn = 0;

            for(j = 0; j < 8; j++)
            {
                if(sDaDt.ucDT1 & (0x01 << j))
                {
                    ucFn  = (sDaDt.ucDT2 * 8) + j + 1;
                    usCmd = (UINT16)(ucAFN << 8 | ucFn);
                    eCmd  = (eTcmd)usCmd;
                    sNew.eCmd = eCmd;
                    (void)etc_add_cmdpn(psCmdPn ,sNew,pucNumCmdPn);
                }
            }
        }
        else
        {
            for(k = 0; k < 8; k++)
            {
                if(sDaDt.ucDA1 & (0x01 << k))
                {
                    sNew.usPn = ((sDaDt.ucDA2-1) * 8 + k + 1);
                    for(j = 0; j < 8; j++)
                    {
                        if(sDaDt.ucDT1 & (0x01 << j))
                        {
                            ucFn  = (sDaDt.ucDT2 * 8) + j + 1;
                            usCmd = (UINT16)(ucAFN << 8 | ucFn);
                            eCmd  = (eTcmd)usCmd;
                            sNew.eCmd = eCmd;
                            (void)etc_add_cmdpn(psCmdPn, sNew, pucNumCmdPn);
                        }
                    }
                }
            }
        }
    }

    return TC_OK;
}


/*****************************************************************************
 �� �� ��  : etc_cmdpn_to_dadt
 ��������  : ʵ�ֽ�ucNumCmdPn��sTcmdPn���� ת����sTcDaDt����
             �����ת����ĸ���pucNumDaDt
 �������  : eTcAFN eAfn
             sTcDaDt* psDaDt
             UINT8 *pucNumDaDt
             sTcmdPn* psCmdPn
             UINT8  ucNumCmdPn
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��9��13�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_cmdpn_to_dadt(eTcAFN eAfn, sTcDaDt* psDaDt, UINT8 *pucNumDaDt, sTcmdPn* psCmdPn, UINT8  ucNumCmdPn)
{
    sTcPnFn *psPnFn   = NULL;
    UINT8   ucNumPnFn = 0;
    INT32   i         = 0;
    eTcErr  eRet      = TC_OK;
    
    if(!psDaDt || !psCmdPn || !pucNumDaDt)
    {
        #ifdef TC_DBG
        TCDBG("etc_cmdpn_to_dadt() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    psPnFn = (sTcPnFn*)malloc(sizeof(sTcPnFn)*(ucNumCmdPn+1));
    if(!psPnFn)
    {
        #ifdef TC_DBG
        TCDBG("etc_cmdpn_to_dadt() TC_ERR_IO");
        #endif
        return TC_ERR_IO;
    }

    #if 0
    #ifdef TC_DBG
    printf("ucNumCmdPn = %d\n", ucNumCmdPn);
    for(i = 0; i < ucNumCmdPn; i++)
    {
       printf("psCmdPn[%d].eCmd = 0x%04X\n",i, psCmdPn[i].eCmd);
       printf("psCmdPn[%d].usPn = %d\n\n",i, psCmdPn[i].usPn);
    }
    #endif
    #endif

    eRet = etc_cmdpn_to_pnfn(eAfn, psPnFn, &ucNumPnFn, psCmdPn, ucNumCmdPn);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_cmdpn_to_dadt() etc_cmdpn_to_pnfn() error = %d", eRet);
        #endif
        TC_FREE(psPnFn);
        return eRet;
    }

    #if 0
    #ifdef TC_DBG
    int j = 0;
    printf("ucNumPnFn = %d\n", ucNumPnFn);
    for(i = 0; i < ucNumPnFn; i++)
    {
        for(j = 0; j < 8; j++)
        {
            printf("psPnFn[%d].ucFn[%d] = %d\n", i,j ,psPnFn[i].ucFn[j]);
            printf("psPnFn[%d].usPn[%d] = %d\n\n", i,j ,psPnFn[i].usPn[j]);

        }
    }
    #endif
    #endif

    for(i = 0; i < ucNumPnFn; i++)
    {
        eRet = etc_pnfn_to_dadt(&(psPnFn[i]), &(psDaDt[i]));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_cmdpn_to_dadt() etc_pnfn_to_dadt() error = %d", eRet);
            #endif
            TC_FREE(psPnFn);
            return eRet;
        }
    }

    *pucNumDaDt = ucNumPnFn;
    TC_FREE(psPnFn);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : ntc_pow
 ��������  : ��10��N�η� (ע�������Ҫ����10)
 �������  : UINT8 exp
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��5��29��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int  ntc_pow(UINT8 exp)
{
    if(exp > 10)
    {
        return -1;
    }

    if(exp == 0)
    {
        return 1;
    }

    return 10 * ntc_pow(exp -1);
}

/*****************************************************************************
 �� �� ��  : ntc_get_float_sign
 ��������  : ���һ��Float�ķ���λ  0 1
 �������  : float fVal
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��6��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int    ntc_get_float_sign(float fVal)
{
    uMcFloatFmt floatFmt;
    floatFmt.v = fVal;
    return floatFmt.s.sign;
}

/*****************************************************************************
 �� �� ��  : vtc_set_float_sign
 ��������  : ����һ��������Float�ķ���λ
 �������  : float *pfVal
             int sign     ���ڵ���0Ϊ����С��0Ϊ��
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��6��4��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
void   vtc_set_float_sign(float *pfVal, int sign)
{
    uMcFloatFmt *pFloatFmt;
    pFloatFmt = (uMcFloatFmt *)pfVal;

    if(sign >= 0)
    {
        pFloatFmt->s.sign = 0;
    }
    else
    {
        pFloatFmt->s.sign = 1;
    }
}

/*****************************************************************************
 �� �� ��  : ntc_get_double_sign
 ��������  : ���һ��double �ķ���λ
 �������  : double dVal
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��5��30��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
int    ntc_get_double_sign(double dVal)
{
    uMcDoubleFmt  doubleFmt;
    doubleFmt.v = dVal;
    return doubleFmt.s.sign;
}

/*****************************************************************************
 �� �� ��  : vtc_set_double_sign
 ��������  : ���ø������ķ���λ
 �������  : int sign   >= 0 ʱ������Ϊ������ < 0ʱ����Ϊ����
 �������  : double *pdVal
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��5��30��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
void   vtc_set_double_sign(double *pdVal, int sign)
{
    uMcDoubleFmt  *pdoubleFmt;
    pdoubleFmt = (uMcDoubleFmt*)pdVal;

    if(sign >= 0)
    {
        pdoubleFmt->s.sign = 0;
    }
    else
    {
        pdoubleFmt->s.sign = 1;
    }
}

/*****************************************************************************
 �� �� ��  : etc_get_tp
 ��������  : ��õ�ǰ�û���Tp (�Զ�ȡ��ǰϵͳʱ��)
 �������  : sTcTp *psuTp
 �������  : sTcTp *psuTp
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��5��30��
    ��    ��   : ����
    �޸�����   : �����ɺ���
*****************************************************************************/
eTcErr etc_get_tp(sTcTp *psuTp)
{
    // ��ȡϵͳ��ǰʱ��
    time_t now;
    struct tm* timenow;
    time(&now);
    timenow = localtime(&now);
    
    if(!psuTp)
    {
        #ifdef TC_DBG
        TCDBG("etc_get_tp() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    psuTp->sTime.ucDD = timenow->tm_mday;
    psuTp->sTime.ucHH = timenow->tm_hour;
    psuTp->sTime.ucmm = timenow->tm_min;
    psuTp->sTime.ucss = timenow->tm_sec;

    psuTp->ucPermitDelayMinutes = g_ucTcPermitDelayMinutes;

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : btc_tp_timeout
 ��������  : �Ե�ǰʱ��Ϊ��׼�ж�һ��tp�Ƿ�ʱ
 �������  : sTcTp *psTP
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��9�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL  btc_tp_timeout(sTcTp *psTP)
{
    time_t now;
    struct tm* timenow;
    UINT8 ucDelayMinutes;  // ���ʹ�����ʱʱ��
    // ��ȡϵͳ��ǰʱ��
    
    int cDay  = 0;
    int cHour = 0;
    int cMin  = 0;
    int cSec  = 0;
    int rDay  = 0;
    int rHour = 0;
    int rMin  = 0;
    int rSec  = 0;
    int minutes = 0;  // ��ص�����
    
    if(!psTP)
    {
        return TRUE;
    }

    time(&now);
    timenow = localtime(&now);

    cDay  = timenow->tm_mday;
    cHour = timenow->tm_hour;
    cMin  = timenow->tm_min;
    cSec  = timenow->tm_sec;

    rDay  = psTP->sTime.ucDD;
    rHour = psTP->sTime.ucHH;
    rMin  = psTP->sTime.ucmm;
    rSec  = psTP->sTime.ucss;
    ucDelayMinutes = psTP->ucPermitDelayMinutes;
    minutes = (cDay - rDay)*60*24 + (cHour - rHour)*60 + (cMin - rMin) * 1;

    // pclint
    cSec = cSec;
    rSec = rSec;

    if(minutes < 0)
    {
        return TRUE;
    }

    if(minutes <= ucDelayMinutes)
    {
        return FALSE;
    }

    return TRUE;
}
/*****************************************************************************
 �� �� ��  : etc_trans_tp
 ��������  : Tp���ݽṹת������
 �������  : eTcTrans eTrans
 �������  : sTcTp* psUser
             sTcTp_f* psFrame
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��5��30��
    ��    ��   : ����
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_tp(eTcTrans eTrans, sTcTp* psUser, sTcTp_f* psFrame)
{
    eTcErr eRet = TC_OK;

    if(!psFrame || !psUser)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_tp() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    // ֡�ൽ�û���
    if (TC_TRANS_F2U == eTrans)
    {
        psUser->ucPermitDelayMinutes = psFrame->ucPermitDelayMinutes;
        eRet = etc_trans_DDHHmmss(eTrans, &(psUser->sTime), &(psFrame->sTime));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_tp()etc_trans_DDHHmmss error %d!", eRet);
            #endif
            return eRet;
        }
    }
    // �û��ൽ֡��
    else if (TC_TRANS_U2F == eTrans)
    {
        psFrame->ucPermitDelayMinutes = psUser->ucPermitDelayMinutes;
        eRet = etc_trans_DDHHmmss(eTrans, &(psUser->sTime), &(psFrame->sTime));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_tp()etc_trans_DDHHmmss error %d!", eRet);
            #endif
            return eRet;
        }
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_tp() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : btc_is_0xEE
 ��������  : �ж�usLen����pData���������Ƿ���0xEE
 �������  : UINT8* pData
             UINT16 usLen
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��12��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL   btc_is_0xEE(UINT8* pData, UINT16 usLen)
{
    if(!pData)
    {
        return FALSE;
    }

    INT32 i = 0;
    for(i = 0; i < usLen; i++)
    {
        if(0xEE != pData[i])
        {
            return FALSE;
        }
    }

    return TRUE;
}

/*****************************************************************************
 �� �� ��  : vtc_set_0xEE
 ��������  : ��usLen������pData�����ݶ�����Ϊ0xEE
 �������  : UINT8* pData
             UINT16 usLen
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void   vtc_set_0xEE(UINT8* pData, UINT16 usLen)
{
    INT32 i = 0;

    if(!pData)
    {
        return;
    }

    for(i = 0; i < usLen; i++)
    {
        pData[i] = 0xEE;
    }
}

/*****************************************************************************
 �� �� ��  : btc_is_none
 ��������  : �Ƿ�һ��������Ϊȱʡ
 �������  : UINT8* pData
             UINT16 usLen
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL   btc_is_none(UINT8* pData, UINT16 usLen)
{
    return btc_is_0xEE(pData, usLen);
}

/*****************************************************************************
 �� �� ��  : vtc_set_none
 ��������  : ��ĳ����������Ϊȱʡ
 �������  : UINT8* pData
             UINT16 usLen
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��12�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void   vtc_set_none(UINT8* pData, UINT16 usLen)
{
    vtc_set_0xEE(pData, usLen);
}

/*****************************************************************************
 �� �� ��  : btc_have_ec
 ��������  : ���౨�����Ƿ�Ӧ�ú���ec�ֶ�
 �������  : eTcAFN eAFN
             eTcDir eDir
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��2��27��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL   btc_have_ec(eTcAFN eAFN, eTcDir eDir)
{
    if(TC_DIR_T2C == eDir)
    {
        if(TC_AFN_15_FILE == eAFN || 
           TC_AFN_06_AUTH == eAFN)
        {
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

/*****************************************************************************
 �� �� ��  : btc_have_pw
 ��������  : �˱������Ƿ�Ӧ�û���pw�ֶ�
 �������  : eTcAFN eAFN
             eTcDir eDir
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��2��27��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL   btc_have_pw(eTcAFN eAFN, eTcDir eDir)
{
    if((TC_DIR_C2T == eDir)  &&
        (TC_AFN_01_RSET == eAFN  ||
         TC_AFN_04_SETP == eAFN  ||
         TC_AFN_05_CTRL == eAFN  ||
         TC_AFN_16_DATA == eAFN  ||
        (TC_AFN_06_AUTH == eAFN)) )          // ˫�������֤�����ж���PW
    {
        return TRUE;
    }

    return FALSE;
}

/*****************************************************************************
 �� �� ��  : btc_have_tp
 ��������  : �˱���(�� eRole ���͵ı���)���Ƿ�Ӧ�û���tp�ֶ�
             Ŀǰ���б��ĸ�ʽĬ������¶���TP
 �������  : eTcAFN eAFN
             eTcDir eDir
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��2��27��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
BOOL  btc_have_tp(eTcAFN eAFN, eTcDir eDir)
{
    if(TC_CFG_TP == 1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }        
}

/*****************************************************************************
 �� �� ��  : vtc_set_ec
 ��������  : �����¼���������ֵ
 �������  : sTcEc *psEc  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��28��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void vtc_set_ec(sTcEc *psEc)
{
    if(!psEc)
    {
        #ifdef TC_DBG
        TCDBG("vtc_set_ec() pointer is null!");
        #endif
        return;
    }

    g_sTcEc.usEC1 = psEc->usEC1;
    g_sTcEc.usEC2 = psEc->usEC2;
}   

/*****************************************************************************
 �� �� ��  : ustc_get_aux_len
 ��������  : ��õ�ǰ���͵ı����и���������ֳ�(ec pw tp)
 �������  : eTcAFN eAFN
             eTcDir eDir
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��29�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT16 ustc_get_aux_len(eTcAFN eAFN, eTcDir eDir, BOOL bEc, BOOL bTp)
{
    UINT16 usAuxLen = 0;
    BOOL   bPw = FALSE;

    bPw = btc_have_pw(eAFN, eDir);
    if(TRUE == bEc)
    {
        usAuxLen += sizeof(sTcEc);
    }

    if(TRUE == bPw)
    {
        usAuxLen += TC_PW_LEN;
    }

    if(TRUE == bTp)
    {
        usAuxLen += sizeof(sTcTp_f);
    }

    return usAuxLen;

}
/*****************************************************************************
 �� �� ��  : etc_trans_YWMDhms
 ��������  : ���ݸ�ʽ01 ���ڱ�A.1 ��ʽ
 �������  : eTcTrans eTrans

 �������  : sTcYWMDhms* psUser
             sTcYWMDhms_f* psFrame
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��21�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_YWMDhms(eTcTrans eTrans, sTcYWMDhms* psUser, sTcYWMDhms_f* psFrame)
{
    if(!psFrame || !psUser)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_YWMDhms() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    // ֡�ൽ�û���
    if (TC_TRANS_F2U == eTrans) 
    {
        psUser->ucYY  = psFrame->bcd_YY_0 + psFrame->bcd_YY_1 * 10;
        psUser->ucWW  = psFrame->bcd_WW_0;
        psUser->ucMM  = psFrame->bcd_MM_0 + psFrame->bcd_MM_1 * 10;
        psUser->ucDD  = psFrame->bcd_DD_0 + psFrame->bcd_DD_1 * 10;
        psUser->ucHH  = psFrame->bcd_HH_0 + psFrame->bcd_HH_1 * 10;
        psUser->ucmm  = psFrame->bcd_mm_0 + psFrame->bcd_mm_1 * 10;
        psUser->ucss  = psFrame->bcd_ss_0 + psFrame->bcd_ss_1 * 10;
    }
    // �û��ൽ֡��
    else if (TC_TRANS_U2F == eTrans)
    {
        // ��
        psFrame->bcd_YY_0 = uctc_get_bcd_0(psUser->ucYY);
        psFrame->bcd_YY_1 = uctc_get_bcd_1(psUser->ucYY);

        // ��
        if (psUser->ucMM > 12)
        {
             #ifdef TC_DBG
             TCDBG("etc_trans_YWMDhms() ucMM TC_ERR_OUTRNG!");
             #endif
             return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_MM_0 = uctc_get_bcd_0(psUser->ucMM);
            psFrame->bcd_MM_1 = uctc_get_bcd_1(psUser->ucMM);
        }

        // ����
        if (psUser->ucWW > 7)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_YWMDhms() ucWW TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_WW_0 = psUser->ucWW;
        }

        // ��
        if (psUser->ucDD > 31)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_YWMDhms() ucDD TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_DD_0 = uctc_get_bcd_0(psUser->ucDD);
            psFrame->bcd_DD_1 = uctc_get_bcd_1(psUser->ucDD);
        }

        // ʱ
        if(psUser->ucHH > 24)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_YWMDhms() ucHH TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_HH_0 = uctc_get_bcd_0(psUser->ucHH);
            psFrame->bcd_HH_1 = uctc_get_bcd_1(psUser->ucHH);
        }

        // ��
        if(psUser->ucmm > 60)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_YWMDhms() ucmm TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_mm_0 = uctc_get_bcd_0(psUser->ucmm);
            psFrame->bcd_mm_1 = uctc_get_bcd_1(psUser->ucmm);
        }

        // ��
        if(psUser->ucss > 60)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_YWMDhms() ucSencond TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_ss_0 = uctc_get_bcd_0(psUser->ucss);
            psFrame->bcd_ss_1 = uctc_get_bcd_1(psUser->ucss);
        }
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_YWMDhms() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}


/*****************************************************************************
 �� �� ��  : etc_trans_YYMMDDhhmm
 ��������  : ���ݸ�ʽת������  ���ݸ�ʽ2 ���ڱ�A.2 ��λ: ������ʱ��
 �������  : eTcTrans eTrans
             sTcYMDhm* psUser
             sTcYMDhm_f* psFrame
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_YYMMDDhhmm(eTcTrans eTrans, sTcYMDhm* psUser, sTcYMDhm_f* psFrame)
{
    if(!psUser || !psFrame)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_YYMMDDhhmm() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(TC_TRANS_U2F == eTrans)
    {
        // ��
        psFrame->bcd_YY_0 = uctc_get_bcd_0(psUser->ucYY);
        psFrame->bcd_YY_1 = uctc_get_bcd_1(psUser->ucYY);

        // ��
        if(psUser->ucMM > 12)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_YYMMDDhhmm() ucMM TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_MM_0 = uctc_get_bcd_0(psUser->ucMM);
            psFrame->bcd_MM_1 = uctc_get_bcd_1(psUser->ucMM);
        }

        // ��
        if(psUser->ucDD > 31)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_YYMMDDhhmm() ucDD TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_DD_0 = uctc_get_bcd_0(psUser->ucDD);
            psFrame->bcd_DD_1 = uctc_get_bcd_1(psUser->ucDD);
        }

        // ʱ
        if(psUser->ucHH > 24)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_YYMMDDhhmm() ucHH TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_hh_0 = uctc_get_bcd_0(psUser->ucHH);
            psFrame->bcd_hh_1 = uctc_get_bcd_1(psUser->ucHH);
        }

        // ��
        if(psUser->ucmm > 60)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_YYMMDDhhmm() ucmm TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psFrame->bcd_mm_0 = uctc_get_bcd_0(psUser->ucmm);
            psFrame->bcd_mm_1 = uctc_get_bcd_1(psUser->ucmm);
        }

    }
    else if(TC_TRANS_F2U == eTrans)
    {
        psUser->ucYY = psFrame->bcd_YY_0 + psFrame->bcd_YY_1 * 10;
        psUser->ucMM = psFrame->bcd_MM_0 + psFrame->bcd_MM_1 * 10;
        psUser->ucDD = psFrame->bcd_DD_0 + psFrame->bcd_DD_1 * 10;
        psUser->ucHH = psFrame->bcd_hh_0 + psFrame->bcd_hh_1 * 10;
        psUser->ucmm = psFrame->bcd_mm_0 + psFrame->bcd_mm_1 * 10;
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("uctc_get_bcd_0() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_DDHHmmss
 ��������  : ���ݸ�ʽת������ ���ݸ�ʽ3 ���ڱ�A.3 ��λ: ��ʱ����
 �������  : eTcTrans eTrans
             sTcDDhhmmss* psDDhhmmss_u
             sTcDDhhmmss_f* psDDhhmmss_f
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_DDHHmmss(eTcTrans eTrans, sTcDDHHmmss* psDDHHmmss_u, sTcDDHHmmss_f* psDDHHmmss_f)
{
    if(!psDDHHmmss_u || !psDDHHmmss_f)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_DDhhmmss() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(TC_TRANS_U2F == eTrans)
    {
        if(psDDHHmmss_u->ucDD > 31 || psDDHHmmss_u->ucDD < 0)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_DDhhmmss() ucDD TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psDDHHmmss_f->bcd_DD_0 = uctc_get_bcd_0(psDDHHmmss_u->ucDD);
            psDDHHmmss_f->bcd_DD_1 = uctc_get_bcd_1(psDDHHmmss_u->ucDD);
        }

        if(psDDHHmmss_u->ucHH > 24)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_DDhhmmss() ucHH TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psDDHHmmss_f->bcd_HH_0 = uctc_get_bcd_0(psDDHHmmss_u->ucHH);
            psDDHHmmss_f->bcd_HH_1 = uctc_get_bcd_1(psDDHHmmss_u->ucHH);
        }

        if(psDDHHmmss_u->ucmm > 60)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_DDhhmmss() ucHH TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psDDHHmmss_f->bcd_mm_0 = uctc_get_bcd_0(psDDHHmmss_u->ucmm);
            psDDHHmmss_f->bcd_mm_1 = uctc_get_bcd_1(psDDHHmmss_u->ucmm);
        }

        if(psDDHHmmss_u->ucss > 60)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_DDhhmmss() ucHH TC_ERR_OUTRNG!");
            #endif
            return TC_ERR_OUTRNG;
        }
        else
        {
            psDDHHmmss_f->bcd_ss_0 = uctc_get_bcd_0(psDDHHmmss_u->ucss);
            psDDHHmmss_f->bcd_ss_1 = uctc_get_bcd_1(psDDHHmmss_u->ucss);
        }
    }
    else if(TC_TRANS_F2U == eTrans)
    {
        psDDHHmmss_u->ucDD = psDDHHmmss_f->bcd_DD_0 + psDDHHmmss_f->bcd_DD_1 * 10;
        psDDHHmmss_u->ucHH = psDDHHmmss_f->bcd_HH_0 + psDDHHmmss_f->bcd_HH_1 * 10;
        psDDHHmmss_u->ucmm = psDDHHmmss_f->bcd_mm_0 + psDDHHmmss_f->bcd_mm_1 * 10;
        psDDHHmmss_u->ucss = psDDHHmmss_f->bcd_ss_0 + psDDHHmmss_f->bcd_ss_1 * 10;
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_DDhhmmss() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_XXXXXX_XXXX
 ��������  : ���ݸ�ʽ4 ���ڱ�A.4 ��ʽ: (+)XXXXXX.XXXX
 �������  : eTcTrans eTrans
             float* psUser
             sTcFmt_XXXXXX_XXXX* psFrame
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_XXXXXX_XXXX(eTcTrans eTrans, double* psUser, sTcFmt_XXXXXX_XXXX* psFrame)
{
    sTcFmt_XXXXXX_XXXX    *pf;
    double                *pu;
    pf              = (sTcFmt_XXXXXX_XXXX *)psFrame;
    pu              = (double *)psUser;
    double dValue   = *pu;
    
    if(!psFrame || !psUser)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_XXXXXX_XXXX() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        if(dValue > 999999.9999 || dValue < -999999.9999)
        {
            return TC_ERR_OUTRNG;
        }
        CHAR buf[7] = {0};

        //����ṹ
        pf->BCD_5   = (UINT8)(dValue / ntc_pow(5));
        dValue     -= pf->BCD_5 * ntc_pow(5);
        pf->BCD_4   = (UINT8)(dValue / ntc_pow(4));
        dValue     -= pf->BCD_4 * ntc_pow(4);
        pf->BCD_3   = (UINT8)(dValue / ntc_pow(3));
        dValue     -= pf->BCD_3 * ntc_pow(3);
        pf->BCD_2   = (UINT8)(dValue / ntc_pow(2));
        dValue     -= pf->BCD_2 * ntc_pow(2);
        pf->BCD_1   = (UINT8)(dValue / ntc_pow(1));
        dValue     -= pf->BCD_1 * ntc_pow(1);
        pf->BCD_0   = (UINT8)dValue % ntc_pow(1);
        dValue     -= pf->BCD_0;

        sprintf(buf,"%4.4f",dValue);
        pf->BCD_0_1   = buf[2] - '0';
        pf->BCD_0_2   = buf[3] - '0';
        pf->BCD_0_3   = buf[4] - '0';
        pf->BCD_0_4   = buf[5] - '0';

    }
    // ֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        UINT8    bcd[10];
        int      i;
        UINT32   uiInt,uiFrac;

        uiInt = 0;
        uiFrac = 0;

        bcd[0] = (UINT8)pf->BCD_0_4;
        bcd[1] = (UINT8)pf->BCD_0_3;
        bcd[2] = (UINT8)pf->BCD_0_2;
        bcd[3] = (UINT8)pf->BCD_0_1;
        bcd[4] = (UINT8)pf->BCD_0;
        bcd[5] = (UINT8)pf->BCD_1;
        bcd[6] = (UINT8)pf->BCD_2;
        bcd[7] = (UINT8)pf->BCD_3;
        bcd[8] = (UINT8)pf->BCD_4;
        bcd[9] = (UINT8)pf->BCD_5;

        for(i = 0; i < 4; i++)
        {
            uiFrac += bcd[i]*ntc_pow(i);
        }

        for ( ; i < 10; i++)
        {
            uiInt += bcd[i]*ntc_pow(i - 4);
        }

        dValue = (DOUBLE)uiInt + (DOUBLE)uiFrac/10000.0;
        *pu = dValue;
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_XXXXXX_XXXX() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_XXXXXX_XX
 ��������  : ���ݸ�ʽ5 ���ڱ�A.5 ��ʽ: (+)XXXXXX.XX
 �������  : eTcTrans eTrans
             float* psUser
             sTcFmt_XXXXXX_XX* psFrame
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_XXXXXX_XX(eTcTrans eTrans, double* psUser, sTcFmt_XXXXXX_XX* psFrame)
{
    sTcFmt_XXXXXX_XX    *psFmtXXXXXX_XX;
    double              *pdXXXXXX_XX;
    psFmtXXXXXX_XX      = (sTcFmt_XXXXXX_XX *)psFrame;
    pdXXXXXX_XX         = (double *)psUser;
    double dXXXXXX_XX   = *pdXXXXXX_XX;

    if(!psFrame || !psUser)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_XXXXXX_XX() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        if(dXXXXXX_XX > 999999.99 || dXXXXXX_XX < -999999.99)
        {
            return TC_ERR_OUTRNG;
        }
        char buf[5] = {0};
        //����ṹ
        psFmtXXXXXX_XX->BCD_5     = (UINT8)(dXXXXXX_XX / ntc_pow(5));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_5 * ntc_pow(5);
        psFmtXXXXXX_XX->BCD_4     = (UINT8)(dXXXXXX_XX / ntc_pow(4));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_4 * ntc_pow(4);
        psFmtXXXXXX_XX->BCD_3     = (UINT8)(dXXXXXX_XX / ntc_pow(3));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_3 * ntc_pow(3);
        psFmtXXXXXX_XX->BCD_2     = (UINT8)(dXXXXXX_XX / ntc_pow(2));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_2 * ntc_pow(2);
        psFmtXXXXXX_XX->BCD_1     = (UINT8)(dXXXXXX_XX / ntc_pow(1));
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_1 * ntc_pow(1);
        psFmtXXXXXX_XX->BCD_0     = (UINT32)dXXXXXX_XX % ntc_pow(1);
        dXXXXXX_XX -= psFmtXXXXXX_XX->BCD_0;
        sprintf(buf,"%2.2f",dXXXXXX_XX);
        psFmtXXXXXX_XX->BCD_0_1   =  buf[2] - '0';
        psFmtXXXXXX_XX->BCD_0_2   =  buf[3] - '0';

     }
     // ֡�ൽ�û���
     else if(TC_TRANS_F2U == eTrans)
     {
        UINT8    bcd[8];
        int      i;
        UINT32   uiInt,uiFrac;

        uiInt = 0;
        uiFrac = 0;

        bcd[0] = (UINT8)psFmtXXXXXX_XX->BCD_0_2;
        bcd[1] = (UINT8)psFmtXXXXXX_XX->BCD_0_1;
        bcd[2] = (UINT8)psFmtXXXXXX_XX->BCD_0;
        bcd[3] = (UINT8)psFmtXXXXXX_XX->BCD_1;
        bcd[4] = (UINT8)psFmtXXXXXX_XX->BCD_2;
        bcd[5] = (UINT8)psFmtXXXXXX_XX->BCD_3;
        bcd[6] = (UINT8)psFmtXXXXXX_XX->BCD_4;
        bcd[7] = (UINT8)psFmtXXXXXX_XX->BCD_5;

        for(i = 0; i < 2; i++)
        {
            uiFrac += bcd[i]*ntc_pow(i);
        }

        for(; i < 8; i++)
        {
            uiInt+= bcd[i]*ntc_pow(i - 2);
        }

        dXXXXXX_XX = (DOUBLE)uiInt + (DOUBLE)uiFrac/100.0;
        *pdXXXXXX_XX = dXXXXXX_XX;
     }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_XXXXXX_XX() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_sXX_XXXX
 ��������  : ���ݸ�ʽ06 ���ڱ�A.6
 �������  : eTcTrans eTrans

 �������  : float* psUser
             sTcFmt06_f* psFrame
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_sXX_XXXX(eTcTrans eTrans, float* psUser, sTcFmt06_f* psFrame)
{
    sTcFmt_sXX_XXXX   *psFmtsXX_XXXX;
    float             *pfXX_XXXX;
    float             fZhengshu;  // ��������

    psFmtsXX_XXXX  = (sTcFmt_sXX_XXXX *)psFrame;
    pfXX_XXXX      = (float *)psUser;
    float fXX_XXXX = *pfXX_XXXX;
    int sign       = 0;
    
    if(!psFrame || !psUser)
    {
       #ifdef TC_DBG
       TCDBG("etc_trans_sXX_XXXX() para pointer is null!");
       #endif
       return TC_ERR_NULL;
    }
    
    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        if(fXX_XXXX > 79.9999f || fXX_XXXX < -79.9999f)
        {
            return TC_ERR_OUTRNG;
        }

        modff(fXX_XXXX * 10000.0f, &fZhengshu);
        sign = ntc_get_float_sign(fZhengshu);
        vtc_set_float_sign(&fZhengshu, 0);

        char buf[8] = {0};
        sprintf(buf, "%06.0lf\n", fZhengshu);

        //����ṹ
        psFmtsXX_XXXX->S       = sign;
        psFmtsXX_XXXX->BCD_1   = buf[0] - '0';
        psFmtsXX_XXXX->BCD_0   = buf[1] - '0';
        psFmtsXX_XXXX->BCD_0_1 = buf[2] - '0';
        psFmtsXX_XXXX->BCD_0_2 = buf[3] - '0';
        psFmtsXX_XXXX->BCD_0_3 = buf[4] - '0';
        psFmtsXX_XXXX->BCD_0_4 = buf[5] - '0';

    }
    // ֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        UINT8    bcd[6];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtsXX_XXXX->BCD_0_4;
        bcd[1] = (UINT8)psFmtsXX_XXXX->BCD_0_3;
        bcd[2] = (UINT8)psFmtsXX_XXXX->BCD_0_2;
        bcd[3] = (UINT8)psFmtsXX_XXXX->BCD_0_1;
        bcd[4] = (UINT8)psFmtsXX_XXXX->BCD_0;
        bcd[5] = (UINT8)psFmtsXX_XXXX->BCD_1;

        for(i = 0; i < 6; i++)
        {
            valid+= bcd[i]*ntc_pow(i);
        }

        fXX_XXXX = valid/10000.0f;
        *pfXX_XXXX = fXX_XXXX * (psFmtsXX_XXXX->S  == 0 ? 1.0f : -1.0f);

    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_sXX_XXXX() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_sXXX_X
 ��������  : ���ݸ�ʽ07 ���ڱ�A.7
             ��ʽ: (+/1)XXX.X
 �������  : eTcTrans eTrans
             float* psUser
             sTcFmt05* psFrame
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_sXXX_X(eTcTrans eTrans, float* psUser, sTcFmt07_f* psFrame)
{
    sTcFmt_sXXX_X    *psFmtsXXX_X;
    float             *pfXXX_X;
    float             fZhengshu;  // ��������

    psFmtsXXX_X    = (sTcFmt07_f *)psFrame;
    pfXXX_X        = (float *)psUser;
    float fXXX_X   = *pfXXX_X;
    int sign       = 0;
    
    if(!psFrame || !psUser)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_sXXX_X() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        if(fXXX_X > 799.9f || fXXX_X < -799.9f)
        {
            return TC_ERR_OUTRNG;
        }

        modff(fXXX_X*10, &fZhengshu);
        sign = ntc_get_float_sign(fZhengshu);
        vtc_set_float_sign(&fZhengshu, 0);

        char buf[8] = {0};
        sprintf(buf, "%04.0lf\n", fZhengshu);

        //����ṹ
        psFmtsXXX_X->S       = sign;
        psFmtsXXX_X->BCD_2   = buf[0] - '0';
        psFmtsXXX_X->BCD_1   = buf[1] - '0';
        psFmtsXXX_X->BCD_0   = buf[2] - '0';
        psFmtsXXX_X->BCD_0_1 = buf[3] - '0';

    }
    // ֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        UINT8    bcd[4];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtsXXX_X->BCD_0_1;
        bcd[1] = (UINT8)psFmtsXXX_X->BCD_0;
        bcd[2] = (UINT8)psFmtsXXX_X->BCD_1;
        bcd[3] = (UINT8)psFmtsXXX_X->BCD_2;

        for(i = 0; i < 4; i++)
        {
            valid+= bcd[i]*ntc_pow(i);
        }

        fXXX_X = valid/10.0f;
        *pfXXX_X = fXXX_X * (psFmtsXXX_X->S == 0 ? 1.0f : -1.0f);
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_sXXX_X() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_XXX_X
 ��������  : ���ݸ�ʽ08 ���ڱ�A.8 ��ʽ: (+)XXX.X
 �������  : eTcTrans eTrans
             float* psUser
             sTcFmt_XXX_X* psFrame
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_XXX_X(eTcTrans eTrans, float* psUser, sTcFmt08_f* psFrame)
{   
    sTcFmt08_f    *psFmtXXX_X;
    float             *pfXXX_X;
    float             fZhengshu;  // ��������

    psFmtXXX_X    = (sTcFmt08_f *)psFrame;
    pfXXX_X        = (float *)psUser;
    float fXXX_X   = *pfXXX_X;
    
    if(!psFrame || !psUser)
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_XXX_X() para pointer is null!");
         #endif
         return TC_ERR_NULL;
    }

    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        if(fXXX_X > 999.9f || fXXX_X < 0.0f)
        {
            return TC_ERR_OUTRNG;
        }

        modff(fXXX_X*10, &fZhengshu);
        vtc_set_float_sign(&fZhengshu, 0);
        char buf[8] = {0};
        sprintf(buf, "%04.0lf\n", fZhengshu);

        //����ṹ
        psFmtXXX_X->BCD_2   = buf[0] - '0';
        psFmtXXX_X->BCD_1   = buf[1] - '0';
        psFmtXXX_X->BCD_0   = buf[2] - '0';
        psFmtXXX_X->BCD_0_1 = buf[3] - '0';

    }
    // ֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        UINT8    bcd[4];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtXXX_X->BCD_0_1;
        bcd[1] = (UINT8)psFmtXXX_X->BCD_0;
        bcd[2] = (UINT8)psFmtXXX_X->BCD_1;
        bcd[3] = (UINT8)psFmtXXX_X->BCD_2;

        for(i = 0; i < 4; i++)
        {
            valid+= bcd[i]*ntc_pow(i);
        }

        fXXX_X   = valid / 10.0f;
        *pfXXX_X = fXXX_X;
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_XXX_X() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_sXXX_XXX
 ��������  : ���ݸ�ʽ09 ���ڱ�A.9 ��ʽ: (+/1)XXX.XXX
 �������  : eTcTrans eTrans
             float* psUser
             sTcFmt_sXXX_XXX* psFrame
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_sXXX_XXX(eTcTrans eTrans, float* psUser, sTcFmt_sXXX_XXX* psFrame)
{
    sTcFmt_sXXX_XXX   *psFmtsXXX_XXX;
    float             *pfXXX_XXX;
    float             fZhengshu;  // ��������

    psFmtsXXX_XXX  = (sTcFmt_sXXX_XXX *)psFrame;
    pfXXX_XXX      = (float *)psUser;
    float fXXX_XXX = *pfXXX_XXX;
    int sign       = 0;
    
    if(!psFrame || !psUser)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_sXXX_XXX() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        if(fXXX_XXX > 799.999f || fXXX_XXX < -799.999f)
        {
            return TC_ERR_OUTRNG;
        }

        modff(fXXX_XXX*1000.0f, &fZhengshu);
        sign = ntc_get_float_sign(fZhengshu);     // ��÷���λ
        vtc_set_float_sign(&fZhengshu, 0);        // ����Ϊ��

        char buf[8] = {0};
        sprintf(buf, "%06.0lf\n", fZhengshu);

        //����ṹ
        psFmtsXXX_XXX->S       = sign;
        psFmtsXXX_XXX->BCD_2   = buf[0] - '0';
        psFmtsXXX_XXX->BCD_1   = buf[1] - '0';
        psFmtsXXX_XXX->BCD_0   = buf[2] - '0';
        psFmtsXXX_XXX->BCD_0_1 = buf[3] - '0';
        psFmtsXXX_XXX->BCD_0_2 = buf[4] - '0';
        psFmtsXXX_XXX->BCD_0_3 = buf[5] - '0';
     }
     // ֡�ൽ�û���
     else if(TC_TRANS_F2U == eTrans)
     {
        UINT8    bcd[6];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)psFmtsXXX_XXX->BCD_0_3;
        bcd[1] = (UINT8)psFmtsXXX_XXX->BCD_0_2;
        bcd[2] = (UINT8)psFmtsXXX_XXX->BCD_0_1;
        bcd[3] = (UINT8)psFmtsXXX_XXX->BCD_0;
        bcd[4] = (UINT8)psFmtsXXX_XXX->BCD_1;
        bcd[5] = (UINT8)psFmtsXXX_XXX->BCD_2;

        for(i = 0; i < 6; i++)
        {
            valid+= bcd[i]*ntc_pow(i);
        }

        fXXX_XXX = valid/1000.0f;
        *pfXXX_XXX = fXXX_XXX * (psFmtsXXX_XXX->S  == 0 ? 1.0f : -1.0f);

    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_sXXX_XXX() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_XXX_X
 ��������  : ���ݸ�ʽ10 ���ڱ�A.10 ��ʽ: (+)XXX.X
 �������  : eTcTrans eTrans

 �������  : float* psUser
             sTcFmt10_f* psFrame
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_XX_XX(eTcTrans eTrans, float* psUser, sTcFmt10_f* psFrame)
{
    sTcFmt_XX_XX    *pf;
    float             *pu;
    float             fZhengshu;  // ��������

    pf    = (sTcFmt_XX_XX *)psFrame;
    pu        = (float *)psUser;
    float fXX_XX   = *pu;

    if(!psFrame || !psUser)
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_XX_XX() para pointer is null!");
         #endif
         return TC_ERR_NULL; 
    }    

    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        if(fXX_XX > 99.99f || fXX_XX < 0.0f)
        {
            return TC_ERR_OUTRNG;
        }

        modff(fXX_XX*100, &fZhengshu);
        vtc_set_float_sign(&fZhengshu, 0);
        char buf[8] = {0};
        sprintf(buf, "%04.0lf\n", fZhengshu);

        //����ṹ
        pf->BCD_1   = buf[0] - '0';
        pf->BCD_0   = buf[1] - '0';
        pf->BCD_0_1 = buf[2] - '0';
        pf->BCD_0_2 = buf[3] - '0';

    }
    // ֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        UINT8    bcd[4];
        int      i;
        float    valid = 0.0f;
        bcd[0] = (UINT8)pf->BCD_0_2;
        bcd[1] = (UINT8)pf->BCD_0_1;
        bcd[2] = (UINT8)pf->BCD_0;
        bcd[3] = (UINT8)pf->BCD_1;

        for(i = 0; i < 4; i++)
        {
            valid+= bcd[i]*ntc_pow(i);
        }

        fXX_XX   = valid / 100.0f;
        *pu = fXX_XX;
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_XX_XX() para error!");
        #endif
        return TC_ERR_PARA;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_sX7
 ��������  : ���ݸ�ʽ11 ���ڱ�A.11
             ��ʽ: (+/1)XXXXXXX (10(-3)~10(4))
 �������  : eTcTrans eTrans
             void* psUser
             void* psFrame
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��23�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_sX7(eTcTrans eTrans, void* psUser, void* psFrame)
{
    int        valid  = 0;     
    int        sign   = 0;     
    int        i      = 0;
    int        index  = 6; 
    UINT8      bcd[8] = {0};
    UINT8      ucS    = 0;
    UINT8      ucG1   = 0;
    UINT8      ucG2   = 0;
    UINT8      ucG3   = 0;
    UINT8     ucSG123 = 0;
    double    dTmp    = 0.0;   
    double  dZhengshu = 0.0;     // ��������
    
    sTcFmt11_f  *pf = (sTcFmt11_f*)psFrame;
    sTcFmt11    *pu = (sTcFmt11*)psUser;
    
    if(!psFrame || !psUser)
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_sX7() para pointer is null!");
         #endif
         return TC_ERR_NULL;
    }    

    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        dTmp = pu->dValue;
        
        switch(pu->ePrec)
        {
            case TC_PREC_P4:    
                {
                    if(dTmp == 0.0 || 
                      (dTmp >=  10000.0 && dTmp <=  99999990000.0) ||
                      (dTmp <= -10000.0 && dTmp >= -99999990000.0))
                      {
                          modf(dTmp/10000, &dZhengshu);
                          sign = ntc_get_double_sign(dZhengshu);
                          vtc_set_double_sign(&dZhengshu, 1);
     
                          ucS  = sign;
                          ucG1 = 0;
                          ucG2 = 0;
                          ucG3 = 0;
                      }
                      else
                      {
                          #ifdef TC_DBG
                          TCDBG("etc_trans_sX7() para TC_PREC_P4 is out of range!");
                          #endif
                          return TC_ERR_OUTRNG;
                      } 
                }
                break;
                
            case TC_PREC_P3:    
                {
                    if(dTmp == 0.0 || 
                      (dTmp >=  1000.0 && dTmp <=  9999999000.0) ||
                      (dTmp <= -1000.0 && dTmp >= -9999999000.0))
                      {
                          modf(dTmp/1000, &dZhengshu);
                          sign = ntc_get_double_sign(dZhengshu);
                          vtc_set_double_sign(&dZhengshu, 1);
     
                          ucS  = sign;
                          ucG1 = 1;
                          ucG2 = 0;
                          ucG3 = 0;
                      }
                      else
                      {
                          #ifdef TC_DBG
                          TCDBG("etc_trans_sX7() para TC_PREC_P4 is out of range!");
                          #endif
                          return TC_ERR_OUTRNG;
                      } 
                }
                break;
            
            case TC_PREC_P2:    
                {
                    if(dTmp == 0.0 || 
                      (dTmp >=  100.0 && dTmp <=  999999900.0) ||
                      (dTmp <= -100.0 && dTmp >= -999999900.0))
                      {
                          modf(dTmp/100, &dZhengshu);
                          sign = ntc_get_double_sign(dZhengshu);
                          vtc_set_double_sign(&dZhengshu, 1);
     
                          ucS  = sign;
                          ucG1 = 0;
                          ucG2 = 1;
                          ucG3 = 0;
                      }
                      else
                      {
                          #ifdef TC_DBG
                          TCDBG("etc_trans_sX7() para TC_PREC_P4 is out of range!");
                          #endif
                          return TC_ERR_OUTRNG;
                      } 
                }
                break;
            
            case TC_PREC_P1:    
                {
                    if(dTmp == 0.0 || 
                      (dTmp >=  10.0 && dTmp <=  99999990.0) ||
                      (dTmp <= -10.0 && dTmp >= -99999990.0))
                      {
                          modf(dTmp/10, &dZhengshu);
                          sign = ntc_get_double_sign(dZhengshu);
                          vtc_set_double_sign(&dZhengshu, 1);
     
                          ucS  = sign;
                          ucG1 = 1;
                          ucG2 = 1;
                          ucG3 = 0;
                      }
                      else
                      {
                          #ifdef TC_DBG
                          TCDBG("etc_trans_sX7() para TC_PREC_P4 is out of range!");
                          #endif
                          return TC_ERR_OUTRNG;
                      } 
                }
                break;
                
            case TC_PREC_P0:    
                {
                    if(dTmp == 0.0 || 
                      (dTmp >=  1.0 && dTmp <=  9999999.0) ||
                      (dTmp <= -1.0 && dTmp >= -9999999.0))
                      {
                          modf(dTmp, &dZhengshu);
                          sign = ntc_get_double_sign(dZhengshu);
                          vtc_set_double_sign(&dZhengshu, 1);
     
                          ucS  = sign;
                          ucG1 = 0;
                          ucG2 = 0;
                          ucG3 = 1;
                      }
                      else
                      {
                          #ifdef TC_DBG
                          TCDBG("etc_trans_sX7() para TC_PREC_P0 is out of range!");
                          #endif
                          return TC_ERR_OUTRNG;
                      } 
                }
                break;            

            case TC_PREC_N1:    
                {
                    if(dTmp == 0.0 || 
                      (dTmp >=  0.1 && dTmp <=  999999.9) ||
                      (dTmp <= -0.1 && dTmp >= -999999.9))
                      {
                          modf(dTmp * 10, &dZhengshu);
                          sign = ntc_get_double_sign(dZhengshu);
                          vtc_set_double_sign(&dZhengshu, 1);
     
                          ucS  = sign;
                          ucG1 = 1;
                          ucG2 = 0;
                          ucG3 = 1;
                      }
                      else
                      {
                          #ifdef TC_DBG
                          TCDBG("etc_trans_sX7() para TC_PREC_N1 is out of range!");
                          #endif
                          return TC_ERR_OUTRNG;
                      } 
                }
                break;  
                
            case TC_PREC_N2:    
                {
                   if(dTmp == 0.0 || 
                     (dTmp >=  0.01 && dTmp <=  99999.99) ||
                     (dTmp <= -0.01 && dTmp >= -99999.99))
                     {
                         modf(dTmp * 100, &dZhengshu);
                         sign = ntc_get_double_sign(dZhengshu);
                         vtc_set_double_sign(&dZhengshu, 1);
    
                         ucS  = sign;
                         ucG1 = 0;
                         ucG2 = 1;
                         ucG3 = 1;
                     }
                     else
                     {
                         #ifdef TC_DBG
                         TCDBG("etc_trans_sX7() para TC_PREC_N2 is out of range!");
                         #endif
                         return TC_ERR_OUTRNG;
                     } 
                }
                break;  
                
            case TC_PREC_N3:    
                {
                    if(dTmp == 0.0 || 
                      (dTmp >=  0.001 && dTmp <=  9999.999) ||
                      (dTmp <= -0.001 && dTmp >= -9999.999))
                      {
                          modf(dTmp * 1000, &dZhengshu);
                          sign = ntc_get_double_sign(dZhengshu);
                          vtc_set_double_sign(&dZhengshu, 1);
     
                          ucS  = sign;
                          ucG1 = 1;
                          ucG2 = 1;
                          ucG3 = 1;
                      }
                      else
                      {
                          #ifdef TC_DBG
                          TCDBG("etc_trans_sX7() para TC_PREC_N3 is out of range!");
                          #endif
                          return TC_ERR_OUTRNG;
                      } 
                }
            
                break;  

            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_sX7() para ePrec is out of range!");
                #endif
                return TC_ERR_OUTRNG;
                //break;
        }

        ucSG123 = ucS | (ucG1 << 1) | (ucG2 << 2) | (ucG3 << 3);

        char bcd[8] = {0};
        sprintf(bcd, "%07.0lf\n", dZhengshu);

        pf->BCD_0 = bcd[index - 0] - '0';
        pf->BCD_1 = bcd[index - 1] - '0';
        pf->BCD_2 = bcd[index - 2] - '0';
        pf->BCD_3 = bcd[index - 3] - '0';
        pf->BCD_4 = bcd[index - 4] - '0';
        pf->BCD_5 = bcd[index - 5] - '0';
        pf->BCD_6 = bcd[index - 6] - '0';
        pf->SG123 = ucSG123;

        #ifdef TC_DBG
        TCDBG("etc_trans_sX7() ucSG123 = %02X\n", ucSG123);
        #endif
    }
    // ֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        bcd[0]  = (UINT8) pf->BCD_0;
        bcd[1]  = (UINT8) pf->BCD_1;
        bcd[2]  = (UINT8) pf->BCD_2;
        bcd[3]  = (UINT8) pf->BCD_3;
        bcd[4]  = (UINT8) pf->BCD_4;
        bcd[5]  = (UINT8) pf->BCD_5;
        bcd[6]  = (UINT8) pf->BCD_6;
        
        ucSG123 = pf->SG123;
        sign = (ucSG123 & 0x01) ? -1 : 1;
        ucG1 = (ucSG123 & 0x02) ?  1 : 0;
        ucG2 = (ucSG123 & 0x04) ?  1 : 0;
        ucG3 = (ucSG123 & 0x08) ?  1 : 0;
        
        for(i = 0; i < 7; i++)
        {
            if(bcd[i] > 9)
            {
                 #ifdef TC_DBG
                 TCDBG("etc_trans_sX7() bcd is out of range");
                 #endif
                 return TC_ERR_OUTRNG;
            }
        }

        for(i = 0; i < 7; i++)
        {
            valid += bcd[i] * ntc_pow(i);
        }


        if(ucG3 == 0)
        {
            if(ucG2 == 0 && ucG1 == 0)
            {
                dTmp = 10000.0;  // 4.0
                pu->ePrec = TC_PREC_P4;
            }

            if(ucG2 == 0 && ucG1 == 1)
            {
                dTmp = 1000.0;   // 3.0
                pu->ePrec = TC_PREC_P3;
            }

            if(ucG2 == 1 && ucG1 == 0)
            {
                dTmp = 100.0;    // 2.0
                pu->ePrec = TC_PREC_P2;

            }

            if(ucG2 == 1 && ucG1 == 1)
            {
                dTmp = 10.0;     // 1.0
                pu->ePrec = TC_PREC_P1;
            }

        }
        else
        {
            if(ucG2 == 0 && ucG1 == 0)
            {
                 dTmp = 1.0;     // 0.0
                 pu->ePrec = TC_PREC_P0;
            }

            if(ucG2 == 0 && ucG1 == 1)
            {
                 dTmp = 0.1;   // -1.0
                 pu->ePrec = TC_PREC_N1;
            }

            if(ucG2 == 1 && ucG1 == 0)
            {
                 dTmp = 0.01;  // -2.0 
                 pu->ePrec = TC_PREC_N2;
            }

            if(ucG2 == 1 && ucG1 == 1)
            {
                dTmp = 0.001;
                pu->ePrec = TC_PREC_N3;
            }
        }

        pu->dValue = sign * valid * dTmp;

    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_sX7() para error!");
        #endif
        return TC_ERR_PARA;
    }
        
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_ip
 ��������  : IP��ַת������
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��6��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_ip(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcIp   *pu = (sTcIp*)pUser;
    sTcIp_f *pf = (sTcIp_f*)pFrame;
    INT32     i = 0;

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_ip() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

     // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {   
        // ucVersion
        switch(pu->eVersion)
        {
            case TC_IP_V4:
            pf->ucVersion = 1;
            break;

            case TC_IP_V6:
            pf->ucVersion = 2;
            break;

            default:
            #ifdef TC_DBG
            TCDBG("etc_trans_ip() eVersion is error!");
            #endif
            return TC_ERR_PARA;
            //break;
        }

        // ip
        for(i = 0; i < TC_IP_LEN; i++)
        {
            pf->ip[i] = pu->ip[TC_IP_LEN - i - 1];
        }
        
    }
    // ��֡�ൽ�û���
    else
    {   
        // ucVersion
        switch(pf->ucVersion)
        {
            case 1:
            pu->eVersion = TC_IP_V4;
            break;

            case 2:
            pu->eVersion = TC_IP_V6;
            break;

            default:
            #ifdef TC_DBG
            TCDBG("etc_trans_ip() ucVersion is error %d!", pf->ucVersion);
            #endif
            return TC_ERR_PARA;
            //break;
        }

        // ip
        for(i = 0; i < TC_IP_LEN; i++)
        {
            pu->ip[i] = pf->ip[TC_IP_LEN - i - 1];
        }
    }

    * pusLen = TC_IP_LEN + 1;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_version
 ��������  : ���Ӳ���汾��Ϣת������
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_version(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr      eRet = TC_OK;
    sTcVersion   *pu = NULL;
    sTcVersion_f *pf = NULL;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_version() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcVersion*)pUser;
    pf = (sTcVersion_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        memcpy(pf->strFactory, pu->strFactory, 4);
        memcpy(pf->strDevId,   pu->strDevId,   4);
        memcpy(pf->strHard,    pu->strHard,    4);
        memcpy(pf->strSoft,    pu->strSoft,    4);
        memcpy(pf->strProto,   pu->strProto,  16);
        memcpy(pf->strVolume,  pu->strVolume, 16);

        eRet = etc_str_to_bcd(pu->strAddr, pf->strAddr, 16);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_version() etc_str_to_bcd() error %d!", eRet);
            #endif
            return eRet;
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        memcpy(pu->strFactory, pf->strFactory, 4);
        memcpy(pu->strDevId,   pf->strDevId,   4);
        memcpy(pu->strHard,    pf->strHard,    4);
        memcpy(pu->strSoft,    pf->strSoft,    4);
        memcpy(pu->strProto,   pf->strProto,  16);
        memcpy(pu->strVolume,  pf->strVolume, 16);

        eRet = etc_bcd_to_str(pf->strAddr, pu->strAddr, 8);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_version() etc_bcd_to_str() error %d!", eRet);
            #endif
            return eRet;
        }
    }
    else
    {

        #ifdef TC_DBG
        TCDBG("etc_trans_version() para eTrans is out of range!");
        #endif
        return TC_ERR_OUTRNG;
    }

    // sTimeHard
    eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTimeHard), &(pf->sTimeHard));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_version() etc_trans_YYMMDDhhmm() error %d!", eRet);
        #endif
        return eRet;
    }
    
    // sTimeSoft
    eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTimeSoft), &(pf->sTimeSoft));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_version() etc_trans_YYMMDDhhmm() error %d!", eRet);
        #endif
        return eRet;
    }

    * pusLen = sizeof(sTcVersion_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn00f1
 ��������  : TCMD_AFN_0_F1_ALL_OK_DENY ��Ӧ�����ݽṹת������
 �������  : eTcTrans eTrans       
                
 �������  : eTcResCode *peResCode  
             UINT8* pucResCode  
             UINT16* pusLen  ��֡����ֳ�
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��1��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn00f1(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{   
    UINT8      ucResCode  = 0;
    eTcResCode eResCode   = TC_RES_OK;
    eTcResCode      *pU   = NULL;
    UINT8           *pF   = NULL;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn00f1() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pU = (eTcResCode*)pUser;
    pF = (UINT8 *)pFrame;
    

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {   
        eResCode = *pU;
        switch(eResCode)   
        {
           case TC_RES_OK:
           case TC_RES_NONE:
           case TC_RES_NOT_READY:
           case TC_RES_REMOVE:
           case TC_RES_DATA_OTRNG:
           case TC_RES_PARA_OTRNG:
           case TC_RES_NOT_SAME:          
           case TC_RES_NOT_SUPT:
           case TC_RES_DENY:  
               break;
               
           default:
               #ifdef TC_DBG
               TCDBG("etc_trans_afn00f1() eResCode is error %d", eResCode);
               #endif
               return TC_ERR_PARA;
               //break;
        }

        ucResCode  = (UINT8)eResCode;
        *pF        = ucResCode;

    }
    // ��֡�ൽ�û���
    else
    {
        ucResCode = *pF;
        switch(ucResCode)   
        {
           case TC_RES_OK:
           case TC_RES_NONE:
           case TC_RES_NOT_READY:
           case TC_RES_REMOVE:
           case TC_RES_DATA_OTRNG:
           case TC_RES_PARA_OTRNG:
           case TC_RES_NOT_SAME:          
           case TC_RES_NOT_SUPT:
           case TC_RES_DENY:  
               break;
               
           default:
               #ifdef TC_DBG
               TCDBG("etc_trans_afn00f1() ucResCode is error %d", ucResCode);
               #endif
               return TC_ERR_PARA;
               //break;
        }
        
        eResCode = (eTcResCode)ucResCode;
        *pU      = eResCode;
    }

    // �����֡����ֳ�
    *pusLen = sizeof(UINT8);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn00f2
 ��������  : TCMD_AFN_0_F2_ONE_BY_ONE ��Ӧ�����ݽṹת������
 �������  : eTcTrans eTrans       
                
 �������  : eTcResCode *peResCode  
             UINT8* pucResCode  
             UINT16* pusLen  ��֡����ֳ�
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��1��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn00f2(eTcTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen)
{
    INT32       i         = 0;
    INT32       j         = 0;
    INT32       k         = 0;
    INT32       fi        = 0;
    INT32       pi        = 0;
    INT32       nNum      = 0;  
    INT32       nDaDtNum  = 0;      // ��װpackbase����Ϣ��ʶ��64�����ݵ�Ԫ����ܸ���
    INT32       nDaDtPos  = 0;      // ÿ��Ӧ����packbase����Ϣ��ʶ�������
    INT32       nCyc      = 0;
    UINT16      usCMD     = 0;
    UINT16      usPn      = 0;
    UINT8       ucFn      = 0;
    eTcErr      eRet      = TC_OK;
    eTcmd       eCmd      = TCMD_AFN_F_UNKOWN;
    eTcAFN      eAFN      = TC_AFN_NULL;
    eTcAFN      eAFNCmd   = TC_AFN_NULL;
    eTcResCode  eResCode  = TC_RES_OK;
    BOOL        bFindDaDt = FALSE;  // �Ƿ��ҵ�֮ǰ���ڵ���
    BOOL        bP0       = FALSE;
    UINT8*      pMem      = NULL;
    sTcFnPnErr* psFnPnErr = NULL;
    sTcOneByOne_f     *pf = NULL;
    sTcOnebyOne       *pu = NULL;
    sTcPnFn     sPnFn;
    #define     TC_TEAM_MAX  (50)   // ���ܵ��������

    if(!psFrame || !psUser || !pusfLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn00f2() pointer is null");
        #endif
        return TC_ERR_NULL;
    }

    memset(&(sPnFn), 0x00, sizeof(sTcPnFn));
    pf = (sTcOneByOne_f *)psFrame;
    pu = (sTcOnebyOne   *)psUser;

    // ֡��תΪ�û���
    if(TC_TRANS_F2U == eTrans)
    {
        // ����ʱ����Ӧ�ò����ݳ���
        nNum = (int)*pusfLen;
        nNum -= sizeof(UINT8);
        nNum /= sizeof(sTcOne_f); // ���㺬��ȷ�Ϸ��ϸ���

        if(nNum > TC_FN_MAX)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn00f2() TC_ERR_OUTRNG");
            #endif
            return TC_ERR_OUTRNG;
        }

        eAFN = (eTcAFN)pf->ucAFN;
        pu->eAFN = eAFN;
        for(i = 0; i < nNum; i++)
        {
            switch(pf->sOne[i].ucErr)   
            {
               case TC_RES_OK:
               case TC_RES_NONE:
               case TC_RES_NOT_READY:
               case TC_RES_REMOVE:
               case TC_RES_DATA_OTRNG:
               case TC_RES_NOT_SAME:          
               case TC_RES_NOT_SUPT:
               case TC_RES_DENY:  
                   break;
                   
               default:
                   #ifdef TC_DBG
                   TCDBG("etc_trans_afn00f1() ucResCode is error %d", pf->sOne[i].ucErr);
                   #endif
                   return TC_ERR_PARA;
                   //break;
            }

            eResCode = (eTcResCode)(pf->sOne[i].ucErr);
            eRet = etc_dadt_to_pnfn(&(pf->sOne[i].sDaDt), &sPnFn);
            if(eRet != TC_OK)
            {   
                #ifdef TC_DBG
                TCDBG("Error:etc_dadt_to_pnfn() error = %d %s\n", eRet, stcGetErr(eRet));
                #endif
                return eRet;
            }

            // �Ƿ�Ϊp0�����
            bP0 = btc_is_p0(sPnFn.usPn);
            if(TRUE == bP0)
            {
                nCyc = 1;
            }
            else
            {
                nCyc = TC_PN_INDEX_MAX;
            }
            
            for(pi = 0; pi < nCyc; pi++)
            {
                if(TC_PN_NONE != sPnFn.usPn[pi])
                {
                    for(fi = 0; fi < TC_FN_INDEX_MAX; fi++)
                    {
                        if(TC_FN_NONE != sPnFn.ucFn[fi])
                        { 
                            usCMD = (UINT16)((eAFN << 8) | sPnFn.ucFn[fi]);
                            eCmd  = (eTcmd)usCMD; 
                            pu->sOne[j].eResCode = eResCode;
                            pu->sOne[j].usPn = sPnFn.usPn[pi];
                            pu->sOne[j].eCmd = eCmd;
                            j++;
                        }
                    }
                }            
            }
        }

        pu->ucNum = j;
        nDaDtNum = nNum;
        
    }
    else 
    // �û���תΪ֡��
    {
        eAFN = pu->eAFN;
        pf->ucAFN  = (UINT8)pu->eAFN;

        pMem = (UINT8*)malloc(sizeof(sTcFnPnErr) * TC_TEAM_MAX);
        if(!pMem)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn00f2() TC_ERR_IO");
            #endif
            return TC_ERR_IO;
        }
            
        psFnPnErr = (sTcFnPnErr*)pMem;
            
        for(i = 0; i < pu->ucNum; i++)
        {
            // �жϸ������Ƿ�����AFN��������
            eAFNCmd = eTcGetCmdAfn(pu->sOne[i].eCmd);
            if(eAFNCmd != eAFN)  
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn00f2() cmd is not is a same Afn ");
                TCDBG("eAFNCmd = %d", eAFNCmd);
                TCDBG("eAFN = %d", eAFN);
                TCDBG("eCmd[%d] = %04X",i,  pu->sOne[i].eCmd);
                #endif
                TC_FREE(pMem);
                return TC_ERR_TEAM;
            }

            usPn      = pu->sOne[i].usPn;
            ucFn      = ucTcGetCmdFn(pu->sOne[i].eCmd);
            eResCode  = pu->sOne[i].eResCode;

            /*
                �жϸúϷ������ݵ�Ԫ��ʶ,�����ݵ�Ԫ�Ƿ��Ѿ�����Ӧ��λ�� psBasePack
                ����ظ�,���߸���ǰ��,Da2 �벻ͬ��Dt2���, 
                �������ͬ�ı�ʶ�����ݵ�Ԫ��,����nDaTaNum�ĸ���
                
            */
            
            nDaDtPos = nDaDtNum;
            // ��ʼ��PnFn��
            for(k = 0; k < 8; k++)
            {
                psFnPnErr[nDaDtPos].sPnFn.ucFn[k] = TC_FN_NONE;
                psFnPnErr[nDaDtPos].sPnFn.usPn[k] = TC_PN_NONE;
            }
            
            if(nDaDtPos > TC_TEAM_MAX)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn00f2() TC_TEAM_MAX too small");
                #endif
                TC_FREE(pMem);
                return TC_ERR_OUTRNG;
            }
            
            for(j = 0; j < nDaDtNum; j++)
            {
                // �ҵ���nDataPos���ҵ���λ��
                // ���ж�Pn�Ƿ���ͬһ��
                UINT8 ucTeamPn     = 0xFF;
                UINT8 ucTeamPnBase = 0xFF;
                ucTeamPn     = uctc_get_pn_team(usPn);
                ucTeamPnBase = uctc_get_pn8_team(psFnPnErr[j].sPnFn.usPn);
                
                if(ucTeamPn == ucTeamPnBase)
                {
                    // ���ж�Fn�Ƿ�����ͬһ����
                    UINT8 ucTeamFn     = 0xFF;
                    UINT8 ucTeamFnBase = 0xFF;
                    ucTeamFn     = uctc_get_fn_team(ucFn);
                    ucTeamFnBase = uctc_get_fn8_team(psFnPnErr[j].sPnFn.ucFn);

                    if(ucTeamFn == ucTeamFnBase)
                    {
                        BOOL bInFn8 = btc_in_fn8(ucFn, psFnPnErr[j].sPnFn.ucFn);
                        if((eResCode == psFnPnErr[j].eResCode) && (TRUE == bInFn8))
                        {
                            bFindDaDt = TRUE;
                            nDaDtPos  = j;
                            break;
                        }   
                    }
                }
            }

            // δ�ҵ���nDaTaNum++
            if(FALSE == bFindDaDt)
            {
                nDaDtNum  += 1; // ����һ��  
            }
            
            // ���� DaTa�鼰���ݵ�Ԫ
            if(0 == usPn)
            {
                pi = 0;
                for(k = 0; k < 8; k++)
                {
                    psFnPnErr[nDaDtPos].sPnFn.usPn[k] = 0;
                }
            }
            else
            {
                pi = (usPn - 1) % 8; 
                psFnPnErr[nDaDtPos].sPnFn.usPn[pi] = usPn;
            }
          
            fi = (ucFn - 1) % 8;
            psFnPnErr[nDaDtPos].sPnFn.ucFn[fi] = ucFn;

            // ���ݵ�Ԫ
            psFnPnErr[j].eResCode = eResCode;
            
            // ����δ�ҵ�״̬
            bFindDaDt = FALSE;
        }

        //sTcFnPnErr ʵ�� sTcOne_f ת��
        for(i = 0; i < nDaDtNum; i++)
        {
            eRet = etc_pnfn_to_dadt(&psFnPnErr[i].sPnFn, &(pf->sOne[i].sDaDt));
            if(eRet != TC_OK)
            {
                 #ifdef TC_DBG
                 TCDBG("Error:etc_pnfn_to_dadt() error = %d %s\n", eRet, stcGetErr(eRet));
                 #endif
                 return eRet;
            }
                    
            // right or error
            pf->sOne[i].ucErr = psFnPnErr[i].eResCode == TRUE ? 0 : 1;
        }

        TC_FREE(pMem);
     }

    // ������֡����ֽڳ���
    *pusfLen = sizeof(UINT8) + sizeof(sTcOne_f) * nDaDtNum;
 
    return TC_OK;
}   

/*****************************************************************************
 �� �� ��  : etc_trans_afn01f5
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_1_F5_DATA_CLEAR
 ����˵��  : ������������ AFN Ӧ��ΪTC_AFN_13_ASKR 
             ��ʵʱ���ݵ����ݵ�Ԫ��ʶ
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��5��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn01f5(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{   
    eTcErr        eRet = TC_OK;
    eTcAFN        eAfn = TC_AFN_NULL;
    UINT8     ucNumCmd = 0;
    UINT8    ucNumDaDt = 0;
    sTcAfn01f5   *pu  = NULL;
    sTcAfn01f5_f *pf  = NULL;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn01f5() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn01f5   *)pUser;
    pf = (sTcAfn01f5_f *)pFrame;
    
    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {   
        eAfn = eTcGetCmdAfn(pu->sCmdPn[0].eCmd);
        if(TC_AFN_13_ASKR != eAfn)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn01f5() afn is not TC_AFN_13_ASKR  %d!", eAfn);
            #endif
            return TC_ERR_PARA; 
        }

        eRet = etc_cmdpn_to_dadt(TC_AFN_13_ASKR, &(pf->sDaDt[0]), &ucNumDaDt, &(pu->sCmdPn[0]), pu->ucNum);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn01f5() etc_cmdpn_to_dadt() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->ucNum = ucNumDaDt;
    }
    // ��֡�ൽ�û���
    else
    {   
        eRet = etc_dadt_to_cmdpn(TC_AFN_13_ASKR, &(pf->sDaDt[0]), pf->ucNum, &(pu->sCmdPn[0]), &ucNumCmd);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn01f5() etc_cmdpn_to_dadt() error %d!", eRet);
            #endif
            return eRet;
        }
        
        ucNumDaDt = pf->ucNum;
        pu->ucNum = ucNumCmd;
    }

    // �����֡����ֳ�
    *pusLen = sizeof(sTcDaDt) * ucNumDaDt + 1;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f1
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F1_CON_IP_PORT
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��11��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f1(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr      eRet = TC_OK;
    sTcAfn04f1_f *pf = NULL;
    sTcAfn04f1   *pu = NULL;
    UINT16     usLen = 0;

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f1() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pf = (sTcAfn04f1_f*)pFrame;
    pu = (sTcAfn04f1  *)pUser;

    if(TC_TRANS_U2F == eTrans)
    {
        pf->usMainPort  = pu->usMainPort;
        pf->usBackPort  = pu->usBackPort; 
        memcpy(pf->ucAPN, pu->ucAPN, TC_APN_LEN); 
        memcpy(pf->ucUsr, pu->ucUsr, 32);
        memcpy(pf->ucPwd, pu->ucPwd, 32);
    }
    else if(TC_TRANS_F2U == eTrans)
    {
        pu->usMainPort  = pf->usMainPort;
        pu->usBackPort  = pf->usBackPort;  
        memcpy(pu->ucAPN, pf->ucAPN, TC_APN_LEN); 
        memcpy(pu->ucUsr, pf->ucUsr, 32);
        memcpy(pu->ucPwd, pf->ucPwd, 32);
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f1() para eTrans is out of range!");
        #endif
        return TC_ERR_OUTRNG;
    }

    // sMainIp
    eRet = etc_trans_ip(eTrans, &(pu->sMainIp), &(pf->sMainIp), &usLen);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("XXetc_trans_afn04f1() etc_trans_ip() error %d!", eRet);
        #endif
        return eRet;
    }

    // sBackIp
    eRet = etc_trans_ip(eTrans, &(pu->sBackIp), &(pf->sBackIp), &usLen);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("XXetc_trans_afn04f1() etc_trans_ip() error %d!", eRet);
        #endif
        return eRet;
    } 

    // ���֡�೤��
    *pusLen = sizeof(sTcAfn04f1_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f2
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F2_TML_UP_CFG
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��12��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f2(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr            eRet = TC_OK;
    UINT16           usLen = 0;
    UINT16        usTmpLen = 0;
    UINT8        *pucSWTS1 = NULL;   
    UINT8        *pucSWTS2 = NULL;  
    UINT8         *pbs8Con = NULL;    
    UINT8    *pucHeartBeat = NULL;   
    sTcAfn04f2_f       *pf = NULL;
    sTcAfn04f2         *pu = NULL; 
    UINT8            *pTmp = NULL;
    UINT8 *pucPermitDelayM = NULL;   
    sTcIp_f          sIp_f;    
 
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f2() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pf = (sTcAfn04f2_f*)pFrame;
    pu = (sTcAfn04f2  *)pUser;
    memset(&sIp_f, 0, sizeof(sTcIp_f));

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {   
        // usListenPort
        pf->usListenPort = pu->usListenPort;
        usLen += sizeof(UINT16);
        
        // sUpIp
        eRet = etc_trans_ip(eTrans, &(pu->sUpIp), &sIp_f, &usTmpLen);
        if(eRet != TC_OK)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() etc_trans_ip() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->sUpIp = sIp_f;
        usLen += usTmpLen;

        // sUpMask
        eRet = etc_trans_ip(eTrans, &(pu->sUpMask), &sIp_f, &usTmpLen);
        if(eRet != TC_OK)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() etc_trans_ip() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->sUpMask = sIp_f;
        usLen += usTmpLen;

        // sGateIp
        eRet = etc_trans_ip(eTrans, &(pu->sGateIp), &sIp_f, &usTmpLen);
        if(eRet != TC_OK)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() etc_trans_ip() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->sGateIp = sIp_f;
        usLen += usTmpLen;

        // eDelegate
        switch(pu->eDelegate)
        {
            case TC_DELG_NULL:
                pf->ucDelegate = 0;
                break;
                
            case TC_DELG_HTTP:
                pf->ucDelegate = 1;
                break;
                
            case TC_DELG_SOCK4:
                pf->ucDelegate = 2;
                break;
                
            case TC_DELG_SOCK5:
                pf->ucDelegate = 3;
                break;

            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f2() para eDelegate is error!");
                #endif
                return TC_ERR_PARA;
                //break;
        }

        usLen += sizeof(UINT8);

        // sDelgIp
        eRet = etc_trans_ip(eTrans, &(pu->sDelgIp), &sIp_f, &usTmpLen);
        if(eRet != TC_OK)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() etc_trans_ip() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->sDelgIp = sIp_f;
        usLen += usTmpLen;

        // usDelgPort
        pf->usDelgPort = pu->usDelgPort;
        usLen += sizeof(UINT16);

        // eDelgLink
        if(TC_DELK_ANYONE == pu->eDelgLink)
        {
            pf->ucDelgLink = 0;
        }
        else if(TC_DELK_USRPWD == pu->eDelgLink)
        {
            pf->ucDelgLink = 1;
        }
        else
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() eDelgLink para error %d!", pu->eDelgLink);
            #endif
            return TC_ERR_PARA;
        }
        
        usLen += 1;

        // bDlegUsr
        pTmp = &(pf->ucUsrLen);
        if(TRUE == pu->bDlegUsr)
        {
            if(0 == pu->ucDlegUsrLen)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f2() bDlegUsr ucDlegUsrLen error");
                #endif
                return TC_ERR_PARA;
            }

            // ucUsrLen
            pf->ucUsrLen = pu->ucDlegUsrLen;
            usLen += 1;

            // ucDlegUsr
            pTmp += 1;
            memcpy(pTmp, pu->ucDlegUsr, pu->ucDlegUsrLen);
            usLen += pu->ucDlegUsrLen;

            // ���������������볤��n��λ��
            pTmp  += pu->ucDlegUsrLen;
        }
        else
        {
            pf->ucUsrLen = 0;

            // ���������������볤��n��λ��
            usLen += 1;
            pTmp  += 1;
        }

        // bDlegPwd
        if(TRUE == pu->bDlegPwd)
        {
            if(0 == pu->ucDlegPwdLen)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f2() bDlegPwd ucDlegPwdLen error");
                #endif
                return TC_ERR_PARA;
            }
            
            // ucDlegPwdLen
            *pTmp = pu->ucDlegPwdLen;
            usLen += 1;

            // ucDlegPwd
            pTmp += 1; 
            memcpy(pTmp, pu->ucDlegPwd, pu->ucDlegPwdLen);
            usLen += pu->ucDlegPwdLen;
            pTmp += pu->ucDlegPwdLen; 
        }
        else
        {
            *pTmp = 0;
            pTmp  += 1; 
            usLen += 1;
        }

        // ucPermitDelayM 
        pucPermitDelayM = (UINT8*)pTmp++;
        pucSWTS1        = (UINT8*)pTmp++;
        pucSWTS2        = (UINT8*)pTmp++;
        pbs8Con         = (UINT8*)pTmp++;
        pucHeartBeat    = (UINT8*)pTmp++;

        *pucPermitDelayM = pu->ucPermitDelayM;
        *pucSWTS1        = (pu->usWaitTimeoutS & 0xFF);
        *pucSWTS2        = ((pu->usWaitTimeoutS & 0x0F00) >> 8);
        *pucSWTS2       |= ((pu->ucReSendTimes & 0x03) << 4);
        *pucHeartBeat    = pu->ucHeartBeat;
            
        if(pu->bPermitTk == TRUE)
        {
            *pbs8Con |= 0x01;
        }

        if(pu->bPermitEv == TRUE)
        {
            *pbs8Con |= 0x02;
        }
       
        usLen += 5;
    }
    // ��֡�ൽ�û���
    else
    {
        // usListenPort
        pu->usListenPort = pf->usListenPort;
        usLen += sizeof(UINT16);

        // sUpIp
        sIp_f = pf->sUpIp;
        eRet  = etc_trans_ip(eTrans, &(pu->sUpIp), &sIp_f, &usTmpLen);
        if(eRet != TC_OK)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() etc_trans_ip() error %d!", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmpLen;

        // sUpMask
        sIp_f = pf->sUpMask;
        eRet  = etc_trans_ip(eTrans, &(pu->sUpMask), &sIp_f, &usTmpLen);
        if(eRet != TC_OK)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() etc_trans_ip() error %d!", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmpLen;

        // sGateIp
        sIp_f = pf->sGateIp;
        eRet  = etc_trans_ip(eTrans, &(pu->sGateIp), &sIp_f, &usTmpLen);
        if(eRet != TC_OK)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() etc_trans_ip() error %d!", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmpLen;
        
        // eDelegate
        switch(pf->ucDelegate)
        {
            case 0:
                pu->eDelegate = TC_DELG_NULL;
                break;
                
            case 1:
                pu->eDelegate = TC_DELG_HTTP;
                break;
                
            case 2:
                pu->eDelegate = TC_DELG_SOCK4;
                break;
                
            case 3:
                pu->eDelegate = TC_DELG_SOCK5;
                break;

            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f2() para eDelegate is error!");
                #endif
                pu->eDelegate = TC_DELG_UNKOWN;
                break;
        }

        usLen += sizeof(UINT8);

        // sDelgIp
        sIp_f = pf->sDelgIp;
        eRet  = etc_trans_ip(eTrans, &(pu->sDelgIp), &sIp_f, &usTmpLen);
        if(eRet != TC_OK)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() etc_trans_ip() error %d!", eRet);
            #endif
            return eRet;
        }
        
        usLen += usTmpLen;

        // usDelgPort
        pu->usDelgPort = pf->usDelgPort;
        usLen += sizeof(UINT16);

        // eDelgLink
        if(0 == pf->ucDelgLink)
        {
            pu->eDelgLink = TC_DELK_ANYONE;
        }
        else if(1 == pf->ucDelgLink)
        {
            pu->eDelgLink = TC_DELK_USRPWD;
        }
        else
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f2() ucDelgLink para error %d!", pf->ucDelgLink);
            #endif
            pu->eDelgLink = TC_DELK_UNKOWN;
            //return TC_ERR_PARA;
        }
        
        usLen += 1;

         // ucUsrLen
        pu->ucDlegUsrLen = pf->ucUsrLen;
        usLen += 1;

        // bDlegUsr
        pTmp = &(pf->ucUsrLen);
        if(0 == pu->ucDlegUsrLen)
        {
            pu->bDlegUsr = FALSE;

            // ���������������볤��λ��
            pTmp  += 1;
            usLen += 1;
        }
        else
        {      
            pu->bDlegUsr = TRUE;

            // ucDlegUsr
            pTmp += 1;
            memcpy(pu->ucDlegUsr, pTmp, pu->ucDlegUsrLen);
            usLen += pu->ucDlegUsrLen;
            
            // ���������������볤��λ��
            pTmp += pu->ucDlegUsrLen;
        }
 
        // ucDlegPwdLen
        pu->ucDlegPwdLen = *pTmp;
        usLen += 1;
        
        // bDlegPwd
        if(0 == pu->ucDlegPwdLen)
        {
           pu->bDlegPwd = FALSE;
           pTmp  += 1;
           usLen += 1;
        }
        else
        {
           pu->bDlegPwd = TRUE;
           
           // ucDlegPwd
           pTmp += 1; 
           memcpy(pu->ucDlegPwd, pTmp, pu->ucDlegPwdLen);
           usLen += pu->ucDlegPwdLen;
           pTmp  += pu->ucDlegPwdLen;
        }
        
        // ucPermitDelayM
        pucPermitDelayM = (UINT8*)pTmp++;
        pucSWTS1        = (UINT8*)pTmp++;
        pucSWTS2        = (UINT8*)pTmp++;
        pbs8Con         = (UINT8*)pTmp++;
        pucHeartBeat    = (UINT8*)pTmp++;
        
        pu->ucPermitDelayM   = *pucPermitDelayM;
        pu->usWaitTimeoutS   = ((*pucSWTS1) | (((*pucSWTS2) & 0x0F) << 8));
        pu->ucReSendTimes    = (*pucSWTS2 >> 4) & 0x03;
        pu->bPermitTk        = ((*pbs8Con & 0x01) ? TRUE : FALSE);
        pu->bPermitEv        = ((*pbs8Con & 0x02) ? TRUE : FALSE);
        pu->ucHeartBeat      = *pucHeartBeat;

        usLen += 5;
    }

    // �������
    * pusLen = usLen;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f3
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F3_TML_AUTH_PARA
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��12��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f3(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn04f3      *pu  = NULL;
    sTcAfn04f3_f    *pf  = NULL;

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f3() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn04f3   *)pUser;
    pf = (sTcAfn04f3_f *)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {        
        pf->ucTypeID   = pu->ucTypeID;
        pf->usAuthPara = pu->usAuthPara;
    }
    // ��֡�ൽ�û���
    else
    {
        pu->ucTypeID   = pf->ucTypeID;
        pu->usAuthPara = pf->usAuthPara;   
    }

    *pusLen = sizeof(sTcAfn04f3_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f4
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F4_TML_STATE_INPUT
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��12��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f4(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn04f4_f    *pf = NULL;
    sTcAfn04f4      *pu = NULL;  
    INT32             i = 0;
    UINT8        ucMask = 0;

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f4() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pf = (sTcAfn04f4_f*)pFrame;
    pu = (sTcAfn04f4  *)pUser;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
       pf->bIn = 0;
       for(i = 0; i < 8; i++)
       {    
           ucMask = (0x01 << i);
           // bIn
           if(TRUE == pu->bIn[i])
           {
              pf->bIn |= ucMask;
           }

           // bOn
           if(TRUE == pu->bOn[i])
           {
              pf->bOn |= ucMask;
           }
       }
    }
    // ��֡�ൽ�û���
    else
    {
        for(i = 0; i < 8; i++)
        {
            ucMask = (0x01 << i);

            // bIn
            if(pf->bIn & ucMask)
            {
                pu->bIn[i] = TRUE;
            }
            else
            {  
                pu->bIn[i] = FALSE;
            }

            // bOn
            if(pf->bOn & ucMask)
            {
                pu->bOn[i] = TRUE;
            }
            else
            {  
                pu->bOn[i] = FALSE;
            }
        }
    }

    // �������
    * pusLen = sizeof(sTcAfn04f4_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f5
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F5_TML_EVENT_CFG
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��12��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f5(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn04f5_f   *pf  = NULL;
    sTcAfn04f5     *pu  = NULL;  
    INT32          i    = 0;
    INT32          ai   = 0;      // ��Ϊ��������
    INT32          bi   = 0;      // ��λ����
    eTcErc         eErc = TC_ERC_UNKOWN;
    UINT8         ucErc = 0;
    UINT8         ucTmp = 0;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f5() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pf = (sTcAfn04f5_f*)pFrame;
    pu = (sTcAfn04f5  *)pUser;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // aNeed
        if(pu->ucNeed > TC_ERC_NUM_MAX)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f5() para ucNeed is out of range %d!", pu->ucNeed);
            #endif
            return TC_ERR_OUTRNG;
        }

        for(i = 0; i < pu->ucNeed; i++)
        {
            eErc = pu->aNeed[i];
            if(eErc > TC_ERC_NUM_MAX || eErc == TC_ERC_UNKOWN)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f5() para eErc is out of range %d!", eErc);
                #endif
                return TC_ERR_OUTRNG;
            }

            // ��������bs64�е�λ��
            ucErc = (UINT8)eErc;
            ai = (ucErc - 1) / 8;
            bi = (ucErc - 1) % 8;
            pf->aNeed[ai] |= (0x01 << bi);
        }

        // ucImpt
        if(pu->ucImpt > TC_ERC_NUM_MAX)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f5() para ucImpt is out of range %d!", pu->ucImpt);
            #endif
            return TC_ERR_OUTRNG;
        }

        if(pu->ucImpt > pu->ucNeed)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f5() ucImpt > ucNeed (%d - %d)!", pu->ucImpt, pu->ucNeed);
            #endif
            return TC_ERR_LOGIC;
        }
        
        for(i = 0; i < pu->ucImpt; i++)
        {
            eErc = pu->aImpt[i];
            if(eErc > TC_ERC_NUM_MAX || eErc == TC_ERC_UNKOWN)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f5() para eErc is out of range %d!", eErc);
                #endif
                return TC_ERR_OUTRNG;
            }

            // ��������bs64�е�λ��
            ucErc = (UINT8)eErc;
            ai = (ucErc -1) / 8;
            bi = (ucErc -1) % 8;
            pf->aImpt[ai] |= (0x01 << bi);
        }

    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // aNeed
        for(ai = 0; ai < 8; ai++)
        {
            ucTmp = pf->aNeed[ai];
            for(bi = 0; bi < 8; bi++)
            {
                if(ucTmp & (0x01 << bi))
                {
                    ucErc = ai * 8 + bi + 1;
                    eErc = (eTcErc)ucErc;
                    pu->aNeed[i++] = eErc;
                }
            }
        }

        pu->ucNeed = i;
       
        // aImpt 
        i = 0;
        for(ai = 0; ai < 8; ai++)
        {
            ucTmp = pf->aImpt[ai];
            for(bi = 0; bi < 8; bi++)
            {
                if(ucTmp & (0x01 << bi))
                {
                    ucErc = ai * 8 + bi + 1;
                    eErc = (eTcErc)ucErc;
                    pu->aImpt[i++] = eErc;
                }
            }
        }

        pu->ucImpt = i;
    }
    else
    {
       #ifdef TC_DBG
       TCDBG("etc_trans_afn04f5() para eTrans is out of range!");
       #endif
       return TC_ERR_OUTRNG;
    }
    // �������
    * pusLen = sizeof(sTcAfn04f5_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f17
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F17_FREZ_TASK_PARA
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��12��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr          eRet       = TC_OK;
    UINT8           ucNum      = 0;
    sTcAfn04f49     *pu        = NULL;
    sTcAfn04f49_f   *pf        = NULL;
    sTcDaDt         *pDaDt     = NULL;
    sTcFmt01_f      *psTime_f  = NULL;
    UINT8           *pucTmp    = NULL;
    UINT16          usLen      = 0;
    sTcFmt01_f      sFmt01_f;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f17() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn04f49*)pUser;
    pf = (sTcAfn04f49_f*)pFrame;
    memset(&sFmt01_f, 0, sizeof(sTcFmt01_f));

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // sTime
        eRet = etc_trans_YWMDhms(eTrans, &(pu->sTimeFrez), &sFmt01_f);
        if(TC_OK != eRet)
        {       
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f17() etc_trans_YWMDhms() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->sTimeFrez = sFmt01_f;
        usLen += sizeof(sTcFmt01_f);
        
        // sFreez.usPeriod
        pf->sFreez.usPeriod = pu->sFreez.usPeriod;
   
        // sFreez.eUnit
        switch(pu->sFreez.eUnit)
        {
            case TC_PUNT_MONTH:
                pf->sFreez.eUnit = 1;
                break;
                
            case TC_PUNT_DAY:
                pf->sFreez.eUnit = 2;
                break;
                    
            case TC_PUNT_HOUR:
                pf->sFreez.eUnit = 3;
                break;

            case TC_PUNT_MIN:
                pf->sFreez.eUnit = 4;
                break;

            case TC_PUNT_SEC:
                pf->sFreez.eUnit = 5;
                break;
                    
            case TC_PUNT_MS:
                pf->sFreez.eUnit = 6;
                break;
           default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f17() para pointer is error!");
                #endif
                return TC_ERR_PARA;
                //break;
        }

        // sFreez.ucTimes
        pf->sFreez.ucTimes = pu->sFreez.ucTimes;
        usLen += sizeof(sTcFrezPeriod_f);
        
        // cmd pn 
        pDaDt = (sTcDaDt*)(&(pf->ucDaDtNum) + 1);
        eRet = etc_cmdpn_to_dadt(TC_AFN_13_ASKR, pDaDt, &ucNum, &(pu->sCmdPn[0]), pu->uCmdPnNum);
        if(TC_OK != eRet)
        {       
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f17() etc_cmdpn_to_dadt() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->ucDaDtNum = ucNum;
        usLen += sizeof(sTcDaDt) * ucNum + sizeof(UINT8); 
        
        // sTimeRprt
        pucTmp = (UINT8*)(pDaDt + ucNum);
        psTime_f = (sTcFmt01_f *)pucTmp; 
        eRet = etc_trans_YWMDhms(eTrans, &(pu->sTimeRprt), psTime_f);
        if(TC_OK != eRet)
        {       
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f17() etc_trans_YWMDhms() error %d!", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sTcFmt01_f);

        // ucPeriodRpt
        pucTmp += sizeof(sTcFmt01_f);
        *pucTmp = pu->ucPeriodRpt;
        usLen += sizeof(UINT8);

        // eUnitRpt
        pucTmp += 1;
        switch(pu->eUnitRpt)
        {
            case TC_PUNT_MONTH:
                *pucTmp = 4;
                break;
                
            case TC_PUNT_DAY:
                *pucTmp = 3;
                break;
                    
            case TC_PUNT_HOUR:
                *pucTmp = 2;
                break;

            case TC_PUNT_MIN:
                *pucTmp = 1;
                break;
                
           default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f17() para eUnitRpt is error!,%d",pu->eUnitRpt);
                #endif
                return TC_ERR_PARA;
                //break;
        }

        usLen += sizeof(UINT8); 
    }
    // ��֡�ൽ�û���
    else if (TC_TRANS_F2U == eTrans)
    {
        // sTime
        sFmt01_f = pf->sTimeFrez;
        eRet = etc_trans_YWMDhms(eTrans, &(pu->sTimeFrez), &sFmt01_f);
        if(TC_OK != eRet)
        {       
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f17() etc_trans_YWMDhms() error %d!", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sTcFmt01_f);
        
        // sFreez.usPeriod
        pu->sFreez.usPeriod = pf->sFreez.usPeriod;

        // sFreez.eUnit
        switch(pf->sFreez.eUnit)
        {
            case 1:
                pu->sFreez.eUnit = TC_PUNT_MONTH;
                break;
                
            case 2:
                pu->sFreez.eUnit = TC_PUNT_DAY;
                break;
                    
            case 3:
                pu->sFreez.eUnit = TC_PUNT_HOUR;
                break;

            case 4:
                pu->sFreez.eUnit = TC_PUNT_MIN;
                break;

            case 5:
                pu->sFreez.eUnit = TC_PUNT_SEC;
                break;
                    
            case 6:
                pu->sFreez.eUnit = TC_PUNT_MS;
                break;
                
           default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f17() para pointer is error!");
                #endif
                pu->sFreez.eUnit = TC_PUNT_UNKOWN;
                break;
        }

        // sFreez.ucTimes
        pu->sFreez.ucTimes = pf->sFreez.ucTimes;
        usLen += sizeof(sTcFrezPeriod_f);

        // cmd pn 
        pDaDt = (sTcDaDt*)(&(pf->ucDaDtNum) + 1);
        eRet = etc_dadt_to_cmdpn(TC_AFN_13_ASKR, pDaDt, pf->ucDaDtNum, &(pu->sCmdPn[0]), &ucNum);
        if(TC_OK != eRet)
        {       
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f17() etc_dadt_to_cmdpn() error %d!", eRet);
            #endif
            return eRet;
        }

        pu->uCmdPnNum = ucNum;
        usLen += sizeof(sTcDaDt) * ucNum + sizeof(UINT8); 
        
        // sTimeRprt
        pucTmp = (UINT8*)(pDaDt + pf->ucDaDtNum);
        psTime_f = (sTcFmt01_f *)pucTmp; 
        eRet = etc_trans_YWMDhms(eTrans, &(pu->sTimeRprt), psTime_f);
        if(TC_OK != eRet)
        {       
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f17() etc_trans_YWMDhms() error %d!", eRet);
            #endif
            return eRet;
        }
        
        usLen += sizeof(sTcFmt01_f);

        // ucPeriodRpt
        pucTmp += sizeof(sTcFmt01_f);
        pu->ucPeriodRpt = *pucTmp;
        usLen += sizeof(UINT8);

        // eUnitRpt
        pucTmp += 1;
        switch(*pucTmp)
        {
            case 4:
                pu->eUnitRpt = TC_PUNT_MONTH;
                break;
                
            case 3:
                pu->eUnitRpt = TC_PUNT_DAY;
                break;
                    
            case 2:
                pu->eUnitRpt = TC_PUNT_HOUR;
                break;

            case 1:
                pu->eUnitRpt = TC_PUNT_MIN;
                break;
                
           default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f17() para eUnitRpt is error!");
                #endif
                pu->eUnitRpt = TC_PUNT_UNKOWN;
                //return TC_ERR_PARA;
                break;
        }

        usLen += sizeof(UINT8);  
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn04f17() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    // �������
    *pusLen = usLen;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_serial
 ��������  : ���ݽṹת������ 
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��5��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_serial(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAcsParaSer *pu = NULL;
    UINT8         *pf = NULL;
    UINT8       ucSer = 0; 

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_serial() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAcsParaSer*)pUser;
    pf = (UINT8*)pFrame;

    if(TC_TRANS_U2F == eTrans)
    {
        // eTcSerBaud
        switch ( pu->eBaud)
        {
            case TC_BAUD_DEFAULT:
                 //ucSer |= 0;
                 break;

            case TC_BAUD_1200:
                 ucSer |= (1 << 5);
                 break;

            case TC_BAUD_2400:
                 ucSer |= (2 << 5);
                 break;

            case TC_BAUD_4800:
                ucSer |= (3 << 5);
                break;

            case TC_BAUD_9600:
                ucSer |= (4 << 5);
                break;

            case TC_BAUD_19200:
                ucSer |= (5 << 5);
                break;

            case TC_BAUD_38400:
                ucSer |= (6 << 5);
                break; 

            case TC_BAUD_76800:
                ucSer |= (7 << 5);
                break;   

            default:
               #ifdef TC_DBG
               TCDBG("etc_trans_serial() para eBaud is error!");
               #endif
               return TC_ERR_PARA;
               // break;
        }

        // bStop1
        if(TRUE != pu->bStop1)
        {
           ucSer |= (1 << 4);
        }
        // bCheck
        if(TRUE == pu->bCheck)
        {
           ucSer |= (1 << 3);
        }
        
        // bOdd
        if(TRUE == pu->bOdd)
        {
           ucSer |= (1 << 2);
        }    

        // eBit
        switch(pu->eBit)
        {
            case TC_SBIT_5:
                break;
                
            case TC_SBIT_6:
                ucSer |= 1;
                break;
                
            case TC_SBIT_7:
                ucSer |= 2;
                break;
                
            case TC_SBIT_8:
                ucSer |= 3;
                break;
                
            default:                         
                #ifdef TC_DBG
                TCDBG("etc_trans_serial() para eBit is error!");
                #endif
                return TC_ERR_PARA;
               // break;
        }

        // �������
        *(pf) = ucSer;
    }
    else if(TC_TRANS_F2U == eTrans)
    {
        ucSer = *pf;
        switch(ucSer & 0xE0 >> 5)
        {                 
            case 0:
                pu->eBaud = TC_BAUD_DEFAULT;
                break;
                
             case 1:
                 pu->eBaud =  TC_BAUD_1200;
                 break;
                
             case 2:
                 pu->eBaud = TC_BAUD_2400;
                 break;
                
             case 3:
                 pu->eBaud = TC_BAUD_4800;
                 break;
                
             case 4:
                 pu->eBaud = TC_BAUD_9600;
                 break;
                
             case 5:
                 pu->eBaud = TC_BAUD_19200;
                 break;
                
             case 6:
                 pu->eBaud = TC_BAUD_38400;
                 break;  
                   
             case 7:
                 pu->eBaud = TC_BAUD_76800;
                 break;  

             default:
                 #ifdef TC_DBG
                 TCDBG("etc_trans_serial() para eBaud is error!");
                 #endif
                 pu->eBaud = TC_BAUD_UNKOWN;
                 //return TC_ERR_PARA;
                 break;
        }

        // bStop1
        if(ucSer & (1 << 4))
        {
            pu->bStop1 = FALSE;
        }
        else
        {
            pu->bStop1 = TRUE;
        }
        
        // bCheck
        if(ucSer & (1 << 3))
        {
            pu->bCheck = TRUE;
        }
        else
        {
            pu->bCheck = FALSE;
        }
        
        
        // bOdd          
        if(ucSer & (1 << 2))
        {
            pu->bOdd = TRUE;
        }
        else
        {
            pu->bOdd = FALSE;
        }

        // eBit
        switch(ucSer & 0x03)
        {
            case 0:
                pu->eBit = TC_SBIT_5;
                break;
                
            case 1:
                pu->eBit = TC_SBIT_6;
                break;
                
            case 2:
                pu->eBit = TC_SBIT_7;
                break;
                
            case 3:
                pu->eBit = TC_SBIT_8;
                break;
                
            default:                         
                #ifdef TC_DBG
                TCDBG("etc_trans_serial() para eBit is error!");
                #endif
                return TC_ERR_PARA;
               // break;
        }
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_serial() para eTrans is out of range!");
        #endif
        return TC_ERR_OUTRNG;
    }

    // �������
    * pusLen = sizeof(UINT8);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f25
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F25_ELEC_MP_CFG
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��7��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f25(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn04f25_f      *pf = NULL;
    sTcAfn04f25        *pu = NULL;  
    UINT8            *pTmp = NULL;
    eTcErr            eRet = TC_OK;
    UINT16           usLen = 0;
    UINT16        usTmpLen = 0;    
    UINT8            ucSer = 0;       // TC_ACS_PORT_SER  �������в���
    sTcAcsParaEth_f *psEth = NULL;    // TC_ACS_PORT_ETH  ��̫�����в���
    UINT32    *pulAddrZigb = NULL;    // TC_ACS_PORT_ZIGB Zigbee��ַ 

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f25() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pf = (sTcAfn04f25_f*)pFrame;
    pu = (sTcAfn04f25  *)pUser;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // ucPort
        pf->ucPort = pu->ucPort;
        usLen += sizeof(UINT8);

        // ucAddr
        eRet = etc_str_to_bcd(pu->ucAddr, pf->ucAddrBcd, 16);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f25() etc_str_to_bcd() error %d!", eRet);
            #endif
            return eRet;
        }

        usLen += 8;

        // eAcsProto
        switch(pu->eAcsProto)
        {                    
            case TC_ACS_PROT_DLT645_97:
                pf->eAcsProto = 1;
                break;         
                
            case TC_ACS_PROT_DLT645_07:
                pf->eAcsProto = 2;
                break;      
                
            case TC_ACS_PROT_MODBUS:
                pf->eAcsProto = 3;
                break;
                
            default:
                pf->eAcsProto = pu->eAcsProto;
                break;
        }
        
        usLen += sizeof(UINT8);
        
        // ucPwd
        memcpy(pf->ucPwd, pu->ucPwd, 6);
        usLen += 6;

        // eAcsPort
        pTmp = &(pf->ucAcsParaLen);
        pTmp++;
        switch(pu->eAcsPort)
        {
            case TC_ACS_PORT_DC:
                pf->eAcsPort = 1;
                pf->ucAcsParaLen = 0;// �޲���
                break;
                
            case TC_ACS_PORT_AC:
                pf->eAcsPort = 2;
                pf->ucAcsParaLen = 0;// �޲���
                break;
                
            case TC_ACS_PORT_SER:
                pf->eAcsPort = 3;
                pf->ucAcsParaLen = 1; 
                switch(pu->uPortPara.sSer.eBaud)
                {
                    case TC_BAUD_DEFAULT:
                        //ucSer |= 0;
                        break;
                        
                     case TC_BAUD_1200:
                         ucSer |= (1 << 5);
                         break;
                        
                     case TC_BAUD_2400:
                         ucSer |= (2 << 5);
                         break;
                        
                     case TC_BAUD_4800:
                         ucSer |= (3 << 5);
                         break;
                        
                     case TC_BAUD_9600:
                         ucSer |= (4 << 5);
                         break;
                        
                     case TC_BAUD_19200:
                         ucSer |= (5 << 5);
                         break;
                        
                      case TC_BAUD_38400:
                           ucSer |= (6 << 5);
                           break; 
                           
                     case TC_BAUD_76800:
                           ucSer |= (7 << 5);
                           break;   
                           
                      default:
                            #ifdef TC_DBG
                            TCDBG("etc_trans_afn04f25() para eBaud is error!");
                            #endif
                            return TC_ERR_PARA;
                            // break;
                }
             
                // bStop1
                if(TRUE != pu->uPortPara.sSer.bStop1)
                {
                   ucSer |= (1 << 4);
                }
                // bCheck
                if(TRUE == pu->uPortPara.sSer.bCheck)
                {
                   ucSer |= (1 << 3);
                }
                
                // bOdd
                if(TRUE == pu->uPortPara.sSer.bOdd)
                {
                   ucSer |= (1 << 2);
                }    

                // eBit
                switch(pu->uPortPara.sSer.eBit)
                {
                    case TC_SBIT_5:
                        break;
                        
                    case TC_SBIT_6:
                        ucSer |= 1;
                        break;
                        
                    case TC_SBIT_7:
                        ucSer |= 2;
                        break;
                        
                    case TC_SBIT_8:
                        ucSer |= 3;
                        break;
                        
                    default:                         
                        #ifdef TC_DBG
                        TCDBG("etc_trans_afn04f25() para eBit is error!");
                        #endif
                        return TC_ERR_PARA;
                       // break;
                }

                // �������
                *(pTmp) = ucSer;
                break;
                
            case TC_ACS_PORT_ETH:
                pf->eAcsPort = 4;     
                pf->ucAcsParaLen = sizeof(sTcAcsParaEth_f); 
                psEth = (sTcAcsParaEth_f *)pTmp;

                // usPort
                psEth->usPort = pu->uPortPara.sEth.usPort;

                // sMask  
                eRet = etc_trans_ip(eTrans, &(pu->uPortPara.sEth.sMask), &(psEth->sMask), &usTmpLen);
                if(eRet != TC_OK)
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn04f25() etc_trans_ip() error %d!", eRet);
                    #endif
                    return eRet;
                }
                
                // sGate
                eRet = etc_trans_ip(eTrans, &(pu->uPortPara.sEth.sGate), &(psEth->sGate), &usTmpLen);
                if(eRet != TC_OK)
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn04f25() etc_trans_ip() error %d!", eRet);
                    #endif
                    return eRet;
                }

                // �Ѿ��ں�߼��㳤��, ����ֻΪȥ������
                usTmpLen += usTmpLen;
                break;
                
            case TC_ACS_PORT_ZIGB:
                pf->eAcsPort = 5;      
                pf->ucAcsParaLen = 4; 
                pulAddrZigb = (UINT32*)pTmp;
                *pulAddrZigb = pu->uPortPara.ulAddrZigb;
                break;
                
            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f25() para eAcsPort is error!");
                #endif
                return TC_ERR_NULL;
                //break;

        }

        // ���㳤��
        usLen += sizeof(UINT8) * 2 + pf->ucAcsParaLen;
        
    }
    // ��֡�ൽ�û���
    else
    {
        // ucPort
        pu->ucPort = pf->ucPort;
        usLen += sizeof(UINT8);

        // ucAddr
        eRet = etc_bcd_to_str(pf->ucAddrBcd, pu->ucAddr, 8);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f25() etc_bcd_to_str() error %d!", eRet);
            #endif
            return eRet;
        }

        usLen += 8;

        // eAcsProto
        switch(pf->eAcsProto)
        {                
             case 1:
                pu->eAcsProto = TC_ACS_PROT_DLT645_97;
                break;    
                
             case 2:
                pu->eAcsProto = TC_ACS_PROT_DLT645_07;
                break;     
                
             case 3:
                pu->eAcsProto = TC_ACS_PROT_MODBUS;
                break;     

              default:
                pu->eAcsProto = TC_ACS_PROT_UNKOWN;
                break;
        }
        
        usLen += sizeof(UINT8);
        
        // ucPwd
        memcpy(pu->ucPwd, pf->ucPwd, 6);
        usLen += 6;

        // eAcsPort
        pTmp = &(pf->ucAcsParaLen);
        pTmp++;
        switch(pf->eAcsPort)
        {
            case 1:
                pu->eAcsPort = TC_ACS_PORT_DC;
                if(pf->ucAcsParaLen != 0)
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn04f25() ucAcsParaLen error %d!", pf->ucAcsParaLen);
                    #endif
                    return TC_ERR_LOGIC;
                }
                break;
                
            case 2:
                pu->eAcsPort = TC_ACS_PORT_AC;
                if(pf->ucAcsParaLen != 0)
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn04f25() ucAcsParaLen error %d!", pf->ucAcsParaLen);
                    #endif
                    return TC_ERR_LOGIC;
                }
                break;
                
            case 3:
                // ȡ�ò���
                ucSer = *(pTmp);
                pu->eAcsPort = TC_ACS_PORT_SER;
                if(pf->ucAcsParaLen != 1)
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn04f25() ucAcsParaLen error %d!", pf->ucAcsParaLen);
                    #endif
                    return TC_ERR_LOGIC;
                }

                switch(ucSer & 0xE0 >> 5)
                {                 
                    case 0:
                        pu->uPortPara.sSer.eBaud = TC_BAUD_DEFAULT;
                        break;
                        
                     case 1:
                         pu->uPortPara.sSer.eBaud =  TC_BAUD_1200;
                         break;
                        
                     case 2:
                         pu->uPortPara.sSer.eBaud = TC_BAUD_2400;
                         break;
                        
                     case 3:
                         pu->uPortPara.sSer.eBaud = TC_BAUD_4800;
                         break;
                        
                     case 4:
                         pu->uPortPara.sSer.eBaud = TC_BAUD_9600;
                         break;
                        
                     case 5:
                         pu->uPortPara.sSer.eBaud = TC_BAUD_19200;
                         break;
                        
                      case 6:
                           pu->uPortPara.sSer.eBaud = TC_BAUD_38400;
                           break;  
                           
                      case 7:
                           pu->uPortPara.sSer.eBaud = TC_BAUD_76800;
                           break;  
                      default:
                            #ifdef TC_DBG
                            TCDBG("etc_trans_afn04f25() para eBaud is error!");
                            #endif
                            pu->uPortPara.sSer.eBaud = TC_BAUD_UNKOWN;
                            //return TC_ERR_PARA;
                             break;
                }

                // bStop1
                if(ucSer & (1 << 4))
                {
                    pu->uPortPara.sSer.bStop1 = FALSE;
                }
                else
                {
                    pu->uPortPara.sSer.bStop1 = TRUE;
                }
                
                // bCheck
                if(ucSer & (1 << 3))
                {
                    pu->uPortPara.sSer.bCheck = TRUE;
                }
                else
                {
                    pu->uPortPara.sSer.bCheck = FALSE;
                }
                
                
                // bOdd          
                if(ucSer & (1 << 2))
                {
                    pu->uPortPara.sSer.bOdd = TRUE;
                }
                else
                {
                    pu->uPortPara.sSer.bOdd = FALSE;
                }

                // eBit
                switch(ucSer & 0x03)
                {
                    case 0:
                        pu->uPortPara.sSer.eBit = TC_SBIT_5;
                        break;
                        
                    case 1:
                        pu->uPortPara.sSer.eBit = TC_SBIT_6;
                        break;
                        
                    case 2:
                        pu->uPortPara.sSer.eBit = TC_SBIT_7;
                        break;
                        
                    case 3:
                        pu->uPortPara.sSer.eBit = TC_SBIT_8;
                        break;
                        
                    default:                         
                        #ifdef TC_DBG
                        TCDBG("etc_trans_afn04f25() para eBit is error!");
                        #endif
                        return TC_ERR_PARA;
                       // break;
                }
                   
                break;
                
            case 4:
                pu->eAcsPort = TC_ACS_PORT_ETH;     
                if(pf->ucAcsParaLen != sizeof(sTcAcsParaEth_f))
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn04f25() ucAcsParaLen error %d!", pf->ucAcsParaLen);
                    #endif
                    return TC_ERR_LOGIC;
                }

                psEth = (sTcAcsParaEth_f *)pTmp;

                // usPort
                pu->uPortPara.sEth.usPort = psEth->usPort;

                // sMask  
                eRet = etc_trans_ip(eTrans, &(pu->uPortPara.sEth.sMask), &(psEth->sMask), &usTmpLen);
                if(eRet != TC_OK)
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn04f25() etc_trans_ip() error %d!", eRet);
                    #endif
                    return eRet;
                }
                
                // sGate
                eRet = etc_trans_ip(eTrans, &(pu->uPortPara.sEth.sGate), &(psEth->sGate), &usTmpLen);
                if(eRet != TC_OK)
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn04f25() etc_trans_ip() error %d!", eRet);
                    #endif
                    return eRet;
                }

                // �Ѿ��ں�߼��㳤��, ����ֻΪȥ������
                usTmpLen += usTmpLen;
                break;
                
            case 5:
                pu->eAcsPort = TC_ACS_PORT_ZIGB;      
                if(pf->ucAcsParaLen != sizeof(UINT32))
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn04f25() ucAcsParaLen error %d!", pf->ucAcsParaLen);
                    #endif
                    return TC_ERR_LOGIC;
                }

                pulAddrZigb = (UINT32*)pTmp;
                pu->uPortPara.ulAddrZigb = *pulAddrZigb;
                break;
                
            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f25() para eAcsPort is error!");
                #endif
                return TC_ERR_NULL;
                //break;

        }

        // ���㳤��
        usLen += sizeof(UINT8) * 2 + pf->ucAcsParaLen;
   
    }

    // �������
    * pusLen = usLen;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f26
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F26_ELEC_MP_BASE
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��8��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f26(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn04f26_f      *pf = NULL;
    sTcAfn04f26        *pu = NULL;  
    UINT8            ucTmp = 0;
    eTcErr            eRet = TC_OK;
    UINT16           usLen = 0;
    sTcFmt_XXX_X     fU_f;
    sTcFmt_sXXX_XXX  fI_f;

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f26() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pf = (sTcAfn04f26_f*)pFrame;
    pu = (sTcAfn04f26  *)pUser;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // sDigit
        if(TC_DNUM_INTGR_MIN > pu->sDigit.ucInteger ||
           TC_DNUM_INTGR_MAX < pu->sDigit.ucInteger)
        {
           #ifdef TC_DBG
           TCDBG("etc_trans_afn04f26() sDigit.ucInteger is out of range! ucInteger = %d", pu->sDigit.ucInteger);
           #endif
           return TC_ERR_OUTRNG;   
        }
 
        if(TC_DNUM_DECIM_MIN > pu->sDigit.ucDecimal ||
           TC_DNUM_DECIM_MAX < pu->sDigit.ucDecimal)
        {
           #ifdef TC_DBG
           TCDBG("etc_trans_afn04f26() sDigit.ucDecimal is out of range! ucDecimal = %d", pu->sDigit.ucDecimal);
           #endif
           return TC_ERR_OUTRNG;   
        }

        // ʹ����0~3��
        pf->sDigit = 0; 
        ucTmp = pu->sDigit.ucDecimal - 1;
        pf->sDigit |= ucTmp;
        
        // ʹ����0~3��
        ucTmp = (pu->sDigit.ucInteger - 4) << 2;
        pf->sDigit |= ucTmp;
        usLen += sizeof(UINT8);       

        // usTimesU
        pf->usTimesU = pu->usTimesU;
        usLen += sizeof(UINT16);       

        // usTimesI
        pf->usTimesI = pu->usTimesI;
        usLen += sizeof(UINT16);     
        
        // fU
        eRet = etc_trans_XXX_X(eTrans, &(pu->fU), &fU_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f26() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->fU = fU_f;
        usLen += sizeof(sTcFmt_XXX_X);

        // fI
        eRet = etc_trans_sXXX_XXX(eTrans, &(pu->fI), &fI_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f26() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->fI = fI_f;
        usLen += sizeof(sTcFmt_sXXX_XXX);  

        // sLinkWay
        pf->sLinkWay = 0;
        switch(pu->sLinkWay.eLink)
        {
            case TC_LINK_P3_L3:
                pf->sLinkWay = 1;
                break;
                
            case TC_LINK_P3_L4:
                pf->sLinkWay = 2;
                break;
                
            case TC_LINK_P1:
                pf->sLinkWay = 3;
                break;
                
            default:
               #ifdef TC_DBG
               TCDBG("etc_trans_afn04f26() sLinkWay.eLink is out of range!");
               #endif
               return TC_ERR_OUTRNG; 
               //break;
            
        }

        // ePhase
         switch(pu->sLinkWay.ePhase)
        {
            case TC_PHASE_UNKOWN:
                //pf->sLinkWay = 1;
                break;
                
            case TC_PHASE_A:
                pf->sLinkWay |= (1 << 2);
                break;
                
            case TC_PHASE_B:
                pf->sLinkWay |= (2 << 2);
                break;
                
            case TC_PHASE_C:
                pf->sLinkWay |= (3 << 2);
                break;
                
            default:
               #ifdef TC_DBG
               TCDBG("etc_trans_afn04f26() sLinkWay.ePhase is out of range!");
               #endif
               return TC_ERR_OUTRNG; 
               //break;
            
        }
         
        usLen += sizeof(UINT8);    
    }
    // ��֡�ൽ�û���
    else
    {
        // sDigit
        ucTmp = pf->sDigit & 0x03; 
        pu->sDigit.ucDecimal = ucTmp + 1;
        ucTmp = (UINT8)(pf->sDigit & 0x0C >> 2);
        pu->sDigit.ucInteger = ucTmp + 4;
        usLen += sizeof(UINT8);       

        // usTimesU
        pu->usTimesU = pf->usTimesU;
        usLen += sizeof(UINT16);       

        // usTimesI
        pu->usTimesI = pf->usTimesI;
        usLen += sizeof(UINT16);     
        
        // fU
        fU_f = pf->fU;
        eRet = etc_trans_XXX_X(eTrans, &(pu->fU), &fU_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f26() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sTcFmt_XXX_X);

        // fI
        fI_f = pf->fI;
        eRet = etc_trans_sXXX_XXX(eTrans, &(pu->fI), &fI_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f26() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }

        usLen += sizeof(sTcFmt_sXXX_XXX);    
        
        // sLinkWay
        ucTmp = pf->sLinkWay & 0x03;
        switch(ucTmp)
        {
            case 1:
                pu->sLinkWay.eLink = TC_LINK_P3_L3;
                break;
                
            case 2:
                pu->sLinkWay.eLink = TC_LINK_P3_L4;
                break;
                
            case 3:
                pu->sLinkWay.eLink = TC_LINK_P1;
                break;
                
            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f26() sLinkWay.eLink is out of range!");
                #endif
                pu->sLinkWay.eLink = TC_LINK_UNKOWN;
                break;
            
        }

        // ePhase
        ucTmp = (pf->sLinkWay & 0x0C) >> 2;

        switch(ucTmp)
        {
            case 0:
                pu->sLinkWay.ePhase = TC_PHASE_UNKOWN;
                break;
                
            case 1:
                pu->sLinkWay.ePhase = TC_PHASE_A;
                break;
                
            case 2:
                pu->sLinkWay.ePhase = TC_PHASE_B;
                break;
                
            case 3:
                pu->sLinkWay.ePhase = TC_PHASE_C;
                break;
                
            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f26() sLinkWay.ePhase is out of range!");
                #endif
                return TC_ERR_OUTRNG; 
                //break;
        }
         
        usLen += sizeof(UINT8);        
    }

    // �������
    * pusLen = usLen;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f27
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F27_ELEC_LMIT_PARA
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��8��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f27(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr eRet       = TC_OK;
    sTcAfn04f27   *pu = NULL;
    sTcAfn04f27_f *pf = NULL;
    sTcFmt06_f     sFmt06_f;
    sTcFmt08_f     sFmt08_f;
    sTcFmt09_f     sFmt09_f;
    sTcFmt10_f     sFmt10_f;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f27() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn04f27*)pUser;
    pf = (sTcAfn04f27_f*)pFrame;

    memset(&sFmt06_f, 0, sizeof(sTcFmt06_f));
    memset(&sFmt08_f, 0, sizeof(sTcFmt08_f));
    memset(&sFmt09_f, 0, sizeof(sTcFmt09_f));
    memset(&sFmt10_f, 0, sizeof(sTcFmt10_f));
    
    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        pf->ucTimeLossV    = pu->ucTimeLossV;
        pf->sOverV.ucTime  = pu->sOverI.ucTime;
        pf->sLossV.ucTime  = pu->sLossV.ucTime;  
        pf->sOverI.ucTime  = pu->sOverI.ucTime; 
        pf->sSuperI.ucTime = pu->sSuperI.ucTime; 
        pf->sZeroI.ucTime  = pu->sZeroI.ucTime;  
        pf->sUblV.ucTime   = pu->sUblV.ucTime; 
        pf->sUblI.ucTime   = pu->sUblI.ucTime; 

        // fDropV
        eRet = etc_trans_XXX_X(eTrans, &(pu->fDropV), &sFmt08_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->fDropV = sFmt08_f;

        // sOverV.fUpUp
        eRet = etc_trans_XXX_X(eTrans, &(pu->sOverV.fUpUp), &sFmt08_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sOverV.fUpUp = sFmt08_f;

        // sOverV.fFactor
        eRet = etc_trans_XX_XX(eTrans, &(pu->sOverV.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sOverV.fFactor = sFmt10_f;
        
        // sLossV.fDownDown
        eRet = etc_trans_XXX_X(eTrans, &(pu->sLossV.fDownDown), &sFmt08_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sLossV.fDownDown = sFmt08_f;

        // sLossV.fFactor
        eRet = etc_trans_XX_XX(eTrans, &(pu->sLossV.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sLossV.fFactor = sFmt10_f;

        // sOverI.fUpUp
        eRet = etc_trans_sXXX_XXX(eTrans, &(pu->sOverI.fUpUp), &sFmt09_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sOverI.fUpUp = sFmt09_f;

        // sOverI.fFactor
        eRet = etc_trans_XX_XX(eTrans, &(pu->sOverI.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sOverI.fFactor = sFmt10_f;

        // sSuperI.fUp
        eRet = etc_trans_sXXX_XXX(eTrans, &(pu->sSuperI.fUp), &sFmt09_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sSuperI.fUp = sFmt09_f;

        // sSuperI.fFactor
        eRet = etc_trans_XX_XX(eTrans, &(pu->sSuperI.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sSuperI.fFactor = sFmt10_f;

        // sZeroI.fUpUp
        eRet = etc_trans_sXXX_XXX(eTrans, &(pu->sZeroI.fUp), &sFmt09_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sZeroI.fUp = sFmt09_f;

        // sZeroI.fFactor
        eRet = etc_trans_XX_XX(eTrans, &(pu->sZeroI.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sZeroI.fFactor = sFmt10_f;
        
        // sUblV.fLimit
        eRet = etc_trans_sXX_XXXX(eTrans, &(pu->sUblV.fLimit), &sFmt06_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXX_XXXX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sUblV.fLimit = sFmt06_f;
        
        // sUblV.fFactor
        eRet = etc_trans_XX_XX(eTrans, &(pu->sUblV.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sUblV.fFactor = sFmt10_f;
        
        // sUblI.fLimit
        eRet = etc_trans_sXX_XXXX(eTrans, &(pu->sUblI.fLimit), &sFmt06_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXX_XXXX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sUblI.fLimit = sFmt06_f;
        
        // sUblI.fFactor
        eRet = etc_trans_XX_XX(eTrans, &(pu->sUblI.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sUblI.fFactor = sFmt10_f;

    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        pu->ucTimeLossV    = pf->ucTimeLossV;
        pu->sOverV.ucTime  = pf->sOverI.ucTime;
        pu->sLossV.ucTime  = pf->sLossV.ucTime;
        pu->sOverI.ucTime  = pf->sOverI.ucTime;
        pu->sSuperI.ucTime = pf->sSuperI.ucTime; 
        pu->sZeroI.ucTime  = pf->sZeroI.ucTime;  
        pu->sUblV.ucTime   = pf->sUblV.ucTime; 
        pu->sUblI.ucTime   = pf->sUblI.ucTime; 

        // fDropV
        sFmt08_f = pf->fDropV;
        eRet = etc_trans_XXX_X(eTrans, &(pu->fDropV), &sFmt08_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }

        // sOverV.fUpUp
        sFmt08_f = pf->sOverV.fUpUp ;
        eRet = etc_trans_XXX_X(eTrans, &(pu->sOverV.fUpUp), &sFmt08_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sOverV.fFactor
        sFmt10_f  =  pf->sOverV.fFactor;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sOverV.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sLossV.fDownDown
        sFmt08_f =  pf->sLossV.fDownDown;
        eRet = etc_trans_XXX_X(eTrans, &(pu->sLossV.fDownDown), &sFmt08_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }

        // sLossV.fFactor
        sFmt10_f = pf->sLossV.fFactor;

        eRet = etc_trans_XX_XX(eTrans, &(pu->sLossV.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sOverI.fUpUp
        sFmt09_f = pf->sOverI.fUpUp;
        eRet = etc_trans_sXXX_XXX(eTrans, &(pu->sOverI.fUpUp), &sFmt09_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sOverI.fFactor
        sFmt10_f =  pf->sOverI.fFactor;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sOverI.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sSuperI.fUp
        sFmt09_f = pf->sSuperI.fUp;
        eRet = etc_trans_sXXX_XXX(eTrans, &(pu->sSuperI.fUp), &sFmt09_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sSuperI.fFactor
        sFmt10_f = pf->sSuperI.fFactor;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sSuperI.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sZeroI.fUpUp
        sFmt09_f = pf->sZeroI.fUp;
        eRet = etc_trans_sXXX_XXX(eTrans, &(pu->sZeroI.fUp), &sFmt09_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXXX_XXX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sZeroI.fFactor
        sFmt10_f = pf->sZeroI.fFactor;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sZeroI.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sUblV.fLimit
        sFmt06_f = pf->sUblV.fLimit ;
        eRet = etc_trans_sXX_XXXX(eTrans, &(pu->sUblV.fLimit), &sFmt06_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXX_XXXX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sUblV.fFactor
        sFmt10_f = pf->sUblV.fFactor;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sUblV.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sUblI.fLimit
        sFmt06_f = pf->sUblI.fLimit;
        eRet = etc_trans_sXX_XXXX(eTrans, &(pu->sUblI.fLimit), &sFmt06_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_sXX_XXXX() error %d!", eRet);
            #endif
            return eRet;
        }

        // sUblI.fFactor
        sFmt10_f = pf->sUblI.fFactor;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sUblI.fFactor), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f27() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f27() para eTrans is out of range!");
        #endif
        return TC_ERR_OUTRNG;
    }

    // ���֡�೤��
    *pusLen = sizeof(sTcAfn04f27_f);
    return TC_OK;
}


/*****************************************************************************
 �� �� ��  : etc_trans_afn04f28
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F28_ELEC_LMIT_FACTR
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��8��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f28(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr        eRet = TC_OK;
    sTcAfn04F28    *pu = NULL;
    sTcAfn04F28_f  *pf = NULL;
    sTcFmt10_f    sFmt10_f;

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f28() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn04F28*)pUser;
    pf = (sTcAfn04F28_f*)pFrame;
    memset(&sFmt10_f, 0, sizeof(sTcFmt10_f));

    if(TC_TRANS_F2U == eTrans)
    {
        // fPara1
        sFmt10_f = pf->fPara1;
        eRet = etc_trans_XX_XX(eTrans, &(pu->fPara1), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f28() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fPara2
        sFmt10_f = pf->fPara2;
        eRet = etc_trans_XX_XX(eTrans, &(pu->fPara2), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f28() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fWarning
        sFmt10_f = pf->fWarning;
        eRet = etc_trans_XX_XX(eTrans, &(pu->fWarning), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f28() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        
    }
    else if( TC_TRANS_U2F == eTrans)
    {
        // fPara1
        eRet = etc_trans_XX_XX(eTrans, &(pu->fPara1), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f28() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->fPara1 = sFmt10_f;
        
        // fPara2
        eRet = etc_trans_XX_XX(eTrans, &(pu->fPara2), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f28() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->fPara2 = sFmt10_f;

        // fWarning
        eRet = etc_trans_XX_XX(eTrans, &(pu->fWarning), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f28() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
   
        pf->fWarning = sFmt10_f;
    }
    else
    {
       #ifdef TC_DBG
       TCDBG("etc_trans_afn04f28() para eTrans is out of range!");
       #endif
       return TC_ERR_OUTRNG;
    }

    // �������
    *pusLen = sizeof(sTcFactorLimit_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f29
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F29_ELEC_FIX_HARM
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��8��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f29(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr          eRet = TC_OK;
    sTcAfn04F29      *pu = NULL;
    sTcAfn04F29_f    *pf = NULL;
    sTcFmt10_f  sFmt10_f = {0};
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f29() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn04F29*)pUser;
    pf = (sTcAfn04F29_f*)pFrame;

    if(TC_TRANS_F2U == eTrans)
    {

        // (1)sVa
        // fTotal
        sFmt10_f = pf->sVa.fTotal;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVa.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fOdd
        sFmt10_f = pf->sVa.fOdd;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVa.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fEven
        sFmt10_f = pf->sVa.fEven;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVa.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // (2)sVb
        // fTotal
        sFmt10_f = pf->sVb.fTotal;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVb.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fOdd
        sFmt10_f = pf->sVb.fOdd;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVb.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fEven
        sFmt10_f = pf->sVb.fEven;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVb.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // (3)sVc
        // fTotal
        sFmt10_f = pf->sVc.fTotal;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVc.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fOdd
        sFmt10_f = pf->sVc.fOdd;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVc.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fEven
        sFmt10_f = pf->sVc.fEven;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVc.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // (4)sIa
        // fTotal
        sFmt10_f = pf->sIa.fTotal;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIa.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fOdd
        sFmt10_f = pf->sIa.fOdd;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIa.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fEven
        sFmt10_f = pf->sIa.fEven;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIa.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // (5)sIb
        // fTotal
        sFmt10_f = pf->sIb.fTotal;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIb.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fOdd
        sFmt10_f = pf->sIb.fOdd;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIb.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fEven
        sFmt10_f = pf->sIb.fEven;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIb.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // (6)sIc
        // fTotal
        sFmt10_f = pf->sIc.fTotal;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIc.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fOdd
        sFmt10_f = pf->sVb.fOdd;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIc.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fEven
        sFmt10_f = pf->sIc.fEven;
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIc.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
    }
    else if(TC_TRANS_U2F == eTrans)
    {

        // (1)sVa
        // fTotal
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVa.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVa.fTotal = sFmt10_f;
            
        // fOdd
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVa.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVa.fOdd = sFmt10_f;
            
        // fEven
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVa.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVa.fEven = sFmt10_f;
        
        // (2)sVb
        // fTotal
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVb.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVb.fTotal = sFmt10_f;
        
        // fOdd
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVb.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVb.fOdd = sFmt10_f;
        
        // fEven
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVb.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVb.fEven = sFmt10_f;
        
        // (3)sVc
        // fTotal
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVc.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVc.fTotal = sFmt10_f;
        
        // fOdd
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVc.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVc.fOdd = sFmt10_f;
        
        // fEven
        eRet = etc_trans_XX_XX(eTrans, &(pu->sVc.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVc.fEven = sFmt10_f;
        
        // (4)sIa
        // fTotal
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIa.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sIa.fTotal = sFmt10_f;
        
        // fOdd
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIa.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sIa.fOdd = sFmt10_f;
        
        // fEven
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIa.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sIa.fEven = sFmt10_f;
        
        // (5)sIb
        // fTotal
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIb.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sIb.fTotal = sFmt10_f;
        
        // fOdd
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIb.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sIb.fOdd = sFmt10_f;
        
        // fEven
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIb.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sIb.fEven = sFmt10_f;
        
        // (6)sIc
        // fTotal
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIc.fTotal), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sIc.fTotal = sFmt10_f;
        
        // fOdd
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIc.fOdd), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sVb.fOdd = sFmt10_f;
        
        // fEven
        eRet = etc_trans_XX_XX(eTrans, &(pu->sIc.fEven), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f29() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        pf->sIc.fEven = sFmt10_f;
    }
    else
    {
       #ifdef TC_DBG
       TCDBG("etc_trans_afn04f29() para eTrans is out of range!");
       #endif
       return TC_ERR_OUTRNG;
    }
        
    // �������
    *pusLen = sizeof(sTcElecFixHarm_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f30
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F30_ELEC_FLASH
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��11��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f30(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr        eRet = TC_OK;
    sTcAfn04f30    *pu = NULL;
    sTcAfn04f30_f  *pf = NULL;
    sTcFmt10_f sFmt10_f;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f30() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn04f30*)pUser;
    pf = (sTcAfn04f30_f*)pFrame;
    memset(&sFmt10_f, 0, sizeof(sTcFmt10_f));

    if(TC_TRANS_F2U == eTrans)
    {

        // fLong
        sFmt10_f = pf->fLong;
        eRet = etc_trans_XX_XX(eTrans, &(pu->fLong), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f30() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }

        // fShort
        sFmt10_f = pf->fShort;
        eRet = etc_trans_XX_XX(eTrans, &(pu->fShort), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f30() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
    }
    else if(TC_TRANS_U2F == eTrans)
    {
        // fLong
        eRet = etc_trans_XX_XX(eTrans, &(pu->fLong), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f30() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->fLong = sFmt10_f;
        
        // fShort
        eRet = etc_trans_XX_XX(eTrans, &(pu->fShort), &sFmt10_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f30() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->fShort = sFmt10_f;
    }
    else
    {
       #ifdef TC_DBG
       TCDBG("etc_trans_afn04f30() para eTrans is out of range!");
       #endif
       return TC_ERR_OUTRNG;
    }
    
    // �������
    *pusLen = sizeof(sTcElecFlash_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f33
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F33_NELC_MP_CFG
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��11��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f33(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn04f25(eTrans, pUser, pFrame,  pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f34
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F34_NELC_MP_PARA
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��11��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f34(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr        eRet = TC_OK;
    UINT8        ucTmp = 0;
    sTcAfn04f34    *pu = NULL;
    sTcAfn04f34_f  *pf = NULL;
    sTcFmt11_f     sDouble_f;            
    sTcDouble      sDouble;     
    sTcDouble      sUp;          
    sTcDouble      sDown;  

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f34() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn04f34*)pUser;
    pf = (sTcAfn04f34_f*)pFrame;
    memset(&sDouble_f, 0, sizeof(sTcFmt11_f));
    memset(&sDouble,   0, sizeof(sTcDouble));
    memset(&sUp,       0, sizeof(sTcDouble));
    memset(&sDown,     0, sizeof(sTcDouble));

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        sUp.ePrec    = pu->sUp.ePrec;
        sUp.dValue   = pu->sUp.dValue;
        sDown.ePrec  = pu->sDown.ePrec;
        sDown.dValue = pu->sDown.dValue;

        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f34()u2f pu->sUp ePrec =%d dValue =%f", pu->sUp.ePrec, pu->sUp.dValue);
        TCDBG("etc_trans_afn04f34() u2f pu->sDown ePrec =%d dValue =%f", pu->sDown.ePrec, pu->sDown.dValue);
        #endif

        // eType
        switch(pu->eType)
        {

            case TC_NELC_TEMP:
                ucTmp = 1;
                break;
                
            case TC_NELC_FLOW:
                ucTmp = 2;
                break;

            case TC_NELC_FV:
                ucTmp = 3;
                break;
                
            case TC_NELC_PRESS:
                ucTmp = 4;
                break;    
                
            case TC_NELC_HUMI:
                ucTmp = 5;
                break;
                
            case TC_NELC_LIGHT:
                ucTmp = 6;
                break;
                
            case TC_NELC_RV:
                ucTmp = 7;
                break;
                
            case TC_NELC_420MA:
                ucTmp = 8;
                break;
                
            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn04f34() eType is out of range!");
                #endif
                return TC_ERR_OUTRNG;      
               // break;
        }
        
        pf->eType = ucTmp;

        // sUp
        eRet = etc_trans_sX7(eTrans, &sUp, &sDouble_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f34() etc_trans_sX7() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sUp = sDouble_f;

        // sDown
        eRet = etc_trans_sX7(eTrans, &sDown, &sDouble_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f34() etc_trans_sX7() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sDown = sDouble_f;
    }
    // ��֡�ൽ�û���
    else if (TC_TRANS_F2U == eTrans)
    {
        switch(pf->eType)
        {
            case 1:
                pu->eType = TC_NELC_TEMP;
                break;
                
            case 2:
                pu->eType = TC_NELC_FLOW;
                break;

            case 3:
                pu->eType = TC_NELC_FV;
                break;

            case 4:
                pu->eType = TC_NELC_PRESS;
                break;

            case 5:
                pu->eType = TC_NELC_HUMI;
                break;
                
            case 6:
                pu->eType = TC_NELC_LIGHT;
                break;
                
            case 7:
                pu->eType = TC_NELC_RV;
                break;
                
            case 8:
                pu->eType = TC_NELC_420MA;
                break;
                
            default:
                pu->eType = TC_NELC_UNKOWN;
                break;
        }

        // sUp
        sDouble_f  = pf->sUp ;
        eRet = etc_trans_sX7(eTrans, &sDouble, &sDouble_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f34() etc_trans_sX7() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pu->sUp = sDouble;
        
        // sDown
        sDouble_f  = pf->sDown ;
        eRet = etc_trans_sX7(eTrans, &sDouble, &sDouble_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn04f34() etc_trans_sX7() error %d!", eRet);
            #endif
            return eRet;
        }

        pu->sDown = sDouble;

        #ifdef TC_DBG
        TCDBG("etc_trans_afn04f34() f2u pu->sUp ePrec =%d dValue =%f", pu->sUp.ePrec, pu->sUp.dValue);
        TCDBG("etc_trans_afn04f34() f2u pu->sDown ePrec =%d dValue =%f", pu->sDown.ePrec, pu->sDown.dValue);
        #endif
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn04f34() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
    
    // �������
    *pusLen = sizeof(sTcAfn04f34_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn04f35
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_4_F35_NELC_MP_LMIT
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��11��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn04f35(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn04f34(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn05f1
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_5_F1_CHECK_TIME
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��12��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn05f1(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr       eRet = TC_OK;
    sTcYWMDhms    *pu = NULL;
    sTcYWMDhms_f  *pf = NULL;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn05f1() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    pu = (sTcYWMDhms*)pUser;
    pf = (sTcYWMDhms_f *)pFrame;
    
    eRet = etc_trans_YWMDhms(eTrans, pu, pf);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn05f1() etc_trans_YWMDhms() error %d!", eRet);
        #endif
        return eRet;
    }

    // �������
    *pusLen = sizeof(sTcYWMDhms_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn05f2
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_5_F2_FREZ_TEMP
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��12��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn05f2(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    eTcErr       eRet = TC_OK;
    sTcAfn05f2    *pu = NULL;
    sTcAfn05f2_f  *pf = NULL;
    UINT8       ucTmp = 0;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn05f1() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    pu = (sTcAfn05f2*)pUser;
    pf = (sTcAfn05f2_f *)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        eRet = etc_cmdpn_to_dadt(TC_AFN_13_ASKR, &(pf->sDaDt[0]), &ucTmp, &(pu->sCmdPn[0]), pu->ucNum);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn05f2() etc_cmdpn_to_dadt() error %d!", eRet);
            #endif
            return eRet;
        }

        // ucNum
        pf->ucNum = ucTmp;
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {

        eRet = etc_dadt_to_cmdpn(TC_AFN_13_ASKR, &(pf->sDaDt[0]), pf->ucNum, &(pu->sCmdPn[0]), &ucTmp);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn05f2() etc_dadt_to_cmdpn() error %d!", eRet);
            #endif
            return eRet;
        }

        pu->ucNum = ucTmp;
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn05f2() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
    
    // �������
    *pusLen = sizeof(sTcDaDt)*ucTmp + sizeof(pf->ucNum);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn05f5
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_5_F5_NX_MODEL_ACT
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn05f5(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn05f5    *pu = NULL;
    sTcAfn05f5_f  *pf = NULL;
    INT32           i = 0;
    UINT8         ucN = 0;
    eTcErr       eRet = TC_OK;
    sTcYWMDhms_f  sYWMDhms_f;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn05f5() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn05f5   *)pUser;
    pf = (sTcAfn05f5_f *)pFrame;
    memset(&sYWMDhms_f, 0, sizeof(sTcYWMDhms_f));

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // ucN
        pf->ucN = pu->ucN;
        ucN = pf->ucN;

        // sOne
        for(i = 0; i < ucN; i++)
        {
            // id
            pf->sOne[i].ucID = pu->sOne[i].ucID;
            
            // sTime
            eRet = etc_trans_YWMDhms(eTrans, &(pu->sOne[i].sTime), &sYWMDhms_f);
            if (TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn05f5() etc_trans_YWMDhms() error %d!", eRet);
                #endif
                return eRet;
            }

            pf->sOne[i].sTime = sYWMDhms_f;
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // ucN
        pu->ucN = pf->ucN;
        ucN = pf->ucN;

        // sOne
        for(i = 0; i < ucN; i++)
        {
            // id
            pu->sOne[i].ucID = pf->sOne[i].ucID;

            // sTime
            sYWMDhms_f = pf->sOne[i].sTime;
            eRet = etc_trans_YWMDhms(eTrans, &(pu->sOne[i].sTime), &sYWMDhms_f);
            if (TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn05f5() etc_trans_YWMDhms() error %d!", eRet);
                #endif
                return eRet;
            }
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn05f5() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
    *pusLen = sizeof(sTcNxModelOne_f) * ucN + sizeof(UINT8);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn05f6
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_5_F6_NX_MODEL_CLR
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn05f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn05f6   *pu = NULL;
    sTcAfn05f6_f *pf = NULL;
    INT32           i = 0;
    UINT8         ucN = 0;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn05f6() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn05f6*)pUser;
    pf = (sTcAfn05f6_f *)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // ucN
        pf->ucN = pu->ucN;
        ucN = pf->ucN;

        // sOne
        for(i = 0; i < ucN; i++)
        {
           pf->ucID[i] = pu->ucID[i];
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // ucN
        pu->ucN = pf->ucN;
        ucN = pu->ucN;
        
        // sOne
        for(i = 0; i < ucN; i++)
        {
           pu->ucID[i] = pf->ucID[i];
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn05f6() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
    *pusLen = sizeof(UINT8) * (pf->ucN) + sizeof(UINT8);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn05f7
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_5_F7_RQ_RESPN_ACT
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn05f7(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn05f6(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn05f8
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_5_F8_RQ_RESPN_CLT
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn05f8(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn05f6(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn05f17
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_5_F17_REMOTE_OFF
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��12��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn05f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    eTcErr        eRet = TC_OK;
    sTcAfn05f17    *pu = NULL;
    sTcAfn05f17_f  *pf = NULL;
    INT32            i = 0;
    sTcYMDhm_f   sYMDhm_f;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn05f17() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn05f17*)pUser;
    pf = (sTcAfn05f17_f *)pFrame;
    memset(&sYMDhm_f, 0, sizeof(sTcYMDhm_f));

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // bOff
        pf->bOff = 0;
        for(i = 0; i < 8; i++)
        {
            if(TRUE == pu->bOff[i])
            {
                pf->bOff |= (0x01 << i);
            }
        }
        
        // sTimeStart
        eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTimeStart), &sYMDhm_f);
        if ( TC_OK != eRet )
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn05f17() etc_trans_YYMMDDhhmm() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->sTimeStart = sYMDhm_f;

        // sTimeEnd
        eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTimeEnd), &sYMDhm_f);
        if ( TC_OK != eRet )
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn05f17() etc_trans_YYMMDDhhmm() error %d!", eRet);
            #endif
            return eRet;
        }      

        pf->sTimeEnd = sYMDhm_f;
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        for (i = 0; i < 8; i++)
        {
            if (pf->bOff & (0x01 << i))
            {
                pu->bOff[i] = TRUE;
            }
            else
            {
                pu->bOff[i] = FALSE;
            }
        }
        
        // sTimeStart
        sYMDhm_f = pf->sTimeStart;
        eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTimeStart), &sYMDhm_f);
        if ( TC_OK != eRet )
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn05f17() etc_trans_YYMMDDhhmm() error %d!", eRet);
            #endif
            return eRet;
        }

        // sTimeEnd        
        sYMDhm_f = pf->sTimeEnd;
        eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTimeEnd), &sYMDhm_f);
        if ( TC_OK != eRet )
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn05f17() etc_trans_YYMMDDhhmm() error %d!", eRet);
            #endif
            return eRet;
        } 
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn05f17() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    // �������
    *pusLen = sizeof(sTcAfn05f17_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn05f18
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_5_F18_REMOTE_ON
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��12��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn05f18(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn05f18    *pu = NULL;
    sTcAfn05f18_f  *pf = NULL;
    INT32            i = 0;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn05f18() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn05f18*)pUser;
    pf = (sTcAfn05f18_f *)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // bOff
        pf->bOn = 0;
        for(i = 0; i < 8; i++)
        {
            if(TRUE == pu->bOn[i])
            {
                pf->bOn |= (0x01 << i);
            }
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        for (i = 0; i < 8; i++)
        {
            if (pf->bOn & (0x01 << i))
            {
                pu->bOn[i] = TRUE;
            }
            else
            {
                pu->bOn[i] = FALSE;
            }
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn05f18() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    // �������
    *pusLen = sizeof(UINT8);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn10f11
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_A_F11_TML_SPRT_EVENT
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn10f11(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn10f11   *pu = NULL;
    sTcAfn10f11_f *pf = NULL;
    INT32           i = 0;

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn10f11() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn10f11*)pUser;
    pf = (sTcAfn10f11_f *)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // ֡��������0
        memset(pf, 0x0, sizeof(sTcAfn10f11_f));
        
        for(i = 0; i < TC_ERC_NUM_MAX; i++)
        {
            if(TRUE == pu->bSuprt[i])
            {
                pf->ucEvent[i/8] |= (0x01 << (i%8));
            }
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        for(i = 0; i < TC_ERC_NUM_MAX; i++)
        {
            if((UINT8)(pf->ucEvent[i/8]) & (0x01 << (i%8)))
            {
                pu->bSuprt[i] = TRUE;
            }
            else
            {
                pu->bSuprt[i] = FALSE;
            }
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn10f11() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
   *pusLen = sizeof(sTcAfn10f11_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn10f12
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_A_F12_ELEC_MP_INFO
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn10f12(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn10f12   *pu = NULL;
    sTcAfn10f12_f *pf = NULL;
    INT32           i = 0;
    INT32           k = 0;
    INT32           j = 0;
    INT32        kMax = 0;
    UINT8       ucDa1 = 0;
    UINT16    usPn    = 0;
    UINT16    usPnMin = 0;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn10f12() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn10f12*)pUser;
    pf = (sTcAfn10f12_f *)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // ucSprt
        pf->ucSprt = pu->ucSprt;

        // �ҵ�pn��Сֵȷ����ʼDa2
        usPnMin = pu->usPn[0];
        for(i = 0; i < pu->usNum; i++)
        {
            usPn = pu->usPn[i];
            if(usPn < TC_PN_MIN || usPn > TC_PN_MAX)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn10f12() para usPn is out of range!");
                #endif
                return TC_ERR_OUTRNG;
            }

            // ȡ��pn��Сֵ
            usPnMin = (usPnMin < usPn) ? usPnMin : usPn;
        }

        // ����С��Da2
        pf->ucSDa2 = ((usPnMin - 1) / 8 + 1);

        // Da1
        for(i = 0; i < pu->usNum; i++)
        {
            usPn = pu->usPn[i];

            // ����ڱ����е�Da2������
            k = ((usPn - 1) / 8 + 1) - pf->ucSDa2;
            pf->ucDa1[k] |= 0x01 << ((usPn - 1) % 8);

            // ȡ��KMax
            kMax = kMax > k ? kMax : k;
        }

        pf->ucK = kMax + 1;

    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // ucSprt
        pu->ucSprt = pf->ucSprt;

        // usPn
        for(i = 0; i < pf->ucK; i++)
        {
            ucDa1 = pf->ucDa1[i];
            for(k = 0; k < 8; k++)
            {
                if(ucDa1 & (0x01 << k))
                {
                    pu->usPn[j++] = (i + pf->ucSDa2 - 1) * 8 + k + 1;
                }
            }
        }

        pu->usNum = j;
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn10f12() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
   *pusLen = sizeof(UINT8) * (pf->ucK) + sizeof(UINT8)* 3;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn10f13
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_A_F13_NELC_MP_INFO
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn10f13(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn10f12(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn10f14
 ��������  : ���ݽṹת������  
 ��Ӧ����  : TCMD_AFN_A_F14_TML_PROTO_SPRT
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 ����˵��  : ��n=0ʱ����ʾ����˿ڲ�֧���κ�ͨ��Э�飬�� 46��ʾ�����ݵ�ԪҲ�ͽ���һ�ֽ�
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn10f14(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn10f14   *pu = NULL;
    sTcAfn10f14_f *pf = NULL;
    INT32           i = 0;
    UINT16      usLen = 0;
  
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn10f14() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn10f14*)pUser;
    pf = (sTcAfn10f14_f *)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // ucN
        pf->ucN = pu->ucN;
        usLen += 1;
        if(pu->ucN != 0)
        {
            pf->ucM = pu->ucM;
            pf->ucK = pu->ucK;
            usLen += 2;
            for(i = 0; i < pu->ucK; i++)
            {
                // eType
                switch(pu->sOne[i].eType)
                {                    
                    case TC_ACS_PROT_DLT645_97:
                        pf->sOne[i].eType = 1;
                        break;         
                        
                    case TC_ACS_PROT_DLT645_07:
                        pf->sOne[i].eType = 2;
                        break;      
                        
                    case TC_ACS_PROT_MODBUS:
                        pf->sOne[i].eType = 3;
                        break;
                        
                    default:
                        pf->sOne[i].eType = pu->sOne[i].eType;
                        break;
                }
                
                usLen += 1;
                
                // strName
                memcpy(pf->sOne[i].strName, pf->sOne[i].strName, TC_PROTO_NAME_LEN);
                usLen += TC_PROTO_NAME_LEN;
            }
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // ucN
        pu->ucN = pf->ucN;
        usLen += 1;
        if(pf->ucN != 0)
        {
            pu->ucM = pf->ucM;
            pu->ucK = pf->ucK;
            usLen += 2;
            for(i = 0; i < pu->ucK; i++)
            {
                if(pf->sOne[i].eType >= 128)
                {
                    pu->sOne[i].eType = TC_ACS_PROT_USER;
                }
                else
                {
                    switch(pf->sOne[i].eType)
                    {                   
                        case 1:
                           pu->sOne[i].eType = TC_ACS_PROT_DLT645_97;
                           break;    
                           
                        case 2:
                           pu->sOne[i].eType = TC_ACS_PROT_DLT645_07;
                           break;     
                           
                        case 3:
                           pu->sOne[i].eType = TC_ACS_PROT_MODBUS;
                           break;     
           
                         default:
                           pu->sOne[i].eType = TC_ACS_PROT_UNKOWN;
                           break;
                    }
                }

                usLen += 1;

                // strName
                memcpy(pu->sOne[i].strName, pf->sOne[i].strName, TC_PROTO_NAME_LEN);
                usLen += TC_PROTO_NAME_LEN;
            }
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn10f14() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
   *pusLen = usLen;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn10f15
 ��������  : ���ݽṹת������  
 ��Ӧ����  : TCMD_AFN_A_F15_TML_MODEL_VERSION
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 ����˵��  : ��n=0ʱ����ʾ����˿ڲ�֧���κ�ͨ��Э�飬�� 46��ʾ�����ݵ�ԪҲ�ͽ���һ�ֽ�
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn10f15(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn10f15   *pu = NULL;
    sTcAfn10f15_f *pf = NULL;
    eTcErr       eRet = TC_OK;
    INT32           i = 0;
    UINT16      usLen = 0;
    UINT16   usLenTmp = 0;
  
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn10f15() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn10f15*)pUser;
    pf = (sTcAfn10f15_f *)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // ucN
        pf->ucN = pu->ucN;
        usLen += 1;
        if(pu->ucN != 0)
        {
            pf->ucM = pu->ucM;
            pf->ucK = pu->ucK;
            usLen += 2;
            for(i = 0; i < pu->ucK; i++)
            {
                // sOne
                // ucID
                pf->sOne[i].ucID = pu->sOne[i].ucID;
                usLen += 1;

                // sVersion
                eRet = etc_trans_version(eTrans, &(pu->sOne[i].sVersion), &(pf->sOne[i].sVersion), &usLenTmp);
                if(TC_OK != eRet)
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn10f15() etc_trans_version() error %d!", eRet);
                    #endif
                    return eRet;
                }
                
                usLen += usLenTmp;
            }
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // ucN
        pu->ucN = pf->ucN;
        usLen += 1;
        if(pf->ucN != 0)
        {
            pu->ucM = pf->ucM;
            pu->ucK = pf->ucK;
            usLen += 2;
            for(i = 0; i < pu->ucK; i++)
            {
                // sOne
                // ucID
                pu->sOne[i].ucID = pf->sOne[i].ucID;
                usLen += 1;

                // sVersion
                eRet = etc_trans_version(eTrans, &(pu->sOne[i].sVersion), &(pf->sOne[i].sVersion), &usLenTmp);
                if(TC_OK != eRet)
                {
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn10f15() etc_trans_version() error %d!", eRet);
                    #endif
                    return eRet;
                }
                
                usLen += usLenTmp;
            }
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn10f15() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
   *pusLen = usLen;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn10f16
 ��������  : ���ݽṹת������  
 ��Ӧ����  : TCMD_AFN_A_F16_TML_VERSION
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn10f16(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_version(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f1
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F1_CLOCK
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f1(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr eRet = TC_OK;
    eRet = etc_trans_YWMDhms(eTrans, (sTcYWMDhms*)pUser, (sTcYWMDhms_f*)pFrame);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f1() etc_trans_YWMDhms() error %d!", eRet);
        #endif
        return eRet;
    }

    *pusLen = sizeof(sTcYWMDhms_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f2
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F2_PARA_STATE
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f2(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f2   *pu = NULL;
    sTcAfn13f2_f *pf = NULL;
    INT32          i = 0;
    INT32          j = 0;
    UINT8      ucTmp = 0;
    UINT8      ucVal = 0;
    eTcmd       eCmd = TCMD_AFN_F_UNKOWN;
  
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f2() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f2*)pUser;
    pf = (sTcAfn13f2_f *)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // �����Ϸ���
        // �Ȳ�������,���������û��ڷ�֡ʱ�����Դ����ظ���������
        // TC_SET_NUM_MAX
        
        // ��������
        memset(pf->ucSet, 0x0, sizeof(sTcAfn13f2_f));
        
        // ��������
        for(i = 0; i < pu->ucNum; i++)
        {
            eCmd = pu->eCmd[i];

            // �жϸ������Ƿ������ò�������
            switch ( eCmd )
            {
                case TCMD_AFN_4_F1_CON_IP_PORT :
                case TCMD_AFN_4_F2_TML_UP_CFG:
                case TCMD_AFN_4_F3_TML_AUTH_PARA :
                case TCMD_AFN_4_F4_TML_STATE_INPUT :
                case TCMD_AFN_4_F5_TML_EVENT_CFG :
                case TCMD_AFN_4_F17_FREZ_TASK_PARA :
                case TCMD_AFN_4_F25_ELEC_MP_CFG :
                case TCMD_AFN_4_F26_ELEC_MP_BASE :
                case TCMD_AFN_4_F27_ELEC_LMIT_PARA :
                case TCMD_AFN_4_F28_ELEC_LMIT_FACTR :
                case TCMD_AFN_4_F29_ELEC_FIX_HARM :
                case TCMD_AFN_4_F30_ELEC_FLASH :
                case TCMD_AFN_4_F33_NELC_MP_CFG :
                case TCMD_AFN_4_F34_NELC_MP_PARA :
                case TCMD_AFN_4_F35_NELC_MP_LMIT :
                    break;
                    
                default:
                    #ifdef TC_DBG
                    TCDBG("etc_trans_afn13f2() eCmd para is out of range");
                    #endif
                    return TC_ERR_PARA;
                    // break;
            }

            // ��������Ӧ�����к�
            ucTmp = (UINT8)(eCmd & 0xFF);

            // ��������31���ֽ������е�λ��
            j = (ucTmp-1) / 8;
            ucVal = 0x01 << ((ucTmp-1) % 8);
            pf->ucSet[j] |= ucVal;
            
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        for(i = 0; i < 31; i++)
        {
            ucVal = pf->ucSet[i];
            for(j = 0; j < 8; j++)
            {
                if(ucVal & (0x01 << j))
                {
                    // ��������ݶ�Ӧ��������
                    eCmd = (eTcmd)(0x0400 | ((i * 8) + j + 1));

                    // �жϸ��������Ƿ���Ч
                    switch ( eCmd )
                    {
                        case TCMD_AFN_4_F1_CON_IP_PORT :
                        case TCMD_AFN_4_F2_TML_UP_CFG:
                        case TCMD_AFN_4_F3_TML_AUTH_PARA :
                        case TCMD_AFN_4_F4_TML_STATE_INPUT :
                        case TCMD_AFN_4_F5_TML_EVENT_CFG :
                        case TCMD_AFN_4_F25_ELEC_MP_CFG :
                        case TCMD_AFN_4_F26_ELEC_MP_BASE :
                        case TCMD_AFN_4_F27_ELEC_LMIT_PARA :
                        case TCMD_AFN_4_F28_ELEC_LMIT_FACTR :
                        case TCMD_AFN_4_F29_ELEC_FIX_HARM :
                        case TCMD_AFN_4_F30_ELEC_FLASH :
                        case TCMD_AFN_4_F33_NELC_MP_CFG :
                        case TCMD_AFN_4_F34_NELC_MP_PARA :
                        case TCMD_AFN_4_F35_NELC_MP_LMIT :
                            break;
                            
                        default:
                            #ifdef TC_DBG
                            TCDBG("etc_trans_afn13f2() eCmd para is out of range");
                            #endif
                            return TC_ERR_PARA;
                            // break;
                    }

                    // ת������
                    pu->eCmd[ucTmp++] = eCmd;
                }
            }
        }

        // ����Ѿ����õĲ�������
        pu->ucNum = ucTmp;
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f2() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
   *pusLen = sizeof(sTcAfn13f2_f);   
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f3
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F3_EVENT_1
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f3(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    UINT16       *pu = NULL;
    UINT16       *pf = NULL;
   
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f3() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (UINT16*)pUser;
    pf = (UINT16*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        *pf = *pu;
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        *pu = *pf;
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f3() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
    *pusLen = sizeof(UINT16);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f4
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F4_EVENT_2
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f4(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f3(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f5
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F5_EVENT_STATE 
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f5(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f5    *pu = NULL;
    sTcAfn13f5_f  *pf = NULL;
    INT32           i = 0;
    INT32           j = 0;
    INT32       index = 0;
   
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f5() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f5*)pUser;
    pf = (sTcAfn13f5_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        for(i = 0; i < TC_ERC_NUM_MAX; i++)
        {
            if(TRUE == pu->bHave[i])
            {
                pf->ucHave[i/8] |= (0x01 << (i%8));
            }
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                index = i*8+j;
                if(index > TC_ERC_NUM_MAX)
                {
                    i = 100; // ��ѭ����������8�ϲ�Ҳ���˳�ѭ��
                    break;
                }
                
                if( pf->ucHave[i] & (0x01 << j))
                {
                    pu->bHave[index] = TRUE;
                }
                else
                {
                    pu->bHave[index] = FALSE;
                }
             }
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f5() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
    *pusLen = sizeof(sTcAfn13f5_f);    
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f6
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F6_POWR_TIMES
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f6    *pu = NULL;
    sTcAfn13f6_f  *pf = NULL;
    eTcErr       eRet = TC_OK;
    INT32           i = 0;
    UINT32      ulPow = 0;
    UINT32     ulData = 0;
    UINT8       ucTmp = 0;
    UINT8   ucData[7] = {0};

    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f6() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f6*)pUser;
    pf = (sTcAfn13f6_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // �ж����ݵ���Ч��
        if(pu->ulTimes > TC_POWR_TIMES_MAX)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f6() para ulPowerTimes is out of range!");
            #endif
            return TC_ERR_OUTRNG;
        }
        
        // ������ת��Ϊ����
        ulData = pu->ulTimes;

        for(i = 0; i < 6; i++)
        {
            ulPow     = ntc_pow(6-i);
            ucTmp     = ulData / ulPow;
            ulData   -= ucTmp  * ulPow; 
            ucData[i] = ucTmp  + '0';
        }
      
        // ת����bcd       
        eRet = etc_str_to_bcd((const UINT8*)ucData, pf->ucBcd, 6);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f6() etc_str_to_bcd() error %d!", eRet);
            #endif
            return eRet;
        }
        
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // ת����strs       
        eRet = etc_bcd_to_str((const UINT8*)&(pf->ucBcd[0]), (UINT8*)ucData, 3);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f6() etc_bcd_to_str() error %d!", eRet);
            #endif
            return eRet;
        }

        // ת��������
        pu->ulTimes = atol((const char*)ucData);
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f6() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
    *pusLen = sizeof(sTcAfn13f6_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f5
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F9_STATE
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f9(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f9    *pu = NULL;
    sTcAfn13f9_f  *pf = NULL;
    INT32           i = 0;
  
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f9() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f9*)pUser;
    pf = (sTcAfn13f9_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // bSt
        pf->ucSt8 = 0;
        for(i = 0; i < 8; i++)
        {
            if(TRUE == pu->bSt[i])
            {
                pf->ucSt8 |= (0x01 << i);
            }
        }
        
        // bCd
        pf->ucCd8 = 0;
        for(i = 0; i < 8; i++)
        {
            if(TRUE == pu->bCd[i])
            {
                pf->ucCd8 |= (0x01 << i);
            }
        }        
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // ucSt8
        for(i = 0; i < 8; i++)
        {
            if((0x01 << i) & pf->ucSt8)
            {
                pu->bSt[i] = TRUE;
            }
            else
            {
                pu->bSt[i] = FALSE;
            }
        }

        // ucCd8
        for(i = 0; i < 8; i++)
        {
            if((0x01 << i) & pf->ucCd8)
            {
                pu->bCd[i] = TRUE;
            }
            else
            {
                pu->bCd[i] = FALSE;
            }
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f9() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
    *pusLen = sizeof(sTcAfn13f9_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f17
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F17_POWR_HAVE_T
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f17    *pu = NULL;
    sTcAfn13f17_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f17() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f17*)pUser;
    pf = (sTcAfn13f17_f*)pFrame;

    if(TC_TRANS_F2U != eTrans && TC_TRANS_U2F != eTrans)
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f17() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    eRet = etc_trans_sXX_XXXX(eTrans, &(pu->fXX_XXXX), &(pf->fXX_XXXX));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f17() etc_trans_sXX_XXXX() error %d!", eRet);
        #endif
        return eRet;
    }

    // �������
    *pusLen = sizeof(sTcAfn13f17_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f18
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F18_POWR_NONE_T
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f18(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f17(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f19
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F19_DEMD_TIME_D
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f19(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f19    *pu = NULL;
    sTcAfn13f19_f  *pf = NULL;
    eTcErr        eRet = TC_OK;
  
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f19() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f19*)pUser;
    pf = (sTcAfn13f19_f*)pFrame;

    // fXX_XXXX
    eRet = etc_trans_sXX_XXXX(eTrans, &(pu->fXX_XXXX), &(pf->fXX_XXXX));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f19() etc_trans_sXX_XXXX() error %d!", eRet);
        #endif
        return eRet;
    }

    // sTime
    eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTime), &(pf->sTime));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f19() etc_trans_YYMMDDhhmm() error %d!", eRet);
        #endif
        return eRet;
    }

    // �������
    *pusLen = sizeof(sTcAfn13f19_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f21
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F21_FACTR_T
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f21    *pu = NULL;
    sTcAfn13f21_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f21() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f21*)pUser;
    pf = (sTcAfn13f21_f*)pFrame;

    if(TC_TRANS_F2U != eTrans && TC_TRANS_U2F != eTrans)
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f21() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    eRet = etc_trans_XX_XX(eTrans, &(pu->fXX_XX), &(pf->fXX_XX));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f21() etc_trans_XX_XX() error %d!", eRet);
        #endif
        return eRet;
    }

    // �������
    *pusLen = sizeof(sTcAfn13f21_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f22
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F22_FACTR_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f22(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f21(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f23
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F23_FACTR_B
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f23(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f21(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f24
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F24_FACTR_C
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f24(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f21(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f25
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F25_POWR_HAVE_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f25(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f17(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f26
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F26_POWR_HAVE_B
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f26(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f17(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f27
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F27_POWR_HAVE_C
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f27(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f17(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f28
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F28_POWR_NONE_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f28(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f17(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f29
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F29_POWR_NONE_B
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f29(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f17(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f30
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F30_POWR_NONE_C
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f30(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f17(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f33
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F33_POWR_HAVE_FRTH
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f33(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn13f33    *pu = NULL;
    sTcAfn13f33_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f33() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f33*)pUser;
    pf = (sTcAfn13f33_f*)pFrame;
    
    eRet = etc_trans_XXXXXX_XXXX(eTrans, &(pu->dXXXXXX_XXXX), &(pf->dXXXXXX_XXXX));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f33() etc_trans_XXXXXX_XXXX() error %d!", eRet);
        #endif
        return eRet;
    }

    // �������
    * pusLen = sizeof(sTcFmt04_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f34
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F34_POWR_HAVE_BACK
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f34(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f33(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f35
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F35_POWR_NONE_FRTH
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f35(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn13f35   *pu = NULL;
    sTcAfn13f35_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f35() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f35*)pUser;
    pf = (sTcAfn13f35_f*)pFrame;
    
    eRet = etc_trans_XXXXXX_XX(eTrans, &(pu->dXXXXXX_XX), &(pf->dXXXXXX_XX));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f35() etc_trans_XXXXXX_XX() error %d!", eRet);
        #endif
        return eRet;
    }

    // �������
    * pusLen = sizeof(sTcFmt05_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f36
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F36_POWR_NONE_BACK
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f36(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f35(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f41
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F41_VOLT_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f41(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn13f41    *pu = NULL;
    sTcAfn13f41_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    sTcFmt08_f fXXX_X;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f41() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f41*)pUser;
    pf = (sTcAfn13f41_f*)pFrame;
    memset(&fXXX_X, 0, sizeof(sTcFmt_XXX_X));
    
    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        eRet = etc_trans_XXX_X(eTrans, &(pu->fXXX_X), &fXXX_X);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f41() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->fXXX_X = fXXX_X;
    }
    // ֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        fXXX_X = pf->fXXX_X; 
        eRet = etc_trans_XXX_X(eTrans, &(pu->fXXX_X), &(pf->fXXX_X));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f41() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f41() para error!");
        #endif
        return TC_ERR_PARA;
    }
    
    // �������
    * pusLen = sizeof(sTcAfn13f41_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f42
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F58_VOLT_B
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f42(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f41(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f43
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F43_VOLT_C
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f43(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f41(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f44
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F44_VANGL_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f44(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn13f44    *pu = NULL;
    sTcAfn13f44_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    sTcFmt07_f    fsXXX_X;

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f44() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f44*)pUser;
    pf = (sTcAfn13f44_f*)pFrame;
    memset(&fsXXX_X, 0, sizeof(sTcFmt07_f));
    
    // �û��ൽ֡��
    if(TC_TRANS_U2F == eTrans)
    {
        eRet = etc_trans_sXXX_X(eTrans, &(pu->fsXXX_X), &fsXXX_X);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f44() etc_trans_sXXX_X() error %d!", eRet);
            #endif
            return eRet;
        }

        pf->fsXXX_X = fsXXX_X;
    }
    // ֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        fsXXX_X = pf->fsXXX_X;
        eRet = etc_trans_sXXX_X(eTrans, &(pu->fsXXX_X), &fsXXX_X);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f44() etc_trans_sXXX_X() error %d!", eRet);
            #endif
            return eRet;
        }
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f44() para error!");
        #endif
        return TC_ERR_PARA;
    }
    
    // �������
    * pusLen = sizeof(sTcAfn13f44_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f45
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F45_VANGL_B
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f45(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f44(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f46
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F46_VANGL_C
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f46(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f44(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f47
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F47_VOLT_UBL
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f47(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f27(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f48
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F48_CIRCLE_V
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f48(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f17(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f49
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F49_ELEC_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f49(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn13f49   *pu = NULL;
    sTcAfn13f49_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f49() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f49*)pUser;
    pf = (sTcAfn13f49_f*)pFrame;
    
    eRet = etc_trans_sXXX_XXX(eTrans, &(pu->fsXXX_XXX), &(pf->fsXXX_XXX));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f49() etc_trans_sXXX_XXX() error %d!", eRet);
        #endif
        return eRet;
    }

    // �������
    * pusLen = sizeof(sTcAfn13f49_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f50
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F50_ELEC_B
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f50(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f49(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f51
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F51_ELEC_C
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f51(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f49(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f52
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F52_ELEC_M
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f52(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f49(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f53
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F53_EANGL_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f53(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f44(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f54
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F54_EANGL_B
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f54(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f44(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f55
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F55_EANGL_C
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f55(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f44(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f56
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F56_ELEC_UBL
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f56(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    return etc_trans_afn13f44(eTrans, pUser, pFrame, pusLen);
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f57
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F57_VDMAX_A_TIME
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f57(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn13f57    *pu = NULL;
    sTcAfn13f57_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f57() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    pu = (sTcAfn13f57*)pUser;
    pf = (sTcAfn13f57_f*)pFrame;

    // fXXX_X
    eRet = etc_trans_XXX_X(eTrans, &(pu->fXXX_X), &(pf->fXXX_X));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f57() etc_trans_XXX_X() error %d!", eRet);
        #endif
        return eRet;
    }
    
    // sTime
    eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTime), &(pf->sTime));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f57() etc_trans_YYMMDDhhmm() error %d!", eRet);
        #endif
        return eRet;
    }

    * pusLen = sizeof(sTcVdMaxTimeA_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f60
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F60_IDMAX_A_TIME
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��13��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f60(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn13f60    *pu = NULL;
    sTcAfn13f60_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f60() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    pu = (sTcAfn13f60*)pUser;
    pf = (sTcAfn13f60_f*)pFrame;

    // fsXXX_XXX
    eRet = etc_trans_sXXX_XXX(eTrans, &(pu->fsXXX_XXX), &(pf->fsXXX_XXX));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f60() etc_trans_sXXX_XXX() error %d!", eRet);
        #endif
        return eRet;
    }
    
    // sTime
    eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTime), &(pf->sTime));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f60() etc_trans_YYMMDDhhmm() error %d!", eRet);
        #endif
        return eRet;
    }

    * pusLen = sizeof(sTcIdMaxTimeA_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f65
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F65_VDPP_TIME_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f65(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f97    *pu = NULL;
    sTcAfn13f97_f  *pf = NULL;
    eTcErr        eRet = TC_OK;  
    INT32            i = 0;
    UINT16       usPow = 0;
    UINT16      usData = 0;
    UINT8        ucTmp = 0;
    UINT8    ucData[5] = {0};
        
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f65() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f97*)pUser;
    pf = (sTcAfn13f97_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        if(pu->usMinutes > TC_BCD_XXXX_MAX)
        {
           #ifdef TC_DBG
           TCDBG("etc_trans_afn13f65() para usMinutes is out of range! usMinutes = %d", pu->usMinutes);
           #endif
           return TC_ERR_OUTRNG;
        }
        
        // ������ת��Ϊ����
        usData = pu->usMinutes;

        for(i = 0; i < 4; i++)
        {
            usPow     = ntc_pow(4-i);
            ucTmp     = usData / usPow;
            usData   -= ucTmp  * usPow; 
            ucData[i] = ucTmp  + '0';
        }

        // ת��Ϊbcd       
        eRet = etc_str_to_bcd(ucData, pf->ucBCD, 4);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f65() etc_str_to_bcd() error %d!", eRet);
            #endif
            return eRet;
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // ת����strs       
        eRet = etc_bcd_to_str(pf->ucBCD, ucData, 2);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f65() etc_bcd_to_str() error %d!", eRet);
            #endif
            return eRet;
        }

        // ת��������
        pu->usMinutes = (UINT16)atol((const char*)ucData);
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f65() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }
   
    // �������
    *pusLen = sizeof(sTcAfn13f97_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f113
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F113_HARM_VOLT_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f113(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f113     *pu = NULL;
    sTcAfn13f113_f   *pf = NULL;
    UINT8            ucN = 0;
    INT32              i = 0;
    eTcErr          eRet = TC_OK;
   
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f113() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f113*)pUser;
    pf = (sTcAfn13f113_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        ucN = pu->ucN;
        pf->ucN = ucN;
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        ucN = pf->ucN;
        pu->ucN = ucN;
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f113() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    if(ucN > TC_HARM_TIMES_MAX)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f113() para ucN is out of range! ucN = %d", ucN);
        #endif
        return TC_ERR_OUTRNG;
    }
            
    // fXXX_X
    for(i = 0; i < ucN; i++)
    {
        eRet = etc_trans_XXX_X(eTrans, &(pu->fXXX_X[i]), &(pf->fXXX_X[i]));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f113() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }
    }
        
    // �������
    *pusLen = sizeof(sTcFmt08_f) * ucN + 1;
     return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f116
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F116_HARM_ELEC_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f116(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f116     *pu = NULL;
    sTcAfn13f116_f   *pf = NULL;
    UINT8            ucN = 0;
    INT32              i = 0;
    eTcErr          eRet = TC_OK;
   
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f116() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f116*)pUser;
    pf = (sTcAfn13f116_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        ucN = pu->ucN;
        pf->ucN = ucN;
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        ucN = pf->ucN;
        pu->ucN = ucN;
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f116() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    if(ucN > TC_HARM_TIMES_MAX)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f116() para ucN is out of range! ucN = %d", ucN);
        #endif
        return TC_ERR_OUTRNG;
    }
            
    // fXXX_X
    for(i = 0; i < ucN; i++)
    {
        eRet = etc_trans_sXXX_XXX(eTrans, &(pu->fsXXX_XXX[i]), &(pf->fsXXX_XXX[i]));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f116() etc_trans_XXX_X() error %d!", eRet);
            #endif
            return eRet;
        }
    }
        
    // �������
    *pusLen = sizeof(sTcFmt09_f) * ucN + 1;
    
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn13f121
 ��������  : ���ݽṹת������
 ��Ӧ����  : MCMD_AFN_D_F153_HARM_VINC_A
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��15��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f121(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn13f121     *pu = NULL;
    sTcAfn13f121_f   *pf = NULL;
    UINT8            ucN = 0;
    INT32              i = 0;
    eTcErr          eRet = TC_OK;
   
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f121() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
   
    pu = (sTcAfn13f121*)pUser;
    pf = (sTcAfn13f121_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        ucN = pu->ucN;
        pf->ucN = ucN;
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        ucN = pf->ucN;
        pu->ucN = ucN;
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f121() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    if(ucN > TC_HARM_TIMES_MAX)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f121() para ucN is out of range! ucN = %d", ucN);
        #endif
        return TC_ERR_OUTRNG;
    }
            
    // fXXX_X
    for(i = 0; i < ucN; i++)
    {
        eRet = etc_trans_XX_XX(eTrans, &(pu->fXX_XX[i]), &(pf->fXX_XX[i]));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f116() etc_trans_XX_XX() error %d!", eRet);
            #endif
            return eRet;
        }
    }
        
    // �������
    *pusLen = sizeof(sTcFmt10_f) * ucN + 1;
    return TC_OK;
}
/*****************************************************************************
 �� �� ��  : etc_trans_afn13f137
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_D_F137_NELC_VALUE
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
 �������  : UINT16* pusLen  ���֡����ֽ���
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��11��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn13f137(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    eTcErr        eRet = TC_OK;
    UINT8        ucTmp = 0;
    sTcAfn13f137    *pu = NULL;
    sTcAfn13f137_f  *pf = NULL;
    sTcFmt11_f     sDouble_f;  

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn13f137() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn13f137*)pUser;
    pf = (sTcAfn13f137_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // eType
        switch(pu->eType)
        {
            case TC_NELC_TEMP:
                ucTmp = 1;
                break;
                
            case TC_NELC_FLOW:
                ucTmp = 2;
                break;

            case TC_NELC_FV:
                ucTmp = 3;
                break;
                
            case TC_NELC_PRESS:
                ucTmp = 4;
                break;    
                
            case TC_NELC_HUMI:
                ucTmp = 5;
                break;
                
            case TC_NELC_LIGHT:
                ucTmp = 6;
                break;
                
            case TC_NELC_RV:
                ucTmp = 7;
                break;
                
            case TC_NELC_420MA:
                ucTmp = 8;
                break;
                
            default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn13f137() eType is out of range!");
                #endif
                return TC_ERR_OUTRNG;      
               // break;
        }
        
        pf->eType = ucTmp;

        // sValue
        eRet = etc_trans_sX7(eTrans, &(pu->sDouble), &sDouble_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f137() etc_trans_sX7() error %d!", eRet);
            #endif
            return eRet;
        }
        
        pf->sDouble = sDouble_f;   
    }
    // ��֡�ൽ�û���
    else if (TC_TRANS_F2U == eTrans)
    {
        switch(pf->eType)
        {
            case 1:
                pu->eType = TC_NELC_TEMP;
                break;
                
            case 2:
                pu->eType = TC_NELC_FLOW;
                break;

            case 3:
                pu->eType = TC_NELC_FV;
                break;

            case 4:
                pu->eType = TC_NELC_PRESS;
                break;

            case 5:
                pu->eType = TC_NELC_HUMI;
                break;
                
            case 6:
                pu->eType = TC_NELC_LIGHT;
                break;
                
            case 7:
                pu->eType = TC_NELC_RV;
                break;
                
            case 8:
                pu->eType = TC_NELC_420MA;
                break;
                
            default:
                pu->eType = TC_NELC_UNKOWN;
                break;
        }
  
        // sValue
        sDouble_f = pf->sDouble;
        eRet = etc_trans_sX7(eTrans, &(pu->sDouble), &sDouble_f);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_trans_afn13f137() etc_trans_sX7() error %d!", eRet);
            #endif
            return eRet;
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn13f137() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    // �������
    *pusLen = sizeof(sTcFmt11_f) + sizeof(UINT8);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn12f9_m2s  (�������)
 ��������  : ���ݽṹת������
 ��Ӧ����  : TCMD_AFN_C_F9_FREZ_AUTO
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��11��14��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn12f9_m2s(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{  
    sTcAfn12f9    *pu = NULL;
    sTcAfn12f9_f  *pf = NULL;
    eTcErr       eRet = TC_OK;

    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn12f9_m2s() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(TC_TRANS_U2F != eTrans && TC_TRANS_F2U != eTrans)
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn12f9_m2s() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    pu = (sTcAfn12f9*)pUser;
    pf = (sTcAfn12f9_f *)pFrame;

    // sTs
    eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTs), &(pf->sTs));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn12f9_m2s() etc_trans_YYMMDDhhmm() error %d!", eRet);
        #endif
        return eRet;
    }

    // sTe
    eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTe), &(pf->sTe));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn12f9_m2s() etc_trans_YYMMDDhhmm() error %d!", eRet);
        #endif
        return eRet;
    }

    // �������
   *pusLen = sizeof(sTcAfn12f9_f);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_trans_afn12f9_s2m
 ��������  : ���ݽṹת������
 ��Ӧ����  : MCMD_AFN_C_F9_FREZ_AUTO
 �������  : eTcTrans eTrans  
             void* pUser      
             void* pFrame     
             UINT16* pusLen   
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��2��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_trans_afn12f9_s2m(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen)
{
    sTcAfn12f9A    *pu = NULL;
    sTcAfn12f9A_f  *pf = NULL;
    sTcDaDt   * psDaDt = NULL;
    pTcFunc      pFunc = NULL;   
    UINT8      *pTmp   = NULL;
    UINT8     ucNumTmp = 0;
    eTcErr        eRet = TC_OK;
    INT32            n = 0;
    INT32            m = 0;
    UINT16    usLenTmp = 0;
    UINT16    usLenOut = 0;
    eTcmd         eCmd = TCMD_AFN_F_UNKOWN;
    sTcmdInfor  sCmdInfor;
    eTcAFN        eAfn = TC_AFN_NULL;
    
    if(!pUser || !pFrame || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn12f9_s2m() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pu = (sTcAfn12f9A*)pUser;
    pf = (sTcAfn12f9A_f*)pFrame;

    // �û��ൽ��֡��
    if(TC_TRANS_U2F == eTrans)
    {
        // usPeriod
        pf->usPeriod = pu->usPeriod;
        usLenOut += sizeof(UINT16);
        
        // eUnit
        switch(pu->eUnit)
        {
            case TC_PUNT_MONTH:
                pf->eUnit = 1;
                break;
                
            case TC_PUNT_DAY:
                pf->eUnit = 2;
                break;
                    
            case TC_PUNT_HOUR:
                pf->eUnit = 3;
                break;

            case TC_PUNT_MIN:
                pf->eUnit = 4;
                break;

            case TC_PUNT_SEC:
                pf->eUnit = 5;
                break;
                    
            case TC_PUNT_MS:
                pf->eUnit = 6;
                break;
                
           default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn12f9_s2m() para pointer is error!");
                #endif
                return TC_ERR_PARA;
                //break;
        }

        usLenOut += 1;
         
        // ucN
        pf->ucN = pu->ucN;
        usLenOut += 1;
        
        // ucM
        pf->ucM = pu->ucM;
        usLenOut += 1;
            
        // sOne
        pTmp = &(pf->ucDaDt[0]);
        for(m = 0; m < pf->ucM; m++)
        {
            ucNumTmp = 0;
            // ��Ԫ��ʶ
            psDaDt = (sTcDaDt*)pTmp;
            eRet = etc_cmdpn_to_dadt(TC_AFN_13_ASKR, psDaDt, &ucNumTmp, &(pu->sOne[m].sCmdPn), 1);

            #if 0
            #ifdef TC_DBG
            TCDBG("etc_trans_afn12f9_s2m() eCmd = %04X!", pu->sOne[m].sCmdPn.eCmd);
            TCDBG("etc_trans_afn12f9_s2m() sTcDaDt ucDA1= %d!", psDaDt->ucDA1);
            TCDBG("etc_trans_afn12f9_s2m() sTcDaDt ucDA2= %d!", psDaDt->ucDA2);
            TCDBG("etc_trans_afn12f9_s2m() sTcDaDt ucDT1= %d!", psDaDt->ucDT1);
            TCDBG("etc_trans_afn12f9_s2m() sTcDaDt ucDT2= %d!", psDaDt->ucDT2);
            #endif    
            #endif    
            
            if(TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn12f9_s2m() etc_pnfn_to_dadt() error %d!", eRet);
                #endif
                return eRet;
            }

            eCmd = pu->sOne[m].sCmdPn.eCmd;
            eAfn = eTcGetCmdAfn(eCmd);
            if(TC_AFN_13_ASKR != eAfn)
            {
               #ifdef TC_DBG
               TCDBG("etc_trans_afn12f9_s2m() eCmd is out of range!");
               #endif
               return TC_ERR_OUTRNG;    
            }
            
            eRet = eTcGetCmdInfor(eCmd, TC_DIR_T2C, &sCmdInfor);
            if(TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn12f9_s2m() eTcGetCmdInfor() error %d!", eRet);
                #endif
                return eRet;
            }
            
            pFunc = sCmdInfor.pFunc;
            if(NULL == pFunc)
            {
               #ifdef TC_DBG
               TCDBG("etc_trans_afn12f9_s2m() eCmd is out of range!");
               #endif
               return TC_ERR_OUTRNG;  
            }
            
            // ���ݵ�Ԫ
            pTmp += sizeof(sTcDaDt);
            usLenOut += sizeof(sTcDaDt);
            for(n = 0; n < pu->ucN; n++)
            {
               eRet = pFunc(eTrans, &(pu->sOne[m].uApp[n]), pTmp, &usLenTmp);
               if(TC_OK != eRet)
               {
                   #ifdef TC_DBG
                   TCDBG("etc_trans_afn12f9_s2m() pFunc() error %d!", eRet);
                   #endif
                   return eRet;
               }

               pTmp += usLenTmp;
               usLenOut += usLenTmp;
            }     
        }
    }
    // ��֡�ൽ�û���
    else if(TC_TRANS_F2U == eTrans)
    {
        // usPeriod
        pu->usPeriod = pf->usPeriod;
        usLenOut += sizeof(UINT16);

         // eUnit
        switch(pf->eUnit)
        {
            case 1:
                pu->eUnit = TC_PUNT_MONTH;
                break;
                
            case 2:
                pu->eUnit = TC_PUNT_DAY;
                break;
                    
            case 3:
                pu->eUnit = TC_PUNT_HOUR;
                break;

            case 4:
                pu->eUnit = TC_PUNT_MIN;
                break;

            case 5:
                pu->eUnit = TC_PUNT_SEC;
                break;
                    
            case 6:
                pu->eUnit = TC_PUNT_MS;
                break;
                
           default:
                #ifdef TC_DBG
                TCDBG("etc_trans_afn12f9_s2m() para pointer is error!");
                #endif
                pu->eUnit = TC_PUNT_UNKOWN;
                break;
        }

        usLenOut += 1;

        // ucN
        pu->ucN = pf->ucN;
        usLenOut += 1;

        // usPeriod
        pu->ucM = pf->ucM;
        usLenOut += 1;
        
        // sOne
        pTmp = &(pf->ucDaDt[0]);
        
        for(m = 0; m < pf->ucM; m++)
        {
            ucNumTmp = 0;
            
            // ��Ԫ��ʶ
            psDaDt = (sTcDaDt*)pTmp;
            eRet = etc_dadt_to_cmdpn(TC_AFN_13_ASKR, psDaDt, 1, &(pu->sOne[m].sCmdPn), &ucNumTmp);
            if(TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn12f9_s2m() etc_dadt_to_cmdpn() error %d!", eRet);
                #endif
                return eRet;
            }

            eCmd = pu->sOne[m].sCmdPn.eCmd;

            #ifdef TC_DBG
            TCDBG("etc_trans_afn12f9_s2m() eCmd = %04X", eCmd);
            #endif
               
            eAfn = eTcGetCmdAfn(eCmd);
            if(TC_AFN_13_ASKR != eAfn)
            {
               #ifdef TC_DBG
               TCDBG("etc_trans_afn12f9_s2m() eCmd is out of range!");
               #endif
               return TC_ERR_OUTRNG;    
            }
            
            eRet = eTcGetCmdInfor(eCmd, TC_DIR_T2C, &sCmdInfor);
            if(TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etc_trans_afn12f9_s2m() eTcGetCmdInfor() error %d!", eRet);
                #endif
                return eRet;
            }
            
            pFunc = sCmdInfor.pFunc;
            if(NULL == pFunc)
            {
               #ifdef TC_DBG
               TCDBG("etc_trans_afn12f9_s2m() eCmd is out of range!");
               #endif
               return TC_ERR_OUTRNG;  
            }
            
            // ���ݵ�Ԫ
            pTmp += sizeof(sTcDaDt);
            usLenOut += sizeof(sTcDaDt);
                       
            for(n = 0; n < pu->ucN; n++)
            {
               eRet = pFunc(eTrans, &(pu->sOne[m].uApp[n]), pTmp, &usLenTmp);
               if(TC_OK != eRet)
               {
                   #ifdef TC_DBG
                   TCDBG("etc_trans_afn12f9_s2m() pFunc() error %d!", eRet);
                   #endif
                   return eRet;
               }

               pTmp += usLenTmp;
               usLenOut += usLenTmp;
            }     
        }
    }
    else
    {
         #ifdef TC_DBG
         TCDBG("etc_trans_afn12f9_s2m() eTrans is out of range!");
         #endif
         return TC_ERR_OUTRNG;    
    }

    // sTs
    eRet = etc_trans_YYMMDDhhmm(eTrans, &(pu->sTs), &(pf->sTs));
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_trans_afn12f9_m2s() etc_trans_YYMMDDhhmm() error %d!", eRet);
        #endif
        return eRet;
    }

    usLenOut += sizeof(sTcFmt02_f);
    
    // �������
    * pusLen = usLenOut;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : uctc_get_check_sum
 ��������  : ����У��ͺ���(У�����ȫ���û����ݵ�������,�����ǽ�λ(ģ256))
             �û�������:
             (1)������C
             (2)��ַ��A
             (3)��·�û�����

 �������  : UINT8 *pStartPos
             UINT16 usLen
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��1��16��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
UINT8 uctc_get_check_sum(UINT8 *pStartPos, UINT16 usLen)
{
    UINT8 ucCheckSum = 0;
    int i = 0;

    for(i = 0; i < usLen; i++)
    {
        ucCheckSum += pStartPos[i];
    }

    return ucCheckSum;
}

/*****************************************************************************
 �� �� ��  : eTcInit
 ��������  : Э���ʼ��
 �������  : sTcInit* sInit
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��25�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr eTcInit(sTcInit* psInit)
{
    if(g_bTcInit == TRUE)
    {
        return TC_OK;
    }

    if(!psInit)
    {
        #ifdef TC_DBG
        TCDBG("eTcInit() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(TC_ROLE_CONTOR != psInit->eRole && TC_ROLE_TERMIN != psInit->eRole)
    {
        #ifdef TC_DBG
        TCDBG("eTcInit() para error!");
        #endif
        return TC_ERR_PARA;
    }

    g_ucTcPermitDelayMinutes = psInit->ucPermitDelayMinutes;
    g_eTcRole = psInit->eRole;

    #if TC_CFG_SPT_CON
    if(psInit->eRole == TC_ROLE_TERMIN)
    {
        g_sTcEc.usEC1 = 0;
        g_sTcEc.usEC2 = 0;
    }
    #endif

    //pw
    #if TC_CFG_SPT_CON
    memcpy(g_aucTcPw, psInit->aucPw, TC_PW_LEN);
    #endif

    // ����������㷨
    #if TC_CFG_ENCRYPT
    g_peTcEncryptFunc = psInit->EncryptFunc;  // ���ܽӿ�
    g_peTcDecryptFunc = psInit->DecryptFunc;  // ���ܽӿ�
    #endif

    g_bTcInit = TRUE;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etcIsValidPack
 ��������  : �ж�һ��֡�Ƿ�����Ч��֡,�������ȷ�ķ������ǹ̶�֡���ǿɱ�֡
 �������  : const UINT8* pInBuf
             UINT16 usLen

 �������  : BOOL *pbFiexed
 �� �� ֵ  :
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��25�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etcIsValidPack(const UINT8* pInBuf, UINT16 usLen, BOOL *pbFiexed)
{
    UINT8  ucFrmCS       = 0;    // ֡�еļ����
    UINT8  ucCalCS       = 0;    // ���������У���
    UINT8  uc0x16        = 0;    // ֡������
    UINT16 usUserLen     = 0;
    UINT8  ucHead        = 0;

    sTcfHeadFixed *psHeadFixed = NULL;
    sTcfHeadAlter *psHeadAlter = NULL;

    if(!pInBuf || !pbFiexed)
    {
       #ifdef TC_DBG
       TCDBG("etcIsValidPack() pointer is null!");
       #endif
       return TC_ERR_NULL;
    }

    if(TC_FRM_LEN_MIN > usLen)
    {
        #ifdef TC_DBG
        TCDBG("etcIsValidPack() frame is not completed!");
        #endif
        return TC_ERR_UNCOMP;
    }

    ucHead = (UINT8)(*pInBuf);

    // �̶�֡
    if(TC_STCHAR_FIXED == ucHead)
    {
        psHeadFixed = (sTcfHeadFixed *)pInBuf;

        if(TC_PROTO_VERSION != psHeadFixed->ucV)
        {
            #ifdef TC_DBG
            TCDBG("etcIsValidPack() proto version is error!");
            #endif
            return TC_ERR_PROTO;
        }

        // ֡�е�ʵ��У���
        ucFrmCS = psHeadFixed->ucS;

        // ���������У���
        ucCalCS = uctc_get_check_sum((UINT8*)&(psHeadFixed->usC), TC_FIXED_USR_LEN);

        // ������
        //uc0x16 = psHeadFixed->ucE;

        // �������
        *pbFiexed = TRUE;

    }
    // �ɱ�֡
    else if(TC_STCHAR_ALTER == ucHead)
    {
        psHeadAlter = (sTcfHeadAlter *)pInBuf;

        if(0x68 != psHeadAlter->f68 || 0x68 != psHeadAlter->s68)
        {
            #ifdef TC_DBG
            TCDBG("etcIsValidPack() start chart 0x68 is error!");
            #endif
            return TC_ERR_0x68;
        }

        // L1 L2
        if(psHeadAlter->usL1 != psHeadAlter->usL2)
        {
            #ifdef TC_DBG
            TCDBG("etcIsValidPack() L1 and L2 is not equal!");
            #endif
            return TC_ERR_L1L2;
        }
        else
        {
            usUserLen = psHeadAlter->usL1;
            if(usLen < (usUserLen + TC_ALTER_BUT_USER_LEN))
            {
                #ifdef TC_DBG
                TCDBG("etcIsValidPack() frame is not completed!");
                #endif
                return TC_ERR_UNCOMP;
            }
        }

        // ֡��Я����У���
        ucFrmCS =  *(UINT8*)((UINT8*)&(psHeadAlter->usC) + usUserLen);

        // ���������У���
        ucCalCS = uctc_get_check_sum((UINT8*)&(psHeadAlter->usC), usUserLen);

        // ������
        uc0x16 = *(UINT8*)((UINT8*)&(psHeadAlter->usC) + usUserLen + 1);

        // �������
        *pbFiexed = FALSE;
    }
    else
    {
        #ifdef TC_DBG
        TCDBG("etcIsValidPack() is not gbnx31 frame!");
        #endif
        return TC_ERR_PACK;
    }

    // У���
    if(ucCalCS != ucFrmCS)
    {
        #ifdef TC_DBG
        TCDBG("etcIsValidPack() check sum is error! CalCS = %02X, FrmCS = %02X", ucCalCS, ucFrmCS);
        #endif
        return TC_ERR_CS;
    }

    // ������(ֻ�ɱ�֡�н�����)
    if(TC_STCHAR_ALTER == ucHead)
    {
        if(TC_FRM_END_CHAR != uc0x16)
        {
            #ifdef TC_DBG
            TCDBG("etcIsValidPack() end char 0x16 is error!");
            #endif
            return TC_ERR_0x16;
        }
    }
    
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etcFindValidPack
 ��������  : �ҵ���һ����Ч֡��λ�ü�����
 �������  : UINT8* pinBuf        
             UINT16 usLen         
             UINT16* pusFirstOff  
             UINT16* pusFirstLen  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��21��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etcFindValidPack(UINT8* pinBuf, UINT16 usLen, UINT16* pusFirstOff, UINT16* pusFirstLen)
{
    eTcErr       eRet = TC_OK;  
    INT32           i = 0; 
    INT32           j = 0;
    UINT16 usValidLen = 0;
    BOOL       bFixed = FALSE;
    
    if(!pinBuf || !pusFirstOff || !pusFirstLen)
    {
        #ifdef TC_DBG
        TCDBG("etcFindValidPack() para pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(usLen < TC_FRM_LEN_MIN)
    {
        #ifdef TC_DBG
        TCDBG("etcFindValidPack() frame is not complete usLen = %d!", usLen);
        #endif
        return TC_ERR_UNCOMP;
    }
    
    for(i = 0; i < usLen; i++)
    {
        // �̶�֡
        if(TC_STCHAR_FIXED == pinBuf[i])
        {
             eRet = etcIsValidPack((UINT8*)(pinBuf + i), TC_FRM_LEN_MIN, &bFixed);
             if(TC_OK == eRet)
             {
                 *pusFirstOff = i;
                 *pusFirstLen = TC_FRM_LEN_MIN;
                 return TC_OK;
             }
        }
        
        // �ɱ�֡
        if(TC_STCHAR_ALTER == pinBuf[i])
        {   
            // �ж��������ֽ�λ���ǲ���0x68 usLen
            if(TC_STCHAR_ALTER == pinBuf[i+5])
             {
                for(j = i+6; j < usLen; j++)
                {
                    if(pinBuf[j] == TC_FRM_END_CHAR)
                    {    
                        usValidLen = j + 1;
                        eRet = etcIsValidPack((UINT8*)(pinBuf + i), usValidLen, &bFixed);
                        if(TC_OK == eRet)
                        {
                            *pusFirstOff = i;
                            *pusFirstLen = usValidLen;
                            return TC_OK;
                        }
                    }
                }

                continue;
            }
        }  
    }
	
    return TC_ERR_NONE;
}

/*****************************************************************************
 �� �� ��  : etc_pack_common
 ��������  : �������� ���ķ�װ����
 �������  : sTcPackCommon *psCommon

 �������  : UINT16 *pusLen     ��װ���֡��
             UINT8  *pOutBuf    ��װ���֡����
             pusLen pOutBuf ���û�����ռ�
 �� �� ֵ  :
 ���ú���  :
 ��������  : emcLitePack

 �޸���ʷ      :
  1.��    ��   : 2013��10��25�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_pack_common(sTcPackCommon *psCommon,  UINT16 *pusLen, UINT8  *pOutBuf)
{
    eTcErr        eRet         = TC_OK;
    UINT16        usBufLen     = 0;
    UINT16        usUsrLen     = 0;      // �û�������(������C����ַ��A����·�û�����D)�ֳ�
    BOOL          bFixed       = FALSE;  // �Ƿ�Ϊ�̶�֡
    UINT8         *pA2CsData   = NULL;
    UINT8         *pucCS       = NULL;   // ���ڼ���CS
    sTcfHeadFixed *psHeadFixed = NULL;
    sTcfHeadAlter *psHeadAlter = NULL;
    UINT16        usC          = 0;      // ������C
    sTcA_f        stA;                   // ��ַ��A

    if(!psCommon || !pusLen || !pOutBuf)
    {
        #ifdef TC_DBG
        TCDBG("etc_pack_common() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    /*
    if(g_bTcInit != TRUE)
    {
        #ifdef TC_DBG
        TCDBG("etc_pack_common() protocol is not init!");
        #endif
        return TC_ERR_INIT;
    }
   */

    // ֡���Ƿ���
    if(psCommon->usA2CsLen > TC_SEQ2CS_MAX)
    {
        #ifdef TC_DBG
        TCDBG("etc_pack_common() usAddr2CsLen out of range! len =  %d", psCommon->usA2CsLen);
        #endif
        return TC_ERR_OUTRNG;
    }

    if(!(psCommon->pA2CsData))
    {
        #ifdef TC_DBG
        TCDBG("etc_pack_common() pAddr2CsData pointer is null!");
        #endif
        return TC_ERR_A2CS;
    }

    // �̶�֡
    bFixed = psCommon->bFixed;
    if(TRUE == bFixed)
    {
        psHeadFixed = (sTcfHeadFixed*)pOutBuf;

        // 10H
        psHeadFixed->f10 = TC_STCHAR_FIXED;

        // ctrl
        eRet = etc_trans_ctrl(TC_TRANS_U2F, &(psCommon->sCtrl), &usC);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_pack_common()-> etc_trans_ctrl() error: %d!", eRet);
            #endif
            return eRet;
        }

        psHeadFixed->usC = usC;
        // address
        eRet = etc_trans_address(TC_TRANS_U2F, &(psCommon->sAddress), &stA);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_pack_common()-> etc_trans_address() error: %d!", eRet);
            #endif
            return eRet;
        }

        psHeadFixed->stA = stA;
            
        // �����û����� (�̶�֡�н�һ�ֽڵ�Э��汾) �ϲ�����Ѿ���ֵ
        psHeadFixed->ucV = TC_PROTO_VERSION;

        // У���CS
        usUsrLen = TC_FIXED_USR_LEN;
        psHeadFixed->ucS = uctc_get_check_sum((UINT8*)&(psHeadFixed->usC), usUsrLen);

        psHeadFixed->ucE = TC_FRM_END_CHAR;

        // ֡����
        usBufLen = TC_FIXED_LEN;
    }
    // �ɱ�֡
    else
    {
        psHeadAlter = (sTcfHeadAlter*)pOutBuf;

        // ��ʼ�ַ�
        psHeadAlter->f68 = TC_STCHAR_ALTER;
        psHeadAlter->s68 = TC_STCHAR_ALTER;

        // L1 L2(������C����ַ��A����·�û����� �ֽ��ܳ�)
        usUsrLen = psCommon->usA2CsLen + TC_ALTER_USR_OTHER_LEN;
        psHeadAlter->usL1 = usUsrLen;
        psHeadAlter->usL2 = usUsrLen;

        // ctrl
        eRet = etc_trans_ctrl(TC_TRANS_U2F, &(psCommon->sCtrl), &usC);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_pack_common()-> etc_trans_ctrl() error: %d!", eRet);
            #endif
            return eRet;
        }

        psHeadAlter->usC = usC;
        
        // address
        eRet = etc_trans_address(TC_TRANS_U2F, &(psCommon->sAddress), &stA);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_pack_common()-> etc_trans_address() error: %d!", eRet);
            #endif
            return eRet;
        }

        psHeadAlter->stA = stA;

        // �����û����� (�̶�֡�н�һ�ֽڵ�Э��汾)
        psHeadAlter->ucV = TC_PROTO_VERSION;
        // AC �����ϲ��ʼ��
        // �û�������
        pA2CsData = (UINT8*)&(psHeadAlter->ucV);
        memcpy((void*)pA2CsData, (void*)(psCommon->pA2CsData), psCommon->usA2CsLen);

        // У���CS
        pucCS  = (UINT8*)(pA2CsData + psCommon->usA2CsLen);
        *pucCS = uctc_get_check_sum((UINT8*)&(psHeadAlter->usC), usUsrLen);
        
        // ֡����
        usBufLen = psCommon->usA2CsLen + TC_ALTER_OTHER_LEN;

        // ������
        *(pucCS+1) = TC_FRM_END_CHAR;
    }

    // �������
    *pusLen = usBufLen;
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_unpack_common
 ��������  : �������Ľ���
 �������  : sTcPackCommon *psUnpack  
             UINT8* pInBuf            
             UINT16 usLen             
 �������  : sTcPackCommon *psUnpack
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��10��31��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_unpack_common(sTcPackCommon *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
    BOOL          bFixed          = FALSE;    // �Ƿ�Ϊ�̶�֡
    sTcfHeadFixed *psHeadFixed    = NULL;
    sTcfHeadAlter *psHeadAlter    = NULL;
    eTcErr        eRet            = TC_OK;
    
    if(!psUnpack || !psUnpack || !usLen)
    {
        #ifdef TC_DBG
        TCDBG("etc_unpack_common() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    eRet = etcIsValidPack(pInBuf, usLen, &bFixed);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_unpack_common() is not a valid frame %d!", eRet);
        #endif
        return eRet;
    }

    psUnpack->bFixed = bFixed;
    
    // �̶�֡
    if(TRUE == bFixed)
    {
        psHeadFixed = (sTcfHeadFixed *)pInBuf;

        // addr
        eRet = etc_trans_address(TC_TRANS_F2U, &(psUnpack->sAddress), &(psHeadFixed->stA));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_unpack_common() etc_trans_address() error %d!", eRet);
            #endif
            return eRet;     
        }

        // ctrl
         // ������C
        eRet = etc_trans_ctrl(TC_TRANS_F2U, &(psUnpack->sCtrl), &(psHeadFixed->usC));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_unPack_base()-> etc_trans_ctrl() error eRet = %d", eRet);
            #endif
            return eRet;
        }

        psUnpack->usA2CsLen = 1;
        psUnpack->pA2CsData = &(psHeadFixed->ucV);
        
    }
    // �ɱ�֡
    else
    {
        psHeadAlter = (sTcfHeadAlter *)pInBuf;

        // addr
        eRet = etc_trans_address(TC_TRANS_F2U, &(psUnpack->sAddress), &(psHeadAlter->stA));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_unpack_common() etc_trans_address() error %d!", eRet);
            #endif
            return eRet;     
        }

        // ctrl
         // ������C
        eRet = etc_trans_ctrl(TC_TRANS_F2U, &(psUnpack->sCtrl), &(psHeadAlter->usC));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_unPack_base()-> etc_trans_ctrl() error eRet = %d", eRet);
            #endif
            return eRet;
        }

        psUnpack->usA2CsLen = psHeadAlter->usL1 - TC_CA_LEN;
        psUnpack->pA2CsData = &(psHeadAlter->ucV);
        
    }
    
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etc_pack_base
 ��������  : ʵ�ֻ����ı��ķ�װ, ��Ӧ��һ�����ݵ�Ԫ��ʶ, ֮�����64�����ݵ�Ԫ
             ��������㷨�ӿ�,�ô���Ӧ�ò����ݼ��� ���ܺ���ܿ��ܻ�ı䳤��,
             ���ܵ�������������Ӧ�ò㹦���롢���ݵ�Ԫ��ʶ�����ݵ�Ԫ����
             Ӧ�ò������,���ϲ㴫��Ŀռ�,�����ȽϽ�ʡ�ڴ�

 �������  : stcBaskPack* psPack

 �������  : UINT16* pusLen
             UINT8* pOutBuf
 �� �� ֵ  :
 ���ú���  : etc_pack_common()
 ��������  : etcPack()

 �޸���ʷ      :
  1.��    ��   : 2013��10��25�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_pack_base(stcBaskPack* psPack, UINT8* pOutBuf, UINT16* pusLen)
{
    eTcErr         eRet        = TC_OK;
    eTcmd          eCmd        = TCMD_AFN_F_UNKOWN;
    eTcDir         eDir        = TC_DIR_UNKOWN;
    eTcAFN         eAFN        = TC_AFN_NULL;
    BOOL           bSameTeam   = FALSE;
    BOOL           bP0         = FALSE;
    UINT8          ucPnNum     = 0;
    UINT16         usA2CsLen   = 0;
    UINT16         usA2CsPos   = 0;
    UINT16         usfDataLen  = 0;      // ֡�����ݵ�Ԫ�ֳ�
    UINT16         usCMD       = 0;
    INT32          i           = 0;
    INT32          j           = 0;
    INT32          fi          = 0;
    INT32          pi          = 0;
    UINT8*         pA2Cs       = NULL;   // ��·�û����ݲ�
    UINT8*         puData      = NULL;   // ���ݵ�Ԫ�û�������
    UINT8*         pData       = NULL;   // ���ݵ�Ԫ
    UINT8*         pUcAc       = NULL;   // �û�������Ac�û���ָ��
    sTcDaDt*       pDaDt       = NULL;   // ���ݵ�Ԫ��ʶ
    sTcTp_f*       psfTp       = NULL;   // ֡��Tp�ֶ�
    pTcFunc        pFunc       = NULL;
    sTcmdInfor     sCmdInfor;
    sTcTp          suTp;                 // �û���Tp�ֶ���Ϣ
    sTcPnFn        sPnFn;
    sTcPackCommon  sPackCommon;

    // ����
    #if TC_CFG_ENCRYPT
    UINT8*         pEncry_in   = NULL;  // ��Ҫ���ܲ��ֵ��׵�ַ ����
    INT32          nLen_in     = 0;     // ���ĵ����ֳ�
    UINT8*         pEncry_out  = NULL;  // ��Ҫ���ܲ��ֵ��׵�ַ ���
    INT32          nLen_out    = 0;     // ���ĵ����ֳ�
    #endif

    memset(&(suTp), 0x00, sizeof(sTcTp));
    memset(&(sPnFn), 0x00, sizeof(sTcPnFn));
    memset(&sPackCommon, 0x00, sizeof(sTcPackCommon));

    if(!psPack || !pusLen || !pOutBuf)
    {
        #ifdef TC_DBG
        TCDBG("etc_pack_base() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(TRUE != g_bTcInit)
    {
        #ifdef TC_DBG
        TCDBG("etc_pack_base() protocol isn't init!");
        #endif
        return TC_ERR_INIT;
    }

    if(TC_ROLE_CONTOR == g_eTcRole)
    {
        eDir = TC_DIR_C2T;
    }
    else
    {
        eDir = TC_DIR_T2C;
    }

    /* ��װsTcPackCommon ��� */
    // ����ͨ�÷������
    pA2Cs = (UINT8*)malloc(TC_A2CS_BYTE_MAX);
    if(!pA2Cs)
    {
        #ifdef TC_DBG
        TCDBG("etc_pack_base() malloc failed!");
        #endif
        return TC_ERR_IO;
    }

    // ������·����������
    // �̶�֡
    if(TRUE == psPack->bFixed)
    {
        // �̶�֡����·�����ݽ�Ϊһ���汾��Ϣ
        *pA2Cs = TC_PROTO_VERSION;
        usA2CsPos += 1;
    }
    // �ɱ�֡
    else
    {
        // Э���ʶ
        *pA2Cs = TC_PROTO_VERSION;
         usA2CsPos += 1;

        // Ӧ�ÿ�����AC
        pUcAc = (UINT8*)(pA2Cs + usA2CsPos);
        eRet  = etc_trans_ac(TC_TRANS_U2F, &(psPack->sAc), pUcAc);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_pack_base() etc_trans_ac error %d!", eRet);
            #endif
            TC_FREE(pA2Cs);
            return eRet;
        }

        usA2CsPos += 1;

        // ��װ�䳤�����ݵ�Ԫ��ʶ�����ݵ�Ԫ��
        if(0 == psPack->usNum)
        {
            #ifdef TC_DBG
            TCDBG("etc_pack_base() usNum is 0!");
            #endif
            TC_FREE(pA2Cs);
            return TC_ERR_PROTO;
        }

        // ��װ����һ�����ݱ�ʶ�����ݵ�Ԫ���
        for(i = 0; i < psPack->usNum; i++)
        {
            for(j = 0; j < TC_PN_INDEX_MAX; j++)
            {
                sPnFn.usPn[j] =  psPack->sData[i].sPnFn.usPn[j];
                sPnFn.ucFn[j] =  psPack->sData[i].sPnFn.ucFn[j];
            }

            // ȷ��ÿ��Pn ������ͬһ����Ϣ����
            bSameTeam = btc_same_team_pn(sPnFn.usPn, NULL);
            if(FALSE == bSameTeam)
            {
                #ifdef TC_DBG
                TCDBG("etc_pack_base() pn is not is same team!");
                #endif
                TC_FREE(pA2Cs);
                return TC_ERR_TEAM;
            }

            // ȷ��ÿ��Fn ������ͬһ����Ϣ����
            bSameTeam = btc_same_team_fn(sPnFn.ucFn, NULL);
            if(FALSE == bSameTeam)
            {
                #ifdef TC_DBG
                TCDBG("etc_pack_base() Fn is not is same team!");
                #endif
                TC_FREE(pA2Cs);
                return TC_ERR_TEAM;
            }

            // ��������
            eAFN = psPack->sAc.eAfn;

            // ��װ���ݵ�Ԫ��ʶ
            pDaDt = (sTcDaDt*)(pA2Cs + usA2CsPos);
            eRet = etc_pnfn_to_dadt(&(sPnFn), pDaDt);
            if(TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etc_pack_base() etc_pnfn_to_dadt() failed %d %s!", eRet, stcGetErr(eRet));
                #endif
                TC_FREE(pA2Cs);
                return eRet;
            }

            usA2CsPos +=  sizeof(sTcDaDt);
            /*
                �����װ���64����Fn Pn���Ӧ�����ݵ�Ԫ
                ���ݵ�ԪΪ�����ݵ�Ԫ��ʶ����֯�����ݣ���������������ȡ�
                ������֯��˳������Ȱ�pn��С�����ٰ�Fn��С����Ĵ��򣬼������һ����Ϣ��pi
                ��������Ϣ��Fn�Ĵ�����ٽ�����һ��pi+1�Ĵ���
            */

            // ���������
            bP0 = btc_is_p0(sPnFn.usPn);
            if(TRUE == bP0)
            {
                 ucPnNum = 1;               // 1 - p0
            }
            else
            {
                 ucPnNum = TC_PN_INDEX_MAX; // 2 - �������8��Pn
            }

            // Ӧ�ò�������
            for(pi = 0; pi < ucPnNum; pi++)
            {
                if(TC_PN_NONE != sPnFn.usPn[pi])
                {
                    for(fi = 0; fi < TC_FN_INDEX_MAX; fi++)
                    {
                        if(TC_FN_NONE != sPnFn.ucFn[fi])
                        {
                             // �ϳ�������
                            usCMD = (UINT16)((eAFN << 8) | (sPnFn.ucFn[fi]));
                            eCmd  = (eTcmd)usCMD;

                            // ���������Ϣ
                            eRet = eTcGetCmdInfor(eCmd, eDir, &sCmdInfor);
                            if(TC_OK != eRet)
                            {
                                #ifdef TC_DBG
                                TCDBG("etc_pack_base() eTcGetCmdInfor() failed %d %s!", eRet, stcGetErr(eRet));
                                #endif
                                TC_FREE(pA2Cs);
                                return eRet;
                            }

                            // ���ݵ�Ԫ
                            pData = (UINT8*)(pA2Cs + usA2CsPos);
                            pFunc = sCmdInfor.pFunc;
                            if(NULL != pFunc)
                            {
                                puData = (UINT8*)(psPack->sData[i].puApp[pi][fi]);
                                eRet = pFunc(TC_TRANS_U2F, puData, pData, &usfDataLen);
                                if(TC_OK != eRet)
                                {
                                    #ifdef TC_DBG
                                    TCDBG("etc_pack_base() transU2FpFunc() failed %d %s!", eRet, stcGetErr(eRet));
                                    #endif
                                    TC_FREE(pA2Cs);
                                    return eRet;
                                }

                                usA2CsPos += usfDataLen;
                            }
                        }
                    }
                }
            }
        }

        // ����
        #if TC_CFG_ENCRYPT
        if(NULL != g_peTcEncryptFunc)
        {
            pEncry_in  = pA2Cs;  // ������Ҫ�ٵ���,��ȷ����Ҫ���ܵĲ���
            nLen_in    = usA2CsPos;
            pEncry_out = (UINT8*)malloc(TC_A2CS_BYTE_MAX);
            if(!pEncry_out)
            {
                #ifdef TC_DBG
                TCDBG("etc_pack_base() malloc failed!");
                #endif
                TC_FREE(pA2Cs);
                return TC_ERR_IO;
            }

            eRet = g_peTcEncryptFunc(pEncry_in, nLen_in, pEncry_out, &nLen_out);
            if(TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etc_pack_base() encrypt failed! %d", eRet);
                #endif
                TC_FREE(pA2Cs);
                TC_FREE(pEncry_out);
                return TC_ERR_ENCRYPT;
            }

            // �滻������
            memcpy((void*)pA2Cs, (void*)pEncry_out, nLen_out);

            // ���³���
            usA2CsPos = nLen_out;

        }
        #endif

        /* ������Ϣ��AUX */
        // ����� EC (ֻ���������б�����)
        if(TC_DIR_T2C == eDir)
        {
            if(TRUE == psPack->sAc.bEc)
            {
                pData = (UINT8*)(pA2Cs + usA2CsPos);
                memcpy((void*)pData, (void*)&g_sTcEc, sizeof(sTcEc));
                usA2CsPos += sizeof(sTcEc);
            }
        }
        else
        {
            // ����� pw
            // pw������Ҫ�����б�����,����վ����,�ն���֤��ͨ����ִ��(16�ֽ�)
            if(TRUE == btc_have_pw(eAFN, eDir))
            {
                pData = (UINT8*)(pA2Cs + usA2CsPos);
                memcpy((void*)pData, (void*)psPack->aPw, TC_PW_LEN);
                usA2CsPos += TC_PW_LEN;
            }
        }

        // ����� TP
        if(TRUE == psPack->sAc.bTp)
        {
            pData = (UINT8*)(pA2Cs + usA2CsPos);
            psfTp = (sTcTp_f *)pData;
            suTp  = psPack->sTp;
            (void)etc_trans_tp(TC_TRANS_U2F, &suTp, psfTp);
            usA2CsPos += sizeof(sTcTp_f);
        }
        
        // ��� TCMD_AFN_C_F1_FREZ_TEMP ��Ӧ��
        if(TC_AFN_13_ASKR == psPack->sAc.eAfn && 
           TC_PRM_A2P == psPack->sCtrl.ePRM)
        {
            psPack->sAc.eAfn = TC_AFN_12_ASKT;
        }
        
    }

    // �ܽ�����
    usA2CsLen               = usA2CsPos;
    sPackCommon.sAddress    = psPack->sAddress;
    sPackCommon.sCtrl       = psPack->sCtrl;;
    sPackCommon.usA2CsLen   = usA2CsLen;
    sPackCommon.pA2CsData   = pA2Cs;
    sPackCommon.bFixed      = psPack->bFixed;

    // ͨ��ͨ�÷������pack
    eRet = etc_pack_common(&sPackCommon, pusLen, pOutBuf);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_pack_base() etc_pack_common failed:%s!", stcGetErr(eRet));
        #endif

        TC_FREE(pA2Cs);
        // �ͷż��ܲ���������ڴ�
        #if TC_CFG_ENCRYPT
        TC_FREE(pEncry_out);
        #endif
        return eRet;
    }

    TC_FREE(pA2Cs);

    // �ͷż��ܲ���������ڴ�
    #if TC_CFG_ENCRYPT
    TC_FREE(pEncry_out);
    #endif

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : vtc_free_base_data
 ��������  : �����ͷ�etc_unPack_base()�����֧��̬������ڴ�, �Է�ֹ�ڴ�й¶

 �������  : sTcBaseData* pBaseData
             INT32 Num
 �������  : ��
 �� �� ֵ  :
 ���ú���  :
 ��������  : etc_unPack_base

 �޸���ʷ      :
  1.��    ��   : 2014��1��4�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
void vtc_free_base_data(sTcBaseData* pBaseData, INT32 Num)
{
    INT32  i       = 0;
    INT32  fi      = 0;
    INT32  pi      = 0;
    uTcApp *pFree = NULL;

    if(!pBaseData || Num <= 0)
    {
        return;
    }

    for(i = 0; i < Num; i++)
    {
       for(pi = 0; pi < 8; pi++)
       {
            for(fi = 0; fi < 8; fi++)
            {
                pFree = pBaseData[i].puApp[pi][fi];
                if(pFree != NULL)
                {
                    free(pFree);
                }
            }
       }
    }
}
/*****************************************************************************
 �� �� ��  : etc_unPack_base
 ��������  : ʵ�ֻ����ı��Ľ��װ, ��������㷨�ӿ�
             �ô���Ӧ�ò����ݽ��� ���ܺ���ܿ��ܻ�ı䳤��,
             ���ܵ�������������Ӧ�ò㹦���롢���ݵ�Ԫ��ʶ�����ݵ�Ԫ����
 �������  : stcBaskPack *psUnpack
             UINT8* pInBuf
             UINT16 usLen
 �������  : ��
 �� �� ֵ  :
 ���ú���  : etcUnPack
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��28�� ����һ
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etc_unPack_base(stcBaskPack *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
    eTcErr        eRet            = TC_OK;
    eTcDir        eDir            = TC_DIR_UNKOWN;
    eTcAFN        eAFN            = TC_AFN_NULL;
    eTcmd         eCmd            = TCMD_AFN_F_UNKOWN;
    BOOL          bP0             = FALSE;
    BOOL          bTp             = FALSE;
    BOOL          bEc             = FALSE;
    BOOL          bFixed          = FALSE;    // �Ƿ�Ϊ�̶�֡
    sTcfHeadFixed *psHeadFixed    = NULL;
    sTcfHeadAlter *psHeadAlter    = NULL;
    sTcDaDt       *pDaDt          = NULL;
    UINT8         *pucTemp        = NULL;     // ��������ָ��
    sTcEc         *psEC           = NULL;
    uTcApp        *puApp          = NULL;
    pTcFunc        pFunc          = NULL;
    UINT8          ucFn           = 0;
    UINT8          ucPnCycMax     = 0;        // ��Pnѭ�������ֵ
    UINT16         usPn           = 0;
    UINT16         usUsrdLen      = 0;        //�û�Ӧ��������֡����ֳ�
    UINT16         usUsrdLenTotal = 0;        //�û�Ӧ��������֡����ֳ�
    UINT16         usAuxLen       = 0;        // ������֡��EcPwTp֡��ļ�����Ĳ��ֳ�
    UINT16         usLenUserField = 0;        // �û�����������
    UINT16         usDataNum      = 0;        // ���ݵ�Ԫ��ĸ���
    INT32          nLenUserField  = 0;        // ÿ�ν���һ�����������ݵ�Ԫ����û��������ֳ�
    INT32          i              = 0;
    INT32          fi             = 0;        // Fn������
    INT32          pi             = 0;        // Pn������

    sTcPnFn     sPnFn;
    sTcmdInfor  sCmdInfor;

    if(!psUnpack || !pInBuf)
    {
        #ifdef TC_DBG
        TCDBG("etc_unPack_base() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(TRUE != g_bTcInit)
    {
        #ifdef TC_DBG
        TCDBG("etc_unPack_base() protocol is not init!");
        #endif
        return TC_ERR_INIT;
    }

    if(usLen < TC_FRM_LEN_MIN)
    {
        #ifdef TC_DBG
        TCDBG("etc_unPack_base() input frame length is too short usLen = %d", usLen);
        #endif
        return TC_ERR_UNCOMP;
    }

    // �жϸ�֡�Ƿ���һ����Ч��֡
    eRet = etcIsValidPack(pInBuf, usLen, &bFixed);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etc_unPack_base() input is not a valid pack eRet = %d", eRet);
        #endif
        return TC_ERR_PACK;
    }

    psUnpack->bFixed = bFixed;
    
    // �̶�֡
    if(TRUE == bFixed)
    {
        psHeadFixed = (sTcfHeadFixed *)pInBuf;

        // ������C
        eRet = etc_trans_ctrl(TC_TRANS_F2U, &(psUnpack->sCtrl), &(psHeadFixed->usC));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_unPack_base()-> etc_trans_ctrl() error eRet = %d", eRet);
            #endif
            return eRet;
        }

        // ��ַ��A
        eRet = etc_trans_address(TC_TRANS_F2U, &(psUnpack->sAddress), &(psHeadFixed->stA));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_unPack_base()-> etc_trans_address() error eRet = %d", eRet);
            #endif
            return eRet;
        }
    }
    // �ɱ�֡
    else
    {
        psHeadAlter = (sTcfHeadAlter *)pInBuf;

        // �û������ݳ���
        usLenUserField = psHeadAlter->usL1;

         // ������C
        eRet = etc_trans_ctrl(TC_TRANS_F2U, &(psUnpack->sCtrl), &(psHeadAlter->usC));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_unPack_base()-> etc_trans_ctrl() error eRet = %d", eRet);
            #endif
            return eRet;
        }

        // ��ַ��A
        eRet = etc_trans_address(TC_TRANS_F2U, &(psUnpack->sAddress), &(psHeadAlter->stA));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_unPack_base()-> etc_trans_address() error eRet = %d", eRet);
            #endif
            return eRet;
        }

        // Э���ʶ
        //psHeadAlter->ucV == TC_PROTO_VERSION

        // Ӧ�ÿ�����AC
        eRet = etc_trans_ac(TC_TRANS_F2U, &(psUnpack->sAc), &(psHeadAlter->ucAc));
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etc_unPack_base()-> etc_trans_ac() error eRet = %d", eRet);
            #endif
            return eRet;
        }

        // ���AUX���ݳ���
        eDir = psUnpack->sCtrl.eDir;
        bEc  = psUnpack->sAc.bEc;
        bTp  = psUnpack->sAc.bTp;
        eAFN = psUnpack->sAc.eAfn;

        usAuxLen = ustc_get_aux_len(eAFN, eDir, bEc, bTp);

        // ������·�����ݳ���
        nLenUserField = (INT32)(usLenUserField - usAuxLen - TC_CA_LEN);

        // ��ȥ(Э���ʶ��Ӧ�ÿ�����AC�ĳ���)
        nLenUserField -= TC_VAC_LEN;

        // Ӧ�ò����� ���ݵ�Ԫ��ʶ�����ݵ�Ԫ��
        pucTemp = (UINT8*)((UINT8*)&(psHeadAlter->ucAc) + 1);
        while(nLenUserField > 0)
        {
            #if 0
            #ifdef TC_DBG
            TCDBG("emcBaseUnPack() nLenUserField = %d", nLenUserField);
            #endif
            #endif

            // ��ʼ��
            usUsrdLen = nLenUserField;

            // ���ݵ�Ԫ��ʶ
            pDaDt = (sTcDaDt*)pucTemp;
            eRet = etc_dadt_to_pnfn(pDaDt, &sPnFn);
            if(TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etc_unPack_base() -> etc_dadt_to_pnfn() error = %d\n", eRet);
                #endif
                return eRet;
            }

            pucTemp += sizeof(sTcDaDt);

            bP0 = btc_is_p0(sPnFn.usPn);
            if(TRUE == bP0)
            {
                //P0���������ѭ��
                ucPnCycMax = 1;
            }
            else
            {
                // ����P0�������˫��ѭ��
                ucPnCycMax = 8;
            }

            psUnpack->sData[i].sPnFn = sPnFn;
            for(pi = 0; pi < ucPnCycMax; pi++)
            {
                usPn = sPnFn.usPn[pi];
                if(TC_PN_NONE == usPn)
                {
                    // �Ϸ���������, ��û�ж�Ӧλ�õ�PN
                }
                else if(usPn < TC_PN_MIN || usPn > TC_PN_MAX)
                {
                    // �Ƿ�Fn
                    #ifdef TC_DBG
                    TCDBG("etc_unPack_base() usPn error Pn = %d\n", usPn);
                    #endif
                    return TC_ERR_PARA;
                }
                else
                {
                    for(fi = 0; fi < 8; fi++)
                    {
                        ucFn = sPnFn.ucFn[fi];
                        if(TC_FN_NONE == ucFn)
                        {
                            // ���������û�и�FN, �Ϸ���������
                        }
                        else if(ucFn < TC_FN_MIN || ucFn > TC_FN_MAX)
                        {
                            // �Ƿ�Fn
                            #ifdef TC_DBG
                            TCDBG("etc_unPack_base() ucFn error Fn = %d\n", ucFn);
                            #endif
                            return TC_ERR_PARA;
                        }
                        else
                        {
                            eCmd = (eTcmd)((eAFN << 8) | (sPnFn.ucFn[fi]));
                            eRet = eTcGetCmdInfor(eCmd, eDir, &sCmdInfor);
                            if(TC_OK != eRet)
                            {
                                #ifdef TC_DBG
                                TCDBG("etc_unPack_base() eTcGetCmdInfor() failed %d %s!", eRet, stcGetErr(eRet));
                                #endif
                                return eRet;
                            }

                            pFunc = sCmdInfor.pFunc;
                            if(NULL != pFunc)
                            {
                                // �����ڴ�,���Ӧ�ò�����, �ɵ������ͷŸ��ڴ�, �ú����ڲ��ͷ�
                                puApp = (uTcApp*)malloc(sizeof(uTcApp));
                                if(!puApp)
                                {
                                    #ifdef TC_DBG
                                    TCDBG("etc_unPack_base() malloc failed!");
                                    #endif
                                    return TC_ERR_IO;
                                }

                                psUnpack->sData[i].puApp[pi][fi] = puApp;
                                eRet = pFunc(TC_TRANS_F2U, (void*)(psUnpack->sData[i].puApp[pi][fi]), (void*)pucTemp, &usUsrdLen);
                                if(eRet != TC_OK)
                                {
                                    #ifdef TC_DBG
                                    TCDBG("etc_unPack_base() transfunc() error = %d\n", eRet);
                                    #endif

                                    // �ͷ�֮�䶯̬������ڴ�ռ�
                                    vtc_free_base_data(psUnpack->sData, i+1);
                                    return eRet;
                                }

                                // ����ָ�����
                                pucTemp += usUsrdLen;

                                // ��¼�����ܳ�
                                usUsrdLenTotal += usUsrdLen;
                            }
                        }
                    }
                }
            }

            // �������
            usDataNum++;

            // ���ȼ���
            nLenUserField -= sizeof(sTcDaDt);
            nLenUserField -= usUsrdLenTotal;

            // ���ü���
            usUsrdLenTotal = 0;
            i++;
        }

        // �����EC
        if(TRUE == bEc)
        {
            psEC = (sTcEc*)pucTemp;
            psUnpack->sEc.usEC1 = psEC->usEC1;
            psUnpack->sEc.usEC2 = psEC->usEC2;
            pucTemp += sizeof(sTcEc);
        }

        // �����PW
        if(TRUE == btc_have_pw(eAFN, eDir))
        {
            memcpy((void*)(psUnpack->aPw), (void*)pucTemp, TC_PW_LEN);
            pucTemp += TC_PW_LEN;
        }

        // �����TP
        if(TRUE == bTp)
        {
            eRet = etc_trans_tp(TC_TRANS_F2U, &(psUnpack->sTp), (sTcTp_f*)pucTemp);
            if(eRet != TC_OK)
            {
                #ifdef TC_DBG
                TCDBG("eTcUnpack() etc_trans_tp() error = %d\n", eRet);
                #endif
                return eRet;
            }

            //pucTemp += sizeof(sMtfTp);
        }

        psUnpack->usNum = usDataNum;
    }

    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etcPack
 ��������  : ��װ����(�߼��ӿ�)
 ʵ�ֹ���  : (1) ʵ����ɢ����Ϣ������Ϣ����Զ�����
             (2) �Զ�ȡ��ǰ��ʱ�����ϳ�tp
             (3) Ϊ�ϲ�������صĲ��� �繦�����

 �������  : stcPack* psPack

 �������  : UINT16* pusLen
             UINT8* pOutBuf
 �� �� ֵ  :
 ���ú���  : etc_pack_common()
 ��������  : etcPack()

 �޸���ʷ      :
  1.��    ��   : 2013��10��25�� ������
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etcPack(stcPack* psPack, UINT8* pOutBuf, UINT16* pusLen)
{
    eTcErr         eRet         = TC_OK;
    eTcmd          eCmd         = TCMD_AFN_F_UNKOWN;
    eTcDir         eDir         = TC_DIR_UNKOWN;
    eTcAFN         eAFN         = TC_AFN_NULL;
    eTcAFN         eAFNCmd      = TC_AFN_NULL;  // �����Ӧ��AFN
    UINT8          ucTeamPn     = 0xFF;
    UINT8          ucTeamPnBase = 0xFF;
    UINT8          ucTeamFn     = 0xFF;
    UINT8          ucTeamFnBase = 0xFF;
    UINT8          ucFn         = 0;
    UINT16         usPn         = 0;
    INT32          FnIndex      = 0;
    INT32          PnIndex      = 0;
    INT32          i            = 0;
    INT32          j            = 0;
    INT32          k            = 0;
    INT32          nDaDtNum     = 0;      // ��װpackbase����Ϣ��ʶ��64�����ݵ�Ԫ����ܸ���
    INT32          nDaDtPos     = 0;      // ÿ��Ӧ����packbase����Ϣ��ʶ�������
    BOOL           bFindDaDt    = FALSE;  // �Ƿ��ҵ�֮ǰ���ڵ���
    BOOL           bInFn8       = FALSE;
    UINT8*         pMemBase     = NULL;
    stcBaskPack*   psBasePack   = NULL;
    sTcmdInfor     sCmdInfor;

    // �������
    if(!psPack || !pusLen || !pOutBuf)
    {
        #ifdef TC_DBG
        TCDBG("etcPack() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(TRUE != g_bTcInit)
    {
        #ifdef TC_DBG
        TCDBG("etcPack() protocol is not init!");
        #endif
        return TC_ERR_INIT;
    }

    // Ϊ����psBasePack�����ڴ�
    pMemBase  = (UINT8*)malloc(TC_USER_MAX);
    if(!pMemBase)
    {
        #ifdef TC_DBG
        TCDBG("etcPack() malloc failed!");
        #endif
        return TC_ERR_IO;
    }

    psBasePack = (stcBaskPack*)pMemBase;

    // ��װ�� stcBaskPack ����
    psBasePack->sAddress = psPack->sAddress;
    psBasePack->sCtrl    = psPack->sCtrl;
    psBasePack->bFixed   = psPack->bFixed;

    eDir = psPack->sCtrl.eDir;

    // �̶�֡
    if(TRUE == psPack->bFixed)
    {
        // �÷�֧�±ߵĵ����������˴�������
    }
    // �ɱ�֡
    else
    {
        psBasePack->sAc      = psPack->sAc;
        psBasePack->sEc      = psPack->sEc;
        psBasePack->sTp      = psPack->sTp;
        memcpy(psBasePack->aPw, psPack->aPw, TC_PW_LEN);
        eAFN = psPack->sAc.eAfn;

        // ����ɢ�����ݵ�Ԫ��ʶ�����ݵ�Ԫ��ϳ���
        for(i = 0; i < psPack->usNum; i++)
        {
            eCmd = psPack->sData[i].eCmd;

            // �жϸ������Ƿ��ǺϷ��ġ���֧�ֵ�
            eRet = eTcGetCmdInfor(eCmd, eDir, &sCmdInfor);
            if(eRet != TC_OK)
            {
                #ifdef TC_DBG
                TCDBG("etcPack() eTcGetCmdInfor() failed %d %s!", eRet, stcGetErr(eRet));
                #endif
                TC_FREE(pMemBase);
                return eRet;
            }

            // �жϸ������Ƿ�����AFN��������
            eAFNCmd = eTcGetCmdAfn(eCmd);
            if(eAFNCmd != eAFN)
            {
                TC_FREE(pMemBase);
                #ifdef TC_DBG
                TCDBG("etcPack() cmd is %04X", eCmd);
                TCDBG("etcPack() cmd is not is a same Afn eAFNCmd = %d eAFN = %d", eAFNCmd, eAFN);
                #endif
                return TC_ERR_TEAM;
            }

            usPn = psPack->sData[i].usPN;
            ucFn = ucTcGetCmdFn(eCmd);

            /*
                �жϸúϷ������ݵ�Ԫ��ʶ,�����ݵ�Ԫ�Ƿ��Ѿ�����Ӧ��λ�� psBasePack
                ����ظ�,���߸���ǰ��, Da2 �벻ͬ��Dt2���,
                �������ͬ�ı�ʶ�����ݵ�Ԫ��, ����nDaTaNum�ĸ���
            */

            nDaDtPos = nDaDtNum;

            // ��ʼ��PnFn��
            for(k = 0; k < 8; k++)
            {
                psBasePack->sData[nDaDtPos].sPnFn.ucFn[k] = TC_FN_NONE;
                psBasePack->sData[nDaDtPos].sPnFn.usPn[k] = TC_PN_NONE;
            }

            for(j = 0; j < nDaDtNum; j++)
            {
                // �ҵ���nDataPos���ҵ���λ��
                // ���ж�Pn�Ƿ���ͬһ��
                ucTeamPn     = uctc_get_pn_team(usPn);
                ucTeamPnBase = uctc_get_pn8_team(psBasePack->sData[j].sPnFn.usPn);

                if(ucTeamPn == ucTeamPnBase)
                {
                    // ���ж�Fn�Ƿ�����ͬһ����
                    ucTeamFn     = uctc_get_fn_team(ucFn);
                    ucTeamFnBase = uctc_get_fn8_team(psBasePack->sData[j].sPnFn.ucFn);

                    if(ucTeamFn == ucTeamFnBase)
                    {
                        //bInPn8 = bmt_in_pn8(usPn, psBasePack->sData[j].sPnFn.usPn);
                        bInFn8 = btc_in_fn8(ucFn, psBasePack->sData[j].sPnFn.ucFn);

                        //if(TRUE == bInPn8 || TRUE == bInFn8)
                        if(TRUE == bInFn8)
                        {
                            bFindDaDt = TRUE;
                            nDaDtPos  = j;
                            break;
                        }
                    }
                }
            }

            // δ�ҵ���nDaTaNum++
            if(FALSE == bFindDaDt)
            {
                nDaDtNum  += 1; // ����һ��
            }

            // ���� DaTa�鼰���ݵ�Ԫ
            if(0 == usPn)
            {
                PnIndex = 0;

                for(k = 0; k < 8; k++)
                {
                    psBasePack->sData[nDaDtPos].sPnFn.usPn[k] = 0;
                }
            }
            else
            {
                PnIndex = (usPn - 1) % 8;
                psBasePack->sData[nDaDtPos].sPnFn.usPn[PnIndex] = usPn;
            }

            FnIndex = (ucFn - 1) % 8;
            psBasePack->sData[nDaDtPos].sPnFn.ucFn[FnIndex] = ucFn;

            // ���ݵ�Ԫ
            psBasePack->sData[nDaDtPos].puApp[PnIndex][FnIndex] = &(psPack->sData[i].uApp);

            // ����δ�ҵ�״̬
            bFindDaDt = FALSE;

        }

        psBasePack->usNum = nDaDtNum;
    }

    // ���� etc_pack_base()
    eRet = etc_pack_base(psBasePack , pOutBuf, pusLen);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etcPack() etc_pack_base() failed! code : %d %s", eRet, stcGetErr(eRet));
        #endif
        TC_FREE(pMemBase);
        return eRet;
    }

    TC_FREE(pMemBase);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etcUnPack
 ��������  : Э�����(�߼��ӿ�)
             ��etc_unPack_base()������������ϢstcBaskPack, ��װ�ɸ߼�stcPack

             (1)����Ҫ��Ϣ��ȡ
             (2)��PnFn���ݵ�Ԫ��ȡ����ɢ��

 �������  :  UINT8* pInBuf
              UINT16 usLen

 �������  : stcPack *psUnpack
 �� �� ֵ  :
 ���ú���  : etc_unPack_base()
 ��������  : etcUnPackTml()

 �޸���ʷ      :
  1.��    ��   : 2013��10��29�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etcUnPack(stcPack *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
    eTcErr       eRet        = TC_OK;
    eTcmd        eCmd        = TCMD_AFN_F_UNKOWN;
    eTcAFN       eAFN        = TC_AFN_NULL;
    UINT8*       pMemBase    = NULL;
    stcBaskPack* pBaseUnpack = NULL;
    uTcApp      *puApp       = NULL;
    BOOL         bP0         = FALSE;
    INT32        i           = 0;
    INT32        j           = 0;
    INT32        fi          = 0;
    INT32        pi          = 0;
    INT32        PnCyc       = 0;
    UINT16       usPn        = 0;
    UINT8        ucFn        = 0;
    sTcmdInfor   sCmdInfor;

    if(!psUnpack || !pInBuf)
    {
        #ifdef TC_DBG
        TCDBG("etcUnPack() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    if(TRUE != g_bTcInit)
    {
        #ifdef TC_DBG
        TCDBG("etcUnPack() protocol is not init!");
        #endif
        return TC_ERR_INIT;
    }

    // ��ʼ������
    memset(&sCmdInfor, 0, sizeof(sTcmdInfor));

    pMemBase = (UINT8*)malloc(TC_USER_MAX);
    if(!pMemBase)
    {
        #ifdef TC_DBG
        TCDBG("etcUnPack() malloc failed!");
        #endif
        return TC_ERR_IO;
    }
    
    pBaseUnpack = (stcBaskPack*)pMemBase;

    // ���ý�������
    eRet = etc_unPack_base(pBaseUnpack, pInBuf, usLen);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etcUnPack() -> etc_unPack_base() failed! %d %s", eRet, stcGetErr(eRet));
        #endif
        TC_FREE(pMemBase);
        return eRet;
    }

    // �����ֶ�
    psUnpack->sAddress = pBaseUnpack->sAddress;
    psUnpack->sCtrl    = pBaseUnpack->sCtrl;
    psUnpack->bFixed   = pBaseUnpack->bFixed;

    // �̶�֡
    if(TRUE == pBaseUnpack->bFixed)
    {
        psUnpack->bPw   = FALSE;
        psUnpack->usNum = 1;
        psUnpack->sData[0].usPN = 0;
        psUnpack->sData[0].usPN = 0;
        psUnpack->sData[0].bApp = FALSE;

        if(TC_DIR_T2C == psUnpack->sCtrl.eDir)
        {
            switch(psUnpack->sCtrl.eFcode)
            {
                case TC_FCD_LOG_IN:
                    psUnpack->sData[0].eCmd = TCMD_AFN_2_F1_LOG_IN;
                    break;

                case TC_FCD_LOG_OUT:
                    psUnpack->sData[0].eCmd = TCMD_AFN_2_F2_LOG_OUT;
                    break;

                case TC_FCD_HEART_BEAT:
                    psUnpack->sData[0].eCmd = TCMD_AFN_2_F3_HEART_BEAT;
                    break;

                default:
                    #ifdef TC_DBG
                    TCDBG("etcUnPack() -> fixed frame's eFcode is error %d", psUnpack->sCtrl.eFcode);
                    #endif
                    TC_FREE(pMemBase);
                    return TC_ERR_FCODE;
                    // break;
            }
        }
        else
        {
            if(TC_FCD_LINK_OK == psUnpack->sCtrl.eFcode)
            {
                psUnpack->sData[0].eCmd = TCMD_AFN_2_F4_LINK_OK;

            }
            else
            {
                 #ifdef TC_DBG
                 TCDBG("etcUnPack() -> fixed frame's eFcode is error %d", psUnpack->sCtrl.eFcode);
                 #endif
                 TC_FREE(pMemBase);
                 return TC_ERR_FCODE;
            }
        }
    }
    // �ɱ�֡
    else
    {
        // ת�����ݽṹ
        psUnpack->sAc = pBaseUnpack->sAc;
        psUnpack->sEc = pBaseUnpack->sEc;
        psUnpack->sTp = pBaseUnpack->sTp;
        memcpy(psUnpack->aPw, pBaseUnpack->aPw, TC_PW_LEN);
        eAFN = psUnpack->sAc.eAfn;
        psUnpack->bPw = btc_have_pw(eAFN, psUnpack->sCtrl.eDir);

        // Ӧ�ò�����
        for(i = 0; i < pBaseUnpack->usNum; i++)
        {
            bP0 = btc_is_p0(pBaseUnpack->sData[i].sPnFn.usPn);
            PnCyc = ((bP0 == TRUE) ? 1 : 8);

            for(pi = 0; pi < PnCyc; pi++)
            {
                usPn = pBaseUnpack->sData[i].sPnFn.usPn[pi];
                if(TC_PN_NONE == usPn)
                {
                    // �Ϸ���������, ��û�ж�Ӧλ�õ�PN
                }
                else if(usPn < TC_PN_MIN || usPn > TC_PN_MAX)
                {
                    // �Ƿ�Fn
                    #ifdef TC_DBG
                    TCDBG("etcUnPack() usPn error Pn = %d\n", usPn);
                    #endif
                    TC_FREE(pMemBase);
                    return TC_ERR_PARA;
                }
                else
                {
                    #if 0
                    #ifdef TC_DBG
                    for(fi = 0; fi < 8; fi++)
                    {   ucFn = pUnpackBase->sData[i].sPnFn.ucFn[fi];
                        TCDBG("etcUnPack() sData[%d].sPnFn.ucFn[%d] = %d",i, fi, ucFn);
                    }
                    #endif
                    #endif

                    for(fi = 0; fi < 8; fi++)
                    {
                        ucFn = pBaseUnpack->sData[i].sPnFn.ucFn[fi];
                        if(TC_FN_NONE == ucFn)
                        {
                            // ���������û�и�FN, �Ϸ���������
                        }
                        else if(ucFn < TC_FN_MIN || ucFn > TC_FN_MAX)
                        {
                            // �Ƿ�Fn
                            #ifdef TC_DBG
                            TCDBG("etcUnPack() ucFn error Fn = %d\n", ucFn);
                            #endif
                            TC_FREE(pMemBase);
                            return TC_ERR_PARA;
                        }
                        else
                        {
                            eCmd = (eTcmd)((eAFN << 8) | ucFn);
                            eRet = eTcGetCmdInfor(eCmd, psUnpack->sCtrl.eDir, &sCmdInfor);
                            if(TC_OK != eRet)
                            {
                                #ifdef TC_DBG
                                TCDBG("etcUnPack() eTcGetCmdInfor() failed %d %s!", eRet, stcGetErr(eRet));
                                #endif
                                TC_FREE(pMemBase);
                                return eRet;
                            }

                            // һ����Ч�����ݵ�Ԫ��ʶ��
                            psUnpack->sData[j].eCmd  = eCmd;
                            psUnpack->sData[j].usPN  = usPn;

                            if(NULL != sCmdInfor.pFunc)
                            {
                                psUnpack->sData[j].bApp = TRUE;
                                puApp = pBaseUnpack->sData[i].puApp[pi][fi];
                                if(!puApp)
                                {
                                    #ifdef TC_DBG
                                    TCDBG("etcUnPack() app date is null");
                                    #endif
                                    TC_FREE(pMemBase);
                                    return TC_ERR_PARA;
                                }

                                memcpy((void*)&(psUnpack->sData[j].uApp), (void*)puApp, sizeof(uTcApp));
                                TC_FREE(puApp);
                            }
                            else
                            {
                                psUnpack->sData[j].bApp = FALSE;
                            }

                            j++;
                        }
                    }
                }
            }
        }

        // ������������
        psUnpack->usNum = j;
    }

    TC_FREE(pMemBase);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etcPackTml
 ��������  : �������� Э���װ(�߼��ӿ�)
             (1)���������಻���ĵ��ֶ�����
             (2)�������÷�װ��ȷ�Ĳ���
             (3)�õ�ǰ����ʱ���װTp
             (4)�õ�ǰ���¼���¼��Ec
             (5)����֡���к�

 �������  :  sTcPackTml* psPack


 �������  : UINT8* pOutBuf,
             UINT16* pusLen
 �� �� ֵ  :
 ���ú���  : etc_unPack_base()
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��10��29�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etcPackTml(sTcPackTml* psPack, UINT8* pOutBuf, UINT16* pusLen)
{
    stcPack  *pstcPack = NULL;
    UINT8    *pMemPack = NULL;
    eTcmd     eCmd     = TCMD_AFN_F_UNKOWN;
    eTcFcode  eFcode   = TC_FCD_MAX;
    eTcErr    eRet     = TC_OK;
    INT32     i        = 0;

    if(!psPack || !pOutBuf || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etcPackTml() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pMemPack = (UINT8*)malloc(TC_USER_MAX);
    if(!pMemPack)
    {
        #ifdef TC_DBG
        TCDBG("etcPackTml() malloc failed!");
        #endif
        return TC_ERR_IO;
    }

    pstcPack = (stcPack *)pMemPack;

    // ȡ�õ�һ���������������
    eCmd = psPack->sData[0].eCmd;

    // �̶�֡
    if(TCMD_AFN_2_F1_LOG_IN     == eCmd ||
       TCMD_AFN_2_F2_LOG_OUT    == eCmd ||
       TCMD_AFN_2_F3_HEART_BEAT == eCmd ||
       TCMD_AFN_2_F4_LINK_OK    == eCmd)
    {
        // �����ֶβ�����
        pstcPack->bFixed       = TRUE;
        pstcPack->sAddress     = psPack->sAddress;

        // ������
        pstcPack->sCtrl.eDir   = TC_DIR_T2C;
        pstcPack->sCtrl.ePRM   = TC_PRM_A2P;
        //pstcPack->sCtrl.ucPSEQ = (++g_ucTcPseq % 31);
        pstcPack->sCtrl.ucRSEQ = 0;

        switch(eCmd)
        {
            case TCMD_AFN_2_F1_LOG_IN:
                pstcPack->sCtrl.eFcode = TC_FCD_LOG_IN;
                break;

            case TCMD_AFN_2_F2_LOG_OUT:
                pstcPack->sCtrl.eFcode = TC_FCD_LOG_OUT;
                break;

            case TCMD_AFN_2_F3_HEART_BEAT:
                pstcPack->sCtrl.eFcode = TC_FCD_HEART_BEAT;
                break;

            default:
                #ifdef TC_DBG
                TCDBG("etcPackTml() contrator don't suport cmd: TCMD_AFN_2_F4_LINK_OK!");
                #endif
                TC_FREE(pMemPack);
                return TC_ERR_PARA;
                break;
        }
    }
    // �ɱ�֡
    else
    {
        pstcPack->bFixed       = FALSE;
        pstcPack->sAddress     = psPack->sAddress;
        pstcPack->sCtrl.eDir   = TC_DIR_T2C;

        // ����֡
        if(TRUE == psPack->bActive)
        {
            pstcPack->sCtrl.ePRM = TC_PRM_A2P;
        }
        // ��վ֡
        else
        {
            pstcPack->sCtrl.ePRM = TC_PRM_P2A;
        }
        
        /*
           ��Ӧ֡��� RSEQ
            (1) ��Ӧ֡��� RSEQ �� PRM=0 ʱ�����Ӷ�֡����Ч��
                �ñ����ʾ 0~15�����ڶ���Ӷ�֡��Ӧһ������֡�Ĵ��䡣
            (2) ÿһ������վ�ʹӶ�վ֮����� 1 �������ļ�������
                ���ڼ�¼��ǰ RSEQ����ֻ��һ֡�Ӷ�֡��Ӧ����֡�ģ�
                RSEQ=0�������� n ��n��16��֡��Ӧ�ģ�RSEQ �� n-1 ��ݼ�������
                ÿ����һ֡�� 1��ֱ�����һ֡ RSEQ=0��
        */

        // ��ǰ���ǵ�֡�ظ�RSEQ = 0;
        pstcPack->sCtrl.ucRSEQ = 0;

        // ������
        eRet = etc_get_fcode(eCmd, TC_DIR_T2C, pstcPack->sCtrl.ePRM, &eFcode);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etcPackTml() etc_get_fcode error code %d!", eRet);
            #endif
            TC_FREE(pMemPack);
            return eRet;
        }

        pstcPack->sCtrl.eFcode = eFcode;

        // �������ֶ�
        pstcPack->sAc.eAfn = eTcGetCmdAfn(eCmd);

        // Ec
        if(TC_CFG_EC == 1)
        {
            pstcPack->sAc.bEc = btc_have_ec(pstcPack->sAc.eAfn, TC_DIR_T2C);
        }
        else
        {
            pstcPack->sAc.bEc = FALSE;
        }

        pstcPack->sEc.usEC1 = g_sTcEc.usEC1;
        pstcPack->sEc.usEC2 = g_sTcEc.usEC2;

        // Tp
        pstcPack->sAc.bTp = btc_have_tp(pstcPack->sAc.eAfn, TC_DIR_T2C);
      
        // ȡ�õ�ǰϵͳʱ��
        if(TRUE == pstcPack->sAc.bTp)
        {
            eRet = etc_get_tp(&pstcPack->sTp);
            if(TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etcPackTml() etc_get_tp() error code %d!", eRet);
                #endif
                TC_FREE(pMemPack);
                return eRet;
            }
        }

        // Ӧ�ò�����
        pstcPack->usNum = psPack->usNum;

        for(i =0; i < psPack->usNum; i++)
        {
            memcpy((void*)&(pstcPack->sData[i]), (void*)&(psPack->sData[i]), sizeof(sTcData));
        }
    }
    
    /*
        ����֡��� PSEQ
        �ñ����ʾ 0~31����������Ͷ�Ӧ����֡���Լ���ֹ��Ϣ����Ķ�ʧ���ظ�

        (1)ÿһ������վ�ʹӶ�վ֮����� 1 �������ļ����������ڼ�¼��ǰ PSEQ��
        ����վ��ͬһ�Ӷ�վ�����µĴ������ʱ��PSEQ+1��

        (2)����ʱδ�յ��Ӷ�վ�ı��ģ�����ճ��ֲ��������վ���ı�PSEQ��
        �ظ�ԭ���Ĵ������
    */

    if(FALSE == psPack->bReSend)
    {
         g_ucTcPseq = (g_ucTcPseq+1) % 31;
    }

    pstcPack->sCtrl.ucPSEQ = g_ucTcPseq;
     
    // ���ô������
    eRet = etcPack(pstcPack, pOutBuf, pusLen);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etcPackTml() etcPack() error code %d!", eRet);
        #endif
        TC_FREE(pMemPack);
        return eRet;
    }
    
    TC_FREE(pMemPack);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etcUnPackTml
 ��������  : ��������Э�����(�߼��ӿ�)

             (1)������վ����������������֡
             (2)��һЩ��������ʼ�ļ��(����ʱ���ǩ�Ƿ�ʱ��pw�Ƿ�Ϸ���)
             (3)����֡���к�
             (4)���μ��в಻��ϵ����Ϣ�ֶ�

 �������  :  UINT8* pInBuf
              UINT16 usLen

 �������  : sTcPackTml *psUnpack
 �� �� ֵ  :
 ���ú���  : etc_unPack_base()
 ��������  : etcUnPackTml()

 �޸���ʷ      :
  1.��    ��   : 2013��10��29�� ���ڶ�
    ��    ��   : liming
    �޸�����   : �����ɺ���
*****************************************************************************/
eTcErr etcUnPackTml(sTcPackTml *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
    eTcErr       eRet        = TC_OK;
    UINT8*       pMemUnpack  = NULL;
    stcPack*     psmcUnpack  = NULL;
    BOOL         bTimeOut    = FALSE;
    INT32        i           = 0;

    if(!psUnpack || !pInBuf)
    {
        #ifdef TC_DBG
        TCDBG("etcUnPackTml() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }
    
    pMemUnpack = (UINT8*)malloc(TC_USER_MAX);
    if(!pMemUnpack)
    {
        #ifdef TC_DBG
        TCDBG("etcUnPackTml() malloc failed!");
        #endif
        return TC_ERR_IO;
    }

    psmcUnpack = (stcPack*)pMemUnpack;

    eRet = etcUnPack(psmcUnpack, pInBuf, usLen);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etcPackTml() etcUnPack() error code %d!", eRet);
        #endif
        TC_FREE(pMemUnpack);
        return eRet;
    }

    // �ֶκϷ��Լ��
    // ���ķ���
    if(TC_DIR_C2T != psmcUnpack->sCtrl.eDir)
    {
        #ifdef TC_DBG
        TCDBG("etcPackTml() frame direction is error! It is not from contrator to terminal!");
        #endif
        TC_FREE(pMemUnpack);
        return TC_ERR_DIR;
    }

    // ֡���к�
    if(TC_PRM_A2P == psmcUnpack->sCtrl.ePRM)
    {
        g_ucTcPseq = psmcUnpack->sCtrl.ucPSEQ & 0x1F;
        psUnpack->bActive = TRUE;
    }
    else
    {
        psUnpack->bActive = FALSE;
    }

    #if 1
    // ʱ���ǩ
    if(TRUE == psmcUnpack->sAc.bTp)
    {
        bTimeOut = btc_tp_timeout(&(psmcUnpack->sTp));
        if(TRUE == bTimeOut)
        {
            #ifdef TC_DBG
            TCDBG("etcPackTml() frame is timeout!");
            #endif
            TC_FREE(pMemUnpack);
            return TC_ERR_TIMEOUT;
        }
    }
    #endif
    
    // Pw����
    // ��ʱû����֤����,Ԥ��

    // �������
    psUnpack->sAddress = psmcUnpack->sAddress;

    // ���ݿ���
    psUnpack->usNum = psmcUnpack->usNum;
    for(i = 0; i < psmcUnpack->usNum; i++)
    {
        psUnpack->sData[i] = psmcUnpack->sData[i];
    }

    TC_FREE(pMemUnpack);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etcPackCon
 ��������  : ������ ��װ���Ľӿ�
 �������  : sTcPackCon* psPack  
     
 �������  : UINT8* pOutBuf   �����ϸ�ı������� 
             UINT16* pusLen   ����ñ��ĵ��ֳ�
 �� �� ֵ  : eTcErr
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2013��12��5��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etcPackCon(sTcPackCon* psPack, UINT8* pOutBuf, UINT16* pusLen)
{
    stcPack  *pstcPack = NULL;
    UINT8    *pMemPack = NULL;
    eTcmd     eCmd     = TCMD_AFN_F_UNKOWN;
    eTcFcode  eFcode   = TC_FCD_MAX;
    eTcErr    eRet     = TC_OK;
    INT32     i        = 0;

    if(!psPack || !pOutBuf || !pusLen)
    {
        #ifdef TC_DBG
        TCDBG("etcPackTml() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pMemPack = (UINT8*)malloc(TC_USER_MAX);
    if(!pMemPack)
    {
        #ifdef TC_DBG
        TCDBG("etcPackCon() malloc failed!");
        #endif
        return TC_ERR_IO;
    }

    pstcPack = (stcPack *)pMemPack;

    // ȡ�õ�һ���������������
    eCmd = psPack->sData[0].eCmd;

    // �̶�֡
    if(TCMD_AFN_2_F1_LOG_IN     == eCmd ||
       TCMD_AFN_2_F2_LOG_OUT    == eCmd ||
       TCMD_AFN_2_F3_HEART_BEAT == eCmd ||
       TCMD_AFN_2_F4_LINK_OK    == eCmd)
    {
        // �����ֶβ�����
        pstcPack->bFixed       = TRUE;
        pstcPack->sAddress     = psPack->sAddress;

        // ������
        pstcPack->sCtrl.eDir   = TC_DIR_C2T;
        pstcPack->sCtrl.ePRM   = TC_PRM_P2A;
        pstcPack->sCtrl.ucPSEQ = psPack->ucPSEQ;
        pstcPack->sCtrl.ucRSEQ = 0;

        switch(eCmd)
        {
            case TCMD_AFN_2_F4_LINK_OK:
                pstcPack->sCtrl.eFcode = TC_FCD_LINK_OK;
                break;
            
            default:
                #ifdef TC_DBG
                TCDBG("etcPackCon() contrator don't suport cmd: TCMD_AFN_2_F4_LINK_OK!");
                #endif
                TC_FREE(pMemPack);
                return TC_ERR_PARA;
                break;
        }
    }
    // �ɱ�֡
    else
    {
        pstcPack->bFixed       = FALSE;
        pstcPack->sAddress     = psPack->sAddress;
        pstcPack->sCtrl.eDir   = TC_DIR_C2T;

        // ��վ�����Ķ�������֡
        pstcPack->sCtrl.ePRM = TC_PRM_A2P;
        
        /*
            ����֡��� PSEQ
            �ñ����ʾ 0~31����������Ͷ�Ӧ����֡���Լ���ֹ��Ϣ����Ķ�ʧ���ظ�

            (1)ÿһ������վ�ʹӶ�վ֮����� 1 �������ļ����������ڼ�¼��ǰ PSEQ��
               ����վ��ͬһ�Ӷ�վ�����µĴ������ʱ��PSEQ+1��

            (2)����ʱδ�յ��Ӷ�վ�ı��ģ�����ճ��ֲ��������վ���ı�PSEQ��
               �ظ�ԭ���Ĵ������
        */

        pstcPack->sCtrl.ucPSEQ = psPack->ucPSEQ;
     
        /*
           ��Ӧ֡��� RSEQ
            (1) ��Ӧ֡��� RSEQ �� PRM=0 ʱ�����Ӷ�֡����Ч��
                �ñ����ʾ 0~15�����ڶ���Ӷ�֡��Ӧһ������֡�Ĵ��䡣
            (2) ÿһ������վ�ʹӶ�վ֮����� 1 �������ļ�������
                ���ڼ�¼��ǰ RSEQ����ֻ��һ֡�Ӷ�֡��Ӧ����֡�ģ�
                RSEQ=0�������� n ��n��16��֡��Ӧ�ģ�RSEQ �� n-1 ��ݼ�������
                ÿ����һ֡�� 1��ֱ�����һ֡ RSEQ=0��
        */
        
        pstcPack->sCtrl.ucRSEQ = 0;

        // ������
        eRet = etc_get_fcode(eCmd, TC_DIR_C2T, pstcPack->sCtrl.ePRM, &eFcode);
        if(TC_OK != eRet)
        {
            #ifdef TC_DBG
            TCDBG("etcPackCon() etc_get_fcode error code %d!", eRet);
            #endif
            TC_FREE(pMemPack);
            return eRet;
        }
        pstcPack->sCtrl.eFcode = eFcode;

        // �������ֶ�
        pstcPack->sAc.eAfn = eTcGetCmdAfn(eCmd);

        // Ec
        pstcPack->sAc.bEc = FALSE; 
         
        // Tp
        pstcPack->sAc.bTp = btc_have_tp(pstcPack->sAc.eAfn, TC_DIR_C2T);

        // pw
        memcpy(pstcPack->aPw, psPack->aPw, TC_PW_LEN);

        // ȡ�õ�ǰϵͳʱ��
        if(TRUE == pstcPack->sAc.bTp)
        {
            eRet = etc_get_tp(&pstcPack->sTp);
            if(TC_OK != eRet)
            {
                #ifdef TC_DBG
                TCDBG("etcPackCon() etc_get_tp() error code %d!", eRet);
                #endif
                TC_FREE(pMemPack);
                return eRet;
            }
        }

        // Ӧ�ò�����
        pstcPack->usNum = psPack->usNum;

        for (i =0; i < psPack->usNum; i++)
        {
            memcpy((void*)&(pstcPack->sData[i]), (void*)&(psPack->sData[i]), sizeof(sTcData));
        }
    }

    // ���ô������
    eRet = etcPack(pstcPack, pOutBuf, pusLen);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etcPackCon() etcPack() error code %d!", eRet);
        #endif
        TC_FREE(pMemPack);
        return eRet;
    }
    
    TC_FREE(pMemPack);
    return TC_OK;
}

/*****************************************************************************
 �� �� ��  : etcUnPackCon
 ��������  : �������౨�Ľ�������
 �������  : UINT8* pInBuf   ����ı�������       
             UINT16 usLen    ���뱨�ĵ��ֳ�
 �������  : sTcPackCon *psUnpack  ������Ľṹ
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2014��1��8��
    ��    ��   : liming
    �޸�����   : �����ɺ���

*****************************************************************************/
eTcErr etcUnPackCon(sTcPackCon *psUnpack, UINT8* pInBuf, UINT16 usLen)
{
    eTcErr       eRet        = TC_OK;
    UINT8*       pMemUnpack  = NULL;
    stcPack*     psmcUnpack  = NULL;
    BOOL         bTimeOut    = FALSE;
    INT32        i           = 0;

    if(!psUnpack || !pInBuf)
    {
        #ifdef TC_DBG
        TCDBG("etcUnPackCon() pointer is null!");
        #endif
        return TC_ERR_NULL;
    }

    pMemUnpack = (UINT8*)malloc(TC_USER_MAX);
    if(!pMemUnpack)
    {
        #ifdef TC_DBG
        TCDBG("etcUnPackTml() malloc failed!");
        #endif
        return TC_ERR_IO;
    }

    psmcUnpack = (stcPack*)pMemUnpack;

    eRet = etcUnPack(psmcUnpack, pInBuf, usLen);
    if(TC_OK != eRet)
    {
        #ifdef TC_DBG
        TCDBG("etcPackTml() etcUnPack() error code %d!", eRet);
        #endif
        TC_FREE(pMemUnpack);
        return eRet;
    }

    // �ֶκϷ��Լ��
    // ���ķ���
    if(TC_DIR_T2C != psmcUnpack->sCtrl.eDir)
    {
        #ifdef TC_DBG
        TCDBG("etcUnPackCon() frame direction is error! It is not from terminal to contrator!");
        #endif
        TC_FREE(pMemUnpack);
        return TC_ERR_DIR;
    }

    // ֡���к�
    psUnpack->ucPSEQ = psmcUnpack->sCtrl.ucPSEQ;
    psUnpack->ucRSEQ = psmcUnpack->sCtrl.ucRSEQ;
        
    // Pw
    // Pw���ն˵��������ķ������ж�û��Pw�ֶ�
    // pw ֻ�����ڼ��������ն˵���Ҫ������

    #if 1
    // ʱ���ǩ
    if(TRUE == psmcUnpack->sAc.bTp)
    {
        bTimeOut = btc_tp_timeout(&(psmcUnpack->sTp));
        if(TRUE == bTimeOut)
        {
            #ifdef TC_DBG
            TCDBG("etcUnPackCon () frame is timeout!");
            #endif
            TC_FREE(pMemUnpack);
            return TC_ERR_TIMEOUT;
        }
    }
    #endif
  

    // �������
    psUnpack->sAddress = psmcUnpack->sAddress;

    // ���ݿ���
    psUnpack->usNum = psmcUnpack->usNum;
    for(i = 0; i < psmcUnpack->usNum; i++)
    {
        psUnpack->sData[i] = psmcUnpack->sData[i];
    }

    TC_FREE(pMemUnpack);
    return TC_OK;
}
