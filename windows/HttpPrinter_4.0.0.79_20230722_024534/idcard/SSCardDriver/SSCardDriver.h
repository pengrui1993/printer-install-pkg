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
**  Description:     读取社保卡发卡公共信息。
**  Parameter[out]:  KSBM: 卡识别码
                     KLB: 卡类别
					 GFBB: 规范版本
					 JGBM: 初始化机构代码
					 FKRQ: 发卡日期
					 KYXQ: 卡有效期
					 KH: 卡号
**  Parameter[out]:  pErrMsg: 错误描述
**  Return:          int: 操作成功返回0；否则返回小于0的错误码，            
***************************************************/	
int __stdcall iReadCardPublicInfo(char* KSBM, char* KLB, char* GFBB, char* JGBM, char* FKRQ, char* KYXQ, char* KH, char* pErrMsg);

/***************************************************
**  Function:        iReadPersonPublicInfo 
**  Description:     读取社保卡持卡人公共信息。  
**  Parameter[out]:  SHBZHM: 社会保障号码
**                   XM: 姓名
**                   XB: 性别
**                   MZ: 民族
**                   CSD: 出生地
**                   CSRQ: 出生日期
**                   pErrMsg: 错误描述
**  Return:          int: 操作成功返回0；否则返回小于0的错误码，            
***************************************************/	
int __stdcall iReadPersonPublicInfo(char* SHBZHM,char* XM,char* XB,char* MZ,char* CSD,char* CSRQ,char* pErrMsg);

/***************************************************
**  Function:        iReadIdentityInfo
**  Description:     读取二代证信息
**  Parameter[in]:   pcPhotoPath：照片文件保存路径，若为空则不保存。
**  Parameter[out]:  pName: 姓名
**                   pGeneder: 性别（描述信息）
**                   pNation: 民族（描述信息）
**                   pBirth: 出生日期
**                   pAddress: 户籍地址
**                   pCertNO: 身份证号
**                   pDepartment: 签发机关
**                   pMadedDate: 发卡日期
**                   pExpire: 截至有效期
**                   pPhotoBuffer: 照片数据流.pcPhotoPath为空不生成
**                   pErrMsg：函数执行结果的描述信息： 如”成功”。
**  Return:          int:操作成功返回0；否则返回小于0的错误码          
***************************************************/	
int __stdcall iReadIdentityInfo(const char* pcPhotoPath, char* pName, char* pGeneder,	char* pNation,char* pBirth,char* pAddress,char* pCertNO,char* pDepartment,char* pMadedDate,char* pExpire,	char* pPhotoBuffer, char* pErrMsg);

/***************************************************
**  Function:        iReadPBOCAccount
**  Description:     读金融账号
**  Parameter[out]:  pOutData：个人账户信息
**                   pErrmsg：函数执行结果的描述信息： 如”成功”。
**  Return:          int:操作成功返回0；否则返回小于0的错误码，pErrmsg为错误描述。           
***************************************************/
int __stdcall iReadPBOCAccount(char* pOutData, char* pErrMsg);

/***************************************************
**  Function:        iReadPBOCAccount
**  Description:     读银行卡个人账户和
**  Parameter[out]:  pOutData：个人账户信息
					 pBankNoSnr 个人账户序列号,与个人账户一起确定账户唯一性
**                   pErrmsg：函数执行结果的描述信息： 如”成功”。
**  Return:          int:操作成功返回0；否则返回小于0的错误码，pErrmsg为错误描述。           
***************************************************/
int __stdcall iReadPBOCAccount_Ext(char* pBankNo, char* pBankNoSnr, char* pErrMsg);

/***************************************************
**  Function:        iPKBGetPIN
**  Description:     获取密码键盘输入信息
**  Parameter[out]:  pcErrMsg：函数执行结果的描述信息： 如”成功”。
**  Return:          int:操作成功，返回0；否则，返回小于0的错误码，pcErrMsg为错误描述。
**  Author:          YJZ
**  Date:            2015/12/24
**  Note:            此函数不需要PSAM卡
***************************************************/
int __stdcall iPKBGetPIN (char* pcPass,char* pcErrMsg);

/***************************************************
**  Function:        iVerifyPIN
**  Description:     校验个人PIN码
**  Parameter[in]:   pchPIN：个人PIN码
**  Parameter[out]:  pcErrMsg：函数执行结果的描述信息： 如”成功”。
**  Return:          int:操作成功，返回0；否则，返回小于0的错误码，pcErrMsg为错误描述。
**  Author:          YJZ
**  Date:            2015/12/24
**  Note:            此函数不需要PSAM卡
***************************************************/
int __stdcall iPKBVerifyPIN(const char* pchPIN, char* pcErrMsg);

/***************************************************
**  Function:        iChangePIN
**  Description:     修改个人PIN码
**  Parameter[in]:   pcOldPIN：原密码
**                   pcNewPIN：新密码
**  Parameter[out]:  pcErrMsg：函数执行结果的描述信息： 如”成功”。
**  Return:          int:操作成功，返回0；否则，返回小于0的错误码，pcErrMsg为错误描述。
**  Author:          YJZ
**  Date:            2015/12/24
**  Note:            此函数不需要PSAM卡
***************************************************/
int __stdcall iPKBChangePIN(const char* pcOldPIN, const char* pcNewPIN, char* pcErrMsg);

