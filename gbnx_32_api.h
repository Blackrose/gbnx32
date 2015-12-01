/******************************************************************************

                  ��Ȩ���� (C), 2005-2015, ���ҵ���ͨ�����õ缼���ֹ�˾

 ******************************************************************************
  �� �� ��   : gbnx_32_api.h
  �� �� ��   : ����
  ��    ��   : liming
  ��������   : 2013��10��17��
  ����޸�   :
  ��������   : GB/T XXXX.32 2013 ��վ��ɼ��ն�ͨ��Э�����api(C����)
               ���ļ��������ҵ����������ϵͳ�����淶(����) 
               ��3-2����  ������Ч����ն�ͨ��Э��
               ��صĶ��弰Э������Ļ����ӿ�
               
  ��д˵��   : ��վ              master       -> m 
               �����ն�(������)  concentrator -> c
               �ɼ��ն�(�ն�)    terminal     -> t

               �û�������(Ĭ���ֽڶ���)
               ��֡������(��1 �ֽڶ���)

  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��10��17��
    ��    ��   : liming(vliming@126.com)
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef _GBNX_32_API_H_
#define _GBNX_32_API_H_


/*******************************************************
 *  �����ļ� �����
 *  �ô�API֮ǰ�����ú�
 *
{*///
#ifndef _TYPE_DEF_LM_
#define _TYPE_DEF_LM_
#ifndef __RTL_H__
#define __RTL_H__
typedef char                BOOL;
#endif
#define TRUE                (1)
#define FALSE               (0)
typedef unsigned char       UCHAR;
typedef char                CHAR;
typedef unsigned short      USHORT;
typedef short               SHORT;
typedef unsigned long       ULONG;
typedef long                LONG;

#ifndef _TYPE_DEF_
#define _TYPE_DEF_
typedef char                INT8;       //c
typedef short               INT16;      //s
typedef int                 INT32;      //l
typedef unsigned char       UINT8;      //uc
typedef unsigned short      UINT16;     //us
typedef unsigned int        UINT32;     //ul

#ifdef MACHINE_64_BITS
typedef long                INT64;
typedef unsigned long       UINT64;
#else
typedef long long           INT64;
typedef unsigned long long  UINT64;
#endif

typedef char*               STRING;     // str
typedef char                ISBOOL;     // b
typedef unsigned int        IPADDR;     // ip
typedef double              DOUBLE;
typedef void*               FRWK_HANDLE;
#endif
#endif
///*}

/*******************************************************
 *  �����ļ� �����
 *  �ô�API֮ǰ�����ú�
 *
{*///

#define TC_CFG_SPT_TML         (1)         // �Ƿ�֧���ն�   �����ļ� ��֧�ֽ����Ϊ 0
#define TC_CFG_SPT_CON         (1)         // �Ƿ�֧�ּ����� �����ļ� ��֧�ֽ����Ϊ 0
#define TC_CFG_MEDIUM_NET      (1)         // ͨ�Ž���,���������ĵ���󳤶� �������̫��1 ������0
#define TC_CFG_ENCRYPT         (0)         // �Ƿ���Ҫ����
#define TC_CFG_EC              (1)         // ��������Ĭ���������Ec 
#define TC_CFG_TP              (1)         // ��������Ĭ���������Tp
#define TC_CFG_PW              (1)         // ��������Ĭ���������Pw
#define TC_CFG_IP_VER          (1)         // IP��ַ�İ汾 1-IPV4 0-IPV6    
#define TC_CFG_NAME            (1)         // �Ƿ��¼�����������, ���ն˴���ռ��С������½��ú���0
///*}

/*******************************************************
 *  Э����غ궨��
 *
{*///

#define TC_PROTO_VERSION       (0x41)       // ��Э��汾

#define TC_METER_ADDR_LEN      (12)         // ����ַ����
/****************************************
 *  ��ַ��
 *  �ն˵�ַA2ѡַ��ΧΪ1��65535��
 *  A2=0000HΪ��Ч��ַ��A2=FFFFH��A3��D0λΪ"1"ʱ��ʾϵͳ�㲥��ַ��
 *
 *
 *
{*///

#define TC_TML_ADDR_MIN        (1)         // �ն˻�������ַ���ֵ
#define TC_TML_ADDR_MAX        (65535)     // ��վ��ַ���ֵ
#define TC_TML_ADDR_BRD        (0xFFFF)    // ��վ��ַ���ֵ

#define TC_MST_ADDR_MIN        (0)         // ��վ��ַ���ֵ
#define TC_MST_ADDR_MAX        (127)       // ��վ��ַ���ֵ

///*}

/****************************************
 *  Ӧ�������� ���ݵ�Ԫ��ʶ
 *  ����һ��ȷ����DaDt�ṹ,���֧�� 8��Pn ͬʱ����Ӧ�����±� 8��Fn
 *  ������Ҫ 8*8�����ݵ�Ԫ
 *
 *
 *
{*///

#define TC_PN_INDEX_MAX        (8)          // �������ݵ�Ԫ����֯
#define TC_FN_INDEX_MAX        (8)          // �������ݵ�Ԫ����֯
///*}


/****************************************
 *  ��⡢��װ��ز����ֽڳ�
 *
 *
 *
{*///
#define TC_PW_LEN              (16)         // ��Ϣ��֤����
#define TC_PN_MAX              (2040)       // ���ݵ�Ԫ��ʶ DA Pn ���ֵ
#define TC_PN_MIN              (0)          // ���ݵ�Ԫ��ʶ Da Pn ��Сֵ
#define TC_PN_NONE             (0xFFFF)     // ���ݵ�Ԫ��ʶ Da Pn ��Чֵ �����ù��ĵ�ֵ
 
#define TC_FN_MAX              (248)        // ���ݵ�Ԫ��ʶ Dt Fn ���ֵ
#define TC_FN_MIN              (1)          // ���ݵ�Ԫ��ʶ Dt Fn ��Сֵ
#define TC_FN_NONE             (0xFF)       // ���ݵ�Ԫ��ʶ Dt Fn ��Чֵ �����ù��ĵ�ֵ

#define TC_UNIT_DATA_MAX       (128)        // �������ݵ�Ԫ�ֳ�

#define TC_FRM_MAX_WRLESS      (255)        // ����ר�����������ŵ�,����L1������255
#define TC_FRM_MAX_NET         (16384)      // �������紫��,����L1������16383
#define TC_SEQ2CS_MAX          (2048)       // ÿ��֡����SEQ��CS֮�������ֽ������ֵ
#define TC_CA_LEN              (10)         // ���������ַ�����ֳ�
#define TC_VAC_LEN             (2)          // �䳤֡��Э���ʶ��Ӧ�ÿ�����AC�ֽڳ���
#define TC_CANS_LEN            (8)          // ������C ��ַ��A AFN SEQ�ֽ��ܳ�
#define TC_UN_USER_LEN         (8)          // �����з��������ܳ���  0x68 0x68 L L CS 0x16
#define TC_DADT_LEN            (4)          // ���ݱ�ʶ�ֳ� DaDt
#define TC_AFN_LEN             (1)          // AFN �ֳ�
#define TC_DADT_ERR_LEN        (TC_DADT_LEN + 1)  // DaDt �� ERR���ֳ�


// ֡������ֳ�
#if TC_CFG_MEDIUM_NET
#define TC_FRM_LEN_MAX         TC_FRM_MAX_NET
#else
#define TC_FRM_LEN_MAX         TC_FRM_MAX_WRLESS
#endif

#define TC_CS_LEN              (1)                          // У���CS�ֳ�
#define TC_FIXED_USR_LEN       (TC_A_LEN + TC_C_LEN + 1)    // �̶�֡�û��������ֳ� (������C + ��ַ��A + ��·�û�����D)
#define TC_FIXED_LEN           (TC_FIXED_USR_LEN + 3)       // �̶�֡�ֳ�           (�û������� + ��ʼ�ַ�+ CS)
#define TC_STCHAR_FIXED        (0x10)                       // �̶�֡��ʼ�ַ�
#define TC_STCHAR_ALTER        (0x68)                       // �ɱ�֡��ʼ�ַ�
#define TC_FRM_END_CHAR        (0x16)                       // ������
#define TC_ALTER_USR_OTHER_LEN (TC_A_LEN + TC_C_LEN)        // �ɱ�֡�û��������ֳ�(����·�û�����)
#define TC_ALTER_BUT_USER_LEN  (8)                          // �ɱ�֡����(�û�������֮��ĳ���)
#define TC_ALTER_OTHER_LEN     (TC_ALTER_USR_OTHER_LEN + 8) // �ɱ�֡������·�û������ⲿ���ֳ�

#define TC_A2CS_BYTE_MAX       (TC_FRM_LEN_MAX - TC_ALTER_OTHER_LEN)  // ÿ��֡����A��CS֮�������ֽ������ֵ
#define TC_USER_MAX            (2*TC_A2CS_BYTE_MAX)                   // �û���ȱ䳤�ṹ stcPack stcBasePack ��󳤶�


// ֡����С�ֳ�
#define TC_FRM_LEN_MIN         (TC_FIXED_LEN)               // ��������¼��֡����С

// IP��ַ����
#if TC_CFG_IP_VER
#define TC_IP_LEN              (4)                          // ��ӦIPv4 ��ַ����
#else 
#define TC_IP_LEN              (16)                         // ��ӦIpv6 ��ַ����
#endif
///*}

/*******************************************************
 *  �����붨�� eTcErr
 *
{*///
typedef enum
{  
    TC_OK,             // �޴���                    0
    TC_ERR_NULL,       // ָ��Ϊ��                  1
    TC_ERR_OUTRNG,     // ����Խ��                  2
    TC_ERR_NONE,       // ������,û���ҵ�           3
    TC_ERR_IO,         // IO����                    4
    TC_ERR_RES,        // ��Դ����                  5
    TC_ERR_INIT,       // û�г�ʼ��                6
    TC_ERR_PARA,       // ��������                  7
    TC_ERR_FN,         // ָ��Afn �в�֧�ֵ� Fn     8
    TC_ERR_PN,         // ָ��Afn �в�֧�ֵ� Pn     9
    TC_ERR_ADDR,       // ��Ч��ַ                  10
    TC_ERR_CTRL,       // ���������                11
    TC_ERR_0x10,       // SEQ�����                 12
    TC_ERR_A2CS,       // A2CS �������             13
    TC_ERR_AFN,        // AFN ����                  14
    TC_ERR_UNCOMP,     // ��������Э���            15
    TC_ERR_0x68,       // ����ı�����ʼ            16
    TC_ERR_PROTO,      // �����Э���ʶ            17
    TC_ERR_CS,         // ����ļ���              18
    TC_ERR_0x16,       // ����Ľ�β��              19
    TC_ERR_LOGIC,      // ����Ĵ����߼�            20
    TC_ERR_PACK,       // ����һ����Ч�İ�          21
    TC_ERR_PFC,        // ���кŲ���Ӧ              22
    TC_ERR_TIMEOUT,    // ���ĳ�ʱ                  23
    TC_ERR_PRM,        // ����վ��ʶ��              24
    TC_ERR_TEAM,       // Fn��Pn����ͬһ����        25
    TC_ERR_ENCRYPT,    // ���ܴ���                  26
    TC_ERR_DECRYPT,    // ���ܴ���                  27
    TC_ERR_L1L2,       // ֡�е�L1��L2�����        28
    TC_ERR_FCODE,      // ���������                29
    TC_ERR_DIR,        // ���ĵķ������            30
    
}eTcErr;    
///*} 

/*******************************************************
 *  Ӧ�ò㹦���� AFN
 *
{*///
typedef enum
{
    TC_AFN_00_CONF  = 0x00,     // ȷ�Ϸ���
    TC_AFN_01_RSET  = 0x01,     // ��λ
    TC_AFN_02_LINK  = 0x02,     // ��·����  ��������� Э�鱾��û�� 
    TC_AFN_04_SETP  = 0x04,     // ���ò���
    TC_AFN_05_CTRL  = 0x05,     // ��������
    TC_AFN_06_AUTH  = 0x06,     // �����֤����ԿЭ��
    TC_AFN_10_GETP  = 0x0A,     // ��ѯ����
    TC_AFN_12_ASKT  = 0x0C,     // ���󣨶�ʱ�ϱ�����������
    TC_AFN_13_ASKR  = 0x0D,     // ����ʵʱ���� 
    TC_AFN_14_ASKE  = 0x0E,     // ���������ϱ����¼���¼ 
    TC_AFN_15_FILE  = 0x0F,     // �ļ�����
    TC_AFN_16_DATA  = 0x10,     // ����ת��
    TC_AFN_NULL     = 0xFF      // �����ڵ�AFN

}eTcAFN;    
 ///*} 

/*******************************************************
 *  �����붨��
 *  �������� TCMD_AFN_(xx)_F(xx)_NAME  
 *  xx ��ʾ���� 
 *  F  ��ʾ��Ϣ���ʶ
 *  ����Э�����, ÿ���ڵ����8��Fn�������һ�����ݱ�ʶ
 *  ����: �ն˻���������վ
 *  ����: ��վ���ն˻�����
 *
{*///
typedef enum
{

    TCMD_AFN_F_UNKOWN,                                // δ֪����

    /**********************************
    * ����: ȷ��/����
    * AFN : 00H
    *  PN : p0
    * ����: ��
    * ����: ��
    {*///
    TCMD_AFN_0_F1_ALL_OK_DENY         = 0x0001,       // ȫ��ȷ��/���ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ����ȷ��/���� 
    TCMD_AFN_0_F2_ONE_BY_ONE          = 0x0003,       // �����ݵ�Ԫ��ʶȷ�Ϻͷ��ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ�������ȷ��/����
    ///*}    

    /**********************************
     * ����: ��λ����
     * AFN : 01
     *  PN : p0 /����ն˺�
     * ����: AFN 00H ȷ��/����
     * ����: ��
    {*///
    TCMD_AFN_1_F1_HARD_INIT           = 0x0101,       // Ӳ����ʼ��
    TCMD_AFN_1_F2_DATA_INIT           = 0x0102,       // ��������ʼ��
    TCMD_AFN_1_F3_FACTORY_RESET       = 0x0103,       // ������ȫ����������ʼ�������ָ����������ã�
    TCMD_AFN_1_F4_PARA_INIT           = 0x0104,       // ����������ϵͳ��վͨ���йصģ���ȫ����������ʼ��
    TCMD_AFN_1_F5_DATA_CLEAR          = 0x0105,       // ����ָ������
    ///*}                                            

    /**********************************
     * ��·�ӿڼ��
     * AFN : ��
     *  PN : ��
     * ����: ��(F1 ~ F3)
     * ����: ��(F4)
     * ˵��: ��������֡Ϊ�̶�֡,�����֡��ʽΪ�ɱ�֡
    {*///
    TCMD_AFN_2_F1_LOG_IN              = 0x0201,       // ������·����¼ϵͳ
    TCMD_AFN_2_F2_LOG_OUT             = 0x0202,       // �����·���˳�ϵͳ
    TCMD_AFN_2_F3_HEART_BEAT          = 0x0203,       // ������·����������
    TCMD_AFN_2_F4_LINK_OK             = 0x0204,       // ȷ��(��¼/�˳�/����)
    ///*}

    /**********************************
     * ����: ���ò���
     * AFN : 04
     *  PN : ���鶨��
     * ����: ��
     * ����: ��
    {*///
    // ��1   pn:p0
    TCMD_AFN_4_F1_CON_IP_PORT         = 0x0401,       // �����뽻���ն�IP��ַ�Ͷ˿�
    TCMD_AFN_4_F2_TML_UP_CFG          = 0x0402,       // ����ն�����ͨ�Ų�������
    TCMD_AFN_4_F3_TML_AUTH_PARA       = 0x0403,       // ����ն�����ͨ����Ϣ��֤��������  
    TCMD_AFN_4_F4_TML_STATE_INPUT     = 0x0404,       // ״̬���������
    TCMD_AFN_4_F5_TML_EVENT_CFG       = 0x0405,       // �¼���¼����
    
    // ��3   pn:����� 
    TCMD_AFN_4_F17_FREZ_TASK_PARA     = 0x0411,       // ����������������  

    // ��4   pn:�����������
    TCMD_AFN_4_F25_ELEC_MP_CFG        = 0x0419,       // �������������ò���
    TCMD_AFN_4_F26_ELEC_MP_BASE       = 0x041A,       // ����������������� 
    TCMD_AFN_4_F27_ELEC_LMIT_PARA     = 0x041B,       // ������������ֵ����
    TCMD_AFN_4_F28_ELEC_LMIT_FACTR    = 0x041C,       // �����������ܹ����������� 
    TCMD_AFN_4_F29_ELEC_FIX_HARM      = 0x041D,       // ����������г��������Խ�޶�ֵ
    TCMD_AFN_4_F30_ELEC_FLASH         = 0x041E,       // ��������������Խ�޲���
    
    // ��5   pn:�ǵ����������
    TCMD_AFN_4_F33_NELC_MP_CFG        = 0x0421,       // �ǵ������������ò��� 
    TCMD_AFN_4_F34_NELC_MP_PARA       = 0x0422,       // �ǵ����������������
    TCMD_AFN_4_F35_NELC_MP_LMIT       = 0x0423,       // �ǵ���������Խ�޲���
    ///*}   

    /**********************************
     * ����: ��������
     * AFN : 05
     *  PN : ���鶨��
     * ����: AFN 00H ȷ��/����
     * ����: ��
    {*///
    // ��1  pn:p0
    TCMD_AFN_5_F1_CHECK_TIME          = 0x0501,       // Уʱ����
    TCMD_AFN_5_F2_FREZ_TEMP           = 0x0502,       // ��ʱ��������
    TCMD_AFN_5_F3_AUTO_SAY_ON         = 0x0503,       // ���������ϱ� 
    TCMD_AFN_5_F4_AUTO_SAY_OFF        = 0x0504,       // ��ֹ�����ϱ� 
    TCMD_AFN_5_F5_NX_MODEL_ACT        = 0x0505,       // ��Чģ����Ч
    TCMD_AFN_5_F6_NX_MODEL_CLR        = 0x0506,       // ��Чģ�����
    TCMD_AFN_5_F7_RQ_RESPN_ACT        = 0x0507,       // ������Ӧ��Ϣ��Ч
    TCMD_AFN_5_F8_RQ_RESPN_CLT        = 0x0508,       // ������Ӧ��Ϣ���
    
    // ��2  pn:�����    
    TCMD_AFN_5_F9_REPT_FREZ_ON        = 0x0509,       // ������ʱ�ϱ�������������
    TCMD_AFN_5_F10_REPT_FREZ_OFF      = 0x050A,       // ��ֹ��ʱ�ϱ�������������

    // ��3  pn:p0
    TCMD_AFN_5_F17_REMOTE_OFF          = 0x0511,      // ң����բ
    TCMD_AFN_5_F18_REMOTE_ON           = 0x0512,      // �����բ
    ///*}
    
    /**********************************
     * ����: �����֤����ԿЭ��
     * AFN : 06
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    TCMD_AFN_6_F1_ID_AUTH_Q           = 0x0601,       // �����֤����
    TCMD_AFN_6_F2_ID_AUTH_A           = 0x0602,       // �����֤��Ӧ
    TCMD_AFN_6_F3_RAND_Q              = 0x0603,       // ȡ���������
    TCMD_AFN_6_F4_RAND_A              = 0x0604,       // ȡ�������Ӧ
    ///*}   

     /**********************************
     * ����: ��ѯ����
     * AFN : 0A
     *  PN : ���鶨��
     * ����: ��
     * ����: ��
    {*///
    // ��1   pn:p0
    TCMD_AFN_A_F1_CON_IP_PORT         = 0x0A01,       // �����뽻���ն�IP��ַ�Ͷ˿�
    TCMD_AFN_A_F2_TML_UP_CFG          = 0x0A02,       // ����ն�����ͨ�Ų�������
    TCMD_AFN_A_F3_TML_AUTH_PARA       = 0x0A03,       // ����ն�����ͨ����Ϣ��֤��������  
    TCMD_AFN_A_F4_TML_STATE_INPUT     = 0x0A04,       // ״̬���������
    TCMD_AFN_A_F5_TML_EVENT_CFG       = 0x0A05,       // �¼���¼����

    // ��2  pn:P0    
    TCMD_AFN_A_F11_TML_SPRT_EVENT     = 0x050B,       // �ն�֧�ֵ��¼���¼��Ϣ
    TCMD_AFN_A_F12_ELEC_MP_INFO       = 0x0A0C,       // �����õ�����������Ϣ
    TCMD_AFN_A_F13_NELC_MP_INFO       = 0x0A0D,       // �����÷ǵ�����������Ϣ
    TCMD_AFN_A_F14_TML_PROTO_SPRT     = 0x0A0E,       // ����˿�֧�ֵ�ͨ��Э����Ϣ
    TCMD_AFN_A_F15_TML_MODEL_VERSION  = 0x0A0F,       // �ն��ڸ�����ģ�����Ӳ���汾��Ϣ
    TCMD_AFN_A_F16_TML_VERSION        = 0x0A10,       // �ն���Ӳ���汾��Ϣ
    
    // ��3   pn:����� 
    TCMD_AFN_A_F17_FREZ_TASK_PARA     = 0x0A11,       // ����������������  

    // ��4   pn:�����������
    TCMD_AFN_A_F25_ELEC_MP_CFG        = 0x0A19,       // �������������ò���
    TCMD_AFN_A_F26_ELEC_MP_BASE       = 0x0A1A,       // ����������������� 
    TCMD_AFN_A_F27_ELEC_LMIT_PARA     = 0x0A1B,       // ������������ֵ����
    TCMD_AFN_A_F28_ELEC_LMIT_FACTR    = 0x0A1C,       // �����������ܹ����������� 
    TCMD_AFN_A_F29_ELEC_FIX_HARM      = 0x0A1D,       // ����������г��������Խ�޶�ֵ
    TCMD_AFN_A_F30_ELEC_FLASH         = 0x0A1E,       // ��������������Խ�޲���
    
    // ��5   pn:�ǵ����������
    TCMD_AFN_A_F33_NELC_MP_CFG        = 0x0A21,       // �ǵ������������ò��� 
    TCMD_AFN_A_F34_NELC_MP_PARA       = 0x0A22,       // �ǵ����������������
    TCMD_AFN_A_F35_NELC_MP_LMIT       = 0x0A23,       // �ǵ���������Խ�޲���
    ///*}

    /**********************************
     * ����: ����(��ʱ�ϱ�)��������
     * AFN : 0CH
     *  PN : ���鶨��
     * ����: ��
     * ����: ��
    {*///
     // ��1   pn:p0
    TCMD_AFN_C_F1_FREZ_TEMP          = 0x0A01,       // ������ʱ��������Ķ�������  

     // ��2   pn:�����
    TCMD_AFN_C_F9_FREZ_AUTO          = 0x0A09,       // ���󣨶�ʱ�ϱ��������������� 
    ///*} 

    /**********************************
     * ����: ����ʵʱ����
     * AFN : 13
     *  PN : ���鶨��
     * ����: ��
     * ����: ��
    {*///
    // ��1   pn: p0
    TCMD_AFN_D_F1_CLOCK              = 0x0D01,       // ����ʱ��  
    TCMD_AFN_D_F2_PARA_STATE         = 0x0D02,       // ����״̬    
    TCMD_AFN_D_F3_EVENT_1            = 0x0D03,       // ��Ҫ�¼���������ǰֵ  
    TCMD_AFN_D_F4_EVENT_2            = 0x0D04,       // һ���¼���������ǰֵ  
    TCMD_AFN_D_F5_EVENT_STATE        = 0x0D05,       // �¼�״̬��־   
    TCMD_AFN_D_F6_POWR_TIMES         = 0x0D06,       // �ϵ����  

    // ��2   pn: p0
    TCMD_AFN_D_F9_STATE              = 0x0D09,       // ״̬������λ��־ 

    // ��3   pn:����������� 
    TCMD_AFN_D_F17_POWR_HAVE_T       = 0x0D11,       // ���й����� 
    TCMD_AFN_D_F18_POWR_NONE_T       = 0x0D12,       // ���޹�����  
    TCMD_AFN_D_F19_DEMD_TIME_D       = 0x0D13,       // ���������������ʱ��
    TCMD_AFN_D_F20_DEMD_TIME_M       = 0x0D14,       // ���������������ʱ��
    TCMD_AFN_D_F21_FACTR_T           = 0x0D15,       // �ܹ������� 
    TCMD_AFN_D_F22_FACTR_A           = 0x0D16,       // A�๦������ 
    TCMD_AFN_D_F23_FACTR_B           = 0x0D17,       // B�๦������  
    TCMD_AFN_D_F24_FACTR_C           = 0x0D18,       // C�๦������ 

    // ��4   pn:�����������
    TCMD_AFN_D_F25_POWR_HAVE_A       = 0x0D19,       // A���й����� 
    TCMD_AFN_D_F26_POWR_HAVE_B       = 0x0D1A,       // B���й����� 
    TCMD_AFN_D_F27_POWR_HAVE_C       = 0x0D1B,       // C���й����� 
    TCMD_AFN_D_F28_POWR_NONE_A       = 0x0D1C,       // A���޹�����  
    TCMD_AFN_D_F29_POWR_NONE_B       = 0x0D1D,       // B���޹�����  
    TCMD_AFN_D_F30_POWR_NONE_C       = 0x0D1E,       // C���޹�����  

    // ��5   pn:�����������
    TCMD_AFN_D_F33_POWR_HAVE_FRTH    = 0x0D21,       // �������й��ܵ���ʾ��
    TCMD_AFN_D_F34_POWR_HAVE_BACK    = 0x0D22,       // �������й��ܵ���ʾ�� 
    TCMD_AFN_D_F35_POWR_NONE_FRTH    = 0x0D23,       // �������޹��ܵ���ʾ��
    TCMD_AFN_D_F36_POWR_NONE_BACK    = 0x0D24,       // �������޹��ܵ���ʾ�� 

    // ��6 pn:�����������
    TCMD_AFN_D_F41_VOLT_A            = 0x0D29,       // A���ѹ     
    TCMD_AFN_D_F42_VOLT_B            = 0x0D2A,       // B���ѹ     
    TCMD_AFN_D_F43_VOLT_C            = 0x0D2B,       // C���ѹ     
    TCMD_AFN_D_F44_VANGL_A           = 0x0D2C,       // A���ѹ��λ��    
    TCMD_AFN_D_F45_VANGL_B           = 0x0D2D,       // B���ѹ��λ��     
    TCMD_AFN_D_F46_VANGL_C           = 0x0D2E,       // C���ѹ��λ��     
    TCMD_AFN_D_F47_VOLT_UBL          = 0x0D2F,       // ��ѹ��ƽ���      
    TCMD_AFN_D_F48_CIRCLE_V          = 0x0D30,       // �ܲ�

    // ��7 pn:�����������
    TCMD_AFN_D_F49_ELEC_A            = 0x0D31,       // A�����      
    TCMD_AFN_D_F50_ELEC_B            = 0x0D32,       // B�����      
    TCMD_AFN_D_F51_ELEC_C            = 0x0D33,       // C�����      
    TCMD_AFN_D_F52_ELEC_M            = 0x0D34,       // �����ߵ���      
    TCMD_AFN_D_F53_EANGL_A           = 0x0D35,       // A�������λ��     
    TCMD_AFN_D_F54_EANGL_B           = 0x0D36,       // B�������λ��     
    TCMD_AFN_D_F55_EANGL_C           = 0x0D37,       // C�������λ��     
    TCMD_AFN_D_F56_ELEC_UBL          = 0x0D38,       // ������ƽ���      

    // ��8 pn:�����������
    TCMD_AFN_D_F57_VDMAX_A_TIME      = 0x0D39,       // ��A���ѹ����ֵ�ͷ���ʱ��      
    TCMD_AFN_D_F58_VDMAX_B_TIME      = 0x0D3A,       // ��B���ѹ����ֵ�ͷ���ʱ��      
    TCMD_AFN_D_F59_VDMAX_C_TIME      = 0x0D3B,       // ��C���ѹ����ֵ�ͷ���ʱ��     
    TCMD_AFN_D_F60_IDMAX_A_TIME      = 0x0D3C,       // ��A���������ֵ�ͷ���ʱ��      
    TCMD_AFN_D_F61_IDMAX_B_TIME      = 0x0D3D,       // ��B���������ֵ�ͷ���ʱ��      
    TCMD_AFN_D_F62_IDMAX_C_TIME      = 0x0D3E,       // ��C���������ֵ�ͷ���ʱ��     

    // ��9 pn:�����������
    TCMD_AFN_D_F65_VDPP_TIME_A       = 0x0D41,       // A���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F66_VDPP_TIME_B       = 0x0D42,       // B���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F67_VDPP_TIME_C       = 0x0D43,       // C���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F68_VDNN_TIME_A       = 0x0D44,       // A���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F69_VDNN_TIME_B       = 0x0D45,       // B���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F70_VDNN_TIME_C       = 0x0D46,       // C���ѹԽ���������ۼ�ʱ��  

    // ��10 pn:�����������
    TCMD_AFN_D_F73_VMPP_TIME_A        = 0x0D49,       // A���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F74_VMPP_TIME_B        = 0x0D4A,       // B���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F75_VMPP_TIME_C        = 0x0D4B,       // C���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F76_VMNN_TIME_A        = 0x0D4C,       // A���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F77_VMNN_TIME_B        = 0x0D4D,       // B���ѹԽ���������ۼ�ʱ��  
    TCMD_AFN_D_F78_VMNN_TIME_C        = 0x0D4E,       // C���ѹԽ���������ۼ�ʱ��  

    // ��11 pn:�����������
    TCMD_AFN_D_F81_VABR_TOTL_A       = 0x0D51,       // A���ѹ�ܻ�����  
    TCMD_AFN_D_F82_VABR_TOTL_B       = 0x0D52,       // B���ѹ�ܻ�����  
    TCMD_AFN_D_F83_VABR_TOTL_C       = 0x0D53,       // C���ѹ�ܻ�����  
    TCMD_AFN_D_F84_EABR_TOTL_A       = 0x0D54,       // A������ܻ�����  
    TCMD_AFN_D_F85_EABR_TOTL_B       = 0x0D55,       // B������ܻ�����  
    TCMD_AFN_D_F86_EABR_TOTL_C       = 0x0D56,       // C������ܻ�����  

    // ��12 pn:�����������
    TCMD_AFN_D_F89_VABR_OOD_A        = 0x0D59,       // A���ѹ��λ�����  
    TCMD_AFN_D_F90_VABR_EVN_A        = 0x0D5A,       // A���ѹż�λ�����  
    TCMD_AFN_D_F91_VABR_OOD_B        = 0x0D5B,       // B���ѹ��λ�����  
    TCMD_AFN_D_F92_VABR_EVN_B        = 0x0D5C,       // B���ѹż�λ�����  
    TCMD_AFN_D_F93_VABR_OOD_C        = 0x0D5D,       // C���ѹ��λ�����  
    TCMD_AFN_D_F94_VABR_EVN_C        = 0x0D5E,       // C���ѹż�λ�����  

    // ��13 pn:�����������
    TCMD_AFN_D_F97_EABR_OOD_A        = 0x0D61,       // A�������λ�����  
    TCMD_AFN_D_F98_EABR_EVN_A        = 0x0D62,       // A�����ż�λ�����  
    TCMD_AFN_D_F99_EABR_OOD_B        = 0x0D63,       // B�������λ�����  
    TCMD_AFN_D_F100_EABR_EVN_B       = 0x0D64,       // B�����ż�λ�����  
    TCMD_AFN_D_F101_EABR_OOD_C       = 0x0D65,       // C�������λ����� 
    TCMD_AFN_D_F102_EABR_EVN_C       = 0x0D66,       // C�����ż�λ�����  

    // ��14 pn:�����������
    TCMD_AFN_D_F105_TFW_HAVE         = 0x0D69,       // �ܻ����й�����  
    TCMD_AFN_D_F106_TFW_NONE         = 0x0D6A,       // �ܻ����޹�����   
    TCMD_AFN_D_F107_THW_HAVE         = 0x0D6B,       // ��г���й�����  
    TCMD_AFN_D_F108_THW_NONE         = 0x0D6C,       // �ܻ����޹�����    
   
    // ��15 pn:�����������
    TCMD_AFN_D_F113_HARM_VOLT_A      = 0x0D71,       // A��N��г����ѹ
    TCMD_AFN_D_F114_HARM_VOLT_B      = 0x0D72,       // B��N��г����ѹ
    TCMD_AFN_D_F115_HARM_VOLT_C      = 0x0D73,       // C��N��г����ѹ
    TCMD_AFN_D_F116_HARM_ELEC_A      = 0x0D74,       // A��N��г������
    TCMD_AFN_D_F117_HARM_ELEC_B      = 0x0D75,       // B��N��г������
    TCMD_AFN_D_F118_HARM_ELEC_C      = 0x0D76,       // C��N��г������

    // ��16 pn:�����������
    TCMD_AFN_D_F121_HARM_VINC_A      = 0x0D79,       // A��N��г����ѹ������
    TCMD_AFN_D_F122_HARM_VINC_B      = 0x0D7A,       // B��N��г����ѹ������
    TCMD_AFN_D_F123_HARM_VINC_C      = 0x0D7B,       // C��N��г����ѹ������
    TCMD_AFN_D_F124_HARM_EINC_A      = 0x0D7C,       // A��N��г������������
    TCMD_AFN_D_F125_HARM_EINC_B      = 0x0D7D,       // B��N��г������������
    TCMD_AFN_D_F126_HARM_EINC_C      = 0x0D7E,       // C��N��г������������
    
    // ��17 pn:�����������
    TCMD_AFN_D_F129_FLS_SHRT_A       = 0x0D81,       // A���ʱ����
    TCMD_AFN_D_F130_FLS_SHRT_B       = 0x0D82,       // B���ʱ����
    TCMD_AFN_D_F131_FLS_SHRT_C       = 0x0D83,       // C���ʱ����
    TCMD_AFN_D_F132_FLS_LONG_A       = 0x0D84,       // A�೤ʱ����
    TCMD_AFN_D_F133_FLS_LONG_B       = 0x0D85,       // B�೤ʱ����
    TCMD_AFN_D_F134_FLS_LONG_C       = 0x0D86,       // C�೤ʱ����

    // ��18 pn:�ǵ����������
    TCMD_AFN_D_F137_NELC_VALUE       = 0x0D89,       // �ǵ�����
    ///*} 

   /**********************************
     * ����: ���������ϱ����¼���¼
     * AFN : 0E
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    TCMD_AFN_E_F1_EVENT_1             = 0x0E01,       // ���������ϱ�����Ҫ�¼�
    TCMD_AFN_E_F2_EVENT_2             = 0x0E02,       // ���������ϱ���һ���¼�
    TCMD_AFN_E_F3_EVENT_S             = 0x0E03,       // ����ָ���¼���¼
    ///*}   

    
    /**********************************
     * ����: �ļ�����
     * AFN : 0F
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    // ��1   pn:p0/����ն˺� 
    TCMD_AFN_F_F1_SOFT_DOWN           = 0x0F01,        // ������� 
    TCMD_AFN_F_F2_SOFT_LEFT           = 0x0F02,        // �������δ�յ����ݶ�  

    // ��2   pn:p0/����ն˺� 
    TCMD_AFN_F_F9_NXMD_DOWN           = 0x0F09,        // ������� 
    TCMD_AFN_F_F10_NXMD_LEFT          = 0x0F0A,        // �������δ�յ����ݶ�  

    // ��3   pn:p0/����ն˺� 
    TCMD_AFN_F_F17_REQS_DOWN          = 0x0F11,        // ������� 
    TCMD_AFN_F_F18_REQS_LEFT          = 0x0F12,        // �������δ�յ����ݶ�  
    ///*}  

     /**********************************
     * ����: ����ת��
     * AFN : 10H
     *  PN : p0
     * ����: ��
     * ����: ��
    {*///
    // ��1 Pn:P0
    TCMD_AFN_10_F1_TRANSMIT           = 0x1001,       // ͸��ת��
    ///*}  
     
    /* ����֮�������չ������ */    
    TCMD_AFN_FN_MAX  

}eTcmd;
///*} 

