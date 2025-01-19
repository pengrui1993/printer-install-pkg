
#define IFD_OK               0   /*!< �ɹ� */
#define IFD_ICC_TypeError    -1  /*!< ���巴����Ч�� */
#define IFD_ICC_NoExist      -2  /*!< �޿� */
#define IFD_ICC_NoPower      -3  /*!< ��Ƭ�ϵ�ʧ�� */
#define IFD_ICC_NoResponse   -4  /*!< ��Ƭ��Ӧ�� */
#define IFD_ConnectError     -11 /*!< ��д������ʧ�� */
#define IFD_UnConnected      -12 /*!< ��д��δ���� */
#define IFD_BadCommand       -13 /*!< ָ����� */ 
#define IFD_ParameterError   -14 /*!< �������� */
#define IFD_CheckSumError    -15 /*!< MACУ����� */

//ICC�籣����������		����ʱ��������ʹ�á�
_declspec(dllexport)long __stdcall ICC_Reader_Open(char *dev_name);
_declspec(dllexport)long __stdcall ICC_Reader_Close(long ReaderHandle);
_declspec(dllexport)long __stdcall ICC_Reader_PowerOn(long ReaderHandle, unsigned char ICC_Slot_No, unsigned char *Response);
_declspec(dllexport)long __stdcall ICC_Reader_PowerOff(long ReaderHandle, unsigned char ICC_Slot_No);
_declspec(dllexport)long __stdcall ICC_Reader_GetStatus(long ReaderHandle, unsigned char ICC_Slot_No);
_declspec(dllexport)long __stdcall ICC_Reader_Application(long ReaderHandle, unsigned char ICC_Slot_No,
										long Length_of_Command_APDU, unsigned char *Command_APDU, unsigned char *Response_APDU);
_declspec(dllexport)long __stdcall ICC_Reader_Libinfo(char *info);

//===============================================����һ���ָ���==================================================
//�豸������غ���
_declspec(dllexport)HANDLE  __stdcall  QS_Device_Open(short Port,long Baud);
_declspec(dllexport)short  __stdcall QS_Device_Close(HANDLE DeviceHandle);

_declspec(dllexport)short  __stdcall QS_Device_Beep(HANDLE DeviceHandle,unsigned short Msecond);

_declspec(dllexport)short  __stdcall QS_Device_ReadLongVer(HANDLE DeviceHandle, unsigned char *LongVer);
_declspec(dllexport)short  __stdcall QS_Device_ReadDeviceUid(HANDLE DeviceHandle, unsigned char *DeviceUid);
_declspec(dllexport)short __stdcall QS_Device_Read_Data(HANDLE DeviceHandle, short Index, short Length, unsigned char *ReadData);
_declspec(dllexport)short __stdcall QS_Device_Write_Data(HANDLE DeviceHandle, short Index, short Length, unsigned char *WriteData);
_declspec(dllexport) short __stdcall QS_Device_GetVer(HANDLE DeviceHandle, unsigned char *DeviceVer);
_declspec(dllexport) short __stdcall QS_Device_ReadLongVer(HANDLE DeviceHandle, unsigned char *LongVer);
_declspec(dllexport)short __stdcall QS_Device_ReadSAMSN(HANDLE icdev, char *number);
_declspec(dllexport)short __stdcall QS_Device_RFReset(HANDLE DeviceHandle, short MSector);
_declspec(dllexport)short __stdcall QS_Device_SetMode(HANDLE DeviceHandle, unsigned char DeviceMode);
_declspec(dllexport)short __stdcall QS_Device_SetMagMode(HANDLE DeviceHandle, unsigned char mode,unsigned char T1,unsigned char T2 ,unsigned  char T3);
_declspec(dllexport)short __stdcall QS_Device_Play_Voice(HANDLE DeviceHandle, unsigned char VoiceType);

//===============================================����һ���ָ���==================================================
//M1����������
_declspec(dllexport)short __stdcall QS_MF_Card(HANDLE DeviceHandle,unsigned char CardMode,unsigned long *CardSnr);
_declspec(dllexport)short __stdcall QS_MF_Card_Hex(HANDLE DeviceHandle,unsigned char CardMode,char *CardSnr);
_declspec(dllexport)short __stdcall QS_MF_Request(HANDLE DeviceHandle,unsigned char CardMode,unsigned short  *TagType);
_declspec(dllexport)short __stdcall QS_MF_Anticoll(HANDLE DeviceHandle,unsigned char CardMode,unsigned long *CardSnr);
_declspec(dllexport)short __stdcall QS_MF_Select(HANDLE DeviceHandle,unsigned long CardSnr,unsigned char *CardSize);