/***************************************************
**  Function:        DeviceBeep
**  Description:     设备蜂鸣
**  Parameter[in]:   time: 蜂鸣持续时间(ms),建议取值10
**  Parameter[out]:  pErrMsg: 函数执行结果的描述信息： 如”成功”。
**  Return:          int:操作成功，返回0；否则，返回小于0的错误码
***************************************************/
int __stdcall DeviceBeep(int time, char *pErrMsg);

/******************************************************************************************************
**  函数名称:        iReadHealthyBasicInfo
**  功能描述:        读取健康卡基本信息，即DDF1EF05下的所有信息
**  输入参数:        hDev:设备句柄
**  输出参数:        KH:卡号；XM：姓名；XB：性别；MZ：名族；CSRQ：出生日期；SFZH：身份证号；pcAddress：籍贯；JKDABH：健康卡档案编号；XLHZKH：新农合证卡号，pErrMsg：错误信息
**  返回值:          int:成功，返回0，失败返回相应的错误码
**  备注:            发卡时间为YYYYMMDD格式；卡号，与居民身份证号或者证件号码一致        
******************************************************************************************************/
int __stdcall iReadHealthyBasicInfo(char * KH, char * XM, char * XB, char * MZ, char * CSRQ, char * SFZH, 
									char * pcAddress, char *JKDABH, char *XLHZKH, char *pErrMsg);

/******************************************************************************************************
**  Function:        iCheckCard
**  Description:     判断是居民健康卡、银行芯片卡还是医院M1S50型就诊卡
**  Return:          int:返回1表示医院就诊卡；返回2表示陕西省居民健康卡，返回3表示社保卡，
**                       返回4表示二代证，返回5表示无卡，返回6表示银行卡，其他值未定义；
**  Note:
******************************************************************************************************/
int __stdcall iCheckCard(void);

/**********************************************************************************
**  Function:     ReadICCardNum
**  Description:  读取银联卡卡号
**  Parameter[in]:ICType    通讯方式:1表示接触式；2表示非接触式；其他值表示自动适应（支持接触和非接触）。                  
**  Parameter[out]:*cardnumber    读取的银联卡卡号
                   *pcErrMsg    出错时返回的错误信息
**  Return:       成功则返回0，否则返回小于0的错误码
**  Note:         
**********************************************************************************/
int __stdcall ReadICCardNum(int ICType, char* cardnumber, char* pcErrMsg);


/***************************************************
**  Function:        iReadMagCard
**  Description:     读取银联卡卡号（磁条方式）
**  Parameter1[out]:  *CardNumber    读取的银联卡卡号。
**  Parameter2[out]:  pcErrMsg：函数执行结果的描述信息： 如”成功”
**  Return:          成功则返回0，否则返回小于0的错误码
**  Author:          史宽厚
**  Date:            2015/05/09
***************************************************/
int __stdcall iReadMagCard(unsigned char ctime ,char* CardNumber, char* pcErrMsg);
/***************************************************
**  Function:        iReadMagCard
**  Description:     读取磁条卡磁道信息
**  Parameter1[out]:  *pTrack1Data    1磁道信息。
**  Parameter2[out]:  *pTrack2Data 2磁道信息
**  Parameter3[out]:  *pTrack4Data 3磁道信息
**  Parameter4[out]:  *pcErrMsg  函数执行结果的描述信息： 如”成功”
**  Return:          成功则返回0，否则返回小于0的错误码
**  Author:          
**  Date:            
***************************************************/
int __stdcall iReadMagCard_Track(unsigned char ctime ,unsigned char *pTrack1Data,unsigned char *pTrack2Data,unsigned char *pTrack3Data, char* pcErrMsg);

/**********************************************************************************
**  Function:     ReadIdentityCardMsg
**  Description:  读取身份证信息
**  Parameter[in]:*pPhotoSaveAddr    照片文件存放路径                  
**  Parameter[out]:*name    姓名
                   *sex    性别
                   *nation    民族
                   *birth    出生日期
				   *address    户籍地址
                   *certno    身份证号
                   *department    签发机关
                   *madeddate    发卡日期
                   *expire    截至有效期
                   *pcErrMsg    出错时返回的错误信息
**  Return:       成功则返回0，否则返回小于0的错误码
**  Note:         
**********************************************************************************/
int __stdcall ReadIdentityCardMsg(const char *pPhotoSaveAddr, char* name, char* sex, char* nation, char* birth,char* address, char* certno,char* department,char* madeddate, char* expire,char* pcErrMsg);

/**********************************************************************************
**  Function:     ReadIdentityCardID
**  Description:  读取身份证ID
**  Parameter[in]:无                  
**  Parameter[out]:*snr    身份证序列号
                   *pcErrMsg    出错时返回的错误信息
**  Return:       成功则返回0，否则返回小于0的错误码
**  Note:         
**********************************************************************************/
int __stdcall ReadIdentityCardID(char* snr, char* pcErrMsg);

