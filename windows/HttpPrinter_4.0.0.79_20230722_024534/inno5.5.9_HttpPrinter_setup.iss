; (管理员身份运行，请选择“工具 | 选项 | 始终以管理员身份安装卸载”。)

; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

[Setup]
; 注意: AppId 值用于唯一识别该应用程序。
; 禁止对其他应用程序的安装器使用相同的 AppId 值！
; (若要生成一个新的 GUID，请选择“工具 | 生成 GUID”。)
AppId={{43A0DB27-40E7-4D7B-B506-C635A5588103}

;中间件的名称
AppName=HttpPrinter
AppVerName=HttpPrinter
;公司名称
AppPublisher=山东易桥智能科技有限公司
;网址
AppPublisherURL=http://www.HttpPrinter.com
AppSupportURL=http://www.HttpPrinter.com
AppUpdatesURL=http://www.HttpPrinter.com;安装目录
DefaultDirName=D:\yiqiao\HttpPrinter
;公司简称
DefaultGroupName=易桥科技
;许可协议和图标,不使用的话,可以前面加 分号 代表注释例如
;LicenseFile=软件许可协议.txt
;WizardImageFile=左侧图标.bmp
;WizardSmallImageFile=顶端图标.bmp


LicenseFile=软件许可协议.txt
WizardImageFile=左侧图标.bmp
WizardSmallImageFile=顶端图标.bmp

;安装文件生成目录
OutputDir=.
;安装文件名称
OutputBaseFilename=HttpPrinter_setup
Compression=lzma
SolidCompression=true
DirExistsWarning=no
;安装时可以选择安装路径
DisableDirPage=no



[Languages]
Name: chinese; MessagesFile: compiler:Default.isl

[Tasks]
;Name: MDAC; Description: Microsoft Data Access Components; Flags: checkedonce restart; MinVersion: 4.0,4.0; OnlyBelowVersion: 0,5.0

[Messages]
BeveledLabel=山东易桥智能科技有限公司 http://www.HttpPrinter.com


[Files]

;主文件
Source: HttpPrinter.exe; DestDir: {app}; Flags: ignoreversion
Source: HttpPrinter.exe.manifest; DestDir: {app}; Flags: ignoreversion 

Source: gridreport_reg.exe; DestDir: {app}; Flags: ignoreversion
Source: gridreport无法使用_请执行gridreport_reg.exe.txt; DestDir: {app}; Flags: ignoreversion


Source: picprint.exe; DestDir: {app}; Flags: ignoreversion
Source: pdfprint.exe; DestDir: {app}; Flags: ignoreversion
Source: printlog.exe; DestDir: {app}; Flags: ignoreversion
Source: reportdesign.exe; DestDir: {app}; Flags: ignoreversion
Source: printreport.exe; DestDir: {app}; Flags: ignoreversion

Source: jsontoexcel.exe; DestDir: {app}; Flags: ignoreversion
Source: pdfviewer.exe; DestDir: {app}; Flags: ignoreversion

;身份证图片解析授权文件
Source: license.dat; DestDir: {app}; Flags: ignoreversion

Source: 更新日志.txt; DestDir: {app}; Flags: ignoreversion
Source: 说明文档.txt; DestDir: {app}; Flags: ignoreversion
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


;数据库和配置文件 不覆盖 onlyifdoesntexist  不卸载 uninsneveruninstall
Source: config.ini; DestDir: {app}; Flags: onlyifdoesntexist uninsneveruninstall
Source: GRDesigner.ini; DestDir: {app}; Flags: onlyifdoesntexist uninsneveruninstall


 ;拍照控件
;Source: CameraOCX.ocx; DestDir: {sys}; Flags: onlyifdoesntexist uninsneveruninstall

      

;样式
;Source: pic\*.*; DestDir: {app}\pic; Flags: onlyifdoesntexist uninsneveruninstall;

;样式
;Source: styles\*.*; DestDir: {app}\styles; Flags: ignoreversion;

;报表
Source: report\*; DestDir: {app}\report; Flags: onlyifdoesntexist recursesubdirs createallsubdirs ;  
;Source: report\*.*; DestDir: {app}\report; Flags: onlyifdoesntexist;  
;Source: jc_report\*.*; DestDir: {app}\jc_report; Flags: onlyifdoesntexist;  



;包含文件夹及子文件夹

Source: "idcard\*"; DestDir: "{app}\idcard"; Flags: igNoreversion recursesubdirs createallsubdirs 
;Source: "pdfedit\*"; DestDir: "{app}\pdfedit"; Flags: onlyifdoesntexist recursesubdirs createallsubdirs ; 

Source: "language\*"; DestDir: "{app}\language"; Flags: onlyifdoesntexist recursesubdirs createallsubdirs ; 


;Source: 报表_正面.grf; DestDir: {app}; Flags: ignoreversion
;Source: 报表_反面.grf; DestDir: {app}; Flags: ignoreversion


;图标和协议
Source: 顶端图标.bmp; DestDir: {app}; Flags: ignoreversionSource: 软件许可协议.txt; DestDir: {app}; Flags: ignoreversion
Source: 左侧图标.bmp; DestDir: {app}; Flags: ignoreversion
Source: HttpPrinter著作权.jpg; DestDir: {app}; Flags: ignoreversion



;报表组件
Source: grdesigner6.exe; DestDir: {app}; Flags: ignoreversion
Source: grdviewer6.exe; DestDir: {app}; Flags: ignoreversion

Source: grdes6.dll; DestDir: {app}; Flags: ignoreversion
Source: gregn6.dll; DestDir: {app}; Flags: ignoreversion
Source: grmysql6.dll; DestDir: {app}; Flags: ignoreversion
Source: grreg6.dll; DestDir: {app}; Flags: ignoreversion
Source: reg.dll; DestDir: {app}; Flags: ignoreversion

;Source: grdesigner50.exe; DestDir: {app}; Flags: ignoreversion
;Source: grdviewer50.exe; DestDir: {app}; Flags: ignoreversion




;系统所需文件 Windows 系统（System）目录（在 Windows NT/2000 下是 System32）。
;Source: w95scm.dll; DestDir: {sys}; Flags: onlyifdoesntexist uninsneveruninstall
;Source: qtintf70.dll; DestDir: {sys}; Flags: onlyifdoesntexist uninsneveruninstall
;Source: ntdll.dll; DestDir: {sys}; Flags: onlyifdoesntexist uninsneveruninstall

;ISTask.dll  结束进程Dll
Source: ISTask.dll; DestDir: {app}; Flags: ignoreversion


;注册组件
; START regtypelib
;Source: "DLL文件所在路径"; DestDir: "{app}"; Flags:ignoreversion regserver uninsneveruninstall noregerror
;Source: "DLL文件所在路径"; DestDir: "{app}"; Flags:regtypelib uninsneveruninstall noregerror
;其中Flags:段的regserver参数就是注册
;ignoreversion 忽略版本
;regserver　注册activeX DLl/OCX
;regtypelib　注册类型库TLB
;restartreplace　如文件在使用重启替换
;noregerror　注册失败不显示错误信息
;replacesameversion　替换相同版本
;uninsnosharedfileprompt　卸载时不出现共享文件提示
;sharedfile　设为共享文件
;sharedfile　设为共享文件"

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


; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”



;打包并检测MCAC版本
; START MDAC
;Source: mdac_typ.exe; DestDir: {app}; Flags: ignoreversion
;Source: mdac_typ.exe; DestDir: {%TEMP}; MinVersion: 4.0,0; OnlyBelowVersion: 4.1,0; Tasks: MDAC; Flags: ignoreversion
;Source: mdac_typ.exe; DestDir: {tmp}; MinVersion: 4.1,4.0; OnlyBelowVersion: 0,5.0; Tasks: MDAC; Flags: ignoreversion
; END MDAC



[Registry]
;注册表中添加自启动
;Root: HKLM; Subkey: "software\Microsoft\Windows\CurrentVersion\Run"; ValueType: string; ValueName: "bugsky"; ValueData: "{app}\HttpPrinter.exe"; Flags: uninsdeletevalue

;注册表中添加自己的程序信息
Root: HKLM; Subkey: software\bugsky; ValueType: string; ValueName: Install; ValueData: {app}; Flags: uninsdeletevalue


;*.grf  Associations  关联报表
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
Name: {group}\HttpPrinter\HttpPrinter官网; Filename: http://www.HttpPrinter.com
Name: {group}\HttpPrinter\{cm:UninstallProgram,HttpPrinter}; Filename: {uninstallexe}

Name: {commondesktop}\HttpPrinter; Filename: {app}\HttpPrinter.exe


[InstallDelete]
;删除 show.txt
;Name: "{app}\报表_正面.grf" ; Type: filesandordirs
                    

;删除快捷方式

[UninstallDelete]
;卸载时删除文件或文件夹

[Run]
Filename: {app}\HttpPrinter.exe; Description: {cm:LaunchProgram,HttpPrinter}; Flags: nowait postinstall skipifsilent
;Filename: {app}\Readme.txt; Description: 查看说明; Flags: nowait postinstall shellexec

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


//安装时删除{app}目录中所有文件;
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

    if MsgBox('是否全新安装报表文件？',mbConfirmation,MB_YESNO)=IDYES then
    begin      
      
      //Source: 'pic\*.*'; DestDir: '{app}\pic'; Flags: onlyifdoesntexist uninsneveruninstall;
      //清空{app}文件夹;
      //DelTree(ExpandConstant('{app}'),True,True,True);
      DelTree(ExpandConstant('{app}\report'),True,True,True);
      //DelTree(ExpandConstant('{app}\jc_report'),True,True,True);

    end;
  end;end;




procedure InitializeWizard();
begin
  //如何让协议许可页面默认选中我同意按钮
  WizardForm.LICENSEACCEPTEDRADIO.Checked := true;

  //自定义安装程序右上角图片大小
  WizardForm.WizardSmallBitmapImage.width:=150; //设置页眉图片的大小
  WizardForm.WizardSmallBitmapImage.left:=WizardForm.width-WizardForm.WizardSmallBitmapImage.width-5; //设置左边页眉留出的空隙
  WizardForm.PAGENAMELABEL.width:=WizardForm.WizardSmallBitmapImage.left-40; //设置标题文字显示的大小
  WizardForm.PAGEDESCRIPTIONLABEL.width:=WizardForm.WizardSmallBitmapImage.left-40; //设置标题文字显示的大小
end;