_declspec(dllexport)short  __stdcall QS_MF_Load_Key(HANDLE DeviceHandle,
							   unsigned char CardMode,
							   unsigned char CardSector,
							   unsigned char *SectorKey);

_declspec(dllexport)short  __stdcall QS_MF_Load_Key_Hex(HANDLE DeviceHandle,
							   unsigned char CardMode,
							   unsigned char CardSector,
							   unsigned char *SectorKey);
_declspec(dllexport)short __stdcall QS_MF_Authentication_Pass_Hex(HANDLE DeviceHandle,
										 unsigned char CardMode,
										 unsigned char CardSector,
										 unsigned char *SectorKey);
_declspec(dllexport)short  __stdcall QS_MF_Authentication(HANDLE DeviceHandle,unsigned char CardMode,unsigned char CardSector);
_declspec(dllexport)short  __stdcall QS_MF_Read(HANDLE DeviceHandle,unsigned char CardBlock,unsigned char *ReceiveData);
_declspec(dllexport)short  __stdcall QS_MF_Read_Hex(HANDLE DeviceHandle,unsigned char CardBlock,unsigned char *ReceiveData);
_declspec(dllexport)short  __stdcall QS_MF_Write(HANDLE DeviceHandle,unsigned char CardBlock,unsigned char *SendData);
_declspec(dllexport)short  __stdcall QS_MF_Write_Hex(HANDLE DeviceHandle,unsigned char CardBlock,unsigned char *SendData);
_declspec(dllexport)short __stdcall QS_MF_Authentication_Pass(HANDLE DeviceHandle,
										 unsigned char CardMode,
										 unsigned char CardSector,
										 unsigned char *SectorKey);
_declspec(dllexport)short __stdcall QS_MF_Authentication_Pass_Hex(HANDLE DeviceHandle,
										 unsigned char CardMode,
										 unsigned char CardSector,
										 unsigned char *SectorKey);
_declspec(dllexport)short __stdcall QS_MF_Halt(HANDLE DeviceHandle);
_declspec(dllexport)short __stdcall QS_MF_Value_Restore(HANDLE icdev, unsigned char BloackAddress);
_declspec(dllexport)short __stdcall QS_MF_Value_Transfer(HANDLE icdev, unsigned char BloackAddress);
_declspec(dllexport)short __stdcall QS_MF_Value_Increment(HANDLE icdev, unsigned char BloackAddress,unsigned long Value);
_declspec(dllexport)short __stdcall QS_MF_Value_Decrement(HANDLE icdev, unsigned char BloackAddress,unsigned long Value);
_declspec(dllexport)short __stdcall QS_MF_Value_Init(HANDLE icdev, unsigned char BloackAddress,unsigned long Value);
_declspec(dllexport)short __stdcall QS_MF_Value_Read(HANDLE icdev, unsigned char BloackAddress,unsigned long *Value);

//===============================================����һ���ָ���==================================================
//�ǽӴ�ʽCPU������
_declspec(dllexport)short __stdcall QS_UnContact_CpuReset(HANDLE DeviceHandle,unsigned char *ResetDataLength,unsigned char *ResetData);
_declspec(dllexport)short __stdcall QS_UnContact_CpuReset_Hex(HANDLE DeviceHandle,unsigned char *ResetDataLength,unsigned char *ResetData);


_declspec(dllexport)short __stdcall QS_UnContact_CpuApdu(HANDLE DeviceHandle,unsigned char SendDataLength,unsigned char * SendData,
							 unsigned char *ReceiveDataLength,unsigned char * ReceiveData);
_declspec(dllexport)short __stdcall QS_UnContact_CpuApdu_Hex(HANDLE DeviceHandle,unsigned char SendDataLength,unsigned char * SendData,
							 unsigned char *ReceiveDataLength,unsigned char * ReceiveData);

//===============================================����һ���ָ���==================================================
//���֤��������

_declspec(dllexport)short __stdcall QS_IDCard_ReadInfo(HANDLE DeviceHandle, char *IDCardData);
_declspec(dllexport)short __stdcall QS_IDCard_SamReadInfo(HANDLE DeviceHandle, short ReadType, 
									  short *TextLength, unsigned char *TextData, 
									  short *PhotoLength, unsigned char *PhotoData, 
									  short *FingerLength, unsigned char *FingerData, 
									  short *ExtDataLength, unsigned char *ExtData);

//���֤���ݽ���
_declspec(dllexport)short __stdcall QS_IDCard_AnalysisTextInfo(HANDLE DeviceHandle, short CharSet, 
											 short TextLength, unsigned char *TextData, 
											 unsigned char *IDCardName, 
											 unsigned char *IDCardSex, 
											 unsigned char *IDCardNation, 
											 unsigned char *IDCardBirthDay, 
											 unsigned char *IDCardAddress, 
											 unsigned char *IDCardNumber, 
											 unsigned char *IDCardDepartment, 
											 unsigned char *IDCardExpireStartDay, 
											 unsigned char *IDCardExpireEndDay, 
											 unsigned char *IDCardReserved);
//����˾�ס֤���ݽ���
_declspec(dllexport)short __stdcall QS_IDCard_AnalysisTextInfoIII(HANDLE DeviceHandle, short CharSet, 
											 short TextLength, unsigned char *TextData, 
											 unsigned char *IDCardEnglish_name, 
											 unsigned char *IDCardSex, 
											 unsigned char *IDCardNumber, 
											 unsigned char *IDCardCitizenship, 
											 unsigned char *IDCardChinese_name, 
											 unsigned char *IDCardExpireStartDay, 
											 unsigned char *IDCardExpireEndDay, 
											 unsigned char *IDCardBirthDay, 
											 unsigned char *IDCardVersion_Number, 
											 unsigned char *IDCardDepartment_Code,
											 unsigned char *IDCardType_Sign,
											 unsigned char *IDCardReserved);
//��̨��ס֤���ݽ���
_declspec(dllexport)short __stdcall QS_IDCard_AnalysisTextInfoHK(HANDLE DeviceHandle, int charset, int TextLength, unsigned char *TextData, 
											  unsigned char *IDCardName, 
											  unsigned char *IDCardSex, 
											  unsigned char *IDCardReserved, 
											  unsigned char *IDCardBirthDay, 
											  unsigned char *IDCardAddress, 
											  unsigned char *IDCardNumber, 
											  unsigned char *IDCardDepartment, 
											  unsigned char *IDCardExpireStartDay, 
											  unsigned char *IDCardExpireEndDay, 
											  unsigned char *IDCardPass_Number, 
											  unsigned char *IDCardSign_Count, 
											  unsigned char *IDCardReserved2, 
											  unsigned char *IDCardType_Sign, 
											  unsigned char *IDCardReserved3);


//��Ƭ����
_declspec(dllexport)short __stdcall QS_IDCard_AnalysisPhoto(HANDLE DeviceHandle, int PhotoType, 
											 int PhotoLength, unsigned char *PhotoData, 
											 int *ReadPhotoLength, unsigned char *ReadPhotoData);


//===============================================����һ���ָ���==================================================
//�Ӵ�ʽCPU������
_declspec(dllexport)short __stdcall QS_Contact_CardStatus(HANDLE DeviceHandle,unsigned char CardNumber);
_declspec(dllexport)short __stdcall QS_Contact_CardDown(HANDLE DeviceHandle,unsigned char CardNumber);
_declspec(dllexport)short __stdcall QS_Contact_SetCpu(HANDLE DeviceHandle,unsigned char CardNumber);
_declspec(dllexport)short __stdcall QS_Contact_CpuReset(HANDLE DeviceHandle,unsigned char *ResetDataLength,unsigned char *ResetData);
_declspec(dllexport)short __stdcall QS_Contact_CpuReset_Hex(HANDLE DeviceHandle,unsigned char *ResetDataLength,unsigned char *ResetData);
_declspec(dllexport)short __stdcall QS_Contact_CpuApdu(HANDLE DeviceHandle,unsigned char SendDataLength,unsigned char * SendData,
							 unsigned char *ReceiveDataLength,unsigned char * ReceiveData);