/**********************************************************************************
**  Function:     ReadMifare
**  Description:  读Mifare1卡
**  Parameter[in]:KeyMode    密码验证模式:
                             0 表示0套A密码；1 表示1套A密码；
                             2 表示2套A密码；4 表示0套B密码；
                             5 表示1套B密码；6 表示2套B密码
                  SecNr    扇区编号（0~15）
				  *SecKey    扇区密码,如"FFFFFFFFFFFF"
                  BlockNr    地址块编号（0~2）
**  Parameter[out]:*SecMsg    读出的块数据
                   *pcErrMsg    出错时返回的错误信息
**  Return:       成功则返回0，否则返回小于0的错误码
**  Note:         
**********************************************************************************/
int __stdcall ReadMifare(const unsigned char KeyMode, unsigned char SecNr, char *SecKey,  const unsigned char BlockNr,char* SecMsg,  char* pcErrMsg);

/**********************************************************************************
**  Function:     writeMifare
**  Description:  写Mifare1卡
**  Parameter[in]:KeyMode    密码验证模式:
                             0 表示0套A密码；1 表示1套A密码；
                             2 表示2套A密码；4 表示0套B密码；
                             5 表示1套B密码；6 表示2套B密码
                  SecNr    扇区编号（0~15）
				  *SecKey    扇区密码,如"FFFFFFFFFFFF"
                  BlockNr    地址块编号（0~2）
                  *SecInfo    要写入的块数据
**  Parameter[out]:*pcErrMsg    出错时返回的错误信息
**  Return:       成功则返回0，否则返回小于0的错误码
**  Note:         
**********************************************************************************/
int __stdcall writeMifare(const unsigned char KeyMode, unsigned char SecNr, char *SecKey, const unsigned char BlockNr, unsigned char *SecInfo, char* pcErrMsg);

/**********************************************************************************
**  Function:     SwitchMode
**  Description:  设备模式切换
**  Parameter[in]:Mode    设备模式: 0-普通模式，1-打卡模式                  
**  Parameter[out]:无
**  Return:       成功则返回0，初始化通讯口错误返回-101，设备模式切换错误返回-102
**  Note:         
**********************************************************************************/

int __stdcall SwitchMode(const int Mode);

/***************************************************
**  Function:        iReadMedicareNO
**  Description:     读取社保卡个人医保账号的功能
**  Parameter1[out]:  pcMedicareNum：读取的社保卡个人医保账号。
**  Parameter2[out]:  pcErrMsg：函数执行结果的描述信息： 如”成功”
**  Return:          int:操作成功，返回0；否则，返回小于0的错误码，pcErrMsg为错误描述。
**  Author:          史宽厚
**  Date:            2015/04/11
***************************************************/
int __stdcall iReadMedicareNO(char* pcMedicareNum, char* pcErrMsg);


/***************************************************
**  需求变更2：为兼容客户的SSSE32（根据我们底层提供的dcic完成的库，只兼容T6）库，增加以下接口
***************************************************/
/***************************************************
**  Function:        ICC_Reader_Open
**  Description:     打卡设备
**  Parameter1[In]:  dev_Name：取值范围”AUTO”、”USBn”、“COMn”，其中”n”的取值范围为1~9。
**  Return:          若正常，返回值为不小于0 的设备句柄；反之返回值为状态码，其含义见附表B1.1
**  Author:          史宽厚
**  Date:            2015/04/11
***************************************************/
long __stdcall ICC_Reader_Open (char * chDev);

/***************************************************
**  Function:        ICC_Reader_Close
**  Description:     该函数通知操作系统关闭所指定的设备
**  Parameter1[In]:  dev_Name：取值范围”AUTO”、”USBn”、“COMn”，其中”n”的取值范围为1~9。
**  Return:          返回值其含义见附表B1.1
**  Author:          史宽厚
**  Date:            2015/04/11
***************************************************/
long __stdcall ICC_Reader_Close (long ReaderHandle);

/***************************************************
**  Function:        SD_ReadCardInfo
**  Description:     该函数验证社保卡，并从社保卡中读出需要的数据。
**  Parameter1[In]:  ReaderHandle：设备句柄； 
**					 cardinfo 的组成规则： 
**					‘sbjgbh~t’+社保机构编号+‘~nsbkkh~t’+社保卡卡号+‘~nyhzh~t’+银行帐号+‘~nsfzhm~t’+身份证号码+‘~nsbm~t’+识别码+‘~n
**  Return:          返回值其含义见附表B1.1
**  Author:          史宽厚
**  Date:            2015/04/11
***************************************************/
long __stdcall  SD_ReadCardInfo(long ReaderHandle, char * cardinfo);

/***************************************************
**  Function:        SD_VerifyPin
**  Description:     校验密码
**  Parameter1[In]:  ReaderHandle：设备句柄
**  Parameter2[In]:	 PIN：密码
**  Parameter3[out]: Sw1Sw2：密码校验结果
**  Return:          密码校验成功返回值为0，否则表示失败。
**  Author:          史宽厚
**  Date:            2015/04/11
***************************************************/
long __stdcall  SD_VerifyPin(long ReaderHandle,unsigned char *PIN,short* Sw1Sw2);

