#ifndef SSCARDDRIVER_H_
#define SSCARDDRIVER_H_ 


#ifdef __cplusplus
extern "C" {
#endif

	long __stdcall iReadCard(int iType,int iAuthType,char* pCardInfo,char* pFileAddr,char *pOutInfo); 
	long __stdcall iWriteCard(int iType,char* pCardInfo,char* pFileAddr,char* pWriteData,char *pOutInfo);
	long __stdcall iReadCardBas(int iType,char *pOutInfo);	
	long __stdcall iVerifyPIN(int iType,char* pOutInfo);	
	long __stdcall iChangePIN(int iType,char* pOutInfo);
	long __stdcall iReloadPIN(int iType,char *pCardInfo,char* pOutInfo);
	long __stdcall iUnblockPIN(int iType,char*pCardInfo,char* pOutInfo);
	long __stdcall iDoDebit(int iType,char*pCardInfo,char* pPayInfo,char* pOutInfo);
	long __stdcall iReadDebitRecord(int iType,char* pOutInfo);

	long __stdcall iReadCardBas_HSM_Step1(int iType,char *pOutInfo);
	long __stdcall iReadCardBas_HSM_Step1To2(int iType,char*pAuthSourceInfo,char *pAuthInfo);
	long __stdcall iReadCardBas_HSM_Step2(char *pKey,char* pOutInfo);

	long __stdcall iReadCard_HSM_Step1(int iType,char* pCardInfo,char *pFileAddr,char *pOutInfo);
	long __stdcall iReadCard_HSM_Step1To2(int iType,char*pAuthSourceInfo,char *pAuthInfo);
	long __stdcall iReadCard_HSM_Step2(char* pKey,char *pOutInfo);

	long __stdcall iWriteCard_HSM_Step1(int iType,char* pCardInfo,char *pFileAddr,char *pOutInfo);
	long __stdcall iWriteCard_HSM_Step1To2(int iType,char*pAuthSourceInfo,char *pAuthInfo);
	long __stdcall iWriteCard_HSM_Step2(char* pKey,char *pWriteData,char *pOutInfo);

	long __stdcall iReloadPIN_HSM_Step1(int iType,char*pCardInfo,char *pOutInfo);
	long __stdcall iReloadPIN_HSM_Step1To2(int iType,char*pAuthSourceInfo,char *pAuthInfo);
	long __stdcall iReloadPIN_HSM_Step2(char* pKey,char *pOutInfo);
	long __stdcall iReloadPIN_HSM_Step2To3(char* pKeyData,char *pOutInfo);
	long __stdcall iReloadPIN_HSM_Step3(char* pKey,  char*pOutInfo);

	long __stdcall iUnblockPIN_HSM_Step1(int iType,char*pCardInfo,char *pOutInfo);
	long __stdcall iUnblockPIN_HSM_Step1To2(int iType,char*pAuthSourceInfo,char *pAuthInfo) ;
	long __stdcall iUnblockPIN_HSM_Step2(char* pKey,char *pOutInfo);
	long __stdcall iUnblockPIN_HSM_Step2To3(char* pKeyData,char *pOutInfo);
	long __stdcall iUnblockPIN_HSM_Step3(char* pKeyData,char *pOutInfo);

	long __stdcall iDoDebit_HSM_Step1(int iType,char *pCardInfo,char *pPayInfo,char *pOutInfo);
	long __stdcall iDoDebit_HSM_Step1To2(char *pMAC1Sourceinfo,char *pMAC1);
	long __stdcall iDoDebit_HSM_Step2(char *pKey,char *pOutInfo);

/***************************************************
**  Function:        iReadCardPublicInfo 
**  Description:     ��ȡ�籣������������Ϣ��
**  Parameter[out]:  KSBM: ��ʶ����
                     KLB: �����
					 GFBB: �淶�汾
					 JGBM: ��ʼ����������
					 FKRQ: ��������
					 KYXQ: ����Ч��
					 KH: ����
**  Parameter[out]:  pErrMsg: ��������
**  Return:          int: �����ɹ�����0�����򷵻�С��0�Ĵ����룬            
***************************************************/	
int __stdcall iReadCardPublicInfo(char* KSBM, char* KLB, char* GFBB, char* JGBM, char* FKRQ, char* KYXQ, char* KH, char* pErrMsg);

/***************************************************
**  Function:        iReadPersonPublicInfo 
**  Description:     ��ȡ�籣���ֿ��˹�����Ϣ��  
**  Parameter[out]:  SHBZHM: ��ᱣ�Ϻ���
**                   XM: ����
**                   XB: �Ա�
**                   MZ: ����
**                   CSD: ������
**                   CSRQ: ��������
**                   pErrMsg: ��������
**  Return:          int: �����ɹ�����0�����򷵻�С��0�Ĵ����룬            
***************************************************/	
int __stdcall iReadPersonPublicInfo(char* SHBZHM,char* XM,char* XB,char* MZ,char* CSD,char* CSRQ,char* pErrMsg);

/***************************************************
**  Function:        iReadIdentityInfo
**  Description:     ��ȡ����֤��Ϣ
**  Parameter[in]:   pcPhotoPath����Ƭ�ļ�����·������Ϊ���򲻱��档
**  Parameter[out]:  pName: ����
**                   pGeneder: �Ա�������Ϣ��
**                   pNation: ���壨������Ϣ��
**                   pBirth: ��������
**                   pAddress: ������ַ
**                   pCertNO: ���֤��
**                   pDepartment: ǩ������
**                   pMadedDate: ��������
**                   pExpire: ������Ч��
**                   pPhotoBuffer: ��Ƭ������.pcPhotoPathΪ�ղ�����
**                   pErrMsg������ִ�н����������Ϣ�� �硱�ɹ�����
**  Return:          int:�����ɹ�����0�����򷵻�С��0�Ĵ�����          
***************************************************/	
int __stdcall iReadIdentityInfo(const char* pcPhotoPath, char* pName, char* pGeneder,	char* pNation,char* pBirth,char* pAddress,char* pCertNO,char* pDepartment,char* pMadedDate,char* pExpire,	char* pPhotoBuffer, char* pErrMsg);

/***************************************************
**  Function:        iReadPBOCAccount
**  Description:     �������˺�
**  Parameter[out]:  pOutData�������˻���Ϣ
**                   pErrmsg������ִ�н����������Ϣ�� �硱�ɹ�����
**  Return:          int:�����ɹ�����0�����򷵻�С��0�Ĵ����룬pErrmsgΪ����������           
***************************************************/
int __stdcall iReadPBOCAccount(char* pOutData, char* pErrMsg);

/***************************************************
**  Function:        iReadPBOCAccount
**  Description:     �����п������˻���
**  Parameter[out]:  pOutData�������˻���Ϣ
					 pBankNoSnr �����˻����к�,������˻�һ��ȷ���˻�Ψһ��
**                   pErrmsg������ִ�н����������Ϣ�� �硱�ɹ�����
**  Return:          int:�����ɹ�����0�����򷵻�С��0�Ĵ����룬pErrmsgΪ����������           
***************************************************/
int __stdcall iReadPBOCAccount_Ext(char* pBankNo, char* pBankNoSnr, char* pErrMsg);

/***************************************************
**  Function:        iPKBGetPIN
**  Description:     ��ȡ�������������Ϣ
**  Parameter[out]:  pcErrMsg������ִ�н����������Ϣ�� �硱�ɹ�����
**  Return:          int:�����ɹ�������0�����򣬷���С��0�Ĵ����룬pcErrMsgΪ����������
**  Author:          YJZ
**  Date:            2015/12/24
**  Note:            �˺�������ҪPSAM��
***************************************************/
int __stdcall iPKBGetPIN (char* pcPass,char* pcErrMsg);

/***************************************************
**  Function:        iVerifyPIN
**  Description:     У�����PIN��
**  Parameter[in]:   pchPIN������PIN��
**  Parameter[out]:  pcErrMsg������ִ�н����������Ϣ�� �硱�ɹ�����
**  Return:          int:�����ɹ�������0�����򣬷���С��0�Ĵ����룬pcErrMsgΪ����������
**  Author:          YJZ
**  Date:            2015/12/24
**  Note:            �˺�������ҪPSAM��
***************************************************/
int __stdcall iPKBVerifyPIN(const char* pchPIN, char* pcErrMsg);

/***************************************************
**  Function:        iChangePIN
**  Description:     �޸ĸ���PIN��
**  Parameter[in]:   pcOldPIN��ԭ����
**                   pcNewPIN��������
**  Parameter[out]:  pcErrMsg������ִ�н����������Ϣ�� �硱�ɹ�����
**  Return:          int:�����ɹ�������0�����򣬷���С��0�Ĵ����룬pcErrMsgΪ����������
**  Author:          YJZ
**  Date:            2015/12/24
**  Note:            �˺�������ҪPSAM��
***************************************************/
int __stdcall iPKBChangePIN(const char* pcOldPIN, const char* pcNewPIN, char* pcErrMsg);

/***************************************************
**  Function:        DeviceBeep
**  Description:     �豸����
**  Parameter[in]:   time: ��������ʱ��(ms),����ȡֵ10
**  Parameter[out]:  pErrMsg: ����ִ�н����������Ϣ�� �硱�ɹ�����
**  Return:          int:�����ɹ�������0�����򣬷���С��0�Ĵ�����
***************************************************/
int __stdcall DeviceBeep(int time, char *pErrMsg);

/******************************************************************************************************
**  ��������:        iReadHealthyBasicInfo
**  ��������:        ��ȡ������������Ϣ����DDF1EF05�µ�������Ϣ
**  �������:        hDev:�豸���
**  �������:        KH:���ţ�XM��������XB���Ա�MZ�����壻CSRQ���������ڣ�SFZH�����֤�ţ�pcAddress�����᣻JKDABH��������������ţ�XLHZKH����ũ��֤���ţ�pErrMsg��������Ϣ
**  ����ֵ:          int:�ɹ�������0��ʧ�ܷ�����Ӧ�Ĵ�����
**  ��ע:            ����ʱ��ΪYYYYMMDD��ʽ�����ţ���������֤�Ż���֤������һ��        
******************************************************************************************************/
int __stdcall iReadHealthyBasicInfo(char * KH, char * XM, char * XB, char * MZ, char * CSRQ, char * SFZH, 
									char * pcAddress, char *JKDABH, char *XLHZKH, char *pErrMsg);

/******************************************************************************************************
**  Function:        iCheckCard
**  Description:     �ж��Ǿ��񽡿���������оƬ������ҽԺM1S50�;��￨
**  Return:          int:����1��ʾҽԺ���￨������2��ʾ����ʡ���񽡿���������3��ʾ�籣����
**                       ����4��ʾ����֤������5��ʾ�޿�������6��ʾ���п�������ֵδ���壻
**  Note:
******************************************************************************************************/
int __stdcall iCheckCard(void);

/**********************************************************************************
**  Function:     ReadICCardNum
**  Description:  ��ȡ����������
**  Parameter[in]:ICType    ͨѶ��ʽ:1��ʾ�Ӵ�ʽ��2��ʾ�ǽӴ�ʽ������ֵ��ʾ�Զ���Ӧ��֧�ֽӴ��ͷǽӴ�����                  
**  Parameter[out]:*cardnumber    ��ȡ������������
                   *pcErrMsg    ����ʱ���صĴ�����Ϣ
**  Return:       �ɹ��򷵻�0�����򷵻�С��0�Ĵ�����
**  Note:         
**********************************************************************************/
int __stdcall ReadICCardNum(int ICType, char* cardnumber, char* pcErrMsg);


/***************************************************
**  Function:        iReadMagCard
**  Description:     ��ȡ���������ţ�������ʽ��
**  Parameter1[out]:  *CardNumber    ��ȡ�����������š�
**  Parameter2[out]:  pcErrMsg������ִ�н����������Ϣ�� �硱�ɹ���
**  Return:          �ɹ��򷵻�0�����򷵻�С��0�Ĵ�����
**  Author:          ʷ���
**  Date:            2015/05/09
***************************************************/
int __stdcall iReadMagCard(unsigned char ctime ,char* CardNumber, char* pcErrMsg);
/***************************************************
**  Function:        iReadMagCard
**  Description:     ��ȡ�������ŵ���Ϣ
**  Parameter1[out]:  *pTrack1Data    1�ŵ���Ϣ��
**  Parameter2[out]:  *pTrack2Data 2�ŵ���Ϣ
**  Parameter3[out]:  *pTrack4Data 3�ŵ���Ϣ
**  Parameter4[out]:  *pcErrMsg  ����ִ�н����������Ϣ�� �硱�ɹ���
**  Return:          �ɹ��򷵻�0�����򷵻�С��0�Ĵ�����
**  Author:          
**  Date:            
***************************************************/
int __stdcall iReadMagCard_Track(unsigned char ctime ,unsigned char *pTrack1Data,unsigned char *pTrack2Data,unsigned char *pTrack3Data, char* pcErrMsg);

/**********************************************************************************
**  Function:     ReadIdentityCardMsg
**  Description:  ��ȡ���֤��Ϣ
**  Parameter[in]:*pPhotoSaveAddr    ��Ƭ�ļ����·��                  
**  Parameter[out]:*name    ����
                   *sex    �Ա�
                   *nation    ����
                   *birth    ��������
				   *address    ������ַ
                   *certno    ���֤��
                   *department    ǩ������
                   *madeddate    ��������
                   *expire    ������Ч��
                   *pcErrMsg    ����ʱ���صĴ�����Ϣ
**  Return:       �ɹ��򷵻�0�����򷵻�С��0�Ĵ�����
**  Note:         
**********************************************************************************/
int __stdcall ReadIdentityCardMsg(const char *pPhotoSaveAddr, char* name, char* sex, char* nation, char* birth,char* address, char* certno,char* department,char* madeddate, char* expire,char* pcErrMsg);

/**********************************************************************************
**  Function:     ReadIdentityCardID
**  Description:  ��ȡ���֤ID
**  Parameter[in]:��                  
**  Parameter[out]:*snr    ���֤���к�
                   *pcErrMsg    ����ʱ���صĴ�����Ϣ
**  Return:       �ɹ��򷵻�0�����򷵻�С��0�Ĵ�����
**  Note:         
**********************************************************************************/
int __stdcall ReadIdentityCardID(char* snr, char* pcErrMsg);

/**********************************************************************************
**  Function:     ReadMifare
**  Description:  ��Mifare1��
**  Parameter[in]:KeyMode    ������֤ģʽ:
                             0 ��ʾ0��A���룻1 ��ʾ1��A���룻
                             2 ��ʾ2��A���룻4 ��ʾ0��B���룻
                             5 ��ʾ1��B���룻6 ��ʾ2��B����
                  SecNr    ������ţ�0~15��
				  *SecKey    ��������,��"FFFFFFFFFFFF"
                  BlockNr    ��ַ���ţ�0~2��
**  Parameter[out]:*SecMsg    �����Ŀ�����
                   *pcErrMsg    ����ʱ���صĴ�����Ϣ
**  Return:       �ɹ��򷵻�0�����򷵻�С��0�Ĵ�����
**  Note:         
**********************************************************************************/
int __stdcall ReadMifare(const unsigned char KeyMode, unsigned char SecNr, char *SecKey,  const unsigned char BlockNr,char* SecMsg,  char* pcErrMsg);

/**********************************************************************************
**  Function:     writeMifare
**  Description:  дMifare1��
**  Parameter[in]:KeyMode    ������֤ģʽ:
                             0 ��ʾ0��A���룻1 ��ʾ1��A���룻
                             2 ��ʾ2��A���룻4 ��ʾ0��B���룻
                             5 ��ʾ1��B���룻6 ��ʾ2��B����
                  SecNr    ������ţ�0~15��
				  *SecKey    ��������,��"FFFFFFFFFFFF"
                  BlockNr    ��ַ���ţ�0~2��
                  *SecInfo    Ҫд��Ŀ�����
**  Parameter[out]:*pcErrMsg    ����ʱ���صĴ�����Ϣ
**  Return:       �ɹ��򷵻�0�����򷵻�С��0�Ĵ�����
**  Note:         
**********************************************************************************/
int __stdcall writeMifare(const unsigned char KeyMode, unsigned char SecNr, char *SecKey, const unsigned char BlockNr, unsigned char *SecInfo, char* pcErrMsg);

/**********************************************************************************
**  Function:     SwitchMode
**  Description:  �豸ģʽ�л�
**  Parameter[in]:Mode    �豸ģʽ: 0-��ͨģʽ��1-��ģʽ                  
**  Parameter[out]:��
**  Return:       �ɹ��򷵻�0����ʼ��ͨѶ�ڴ��󷵻�-101���豸ģʽ�л����󷵻�-102
**  Note:         
**********************************************************************************/

int __stdcall SwitchMode(const int Mode);

/***************************************************
**  Function:        iReadMedicareNO
**  Description:     ��ȡ�籣������ҽ���˺ŵĹ���
**  Parameter1[out]:  pcMedicareNum����ȡ���籣������ҽ���˺š�
**  Parameter2[out]:  pcErrMsg������ִ�н����������Ϣ�� �硱�ɹ���
**  Return:          int:�����ɹ�������0�����򣬷���С��0�Ĵ����룬pcErrMsgΪ����������
**  Author:          ʷ���
**  Date:            2015/04/11
***************************************************/
int __stdcall iReadMedicareNO(char* pcMedicareNum, char* pcErrMsg);


/***************************************************
**  ������2��Ϊ���ݿͻ���SSSE32���������ǵײ��ṩ��dcic��ɵĿ⣬ֻ����T6���⣬�������½ӿ�
***************************************************/
/***************************************************
**  Function:        ICC_Reader_Open
**  Description:     ���豸
**  Parameter1[In]:  dev_Name��ȡֵ��Χ��AUTO������USBn������COMn�������С�n����ȡֵ��ΧΪ1~9��
**  Return:          ������������ֵΪ��С��0 ���豸�������֮����ֵΪ״̬�룬�京�������B1.1
**  Author:          ʷ���
**  Date:            2015/04/11
***************************************************/
long __stdcall ICC_Reader_Open (char * chDev);

/***************************************************
**  Function:        ICC_Reader_Close
**  Description:     �ú���֪ͨ����ϵͳ�ر���ָ�����豸
**  Parameter1[In]:  dev_Name��ȡֵ��Χ��AUTO������USBn������COMn�������С�n����ȡֵ��ΧΪ1~9��
**  Return:          ����ֵ�京�������B1.1
**  Author:          ʷ���
**  Date:            2015/04/11
***************************************************/
long __stdcall ICC_Reader_Close (long ReaderHandle);

/***************************************************
**  Function:        SD_ReadCardInfo
**  Description:     �ú�����֤�籣���������籣���ж�����Ҫ�����ݡ�
**  Parameter1[In]:  ReaderHandle���豸����� 
**					 cardinfo ����ɹ��� 
**					��sbjgbh~t��+�籣�������+��~nsbkkh~t��+�籣������+��~nyhzh~t��+�����ʺ�+��~nsfzhm~t��+���֤����+��~nsbm~t��+ʶ����+��~n
**  Return:          ����ֵ�京�������B1.1
**  Author:          ʷ���
**  Date:            2015/04/11
***************************************************/
long __stdcall  SD_ReadCardInfo(long ReaderHandle, char * cardinfo);

/***************************************************
**  Function:        SD_VerifyPin
**  Description:     У������
**  Parameter1[In]:  ReaderHandle���豸���
**  Parameter2[In]:	 PIN������
**  Parameter3[out]: Sw1Sw2������У����
**  Return:          ����У��ɹ�����ֵΪ0�������ʾʧ�ܡ�
**  Author:          ʷ���
**  Date:            2015/04/11
***************************************************/
long __stdcall  SD_VerifyPin(long ReaderHandle,unsigned char *PIN,short* Sw1Sw2);

/***************************************************
**  Function:        SD_UnblockChangePin
**  Description:     �޸�����
**  Parameter1[In]:  ReaderHandle���豸���
**  Parameter2[In]:	 newPin��������
**  Return:          �����ɹ�����ֵΪ0������ֵС��0 Ϊ������
**  Author:          ʷ���
**  Date:            2015/04/11
***************************************************/
long __stdcall  SD_UnblockChangePin(long ReaderHandle,unsigned char *newPin);

/***************************************************
**  Function:        iReadMedicareNO
**  Description:     ��ȡ��������
**  Parameter1[In]:  ReaderHandle���豸���
**  Parameter2[In]:  ctime����ʱʱ����Ϊ��λ
**  Parameter3[out]:  rlen���������ݵĳ���
**  Parameter4[out]:  cpass���������ݣ������������Ϣ����
**  Return:          �����ɹ�����ֵΪ0������ֵС��0 Ϊ������
**  Author:          ʷ���
**  Date:            2015/04/11
***************************************************/
long __stdcall SD_GetInputPass(long ReaderHandle,unsigned char ctime,unsigned char *rlen,unsigned char * cpass);

/***************************************************
**  Function:        iRead4428Info
**  Description:     ��ȡ������ҽ����4428���Ļ�����Ϣ
**  Parameter1[out]:  char* chCardNum ���� 0x20 9
**  Parameter2[out]:  Char* chID ���֤�� 0x33 18 
**  Parameter3[out]:  Char* chPutCardDate �������� 0x45 8
**  Parameter4[out]:  Char* chName ���� 0x6A ? ����+0x20 ��
**  Parameter5[out]:  Char* chWorkAddr������λ 0x92 ? ��λ+0x20 
**  Return:          �����ɹ�����ֵΪ0������ֵС��0 Ϊ������
**  Author:          ʷ���
**  Date:            2017/05/19
***************************************************/
int __stdcall iRead4428Info(char* chCardNum, char* chID ,char* chPutCardDate,char* chName ,char* chWorkAddr ,  char* pErrMsg);

/***************************************************
**  Function:        iReadPutCardName
**  Description:     ��ȡ������������
**  Parameter1[out]:  pcMedicareNum�������������ơ�
**  Parameter2[out]:  pcErrMsg������ִ�н����������Ϣ�� �硱�ɹ���
**  Return:          int:�����ɹ�������0�����򣬷���С��0�Ĵ����룬pcErrMsgΪ����������
**  Author:          ʷ���
**  Date:            2017/05/19
***************************************************/
int __stdcall iReadPutCardName(char* pcPutCardName, char* pcErrMsg);

/***************************************************
**  Function:        readcard
**  Description:     ��ȡ���п���Ϣ
**  Parameter[in]:   amt ���׽��
                     tranType �������� 0:���п� 1:�籣��
**  Parameter[out]:  track1Data ��һ�ŵ���Ϣ
                     track2Data �ڶ��ŵ���Ϣ
                     track3Data �����ŵ���Ϣ
					 SeqNum ��һ���ֽ�:�Ƿ��п����кű�־, 0x01 ��ʾ��x00��ʾû�У��ڶ����ֽڣ�ʵ�ʿ����к�
					 Field55 55����Ϣ
**  Return:          �����ɹ�������0�����򣬷��ش�����
***************************************************/
int __stdcall readcard(double amt, char* tranType, char* track1Data, char* track2Data, char* track3Data, char* SeqNum, char* Field55);

/******************************************************************************************************
**  Function:       �綯����������
**  Parameter[in]:  ��
**  Parameter[out]: pOutInfo ����ʱ���صĴ�����Ϣ
**  Return:         �����ɹ�����0�����򷵻�С��0�Ĵ�����
******************************************************************************************************/
int __stdcall iEnterCard(char *pOutInfo);

/******************************************************************************************************
**  Function:       �綯�������˿�
**  Parameter[in]:  ��
**  Parameter[out]: pOutInfo ����ʱ���صĴ�����Ϣ
**  Return:         �����ɹ�����0�����򷵻�С��0�Ĵ�����
******************************************************************************************************/
int __stdcall iExitCard(char *pOutInfo);

/******************************************************************************************************
**  Function:       �綯�������ƿ�
**  Parameter[in]:  mode   �ƿ�ģʽ��0-������λ�ã� 1-�Ӵ�ʽλ�ã� 2-�ǽӴ�ʽλ��
**  Parameter[out]: pOutInfo ����ʱ���صĴ�����Ϣ
**  Return:         �����ɹ�����0�����򷵻�С��0�Ĵ�����
******************************************************************************************************/
int __stdcall iMoveCard(int mode, char *pOutInfo);

/**
* @brief   ɨ���ά��
* @param[in]: iTimeout    ��ʱʱ��
* @param[out]: pOutInfo    ɨ�����ݣ�����ʱ���ش�����Ϣ     
* @return	�����ɹ�����0�����򷵻�С��0�Ĵ�����
*/
int __stdcall iScan2DBarcode(int iTimeout, char *pOutInfo);

/**
* @brief   ��ȡ�籣����Ψһʶ���
* @param[out]: pUid    Ψһʶ���
* @param[out]: pOutInfo    ����ʱ���ش�����Ϣ     
* @return	�����ɹ�����0�����򷵻�С��0�Ĵ�����
*/
int __stdcall iReadUid(char *pUid, char *pOutInfo);

/**
* @brief   ��ȡ���Ϻ���Ĺ���
* @param[out]:  pcNum����ȡ�ı��Ϻ��롣
* @param[out]:  pcErrMsg������ִ�н����������Ϣ��
* @return	�����ɹ�������0�����򣬷���С��0�Ĵ����롣
*/
int __stdcall iReadSecurityNO(char* pcNum, char* pcErrMsg);

/**
* @brief   ��ȡ֤����Ϣ��
* @param[in,out]:  piFingerLen:  ָ����Ϣ���ȡ�inʱ��ָpucFinger��ռ���ڴ�ռ䣬����1024,��Ϊ0ʱ����ȡָ����Ϣ��;outʱ��ָpucFingerʵ�ʶ�ȡ�ĵ����ݳ��ȡ�
* @param[out]:  pucFinger:  ָ����Ϣ��ʮ���������ݡ�ʵ�ʳ���Ϊ*piFingerLen��
* @param[out]:  pOutInfo:  ֤����Ϣ�б�����˵�����Note��
* @return	�����ɹ�����0�����򷵻�С��0�Ĵ����롣   
* @Note:          
1������˾���֤,�������ݣ�
I|Ӣ����|��������|�Ա�|����|��������|���þ���֤����|֤��ǩ������|֤����ֹ����|��������������ش���|֤���汾��|��Ƭ BASE64|
2���۰�̨��ס֤,�������ݣ�
J|����|�Ա�|��������|��ַ|���֤��|ǩ������|��������|��Ч����|ͨ��֤����|ǩ������|��Ƭ BASE64|
3���������֤,�������ݣ�
|����|�Ա�|����|��������|��ַ|���֤��|��������|��Ч����|ǩ������|��ƬBASE64|
*/
long __stdcall iReadIdentityCard(int *piFingerLen, unsigned char *pucFinger, char* pOutInfo);

/**
* @brief   ��ȡ���������Ϣ
* @par    ˵����
*  ��ȡ���������Ϣ��
* @param[in]   iType ������Ϣ����Ļ��ʾ
* @n 0x00 - ����ʾ������
* @n 0x01 - "����������"��
* @n 0x02 - "��������һ��"��
* @n 0x03 - "������ԭ����"��
* @n 0x04 - "������������"��
* @param[out]	pOutInfo	�ɹ�����PIN�ַ���;ʧ�ܷ��ش���������Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iGetPassword(int iType, char* pOutInfo);

/**
* @brief  iOpenDev
* @par    ˵����
* �ú���֪ͨ�ն˲���ϵͳ�������������Ӧ���ն��豸�ӿڣ��Ա����߽���ͨ�ŵ��߼���ϵ, ���򿪳ɹ��ڽ��а汾�����к�У�顣
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return �����ɹ������豸��ʶ�������򷵻�С��0�Ĵ����룬pOutInfoΪ���������� 
******************************************************************************************************/
HANDLE __stdcall iOpenDev(char *pOutInfo);

/**
* @brief  �ر��豸��
* @par    ˵����
* �ر��豸��ͨѶ���ͷ���Դ��
* @param[in] icdev �豸��ʶ����
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iCloseDev(HANDLE icdev);

/**
* @brief  ���ô�ӡ��������
* @par    ˵����
* ���ò�����ӡ���Ĳ�����
* @param[in] icdev �豸��ʶ����
* @param[in] FontSize �������ã�0x00��ʾ�ַ���СΪ8*16��0x01��ʾ�ַ���СΪ12*24��0x02��ʾ�ַ���СΪ16*32��
* @param[in] Alignment �������ã�0x00��ʾ����룬0x01��ʾ���У�0x02��ʾ�Ҷ��롣
* @param[in] LeftMargin ��߾����ã��ַ���СΪ8*16ʱ<48���ַ���СΪ12*24ʱ<32���ַ���СΪ16*32ʱ<24��
* @param[in] RightMargin �ұ߾����ã��ַ���СΪ8*16ʱ<48���ַ���СΪ12*24ʱ<32���ַ���СΪ16*32ʱ<24��
* @param[in] RowPitch �м�����ã���λΪ�㡣
* @param[in] PrintOutRate ��ӡ�ٶ����ã�0x00~0x03����0x00��죬0x03������
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iSetPrint(HANDLE icdev, unsigned char FontSize, unsigned char Alignment, unsigned char LeftMargin, unsigned char  RightMargin, unsigned char RowPitch, unsigned char PrintOutRate, char *pOutInfo);

/**
* @brief  ��ѯ��ӡ��������
* @par    ˵����
* ��ѯ������ӡ���Ĳ�����
* @param[in] icdev �豸��ʶ����
* @param[out] FontSize �������ã�0x00��ʾ�ַ���СΪ8*16��0x01��ʾ�ַ���СΪ12*24��0x02��ʾ�ַ���СΪ16*32��
* @param[out] Alignment �������ã�0x00��ʾ����룬0x01��ʾ���У�0x02��ʾ�Ҷ��롣
* @param[out] LeftMargin ��߾����ã��ַ���СΪ8*16ʱ<48���ַ���СΪ12*24ʱ<32���ַ���СΪ16*32ʱ<24��
* @param[out] RightMargin �ұ߾����ã��ַ���СΪ8*16ʱ<48���ַ���СΪ12*24ʱ<32���ַ���СΪ16*32ʱ<24��
* @param[out] RowPitch �м�����ã���λΪ�㡣
* @param[out] PrintOutRate ��ӡ�ٶ����ã�0x00~0x03����0x00��죬0x03������
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iCheckPrint(HANDLE icdev, unsigned char *FontSize, unsigned char *Alignment, unsigned char *LeftMargin, unsigned char *RightMargin, unsigned char *RowPitch, unsigned char *PrintOutRate, char *pOutInfo);

/**
* @brief  ��ӡ�ַ���
* @par    ˵����
* ��ӡ�ı��ַ���Ϣ��
* @param[in] icdev �豸��ʶ����
* @param[in] length �ַ����ݵĳ��ȣ�����С�ڻ����480��
* @param[in] character �ַ����ݡ�
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iPrintCharacter(HANDLE icdev, unsigned short length, unsigned char *character, char *pOutInfo);

/**
* @brief  ��ӡһά�롣
* @par    ˵����
* ��ӡһά����Ϣ��
* @param[in] icdev �豸��ʶ����
* @param[in] hight һά��ĸ߶ȡ�
* @param[in] displayflag ��ʾ���ͣ�0x00��ʾͼ�������ı����ϣ�0x01��ʾͼ�������ı����£�0x02��ʾֻ��ʾͼ�β���ʾ�ı���
* @param[in] FontSize �������ã�0x00��ʾ�ַ���СΪ8*16��0x01��ʾ�ַ���СΪ12*24��0x02��ʾ�ַ���СΪ16*32��
* @param[in] length �ı����ݵĳ��ȣ�����С�ڻ����15��
* @param[in] Onedimensional �ı����ݡ�
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iPrintOnedimensional(HANDLE icdev, unsigned char hight, unsigned char displayflag, unsigned char FontSize, unsigned short length, unsigned char *Onedimensional, char *pOutInfo);

/**
* @brief  ��ֽ��
* @par    ˵����
* ��ֽ���豸�����ڴ�ӡ��
* @param[in] icdev �豸��ʶ����
* @param[in] RowPitch ��ֽ��������λΪ�㡣
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iPrintenter(HANDLE icdev, unsigned char RowPitch);

/**
* @brief  ��ȡ��ӡ��״̬��
* @par    ˵����
* ��ȡ��ӡ����״̬��
* @param[in] icdev �豸��ʶ����
* @param[out] paperstatus ֽ״̬��0x00��ʾ��ȱֽ��0x01��ʾȱֽ��
* @param[out] tempturestatus �¶�״̬��0x00��ʾ�¶�������0x01��ʾ�¶ȹ��ߡ�
* @param[out] zkstatus �ֿ�״̬��
* @n 0x00 - �����ֿⶼ���ڡ�
* @n 0x01 - �����ֿⶼ�����ڡ�
* @n 0x02 - ����8*16�ֿ⡣
* @n 0x03 - ����12*24�ֿ⡣
* @n 0x04 - ����16*32�ֿ⡣
* @n 0x05 - ����8*16�ֿ��12*24�ֿ⡣
* @n 0x06 - ����8*16�ֿ��16*32�ֿ⡣
* @n 0x07 - ����12*24�ֿ��16*32�ֿ⡣
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iPrintStatus(HANDLE icdev, unsigned char *paperstatus, unsigned char *tempturestatus, unsigned char *zkstatus, char *pOutInfo);

/**
* @brief  ��ӡͼƬ��
* @par    ˵����
* ��ӡͼƬ��Ϣ��
* @param[in] icdev �豸��ʶ����
* @param[in] length ���ȣ���λΪ�ֽڣ�����С�ڻ����48������Ϊ0��
* @param[in] height �߶ȣ���λΪ�㣬����С��100������Ϊ0��
* @param[in] Alignment �������ã�0x00��ʾ����룬0x01��ʾ���У�0x02��ʾ�Ҷ��롣
* @param[in] LeftMargin ��߾����ã�����С�ڻ����48��
* @param[in] RightMargin �ұ߾����ã�����С�ڻ����48��
* @param[in] size ͼƬ���ݵĴ�С��
* @param[in] Picture ͼƬ���ݡ�
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iPrintPicture(HANDLE c_iHandle, unsigned char length, unsigned char height, unsigned char Alignment, unsigned char LeftMargin, unsigned char RightMargin, unsigned short size, unsigned char *Picture, char *pOutInfo);

/**
* @brief  ��ʾͼ��
* @par    ˵����
* ����Ļ����ʾͼ�������ͼ��ָ����ǰ��ͼ��
* @param[in] icdev �豸��ʶ����
* @param[in] x ͼ����ʾ����ʼX���ꡣ
* @param[in] y ͼ����ʾ����ʼY���ꡣ
* @param[in] w ͼ����ʾ�Ŀ�ȡ�
* @param[in] h ͼ����ʾ�ĸ߶ȡ�
* @param[in] time_s ��ʾʱ�䣬��λΪ�룬0��ʾһֱ��ʾ��
* @param[in] image_data ͼ�����ݡ���ʽΪ����4���ֽ�ͼ����Ϣ���ȣ�Big-Endian������ͼ����Ϣ����
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iScreenDisplayImage(HANDLE icdev, int x, int y, int w, int h, int time_s, const unsigned char *image_data, char *pOutInfo);

/**
* @brief  �����ʾ��
* @par    ˵����
* �����Ļ�ϵ���ʾ�������������ʾΪǰ����
* @param[in] icdev �豸��ʶ����
* @param[in] x �����ʾ����ʼX���ꡣ
* @param[in] y �����ʾ����ʼY���ꡣ
* @param[in] w �����ʾ�Ŀ�ȡ�
* @param[in] h �����ʾ�ĸ߶ȡ�
* @param[in] time_s ��ʱ���ʱ�䣬��λΪ�룬0��ʾ���������
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iScreenClearDisplay(HANDLE icdev, int x, int y, int w, int h, int time_s, char *pOutInfo);

/**
* @brief  װ�ر���ͼ��
* @par    ˵����
* װ�ر���ͼ���豸�ڲ���
* @param[in] icdev �豸��ʶ����
* @param[in] number ͼ����ţ���1��ʼ��š�
* @param[in] image_data ͼ�����ݡ���ʽΪ����4���ֽ�ͼ����Ϣ���ȣ�Big-Endian������ͼ����Ϣ����
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ��� 
*/
int __stdcall iScreenLoadBgImage(HANDLE icdev, int number, const unsigned char *image_data, char *pOutInfo);
/**
* @brief  ��ʾ����ͼ��
* @par    ˵����
* ��ʾ�豸�ڲ�װ�صı���ͼ��
* @param[in] icdev �豸��ʶ����
* @param[in] number ͼ����ţ���1��ʼ��š�
* @param[in] x ͼ����ʾ����ʼX���ꡣ
* @param[in] y ͼ����ʾ����ʼY���ꡣ
* @param[in] w ͼ����ʾ�Ŀ�ȡ�
* @param[in] h ͼ����ʾ�ĸ߶ȡ�
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iScreenDisplayBgImage(HANDLE icdev, int number, int x, int y, int w, int h, char *pOutInfo);

/**
* @brief  ��ȡ��ʾ���á�
* @par    ˵����
* ��ȡ��ʾ���á�
* @param[in] icdev �豸��ʶ����
* @param[in] tag ��ǩ��
* @n 0x01 - Ϩ��ʱ�䣬������Ϣ���ȹ̶�Ϊ4���ֽڣ���λΪ�루Big-Endian�����磺config_data = {0x04,0x00,0x00,0x00,0x10}��ʾϨ��ʱ��Ϊ16�롣
* @n 0x02 - ��ʾ�ֱ��ʣ�������Ϣ���ȹ̶�Ϊ4���ֽڣ�ǰ2���ֽ�Ϊˮƽ�ֱ��ʣ�Big-Endian������2���ֽ�Ϊ��ֱ�ֱ��ʣ�Big-Endian�����磺config_data = {0x04,0x02,0x80,0x01,0xE0}��ʾ�ֱ���Ϊ640x480��
* @param[out] config_data �������ݡ���ʽΪ����1�ֽ�������Ϣ���ȡ���������Ϣ����
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iScreenDisplayGetConfig(HANDLE icdev, unsigned char tag, unsigned char *config_data, char *pOutInfo);

/**
* @brief  ������ʾ���á�
* @par    ˵����
* ������ʾ���á�
* @param[in] icdev �豸��ʶ����
* @param[in] tag ��ǩ��
* @n 0x01 - Ϩ��ʱ�䣬������Ϣ���ȹ̶�Ϊ4���ֽڣ���λΪ�루Big-Endian�����磺config_data = {0x04,0x00,0x00,0x00,0x10}��ʾϨ��ʱ��Ϊ16�롣
* @n 0x02 - ��ʾ�ֱ��ʣ�������Ϣ���ȹ̶�Ϊ4���ֽڣ�ǰ2���ֽ�Ϊˮƽ�ֱ��ʣ�Big-Endian������2���ֽ�Ϊ��ֱ�ֱ��ʣ�Big-Endian�����磺config_data = {0x04,0x02,0x80,0x01,0xE0}��ʾ�ֱ���Ϊ640x480��
* @param[in] config_data �������ݡ���ʽΪ����1�ֽ�������Ϣ���ȡ���������Ϣ����
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iScreenDisplaySetConfig(HANDLE icdev, unsigned char tag, unsigned char *config_data, char *pOutInfo);

/**
* @brief  ��ʾ���֡�
* @par    ˵����
* ����Ļ����ʾ���֣�ע������Ҳ����ǰ����
* @param[in] icdev �豸��ʶ����
* @param[in] font_size �����С��
* @param[in] fg_rgb ����ǰ��ɫ��3���ֽ�RGBֵ����һ���ֽ�ΪR���ڶ����ֽ�ΪG���������ֽ�ΪB��
* @param[in] bg_rgb ���ֱ���ɫ��3���ֽ�RGBֵ����һ���ֽ�ΪR���ڶ����ֽ�ΪG���������ֽ�ΪB��
* @param[in] x ������ʾ����ʼX���ꡣ
* @param[in] y ������ʾ����ʼY���ꡣ
* @param[in] time_s ��ʾʱ�䣬��λΪ�룬0��ʾһֱ��ʾ��
* @param[in] line_flag ���б�־��0��ʾ���Զ����У�1��ʾ�Զ����С�
* @param[in] voice_flag ������־��0��ʾ������������1��ʾ����������
* @param[in] text �ı��ַ�����
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iScreenDisplayText(HANDLE icdev, unsigned char font_size, const unsigned char *fg_rgb, const unsigned char *bg_rgb, int x, int y, int time_s, unsigned char line_flag, unsigned char voice_flag, const char *text, char *pOutInfo);

/**
* @brief  ��䱳����
* @par    ˵����
* ʹ��ָ����ɫ��䱳����
* @param[in] icdev �豸��ʶ����
* @param[in] rgb ��ɫ��3���ֽ�RGBֵ����һ���ֽ�ΪR���ڶ����ֽ�ΪG���������ֽ�ΪB��
* @param[in] x ��ʼX���ꡣ
* @param[in] y ��ʼY���ꡣ
* @param[in] w ��ȡ�
* @param[in] h �߶ȡ�
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iScreenDisplayBgImageByColor(HANDLE icdev, const unsigned char *rgb, int x, int y, int w, int h, char *pOutInfo);

/**
* @brief  ��ʾ��ά�롣
* @par    ˵����
* ��ʾ��ά�롣
* @param[in] icdev �豸��ʶ����
* @param[in] type ���0x01��ʾ�����ζ�ά�롣
* @param[in] x ��ʼX���ꡣ
* @param[in] y ��ʼY���ꡣ
* @param[in] w ��ȡ�
* @param[in] h �߶ȡ�
* @param[in] content ��������
* @param[in] content_len �������ݵĳ��ȡ�
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iScreenDisplay2DBarcode(HANDLE icdev, unsigned char type, int x, int y, int w, int h, const unsigned char *content, int content_len, char *pOutInfo);

/**
* @brief  LCD��ʾ������
* @par    ˵����
* LCD��ʾ������
* @param[in] icdev �豸��ʶ����
* @param[in] type ��ʽ���ͣ�0x00��ʾXML��ʽ��0x01��ʾTLV��ʽ��0x02��ʾJPEG��ʽ��
* @param[in] slen �������ݵĳ��ȡ�
* @param[in] sdata �������ݡ�
* @param[out] rlen �������ݵĳ��ȡ�
* @param[out] rdata ���ص����ݡ�
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iLcdDisplayInteraction(HANDLE icdev, unsigned char type, unsigned int slen, const unsigned char *sdata, unsigned int *rlen, unsigned char *rdata, char *pOutInfo);

/**
* @brief  LCD��ʾ��������ѯ״̬����
* @par    ˵����
* LCD��ʾ��������ѯ״̬����
* @param[in] icdev �豸��ʶ����
* @param[in] type ��ʽ���ͣ�0x00��ʾXML��ʽ��0x01��ʾTLV��ʽ��0x02��ʾJPEG��ʽ��
* @param[in] id ����Ψһ��ʶһ���������ݵĴ��䡣
* @param[in] size_of_processed_pc_data ��ʾPC�Ѵ������ݵ��ܴ�С����λ���ֽڣ���
* @param[out] size_of_processed_device_data ��ʾDEVICE�Ѵ������ݵ��ܴ�С����λ���ֽڣ���
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iLcdDisplayInteractionQueryState(HANDLE icdev, unsigned char type, unsigned int id, unsigned int size_of_processed_pc_data, unsigned int *size_of_processed_device_data, char *pOutInfo);

/**
* @brief  T60 LCD��ʾ����������PC��DEVICE���ݴ��䣩��
* @par    ˵����
* LCD��ʾ����������PC��DEVICE���ݴ��䣩��
* @param[in] icdev �豸��ʶ����
* @param[in] type ��ʽ���ͣ�0x00��ʾXML��ʽ��0x01��ʾTLV��ʽ��0x02��ʾJPEG��ʽ��
* @param[in] id ����Ψһ��ʶһ���������ݵĴ��䡣
* @param[in] pc_capacity_size ��ʾPCÿ֡�д������ݵ����ֵ����λ���ֽڣ���
* @param[in] data_size Ҫ�������ݵ��ܴ�С����λ���ֽڣ���
* @param[out] device_capacity_size ��ʾDEVICEÿ֡�д������ݵ����ֵ����λ���ֽڣ���
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iLcdDisplayInteractionPcToDeviceRequest(HANDLE icdev, unsigned char type, unsigned int id, unsigned int pc_capacity_size, unsigned int data_size, unsigned int *device_capacity_size, char *pOutInfo);

/**
* @brief  T60 LCD��ʾ����������PC��DEVICE���ݴ��䣩��
* @par    ˵����
* LCD��ʾ����������PC��DEVICE���ݴ��䣩��
* @param[in] icdev �豸��ʶ����
* @param[in] type ��ʽ���ͣ�0x00��ʾXML��ʽ��0x01��ʾTLV��ʽ��0x02��ʾJPEG��ʽ��
* @param[in] id ����Ψһ��ʶһ���������ݵĴ��䡣
* @param[in,out] offset ����PCҪ�������ݵ�ƫ��������λ���ֽڣ����ҷ���DEVICEʵ�ʽ������ݵ�ƫ��������λ���ֽڣ���
* @param[in,out] length ����PCҪ�������ݵĳ��ȣ���λ���ֽڣ����ҷ���DEVICEʵ�ʽ������ݵĳ��ȣ���λ���ֽڣ���
* @param[in] data ����PCҪ���͵����ݡ�
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iLcdDisplayInteractionPcToDeviceRun(HANDLE icdev, unsigned char type, unsigned int id, unsigned int *offset, unsigned int *length, const unsigned char *data, char *pOutInfo);

/**
* @brief  T60 LCD��ʾ����������DEVICE��PC���ݴ��䣩��
* @par    ˵����
* LCD��ʾ����������DEVICE��PC���ݴ��䣩��
* @param[in] icdev �豸��ʶ����
* @param[in] type ��ʽ���ͣ�0x00��ʾXML��ʽ��0x01��ʾTLV��ʽ��0x02��ʾJPEG��ʽ��
* @param[in] id ����Ψһ��ʶһ���������ݵĴ��䡣
* @param[in] pc_capacity_size ��ʾPCÿ֡�д������ݵ����ֵ����λ���ֽڣ���
* @param[out] device_capacity_size ��ʾDEVICEÿ֡�д������ݵ����ֵ����λ���ֽڣ���
* @param[out] data_size Ҫ�������ݵ��ܴ�С����λ���ֽڣ���
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iLcdDisplayInteractionDeviceToPcRequest(HANDLE icdev, unsigned char type, unsigned int id, unsigned int pc_capacity_size, unsigned int *device_capacity_size, unsigned int *data_size, char *pOutInfo);

/**
* @brief  T60 LCD��ʾ����������DEVICE��PC���ݴ��䣩��
* @par    ˵����
* LCD��ʾ����������DEVICE��PC���ݴ��䣩��
* @param[in] icdev �豸��ʶ����
* @param[in] type ��ʽ���ͣ�0x00��ʾXML��ʽ��0x01��ʾTLV��ʽ��0x02��ʾJPEG��ʽ��
* @param[in] id ����Ψһ��ʶһ���������ݵĴ��䡣
* @param[in,out] offset ����PCҪ�������ݵ�ƫ��������λ���ֽڣ����ҷ���DEVICEʵ�ʷ������ݵ�ƫ��������λ���ֽڣ���
* @param[in,out] length ����PCҪ�������ݵĳ��ȣ���λ���ֽڣ����ҷ���DEVICEʵ�ʷ������ݵĳ��ȣ���λ���ֽڣ���
* @param[out] data ����DEVICEʵ�ʷ��͵����ݡ�
* @param[out]:  pOutInfo ����ʱ���ش�����Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
int __stdcall iLcdDisplayInteractionDeviceToPcRun(HANDLE icdev, unsigned char type, unsigned int id, unsigned int *offset, unsigned int *length, unsigned char *data, char *pOutInfo);

/**
* @brief  ��ȡǩ����˽Կ�ԡ�
* @par    ˵����
* �ڿ��ڲ���ǩ����˽Կ�ԣ�����������Ĺ�Կ���ݡ�
* @param[in] pAdminPin �ɵĹ���ԱPIN
* @param[in] pUserPin �û�PIN
* @param[out] pOutInfo ����ǩ����Կ���ݻ������Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
long __stdcall iWriteCA_HSM_Step1(char* pAdminPin, char* pUserPin, char* pOutInfo);
/**
* @brief  ֤��д�롣
* @par    ˵����
* ֤��д�롣
* @param[in] QMZS ǩ��֤��
* @param[in] JMZS ����֤��
* @param[in] JMMY ������Կ
* @param[in] ZKMY ��������Կ
* @param[in] GLYPIN �¹���ԱPIN
* @param[in] oldZKMY ��������Կ
* @param[out] pOutInfo ���ؿ��ַ����������Ϣ
* @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
*/
long __stdcall iWriteCA_HSM_Step2(char* QMZS, char* JMZS, char* JMMY, char* ZKMY, char* GLYPIN, char* oldZKMY, char* pOutInfo);

#ifdef __cplusplus
}
#endif
#endif