_declspec(dllexport)short __stdcall QS_Contact_CpuApdu_Hex(HANDLE DeviceHandle,unsigned char SendDataLength,unsigned char * SendData,
							 unsigned char *ReceiveDataLength,unsigned char * ReceiveData);

_declspec(dllexport)short __stdcall QS_Contact_CpuApduExt(HANDLE DeviceHandle,int SendDataLength,unsigned char * SendData,
							  int *ReceiveDataLength,unsigned char * ReceiveData);

_declspec(dllexport)short __stdcall QS_Contact_CpuApduExt_Hex(HANDLE DeviceHandle,int SendDataLength,unsigned char * SendData,
							  int *ReceiveDataLength,unsigned char * ReceiveData);

_declspec(dllexport)short __stdcall QS_Contact_Check4428(HANDLE icdev);
_declspec(dllexport)short __stdcall QS_Contact_Read4428(HANDLE icdev, short offset,short length,unsigned char * Data);

_declspec(dllexport)short __stdcall QS_Contact_Check4442(HANDLE icdev);
_declspec(dllexport)short __stdcall QS_Contact_Read4442(HANDLE icdev, short offset,short length,unsigned char * Data);

_declspec(dllexport)short __stdcall QS_Contact_Check24C64( HANDLE icdev);
_declspec(dllexport)short __stdcall QS_Contact_Read24C64( HANDLE icdev, short offset, short length, unsigned char *Data);

//===============================================����һ���ָ���==================================================


//���ſ���Ϣ
//
_declspec(dllexport)short __stdcall QS_MagCard_Read(HANDLE DeviceHandle,unsigned char TimeOut,
								  unsigned char * Track1Data,  unsigned int * Track1Len,
								  unsigned char * Track2Data,  unsigned int * Track2Len,
								  unsigned char * Track3Data,  unsigned int * Track3Len);
//
_declspec(dllexport)short __stdcall QS_MagCard_Read_01(HANDLE DeviceHandle,unsigned char TimeOut,
								  unsigned char * Track1Data,  unsigned int * Track1Len,
								  unsigned char * Track2Data,  unsigned int * Track2Len,
								  unsigned char * Track3Data,  unsigned int * Track3Len);
//
_declspec(dllexport)short __stdcall QS_MagCard_Read_02(HANDLE DeviceHandle,int MSecTimeOut,
								  unsigned char * Track1Data,  unsigned int * Track1Len,
								  unsigned char * Track2Data,  unsigned int * Track2Len,
								  unsigned char * Track3Data,  unsigned int * Track3Len);

_declspec(dllexport)short __stdcall QS_MagCard_Start(HANDLE DeviceHandle);
_declspec(dllexport)short __stdcall QS_MagCard_GetData(HANDLE DeviceHandle,  unsigned int *Track1Len,unsigned char *Track1Data,unsigned int *Track2Len,unsigned char *Track2Data, unsigned int *Track3Len,unsigned char *Track3Data);
_declspec(dllexport)short __stdcall QS_MagCard_Stop(HANDLE DeviceHandle);