/***************************************************
**  Function:        SD_UnblockChangePin
**  Description:     修改密码
**  Parameter1[In]:  ReaderHandle：设备句柄
**  Parameter2[In]:	 newPin：新密码
**  Return:          操作成功返回值为0，返回值小于0 为错误码
**  Author:          史宽厚
**  Date:            2015/04/11
***************************************************/
long __stdcall  SD_UnblockChangePin(long ReaderHandle,unsigned char *newPin);

/***************************************************
**  Function:        iReadMedicareNO
**  Description:     获取键盘输入
**  Parameter1[In]:  ReaderHandle：设备句柄
**  Parameter2[In]:  ctime：超时时间秒为单位
**  Parameter3[out]:  rlen：返回数据的长度
**  Parameter4[out]:  cpass：返回数据（键盘输入的信息）。
**  Return:          操作成功返回值为0，返回值小于0 为错误码
**  Author:          史宽厚
**  Date:            2015/04/11
***************************************************/
long __stdcall SD_GetInputPass(long ReaderHandle,unsigned char ctime,unsigned char *rlen,unsigned char * cpass);

/***************************************************
**  Function:        iRead4428Info
**  Description:     读取济南老医保卡4428卡的基本信息
**  Parameter1[out]:  char* chCardNum 卡号 0x20 9
**  Parameter2[out]:  Char* chID 身份证号 0x33 18 
**  Parameter3[out]:  Char* chPutCardDate 发卡日期 0x45 8
**  Parameter4[out]:  Char* chName 姓名 0x6A ? 姓名+0x20 。
**  Parameter5[out]:  Char* chWorkAddr工作单位 0x92 ? 单位+0x20 
**  Return:          操作成功返回值为0，返回值小于0 为错误码
**  Author:          史宽厚
**  Date:            2017/05/19
***************************************************/
int __stdcall iRead4428Info(char* chCardNum, char* chID ,char* chPutCardDate,char* chName ,char* chWorkAddr ,  char* pErrMsg);

/***************************************************
**  Function:        iReadPutCardName
**  Description:     读取发卡机构名称
**  Parameter1[out]:  pcMedicareNum：发卡机构名称。
**  Parameter2[out]:  pcErrMsg：函数执行结果的描述信息： 如”成功”
**  Return:          int:操作成功，返回0；否则，返回小于0的错误码，pcErrMsg为错误描述。
**  Author:          史宽厚
**  Date:            2017/05/19
***************************************************/
int __stdcall iReadPutCardName(char* pcPutCardName, char* pcErrMsg);

/***************************************************
**  Function:        readcard
**  Description:     获取银行卡信息
**  Parameter[in]:   amt 交易金额
                     tranType 读卡类型 0:银行卡 1:社保卡
**  Parameter[out]:  track1Data 第一磁道信息
                     track2Data 第二磁道信息
                     track3Data 第三磁道信息
					 SeqNum 第一个字节:是否有卡序列号标志, 0x01 表示有x00表示没有，第二个字节：实际卡序列号
					 Field55 55域信息
**  Return:          操作成功，返回0；否则，返回错误码
***************************************************/
int __stdcall readcard(double amt, char* tranType, char* track1Data, char* track2Data, char* track3Data, char* SeqNum, char* Field55);

/******************************************************************************************************
**  Function:       电动读卡器进卡
**  Parameter[in]:  无
**  Parameter[out]: pOutInfo 出错时返回的错误信息
**  Return:         操作成功返回0；否则返回小于0的错误码
******************************************************************************************************/
int __stdcall iEnterCard(char *pOutInfo);

/******************************************************************************************************
**  Function:       电动读卡器退卡
**  Parameter[in]:  无
**  Parameter[out]: pOutInfo 出错时返回的错误信息
**  Return:         操作成功返回0；否则返回小于0的错误码
******************************************************************************************************/
int __stdcall iExitCard(char *pOutInfo);

/******************************************************************************************************
**  Function:       电动读卡器移卡
**  Parameter[in]:  mode   移卡模式，0-磁条卡位置， 1-接触式位置， 2-非接触式位置
**  Parameter[out]: pOutInfo 出错时返回的错误信息
**  Return:         操作成功返回0；否则返回小于0的错误码
******************************************************************************************************/
int __stdcall iMoveCard(int mode, char *pOutInfo);

/**
* @brief   扫描二维码
* @param[in]: iTimeout    超时时间
* @param[out]: pOutInfo    扫码数据；出错时返回错误信息     
* @return	操作成功返回0；否则返回小于0的错误码
*/
int __stdcall iScan2DBarcode(int iTimeout, char *pOutInfo);

/**
* @brief   读取社保机具唯一识别号
* @param[out]: pUid    唯一识别号
* @param[out]: pOutInfo    出错时返回错误信息     
* @return	操作成功返回0；否则返回小于0的错误码
*/
int __stdcall iReadUid(char *pUid, char *pOutInfo);

/**
* @brief   读取保障号码的功能
* @param[out]:  pcNum：读取的保障号码。
* @param[out]:  pcErrMsg：函数执行结果的描述信息。
* @return	操作成功，返回0；否则，返回小于0的错误码。
*/
int __stdcall iReadSecurityNO(char* pcNum, char* pcErrMsg);