/*******************************************************
 *  �¼����Ͷ��� eTcErc
 *
{*///
typedef enum
{
    TC_ERC_UNKOWN,            // ERC0: δ֪�¼���¼����
    TC_ERC_1_RESET,           // ERC1: ��λ�¼�
    TC_ERC_2_SOFT_CHANGE,     // ERC2: ����汾����¼�
    TC_ERC_3_PARA_CHANGE,     // ERC3: ��������¼�
    TC_ERC_4_STATE_CHANGE,    // ERC4: ״̬����λ�¼�
    TC_ERC_5_REMOTE_SWITCH,   // ERC5: ң����բ�¼�
    TC_ERC_6_POWER_ON_OFF,    // ERC6: ͣ/�ϵ��¼� 
    TC_ERC_7_FACTOR_OVER,     // ERC7: �ܹ�������Խ���¼�
    TC_ERC_8_VOLT_EXCP,       // ERC8: ��ѹƫ��Խ���¼�
    TC_ERC_9_VOLT_CRICLE,     // ERC9: ��ѹ��·�쳣�¼�
    TC_ERC_10_ELEC_CRICLE,    // ERC10:������·�쳣�¼�
    TC_ERC_11_VOLT_OVER,      // ERC11:��ѹԽ���¼�
    TC_ERC_12_ELEC_OVER,      // ERC12:����Խ���¼�
    TC_ERC_13_UNBL_OVER_V,    // ERC13:��ѹ��ƽ���Խ���¼�
    TC_ERC_14_UNBL_OVER_I,    // ERC14:������ƽ��Խ���¼�
    TC_ERC_15_HUNBL_OVER_V,   // ERC15:г����ѹ������Խ���¼�
    TC_ERC_16_HUNBL_OVER_I,   // ERC16:г������������Խ���¼�
    TC_ERC_17_NELC_OVER,      // ERC17:�ǵ�����Խ���¼�
    TC_ERC_NUM_MAX            // �¼��������ֵ
}eTcEventRecord, eTcErc; // �¼����Ͷ���
///*} 

/*******************************************************
 *  ֡�����û��� ���ݽṹת���������Ͷ���
 *
{*///
typedef enum
{
    TC_TRANS_UNKOWN,    // δ֪����
    TC_TRANS_U2F,       // �û������ݽṹ��֡���ݽṹ
    TC_TRANS_F2U,       // ֡�����ݽṹ���û������ݽṹ

}eTcTrans;              // �û�����֡�����ݽṹת������

// ת��֡�����û������ݽṹ�ĺ���ָ������
// pusLen Ϊ��װ��֡��������ֽڳ�
typedef eTcErr (*pTcFunc)(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*}

/************************************************************
 *  �ڲ��ӿ�
 *
{*///
/*******************************************************************
 *  ��¼A ���ݸ�ʽ�Ķ�����ת������
 *
{*///

/*********************************************
 *  ���ݸ�ʽ01 ���ڱ�A.1
 *  ��ʽ:
 *  �ֳ�: 6
 *  +-------+------+------+------+------+------+------+------+------+
 *  |              |                       �ֽڸ�ʽ                 |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ʱ  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |����-��| ����BCD��λ        |��BCD |        ��BCD���λ        |
 *  |       |                    |��ʮλ|                           |
 *  +-------+------+------+------+------+------+------+------+------+
 *  |   ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  ���ڶ������£�D5 ~ D7�����ʾ 0 ~ 7��0����Ч��1-7���α�ʾ����һ��������
{*///

// �û���
typedef struct
{
    UINT8 ucYY;    // ��
    UINT8 ucMM;    // ��
    UINT8 ucWW;    // ����
    UINT8 ucDD;    // ��
    UINT8 ucHH;    // Сʱ
    UINT8 ucmm;    // ����
    UINT8 ucss;    // ��

}sTcUerClock, sTcFmt01, sTcYWMDhms;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8  bcd_ss_0:4;  //��
    UINT8  bcd_ss_1:4;
    UINT8  bcd_mm_0:4;  // ��
    UINT8  bcd_mm_1:4;
    UINT8  bcd_HH_0:4;  // ʱ
    UINT8  bcd_HH_1:4;
    UINT8  bcd_DD_0:4;  // ��
    UINT8  bcd_DD_1:4;
    UINT8  bcd_MM_0:4;  // ��
    UINT8  bcd_MM_1:1;
    UINT8  bcd_WW_0:3;  // ����
    UINT8  bcd_YY_0:4;  // ��
    UINT8  bcd_YY_1:4;

}sTcUerClock_f, sTcFmt01_f, sTcYWMDhms_f;
#pragma pack()

// ת������
eTcErr etc_trans_YWMDhms(eTcTrans eTrans, sTcYWMDhms* psUser, sTcYWMDhms_f* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ2 ���ڱ�A.2
 *  ��λ: ������ʱ��
 *  �ֳ�: 5
 *  ��ʽ:
 *  +------+------+------+------+------+------+------+------+------+
 *  |      |                       �ֽڸ�ʽ                        |
 *  + ���� +------+------+------+------+------+------+------+------+
 *  |      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ʱ  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
typedef struct
{
    UINT8  ucYY;        // ��
    UINT8  ucMM;        // ��
    UINT8  ucDD;        // ��
    UINT8  ucHH;        // ʱ
    UINT8  ucmm;        // ��

}sTcFmt02, sTcYYMMDDhhmm, sTcYMDhm;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8  bcd_mm_0:4;  // ��
    UINT8  bcd_mm_1:4;
    UINT8  bcd_hh_0:4;  // ʱ
    UINT8  bcd_hh_1:4;
    UINT8  bcd_DD_0:4;  // ��
    UINT8  bcd_DD_1:4;
    UINT8  bcd_MM_0:4;  // ��
    UINT8  bcd_MM_1:4;
    UINT8  bcd_YY_0:4;  // ��
    UINT8  bcd_YY_1:4;

}sTcFmt02_f, sTcYYMMDDhhmm_f, sTcYMDhm_f;
#pragma pack()

