; (����Ա������У���ѡ�񡰹��� | ѡ�� | ʼ���Թ���Ա��ݰ�װж�ء���)

; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

[Setup]
; ע��: AppId ֵ����Ψһʶ���Ӧ�ó���
; ��ֹ������Ӧ�ó���İ�װ��ʹ����ͬ�� AppId ֵ��
; (��Ҫ����һ���µ� GUID����ѡ�񡰹��� | ���� GUID����)
AppId={{43A0DB27-40E7-4D7B-B506-C635A5588103}

;�м��������
AppName=HttpPrinter
AppVerName=HttpPrinter
;��˾����
AppPublisher=ɽ���������ܿƼ����޹�˾
;��ַ
AppPublisherURL=http://www.HttpPrinter.com
AppSupportURL=http://www.HttpPrinter.com
AppUpdatesURL=http://www.HttpPrinter.com;��װĿ¼
DefaultDirName=D:\yiqiao\HttpPrinter
;��˾���
DefaultGroupName=���ſƼ�
;���Э���ͼ��,��ʹ�õĻ�,����ǰ��� �ֺ� ����ע������
;LicenseFile=������Э��.txt
;WizardImageFile=���ͼ��.bmp
;WizardSmallImageFile=����ͼ��.bmp


LicenseFile=������Э��.txt
WizardImageFile=���ͼ��.bmp
WizardSmallImageFile=����ͼ��.bmp

;��װ�ļ�����Ŀ¼
OutputDir=.
;��װ�ļ�����
OutputBaseFilename=HttpPrinter_setup
Compression=lzma
SolidCompression=true
DirExistsWarning=no
;��װʱ����ѡ��װ·��
DisableDirPage=no



[Languages]
Name: chinese; MessagesFile: compiler:Default.isl

[Tasks]
;Name: MDAC; Description: Microsoft Data Access Components; Flags: checkedonce restart; MinVersion: 4.0,4.0; OnlyBelowVersion: 0,5.0

[Messages]
BeveledLabel=ɽ���������ܿƼ����޹�˾ http://www.HttpPrinter.com


[Files]

;���ļ�
Source: HttpPrinter.exe; DestDir: {app}; Flags: ignoreversion
Source: HttpPrinter.exe.manifest; DestDir: {app}; Flags: ignoreversion 

Source: gridreport_reg.exe; DestDir: {app}; Flags: ignoreversion
Source: gridreport�޷�ʹ��_��ִ��gridreport_reg.exe.txt; DestDir: {app}; Flags: ignoreversion


Source: picprint.exe; DestDir: {app}; Flags: ignoreversion
Source: pdfprint.exe; DestDir: {app}; Flags: ignoreversion
Source: printlog.exe; DestDir: {app}; Flags: ignoreversion
Source: reportdesign.exe; DestDir: {app}; Flags: ignoreversion
Source: printreport.exe; DestDir: {app}; Flags: ignoreversion

Source: jsontoexcel.exe; DestDir: {app}; Flags: ignoreversion
Source: pdfviewer.exe; DestDir: {app}; Flags: ignoreversion

;���֤ͼƬ������Ȩ�ļ�
Source: license.dat; DestDir: {app}; Flags: ignoreversion

Source: ������־.txt; DestDir: {app}; Flags: ignoreversion
Source: ˵���ĵ�.txt; DestDir: {app}; Flags: ignoreversion
Source: logo.bmp; DestDir: {app}; Flags: onlyifdoesntexist
Source: token.txt; DestDir: {app}; Flags: onlyifdoesntexist
Source: oem.lic; DestDir: {app}; Flags: onlyifdoesntexist

Source: borlndmm.dll; DestDir: {app}; Flags: onlyifdoesntexist

Source: libeay32.dll; DestDir: {app}; Flags: onlyifdoesntexist
Source: ssleay32.dll; DestDir: {app}; Flags: onlyifdoesntexist

Source: pdfium.dll; DestDir: {app}; Flags: onlyifdoesntexist

Source: test.fr3; DestDir: {app}; Flags: onlyifdoesntexist
Source: test.fr3.sdb; DestDir: {app}; Flags: onlyifdoesntexist
Source: test.grf; DestDir: {app}; Flags: onlyifdoesntexist
Source: test.rls; DestDir: {app}; Flags: onlyifdoesntexist
Source: test.rls.sdb; DestDir: {app}; Flags: onlyifdoesntexist


;���ݿ�������ļ� ������ onlyifdoesntexist  ��ж�� uninsneveruninstall
Source: config.ini; DestDir: {app}; Flags: onlyifdoesntexist uninsneveruninstall
Source: GRDesigner.ini; DestDir: {app}; Flags: onlyifdoesntexist uninsneveruninstall


 ;���տؼ�
;Source: CameraOCX.ocx; DestDir: {sys}; Flags: onlyifdoesntexist uninsneveruninstall

      

;��ʽ
;Source: pic\*.*; DestDir: {app}\pic; Flags: onlyifdoesntexist uninsneveruninstall;

;��ʽ
;Source: styles\*.*; DestDir: {app}\styles; Flags: ignoreversion;

;����
Source: report\*; DestDir: {app}\report; Flags: onlyifdoesntexist recursesubdirs createallsubdirs ;  
;Source: report\*.*; DestDir: {app}\report; Flags: onlyifdoesntexist;  
;Source: jc_report\*.*; DestDir: {app}\jc_report; Flags: onlyifdoesntexist;  



;�����ļ��м����ļ���

Source: "idcard\*"; DestDir: "{app}\idcard"; Flags: igNoreversion recursesubdirs createallsubdirs 
;Source: "pdfedit\*"; DestDir: "{app}\pdfedit"; Flags: onlyifdoesntexist recursesubdirs createallsubdirs ; 

Source: "language\*"; DestDir: "{app}\language"; Flags: onlyifdoesntexist recursesubdirs createallsubdirs ; 


;Source: ����_����.grf; DestDir: {app}; Flags: ignoreversion
;Source: ����_����.grf; DestDir: {app}; Flags: ignoreversion


;ͼ���Э��
Source: ����ͼ��.bmp; DestDir: {app}; Flags: ignoreversionSource: ������Э��.txt; DestDir: {app}; Flags: ignoreversion
Source: ���ͼ��.bmp; DestDir: {app}; Flags: ignoreversion
Source: HttpPrinter����Ȩ.jpg; DestDir: {app}; Flags: ignoreversion



;�������
Source: grdesigner6.exe; DestDir: {app}; Flags: ignoreversion
Source: grdviewer6.exe; DestDir: {app}; Flags: ignoreversion

Source: grdes6.dll; DestDir: {app}; Flags: ignoreversion
Source: gregn6.dll; DestDir: {app}; Flags: ignoreversion
Source: grmysql6.dll; DestDir: {app}; Flags: ignoreversion
Source: grreg6.dll; DestDir: {app}; Flags: ignoreversion
Source: reg.dll; DestDir: {app}; Flags: ignoreversion

;Source: grdesigner50.exe; DestDir: {app}; Flags: ignoreversion
;Source: grdviewer50.exe; DestDir: {app}; Flags: ignoreversion




;ϵͳ�����ļ� Windows ϵͳ��System��Ŀ¼���� Windows NT/2000 ���� System32����
;Source: w95scm.dll; DestDir: {sys}; Flags: onlyifdoesntexist uninsneveruninstall
;Source: qtintf70.dll; DestDir: {sys}; Flags: onlyifdoesntexist uninsneveruninstall
;Source: ntdll.dll; DestDir: {sys}; Flags: onlyifdoesntexist uninsneveruninstall

;ISTask.dll  ��������Dll
Source: ISTask.dll; DestDir: {app}; Flags: ignoreversion


;ע�����
; START regtypelib
;Source: "DLL�ļ�����·��"; DestDir: "{app}"; Flags:ignoreversion regserver uninsneveruninstall noregerror
;Source: "DLL�ļ�����·��"; DestDir: "{app}"; Flags:regtypelib uninsneveruninstall noregerror
;����Flags:�ε�regserver��������ע��
;ignoreversion ���԰汾
;regserver��ע��activeX DLl/OCX
;regtypelib��ע�����Ϳ�TLB
;restartreplace�����ļ���ʹ�������滻
;noregerror��ע��ʧ�ܲ���ʾ������Ϣ
;replacesameversion���滻��ͬ�汾
;uninsnosharedfileprompt��ж��ʱ�����ֹ����ļ���ʾ
;sharedfile����Ϊ�����ļ�
;sharedfile����Ϊ�����ļ�"

Source: grdes6.dll; DestDir: {app}; Flags: ignoreversion regserver uninsneveruninstall noregerror 
Source: grdes6.dll; DestDir: {app}; Flags: regtypelib uninsneveruninstall noregerror 

Source: gregn6.dll; DestDir: {app}; Flags: ignoreversion regserver uninsneveruninstall noregerror 
Source: gregn6.dll; DestDir: {app}; Flags: regtypelib uninsneveruninstall noregerror 





;Source: grdes50.dll; DestDir: {app}; Flags: ignoreversion regserver uninsneveruninstall noregerror 
;Source: grdes50.dll; DestDir: {app}; Flags: regtypelib uninsneveruninstall noregerror 

;Source: gregn50.dll; DestDir: {app}; Flags: ignoreversion regserver uninsneveruninstall noregerror 
;Source: gregn50.dll; DestDir: {app}; Flags: regtypelib uninsneveruninstall noregerror 

;Source: CameraOCX.ocx; DestDir: {sys}; Flags: regserver uninsneveruninstall noregerror
;Source: CameraOCX.ocx; DestDir: {sys}; Flags: regtypelib uninsneveruninstall noregerror

; END regtypelib


; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��



;��������MCAC�汾
; START MDAC
;Source: mdac_typ.exe; DestDir: {app}; Flags: ignoreversion
;Source: mdac_typ.exe; DestDir: {%TEMP}; MinVersion: 4.0,0; OnlyBelowVersion: 4.1,0; Tasks: MDAC; Flags: ignoreversion
;Source: mdac_typ.exe; DestDir: {tmp}; MinVersion: 4.1,4.0; OnlyBelowVersion: 0,5.0; Tasks: MDAC; Flags: ignoreversion
; END MDAC



[Registry]
;ע��������������
;Root: HKLM; Subkey: "software\Microsoft\Windows\CurrentVersion\Run"; ValueType: string; ValueName: "bugsky"; ValueData: "{app}\HttpPrinter.exe"; Flags: uninsdeletevalue

;ע���������Լ��ĳ�����Ϣ
Root: HKLM; Subkey: software\bugsky; ValueType: string; ValueName: Install; ValueData: {app}; Flags: uninsdeletevalue


;*.grf  Associations  ��������
;Root: HKCR; Subkey: ".grf"; ValueType: string; ValueName: ""; ValueData: "MyReport"; Flags: uninsdeletevalue
;Root: HKCR; Subkey: "MyReport"; ValueType: string; ValueName: ""; ValueData: "MyReport"; Flags: uninsdeletekey
;Root: HKCR; Subkey: "MyReport\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\grdesigner6.exe,0"
;Root: HKCR; Subkey: "MyReport\shell\open\command"; ValueType: string; ValueName: ""; ValueData: """{app}\grdesigner6.exe"" ""%1"""




; Delay MDAC installation on Win95 machines
;MDAC 2.0+
;Root: HKCU; Subkey: SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce; ValueType: string; ValueName: MDAC_Setup; ValueData: """{%TEMP}\mdac_typ.exe"" /Q /C:""setup /QT"""; MinVersion: 4.0,0; OnlyBelowVersion: 4.1,0; Tasks: MDAC
;MDAC 2.6+
;Root: HKCU; Subkey: SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce; ValueType: string; ValueName: MDAC_Setup; ValueData: """{%TEMP}\mdac_typ.exe"" /Q:A /C:""dasetup /Q:D /N"""; MinVersion: 4.0,0; OnlyBelowVersion: 4.1,0; Tasks: MDAC

[Icons]
Name: {group}\HttpPrinter\HttpPrinter; Filename: {app}\HttpPrinter.exe
Name: {group}\HttpPrinter\HttpPrinter����; Filename: http://www.HttpPrinter.com
Name: {group}\HttpPrinter\{cm:UninstallProgram,HttpPrinter}; Filename: {uninstallexe}

Name: {commondesktop}\HttpPrinter; Filename: {app}\HttpPrinter.exe


[InstallDelete]
;ɾ�� show.txt
;Name: "{app}\����_����.grf" ; Type: filesandordirs
                    

;ɾ����ݷ�ʽ

[UninstallDelete]
;ж��ʱɾ���ļ����ļ���

[Run]
Filename: {app}\HttpPrinter.exe; Description: {cm:LaunchProgram,HttpPrinter}; Flags: nowait postinstall skipifsilent
;Filename: {app}\Readme.txt; Description: �鿴˵��; Flags: nowait postinstall shellexec

; START MDAC 2.0+ (see also: http://support.microsoft.com/default.aspx?scid=KB;EN-US;Q192009&)
;Filename: {tmp}\mdac_typ.exe; Parameters: "/Q /C:""setup /QNT"""; WorkingDir: {tmp}; Flags: skipifdoesntexist; Tasks: MDAC; MinVersion: 4.1,4.0; OnlyBelowVersion: 0,5.0
; END MDAC 2.0+
; START MDAC 2.6+ (see also: http://msdn.microsoft.com/library/default.asp?url=/library/en-us/mdacsdk/htm/wphistory_redistributemdac.asp)
;Filename: {tmp}\mdac_typ.exe; Parameters: "/Q:A /C:""dasetup /Q:D /N"""; WorkingDir: {tmp}; Flags: skipifdoesntexist; Tasks: MDAC; MinVersion: 4.1,4.0; OnlyBelowVersion: 0,5.0
; END MDAC 2.6+


[Code]


procedure DirectoryCopy(SourcePath, DestPath: string);
var
  FindRec: TFindRec;
  SourceFilePath: string;
  DestFilePath: string;
begin
  if FindFirst(SourcePath + '\*', FindRec) then
  begin
    try
      repeat
        if (FindRec.Name <> '.') and (FindRec.Name <> '..') then
        begin
          SourceFilePath := SourcePath + '\' + FindRec.Name;
          DestFilePath := DestPath + '\' + FindRec.Name;
          if FindRec.Attributes and FILE_ATTRIBUTE_DIRECTORY = 0 then
          begin
            if FileCopy(SourceFilePath, DestFilePath, False) then
            begin
              Log(Format('Copied %s to %s', [SourceFilePath, DestFilePath]));
            end
              else
            begin
              Log(Format('Failed to copy %s to %s', [SourceFilePath, DestFilePath]));
            end;
          end
            else
          begin
            if DirExists(DestFilePath) or CreateDir(DestFilePath) then
            begin
              Log(Format('Created %s', [DestFilePath]));
              DirectoryCopy(SourceFilePath, DestFilePath);
            end
              else
            begin
              Log(Format('Failed to create %s', [DestFilePath]));
            end;
          end;
        end;
      until not FindNext(FindRec);
    finally
      FindClose(FindRec);
    end;
  end
    else
  begin
    Log(Format('Failed to list %s', [SourcePath]));
  end;
end;


//��װʱɾ��{app}Ŀ¼�������ļ�;
procedure CurStepChanged(CurStep: TSetupStep);
var
  DestPath,DestPath_report: string; //DestPath_jc_report
begin
  if CurStep=ssInstall then    
  begin
    DestPath := ExpandConstant('{app}\bak\'+GetDateTimeString('yyyymmddhhnnss', '-', ':')+inttostr(Random(9))+inttostr(Random(9))+inttostr(Random(9))+inttostr(Random(9))); 
    DestPath_report := DestPath +'\report';
    //DestPath_jc_report := DestPath +'\jc_report';

    if  (DirExists(DestPath_report) = false) then  ForceDirectories(DestPath_report) ;
    //if  (DirExists(DestPath_jc_report) = false) then  ForceDirectories(DestPath_jc_report) ;
    
    DirectoryCopy(ExpandConstant('{app}\report'), DestPath_report);
    //DirectoryCopy(ExpandConstant('{app}\jc_report'), DestPath_jc_report);

    if MsgBox('�Ƿ�ȫ�°�װ�����ļ���',mbConfirmation,MB_YESNO)=IDYES then
    begin      
      
      //Source: 'pic\*.*'; DestDir: '{app}\pic'; Flags: onlyifdoesntexist uninsneveruninstall;
      //���{app}�ļ���;
      //DelTree(ExpandConstant('{app}'),True,True,True);
      DelTree(ExpandConstant('{app}\report'),True,True,True);
      //DelTree(ExpandConstant('{app}\jc_report'),True,True,True);

    end;
  end;end;




procedure InitializeWizard();
begin
  //�����Э�����ҳ��Ĭ��ѡ����ͬ�ⰴť
  WizardForm.LICENSEACCEPTEDRADIO.Checked := true;

  //�Զ��尲װ�������Ͻ�ͼƬ��С
  WizardForm.WizardSmallBitmapImage.width:=150; //����ҳüͼƬ�Ĵ�С
  WizardForm.WizardSmallBitmapImage.left:=WizardForm.width-WizardForm.WizardSmallBitmapImage.width-5; //�������ҳü�����Ŀ�϶
  WizardForm.PAGENAMELABEL.width:=WizardForm.WizardSmallBitmapImage.left-40; //���ñ���������ʾ�Ĵ�С
  WizardForm.PAGEDESCRIPTIONLABEL.width:=WizardForm.WizardSmallBitmapImage.left-40; //���ñ���������ʾ�Ĵ�С
end;