/**
* @brief   读取证件信息。
* @param[in,out]:  piFingerLen:  指纹信息长度。in时，指pucFinger所占的内存空间，建议1024,（为0时不读取指纹信息）;out时，指pucFinger实际读取的的数据长度。
* @param[out]:  pucFinger:  指纹信息，十六进制数据。实际长度为*piFingerLen。
* @param[out]:  pOutInfo:  证件信息列表。具体说明详见Note。
* @return	操作成功返回0；否则返回小于0的错误码。   
* @Note:          
1、外国人居留证,返回数据：
I|英文名|中文姓名|性别|国籍|出生日期|永久居留证号码|证件签发日期|证件终止日期|当次申请受理机关代码|证件版本号|照片 BASE64|
2、港澳台居住证,返回数据：
J|姓名|性别|出生日期|地址|身份证号|签发机关|发卡日期|有效日期|通行证号码|签发次数|照片 BASE64|
3、居民身份证,返回数据：
|姓名|性别|民族|出生日期|地址|身份证号|发卡日期|有效日期|签发机关|照片BASE64|
*/
long __stdcall iReadIdentityCard(int *piFingerLen, unsigned char *pucFinger, char* pOutInfo);

/**
* @brief   获取密码键盘信息
* @par    说明：
*  获取密码键盘信息。
* @param[in]   iType 语音信息，屏幕显示
* @n 0x00 - 不提示语音。
* @n 0x01 - "请输入密码"。
* @n 0x02 - "请再输入一次"。
* @n 0x03 - "请输入原密码"。
* @n 0x04 - "请输入新密码"。
* @param[out]	pOutInfo	成功返回PIN字符串;失败返回错误描述信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iGetPassword(int iType, char* pOutInfo);

/**
* @brief  iOpenDev
* @par    说明：
* 该函数通知终端操作系统打开与读卡器所对应的终端设备接口，以便两者建立通信的逻辑关系, 若打开成功在进行版本和序列号校验。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return 操作成功返回设备标识符；否则返回小于0的错误码，pOutInfo为错误描述。 
******************************************************************************************************/
HANDLE __stdcall iOpenDev(char *pOutInfo);

/**
* @brief  关闭设备。
* @par    说明：
* 关闭设备的通讯和释放资源。
* @param[in] icdev 设备标识符。
* @return <0表示失败，==0表示成功。
*/
int __stdcall iCloseDev(HANDLE icdev);

/**
* @brief  设置打印机参数。
* @par    说明：
* 设置操作打印机的参数。
* @param[in] icdev 设备标识符。
* @param[in] FontSize 字体设置，0x00表示字符大小为8*16，0x01表示字符大小为12*24，0x02表示字符大小为16*32。
* @param[in] Alignment 对齐设置，0x00表示左对齐，0x01表示居中，0x02表示右对齐。
* @param[in] LeftMargin 左边距设置，字符大小为8*16时<48，字符大小为12*24时<32，字符大小为16*32时<24。
* @param[in] RightMargin 右边距设置，字符大小为8*16时<48，字符大小为12*24时<32，字符大小为16*32时<24。
* @param[in] RowPitch 行间隔设置，单位为点。
* @param[in] PrintOutRate 打印速度设置（0x00~0x03），0x00最快，0x03最慢。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iSetPrint(HANDLE icdev, unsigned char FontSize, unsigned char Alignment, unsigned char LeftMargin, unsigned char  RightMargin, unsigned char RowPitch, unsigned char PrintOutRate, char *pOutInfo);

/**
* @brief  查询打印机参数。
* @par    说明：
* 查询操作打印机的参数。
* @param[in] icdev 设备标识符。
* @param[out] FontSize 字体设置，0x00表示字符大小为8*16，0x01表示字符大小为12*24，0x02表示字符大小为16*32。
* @param[out] Alignment 对齐设置，0x00表示左对齐，0x01表示居中，0x02表示右对齐。
* @param[out] LeftMargin 左边距设置，字符大小为8*16时<48，字符大小为12*24时<32，字符大小为16*32时<24。
* @param[out] RightMargin 右边距设置，字符大小为8*16时<48，字符大小为12*24时<32，字符大小为16*32时<24。
* @param[out] RowPitch 行间隔设置，单位为点。
* @param[out] PrintOutRate 打印速度设置（0x00~0x03），0x00最快，0x03最慢。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iCheckPrint(HANDLE icdev, unsigned char *FontSize, unsigned char *Alignment, unsigned char *LeftMargin, unsigned char *RightMargin, unsigned char *RowPitch, unsigned char *PrintOutRate, char *pOutInfo);

/**
* @brief  打印字符。
* @par    说明：
* 打印文本字符信息。
* @param[in] icdev 设备标识符。
* @param[in] length 字符数据的长度，必须小于或等于480。
* @param[in] character 字符数据。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iPrintCharacter(HANDLE icdev, unsigned short length, unsigned char *character, char *pOutInfo);

/**
* @brief  打印一维码。
* @par    说明：
* 打印一维码信息。
* @param[in] icdev 设备标识符。
* @param[in] hight 一维码的高度。
* @param[in] displayflag 显示类型，0x00表示图形在下文本在上，0x01表示图形在上文本在下，0x02表示只显示图形不显示文本。
* @param[in] FontSize 字体设置，0x00表示字符大小为8*16，0x01表示字符大小为12*24，0x02表示字符大小为16*32。
* @param[in] length 文本数据的长度，必须小于或等于15。
* @param[in] Onedimensional 文本数据。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iPrintOnedimensional(HANDLE icdev, unsigned char hight, unsigned char displayflag, unsigned char FontSize, unsigned short length, unsigned char *Onedimensional, char *pOutInfo);

/**
* @brief  进纸。
* @par    说明：
* 进纸到设备内用于打印。
* @param[in] icdev 设备标识符。
* @param[in] RowPitch 进纸行数，单位为点。
* @return <0表示失败，==0表示成功。
*/
int __stdcall iPrintenter(HANDLE icdev, unsigned char RowPitch);