// ת������
eTcErr etc_trans_YYMMDDhhmm(eTcTrans eTrans, sTcYMDhm* psUser, sTcYMDhm_f* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ3 ���ڱ�A.3
 *  ��λ: ����ʱ��
 *  �ֳ�: 4
 *  ��ʽ:
 *  +------+------+------+------+------+------+------+------+------+
 *  |      |                       �ֽڸ�ʽ                        |
 *  + ���� +------+------+------+------+------+------+------+------+
 *  |      |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ʱ  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *  |  ��  |         BCD��ʮλ         |         BCD���λ         |
 *  +------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
typedef struct
{
    UINT8  ucDD;        // ��
    UINT8  ucHH;        // ʱ
    UINT8  ucmm;        // ��
    UINT8  ucss;        // ��
}sTcFmt03, sTcDDHHmmss;

// ֡��
typedef struct
{
    UINT8  bcd_ss_0:4;  // ��
    UINT8  bcd_ss_1:4;
    UINT8  bcd_mm_0:4;  // ��
    UINT8  bcd_mm_1:4;
    UINT8  bcd_HH_0:4;  // ʱ
    UINT8  bcd_HH_1:4;
    UINT8  bcd_DD_0:4;  // ��
    UINT8  bcd_DD_1:4;

}sTcFmt03_f, sTcDDHHmmss_f;

// ת������
eTcErr etc_trans_DDHHmmss(eTcTrans eTrans, sTcDDHHmmss* psDDHHmmss_u, sTcDDHHmmss_f* psDDHHmmss_f);
///*}

/*********************************************
 *  ���ݸ�ʽ4 ���ڱ�A.4
 *  ��ʽ: (+)XXXXXX.XXXX
 *  �ֳ�: 5
 *  ��ʽ:
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ǧ��λ        |        BCD�����λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE4 |         BCD��ǧλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE5 |        BCD��ʮ��λ        |          BCD����λ        |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// double dXXXXXX.XXXX

// ֡��
typedef struct
{
    UINT8 BCD_0_4:4;  // BCD �ٷ�λ
    UINT8 BCD_0_3:4;  // BCD ʮ��λ
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
    UINT8 BCD_2  :4;  // BCD ��λ
    UINT8 BCD_3  :4;  // BCD ǧλ
    UINT8 BCD_4  :4;  // BCD ��λ
    UINT8 BCD_5  :4;  // BCD ʮ��λ

}sTcFmt04, sTcFmt04_f, sTcFmt_XXXXXX_XXXX;

// ת������
eTcErr etc_trans_XXXXXX_XXXX(eTcTrans eTrans, double* psUser, sTcFmt_XXXXXX_XXXX* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ5 ���ڱ�A.5
 *  ��ʽ: (+)XXXXXX.XX
 *  �ֳ�: 4
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |         BCD��ǧλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE4 |        BCD��ʮ��λ        |         BCD����λ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// double dXXXXXX.XX

// ֡��
typedef struct
{
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
    UINT8 BCD_2  :4;  // BCD ��λ
    UINT8 BCD_3  :4;  // BCD ǧλ
    UINT8 BCD_4  :4;  // BCD ��λ
    UINT8 BCD_5  :4;  // BCD ʮ��λ

}sTcFmt05, sTcFmt05_f, sTcFmt_XXXXXX_XX;

// ת������
eTcErr etc_trans_XXXXXX_XX(eTcTrans eTrans, double* psUser, sTcFmt_XXXXXX_XX* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ6 ���ڱ�A.6
 *  ��ʽ: (+/-)XX.XXXX
 *  �ֳ�: 3
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ǧ��λ        |        BCD�����λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |  S   |     BCD��ʮλ      |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// float fXX.XXXX

// ֡��
typedef struct
{
    UINT8 BCD_0_4:4;  // BCD ���λ
    UINT8 BCD_0_3:4;  // BCD ǧ��λ
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :3;  // BCD ʮλ
    UINT8 S      :1;  // ����λ
}sTcFmt06_f, sTcFmt_sXX_XXXX;

// 10 exp�η� exp < 10
int  ntc_pow(UINT8 exp);

// ת������
eTcErr etc_trans_sXX_XXXX(eTcTrans eTrans, float* psUser, sTcFmt06_f* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ07 ���ڱ�A.7
 *  ��ʽ: (+/-)XXX.X
 *  �ֳ�: 2
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD�����λ        |        BCD��ʮ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |  S   |     BCD���λ      |         BCD��ʮλ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///
// �û���
// float fsXXX.X

// ֡��
typedef struct
{
    UINT8 BCD_0_1:4; // BCD ʮ��λ
    UINT8 BCD_0  :4; // BCD ��λ
    UINT8 BCD_1  :4; // BCD ʮλ
    UINT8 BCD_2  :3; // BCD ��λ
    UINT8 S      :1; // BCD ����λ
}sTcFmt07, sTcFmt07_f, sTcFmt_sXXX_X;

// ת������
eTcErr etc_trans_sXXX_X(eTcTrans eTrans, float* psUser, sTcFmt07_f* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ08 ���ڱ�A.8
 *  ��ʽ: (+)XXX.X
 *  �ֳ�: 2
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD�����λ        |        BCD��ʮ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD���λ         |         BCD��ʮλ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// float fXXX.X

// ֡��
typedef struct
{
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
    UINT8 BCD_2  :4;  // BCD ��λ
}sTcFmt08, sTcFmt08_f, sTcFmt_XXX_X;

// ת������
eTcErr etc_trans_XXX_X(eTcTrans eTrans, float* psUser, sTcFmt_XXX_X* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ09 ���ڱ�A.9
 *  ��ʽ: (+/-)XXX.XXX
 *  �ֳ�: 3
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + ����  +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ٷ�λ        |        BCD��ǧ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD���λ         |        BCD��ʮ��λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |  S   |     BCD���λ      |         BCD��ʮλ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *
{*///

// �û���
// float sXXX.XXX    (+/-)XXX.XXX

// ֡��
typedef struct
{
    UINT8 BCD_0_3:4;  // BCD ǧ��λ
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
    UINT8 BCD_2  :3;  // BCD ��λ
    UINT8 S      :1;  // ����λ

}sTcFmt09,sTcFmt09_f,sTcFmt_sXXX_XXX;

// ת������
eTcErr etc_trans_sXXX_XXX(eTcTrans eTrans, float* psUser, sTcFmt_sXXX_XXX* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ10 ���ڱ�A.10 ��ʽ�б�
 *  ��ʽ: (+)XX.XX
 *  �ֳ�: 2
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |        BCD��ʮ��λ        |        BCD��ٷ�λ        |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
{*///

// �û���
// float fXX.XX

// ֡��
typedef struct
{
    UINT8 BCD_0_2:4;  // BCD �ٷ�λ
    UINT8 BCD_0_1:4;  // BCD ʮ��λ
    UINT8 BCD_0  :4;  // BCD ��λ
    UINT8 BCD_1  :4;  // BCD ʮλ
}sTcFmt10_f, sTcFmt_XX_XX;

// ת������
eTcErr etc_trans_XX_XX(eTcTrans eTrans, float* psUser, sTcFmt10_f* psFrame);
///*}

/*********************************************
 *  ���ݸ�ʽ11 ���ڱ�A.11
 *  ��ʽ: (+/-)XXXXXXX
 *  �ֳ�: 4
 *  +-------+------+------+------+------+------+------+------+------+
 *  |       |                       �ֽڸ�ʽ                        |
 *  + �� �� +------+------+------+------+------+------+------+------+
 *  |       |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE1 |         BCD��ʮλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE2 |         BCD��ǧλ         |         BCD���λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE3 |        BCD��ʮ��λ        |         BCD����λ         |
 *  +-------+------+------+------+------+------+------+------+------+
 *  | BYTE4 |  G3  |  G2  |  G1  |  S   |         BCD�����λ       |
 *  +-------+------+------+------+------+------+------+------+------+
 *  
 *  +-------+-------+-------+----------+
 *  |   G3  |  G2   |  G1   |   ����   |
 *  +-------+-------+-------+----------+
 *  |   0   |   0   |   0   |   10(4)  |
 *  +-------+-------+-------+----------+
 *  |   0   |   0   |   1   |   10(3)  |
 *  +-------+-------+-------+----------+
 *  |   0   |   1   |   0   |   10(2)  |
 *  +-------+-------+-------+----------+
 *  |   0   |   1   |   1   |   10(1)  |
 *  +-------+-------+-------+----------+
 *  |   1   |   0   |   0   |   10(0)  |
 *  +-------+-------+-------+----------+
 *  |   1   |   0   |   1   |   10(-1) |
 *  +-------+-------+-------+----------+
 *  |   1   |   1   |   0   |   10(-2) |
 *  +-------+-------+-------+----------+
 *  |   1   |   1   |   1   |   10(-3) |
 *  +-------+-------+-------+----------+
 *
 *  S ����λ:S = 0 ���� S = 1 ��ʾ����
 *
{*///
// �û���
//double dValue
#define TC_SX7_MIN     (-99999990000.0)
#define TC_SX7_MAX     (99999990000.0)

typedef enum
{
    TC_PREC_UNKOWN,
    TC_PREC_P4,  // ��Χ 0, (+/-)10000~99999990000
    TC_PREC_P3,  // ��Χ 0, (+/-)1000~9999999000
    TC_PREC_P2,  // ��Χ 0, (+/-)100~999999900
    TC_PREC_P1,  // ��Χ 0, (+/-)10~99999990
    TC_PREC_P0,  // ��Χ 0, (+/-)1~9999999
    TC_PREC_N1,  // ��Χ 0, (+/-)0.1~999999.9
    TC_PREC_N2,  // ��Χ 0, (+/-)0.01~99999.99
    TC_PREC_N3,  // ��Χ 0, (+/-)0.001~9999.999

}eTcPrecise;            // ����

typedef struct
{
    eTcPrecise  ePrec;
    double      dValue;   
}sTcFmt11, sTcDouble; 

// ֡��
#pragma pack(1)
typedef struct
{
    UINT8 BCD_0  :4; // BCD ��λ
    UINT8 BCD_1  :4; // BCD ʮλ
    UINT8 BCD_2  :4; // BCD ��λ
    UINT8 BCD_3  :4; // BCD ǧλ
    UINT8 BCD_4  :4; // BCD ��λ
    UINT8 BCD_5  :4; // BCD ʮ��λ
    UINT8 BCD_6  :4; // BCD ����λ
    UINT8 SG123  :4;
    /*
    UINT8 S      :1; // ����λ 0 Ϊ�� 1Ϊ��
    UINT8 G1     :1; // 
    UINT8 G2     :1; // 
    UINT8 G3     :1; // 
    */
}sTcFmt11_f, sTcFmt_sX7_f;
#pragma pack()

// ת������
eTcErr etc_trans_sX7(eTcTrans eTrans, void* psUser, void* psFrame);
///*}
///*}

/******************************************************************************
 *  ��������:float���͵�
 *  ����˵��:
 *  �������ڻ�����ָ����ʽ��ʾ���ֽ�Ϊ��������β����ָ������ָ���Ĳ��֡�
 *  �����ǵ����Ȼ���˫�����ڴ洢�ж���Ϊ�������֣�
 1.����λ(Sign) : 0��������1����Ϊ��
 2.ָ��λ��Exponent��:���ڴ洢��ѧ�������е�ָ�����ݣ����Ҳ�����λ�洢
 3.β�����֣�Mantissa����β������
{*///
typedef union
{
    float v;
    struct
    {
        unsigned mantissa1 : 23;
        unsigned exponent  : 8;
        unsigned sign      : 1;
    }s;

}uMcFloatFmt;

int    ntc_get_float_sign(float fVal);              // ȡ��һ��flaot�ķ���λ  sign = -1 / +1
void   vtc_set_float_sign(float *pfVal, int sign);  // ����һ���������ķ���λ sign = -1 / +1
///*}

/******************************************************************************
 * ��������: double ���͵ĺϳ����ϳ�
 * ����˵��:
 * �������ڻ�����ָ����ʽ��ʾ���ֽ�Ϊ��������β����ָ������ָ���Ĳ��֡�
 * �����ǵ����Ȼ���˫�����ڴ洢�ж���Ϊ�������֣�
 *   1.����λ(Sign) : 0��������1����Ϊ��
 *   2.ָ��λ��Exponent��:���ڴ洢��ѧ�������е�ָ�����ݣ����Ҳ�����λ�洢
 *   3.β�����֣�Mantissa����β������
 *
{*///
typedef union
{
    double v;
    struct
    {
        unsigned mantissa2 : 32;
        unsigned mantissa1 : 20;
        unsigned exponent  : 11;
        unsigned sign      :  1;
    } s;

}uMcDoubleFmt;

int    ntc_get_double_sign(double dVal);              // ȡ��һ��double�ķ���λ sign = -1 / +1
void   vtc_set_double_sign(double *pdVal, int sign);  // ����һ���������ķ���λ sign = -1 / +1
///*}
///*}


/*********************************************
 *  BCD ת������
 *
 *
{*///
UINT8 uctc_get_bcd_0(UINT8 ucData);        // ��ø�����BCD��λ
UINT8 uctc_get_bcd_1(UINT8 ucData);        // ��ø�����BCD��λ
///*}

/***************************************************************************
 * BCD �� �ַ�����ת������
 * len ����Ϊż��
 *
{*///
eTcErr etc_str_to_bcd(const UINT8* pstr, UINT8* pbcd, INT32 len);
eTcErr etc_bcd_to_str(const UINT8* pbcd, UINT8* pstr, INT32 len);
///*}

/*******************************************************
 *  ��������Ϣ���ݱ�ӳ�亯��
 *
{*///
typedef enum
{
    TC_ROLE_UNKOWN,    // δ֪���
    TC_ROLE_CONTOR,    // ������
    TC_ROLE_TERMIN,    // �ն�
}eTcRole;              // Э��Ӧ��ģ������
 
typedef enum
{
    TC_DIR_UNKOWN,     // δ֪���ķ���
    TC_DIR_C2T,        // ���������ն�  ����
    TC_DIR_T2C,        // �ն˵�������  ����
}eTcDir;               // ���ĵķ��ͷ���

typedef enum
{
    TC_PN_UNKOWN,      // δ֪PN����
    TC_PN_P0,          // P0 ������PN ����������
    TC_PN_MP,          // �������(measured point)
    TC_PN_TK,          // �����  (task number)
    TC_PN_TM,          // �ն˺�

}eTcPn;                // Pn����

typedef struct
{
    eTcmd    eCmd;     // �������ʶ
    eTcDir   eDir;     // �ñ��Ĵ��ڵķ�������
    eTcPn    ePn;      // Pn����
    pTcFunc  pFunc;    // �������Ӧ���û����������װ�����ݽṹת������

    #if TC_CFG_NAME
    char*    pName;    // ��Э����Ϣ�����ĺ���
    #endif
    
}sTcmdInfor;
///*}

// ͨ���������ͺͱ��ķ����ø������Ӧ�������Ϣ
eTcErr eTcGetCmdInfor(eTcmd eCmd, eTcDir eDir, sTcmdInfor* psInfor);
///*}

/************************************************************
 *  ��ַ��A�ṹ
 *
{*///
// �û���ṹ
#define TC_REGN_LEN   (6)      // ����������A1 ���� (�û���)
#define TC_A1_LEN     (3)      // ����������A1 ���� (��֡��)
#define TC_A_LEN      (8)      // ��ַ�� ֡�೤��

typedef struct
{
    UINT8  acRegionCode[TC_REGN_LEN];   // ����������A1 �籱�� 110000, ���������밴GB2260-91�Ĺ涨ִ��
    UINT32 ulTmlAddress;                // ����ն˵�ַA2ѡַ    ��ΧΪ 1~4294967295
    BOOL   bTeam;                       // Ϊtrue ��ʾulTmlAddress Ϊ���ַ, Ϊfalse ��ʾulTmlAddress��һ��ַ
    UINT8  ucConAddress;                // ��վ��ַ�����ַ��־A3, ��Χ(0~127)

}sTcA, sTcAddress;

// ��֡��ṹ
#pragma pack(1)
typedef struct
{
    UINT8  acRegionCode[TC_A1_LEN];     // ����������A1           (BCD)  ���ֽ���ǰ  ���ֽ��ں�
    UINT32 ulTmlAddress;                // ����ն˵�ַA2ѡַ   ��ΧΪ1~4294967295
    //UINT8  ucTeam:1;                  // Ϊ1��ʾ ulTmlAddress Ϊ���ַ,A2 == 0xFFFF���㲥��ַ, Ϊ 0 ��ʾ����ַ
    UINT8  ucConAddress;                // ��վ��ַ�����ַ��־A3 (BIN)  ��ò�Ҫ��λ��

}sTcA_f, sTcAddress_f; // ֡��ַ��ʽ����
#pragma pack()

// ת������
eTcErr etc_trans_address(eTcTrans eTrans, sTcAddress *psAddr_u, sTcAddress_f *psAddr_f);
///*}

/************************************************************
 *  ������C �ṹ��ת������
 *
 *  ��֡��Ϊ2�ֽ�
 *  +------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
 *  | D15  | D14  | D13  | D12  | D11  | D10  |  D9  |  D8  |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
 *  | DIR  | PRM  | ���� |            ����֡���PSEQ        |      ����֡���PSEQ       |          ֡������         |
 *  +------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+
 *
 *
 * DIR ���䷽��λ   DIR = 0 ��ʾ��֡����������(��)վ����Ϣ�����뽻���ն˷��������б���
 *                  DIR = 1 ��ʾ��֡����������Ϣ�����뽻���ն�����(��)վ���������б���
 *
 * PRM ������־λ   PRM = 0 ��ʾ��֡�������ԴӶ�����Ӧ��վ���Ӷ�վ����Ӧվ��������վ���䱨��
 *                  PRM = 1 ��ʾ��֡������������վ������վ��Ӷ�վ���䱨��
 *
 *  ����֡���PSEQ
 *      (1)����֡���PSEQ�ñ����ʾ0~31����������Ͷ�Ӧ����֡���Լ���ֹ��Ϣ����Ķ�ʧ���ظ���
 *      (2)ÿһ������վ�ʹӶ�վ֮�����1�������ļ����������ڼ�¼��ǰPSEQ������վ��ͬһ
 *         �Ӷ�վ�����µĴ������ʱ��PSEQ+1������ʱδ�յ��Ӷ�վ�ı��ģ�
 *         ����ճ��ֲ��������վ���ı�PSEQ���ظ�ԭ���Ĵ������
 *
 *  ��Ӧ֡���RSEQ
 *      (1)��Ӧ֡���RSEQ��PRM=0ʱ�����Ӷ�֡����Ч���ñ����ʾ0~15�����ڶ���Ӷ�֡��Ӧһ������֡�Ĵ���
 *      (2)ÿһ������վ�ʹӶ�վ֮�����1�������ļ����������ڼ�¼��ǰRSEQ����ֻ��һ֡�Ӷ�֡��Ӧ����֡�ģ�RSEQ=0��
 *         ������n��n��16��֡��Ӧ�ģ�RSEQ��n-1��ݼ�������ÿ����һ֡��1��ֱ�����һ֡RSEQ=0
 *         �Ӷ�վ�����µĴ������ʱ��PSEQ+1������ʱδ�յ��Ӷ�վ�ı�
 *
 *  ֡�����룬�̶�֡�Ϳɱ�֡��֡�����붨�岻ͬ
 *
{*///

typedef enum
{
    TC_PRM_UNKWON,                 // δ֪����
    TC_PRM_A2P,                    // ��֡����������վ
    TC_PRM_P2A,                    // ��֡�����ڴӶ�վ

}eTcPRM;                           // ��������PRM�ֶ�����

// ���ĳ����ĳ����õ�PRM����
eTcPRM etc_get_prm(eTcDir eDir, eTcAFN eAfn, BOOL bAuto);

typedef enum
{
    // �̶�֡
    // PRM 0
    TC_FCD_LINK_OK      = 0,       // ȷ��

    // PRM 1
    TC_FCD_LOG_IN       = 1,       // ������·����¼ϵͳ
    TC_FCD_LOG_OUT      = 2,       // �����·���˳�ϵͳ
    TC_FCD_HEART_BEAT   = 3,       // ������·����������


    // �ɱ�֡
    // PRM 0
    TC_FCD_OK           = 0,       // ��·�û�ȷ��
    TC_FCD_ANSWER       = 1,       // ���û�������Ӧ����

    // PRM 1
    TC_FCD_NOTI         = 0,       // ���� �M�޻ش�
    TC_FCD_CONF         = 1,       // ���� �Mȷ��
    TC_FCD_ASK          = 2,       // ���� �M��Ӧ

    TC_FCD_MAX,

}eTcFcode;       // ����������

#define TC_C_LEN       (2)         // ������C��֡���ֳ�

#define TC_PSEQ_MIN    (0)         // PSEQ ��Сֵ
#define TC_PSEQ_MAX    (31)        // PSEQ ���ֵ

#define TC_RSEQ_MIN    (0)         // PSEQ ��Сֵ
#define TC_RSEQ_MAX    (15)        // PSEQ ���ֵ

// �û���
typedef struct
{
    eTcDir     eDir;               // ������
    eTcPRM     ePRM;               // ��־�ñ�������������վ ���ǴӶ�վ
    UINT8      ucPSEQ;             // ����֡��� PSEQ
    UINT8      ucRSEQ;             // ��Ӧ֡��� RSEQ
    eTcFcode   eFcode;             // ֡������

}sTctrl;

// ֡��
// UINT16 usTcCtrl;
// ת������
eTcErr etc_trans_ctrl(eTcTrans eTrans, sTctrl* puCtrl, UINT16* pfCtrl);

// ��� eTcFcode ֡���Ӧ�Ĺ�����
eTcErr etc_get_fcode(eTcmd eCmd, eTcDir eDir, eTcPRM ePRM, eTcFcode * peFcode);


// ��װ����
eTcErr etc_get_ctrl(eTcAFN eAFN, eTcDir eDir, eTcPRM ePRM, sTctrl *psCtrl);
///*}
/************************************************************
 *  Ӧ�ÿ�����AC �ṹ��ת������
 *
 *  ��֡��Ϊ1�ֽ�
 *  +------+------+------+------+------+------+------+------+
 *  |  D7  |  D6  |  D5  |  D4  |  D3  |  D2  |  D1  |  D0  |
 *  +------+------+------+------+------+------+------+------+
 *  |  Tpv |  ACD |  --  |          Ӧ�ù����� AFN          |
 *  +------+------+------+------+------+------+------+------+
 *
 *
 * Tpv ʱ���ǩ��Чλ Tpv
 *     TpV=0����ʾ�ڸ�����Ϣ����[��]ʱ���ǩ Tp
 *     TpV=1����ʾ�ڸ�����Ϣ����[��]ʱ���ǩ Tp
 *
 * ACD ��ʾ����λ
 *     ACD=1����ʾ����Ҫ�¼����ݵȴ����ʣ��Ҹ�����Ϣ������ EC
 *     ACD=0����ʾ����Ҫ�¼����ݵȴ�����
 *
 * AFN Ӧ�ù�����
 *     0   ȷ�ϨM����
 *     1   ��λ
 *     4   ���ò���
 *     5   ��������
 *     6   �����֤����ԿЭ��
 *     10  ��ѯ����
 *     12  ���󣨶�ʱ�ϱ�����������
 *     13  ����ʵʱ����
 *     14  ���������ϱ����¼���¼
 *     15  �ļ�����
 *     16  ����ת��
 *
{*///
// �û���ṹ
typedef struct
{
    BOOL    bTp;    // �Ƿ���Tp
    BOOL    bEc;    // �Ƿ���Ec
    eTcAFN  eAfn;   // Ӧ�ù�����

}sTcAc;             // Ӧ�ÿ�����AC

// ��װ��ṹ
// ucAc;

// ת������
eTcErr etc_trans_ac(eTcTrans eTrans, sTcAc* puAc, UINT8* pfAc);
///*}

/************************************************************
 *  ���ݱ�ʶ��Ԫ
 *  ÿ�����ݱ�ʶ��Ԫ����Ϣ�������ʽ��֯��
 *  ÿ�����ݱ�ʶ��Ԫ�������(8)��Fn ��������(8)��Pn
 *
 * -----
 * DADT ֡��ṹ
 * ��Ϣ�� | DA | DA1 | D7 D6 D5 D4 D3 D2 D1 D0
 *        |    | DA2 | D7 D6 D5 D4 D3 D2 D1 D0
 * ��Ϣ�� | DT | DT1 | D7 D6 D5 D4 D3 D2 D1 D0
 *        |    | DT2 | D7 D6 D5 D4 D3 D2 D1 D0
 *
 * ---
 * ��Ϣ��DA����Ϣ��ԪDA1����Ϣ����DA2�����ֽڹ���
 * DA1 ��λ��ʾĳһ��Ϣ�����1��8����Ϣ��
 * DA2 ���ö����Ʊ��뷽ʽ��ʾ��Ϣ����
 * DA1��DA2��ͬ������Ϣ���ʶpn��n = 1��2040��
 * ��Ϣ���ʶpn��Ӧ�ڲ�ͬ��Ϣ���ʶFn���������¸��ֺ���
 * ������š��ܼ���š������ִΡ�ֱ��ģ�����˿ںš������
 *
 * ��Ϣ����DA2 | ��Ϣ��ԪDA1
 *       D7~D0 | D7    D6    D5    D4    D3    D2    D1    D0
 *           1 | p8    p7    p6    P5    p4    p3    p2    p1
 *           2 | p16   p15   p14   p13   p12   p11   p10   p9
 *           3 | p24   p23   p22   p21   p20   p19   p18   p17
 *          .. | ...   ...   ...   ...   ...   ...   ...   ...
 *          255| P2040 P2039 P2038 P2037 P2036 P2035 P2034 P2033
 *
 * ---
 * ��Ϣ��DT����Ϣ��ԪDT1����Ϣ����DT2�����ֽڹ���
 * DT1 ��λ��ʾĳһ��Ϣ�����1��8����Ϣ����
 * DT2 ���ö����Ʊ��뷽ʽ��ʾ��Ϣ����
 * DT1 DT2 ��ͬ������Ϣ���ʶFn��n = 1��248��
 *
 * ��Ϣ����DT2 | ��Ϣ��ԪD T1
 *       D7~D0 | D7   D6   D5   D4   D3   D2   D1   D0
 *           0 | F8   F7   F6   F5   F4   F3   F2   F1
 *           1 | F16  F15  F14  F13  F12  F11  F10  F9
 *           2 | F24  F23  F22  F21  F20  F19  F18  F17
 *          .. | ...  ...  ...  ...  ...  ...  ...  ...
 *          30 | F248 F247 F246 F245 F244 F243 F242 F241
 *
{*///

// �û���ṹ
typedef struct
{

    UINT16  usPn[TC_PN_INDEX_MAX];      // Pn (0 ~ 2040)
                                        // TC_PN_MAX  ���ֵ
                                        // TC_PN_MIN  ��Сֵ
                                        // TC_PN_NONE ��Чֵ

    UINT8   ucFn[TC_FN_INDEX_MAX];      // Fn (1 ~ 248)
                                        // TC_FN_MAX  ���ֵ
                                        // TC_FN_MIN  ��Сֵ
                                        // TC_FN_NONE ��Чֵ
}sTcPnFn;

// ֡��ṹ
typedef struct
{
    UINT8       ucDA1;         // ��Ϣ��Ԫ
    UINT8       ucDA2;         // ��Ϣ����
    UINT8       ucDT1;         // ��Ϣ��Ԫ
    UINT8       ucDT2;         // ��Ϣ����
}sTcDaDt;

// ת������
eTcErr etc_pnfn_to_dadt(sTcPnFn* psPnFn, sTcDaDt* psDaDt);
eTcErr etc_dadt_to_pnfn(sTcDaDt* psDaDt, sTcPnFn* psPnFn);

typedef struct
{
    eTcmd  eCmd;
    UINT16 usPn;
}sTcmdPn;

// �ڲ�����
// ��������Ӧ��AFN
eTcAFN eTcGetCmdAfn(eTcmd eCmd);

// ��������Ӧ��Fn
UINT8  ucTcGetCmdFn(eTcmd eCmd);

// �ж���8��Pn�Ƿ���ͬһ����Ϣ����,ͬʱȡ����������Ϣ����
BOOL btc_same_team_pn(UINT16 *pUsPn8, UINT8* pucDa2);

// �ж�һ��Pn�Ƿ�Ϊ0
BOOL btc_is_p0(UINT16 *pUsPn8);

// ���pn��Ӧ����Ϣ����
UINT8 uctc_get_pn_team(UINT16 usPn);

// ���һ��pn��Ӧ����Ϣ����
UINT8 uctc_get_pn8_team(UINT16 *pusPn);

// �ж�ĳһ��pn�Ƿ���һ��8��pn��
BOOL btc_in_pn8(UINT16 usPn, UINT16 *pusPn8);

// �ж���8��Fn�Ƿ���ͬһ����Ϣ����,ͬʱȡ����������Ϣ����
BOOL btc_same_team_fn(UINT8  *pUcFn8, UINT8* pucDt2);

// ���Fn��Ӧ����Ϣ����
UINT8 uctc_get_fn_team(UINT8 ucFn);

// ���Fn��Ӧ����Ϣ����ĳ���bit
UINT8 uctc_get_fn_bit(UINT8 ucFn);

// ���һ��Fn��Ӧ����Ϣ����
UINT8 uctc_get_fn8_team(UINT8 *pucFn);

// �ж�ĳһ��fn�Ƿ���һ��8��fn��
BOOL btc_in_fn8(UINT8 ucFn, UINT8 *pucFn8);

// ת������
eTcErr etc_add_cmdpn(sTcmdPn* psCmdPn,sTcmdPn sNewCmdPn, UINT8 *pucNumCmdPn);
eTcErr etc_pnfn_to_cmdpn(eTcAFN eAfn, sTcPnFn* psPnFn, UINT8 ucNumPnFn,   sTcmdPn* psCmdPn, UINT8 *pucNumCmdPn);
eTcErr etc_cmdpn_to_pnfn(eTcAFN eAfn, sTcPnFn* psPnFn, UINT8 *pucNumPnFn, sTcmdPn* psCmdPn, UINT8  ucNumCmdPn);
eTcErr etc_dadt_to_cmdpn(eTcAFN eAfn, sTcDaDt* psDaDt, UINT8 ucNumDaDt,   sTcmdPn* psCmdPn, UINT8 *pucNumCmdPn);
eTcErr etc_cmdpn_to_dadt(eTcAFN eAfn, sTcDaDt* psDaDt, UINT8 *pucNumDaDt, sTcmdPn* psCmdPn, UINT8  ucNumCmdPn);
///*}

/************************************************************
 *  Tp ʱ���ǩ��ʽ
 *
{*///
// �û���
typedef struct
{
    sTcFmt03 sTime;                 // ����֡����ʱ��
    UINT8    ucPermitDelayMinutes;  // �����ʹ�����ʱʱ��(����);
}sTcTp;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt03_f sTime;                 // ����֡����ʱ��
    UINT8      ucPermitDelayMinutes;  // �����ʹ�����ʱʱ��(����);
}sTcTp_f;
#pragma pack()

// ת������
eTcErr etc_trans_tp(eTcTrans eTrans, sTcTp* pUser, sTcTp_f* pFrame);

// ��õ�ǰ�û���Tp
eTcErr etc_get_tp(sTcTp *psuTp);   

// �Ե�ǰʱ��Ϊ��׼�ж�һ��tp�Ƿ�ʱ
BOOL  btc_tp_timeout(sTcTp *psTP);
///*}

/*******************************************
 *  ���������
 *  Э������Ӧ����ÿ��ʵ�ʵ�������Ϊ��,��֡����Ҫ�����������������0xEE
{*///
BOOL   btc_is_0xEE(UINT8* pData, UINT16 usLen);    // �ж�֡��ĳ�������Ƿ�����Ч��
void   vtc_set_0xEE(UINT8* pData, UINT16 usLen);   // ��֡��ĳ����������Ϊ��Ч

BOOL   btc_is_none(UINT8* pData, UINT16 usLen);    // ������ȱ��
void   vtc_set_none(UINT8* pData, UINT16 usLen);   // ������������Ϊȱ��
///*}

/************************************************************
 *  ������Ϣ�� AUX ����
 *
{*///

BOOL   btc_have_pw(eTcAFN eAFN, eTcDir eDir);      // ���౨�����Ƿ�Ӧ����pw�ֶ�
BOOL   btc_have_ec(eTcAFN eAFN, eTcDir eDir);      // ���౨�����Ƿ�Ӧ����EC�ֶ�
BOOL   btc_have_tp(eTcAFN eAFN, eTcDir eDir);      // ���౨�����Ƿ�Ӧ����tp�ֶ�

// �û���
typedef struct
{
    UINT16 usEC1;              // ��Ҫ�¼������� EC1
    UINT16 usEC2;              // һ���¼������� EC2

}sTcEc, sTcEc_f;

// �¼��������ú���
void vtc_set_ec(sTcEc *psEc);

// ��ñ����и������֡������ֽ�����
UINT16 ustc_get_aux_len(eTcAFN eAFN, eTcDir eDir, BOOL bEc, BOOL bTp); 

///*}

/*******************************************************
 *  ��������ܺ���
 *  �ؼ����ݵļ���
 *  �����㷨:����Ӧ�ò���Ҫ���ܵĹؼ�����,���öԳ��㷨�������ݼӽ���
 *  ���ܲ���:Ӧ�ò㹦���롢���ݵ�Ԫ��ʶ�����ݵ�Ԫ����
 *  ���ܳ���:ͨ����������öԳ���Կ�㷨���������ݼ��ܳ�����,�û����ݳ��Ȼ���Ӧ�ı�
 *           �ն����յ����öԳ���Կ�㷨���ܵ�������Ϣ��,�����ݽ��н���
 *           ���ܳɹ�����ԭʼ��������Ϣ��������Ϣ�����ݳ���
 *  ��������:��Ҫ���ܵı�������
 *           (1)��λ��������б���
 *           (2)���ò�����������б���
 *           (3)������������б���
 *
 *  �ҵ�����: AFN�Ƿ�Ӧ�ü���   ���ĳ���ܽ��޷������ĸ����ͼ���
 *
{*///
#if TC_CFG_ENCRYPT

// ���ܺ�������
typedef eTcErr (*peTcEncryptFunc)(UINT8* pInData, int nInLen, UINT8* pOutData, int *pOutLen);  

// ���ܺ�������
typedef eTcErr (*peTcDecryptFunc)(UINT8* pInData, int nInLen, UINT8* pOutData, int *pOutLen);  

#endif
///*} 

/*******************************************************
 *  ���������
 *  
 *  �û���:Ĭ���ֽڶ���, ���ϲ����ʱʹ��
 *  ��֡��:1�ֽڶ���,���ڷ�װ֡�ͽ���֡
 *  ��������:ʵ�ֶԸ�Fn�û���ͷ�֡�����ݽṹ��ת������  
 *  
 *
{*///

/*******************************************
 * ��������: ȫ��ȷ��/���ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ����ȷ��/����
 * ��ӦAFN : TC_AFN_00_CONF
 * ��ӦCMD : TCMD_AFN_0_F1_ALL_OK_DENY
 * PN ���� : P0
{*///

// �û��ṹ
typedef enum
{
    TC_RES_OK          = 0,    // ȷ��
    TC_RES_NONE        = 1,    // ����������ݡ������õĲ�������Ҫִ�еĹ���
    TC_RES_NOT_READY   = 2,    // ���������δ����������ִ��δ����
    TC_RES_REMOVE      = 3,    // ����������Ѿ����Ƴ����洰��
    TC_RES_DATA_OTRNG  = 4,    // ��������ݳ���֧�ֵ���Ϣ�㷶Χ
    TC_RES_PARA_OTRNG  = 5,    // ���õĲ�������֧�ֵ���Ϣ�㷶Χ
    TC_RES_NOT_SAME    = 6,    // ���õĽ���˿ںż�������ʵ�ʲ���
    TC_RES_NOT_SUPT    = 7,    // ָ���ӿڲ�֧��ת��
    TC_RES_DENY        = 255   // ����
    
}eTcResCode, sTcAfn00F1;                   // ȷ��/������Ϣ�붨�� 

// eTcResCode    eResCode;

// ��֡�ṹ
//UINT8  ucResCode;

// ת������
eTcErr etc_trans_afn00f1(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ���ȷ�������
 * ��ӦAFN : TC_AFN_00_CONF
 * ��ӦCMD : TCMD_AFN_0_F2_ONE_BY_ONE
 * PN ���� : P0
{*///
// �û�������
typedef struct
{
    eTcmd       eCmd;         // ȷ�϶�Ӧ�Ĺ�����
    UINT16      usPn;         // Pn  0 ~ 2040
    eTcResCode  eResCode;     // ����
}sTcmdErr;                    // ȷ������� �û������ݽṹ

typedef struct
{
    eTcAFN        eAFN;       // ��Ҫȷ�ϵ�AFN
    UINT8        ucNum;       // ��Ҫȷ�� �� ���ϵ� Fn����
    sTcmdErr   sOne[1];       // ucNum ��sMtUFnPnErr  
}sTcOnebyOne;                 // ȷ������� (�û������ݽṹ)

// ֡������
#pragma pack(1) 
typedef struct
{
    sTcPnFn     sPnFn;
    eTcResCode  eResCode;
}sTcFnPnErr;                   // ȷ������� �û������ݽṹ

typedef struct
{
    sTcDaDt     sDaDt;         // ���ݵ�Ԫ��ʶ
    UINT8       ucErr;         // ���� ��ʶ   (0 ��ȷ 1 ����)
}sTcOne_f;                     // ȷ�������  ֡�����ݽṹ   

typedef struct
{
    UINT8       ucAFN;
    sTcOne_f    sOne[1];
}sTcOneByOne_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn00f2(eTcTrans eTrans,void* psUser, void* psFrame, UINT16* pusfLen);
///*} 

/*******************************************
 * ��������: ָ����������(��ʵʱ���ݵ�Ԫ��ʶ��Ч)
 * ��ӦAFN : TC_AFN_01_RSET
 * ��ӦCMD : TCMD_AFN_1_F5_DATA_CLEAR
 * PN ���� : P0
{*///

// �û���
typedef struct
{
    UINT8   ucNum;      // ��������������
    sTcmdPn sCmdPn[1];  // ucNum ��������pn�����

}sTcDataClear, sTcAfn01f5, sTcRtDataClear;

// ��װ��
#pragma pack(1)
typedef struct
{
    UINT8    ucNum;    // ���ݵ�Ԫ��ʶ����
    sTcDaDt  sDaDt[1]; // ncNum�����ݵ�Ԫ��ʶ

}sTcDataClear_f, sTcAfn01f5_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn01f5(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: IP��ַ���ݽṹ
{*///
typedef enum
{
    TC_IP_UNKOWN,
    TC_IP_V4,
    TC_IP_V6,
}eTcIp;

// IP��ַ ��������
typedef struct
{
    eTcIp eVersion;
    UINT8 ip[TC_IP_LEN];
}sTcIp, sTcMask;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8  ucVersion;
    UINT8 ip[TC_IP_LEN];

}sTcIp_f, sTcMask_f;
#pragma pack()

// ת������
eTcErr etc_trans_ip(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �����뽻���ն�IP��ַ�Ͷ˿�
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F1_CON_IP_PORT
 *           TCMD_AFN_A_F1_CON_IP_PORT
 * PN ���� : P0
{*///
// �û���
#define TC_APN_LEN  (16)
typedef struct
{
    sTcIp       sMainIp;             // ����IP��ַ
    UINT16      usMainPort;          // ���ö˿ڵ�ַ
    sTcIp       sBackIp;             // ����IP��ַ
    UINT16      usBackPort;          // ���ö˿ڵ�ַ
    UINT8       ucAPN[TC_APN_LEN];   // APN
    UINT8       ucUsr[32];           // �û���
    UINT8       ucPwd[32];           // ����
    
}sTcDownCfg, sTcAfn04f1;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcIp_f     sMainIp;             // ����IP��ַ
    UINT16      usMainPort;          // ���ö˿ڵ�ַ
    sTcIp_f     sBackIp;             // ����IP��ַ
    UINT16      usBackPort;          // ���ö˿ڵ�ַ
    UINT8       ucAPN[TC_APN_LEN];   // APN
    UINT8       ucUsr[32];           // �û���
    UINT8       ucPwd[32];           // ����
}sTcDownCfg_f, sTcAfn04f1_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f1(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ����ն�����ͨ�Ų�������
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F2_TML_UP_CFG
 *           TCMD_AFN_A_F2_TML_UP_CFG
 * PN ���� : P0
{*///

#define TC_TML_UP_PROTO   (1) // �ն�����ͨ��Э������
// �û���
typedef enum
{
   TC_TUPP_UNKOWN,           // δ֪����
   TC_TUPP_DEL,              // ɾ���ü���ն˺ŵ����ò���
   TC_TUPP_SER,              // ����
   TC_TUPP_ETH,              // ��̫��
}eTcUpPara;                  // ����ն�����ͨ�Ŷ˿�����

typedef enum
{
    TC_DELG_UNKOWN,  // δ֪���� 
    TC_DELG_NULL,    // ��ʹ�ô���
    TC_DELG_HTTP,    // ʹ��http connect����
    TC_DELG_SOCK4,   // ʹ��sock4����
    TC_DELG_SOCK5,   // ʹ��sock5����
   
}eTcDelegate;

// ������������ӷ�ʽ
typedef enum
{
    TC_DELK_UNKOWN, // δ֪��ʽ
    TC_DELK_ANYONE, // ����Ҫ��֤
    TC_DELK_USRPWD, // ��Ҫ�û���������
}eTcDelgLink;

typedef struct
{
    UINT16    usListenPort;     // �����˿ں� 
    sTcIp            sUpIp;     // IP��ַ
    sTcMask        sUpMask;     // ����ն����������ַ
    sTcIp          sGateIp;     // ���ص�ַ
    eTcDelegate  eDelegate;     // ��������
    sTcIp          sDelgIp;     // ��������ַIP��ַ
    UINT16      usDelgPort;     // �������˿�
    eTcDelgLink  eDelgLink;     // ������������ӷ�ʽ
    BOOL          bDlegUsr;     // �Ƿ���Ҫ����������û���
    UINT8     ucDlegUsrLen;     // ����������û������� (1~20)
    UINT8    ucDlegUsr[20];     // ����������û���   
    BOOL          bDlegPwd;     // �Ƿ���Ҫ
    UINT8     ucDlegPwdLen;     // ������������볤��   (1~20)
    UINT8    ucDlegPwd[20];     // �������������
    UINT8   ucPermitDelayM;     // ����ն���Ϊ����վ��������ʱʱ�� (��λ:���� 0~255)
    UINT8    ucReSendTimes;     // �ط����� (0~3)   0 ��ʾ�������ط�
    UINT8      ucHeartBeat;     // ��������
    UINT16  usWaitTimeoutS;     // ����ն���Ϊ����վ�ȴ�Ӧ��ĳ�ʱʱ�� (���� 0~4095)
    BOOL         bPermitTk;     // �������� �Ƿ��������ն���Ҫ������ȷ��
    BOOL         bPermitEv;     // �¼����� �Ƿ��������ն���Ҫ������ȷ��

}sTcTmlUpCfg, sTcAfn04f2;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT16    usListenPort;     // ����ն������Ŷ˿ں� 
    sTcIp_f          sUpIp;     // ����ն�����IP��ַ
    sTcMask_f      sUpMask;     // ����ն����������ַ
    sTcIp_f        sGateIp;     // ���ص�ַ
    UINT8       ucDelegate;     // ��������
    sTcIp_f        sDelgIp;     // ��������ַIP��ַ
    UINT16      usDelgPort;     // �������˿�
    UINT8       ucDelgLink;     // ������������ӷ�ʽ
    UINT8         ucUsrLen;     // ����������û�������m (0~20) 0��ʾ����Ҫ�û�����֤
    /* ����Ϊ�䳤
    UINT8     ucDlegUsr[m];     // ����������û���
    UINT8     ucDlegPwdLen;     // ������������볤�� n  (0~20) 0��ʾ����Ҫ������֤
    UINT8     ucDlegPwd[n];     // �������������

    // �ͽṹ sTcUpCfg_f ��ͬ
    UINT8  ucPermitDelayM;      // ��Ϣ�����뽻���ն���Ϊ����վ��������ʱʱ�� 
    UINT8  ucSWTS1;             // ��Ϣ�����뽻���ն���Ϊ����վ�ȴ�Ӧ��ĳ�ʱʱ����ط�����
    UINT8  ucSWTS2;             // �ն˵ȴ��Ӷ�վ��Ӧ�ĳ�ʱʱ����ط����� wait ts
    UINT8  bs8Con;              // ��Ϣ�����뽻���ն���Ϊ����վ��ȷ��Ӧ��Ĵ�������־ 
    UINT8  ucHeartBeat;         // ��������                     
    */ 
}sTcTmlUpCfg_f, sTcAfn04f2_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f2(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��Ϣ�����뽻���ն�����ͨ����Ϣ��֤����
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F3_TML_AUTH_PARA
 *           TCMD_AFN_A_F3_TML_AUTH_PARA
 * PN ���� : P0
{*///
// �û���
typedef struct
{
    UINT8     ucTypeID;   // ���ڱ�ʾ��ϵͳԼ���ĸ�����Ϣ��֤������ȡֵ��Χ0��255
                          // ���У�0��ʾ����֤��255��ʾר��Ӳ����֤������
                          // 1��254���ڱ�ʾ���������֤����
    UINT16    usAuthPara; // ��Ϣ��֤��������
}sTcAuthPara, sTcAfn04f3;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8     ucTypeID; 
    UINT16    usAuthPara; 
}sTcAuthPara_f, sTcAfn04f3_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f3(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �豸״̬���������
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F4_TML_STATE_INPUT
             TCMD_AFN_A_F4_TML_STATE_INPUT
 * PN ���� : P0
{*///
// �û���
typedef struct
{
    BOOL bIn[8];       // ״̬�������־λ����Ӧ 1��8 ·״̬������true����.      �� false δ����
    BOOL bOn[8];       // ״̬�����Ա�־λ����Ӧ 1��8 ·״̬���� ��true�������㡣�� false ���մ���

}sTcStateInput, sTcAfn04f4;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8 bIn;
    UINT8 bOn;

}sTcStateInput_f, sTcAfn04f4_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f4(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �¼���¼����
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F5_TML_EVENT_CFG
             TCMD_AFN_A_F5_TML_EVENT_CFG
 * PN ���� : P0
{*///

// �û���
typedef struct
{   
    UINT8      ucNeed;   // ��Ҫ��¼���¼���¼�����͸���   
    eTcErc  aNeed[64];   // ucErcNeed����Ҫ��¼���¼���¼��������
    UINT8      ucImpt;   // ����Ϊ��Ҫ�¼��ĸ���
    eTcErc  aImpt[64];   // ucErcImpt���¼�����Ϊ��Ҫ���¼�(��ô����ľ���һ���¼�)
                         // �¼���Ҫ�Եȼ���־λ��D0��D63 ��˳���λ��ʾ�¼����� ERC1��ERC64 ��������¼���
                         //     �á�1������λ����Ӧ�ĸ澯�¼�Ϊ��Ҫ�¼������¼���������ͨ���߱������ϱ�������
                         // Ӧ�����ϱ��¼���¼���粻�߱������ϱ�������ͨ�� ACD λ�ϱ���
                         //     �á�0������λ����Ӧ�ĸ澯�¼�Ϊһ���¼������¼�������ֻ��Ҫ�����¼���¼��

}sTcEventCfg, sTcAfn04f5;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8     aNeed[8];  // �¼���¼��Ч��־λ
    UINT8     aImpt[8];  // �¼���Ҫ�Եȼ���־λ
    
}sTcEventCfg_f, sTcAfn04f5_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f5(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ���������������
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F17_FREZ_TASK_PARA
 * PN ���� : �����������
{*///
// �û���
typedef enum
{
    TC_PUNT_UNKOWN,  // δ֪�����ڵ�λ
    TC_PUNT_MONTH,   // ��
    TC_PUNT_DAY,     // ��
    TC_PUNT_HOUR,    // ʱ
    TC_PUNT_MIN,     // ����
    TC_PUNT_SEC,     // ��
    TC_PUNT_MS,      // ����
}eTcPeriodUnit;      // �������ڵ�λ

typedef struct
{
    UINT16         usPeriod;         // �������� Ϊ��ʱ�����ʱ������Ϊ0��ʾɾ�����������
    eTcPeriodUnit     eUnit;         // �������ڵ�λ
    UINT8           ucTimes;         // ��������������ʾ�Զ�������Ϊ������足��Ĵ�����Ϊ0��ʾ���޴����� 
}sTcFrezPeriod;

typedef struct
{
    sTcYWMDhms      sTimeFrez;         // �����׼ʱ�䣺���ʱ������ 
    sTcYWMDhms      sTimeRprt;         // �ϱ���׼ʱ�䣺���ʱ������
    sTcFrezPeriod      sFreez;         // ��������
    UINT8         ucPeriodRpt;         // ��ʱ�ϱ�����    ��Ϊ��ʱ�ϱ����ݵ�ʱ������0Ϊ����������������趨ʱ�ϱ���
    eTcPeriodUnit    eUnitRpt;         // ��ʱ�ϱ����ڵ�λ����ֵ��Χ1~4�����ηֱ��ʾ�֡�ʱ���ա��£���������
    UINT8           uCmdPnNum;         // ��Ҫ��������ݵ�Ԫ��ʶ ����
    sTcmdPn         sCmdPn[1];         // ��Ҫ��������ݵ�Ԫ��ʶ ����
    
}sTcFrezTaskPara, sTcAfn04f49;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT16         usPeriod;         // �������� Ϊ��ʱ�����ʱ������Ϊ0��ʾɾ�����������
    UINT8             eUnit;         // �������ڵ�λ
    UINT8           ucTimes;         // ��������������ʾ�Զ�������Ϊ������足��Ĵ�����Ϊ0��ʾ���޴����� 
}sTcFrezPeriod_f;

typedef struct
{
    sTcFmt01_f        sTimeFrez;     // �����׼ʱ�䣺���ʱ������ 
    sTcFrezPeriod_f      sFreez;     // �������� 
    UINT8             ucDaDtNum;     // ���ݵ�Ԫ��ʶ����

    // ����Ϊ�䳤
    /*
    sTcDaDt        sDaDt[1];         // ucDaDtNum �����ݵ�Ԫ��ʶ
    sTcFmt01_f        sTimeRprt;     // �����׼ʱ�䣺���ʱ������ 
    UINT8             eUnit;         // ��ʱ�ϱ�����
    UINT8           ucTimes;         // ��ʱ�ϱ����ڵ�λ 
    */
}sTcFrezTaskPara_f, sTcAfn04f49_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �������������ò���
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F25_ELEC_MP_CFG
 * PN ���� : �����������
{*///
// �û���
typedef enum
{
    TC_BAUD_UNKOWN,
    TC_BAUD_DEFAULT,        // �������û�ʹ��Ĭ��
    TC_BAUD_1200,            
    TC_BAUD_2400,
    TC_BAUD_4800,
    TC_BAUD_9600,
    TC_BAUD_19200,
    TC_BAUD_38400,         
    TC_BAUD_76800,   
}eTcSerBaud;                // ���ڲ�����

typedef enum
{
    TC_SBIT_5,
    TC_SBIT_6,
    TC_SBIT_7,
    TC_SBIT_8,

}eTcSerBit;

typedef struct
{
    eTcSerBaud      eBaud;  // ������
    BOOL           bStop1;  // 1ֹͣλ(true) 2ֹͣλ(false)
    BOOL           bCheck;  // ��У��(true) ��У��(false) 
    BOOL             bOdd;  // ��У��(true) żУ��(true)
    eTcSerBit        eBit;  // 5~8λ��
}sTcAcsParaSer;             // ����˿����в������ݸ�ʽ-����

// �ṹsTcAcsParaSer ת������
eTcErr etc_trans_serial(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);

typedef enum
{
   TC_ACS_PROT_UNKOWN,      // δ֪ͨ��Э������
   TC_ACS_PROT_DLT645_97,   // 1 DL/T645-1997 
   TC_ACS_PROT_DLT645_07,   // 2 DL/T645-2007
   TC_ACS_PROT_MODBUS,      // 3 Modbus
   TC_ACS_PROT_USER = 128,  // (128~255)��ʾ�Զ���
}eTcAcsProto;               // �����豸ͨ������

typedef enum
{
    TC_ACS_PORT_UNKOWN,     // δ֪�ӿ�����
    TC_ACS_PORT_DC,         // ֱ��ģ����
    TC_ACS_PORT_AC,         // ����ģ����
    TC_ACS_PORT_SER,        // ����(RS485/RS232)
    TC_ACS_PORT_ETH,        // ��̫��
    TC_ACS_PORT_ZIGB,       // zigbee
    TC_ACS_PORT_USER = 128, // 128~255 �û��Զ��� 
    
}eTcAcsPort;                // ����˿�����

typedef struct
{
    UINT16          usPort; // �����豸�����˿ں�
    sTcMask          sMask; // ���������ַ
    sTcIp            sGate; // ���ص�ַ
}sTcAcsParaEth;             // ����˿����в������ݸ�ʽ-��̫��

typedef struct
{

    UINT8            ucPort;     // �����ʾ0~255��Ϊ0��ʾɾ���õ�������������ò���
    UINT8        ucAddr[16];     // �����豸ͨ�ŵ�ַ
    eTcAcsProto   eAcsProto;     // �����豸ͨ��Э������
    UINT8          ucPwd[6];     // ͨ������
    
    eTcAcsPort     eAcsPort;     // �����ն����� ���� uPortPara������
    union
    {
                                 // eAcsPort == TC_ACS_PORT_DC   ֱ��ģ�����޲�������
                                 // eAcsPort == TC_ACS_PORT_AC   ����ģ�����޲�������
        sTcAcsParaSer  sSer;     // eAcsPort == TC_ACS_PORT_SER  �������в���
        sTcAcsParaEth  sEth;     // eAcsPort == TC_ACS_PORT_ETH  ��̫�����в���
        UINT32   ulAddrZigb;     // eAcsPort == TC_ACS_PORT_ZIGB Zigbee��ַ 
        
    }uPortPara;                  // ����˿����в�������

}sTcElecMpCfg, sTcAfn04f25;

// ��֡��
#pragma pack(1)

typedef struct
{
    UINT16            usPort;    // �����豸�����˿ں�
    sTcMask_f          sMask;    // ���������ַ
    sTcIp_f            sGate;    // ���ص�ַ
}sTcAcsParaEth_f;                // ����˿����в������ݸ�ʽ-��̫��

typedef struct
{

    UINT8            ucPort;     // �����ʾ0~255��Ϊ0��ʾɾ���õ�������������ò���
    UINT8      ucAddrBcd[8];     // �����豸ͨ�ŵ�ַ(BCD)
    UINT8         eAcsProto;     // �����豸ͨ��Э������
    UINT8          ucPwd[6];     // ͨ������
    UINT8          eAcsPort;     // �����ն�����
    UINT8      ucAcsParaLen;     // ��Ӧ�����в����Ľṹ����

    /* �䳤�����в����ṹ
                                 // TC_ACS_PORT_DC ֱ��ģ�����޲�������
                                 // TC_ACS_PORT_AC ����ģ�����޲�������
    UINT8            sSer;       // TC_ACS_PORT_SER  �������в���
    sTcAcsParaEth_f  sEth;       // TC_ACS_PORT_ETH  ��̫�����в���
    UINT32   ulAddrZigb;         // TC_ACS_PORT_ZIGB Zigbee��ַ 

    */

}sTcElecMpCfg_f, sTcAfn04f25_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f25(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �����������������
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F26_ELEC_MP_BASE
 * PN ���� : �����������
{*///

#define TC_DNUM_INTGR_MIN   (4)  // ����λ����Сֵ
#define TC_DNUM_INTGR_MAX   (7)  // ����λ�����ֵ

#define TC_DNUM_DECIM_MIN   (1)  // С��λ����Сֵ
#define TC_DNUM_DECIM_MAX   (4)  // С��λ�����ֵ

typedef struct
{
    UINT8       ucInteger; // �й�����ʾֵ������λ����(4~7)
    UINT8       ucDecimal; // �й�����ʾֵ��С��λ����(1~4)
}sTcDigitNum;    

typedef enum
{   
    TC_LINK_UNKOWN, // δ֪
    TC_LINK_P3_L3,  // ��������
    TC_LINK_P3_L4,  // ��������
    TC_LINK_P1,     // �����
    
}eTcLink;

typedef enum
{
    TC_PHASE_UNKOWN, // δ֪
    TC_PHASE_A,      // A ��
    TC_PHASE_B,      // B ��
    TC_PHASE_C,      // C ��
    
}eTcPhase;

typedef struct
{
    eTcLink    eLink;
    eTcPhase   ePhase;
    
}sTcLinkWay; // ��Դ���߷�ʽ

// �û���
typedef struct
{
    sTcDigitNum      sDigit; // �й�����ʾֵ����λ��С��λ����
    UINT16         usTimesU; // ��ѹ����������
    UINT16         usTimesI; // ��������������
    float                fU; // ���ѹ   (+)XXX.X  (V)
    float                fI; // �����(+/-)XXX.XXX (A)
    sTcLinkWay     sLinkWay; // ��Դ���߷�ʽ
}sTcElecMpBase, sTcAfn04f26;

// ��֡��
#pragma pack(1)
typedef struct
{   
    UINT8            sDigit; // �й�����ʾֵ����λ��С��λ����
    UINT16         usTimesU; // ��ѹ����������
    UINT16         usTimesI; // ��������������
    sTcFmt_XXX_X         fU; // ���ѹ   (+)XXX.X   (V)
    sTcFmt_sXXX_XXX      fI; // ����� (+/-)XXX.XXX (A)
    UINT8          sLinkWay; // ��Դ���߷�ʽ
    
}sTcElecMpBase_f, sTcAfn04f26_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f26(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �����������������ֵ����
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F27_ELEC_LMIT_PARA
 * PN ���� : �����������
{*///
typedef struct
{
    float          fUpUp;        // ��ѹ������(��ѹ����) (+)XXX.X
    UINT8         ucTime;        // ����ʱ��
    float        fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX 
}sTcOverV;                       // ��ѹ�б����

typedef struct
{
    float      fDownDown;        // ��ѹ������(��ѹ����) (+)XXX.X
    UINT8         ucTime;        // ����ʱ��
    float        fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcLossV;                       // Ƿѹ�б���� 

typedef struct
{
    float          fUpUp;        // ����������() (+/-)XXX.XXX
    UINT8         ucTime;        // ����ʱ��
    float        fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcOverI;                       // �����б����

typedef struct
{
    float            fUp;        // ������(���������) (+/-)XXX.XXX
    UINT8         ucTime;        // ����ʱ��
    float        fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcSuperI;                      // ��������б����

typedef struct
{
    float            fUp;        // 0��������� (+/-)XXX.XXX
    UINT8         ucTime;        // ����ʱ��
    float        fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcZeroI;                       // ������������б����

typedef struct
{
    float         fLimit;        // �����ѹ��ƽ�����ֵ (+/-)XX.XXXX
    UINT8         ucTime;        // ����ʱ��
    float        fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcUnblnV;                      // �����ѹ��ƽ�ⳬ���б����

typedef struct
{
    float         fLimit;        // ���������ƽ�����ֵ (+/-)XX.XXXX
    UINT8         ucTime;        // ����ʱ��
    float        fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcUnblnI;                      // ���������ƽ�ⳬ���б����

// �û���
typedef struct
{
    float             fDropV;    // ��ѹ�����б����  (+)XXX.X
    UINT8        ucTimeLossV;    // ��ѹʧѹʱ���б���� minutes
    sTcOverV          sOverV;    // ��ѹ�б����
    sTcLossV          sLossV;    // Ƿѹ�б����
    sTcOverI          sOverI;    // �����б����
    sTcSuperI        sSuperI;    // ��������б����
    sTcZeroI          sZeroI;    // ������������б����
    sTcUnblnV          sUblV;    // �����ѹ��ƽ�ⳬ���б����
    sTcUnblnI          sUblI;    // ���������ƽ�ⳬ���б����
}sTcElecLimitPower, sTcAfn04f27;

// ��֡��
#pragma pack(1)

typedef struct
{
    sTcFmt08_f     fUpUp;        // ��ѹ������(��ѹ����) (+)XXX.X
    UINT8         ucTime;        // ����ʱ��
    sTcFmt10_f   fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX 
}sTcOverV_f;                     // ��ѹ�б����

typedef struct
{
    sTcFmt08_f fDownDown;        // ��ѹ������(��ѹ����) (+)XXX.X
    UINT8         ucTime;        // ����ʱ��
    sTcFmt10_f   fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcLossV_f;                     // Ƿѹ�б���� 

typedef struct
{
    sTcFmt09_f     fUpUp;        // ����������() (+/-)XXX.XXX
    UINT8         ucTime;        // ����ʱ��
    sTcFmt10_f   fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcOverI_f;                     // �����б����

typedef struct
{
    sTcFmt09_f       fUp;        // ������(���������) (+/-)XXX.XXX
    UINT8         ucTime;        // ����ʱ��
    sTcFmt10_f   fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcSuperI_f;                    // ��������б����

typedef struct
{
    sTcFmt09_f       fUp;        // 0��������� (+/-)XXX.XXX
    UINT8         ucTime;        // ����ʱ��
    sTcFmt10_f   fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcZeroI_f;                     // ������������б����

typedef struct
{
    sTcFmt06_f    fLimit;        // �����ѹ��ƽ�����ֵ (+/-)XX.XXXX
    UINT8         ucTime;        // ����ʱ��
    sTcFmt10_f   fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcUnblnV_f;                    // �����ѹ��ƽ�ⳬ���б����

typedef struct
{
    sTcFmt06_f    fLimit;        // ���������ƽ�����ֵ (+/-)XX.XXXX
    UINT8         ucTime;        // ����ʱ��
    sTcFmt10_f   fFactor;        // Խ�޻ָ�ϵͳ         (+)XX.XX   
}sTcUnblnI_f;                    // ���������ƽ�ⳬ���б����

typedef struct
{
    sTcFmt08_f        fDropV;    // ��ѹ�����б����  
    UINT8        ucTimeLossV;    // ��ѹʧѹʱ���б���� minutes
    sTcOverV_f        sOverV;    // ��ѹ�б����
    sTcLossV_f        sLossV;    // Ƿѹ�б����
    sTcOverI_f        sOverI;    // �����б����
    sTcSuperI_f      sSuperI;    // ��������б����
    sTcZeroI_f        sZeroI;    // ������������б����
    sTcUnblnV_f        sUblV;    // �����ѹ��ƽ�ⳬ���б����
    sTcUnblnI_f        sUblI;    // ���������ƽ�ⳬ���б����
}sTcElecLimitPower_f, sTcAfn04f27_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f27(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ���������㹦������Խ��ֵ����
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F28_ELEC_LMIT_FACTR
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    float  fPara1;            // �ܹ��������ֶβ��� 1   (+)XX.XX
    float  fPara2;            // �ܹ��������ֶβ��� 2   (+)XX.XX
    float  fWarning;          // �ܹ�������Խ�޸澯��ֵ (+)XX.XX
}sTcFactorLimit, sTcAfn04F28; // ���������㹦������Խ��ֵ�������ݵ�Ԫ��ʽ  

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt10_f  fPara1;      // �ܹ��������ֶβ��� 1
    sTcFmt10_f  fPara2;      // �ܹ��������ֶβ��� 2
    sTcFmt10_f  fWarning;    // �ܹ�������Խ�޸澯��ֵ
}sTcFactorLimit_f, sTcAfn04F28_f; // ���������㹦������Խ��ֵ�������ݵ�Ԫ��ʽ  
#pragma pack()

// ת������
eTcErr etc_trans_afn04f28(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ����������г��������Խ�޶�ֵ
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F29_ELEC_FIX_HARM
 * PN ���� : �����������
{*///
// aberration ����
typedef struct
{
   float fTotal;              // �ܻ�����Խ�޶�ֵ
   float   fOdd;              // ��λ�����Խ�޶�ֵ
   float  fEven;              // ż�λ����ʳ��޶�ֵ
}sTcAberLimit; 

// �û���
typedef struct
{
    sTcAberLimit      sVa;    // A���ѹ������Խ�޶�ֵ
    sTcAberLimit      sVb;    // B���ѹ������Խ�޶�ֵ
    sTcAberLimit      sVc;    // C���ѹ������Խ�޶�ֵ
    sTcAberLimit      sIa;    // A�����������Խ�޶�ֵ
    sTcAberLimit      sIb;    // B�����������Խ�޶�ֵ
    sTcAberLimit      sIc;    // C�����������Խ�޶�ֵ
     
}sTcElecFixHarm, sTcAfn04F29; // ���������㹦������Խ��ֵ�������ݵ�Ԫ��ʽ  

// ��֡��
#pragma pack(1)
typedef struct
{
   sTcFmt10_f fTotal;             // �ܻ�����Խ�޶�ֵ
   sTcFmt10_f   fOdd;             // ��λ�����Խ�޶�ֵ
   sTcFmt10_f  fEven;             // ż�λ����ʳ��޶�ֵ
}sTcAberLimit_f;

typedef struct
{
    sTcAberLimit_f      sVa;    // A���ѹ������Խ�޶�ֵ
    sTcAberLimit_f      sVb;    // B���ѹ������Խ�޶�ֵ
    sTcAberLimit_f      sVc;    // C���ѹ������Խ�޶�ֵ
    sTcAberLimit_f      sIa;    // A�����������Խ�޶�ֵ
    sTcAberLimit_f      sIb;    // B�����������Խ�޶�ֵ
    sTcAberLimit_f      sIc;    // C�����������Խ�޶�ֵ
    
}sTcElecFixHarm_f, sTcAfn04F29_f; // ���������㹦������Խ��ֵ�������ݵ�Ԫ��ʽ  
#pragma pack()

// ת������
eTcErr etc_trans_afn04f29(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��������������Խ�޲���
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F30_ELEC_FLASH
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    float    fLong;      // ��ʱ����Խ��ֵ  (+)XX.XX
    float   fShort;      // ��ʱ����Խ��ֵ  (+)XX.XX
}sTcElecFlash, sTcAfn04f30;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt10_f    fLong;      // ��ʱ����Խ��ֵ
    sTcFmt10_f   fShort;      // ��ʱ����Խ��ֵ
}sTcElecFlash_f, sTcAfn04f30_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f30(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ǵ������������ò���
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F33_NELC_MP_CFG
 * PN ���� : �����������
{*///
///*} 

// �û���
typedef sTcElecMpCfg sTcNelcMpCfg;
typedef sTcAfn04f25  sTcAfn04f33;

// ��֡��
//typedef sTcElecMpCfg_f sTcNelcMpCfg_f;

// ת������
eTcErr etc_trans_afn04f33(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ǵ������������ݲ���
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F34_NELC_MP_PARA
 * PN ���� : �����������
{*///
// �û���
typedef enum
{
   TC_NELC_UNKOWN,
   TC_NELC_TEMP,       // �¶�
   TC_NELC_FLOW,       // ����
   TC_NELC_FV,         // ����
   TC_NELC_PRESS,      // ѹ��
   TC_NELC_HUMI,       // ʪ��
   TC_NELC_LIGHT,      // �ն�
   TC_NELC_RV,         // ת��
   TC_NELC_420MA,      // 4~20MA

}eTcNelcType;

typedef struct
{
    eTcNelcType eType;           // �ǵ���������
    sTcDouble     sUp;           // ��������
    sTcDouble   sDown;           // ��������
}sTcNelcMpPara, sTcAfn04f34;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8       eType;            // �ǵ���������
    sTcFmt11_f    sUp;            // ��������
    sTcFmt11_f  sDown;            // ��������
}sTcNelcMpCfg_f, sTcAfn04f34_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f34(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ǵ���������Խ�����ݲ���
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_4_F35_NELC_MP_LMIT
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    eTcNelcType eType;           // �ǵ���������
    sTcDouble    sUp;             // Խ���޶�ֵ
    sTcDouble    sDown;           // Խ���޶�ֵ

}sTcNelcMpLimit, sTcAfn04f35;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8       eType;            // �ǵ���������
    sTcFmt11_f    sUp;            // Խ���޶�ֵ
    sTcFmt11_f  sDown;            // Խ���޶�ֵ
}sTcNelcMpLimit_f, sTcAfn04f35_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn04f35(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: Уʱ����
 * ��ӦAFN : TC_AFN_04_SETP
 * ��ӦCMD : TCMD_AFN_5_F1_CHECK_TIME
 * PN ���� : �����������
{*///

// �û���
// sTcYWMDhms
// ��֡��
// sTcYWMDhms_f

// ת������
eTcErr etc_trans_afn05f1(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��ʱ��������
 * ��ӦAFN : TC_AFN_05_CTRL
 * ��ӦCMD : TCMD_AFN_5_F2_FREZ_TEMP
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    UINT8         ucNum;    // ���ݵ�Ԫ��ʶ����
    sTcmdPn   sCmdPn[1];    // ucNum �����ݵ�Ԫ��ʶ
}sTcFrezTemp, sTcAfn05f2;

// ��֡��
typedef struct
{
    UINT8         ucNum;     // ���ݵ�Ԫ��ʶ���� DaDt
    sTcDaDt    sDaDt[1];  // ucNum ��DaDt
}sTcFrezTemp_f, sTcAfn05f2_f;

// ת������
eTcErr etc_trans_afn05f2(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ң����բ
 * ��ӦAFN : TC_AFN_05_CTRL
 * ��ӦCMD : TCMD_AFN_5_F17_REMOTE_OFF
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    BOOL         bOff[8];    // ��1-8��������Ƿ���բ
    sTcYMDhm sTimeStart;    // ��բ��ʼʱ�� 
    sTcYMDhm   sTimeEnd;    // ��բ����ʱ�� 
}sTcRemoteOff, sTcAfn05f17;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8         bOff;      // ÿһbit��ʾ��1-8��������Ƿ����
    sTcYMDhm_f sTimeStart;  // ��բ��ʼʱ�� 
    sTcYMDhm_f   sTimeEnd;  // ��բ����ʱ��   

}sTcRemoteOff_f, sTcAfn05f17_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn05f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �����բ
 * ��ӦAFN : TC_AFN_05_CTRL
 * ��ӦCMD : TCMD_AFN_5_F18_REMOTE_ON
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    BOOL         bOn[8];    // ��1-8��������Ƿ���բ
}sTcRemoteOn, sTcAfn05f18;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8         bOn;      // ÿһbit��ʾ��1-8��������Ƿ����
 
}sTcRemoteOn_f, sTcAfn05f18_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn05f18(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��Чģ����Ч
 * ��ӦAFN : TC_AFN_05_CTRL
 * ��ӦCMD : TCMD_AFN_5_F5_NX_MODEL_ACT
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    UINT8        ucID;       // ��N����Чģʽ���
    sTcYWMDhms  sTime;       // ��ʼʱ��:������ʱ����
}sTcNxModelOne;

typedef struct
{
    UINT8              ucN;  // ��Чģ�͸���
    sTcNxModelOne  sOne[1];  // ��n����Чģ�� һ��N����Чģ��

}sTcNxModelAct, sTcAfn05f5;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8         ucID;       // ��N����Чģʽ���
    sTcYWMDhms_f  sTime;      // ��ʼʱ��:������ʱ����
}sTcNxModelOne_f;

typedef struct
{
    UINT8              ucN;  // ��Чģ�͸���
    sTcNxModelOne_f   sOne[1];  // ��n����Чģ�� һ��N����Чģ��
}sTcNxModelAct_f, sTcAfn05f5_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn05f5(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��Чģ�����
 * ��ӦAFN : TC_AFN_05_CTRL
 * ��ӦCMD : TCMD_AFN_5_F6_NX_MODEL_CLR
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    UINT8            ucN;  // ��Чģ�͸���
    UINT8        ucID[1];  // ��n����Чģ�ͱ��
}sTcNxModelClr, sTcAfn05f6;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8            ucN;  // ��Чģ�͸���
    UINT8        ucID[1];  // ��n����Чģ�ͱ��
}sTcNxModelClr_f, sTcAfn05f6_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn05f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ������Ӧ��Ϣ��Ч
 * ��ӦAFN : TC_AFN_05_CTRL
 * ��ӦCMD : TCMD_AFN_5_F7_RQ_RESPN_ACT
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    UINT8            ucN;  // ������Ӧ��Ϣ����n
    UINT8        ucID[1];  // ��n��������Ӧ��Ϣ���
}sTcRqRespnAct, sTcAfn05f19;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8            ucN;  // ������Ӧ��Ϣ����n
    UINT8        ucID[1];  // ��n��������Ӧ��Ϣ���
}sTcRqRespnAct_f, sTcAfn05f19_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn05f7(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ������Ӧ��Ϣ���
 * ��ӦAFN : TC_AFN_05_CTRL
 * ��ӦCMD : TCMD_AFN_5_F8_RQ_RESPN_CLT
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    UINT8            ucN;  // ������Ӧ��Ϣ����n
    UINT8        ucID[1];  // ��n��������Ӧ��Ϣ���
}sTcRqRespnClr, sTcAfn05f20;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8            ucN;  // ������Ӧ��Ϣ����n
    UINT8        ucID[1];  // ��n��������Ӧ��Ϣ���
}sTcRqRespnClr_f, sTcAfn05f20_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn05f8(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �豸֧�ֵ��¼���¼(ѯ��û�в��� Ӧ�𱾽ṹ)
 * ��ӦAFN : TC_AFN_10_GETP
 * ��ӦCMD : TCMD_AFN_A_F11_TML_SPRT_EVENT
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
   BOOL  bSuprt[TC_ERC_NUM_MAX];    // �Ը��¼��Ƿ�֧��
   
}sTcSuptEvent, sTcAfn10f11;

// ��֡��
#pragma pack(1)
typedef struct
{
   UINT8   ucEvent[8];              // D0~D63��˳���Ӧ��ʾ�¼�����ERC1~ERC64��������¼�
   
}sTcSuptEvent_f, sTcAfn10f11_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn10f11(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �����õ�����������Ϣ(ѯ��û�в��� Ӧ�𱾽ṹ)
 * ��ӦAFN : TC_AFN_10_GETP
 * ��ӦCMD : TCMD_AFN_A_F12_ELEC_MP_INFO
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    UINT8    ucSprt;          // ֧�ֵĲ�������Ϣ��������n (1 < n < 255)
    UINT16    usNum;          // �Ѿ����õ�Pn����
    UINT16  usPn[1];          // ���õľ���pn
}sTcElecMpInfo, sTcAfn10f12;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8   ucSprt;           // ֧�ֵĲ�������Ϣ��������n (1 < n < 255)
    UINT8   ucSDa2;           // ��֡�ϱ�����ʼ��Ϣ����DA2 (1 < m < 255)
    UINT8   ucK;              // ��֡�ϱ��ĸ���
    UINT8   ucDa1[1];         // ��i ����Ϣ����DA2����Ӧ��DA1��i=m~m+k-1�� 
}sTcElecMpInfo_f, sTcAfn10f12_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn10f12(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �����÷ǵ�����������Ϣ(ѯ��û�в��� Ӧ�𱾽ṹ)
 * ��ӦAFN : TC_AFN_10_GETP
 * ��ӦCMD : TCMD_AFN_A_F13_NELC_MP_INFO
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    UINT8    ucSprt;          // ֧�ֵĲ�������Ϣ��������n (1 < n < 255)
    UINT16    usNum;          // �Ѿ����õ�Pn����
    UINT16  usPn[1];          // ���õľ���pn
}sTcNelcMpInfo, sTcAfn10f13;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8   ucSprt;           // ֧�ֵĲ�������Ϣ��������n (1 < n < 255)
    UINT8   ucSDa2;           // ��֡�ϱ�����ʼ��Ϣ����DA2 (1 < m < 255)
    UINT8   ucK;              // ��֡�ϱ��ĸ���
    UINT8   ucDa1[1];         // ��i ����Ϣ����DA2����Ӧ��DA1��i=m~m+k-1�� 
}sTcNelcMpInfo_f, sTcAfn10f13_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn10f13(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ����˿�֧�ֵ�ͨ��Э����Ϣ(ѯ��û�в��� Ӧ�𱾽ṹ)
 * ��ӦAFN : TC_AFN_10_GETP
 * ��ӦCMD : TCMD_AFN_A_F14_TML_PROTO_SPRT
 * PN ���� : p0
{*///

#define TC_PROTO_NAME_LEN  (16)
typedef struct
{
    eTcAcsProto eType;
    UINT8       strName[TC_PROTO_NAME_LEN];    
}sTcProto;

// �û���
typedef struct
{
    UINT8        ucN;               // ֧�ֵ�ͨ��Э������n  ��n=0ʱ����ʾ����˿ڲ�֧���κ�ͨ��Э��
    UINT8        ucM;               // ��֡�ϱ�����ʼ���m��m��1��
    UINT8        ucK;               // ��֡�ϱ��ĸ���k
    sTcProto sOne[1];               // һ��K�� (m~m+k-1)
}sTcTmlProtoSprt, sTcAfn10f14;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8      eType;
    UINT8      strName[TC_PROTO_NAME_LEN];    
}sTcProto_f;

typedef struct
{
    UINT8         ucN;               // ֧�ֵ�ͨ��Э������n ��n=0ʱ����ʾ����˿ڲ�֧���κ�ͨ��Э��
    UINT8         ucM;               // ��֡�ϱ�����ʼ���m��m��1��
    UINT8         ucK;               // ��֡�ϱ��ĸ���k
    sTcProto_f sOne[1];               // һ��K�� (m~m+k-1)
}sTcTmlProtoSprt_f, sTcAfn10f14_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn10f14(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 


// 
/*******************************************
 * ��������: ��Ӳ���汾��Ϣ����
 * ����˵��: ��Ӧ�ڸ�¼G
 *
{*///

// �û���
typedef struct
{
    UINT8    strFactory[4];       // ���̴���
    UINT8      strDevId[4];       // �豸�Mģ����� 
    UINT8       strAddr[16];      // �豸�Mģ���ţ���ַ��  16λ����
    UINT8       strHard[4];       // Ӳ���汾��
    sTcYMDhm     sTimeHard;       // Ӳ���汾����ʱ�� (��ʱ������)
    UINT8       strSoft[4];       // ����汾��
    sTcYMDhm     sTimeSoft;       // ����汾����ʱ�� (��ʱ������)
    UINT8    strVolume[12];       // ����������Ϣ��
    UINT8     strProto[16];       // ����ͨ��Э��汾��
}sTcVersion;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8    strFactory[4];       // ���̴���
    UINT8      strDevId[4];       // �豸�Mģ����� 
    UINT8       strAddr[8];       // �豸�Mģ���ţ���ַ�� BCD 16λ����
    UINT8       strHard[4];       // Ӳ���汾��
    sTcYMDhm_f   sTimeHard;       // Ӳ���汾����ʱ�� (��ʱ������)
    UINT8       strSoft[4];       // ����汾��
    sTcYMDhm_f   sTimeSoft;       // ����汾����ʱ�� (��ʱ������)
    UINT8    strVolume[12];       // ����������Ϣ��
    UINT8     strProto[16];       // ����ͨ��Э��汾��
}sTcVersion_f;
#pragma pack()

// ת������
eTcErr etc_trans_version(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ն��ڸ�����ģ�����Ӳ���汾��Ϣ
 * ��ӦAFN : TC_AFN_10_GETP
 * ��ӦCMD : TCMD_AFN_A_F15_TML_MODEL_VERSION
 * ����˵��: ѯ��û�в��� Ӧ�𱾽ṹ
 * PN ���� : p0
{*///

typedef struct
{
    UINT8            ucID;      // ����ģ����
    sTcVersion   sVersion;      // ����ģ����Ӳ���汾��Ϣ
}sTcModelVerion;

// �û���
typedef struct
{
    UINT8              ucN;      // ����ģ������n ��n=0ʱ����ʾ����ն���������ģ�飬�� 47��ʾ�����ݵ�ԪҲ�ͽ���һ�ֽڡ�
    UINT8              ucM;      // ��֡�ϱ�����ʼ���m��m��1��
    UINT8              ucK;      // ��֡�ϱ��ĸ���k
    sTcModelVerion sOne[1];
}sTcTmlModelVersion, sTcAfn10f15;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8              ucID;      // ����ģ����
    sTcVersion_f   sVersion;      // ����ģ����Ӳ���汾��Ϣ
}sTcModelVerion_f;

typedef struct
{
    UINT8                ucN;     // ����ģ������n ��n=0ʱ����ʾ����ն���������ģ�飬�� 47��ʾ�����ݵ�ԪҲ�ͽ���һ�ֽڡ�
    UINT8                ucM;     // ��֡�ϱ�����ʼ���m��m��1��
    UINT8                ucK;     // ��֡�ϱ��ĸ���k
    sTcModelVerion_f sOne[1];
}sTcTmlModelVersion_f, sTcAfn10f15_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn10f15(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ն���Ӳ���汾��Ϣ
 * ��ӦAFN : TC_AFN_10_GETP
 * ��ӦCMD : TCMD_AFN_A_F16_TML_VERSION
 * ����˵��: ѯ��û�в��� Ӧ�𱾽ṹ
 * PN ���� : p0
{*///
// �û���
typedef sTcVersion sTcTmlVersion;

// ��֡��
// typedef sTcVersion_f sTcTmlVersion_f;

// ת������
eTcErr etc_trans_afn10f16(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 


/*******************************************
 * ��������: ����ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F1_CLOCK
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcUerClock sTcClock, sTcAfn13f1;

// ��֡��
#pragma pack(1)
typedef sTcUerClock_f sTcClock_f, sTcAfn13f1_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f1(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ����״̬��־(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F2_PARA_STATE
 * PN ���� : p0/����ն˺�
{*///

// Ŀǰ�������õĲ�������Ϊ20(TCMD_AFN_4_F1_CON_IP_PORT  �� TCMD_AFN_4_F49_FREZ_TASK_PARA)
#define TC_SET_NUM_MAX  (20)     

// �û���
typedef struct
{
    UINT8    ucNum;  // �Ѿ����õĸ���
    eTcmd  eCmd[1];  // �Ѿ����õĲ�������
}sTcParaState, sTcAfn13f2;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8  ucSet[31];
}sTcParaState_f, sTcAfn13f2_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f2(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��Ҫ�¼���������ǰֵ(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F3_EVENT_1
 * PN ���� : p0/����ն˺�
{*///

// �û���
// UINT16 usEc1

// ��֡��
// UINT16 usEc1_f

// ת������
eTcErr etc_trans_afn13f3(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: һ���¼���������ǰֵ(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F4_EVENT_2
 * PN ���� : p0/����ն˺�
{*///

// �û���
// UINT16 usEc2

// ��֡��
// UINT16 ucEc2_f

// ת������
eTcErr etc_trans_afn13f4(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �¼�״̬��־
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F5_EVENT_STATE
 * �ṹ����: �����޲���, Ӧ��Ϊ���ṹ
 * PN ���� : P0
{*///
// �û���
typedef struct
{
    BOOL bHave[TC_ERC_NUM_MAX];      // ��:�л�֧�ָ��¼� ��: �޻�֧�ָ��¼� 
}sTcEventState, sTcAfn13f5;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8   ucHave[8];               // ÿ��bit�����Ƿ��ж�Ӧ���¼�����
}sTcEventState_f, sTcAfn13f5_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f5(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ϵ����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F6_POWR_TIMES
 * PN ���� : p0/����ն˺�
{*///

#define TC_POWR_TIMES_MAX (999999)
// �û���
typedef struct
{
    UINT32 ulTimes;    //  (0-999999)
}sTcPowerTimes, sTcAfn13f6;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8   ucBcd[3];       // BCD��ʽ
}sTcPowerTimes_f, sTcAfn13f6_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ״̬������λ��־(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F9_STATE
 * PN ���� : p0/����ն˺�
{*///

// �û���
typedef struct
{
    BOOL bSt[8];   // ��ʾ1-8·״̬����״̬ST ��:��, ��:��          
    BOOL bCd[8];   // ��ʾ1-8·״̬���ı仯CD 
                   // ��:��ǰ��ң�Ŵ��ͺ�������һ��״̬�仯
                   // ��:��ǰ��ң�Ŵ��ͺ�û��״̬�仯
}sTcState, sTcAfn13f9;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8  ucSt8;
    UINT8  ucCd8;
}sTcState_f, sTcAfn13f9_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f9(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ���й�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F17_POWR_HAVE_T
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    float fXX_XXXX;              //  ���й�����(Kw) (+)XX.XXXX
}sTcPowerHaveT, sTcAfn13f17;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt06_f fXX_XXXX;       
}sTcPowerHaveT_f, sTcAfn13f17_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ���޹�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F18_POWR_NONE_T
 * PN ���� : p0/����ն˺�
{*///

// �û���
typedef struct
{
    float fXX_XXXX;             //  ���޹�����(Kw) (+)XX.XXXX
}sTcPowerNoneT, sTcAfn13f18;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt06_f fXX_XXXX;       
}sTcPowerNoneT_f, sTcAfn13f18_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f18(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �������������ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F19_DEMD_TIME_D
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    float    fXX_XXXX;           // ������� (+/-)XX.XXXX
    sTcYMDhm sTime;              //  �������������ʱ�� ������ʱ��
}sTcDemandMaxD, sTcAfn13f19;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt06_f fXX_XXXX;  
    sTcYMDhm_f sTime;             //  �������������ʱ�� ������ʱ��
}sTcDemandMaxD_f, sTcAfn13f19_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f19(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ���������������ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F20_DEMD_TIME_M
 * PN ���� : �����������
{*///
// �û���
typedef sTcDemandMaxD sTcDemandMaxM;

// ת������
// ͬ eTcErr etc_trans_afn13f19(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ܹ�������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F21_FACTR_T
 * PN ���� : p0/����ն˺�
{*///

// �û���
typedef struct
{
    float fXX_XX;             //  �ܹ������� (+)XX.XX
}sTcFactorT, sTcAfn13f21;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt10_f fXX_XX;       
}sTcFactorT_f, sTcAfn13f21_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A�๦������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F22_FACTR_A
 * PN ���� : p0/����ն˺�
{*///

// �û���
typedef struct
{
    float fXX_XX;             //  A�๦������ (+)XX.XX
}sTcFactorA, sTcAfn13f28;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt10_f fXX_XX;       
}sTcFactorA_f, sTcAfn13f28_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f22(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B�๦������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F23_FACTR_B
 * PN ���� : p0/����ն˺�
{*///

// �û���
typedef struct
{
    float fXX_XX;             //  B�๦������ (+)XX.XX
}sTcFactorB, sTcAfn13f29;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt10_f fXX_XX;       
}sTcFactorB_f, sTcAfn13f29_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f23(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C�๦������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F24_FACTR_C
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    float fXX_XX;             //  C�๦������ (+)XX.XX
}sTcFactorC, sTcAfn13f30;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt10_f fXX_XX;       
}sTcFactorC_f, sTcAfn13f30_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f24(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���й�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F25_POWR_HAVE_A
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    float fXX_XX;             //  A���й����� (+)XX.XX
}sTcPowerHaveA, sTcAfn13f25;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt10_f fXX_XX;       
}sTcPowerHaveA_f, sTcAfn13f25_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f25(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���й�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F26_POWR_HAVE_B
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcPowerHaveA sTcPowerHaveB;

// ��֡��
// typdef sTcPowerHaveA_f sTcPowerHaveB_f;

// ת������
eTcErr etc_trans_afn13f26(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���й�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F27_POWR_HAVE_C
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcPowerHaveA sTcPowerHaveC;

// ��֡��
// typdef sTcPowerHaveA_f sTcPowerHaveC_f;

// ת������
eTcErr etc_trans_afn13f27(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���޹�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F28_POWR_NONE_A
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcPowerHaveA sTcPowerNoneA;

// ��֡��
// typdef sTcPowerHaveA_f sTcPowerNoneA_f;

// ת������
eTcErr etc_trans_afn13f28(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���޹�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F29_POWR_NONE_B
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcPowerHaveA sTcPowerNoneB;

// ��֡��
// typdef sTcPowerHaveA_f sTcPowerNoneB_f;

// ת������
eTcErr etc_trans_afn13f29(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���޹�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F30_POWR_NONE_C
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcPowerHaveA sTcPowerNoneC;

// ��֡��
// typdef sTcPowerHaveA_f sTcPowerNoneC_f;

// ת������
eTcErr etc_trans_afn13f30(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �������й��ܵ���ʾ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F33_POWR_HAVE_FRTH
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    double dXXXXXX_XXXX;           // ����ʾ��    (+)XXXXXX.XXXX    
}sTcPowerHaveFrth, sTcAfn13f33;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt04_f dXXXXXX_XXXX;
}sTcPowerHaveFrth_f, sTcAfn13f33_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f33(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �������й��ܵ���ʾ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F34_POWR_HAVE_BACK
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcPowerHaveFrth sTcPowerHaveBack;

// ��֡��
// typdef sTcPowerHaveFrth_f sTcPowerHaveBack_f;

// ת������
eTcErr etc_trans_afn13f34(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �������޹��ܵ���ʾ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F35_POWR_NONE_FRTH
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    double dXXXXXX_XX;           // ����ʾ��    (+)XXXXXX.XX    
}sTcPowerNoneFrth, sTcAfn13f35;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt05_f dXXXXXX_XX;
}sTcPowerNoneFrth_f, sTcAfn13f35_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f35(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �������й��ܵ���ʾ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F36_POWR_NONE_BACK
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcPowerNoneFrth sTcPowerNoneBack;

// ��֡��
// typdef sTcPowerNoneFrth_f sTcPowerNoneBack_f;

// ת������
eTcErr etc_trans_afn13f36(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹ(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F41_VOLT_A
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    float fXXX_X;           // ��ѹʾ�� (V)   (+)XXX.X    
}sTcVoltA, sTcAfn13f41;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt08_f fXXX_X;
}sTcVoltA_f, sTcAfn13f41_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f41(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������:  B���ѹ(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F58_VOLT_B
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcVoltA sTcVoltB;

// ��֡��
//typedef sTcVoltA_f sTcVoltB_f;

// ת������
eTcErr etc_trans_afn13f42(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ѹ(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F43_VOLT_C
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcVoltA sTcVoltC;

// ��֡��
//typedef sTcVoltA_f sTcVoltC_f;

// ת������
eTcErr etc_trans_afn13f43(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹ��λ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F44_VANGL_A
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    float fsXXX_X;           // ��ѹʾ�� (��)   (+/-)XXX.X    
}sTcVAngleA, sTcAfn13f44;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt07_f fsXXX_X;
}sTcVAngleA_f, sTcAfn13f44_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f44(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������:  B���ѹ��λ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F45_VANGL_B
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcVAngleA sTcVAngleB;

// ��֡��
// typedef sTcVAngleA_f sTcVAngleB_f;

// ת������
eTcErr etc_trans_afn13f45(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ѹ��λ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F46_VANGL_C
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcVAngleA sTcVAngleC;

// ��֡��
// typedef sTcVAngleA_f sTcVAngleC_f;

// ת������
eTcErr etc_trans_afn13f46(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��ѹ��ƽ���(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F47_VOLT_UBL
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcFactorT sTcVoltUbl;

// ��֡��
// typedef sTcFactorT_f sTcVoltUbl_f;

// ת������
eTcErr etc_trans_afn13f47(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ܲ�(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F48_CIRCLE_V
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcAfn13f25 sTcVCircle;

// ��֡��

// ת������
eTcErr etc_trans_afn13f48(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F49_ELEC_A
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    float fsXXX_XXX;        //  (A) (+/-)XXX.XXX  
}sTcElecA, sTcAfn13f49;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt09_f fsXXX_XXX;
}sTcElecA_f, sTcAfn13f49_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f49(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F50_ELEC_B
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcElecA sTcElecB;

// ��֡��
// ת������
eTcErr etc_trans_afn13f50(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F51_ELEC_C
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcElecA sTcElecC;

// ��֡��
// ת������
eTcErr etc_trans_afn13f51(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �����ߵ���(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F52_ELEC_M
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcElecA sTcElecM;

// ��֡��
// ת������
eTcErr etc_trans_afn13f52(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A�������λ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F53_EANGL_A
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcAfn13f44 sTcEAngleA;

// ��֡��
// ת������
eTcErr etc_trans_afn13f53(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B�������λ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F54_EANGL_B
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcAfn13f44 sTcEAngleB;

// ��֡��
// ת������
eTcErr etc_trans_afn13f54(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C�������λ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F55_EANGL_C
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcAfn13f44 sTcEAngleC;

// ��֡��
// ת������
eTcErr etc_trans_afn13f55(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ������ƽ���(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F56_ELEC_UBL
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcAfn13f44 sTcElecUbl;

// ��֡��
// ת������
eTcErr etc_trans_afn13f56(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��A���ѹ����ֵ�ͷ���ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F57_VDMAX_A_TIME
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    float fXXX_X;           // ��ѹʾ�� (V)   (+)XXX.X    
    sTcYMDhm sTime;         // ����ʱ�� ������ʱ��
    
}sTcVdMaxTimeA, sTcAfn13f57;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt08_f fXXX_X;
    sTcFmt02_f sTime;       
}sTcVdMaxTimeA_f, sTcAfn13f57_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f57(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��B���ѹ����ֵ�ͷ���ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F58_VDMAX_B_TIME
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcVdMaxTimeA sTcVdMaxTimeB;

// ��֡��

// ת������
// ͬ eTcErr etc_trans_afn13f57(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��C���ѹ����ֵ�ͷ���ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F59_VDMAX_C_TIME
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcVdMaxTimeA sTcVdMaxTimeC;

// ��֡��

// ת������
// ͬ eTcErr etc_trans_afn13f57(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��A���������ֵ�ͷ���ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F60_IDMAX_A_TIME
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    float fsXXX_XXX;        // ��������ֵ (A) (+/-)XXX.XXX  
    sTcYMDhm sTime;         // ����ʱ�� ������ʱ��
    
}sTcIdMaxTimeA, sTcAfn13f60;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt09_f fsXXX_XXX;
    sTcFmt02_f sTime;       
}sTcIdMaxTimeA_f, sTcAfn13f60_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f60(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��B���������ֵ�ͷ���ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F61_IDMAX_B_TIME
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcIdMaxTimeA sTcIdMaxTimeB;

// ��֡��

// ת������
// ͬ eTcErr etc_trans_afn13f60(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��C���������ֵ�ͷ���ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F62_IDMAX_C_TIME
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcIdMaxTimeA sTcIdMaxTimeC;

// ��֡��

// ת������
// ͬ eTcErr etc_trans_afn13f60(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F65_VDPP_TIME_A
 * PN ���� : �����������
{*///
#define TC_BCD_XXXX_MAX  (9999)

// �û���
typedef struct
{
    UINT16    usMinutes;       // ʱ�� ���� ���ֵ TC_BCD_XXXX_MAX
    
}sTcVDppTimeA, sTcAfn13f97;  

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8 ucBCD[2];
    
}sTcVDppTimeA_f, sTcAfn13f97_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f65(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F66_VDPP_TIME_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcVDppTimeA sTcVDppTimeB;
// ת������
// ͬ eTcErr etc_trans_afn13f65(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F67_VDPP_TIME_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcVDppTimeA sTcVDppTimeC;
// ת������
// ͬ eTcErr etc_trans_afn13f65(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F68_VDNN_TIME_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcVDppTimeA sTcVDnnTimeA;
// ת������
// ͬ eTcErr etc_trans_afn13f65(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F69_VDNN_TIME_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcVDppTimeA sTcVDnnTimeB;
// ת������
// ͬ eTcErr etc_trans_afn13f65(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F70_VDNN_TIME_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcVDppTimeA sTcVDnnTimeC;
// ת������
// eTcErr etc_trans_afn13f65(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F73_VMPP_TIME_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcPowerTimes sTcVMppTimeA;
// ת������
// ͬ eTcErr etc_trans_afn13f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F74_VMPP_TIME_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcPowerTimes sTcVMppTimeB;
// ת������
// ͬ eTcErr etc_trans_afn13f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F75_VMPP_TIME_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcPowerTimes sTcVMppTimeC;
// ת������
// ͬ eTcErr etc_trans_afn13f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F76_VMNN_TIME_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcPowerTimes sTcVMnnTimeA;
// ת������
// ͬ eTcErr etc_trans_afn13f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F77_VMNN_TIME_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcPowerTimes sTcVMnnTimeB;
// ת������
// ͬ eTcErr etc_trans_afn13f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ѹԽ���������ۼ�ʱ��(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F78_VMNN_TIME_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcPowerTimes sTcVMnnTimeC;
// ת������
// ͬ eTcErr etc_trans_afn13f6(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹ�ܻ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F81_VABR_TOTL_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcVabrTotalA;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���ѹ�ܻ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F82_VABR_TOTL_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcVabrTotalB;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ѹ�ܻ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F83_VABR_TOTL_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcVabrTotalC;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A������ܻ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F84_EABR_TOTL_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcEabrTotalA;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B������ܻ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F85_EABR_TOTL_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcEabrTotalB;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C������ܻ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F86_EABR_TOTL_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcEabrTotalC;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹ��λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F89_VABR_OOD_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcVabrOddA;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹż�λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F90_VABR_EVN_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcVabrEvnA;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���ѹ��λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F91_VABR_OOD_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcVabrOddB;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���ѹż�λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F92_VABR_EVN_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcVabrEvnB;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ѹ��λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F93_VABR_OOD_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcVabrOddC;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ѹż�λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F94_VABR_EVN_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcVabrEvnC;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ѹ��λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F97_EABR_OOD_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcEabrOddA;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A�����ż�λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F98_EABR_EVN_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcEabrEvnA;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B�������λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F99_EABR_OOD_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcEabrOddB;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B�����ż�λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F100_EABR_EVN_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcEabrEvnB;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C�������λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F101_EABR_OOD_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcEabrOddC;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C�����ż�λ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F102_EABR_EVN_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcEabrEvnC;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ܻ����й�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F105_TFW_HAVE
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcAfn13f17 sTcTfwHave;   // (Total Fundamental Wave)

// ��֡��
// ת������
// ͬ eTcErr etc_trans_afn13f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);

///*} 

/*******************************************
 * ��������: �ܻ����޹�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F106_TFW_NONE
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcAfn13f17 sTcTfwNone;   // (Total Fundamental Wave)

// ��֡��
// ת������
// ͬ eTcErr etc_trans_afn13f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ��г���й�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F107_THW_HAVE
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcAfn13f17 sTcThwHave;   // (Total Harmonic Wave)

// ��֡��
// ת������
// ͬ eTcErr etc_trans_afn13f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ܻ����޹�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F108_THW_NONE
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef sTcAfn13f17 sTcThwNone;   // (Total Harmonic Wave)

// ��֡��
// ת������
// ͬ eTcErr etc_trans_afn13f17(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A��N��г����ѹ(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F113_HARM_VOLT_A
 * PN ���� : �����������
{*///

#define TC_HARM_TIMES_MAX      (19) // г���������ֵ

// �û���
typedef struct
{
    UINT8        ucN;          // г������
    float    fXXX_X[1];        // 2 ~ n��г��  (����Ԫ�ظ���Ϊ ucN - 1)
}sTcHarmVoltA, sTcAfn13f113;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8             ucN;      // г������
    sTcFmt08_f  fXXX_X[1];      // 2 ~ n��г��  (����Ԫ�ظ���Ϊ ucN - 1)
}sTcHarmVoltA_f, sTcAfn13f113_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f113(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B��N��г����ѹ(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F114_HARM_VOLT_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcHarmVoltA sTcHarmVoltB;
// ת������
// ͬ eTcErr etc_trans_afn13f113(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C��N��г����ѹ(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F115_HARM_VOLT_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcHarmVoltA sTcHarmVoltC;
// ת������
// ͬ eTcErr etc_trans_afn13f113(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A��N��г������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F116_HARM_ELEC_A
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    UINT8             ucN;          // г������
    float    fsXXX_XXX[1];          // 2 ~ n��г��  (����Ԫ�ظ���Ϊ ucN - 1)
}sTcHarmElecA, sTcAfn13f116;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8                ucN;      // г������
    sTcFmt09_f  fsXXX_XXX[1];      // 2 ~ n��г��  (����Ԫ�ظ���Ϊ ucN - 1)
}sTcHarmElecA_f, sTcAfn13f116_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f116(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B��N��г������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F117_HARM_ELEC_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcHarmElecA sTcHarmElecB;

// ת������
// ͬ eTcErr etc_trans_afn13f116(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C��N��г������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F118_HARM_ELEC_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcHarmElecA sTcHarmElecC;

// ת������
// ͬ eTcErr etc_trans_afn13f116(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A��N��г����ѹ������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F121_HARM_VINC_A
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    UINT8             ucN;          // г������
    float       fXX_XX[1];          // 2 ~ n��г��������  (����Ԫ�ظ���Ϊ ucN - 1)
}sTcHarmVincA, sTcAfn13f121;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8              ucN;      // г������
    sTcFmt10_f   fXX_XX[1];      // 2 ~ n��г��������  (����Ԫ�ظ���Ϊ ucN - 1)
}sTcHarmVincA_f, sTcAfn13f121_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f121(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B��N��г����ѹ������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F122_HARM_VINC_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcHarmVincA sTcHarmVincB;

// ת������
// ͬ eTcErr etc_trans_afn13f121(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C��N��г����ѹ������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F123_HARM_VINC_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcHarmVincA sTcHarmVincC;

// ת������
// ͬ eTcErr etc_trans_afn13f121(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A��N��г������������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F124_HARM_EINC_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcHarmVincA sTcHarmEincA;

// ת������
// ͬ eTcErr etc_trans_afn13f121(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B��N��г������������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F125_HARM_EINC_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcHarmVincA sTcHarmEincB;

// ת������
// ͬ eTcErr etc_trans_afn13f121(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C��N��г������������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F126_HARM_EINC_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcHarmVincA sTcHarmEincC;

// ת������
// ͬ eTcErr etc_trans_afn13f121(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A���ʱ����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F129_FLS_SHRT_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcFlashShortA;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B���ʱ����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F130_FLS_SHRT_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcFlashShortB;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C���ʱ����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F131_FLS_SHRT_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcFlashShortC;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: A�೤ʱ����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F132_FLS_LONG_A
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcFlashLongA;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: B�೤ʱ����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F133_FLS_LONG_B
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcFlashLongB;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: C�೤ʱ����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F134_FLS_LONG_C
 * PN ���� : �����������
{*///
// �û���
typedef sTcAfn13f21 sTcFlashLongC;
// ת������
// ͬ eTcErr etc_trans_afn13f21(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: �ǵ�����(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_13_ASKR
 * ��ӦCMD : TCMD_AFN_D_F137_NELC_VALUE
 * PN ���� : �����������
{*///
// �û���
typedef struct
{
    eTcNelcType   eType;           // �ǵ���������
    sTcDouble   sDouble;           // �ǵ��������� ��ֵ
}sTcNelcValue, sTcAfn13f137;

// ��֡��
#pragma pack(1)
typedef struct
{
    UINT8         eType;       // �ǵ���������
    sTcFmt11_f   sDouble;      // �ǵ���������  ��ֵ
}sTcNelcValue_f, sTcAfn13f137_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn13f137(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ���󣨶�ʱ�ϱ���������������(�������)
 * ��ӦAFN : TC_AFN_12_ASKT
 * ��ӦCMD : TCMD_AFN_C_F9_FREZ_AUTO
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef struct
{
    sTcYMDhm   sTs;    // ���󶳽����������е����ݵ���ʼʱ��ts����ʱ������
    sTcYMDhm   sTe;    // ���󶳽����������е����ݵĽ���ʱ��te����ʱ������
}sTcFrezAutoQ, sTcAfn12f9;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt02_f           sTs;         // ���󶳽����������е����ݵ���ʼʱ��ts����ʱ������
    sTcFmt02_f           sTe;         // ���󶳽����������е����ݵĽ���ʱ��te����ʱ������
}sTcFrezAutoQ_f, sTcAfn12f9_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn12f9_m2s(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 

/*******************************************
 * ��������: ���󣨶�ʱ�ϱ���������������(Ӧ���ʽ)
 * ��ӦAFN : TC_AFN_12_ASKT
 * ��ӦCMD : TCMD_AFN_C_F9_FREZ_AUTO
 * PN ���� : p0/����ն˺�
{*///
// �û���
typedef union
{
    // TCMD_AFN_D_F1_CLOCK
    sTcUerClock           sUerClock;
    
    // TCMD_AFN_D_F2_PARA_STATE
    // ����״̬��־
    sTcParaState          sParaState;       

    // TCMD_AFN_D_F3_EVENT_1
    // ��Ҫ�¼���������ǰֵ
    UINT16                usEc1;            

    // TCMD_AFN_D_F4_EVENT_2
    // һ���¼���������ǰֵ
    UINT16                usEc2;           

    // TCMD_AFN_D_F5_EVENT_STATE
    // �¼�״̬��־
    sTcEventState         sEventState;      

    // TCMD_AFN_D_F6_POWR_TIMES
    sTcPowerTimes         sPowerTimes;

    // TCMD_AFN_D_F9_STATE 
    // ״̬������λ��־
    sTcState              sState;           
    
    // TCMD_AFN_D_F17_POWR_HAVE_T  
    // ���й�����
    sTcPowerHaveT         sPowerHaveT;
    
    // TCMD_AFN_D_F18_POWR_NONE_T         
    // ���޹�����
    sTcPowerNoneT         sPowerNoneT;      

    // TCMD_AFN_D_F19_DEMD_TIME_D           
    // �������������ʱ��
    sTcDemandMaxD         sDemandMaxD;

    // TCMD_AFN_D_F20_DEMD_TIME_M            
    // ���������������ʱ��
    sTcDemandMaxM         sDemandMaxM;
  
    // TCMD_AFN_D_F21_FACTR_T 
    // �ܹ�������	
    sTcFactorT            sFactorT;

    // TCMD_AFN_D_F22_FACTR_A               
    // A�๦������
    sTcFactorA            sFactorA;
    
    // TCMD_AFN_D_F23_FACTR_B               
    // B�๦������
    sTcFactorB            sFactorB;
    
    // TCMD_AFN_D_F24_FACTR_C               
    // C�๦������
    sTcFactorC            sFactorC;
        
    // TCMD_AFN_D_F25_POWR_HAVE_A            
    // A���й�����
    sTcPowerHaveA sPowerHaveA;

    // TCMD_AFN_D_F26_POWR_HAVE_B            
    // B���й�����
    sTcPowerHaveB sPowerHaveB;

    // TCMD_AFN_D_F27_POWR_HAVE_C           
    // C���й�����
    sTcPowerHaveC sPowerHaveC;

    // TCMD_AFN_D_F28_POWR_NONE_A           
    // A���޹�����
    sTcPowerNoneA sPowerNoneA;

    // TCMD_AFN_D_F29_POWR_NONE_B           
    // B���޹�����
    sTcPowerNoneB sPowerNoneB;

    // TCMD_AFN_D_F30_POWR_NONE_C            
    // C���޹�����
    sTcPowerNoneC sPowerNoneC;

    // TCMD_AFN_D_F33_POWR_HAVE_FRTH         
    // �������й��ܵ���ʾ��
    sTcPowerHaveFrth sPowerHaveFrth;

    // TCMD_AFN_D_F34_POWR_HAVE_BACK         
    // �������й��ܵ���ʾ��
    sTcPowerHaveBack sPowerHaveBack;

    // TCMD_AFN_D_F35_POWR_NONE_FRTH         
    // �������޹��ܵ���ʾ��
    sTcPowerNoneFrth sPowerNoneFrth;

    // TCMD_AFN_D_F36_POWR_NONE_BACK         
    // �������޹��ܵ���ʾ��
    sTcPowerNoneBack sPowerNoneBack;

    // TCMD_AFN_D_F41_VOLT_A                 
    // A���ѹ
    sTcVoltA sVoltA;

    // TCMD_AFN_D_F42_VOLT_B                
    // B���ѹ
    sTcVoltB sVoltB;

    // TCMD_AFN_D_F43_VOLT_C                
    // C���ѹ
    sTcVoltC sVoltC;

    // TCMD_AFN_D_F44_VANGL_A                
    // A���ѹ��λ��
    sTcVAngleA sVAngleA;

    // TCMD_AFN_D_F45_VANGL_B                
    // B���ѹ��λ��
    sTcVAngleB sVAngleB;

    // TCMD_AFN_D_F46_VANGL_C                
    // C���ѹ��λ��
    sTcVAngleC sVAngleC;

    // TCMD_AFN_D_F47_VOLT_UBL               
    // ��ѹ��ƽ���
    sTcVoltUbl sVoltUbl;

    // TCMD_AFN_D_F48_CIRCLE_V               
    // �ܲ�
    sTcVCircle sVCircle;

    // TCMD_AFN_D_F49_ELEC_A                 
    // A�����
    sTcElecA sElecA;

    // TCMD_AFN_D_F50_ELEC_B                 
    // B�����
    sTcElecB sElecB;

    // TCMD_AFN_D_F51_ELEC_C                  
    // C�����
    sTcElecC sElecC;

    // TCMD_AFN_D_F52_ELEC_M                  
    // �����ߵ���
    sTcElecM sElecM;

    // TCMD_AFN_D_F53_EANGL_A                 
    // A�������λ��
    sTcEAngleA sEAngleA;

    // TCMD_AFN_D_F54_EANGL_B                 
    // B�������λ��
    sTcEAngleB sEAngleB;

    // TCMD_AFN_D_F55_EANGL_C                 
    // C�������λ��
    sTcEAngleC sEAngleC;

    // TCMD_AFN_D_F56_ELEC_UBL               
    // ������ƽ���
    sTcElecUbl sElecUbl;

    // TCMD_AFN_D_F57_VDMAX_A_TIME                
    // ��A���ѹ����ֵ�ͷ���ʱ��
    sTcVdMaxTimeA sVdMaxTimeA;

    // TCMD_AFN_D_F58_VDMAX_B_TIME            
    // ��B���ѹ����ֵ�ͷ���ʱ��
    sTcVdMaxTimeB sVdMaxTimeB;

    // TCMD_AFN_D_F59_VDMAX_C_TIME                 
    // ��C���ѹ����ֵ�ͷ���ʱ��
    sTcVdMaxTimeC sTcVdMaxTimeC;

    // TCMD_AFN_D_F60_IDMAX_A_TIME                
    // ��A���������ֵ�ͷ���ʱ��
    sTcIdMaxTimeA sIdMaxTimeA;

    // TCMD_AFN_D_F61_IDMAX_B_TIME            
    // ��B���������ֵ�ͷ���ʱ��
    sTcIdMaxTimeB sIdMaxTimeB;

    // TCMD_AFN_D_F62_IDMAX_C_TIME            
    // ��C���������ֵ�ͷ���ʱ��
    sTcIdMaxTimeC sIdMaxTimeC;
   
    // TCMD_AFN_D_F66_VDPP_TIME_B             
    // A���ѹԽ���������ۼ�ʱ��
    sTcVDppTimeA  sVDppTimeA;

    // TCMD_AFN_D_F66_VDPP_TIME_B             
    // B���ѹԽ���������ۼ�ʱ��
    sTcVDppTimeB  sVDppTimeB;

    // TCMD_AFN_D_F67_VDPP_TIME_C             
    // C���ѹԽ���������ۼ�ʱ��
    sTcVDppTimeC  sVDppTimeC;

    // TCMD_AFN_D_F68_VDNN_TIME_A            
    // A���ѹԽ���������ۼ�ʱ��
    sTcVDnnTimeA sVDnnTimeA;

    // TCMD_AFN_D_F69_VDNN_TIME_B            
    // B���ѹԽ���������ۼ�ʱ��
    sTcVDnnTimeB sVDnnTimeB;

    // TCMD_AFN_D_F70_VDNN_TIME_C            
    // C���ѹԽ���������ۼ�ʱ��
    sTcVDnnTimeC sVDnnTimeC;

    // TCMD_AFN_D_F73_VMPP_TIME_A            
    // A���ѹԽ���������ۼ�ʱ��
    sTcVMppTimeA  sVMppTimeA;

    // TCMD_AFN_D_F74_VMPP_TIME_B            
    // B���ѹԽ���������ۼ�ʱ��
    sTcVMppTimeB sVMppTimeB;

    // TCMD_AFN_D_F75_VMPP_TIME_C            
    // C���ѹԽ���������ۼ�ʱ��
    sTcVMppTimeC sVMppTimeC;

    // TCMD_AFN_D_F76_VMNN_TIME_A            
    // A���ѹԽ���������ۼ�ʱ��
    sTcVMnnTimeA sVMnnTimeA;

    // TCMD_AFN_D_F77_VMNN_TIME_B            
    // B���ѹԽ���������ۼ�ʱ��
    sTcVMnnTimeB sVMnnTimeB;

    // TCMD_AFN_D_F78_VMNN_TIME_C            
    // C���ѹԽ���������ۼ�ʱ��
    sTcVMnnTimeC sVMnnTimeC;

    // TCMD_AFN_D_F81_VABR_TOTL_A            
    // A���ѹ�ܻ�����
    sTcVabrTotalA sVabrTotalA;

    // TCMD_AFN_D_F82_VABR_TOTL_B            
    // B���ѹ�ܻ�����
    sTcVabrTotalB sVabrTotalB;

    // TCMD_AFN_D_F83_VABR_TOTL_C            
    // C���ѹ�ܻ�����
    sTcVabrTotalC sVabrTotalC;
    
    // TCMD_AFN_D_F84_EABR_TOTL_A            
    // A������ܻ�����
    sTcEabrTotalA sEabrTotalA;
    
    // TCMD_AFN_D_F85_EABR_TOTL_B            
    // B������ܻ�����
    sTcEabrTotalB sEabrTotalB;
    
    // TCMD_AFN_D_F86_EABR_TOTL_C            
    // C������ܻ�����
    sTcEabrTotalC sEabrTotalC;

    // TCMD_AFN_D_F89_VABR_OOD_A             
    // A���ѹ��λ�����
    sTcVabrOddA sVabrOddA;
    
    // TCMD_AFN_D_F90_VABR_EVN_A             
    // A���ѹż�λ�����
    sTcVabrEvnA sVabrEvnA;
    
    // TCMD_AFN_D_F91_VABR_OOD_B             
    // B���ѹ��λ�����
    sTcVabrOddB sVabrOddB;
    
    // TCMD_AFN_D_F92_VABR_EVN_B             
    // B���ѹż�λ�����
    sTcVabrEvnB sVabrEvnB;
    
    // TCMD_AFN_D_F93_VABR_OOD_C             
    // C���ѹ��λ�����
    sTcVabrOddC sVabrOddC;
    
    // TCMD_AFN_D_F94_VABR_EVN_C             
    // C���ѹż�λ�����
    sTcVabrEvnC sVabrEvnC;

    // TCMD_AFN_D_F97_EABR_OOD_A             
    // A�������λ�����
    sTcEabrOddA sEabrOddA;
    
    // TCMD_AFN_D_F98_EABR_EVN_A             
    // A�����ż�λ�����
    sTcEabrEvnA sEabrEvnA;
    
    // TCMD_AFN_D_F99_EABR_OOD_B             
    // B�������λ�����
    sTcEabrOddB sEabrOddB;
    
    // TCMD_AFN_D_F100_EABR_EVN_B             
    // B�����ż�λ�����
    sTcEabrEvnB sEabrEvnB;
    
    // TCMD_AFN_D_F101_EABR_OOD_C           
    // C�������λ�����
    sTcEabrOddC sEabrOddC;
    
    // TCMD_AFN_D_F102_EABR_EVN_C           
    // C�����ż�λ�����
    sTcEabrEvnC sEabrEvnC;
    
    // TCMD_AFN_D_F105_TFW_HAVE              
    // �ܻ����й�����  
    sTcTfwHave sTfwHave;

    // TCMD_AFN_D_F106_TFW_NONE                
    // �ܻ����޹�����
    sTcTfwNone sTfwNone;
    
    // TCMD_AFN_D_F107_THW_HAVE                
    // ��г���й�����
    sTcThwHave sThwHave;
    
    // TCMD_AFN_D_F108_THW_NONE                
    // �ܻ����޹�����
    sTcThwNone sThwNone;

    // TCMD_AFN_D_F113_HARM_VOLT_A            
    // A��N��г����ѹ
    sTcHarmVoltA sHarmVoltA;
    
    // TCMD_AFN_D_F114_HARM_VOLT_B          
    // B��N��г����ѹ
    sTcHarmVoltB sHarmVoltB;
    
    // TCMD_AFN_D_F115_HARM_VOLT_C          
    // C��N��г����ѹ
    sTcHarmVoltC sHarmVoltC;
    
    // TCMD_AFN_D_F116_HARM_ELEC_A             
    // A��N��г������
    sTcHarmElecA sHarmElecA;
    
    // TCMD_AFN_D_F117_HARM_ELEC_B            
    // B��N��г������
    sTcHarmElecB sHarmElecB;
    
    // TCMD_AFN_D_F118_HARM_ELEC_C            
    // C��N��г������
    sTcHarmElecC sHarmElecC;

    // TCMD_AFN_D_F121_HARM_VINC_A           
    // A��N��г����ѹ������
    sTcHarmVincA sHarmVincA;

    // TCMD_AFN_D_F122_HARM_VINC_B           
    // B��N��г����ѹ������
    sTcHarmVincB sHarmVincB;

    // TCMD_AFN_D_F123_HARM_VINC_C            
    // C��N��г����ѹ������
    sTcHarmVincC sHarmVincC;

    // TCMD_AFN_D_F124_HARM_EINC_A          
    // A��N��г������������
    sTcHarmEincA sHarmEincA;

    // TCMD_AFN_D_F125_HARM_EINC_B           
    // B��N��г������������
    sTcHarmEincB sHarmEincB;

    // TCMD_AFN_D_F126_HARM_EINC_C        
    // C��N��г������������
    sTcHarmEincC sHarmEincC;

    // TCMD_AFN_D_F129_FLS_SHRT_A             
    // A���ʱ����
    sTcFlashShortA sFlashShortA;
    
    // TCMD_AFN_D_F130_FLS_SHRT_B            
    // B���ʱ����
    sTcFlashShortB sFlashShortB;
    
    // TCMD_AFN_D_F131_FLS_SHRT_C     
    // C���ʱ����
    sTcFlashShortC sFlashShortC;
    
    // TCMD_AFN_D_F132_FLS_LONG_A       
    // A�೤ʱ����
    sTcFlashLongA sFlashLongA;
    
    // TCMD_AFN_D_F133_FLS_LONG_B   
    // B�೤ʱ����
    sTcFlashLongB sFlashLongB;
    
    // TCMD_AFN_D_F134_FLS_LONG_C             
    // C�೤ʱ����
    sTcFlashLongC sFlashLongC;
    
    // TCMD_AFN_D_F137_NELC_VALUE      
    // �ǵ�����
    sTcNelcValue sNelcValue;
}uTcFrezApp;

typedef struct
{
    sTcmdPn    sCmdPn;
    uTcFrezApp uApp[1];       // ucN��
}sTcFrezOne;

typedef struct
{
    sTcYMDhm            sTs;    // ���󶳽����������е����ݵ���ʼʱ��ts����ʱ������
    UINT16         usPeriod;    // �������� Ϊ��ʱ�����ʱ������Ϊ0��ʾɾ�����������
    eTcPeriodUnit     eUnit;    // �������ڵ�λ
    UINT8               ucN;    // ��������������ʾ�Զ�������Ϊ������足��Ĵ�����Ϊ0��ʾ���޴����� 
    UINT8               ucM;    // ����Ӧ���ϱ����Ķ����������������õ����ݵ�Ԫ��ʶ��m
    sTcFrezOne      sOne[1];    // ucM ��    
}sTcFrezAutoA, sTcAfn12f9A;

// ��֡��
#pragma pack(1)
typedef struct
{
    sTcFmt02_f          sTs;
    UINT16         usPeriod;     // �������� Ϊ��ʱ�����ʱ������Ϊ0��ʾɾ�����������
    UINT8             eUnit;     // �������ڵ�λ
    UINT8               ucN;     // ��������������ʾ�Զ�������Ϊ������足��Ĵ�����Ϊ0��ʾ���޴����� 
    UINT8               ucM;     // ����Ӧ���ϱ����Ķ����������������õ����ݵ�Ԫ��ʶ��m
    UINT8         ucDaDt[1];     // ����Ϊ�䳤
    
}sTcFrezAutoA_f, sTcAfn12f9A_f;
#pragma pack()

// ת������
eTcErr etc_trans_afn12f9_s2m(eTcTrans eTrans, void* pUser, void* pFrame, UINT16* pusLen);
///*} 
///*} 

/***************************************
 *  ͨ�ò��ַ�װ����  (�ͼ�����)
 *  �ڸú�����ʵ�ּ�������ܹ���
 *  �������͵�֡
 *  (1) �̶�֡
 *
 *  +------+------+------+------+------+------+------+------+
 *  |       ��ʼ�ַ�(10H)       |          �����ַ�         |
 *  |------+------+------+------+------+------+------+------|
 *  |          ������C          |                           |
 *  |------+------+------+------|                           |  
 *  |          ��ַ��A          |          �û�����         |
 *  |------+------+------+------|                           |  
 *  |        ��·�û�����       |                           |
 *  |------+------+------+------+------+------+------+------|  
 *  |          У���CS         |           ֡У��          |
 *  +------+------+------+------+------+------+------+------+  
 *  
 *  ��·�û�����
 *  +------+------+------+------+
 *  |         Э���ʶ          |
 *  +------+------+------+------+
 *
 *  (2) �ɱ�֡
 *
 *  +------+------+------+------+------+------+------+------+
 *  |        ��ʼ�ַ�(68H)      |                           |
 *  |------+------+------+------|                           |  
 *  |           ����L           |                           |
 *  |------+------+------+------|            ֡ͷ           |  
 *  |           ����L           |                           |
 *  |------+------+------+------|
                         |  
 *  |        ��ʼ�ַ�(68H)      |                           |
 *  |------+------+------+------+------+------+------+------|  
 *  |          ������C          |                           |
 *  |------+------+------+------|                           |  
 *  |          ��ַ��A          |        �û�����           |
 *  |------+------+------+------|                           |  
 *  |        ��·�û�����       |                           |
 *  |------+------+------+------+------+------+------+------|  
 *  |          У���CS         |          ֡У��           |
 *  |------+------+------+------+------+------+------+------|  
 *  |        �����ַ�(16H)      |         ֡������          |
 *  +------+------+------+------+------+------+------+------+  
 *
 *  ��·�û�����
 *  +------+------+------+------+
 *  |         Э���ʶ          |
 *  |------+------+------+------|
 *  |        Ӧ�ÿ�����AC       |
 *  |------+------+------+------|
 *  |       ���ݵ�Ԫ��ʶ1       |
 *  |------+------+------+------|
 *  |         ���ݵ�Ԫ1         |
 *  |------+------+------+------|
 *  |         .........         |
 *  |------+------+------+------|
 *  |       ���ݵ�Ԫ��ʶn       |
 *  |------+------+------+------|
 *  |         ���ݵ�Ԫn         |
 *  |------+------+------+------|
 *  |       ������Ϣ��AUX       |
 *  +------+------+------+------+
 *
 *  ˵��:
 *  У���CS:ȫ���û����ݵ��㷨��, �����ǽ�λ
 *
{*///
// �û�������
typedef struct
{
    sTcAddress    sAddress;      // ��ַ�� A
    sTctrl        sCtrl;         // ������ C
    //sTcAc         sAc;           // Ӧ�ÿ�����Ac(Tp Ec Afn)    // �����ϲ㴦��
    BOOL          bFixed;        // �̶�֡ ���� �ɱ�֡ 
    UINT16        usA2CsLen;     // ��addr �� Cs ֮������ݳ���
    UINT8         *pA2CsData;    // ��addr �� Cs ֮�����������
    
}sTcPackCommon;

// ����֡ͷ
// �̶�֡
#pragma pack(1)
typedef struct
{
    UINT8   f10;      // ��ʼ�ַ�(10H) 
    UINT16  usC;      // ������C
    sTcA_f  stA;      // ��ַ��A
    UINT8   ucV;      // ��Э��汾 ��ֵ TC_PROTO_VERSION    
    UINT8   ucS;      // У���CS
    UINT8   ucE;      // ������    
}sTcfHeadFixed;

// �ɱ�֡
typedef struct
{
    UINT8   f68;      // ��һ�� ��ʼ�ַ�(68H)
    UINT16  usL1;     // ��һ������L
    UINT16  usL2;     // �ڶ�������L
    UINT8   s68;      // �ڶ��� ��ʼ�ַ�(68H)
    UINT16  usC;      // ������C
    sTcA_f  stA;      // ��ַ��A
    UINT8   ucV;      // ��Э��汾 ��ֵ TC_PROTO_VERSION  
    UINT8   ucAc;     // Ӧ�ÿ�����AC
    
}sTcfHeadAlter;
#pragma pack()

// ������ͺ���(У�����ȫ���û����ݵ�������,�����ǽ�λ(ģ256))
UINT8 uctc_get_check_sum(UINT8 *pStartPos, UINT16 usLen);

// ��װÿ��֡�Ĺ������� 
eTcErr etc_pack_common(sTcPackCommon *psCommon,  UINT16 *pusLen, UINT8  *pOutBuf); 

// ������������
// ��������
eTcErr etc_unpack_common(sTcPackCommon *psUnpack, UINT8* pInBuf, UINT16 usLen);
///*}


/*******************************************************
 *  �ⲿ�ӿ�(�û�ֻ��������½ӿ�)
 *
{*///

/***************************************
 *  Э��ģ���ʼ��
 *  ʹ��Э��API��Ҫ�Ƚ��г�ʼ��
 *  
{*///
typedef struct
{
    eTcRole eRole;                  // ��ݣ���վ���Ǵ�վ
    UINT8   ucPermitDelayMinutes;   // ����ʱ��

#if  TC_CFG_SPT_CON   
    UINT8   aucPw[TC_PW_LEN];       // ��Ϣ��֤�� �������б�����
#endif

#if TC_CFG_ENCRYPT
    peTcEncryptFunc   EncryptFunc;  // ���ܽӿ�
    peTcDecryptFunc   DecryptFunc;  // ���ܽӿ�
#endif
    
}sTcInit;                           // Э���ʼ�����ݽṹ

// ��ʼ������
eTcErr eTcInit(sTcInit* psInit);
///*}

// �ж��Ƿ�����һ��Ч֡
eTcErr etcIsValidPack(const UINT8* pInBuf, UINT16 usLen, BOOL *pbFiexed);

// �ҵ���һ����Ч��λ�ü��䳤��
eTcErr etcFindValidPack(UINT8* pinBuf, UINT16 usLen, UINT16* pusFirstOff, UINT16* pusFirstLen);

/***************************************************************************
 *  ���ݵ�Ԫ Ӧ�ò����ݽṹ����
 *  ����������ͬ���͵����ݽṹ��ʱ��һ����
 *  
 *  �ն�����Ӧ��վ���ն˵Ĳ�������������ʱ,
 *    ���ն�û�������ĳ��������,��Ӧ������DT�Ķ�Ӧ��־λ�����
 *    ���ն˽���û��ĳ���������еĲ������ݣ���Ӧ�����������е���ȱ����
 *    ���ݵ�ÿ���ֽ���д��EEH����
 *    ע��:����չӦ�ò����ݵ�Ԫʱ,��Ҫ��ÿ��������Ϊÿ����������� 
 *         ��/�޵ı�ʶ ������һ��BOOL ����ʾ 
 *  
{*///
typedef union
{
    /**********************************
     * ����: ȷ��/����
     * AFN : 00H
    {*///
    // TCMD_AFN_0_F1_ALL_OK_DENY
    // ȫ��ȷ��/���ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ����ȷ��/����
    // ����:���ṹ
    // ����:���ṹ
    eTcResCode            eResCode;         

    // TCMD_AFN_0_F2_ONE_BY_ONE
    // �����ݵ�Ԫ��ʶȷ�Ϻͷ��ϣ����յ������е�ȫ�����ݵ�Ԫ��ʶ�������ȷ��/����
    // ����:�޴�����
    // ����:���ṹ
    sTcOnebyOne           sOneByOne;    
    ///*}
 
    /**********************************
     * ����: ��λ����
     * AFN : 01H
    {*///
    // TCMD_AFN_1_F1_HARD_INIT
    // TCMD_AFN_1_F2_DATA_INIT
    // TCMD_AFN_1_F3_FACTORY_RESET
    // TCMD_AFN_1_F4_PARA_INIT
    // ����:�޲���
    // ����:AFN_00

    // TCMD_AFN_1_F5_DATA_CLEAR
    // ����:
    sTcRtDataClear        sRtDataClear;    
    // ����:AFN_00
    ///*}

    /**********************************
     * ����: ��·�ӿڼ��
     * AFN : 02H
    {*///
    // TCMD_AFN_2_F1_LOG_IN
    // TCMD_AFN_2_F2_LOG_OUT
    // TCMD_AFN_2_F3_HEART_BEAT
    // ����:�޴�����
    // ����:�޲���

    // TCMD_AFN_2_F4_LINK_OK
    // ����:�޲���(�Ե�¼���˳���������Ӧ��)
    // ����:�޴�����
    ///*}

    /**********************************
     * ����: ���ò���
     * AFN : 04H
     * ����: AFN_00
    {*///
    // TCMD_AFN_4_F1_CON_IP_PORT 
    // (����)�����뽻���ն�IP��ַ�Ͷ˿�
    // ����:
    sTcDownCfg              sDownCfg;  

    // TCMD_AFN_4_F2_TML_UP_CFG
    // (����)����ն�����ͨ�Ų�������
    // ����:
    sTcTmlUpCfg            sTmlUpCfg; 

    // TCMD_AFN_4_F3_TML_AUTH_PARA
    // (����)����ն�����ͨ����Ϣ��֤��������
    // ����:
    sTcAuthPara            sAuthPara; 

    // TCMD_AFN_4_F4_TML_STATE_INPUT
    // (����)״̬���������
    // ����:
    sTcStateInput          sStateInput; 

    // TCMD_AFN_4_F5_TML_EVENT_CFG
    // (����)�¼���¼����
    // ����:
    sTcEventCfg            sEventCfg; 

    // TCMD_AFN_4_F17_FREZ_TASK_PARA 
    // (����)����������������
    // ����:
    sTcFrezTaskPara        sFrezTaskPara;  

    // TCMD_AFN_4_F25_ELEC_MP_CFG
    // (����)�������������ò���
    // ����:
    sTcElecMpCfg          sElecMpCfg; 

    // TCMD_AFN_4_F26_ELEC_MP_BASE
    // (����)�����������������
    // ����:
    sTcElecMpBase         sElecMpBase;     

    // TCMD_AFN_4_F27_ELEC_LMIT_PARA
    // (����)������������ֵ����
    // ����:
    sTcElecLimitPower      sElecLimitPower; 

    // TCMD_AFN_4_F28_ELEC_LMIT_FACTR
    // (����)�����������ܹ�����������
    // ����:
    sTcFactorLimit         sFactorLimit; 

    // TCMD_AFN_4_F29_ELEC_FIX_HARM
    // (����)����������г��������Խ�޶�ֵ
    // ����:
    sTcElecFixHarm         sElecFixHarm; 

    // TCMD_AFN_4_F30_ELEC_FLASH
    // (����)��������������Խ�޲���
    // ����:
    sTcElecFlash           sElecFlash; 

    // TCMD_AFN_4_F33_NELC_MP_CFG
    // (����)�ǵ������������ò���
    // ����:
    sTcNelcMpCfg          sNElecMpCfg; 

    // TCMD_AFN_4_F34_NELC_MP_PARA
    // (����)�ǵ����������������
    // ����:
    sTcNelcMpPara          sNelcMpPara;      

    // TCMD_AFN_4_F35_NELC_MP_LMIT
    // (����)�ǵ���������Խ�޲���
    // ����:
    sTcNelcMpLimit         sNelcMpLimit;  
    ///*}

    /**********************************
     * ����: TCMD_AFN_5_F1_CHECK_TIME
     * AFN : 05H
     * ����: AFN_00
    {*///
    // TCMD_AFN_5_F1_CHECK_TIME
    // Уʱ���� 
    // ����:
    sTcUerClock         sCheckClock; 

    // TCMD_AFN_5_F2_FREZ_TEMP
    // ��ʱ�������� 
    // ����:
    sTcFrezTemp         sFrezTemp; 

    // TCMD_AFN_5_F3_AUTO_SAY_ON
    // TCMD_AFN_5_F4_AUTO_SAY_OFF 
    // ����:�޲���

    // TCMD_AFN_5_F5_NX_MODEL_ACT
    // ��Чģ����Ч 
    // ����:
    sTcNxModelAct       sNxModelAct; 

    // TCMD_AFN_5_F6_NX_MODEL_CLR
    // ��Чģ����� 
    // ����:
    sTcNxModelClr       sNxModelClr; 

    // TCMD_AFN_5_F7_RQ_RESPN_ACT
    // ������Ӧ��Ϣ��Ч 
    // ����:
    sTcRqRespnAct       sRqRespnAct; 

    // TCMD_AFN_5_F8_RQ_RESPN_CLT
    // ������Ӧ��Ϣ��� 
    // ����:
    sTcRqRespnClr       sRqRespnClr; 

    // TCMD_AFN_5_F9_REPT_FREZ_ON
    // TCMD_AFN_5_F10_REPT_FREZ_OFF 
    // ����:�޲���

    // TCMD_AFN_5_F17_REMOTE_OFF
    // ң����բ 
    // ����:
    sTcRemoteOff        sRemoteOff; 

    // TCMD_AFN_5_F18_REMOTE_ON
    // �����բ 
    // ����:
    sTcRemoteOn         sRemoteOn; 
    ///*}
    
    /**********************************
     * ����: ��ѯ����
     * AFN : 0AH
    {*///
    // TCMD_AFN_A_F1_CON_IP_PORT
    // (��ѯ)�����뽻���ն�IP��ַ�Ͷ˿� 
    // ����:�޲���
    // ����:
    sTcDownCfg             sDownCfgA; 

    // TCMD_AFN_A_F2_TML_UP_CFG
    // (��ѯ)����ն�����ͨ�Ų�������
    // ����:�޲���
    // ����:
    sTcTmlUpCfg            sTmlUpCfgA;    

    // TCMD_AFN_A_F3_TML_AUTH_PARA
    // (��ѯ)����ն�����ͨ����Ϣ��֤��������
    // ����:�޲���
    // ����:
    sTcAuthPara            sAuthParaA; 

    // TCMD_AFN_A_F4_TML_STATE_INPUT
    // (��ѯ)״̬��������� 
    // ����:�޲���
    // ����:
    sTcStateInput          sStateInputA; 

    // TCMD_AFN_A_F5_TML_EVENT_CFG
    // (��ѯ)�¼���¼����
    // ����:�޲���
    // ����:
    sTcEventCfg            sEventCfgA; 

    // TCMD_AFN_A_F11_TML_SPRT_EVENT
    // (��ѯ)�ն�֧�ֵ��¼���¼��Ϣ
    // ����:�޲���
    // ����:
    sTcSuptEvent           sSuptEventA; 

    // TCMD_AFN_A_F12_ELEC_MP_INFO
    // (��ѯ)�����õ�����������Ϣ 
    // ����:�޲���
    // ����:
    sTcElecMpInfo          sElecMpInfoA; 

    // TCMD_AFN_A_F13_NELC_MP_INFO
    // (��ѯ)�����÷ǵ�����������Ϣ
    // ����:�޲���
    // ����:
    sTcNelcMpInfo          sNelcMpInfoA; 

    // TCMD_AFN_A_F14_TML_PROTO_SPRT
    // (��ѯ)����˿�֧�ֵ�ͨ��Э����Ϣ
    // ����:�޲���
    // ����:
    sTcTmlProtoSprt        sTmlProtoSprtA; 

    // TCMD_AFN_A_F15_TML_MODEL_VERSION
    // (��ѯ)�ն��ڸ�����ģ�����Ӳ���汾��Ϣ 
    // ����:�޲���
    // ����:
    sTcTmlModelVersion      sTmlModelVersionA; 

    // TCMD_AFN_A_F16_TML_VERSION
    // (��ѯ)�ն���Ӳ���汾��Ϣ
    // ����:�޲���
    // ����:
    sTcTmlVersion           sTmlVersionA; 

    // TCMD_AFN_A_F17_FREZ_TASK_PARA
    // (��ѯ)����������������
    // ����:�޲���
    // ����:
    sTcFrezTaskPara        sFrezTaskParaA;  

    // TCMD_AFN_A_F25_ELEC_MP_CFG
    // (��ѯ)�������������ò���
    // ����:�޲���
    // ����:
    sTcElecMpCfg          sElecMpCfgA; 

    // TCMD_AFN_A_F26_ELEC_MP_BASE
    // (��ѯ)�����������������
    // ����:�޲���
    // ����:
    sTcElecMpBase         sElecMpBaseA;     

    // TCMD_AFN_A_F27_ELEC_LMIT_PARA
    // (��ѯ)������������ֵ����
    // ����:�޲���
    // ����:
    sTcElecLimitPower      sElecLimitPowerA; 

    // TCMD_AFN_A_F28_ELEC_LMIT_FACTR
    // (��ѯ)�����������ܹ�����������
    // ����:�޲���
    // ����:
    sTcFactorLimit         sFactorLimitA; 

    // TCMD_AFN_A_F29_ELEC_FIX_HARM
    // (��ѯ)����������г��������Խ�޶�ֵ
    // ����:�޲���
    // ����:
    sTcElecFixHarm         sElecFixHarmA; 

    // TCMD_AFN_A_F30_ELEC_FLASH
    // (��ѯ)��������������Խ�޲���
    // ����:�޲���
    // ����:
    sTcElecFlash           sElecFlashA; 

    // TCMD_AFN_A_F33_NELC_MP_CFG
    // (��ѯ)�ǵ������������ò���
    // ����:�޲���
    // ����:
    sTcNelcMpCfg          sNElecMpCfgA; 

    // TCMD_AFN_A_F34_NELC_MP_PARA
    // (��ѯ)�ǵ����������������
    // ����:�޲���
    // ����:
    sTcNelcMpPara          sNelcMpParaA;      

    // TCMD_AFN_A_F35_NELC_MP_LMIT
    // (��ѯ)�ǵ���������Խ�޲���
    // ����:�޲���
    // ����:
    sTcNelcMpLimit         sNelcMpLimitA;  
    ///*}

    /**********************************
     * ����: ����(��ʱ�ϱ�)��������
     * AFN : 0CH
    {*///
    // TCMD_AFN_C_F1_FREZ_TEMP
    // ������ʱ��������Ķ�������
    // ����:�޲���
    // ����:��������ʵʱ������������б��ĸ�ʽ

    // TCMD_AFN_C_F9_FREZ_AUTO
    // ���󣨶�ʱ�ϱ���������������
    // ����:
    sTcFrezAutoQ   sFrezAutoQ;
    // ����:
    sTcFrezAutoA   sFrezAutoA;
    ///*}

    /**********************************
     * ����: ����ʵʱ����
     * AFN : 0CH
     * ����: �޲���
    {*///
    // TCMD_AFN_D_F1_CLOCK
    sTcUerClock           sUerClock;
    
    // TCMD_AFN_D_F2_PARA_STATE
    // ����״̬��־
    sTcParaState          sParaState;       

    // TCMD_AFN_D_F3_EVENT_1
    // ��Ҫ�¼���������ǰֵ
    UINT16                usEc1;            

    // TCMD_AFN_D_F4_EVENT_2
    // һ���¼���������ǰֵ
    UINT16                usEc2;           

    // TCMD_AFN_D_F5_EVENT_STATE
    // �¼�״̬��־
    sTcEventState         sEventState;      

    // TCMD_AFN_D_F6_POWR_TIMES
    sTcPowerTimes         sPowerTimes;

    // TCMD_AFN_D_F9_STATE 
    // ״̬������λ��־
    sTcState              sState;           
    
    // TCMD_AFN_D_F17_POWR_HAVE_T  
    // ���й�����
    sTcPowerHaveT         sPowerHaveT;
    
    // TCMD_AFN_D_F18_POWR_NONE_T         
    // ���޹�����
    sTcPowerNoneT         sPowerNoneT;      

    // TCMD_AFN_D_F19_DEMD_TIME_D           
    // �������������ʱ��
    sTcDemandMaxD         sDemandMaxD;

    // TCMD_AFN_D_F20_DEMD_TIME_M            
    // ���������������ʱ��
    sTcDemandMaxM         sDemandMaxM;
  
    // TCMD_AFN_D_F21_FACTR_T 
    // �ܹ�������	
    sTcFactorT            sFactorT;

    // TCMD_AFN_D_F22_FACTR_A               
    // A�๦������
    sTcFactorA            sFactorA;
    
    // TCMD_AFN_D_F23_FACTR_B               
    // B�๦������
    sTcFactorB            sFactorB;
    
    // TCMD_AFN_D_F24_FACTR_C               
    // C�๦������
    sTcFactorC            sFactorC;
        
    // TCMD_AFN_D_F25_POWR_HAVE_A            
    // A���й�����
    sTcPowerHaveA sPowerHaveA;
    
    // TCMD_AFN_D_F26_POWR_HAVE_B            
    // B���й�����
    sTcPowerHaveB sPowerHaveB;

    // TCMD_AFN_D_F27_POWR_HAVE_C           
    // C���й�����
    sTcPowerHaveC sPowerHaveC;

    // TCMD_AFN_D_F28_POWR_NONE_A           
    // A���޹�����
    sTcPowerNoneA sPowerNoneA;

    // TCMD_AFN_D_F29_POWR_NONE_B           
    // B���޹�����
    sTcPowerNoneB sPowerNoneB;

    // TCMD_AFN_D_F30_POWR_NONE_C            
    // C���޹�����
    sTcPowerNoneC sPowerNoneC;

    // TCMD_AFN_D_F33_POWR_HAVE_FRTH         
    // �������й��ܵ���ʾ��
    sTcPowerHaveFrth sPowerHaveFrth;

    // TCMD_AFN_D_F34_POWR_HAVE_BACK         
    // �������й��ܵ���ʾ��
    sTcPowerHaveBack sPowerHaveBack;

    // TCMD_AFN_D_F35_POWR_NONE_FRTH         
    // �������޹��ܵ���ʾ��
    sTcPowerNoneFrth sPowerNoneFrth;

    // TCMD_AFN_D_F36_POWR_NONE_BACK         
    // �������޹��ܵ���ʾ��
    sTcPowerNoneBack sPowerNoneBack;

    // TCMD_AFN_D_F41_VOLT_A                 
    // A���ѹ
    sTcVoltA sVoltA;

    // TCMD_AFN_D_F42_VOLT_B                
    // B���ѹ
    sTcVoltB sVoltB;

    // TCMD_AFN_D_F43_VOLT_C                
    // C���ѹ
    sTcVoltC sVoltC;

    // TCMD_AFN_D_F44_VANGL_A                
    // A���ѹ��λ��
    sTcVAngleA sVAngleA;

    // TCMD_AFN_D_F45_VANGL_B                
    // B���ѹ��λ��
    sTcVAngleB sVAngleB;

    // TCMD_AFN_D_F46_VANGL_C                
    // C���ѹ��λ��
    sTcVAngleC sVAngleC;

    // TCMD_AFN_D_F47_VOLT_UBL               
    // ��ѹ��ƽ���
    sTcVoltUbl sVoltUbl;

    // TCMD_AFN_D_F48_CIRCLE_V               
    // �ܲ�
    sTcVCircle sVCircle;

    // TCMD_AFN_D_F49_ELEC_A                 
    // A�����
    sTcElecA sElecA;

    // TCMD_AFN_D_F50_ELEC_B                 
    // B�����
    sTcElecB sElecB;

    // TCMD_AFN_D_F51_ELEC_C                  
    // C�����
    sTcElecC sElecC;

    // TCMD_AFN_D_F52_ELEC_M                  
    // �����ߵ���
    sTcElecM sElecM;

    // TCMD_AFN_D_F53_EANGL_A                 
    // A�������λ��
    sTcEAngleA sEAngleA;

    // TCMD_AFN_D_F54_EANGL_B                 
    // B�������λ��
    sTcEAngleB sEAngleB;

    // TCMD_AFN_D_F55_EANGL_C                 
    // C�������λ��
    sTcEAngleC sEAngleC;

    // TCMD_AFN_D_F56_ELEC_UBL               
    // ������ƽ���
    sTcElecUbl sElecUbl;

    // TCMD_AFN_D_F57_VDMAX_A_TIME                
    // ��A���ѹ����ֵ�ͷ���ʱ��
    sTcVdMaxTimeA sVdMaxTimeA;

    // TCMD_AFN_D_F58_VDMAX_B_TIME            
    // ��B���ѹ����ֵ�ͷ���ʱ��
    sTcVdMaxTimeB sVdMaxTimeB;

    // TCMD_AFN_D_F59_VDMAX_C_TIME                 
    // ��C���ѹ����ֵ�ͷ���ʱ��
    sTcVdMaxTimeC sTcVdMaxTimeC;

    // TCMD_AFN_D_F60_IDMAX_A_TIME                
    // ��A���������ֵ�ͷ���ʱ��
    sTcIdMaxTimeA sIdMaxTimeA;

    // TCMD_AFN_D_F61_IDMAX_B_TIME            
    // ��B���������ֵ�ͷ���ʱ��
    sTcIdMaxTimeB sIdMaxTimeB;

    // TCMD_AFN_D_F62_IDMAX_C_TIME            
    // ��C���������ֵ�ͷ���ʱ��
    sTcIdMaxTimeC sIdMaxTimeC;
   
    // TCMD_AFN_D_F66_VDPP_TIME_B             
    // A���ѹԽ���������ۼ�ʱ��
    sTcVDppTimeA  sVDppTimeA;

    // TCMD_AFN_D_F66_VDPP_TIME_B             
    // B���ѹԽ���������ۼ�ʱ��
    sTcVDppTimeB  sVDppTimeB;

    // TCMD_AFN_D_F67_VDPP_TIME_C             
    // C���ѹԽ���������ۼ�ʱ��
    sTcVDppTimeC  sVDppTimeC;

    // TCMD_AFN_D_F68_VDNN_TIME_A            
    // A���ѹԽ���������ۼ�ʱ��
    sTcVDnnTimeA sVDnnTimeA;

    // TCMD_AFN_D_F69_VDNN_TIME_B            
    // B���ѹԽ���������ۼ�ʱ��
    sTcVDnnTimeB sVDnnTimeB;

    // TCMD_AFN_D_F70_VDNN_TIME_C            
    // C���ѹԽ���������ۼ�ʱ��
    sTcVDnnTimeC sVDnnTimeC;

    // TCMD_AFN_D_F73_VMPP_TIME_A            
    // A���ѹԽ���������ۼ�ʱ��
    sTcVMppTimeA  sVMppTimeA;

    // TCMD_AFN_D_F74_VMPP_TIME_B            
    // B���ѹԽ���������ۼ�ʱ��
    sTcVMppTimeB sVMppTimeB;

    // TCMD_AFN_D_F75_VMPP_TIME_C            
    // C���ѹԽ���������ۼ�ʱ��
    sTcVMppTimeC sVMppTimeC;

    // TCMD_AFN_D_F76_VMNN_TIME_A            
    // A���ѹԽ���������ۼ�ʱ��
    sTcVMnnTimeA sVMnnTimeA;

    // TCMD_AFN_D_F77_VMNN_TIME_B            
    // B���ѹԽ���������ۼ�ʱ��
    sTcVMnnTimeB sVMnnTimeB;

    // TCMD_AFN_D_F78_VMNN_TIME_C            
    // C���ѹԽ���������ۼ�ʱ��
    sTcVMnnTimeC sVMnnTimeC;

    // TCMD_AFN_D_F81_VABR_TOTL_A            
    // A���ѹ�ܻ�����
    sTcVabrTotalA sVabrTotalA;

    // TCMD_AFN_D_F82_VABR_TOTL_B            
    // B���ѹ�ܻ�����
    sTcVabrTotalB sVabrTotalB;

    // TCMD_AFN_D_F83_VABR_TOTL_C            
    // C���ѹ�ܻ�����
    sTcVabrTotalC sVabrTotalC;
    
    // TCMD_AFN_D_F84_EABR_TOTL_A            
    // A������ܻ�����
    sTcEabrTotalA sEabrTotalA;
    
    // TCMD_AFN_D_F85_EABR_TOTL_B            
    // B������ܻ�����
    sTcEabrTotalB sEabrTotalB;
    
    // TCMD_AFN_D_F86_EABR_TOTL_C            
    // C������ܻ�����
    sTcEabrTotalC sEabrTotalC;

    // TCMD_AFN_D_F89_VABR_OOD_A             
    // A���ѹ��λ�����
    sTcVabrOddA sVabrOddA;
    
    // TCMD_AFN_D_F90_VABR_EVN_A             
    // A���ѹż�λ�����
    sTcVabrEvnA sVabrEvnA;
    
    // TCMD_AFN_D_F91_VABR_OOD_B             
    // B���ѹ��λ�����
    sTcVabrOddB sVabrOddB;
    
    // TCMD_AFN_D_F92_VABR_EVN_B             
    // B���ѹż�λ�����
    sTcVabrEvnB sVabrEvnB;
    
    // TCMD_AFN_D_F93_VABR_OOD_C             
    // C���ѹ��λ�����
    sTcVabrOddC sVabrOddC;
    
    // TCMD_AFN_D_F94_VABR_EVN_C             
    // C���ѹż�λ�����
    sTcVabrEvnC sVabrEvnC;

    // TCMD_AFN_D_F97_EABR_OOD_A             
    // A�������λ�����
    sTcEabrOddA sEabrOddA;
    
    // TCMD_AFN_D_F98_EABR_EVN_A             
    // A�����ż�λ�����
    sTcEabrEvnA sEabrEvnA;
    
    // TCMD_AFN_D_F99_EABR_OOD_B             
    // B�������λ�����
    sTcEabrOddB sEabrOddB;
    
    // TCMD_AFN_D_F100_EABR_EVN_B             
    // B�����ż�λ�����
    sTcEabrEvnB sEabrEvnB;
    
    // TCMD_AFN_D_F101_EABR_OOD_C           
    // C�������λ�����
    sTcEabrOddC sEabrOddC;
    
    // TCMD_AFN_D_F102_EABR_EVN_C           
    // C�����ż�λ�����
    sTcEabrEvnC sEabrEvnC;
    
    // TCMD_AFN_D_F105_TFW_HAVE              
    // �ܻ����й�����  
    sTcTfwHave sTfwHave;

    // TCMD_AFN_D_F106_TFW_NONE                
    // �ܻ����޹�����
    sTcTfwNone sTfwNone;
    
    // TCMD_AFN_D_F107_THW_HAVE                
    // ��г���й�����
    sTcThwHave sThwHave;
    
    // TCMD_AFN_D_F108_THW_NONE                
    // �ܻ����޹�����
    sTcThwNone sThwNone;
    
    // TCMD_AFN_D_F113_HARM_VOLT_A            
    // A��N��г����ѹ
    sTcHarmVoltA sHarmVoltA;
    
    // TCMD_AFN_D_F114_HARM_VOLT_B          
    // B��N��г����ѹ
    sTcHarmVoltB sHarmVoltB;
    
    // TCMD_AFN_D_F115_HARM_VOLT_C          
    // C��N��г����ѹ
    sTcHarmVoltC sHarmVoltC;
    
    // TCMD_AFN_D_F116_HARM_ELEC_A             
    // A��N��г������
    sTcHarmElecA sHarmElecA;
    
    // TCMD_AFN_D_F117_HARM_ELEC_B            
    // B��N��г������
    sTcHarmElecB sHarmElecB;
    
    // TCMD_AFN_D_F118_HARM_ELEC_C            
    // C��N��г������
    sTcHarmElecC sHarmElecC;

    // TCMD_AFN_D_F121_HARM_VINC_A           
    // A��N��г����ѹ������
    sTcHarmVincA sHarmVincA;

    // TCMD_AFN_D_F122_HARM_VINC_B           
    // B��N��г����ѹ������
    sTcHarmVincB sHarmVincB;

    // TCMD_AFN_D_F123_HARM_VINC_C            
    // C��N��г����ѹ������
    sTcHarmVincC sHarmVincC;

    // TCMD_AFN_D_F124_HARM_EINC_A          
    // A��N��г������������
    sTcHarmEincA sHarmEincA;

    // TCMD_AFN_D_F125_HARM_EINC_B           
    // B��N��г������������
    sTcHarmEincB sHarmEincB;

    // TCMD_AFN_D_F126_HARM_EINC_C        
    // C��N��г������������
    sTcHarmEincC sHarmEincC;

    // TCMD_AFN_D_F129_FLS_SHRT_A             
    // A���ʱ����
    sTcFlashShortA sFlashShortA;
    
    // TCMD_AFN_D_F130_FLS_SHRT_B            
    // B���ʱ����
    sTcFlashShortB sFlashShortB;
    
    // TCMD_AFN_D_F131_FLS_SHRT_C     
    // C���ʱ����
    sTcFlashShortC sFlashShortC;
    
    // TCMD_AFN_D_F132_FLS_LONG_A       
    // A�೤ʱ����
    sTcFlashLongA sFlashLongA;
    
    // TCMD_AFN_D_F133_FLS_LONG_B   
    // B�೤ʱ����
    sTcFlashLongB sFlashLongB;
    
    // TCMD_AFN_D_F134_FLS_LONG_C             
    // C�೤ʱ����
    sTcFlashLongC sFlashLongC;

    // TCMD_AFN_D_F137_NELC_VALUE      
    // �ǵ�����
    sTcNelcValue sNelcValue;
    ///*}
  
    // ������ռλ ��Ӧ������
    UINT8            ucRev[TC_UNIT_DATA_MAX];
    
}uTcApp;

/***************************************
 *  ֡�������ݽṹ �û���  (�ͼ�����)
 *  ���ڷ�װ�����
 *  �䳤�ṹ
{*///
typedef struct
{
    sTcPnFn    sPnFn;
    uTcApp     *puApp[TC_PN_INDEX_MAX][TC_FN_INDEX_MAX];   // �������64�����ݵ�Ԫ��ָ��
}sTcBaseData;

typedef struct
{
    sTcAddress    sAddress;        // ��ַ�� A
    sTctrl        sCtrl;           // ������ C
    BOOL          bFixed;          // �̶�֡���ǿɱ�֡ 

    // �ɱ�֡���������ֶ�
    sTcAc         sAc;             // Ӧ�ÿ�����Ac(Tp Ec Afn)
    sTcEc         sEc;             // �¼�������  ������ sTcAc ���е�bEc (ֻ���������б�����)
    sTcTp         sTp;             // ʱ���ǩ    ������ sTcAc ���е�bTp 
    UINT8         aPw[TC_PW_LEN];  // ��Ϣ��֤��  (ֻ��������Ҫ�����б�����)
    
    // ���ݵ�Ԫ��  �䳤��
    UINT16        usNum;           // ���ݵ�Ԫ��ĸ���
    sTcBaseData   sData[1];        // ���ݵ�Ԫ��
}stcBaskPack;

void vtc_free_base_data(sTcBaseData* pBaseData, INT32 Num);

// ��֡����
eTcErr etc_pack_base(stcBaskPack* psPack, UINT8* pOutBuf, UINT16* pusLen);   

// ��֡����
eTcErr etc_unPack_base(stcBaskPack *psUnpack, UINT8* pInBuf, UINT16 usLen);
///*}

/***************************************
 *  ���ݵ�Ԫ��ʶ���Ӧ�����ݵ�Ԫ (�߼�����)
 *  
 * ���ݵ�ԪΪ�����ݵ�Ԫ��ʶ����֯������,��������������ȡ�
 * ������֯��˳�������ɢ��ʽ
 * ���������ʶ ���ݵ�Ԫ һһ��Ӧ�ķ�ʽ
 * 
{*///
typedef struct
{
    eTcmd        eCmd;        // ������
    UINT16       usPN;        // Pn (0 <= pn <= 2040 )
    BOOL         bApp;        // �Ƿ������ݵ�Ԫ
    uTcApp       uApp;        // ��Ӧ��ͬ����������, ������������, Ӧ�ò�����ʱ��ʱ��
    
}sTcData;
///*}

/***************************************
 *  ��֡���֡(ͨ��) �û������ݽṹ (�߼�����)
 *  ���ڷ�װ�����װ 
 *  �䳤�ṹ
{*///
typedef struct
{    
    sTcAddress    sAddress;        // ��ַ�� A
    sTctrl        sCtrl;           // ������ C
    BOOL          bFixed;          // �̶�֡���ǿɱ�֡ 

    // �ɱ�֡�����¿�ѡ�ֶ�
    sTcAc         sAc;             // Ӧ�ÿ�����Ac(Tp Ec Afn)
    sTcEc         sEc;             // �¼�������  ������ sTcAc ���е�bEc (ֻ���������б�����)
    sTcTp         sTp;             // ʱ���ǩ    ������ sTcAc ���е�bTp 
    BOOL          bPw;             // �Ƿ���Pw�ֶ�(ֻ������Ҫ�����еı�����)
    UINT8         aPw[TC_PW_LEN];  // ��Ϣ��֤��  (ֻ��������Ҫ�����б�����)

    // ���ݵ�Ԫ��  �䳤��
    UINT16        usNum;           // ���ݵ�Ԫ��ĸ���
    sTcData       sData[1];        // usNum�����ݵ�Ԫ��
    
}stcPack;

// �߼��ӿ�(�û�ʹ��)
// ��װ����
eTcErr etcPack(stcPack* psPack, UINT8* pOutBuf, UINT16* pusLen);   

// ��֡����
eTcErr etcUnPack(stcPack *psUnpack, UINT8* pInBuf, UINT16 usLen);
///*}

/***************************************
 *  �ն˲�ṹ��ӿ�(�������಻��ע) 
 *  ����:
 *   (1)�߼������ն˲�ı䳤�ṹ
 *   (2)�����ն˲಻��Ҫ���ĵ��ֶ�
 *   (3)ʵ���ն˲����ݽṹ���ĵķ�֡����װ 
 *  ע��:
 *   (1)
 *
{*///
typedef struct
{
    sTcAddress    sAddress;        // ��ַ�� A
    BOOL          bReSend;         // �Ƿ�Ϊ�ط�  TRUE �ط���֡���������Զ�����1 FALSE ������1
    BOOL          bActive;         // �Ƿ�Ϊ�����ϱ� (����¼���������˳���¼��1��2�����������ϱ�ʱΪ��)
    UINT16        usNum;           // �ð��к���������ĸ��� ������һ��������
    sTcData       sData[1];        // usNum�����ݵ�Ԫ��
}sTcPackTml;

// ��װ����
eTcErr etcPackTml(sTcPackTml* psPack, UINT8* pOutBuf, UINT16* pusLen);   

// ��֡����
eTcErr etcUnPackTml(sTcPackTml *psUnpack, UINT8* pInBuf, UINT16 usLen);
///*}

/***************************************
 *  ��������ṹ��ӿ�(�ն˲಻��ע) 
 *  ����:
 *   (1)�߼�����������ı䳤�ṹ
 *   (2)���μ������಻��Ҫ���ĵ��ֶ�
 *   (3)ʵ�ּ����������ݽṹ���ĵķ�֡����װ 
 *  ע��:
 *   (1)��������,��Ҫά��ÿ��ͨ���ն˵�ucPSEQ
 *
 *
{*///
typedef struct
{
    sTcAddress    sAddress;        // ��ַ�� A
    UINT8         ucPSEQ;          // ����֡��� PSEQ
    UINT8         ucRSEQ;          // ��Ӧ֡��� RSEQ
    UINT8         aPw[TC_PW_LEN];  // ��Ϣ��֤��  (ֻ��������Ҫ�����б�����)

    // ���ݵ�Ԫ��  �䳤��
    UINT16        usNum;           // ���ݵ�Ԫ��ĸ���
    sTcData       sData[1];        // usNum�����ݵ�Ԫ��

}sTcPackCon;

// ��װ����
eTcErr etcPackCon(sTcPackCon* psPack, UINT8* pOutBuf, UINT16* pusLen);   

// ��֡����
eTcErr etcUnPackCon(sTcPackCon *psUnpack, UINT8* pInBuf, UINT16 usLen);
///*}
#endif // _GBNX_32_API_H_