//EM2�綯��������ؽӿ�
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceCardStatus(HANDLE DeviceHandle, unsigned char *status);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceCardInject(HANDLE DeviceHandle, unsigned char time_s, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceCardEject(HANDLE DeviceHandle, unsigned char time_s, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceCardMove(HANDLE DeviceHandle, unsigned char time_s, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceSensorStatus(HANDLE DeviceHandle, unsigned char *value);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceConfig(HANDLE DeviceHandle, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceConfigFront(HANDLE DeviceHandle, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceConfigBack(HANDLE DeviceHandle, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceConfigPlace(HANDLE DeviceHandle, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceCheckCardType(HANDLE DeviceHandle);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceReset(HANDLE DeviceHandle);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceWriteMagConfig(HANDLE DeviceHandle, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceShakeConfig(HANDLE DeviceHandle, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceSetFrontSwitch(HANDLE DeviceHandle, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceGetFrontSwitch(HANDLE DeviceHandle, unsigned char *mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceRecoverError(HANDLE DeviceHandle, unsigned char type);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceSensorStatusEx(HANDLE DeviceHandle, int *rlen, unsigned char *rdata);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceKeepUpDown(HANDLE DeviceHandle, unsigned char mode);
_declspec(dllexport)short __stdcall QS_EM2_SelfServiceDeviceWriteMag(HANDLE DeviceHandle, const unsigned char *t1_data, int t1_len, const unsigned char *t2_data, int t2_len, const unsigned char *t3_data, int t3_len);



//short __stdcall QS_Package_ReadMagCard(HANDLE DeviceHandle, char * ReciveData);
//���P3���� ����
_declspec(dllexport)short __stdcall QS_P3_GetVersion(HANDLE DeviceHandle,char * VerSion);
_declspec(dllexport)short __stdcall QS_P3_Status(HANDLE DeviceHandle);
_declspec(dllexport)short __stdcall QS_P3_ReadKey(HANDLE DeviceHandle,char * key, unsigned char VoiceType,unsigned char TimeOut);
_declspec(dllexport)short __stdcall QS_P3_ReadQRCode(HANDLE DeviceHandle,unsigned char * QRCode,unsigned char TimeOut);
_declspec(dllexport)short __stdcall QS_P3_ReadQRCode02(HANDLE DeviceHandle,unsigned char * QRCodeLength,unsigned char * QRCode,unsigned char TimeOut);
_declspec(dllexport)short __stdcall QS_P3_PlayVoice(HANDLE DeviceHandle, unsigned char VoiceType);

_declspec(dllexport)short __stdcall QS_P3_QRCode_Start(HANDLE DeviceHandle);
_declspec(dllexport)short __stdcall QS_P3_QRCode_GetData(HANDLE DeviceHandle,int *QRCodeLength,unsigned char *QRCode);
_declspec(dllexport)short __stdcall QS_P3_QRCode_Stop(HANDLE DeviceHandle);


//ɨ��ӿ�
_declspec(dllexport)short __stdcall QS_ReadQRCode(HANDLE DeviceHandle,unsigned char * QRCode,unsigned char TimeOut);

_declspec(dllexport)short __stdcall QS_QRCode_Start(HANDLE DeviceHandle);
_declspec(dllexport)short __stdcall QS_QRCode_GetData(HANDLE DeviceHandle,int *QRCodeLength,unsigned char *QRCode);
_declspec(dllexport)short __stdcall QS_QRCode_Stop(HANDLE DeviceHandle);

//ɨ��ӿ�
_declspec(dllexport)short __stdcall QS_ReadQRCode02(HANDLE DeviceHandle,unsigned char * CodeLength,unsigned char * QRCode,unsigned char TimeOut);


//��װ ����
//���ſ�
_declspec(dllexport)short __stdcall QS_Package_ReadMagCard(HANDLE DeviceHandle, char * ReciveData);
_declspec(dllexport)short __stdcall QS_Package_ReadMagCard_01(HANDLE DeviceHandle, char * ReciveData);
//�������籣��
_declspec(dllexport)short __stdcall QS_Package_ReadSBCardInfo(HANDLE DeviceHandle, char * ReciveData);
_declspec(dllexport)short __stdcall QS_Package_ReadSBCardHolderInfo(HANDLE DeviceHandle, char * SBReciveData);
//�����֤
_declspec(dllexport)short __stdcall QS_Package_ReadIDCard(HANDLE DeviceHandle, char * IDCardReciveData,char * BmpFileName);
//���������˿�
_declspec(dllexport)short __stdcall QS_Package_ReadGZElderlyCard(HANDLE DeviceHandle, char * ReciveData);

//����خ������
_declspec(dllexport)short __stdcall QS_Package_ReadMSCard(HANDLE DeviceHandle, char * ReciveData);

//������װ
_declspec(dllexport)short __stdcall QS_Package_No(HANDLE DeviceHandle, short MyType ,short MyInData1, unsigned char * MyInData2,char * MyOutData);

_declspec(dllexport)short __stdcall QS_Package_ReadM1CardA(HANDLE DeviceHandle,unsigned char Sector,char * Key,char * ReciveData);
/*
˵����ʹ��A������֤������ȡM1��ָ������������
������	DeviceHandle	���
		Sector			������
		Key				���������ַ���
		ReciveData		���������ݣ�4���������Է��š�|������
����ֵ���ɹ�����0
*/


_declspec(dllexport)short __stdcall QS_Package_ReadM1CardB(HANDLE DeviceHandle,unsigned char Sector,char * Key,char * ReciveData);
/*
˵����ʹ��B������֤������ȡM1��ָ������������
������	DeviceHandle	���
		Sector			������
		Key				���������ַ���
		ReciveData		���������ݣ�4���������Է��š�|������
����ֵ���ɹ�����0
*/

_declspec(dllexport)short __stdcall QS_Package_WriteM1CardA(HANDLE DeviceHandle,unsigned char Sector,char * Key,char * SendData);
/*
˵����ʹ��A������֤������ȡM1��ָ������������
������	DeviceHandle	���
		Sector			������
		Key				���������ַ���
		SendData		д������ݣ�4���������Է��š�|����������ע�������ĸ�ʽ
						AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA|BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB|CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC|ffffffffffffff078069ffffffffffff
����ֵ���ɹ�����0
*/

_declspec(dllexport)short __stdcall QS_Package_WriteM1CardB(HANDLE DeviceHandle,unsigned char Sector,char * Key,char * SendData);
/*
˵����ʹ��B������֤������ȡM1��ָ������������
������	DeviceHandle	���
		Sector			������
		Key				���������ַ���
		SendData		д������ݣ�4���������Է��š�|����������ע�������ĸ�ʽ
						AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA|BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB|CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC|ffffffffffffff078069ffffffffffff
����ֵ���ɹ�����0
*/


//T60 Lcd ��ʾ���ƽӿ�

_declspec(dllexport)short __stdcall QS_LcdDisplayInteraction(HANDLE icdev, unsigned char type, unsigned int slen, const unsigned char *sdata, unsigned int *rlen, unsigned char *rdata);
_declspec(dllexport)short __stdcall QS_LcdDisplayInteractionQueryState(HANDLE icdev, unsigned char type, unsigned int id, unsigned int size_of_processed_pc_data, unsigned int *size_of_processed_device_data);
_declspec(dllexport)short __stdcall QS_LcdDisplayInteractionPcToDeviceRequest(HANDLE icdev, unsigned char type, unsigned int id, unsigned int pc_capacity_size, unsigned int data_size, unsigned int *device_capacity_size);
_declspec(dllexport)short __stdcall QS_LcdDisplayInteractionPcToDeviceRun(HANDLE icdev, unsigned char type, unsigned int id, unsigned int *offset, unsigned int *length, const unsigned char *data);
_declspec(dllexport)short __stdcall QS_LcdDisplayInteractionDeviceToPcRequest(HANDLE icdev, unsigned char type, unsigned int id, unsigned int pc_capacity_size, unsigned int *device_capacity_size, unsigned int *data_size);
_declspec(dllexport)short __stdcall QS_LcdDisplayInteractionDeviceToPcRun(HANDLE icdev, unsigned char type, unsigned int id, unsigned int *offset, unsigned int *length, unsigned char *data);

//��ӡ�����

_declspec(dllexport)short __stdcall QS_Printer_SetSetting(HANDLE DeviceHandle, 
	unsigned char FontSize,
	unsigned char Alignment, 
	unsigned char LeftMargin, 
	unsigned char RightMargin, 
	unsigned char RowPitch, 
	unsigned char PrintOutRate);

_declspec(dllexport) short __stdcall QS_Printer_GetSetting(HANDLE DeviceHandle,
	  unsigned char *FontSize, 
	  unsigned char *Alignment, 
	  unsigned char *LeftMargin, 
	  unsigned char *RightMargin, 
	  unsigned char *RowPitch, 
	  unsigned char *PrintOutRate);

_declspec(dllexport) short __stdcall QS_Printer_PrintChar(HANDLE DeviceHandle, 
		unsigned short length, 
		unsigned char *character);

_declspec(dllexport) short __stdcall QS_Printer_PrintBarCode(HANDLE DeviceHandle, 
	  unsigned char hight, 
	  unsigned char displayflag, 
	  unsigned char FontSize, 
	  unsigned short length, 
	  unsigned char *Onedimensional);

_declspec(dllexport) short __stdcall QS_Printer_PrintPicture(HANDLE DeviceHandle,  
	  unsigned char length, 
	  unsigned char height, 
	  unsigned char Alignment, 
	  unsigned char LeftMargin, 
	  unsigned char RightMargin, 
	  unsigned short size, 
	  unsigned char *Picture);

_declspec(dllexport) short __stdcall QS_Printer_Enter(HANDLE DeviceHandle,unsigned char RowPitch);
  
_declspec(dllexport) short __stdcall QS_Printer_GetStatus(HANDLE DeviceHandle,  
	  unsigned char *paperstatus, 
	  unsigned char *tempturestatus, 
	  unsigned char *zkstatus);



//�����籣�����������

_declspec(dllexport)long __stdcall iReadCardBas(int iType,char *pOutInfo);
_declspec(dllexport)long __stdcall iReadCard(int iType,int iAuthType,char* pCardInfo,char* pFileAddr,char *pOutInfo);
_declspec(dllexport)long __stdcall iWriteCard(int iType,char* pCardInfo,char* pFileAddr,char* pWriteData,char *pOutInfo);
_declspec(dllexport)long __stdcall iVerifyPIN(int iType,char* pOutInfo);	
_declspec(dllexport)long __stdcall iChangePIN(int iType,char* pOutInfo);
_declspec(dllexport)long __stdcall iReloadPIN(int iType,char *pCardInfo,char* pOutInfo);
_declspec(dllexport)long __stdcall iUnblockPIN(int iType,char*pCardInfo,char* pOutInfo);
_declspec(dllexport)long __stdcall iDoDebit(int iType,char*pCardInfo,char* pPayInfo,char* pOutInfo);


//���籣����Ϣ����Ҫ����PSAM����
_declspec(dllexport)short __stdcall QS_ReadSBCardBySam(char *pOutInfo);


//SBCard
_declspec(dllexport)short __stdcall QS_SBCard_Reset(HANDLE DeviceHandle,unsigned char ucICC_Slot_No,char * pOutInfo );
_declspec(dllexport)short __stdcall QS_SBCard_APDU(HANDLE DeviceHandle,char * pInInfo,char * pOutInfo);

_declspec(dllexport)short __stdcall QS_SBCard_SelectDF(HANDLE DeviceHandle,char * pOutInfo );
_declspec(dllexport)short __stdcall QS_SBCard_SelectEF05(HANDLE DeviceHandle,char * pOutInfo);
//_declspec(dllexport)short __stdcall QS_SBCard_ReadEF05_01(HANDLE DeviceHandle,char * pOutInfo );
//_declspec(dllexport)short __stdcall QS_SBCard_ReadBin(HANDLE DeviceHandle,char * pInInfo,char * pOutInfo);
//_declspec(dllexport)short __stdcall QS_SBCard_ReadBinToString(HANDLE DeviceHandle,char * pInInfo,char * pOutInfo);
_declspec(dllexport)char * __stdcall QS_SBCard_ReadBin(HANDLE DeviceHandle,char * pInInfo);
_declspec(dllexport)char * __stdcall QS_SBCard_ReadBinToString(HANDLE DeviceHandle,char * pInInfo);

_declspec(dllexport)short __stdcall QS_SBCard_ReadCardInfo(HANDLE DeviceHandle,char * pOutInfo );
_declspec(dllexport)short __stdcall QS_SBCard_ReadHoderInfo(HANDLE DeviceHandle,char * pOutInfo );

//��������

_declspec(dllexport)void __stdcall QS_Assist_GetMyErrorInfo(char * ErrorInfo);
_declspec(dllexport)void __stdcall QS_Assist_GetDeviceInfo(char * DeviceInfo);

_declspec(dllexport)short __stdcall QS_Assist_HexToA(unsigned char *HexString, unsigned char *a, short Length);
_declspec(dllexport)short __stdcall QS_Assist_AToHex(unsigned char *a, unsigned char *HexString, short Length);

_declspec(dllexport)short __stdcall QS_Assist_Des(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);
_declspec(dllexport)short __stdcall QS_Assist_TDes(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);


_declspec(dllexport)short __stdcall QS_Assist_05(unsigned char *skey, unsigned char *ptrSource,unsigned short msgLen,unsigned char *ptrDest);

_declspec(dllexport)short __stdcall iReaderGetPass(unsigned char ctimeout, char *cdsp, unsigned char audiocmd,unsigned char *cpasslen, char * cpass);