/**
* @brief  获取打印机状态。
* @par    说明：
* 获取打印机的状态。
* @param[in] icdev 设备标识符。
* @param[out] paperstatus 纸状态，0x00表示不缺纸，0x01表示缺纸。
* @param[out] tempturestatus 温度状态，0x00表示温度正常，0x01表示温度过高。
* @param[out] zkstatus 字库状态。
* @n 0x00 - 三种字库都存在。
* @n 0x01 - 三种字库都不存在。
* @n 0x02 - 存在8*16字库。
* @n 0x03 - 存在12*24字库。
* @n 0x04 - 存在16*32字库。
* @n 0x05 - 存在8*16字库和12*24字库。
* @n 0x06 - 存在8*16字库和16*32字库。
* @n 0x07 - 存在12*24字库和16*32字库。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iPrintStatus(HANDLE icdev, unsigned char *paperstatus, unsigned char *tempturestatus, unsigned char *zkstatus, char *pOutInfo);

/**
* @brief  打印图片。
* @par    说明：
* 打印图片信息。
* @param[in] icdev 设备标识符。
* @param[in] length 长度，单位为字节，必须小于或等于48，不能为0。
* @param[in] height 高度，单位为点，必须小于100，不能为0。
* @param[in] Alignment 对齐设置，0x00表示左对齐，0x01表示居中，0x02表示右对齐。
* @param[in] LeftMargin 左边距设置，必须小于或等于48。
* @param[in] RightMargin 右边距设置，必须小于或等于48。
* @param[in] size 图片数据的大小。
* @param[in] Picture 图片数据。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iPrintPicture(HANDLE c_iHandle, unsigned char length, unsigned char height, unsigned char Alignment, unsigned char LeftMargin, unsigned char RightMargin, unsigned short size, unsigned char *Picture, char *pOutInfo);

/**
* @brief  显示图像。
* @par    说明：
* 在屏幕上显示图像，这里的图像指的是前景图像。
* @param[in] icdev 设备标识符。
* @param[in] x 图像显示的起始X坐标。
* @param[in] y 图像显示的起始Y坐标。
* @param[in] w 图像显示的宽度。
* @param[in] h 图像显示的高度。
* @param[in] time_s 显示时间，单位为秒，0表示一直显示。
* @param[in] image_data 图像数据。格式为：【4个字节图像信息长度（Big-Endian）】【图像信息】。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iScreenDisplayImage(HANDLE icdev, int x, int y, int w, int h, int time_s, const unsigned char *image_data, char *pOutInfo);

/**
* @brief  清除显示。
* @par    说明：
* 清除屏幕上的显示，这里清除的显示为前景。
* @param[in] icdev 设备标识符。
* @param[in] x 清除显示的起始X坐标。
* @param[in] y 清除显示的起始Y坐标。
* @param[in] w 清除显示的宽度。
* @param[in] h 清除显示的高度。
* @param[in] time_s 延时清除时间，单位为秒，0表示立即清除。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iScreenClearDisplay(HANDLE icdev, int x, int y, int w, int h, int time_s, char *pOutInfo);

/**
* @brief  装载背景图像。
* @par    说明：
* 装载背景图像到设备内部。
* @param[in] icdev 设备标识符。
* @param[in] number 图像序号，从1开始编号。
* @param[in] image_data 图像数据。格式为：【4个字节图像信息长度（Big-Endian）】【图像信息】。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。 
*/
int __stdcall iScreenLoadBgImage(HANDLE icdev, int number, const unsigned char *image_data, char *pOutInfo);
/**
* @brief  显示背景图像。
* @par    说明：
* 显示设备内部装载的背景图像。
* @param[in] icdev 设备标识符。
* @param[in] number 图像序号，从1开始编号。
* @param[in] x 图像显示的起始X坐标。
* @param[in] y 图像显示的起始Y坐标。
* @param[in] w 图像显示的宽度。
* @param[in] h 图像显示的高度。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iScreenDisplayBgImage(HANDLE icdev, int number, int x, int y, int w, int h, char *pOutInfo);

/**
* @brief  获取显示配置。
* @par    说明：
* 获取显示配置。
* @param[in] icdev 设备标识符。
* @param[in] tag 标签。
* @n 0x01 - 熄屏时间，配置信息长度固定为4个字节，单位为秒（Big-Endian）。如：config_data = {0x04,0x00,0x00,0x00,0x10}表示熄屏时间为16秒。
* @n 0x02 - 显示分辨率，配置信息长度固定为4个字节，前2个字节为水平分辨率（Big-Endian），后2个字节为垂直分辨率（Big-Endian）。如：config_data = {0x04,0x02,0x80,0x01,0xE0}表示分辨率为640x480。
* @param[out] config_data 配置数据。格式为：【1字节配置信息长度】【配置信息】。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iScreenDisplayGetConfig(HANDLE icdev, unsigned char tag, unsigned char *config_data, char *pOutInfo);

/**
* @brief  设置显示配置。
* @par    说明：
* 设置显示配置。
* @param[in] icdev 设备标识符。
* @param[in] tag 标签。
* @n 0x01 - 熄屏时间，配置信息长度固定为4个字节，单位为秒（Big-Endian）。如：config_data = {0x04,0x00,0x00,0x00,0x10}表示熄屏时间为16秒。
* @n 0x02 - 显示分辨率，配置信息长度固定为4个字节，前2个字节为水平分辨率（Big-Endian），后2个字节为垂直分辨率（Big-Endian）。如：config_data = {0x04,0x02,0x80,0x01,0xE0}表示分辨率为640x480。
* @param[in] config_data 配置数据。格式为：【1字节配置信息长度】【配置信息】。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iScreenDisplaySetConfig(HANDLE icdev, unsigned char tag, unsigned char *config_data, char *pOutInfo);

/**
* @brief  显示文字。
* @par    说明：
* 在屏幕上显示文字，注意文字也属于前景。
* @param[in] icdev 设备标识符。
* @param[in] font_size 字体大小。
* @param[in] fg_rgb 文字前景色，3个字节RGB值，第一个字节为R，第二个字节为G，第三个字节为B。
* @param[in] bg_rgb 文字背景色，3个字节RGB值，第一个字节为R，第二个字节为G，第三个字节为B。
* @param[in] x 文字显示的起始X坐标。
* @param[in] y 文字显示的起始Y坐标。
* @param[in] time_s 显示时间，单位为秒，0表示一直显示。
* @param[in] line_flag 换行标志，0表示不自动换行，1表示自动换行。
* @param[in] voice_flag 语音标志，0表示不播放语音，1表示播放语音。
* @param[in] text 文本字符串。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iScreenDisplayText(HANDLE icdev, unsigned char font_size, const unsigned char *fg_rgb, const unsigned char *bg_rgb, int x, int y, int time_s, unsigned char line_flag, unsigned char voice_flag, const char *text, char *pOutInfo);

/**
* @brief  填充背景。
* @par    说明：
* 使用指定颜色填充背景。
* @param[in] icdev 设备标识符。
* @param[in] rgb 颜色，3个字节RGB值，第一个字节为R，第二个字节为G，第三个字节为B。
* @param[in] x 起始X坐标。
* @param[in] y 起始Y坐标。
* @param[in] w 宽度。
* @param[in] h 高度。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iScreenDisplayBgImageByColor(HANDLE icdev, const unsigned char *rgb, int x, int y, int w, int h, char *pOutInfo);

/**
* @brief  显示二维码。
* @par    说明：
* 显示二维码。
* @param[in] icdev 设备标识符。
* @param[in] type 类别，0x01表示正方形二维码。
* @param[in] x 起始X坐标。
* @param[in] y 起始Y坐标。
* @param[in] w 宽度。
* @param[in] h 高度。
* @param[in] content 数据内容
* @param[in] content_len 数据内容的长度。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iScreenDisplay2DBarcode(HANDLE icdev, unsigned char type, int x, int y, int w, int h, const unsigned char *content, int content_len, char *pOutInfo);

/**
* @brief  LCD显示交互。
* @par    说明：
* LCD显示交互。
* @param[in] icdev 设备标识符。
* @param[in] type 格式类型，0x00表示XML格式，0x01表示TLV格式，0x02表示JPEG格式。
* @param[in] slen 发送数据的长度。
* @param[in] sdata 发送数据。
* @param[out] rlen 返回数据的长度。
* @param[out] rdata 返回的数据。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iLcdDisplayInteraction(HANDLE icdev, unsigned char type, unsigned int slen, const unsigned char *sdata, unsigned int *rlen, unsigned char *rdata, char *pOutInfo);

/**
* @brief  LCD显示交互（查询状态）。
* @par    说明：
* LCD显示交互（查询状态）。
* @param[in] icdev 设备标识符。
* @param[in] type 格式类型，0x00表示XML格式，0x01表示TLV格式，0x02表示JPEG格式。
* @param[in] id 用于唯一标识一次完整数据的传输。
* @param[in] size_of_processed_pc_data 表示PC已处理数据的总大小（单位：字节）。
* @param[out] size_of_processed_device_data 表示DEVICE已处理数据的总大小（单位：字节）。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iLcdDisplayInteractionQueryState(HANDLE icdev, unsigned char type, unsigned int id, unsigned int size_of_processed_pc_data, unsigned int *size_of_processed_device_data, char *pOutInfo);

/**
* @brief  T60 LCD显示交互（请求PC→DEVICE数据传输）。
* @par    说明：
* LCD显示交互（请求PC→DEVICE数据传输）。
* @param[in] icdev 设备标识符。
* @param[in] type 格式类型，0x00表示XML格式，0x01表示TLV格式，0x02表示JPEG格式。
* @param[in] id 用于唯一标识一次完整数据的传输。
* @param[in] pc_capacity_size 表示PC每帧中传输数据的最大值（单位：字节）。
* @param[in] data_size 要传输数据的总大小（单位：字节）。
* @param[out] device_capacity_size 表示DEVICE每帧中传输数据的最大值（单位：字节）。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iLcdDisplayInteractionPcToDeviceRequest(HANDLE icdev, unsigned char type, unsigned int id, unsigned int pc_capacity_size, unsigned int data_size, unsigned int *device_capacity_size, char *pOutInfo);

/**
* @brief  T60 LCD显示交互（进行PC→DEVICE数据传输）。
* @par    说明：
* LCD显示交互（进行PC→DEVICE数据传输）。
* @param[in] icdev 设备标识符。
* @param[in] type 格式类型，0x00表示XML格式，0x01表示TLV格式，0x02表示JPEG格式。
* @param[in] id 用于唯一标识一次完整数据的传输。
* @param[in,out] offset 传入PC要发送数据的偏移量（单位：字节）并且返回DEVICE实际接收数据的偏移量（单位：字节）。
* @param[in,out] length 传入PC要发送数据的长度（单位：字节）并且返回DEVICE实际接收数据的长度（单位：字节）。
* @param[in] data 传入PC要发送的数据。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iLcdDisplayInteractionPcToDeviceRun(HANDLE icdev, unsigned char type, unsigned int id, unsigned int *offset, unsigned int *length, const unsigned char *data, char *pOutInfo);

/**
* @brief  T60 LCD显示交互（请求DEVICE→PC数据传输）。
* @par    说明：
* LCD显示交互（请求DEVICE→PC数据传输）。
* @param[in] icdev 设备标识符。
* @param[in] type 格式类型，0x00表示XML格式，0x01表示TLV格式，0x02表示JPEG格式。
* @param[in] id 用于唯一标识一次完整数据的传输。
* @param[in] pc_capacity_size 表示PC每帧中传输数据的最大值（单位：字节）。
* @param[out] device_capacity_size 表示DEVICE每帧中传输数据的最大值（单位：字节）。
* @param[out] data_size 要传输数据的总大小（单位：字节）。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iLcdDisplayInteractionDeviceToPcRequest(HANDLE icdev, unsigned char type, unsigned int id, unsigned int pc_capacity_size, unsigned int *device_capacity_size, unsigned int *data_size, char *pOutInfo);

/**
* @brief  T60 LCD显示交互（进行DEVICE→PC数据传输）。
* @par    说明：
* LCD显示交互（进行DEVICE→PC数据传输）。
* @param[in] icdev 设备标识符。
* @param[in] type 格式类型，0x00表示XML格式，0x01表示TLV格式，0x02表示JPEG格式。
* @param[in] id 用于唯一标识一次完整数据的传输。
* @param[in,out] offset 传入PC要接收数据的偏移量（单位：字节）并且返回DEVICE实际发送数据的偏移量（单位：字节）。
* @param[in,out] length 传入PC要接收数据的长度（单位：字节）并且返回DEVICE实际发送数据的长度（单位：字节）。
* @param[out] data 返回DEVICE实际发送的数据。
* @param[out]:  pOutInfo 错误时返回错误信息
* @return <0表示失败，==0表示成功。
*/
int __stdcall iLcdDisplayInteractionDeviceToPcRun(HANDLE icdev, unsigned char type, unsigned int id, unsigned int *offset, unsigned int *length, unsigned char *data, char *pOutInfo);

/**
* @brief  获取签名公私钥对。
* @par    说明：
* 在卡内产生签名公私钥对，并输出编码后的公钥数据。
* @param[in] pAdminPin 旧的管理员PIN
* @param[in] pUserPin 用户PIN
* @param[out] pOutInfo 返回签名公钥数据或错误信息
* @return <0表示失败，==0表示成功。
*/
long __stdcall iWriteCA_HSM_Step1(char* pAdminPin, char* pUserPin, char* pOutInfo);
/**
* @brief  证书写入。
* @par    说明：
* 证书写入。
* @param[in] QMZS 签名证书
* @param[in] JMZS 加密证书
* @param[in] JMMY 加密密钥
* @param[in] ZKMY 新主控密钥
* @param[in] GLYPIN 新管理员PIN
* @param[in] oldZKMY 旧主控密钥
* @param[out] pOutInfo 返回空字符串或错误信息
* @return <0表示失败，==0表示成功。
*/
long __stdcall iWriteCA_HSM_Step2(char* QMZS, char* JMZS, char* JMMY, char* ZKMY, char* GLYPIN, char* oldZKMY, char* pOutInfo);

#ifdef __cplusplus
}
#endif
#endif