windows:
printer manager
http://www.httpprinter.com/download.html
download httpprinter package (app and doc)

driver
https://www.cloudprinters.cn/downloadList
58MM小票驱动

usb port searching
command:control
control>all-control>devivce-and-printer
double click 58 printer
hardware>device-ability
doublic click SUPERRISCS31
event->event
已配置设备 USBPRINT\SUPERRISCS31\6&2291db0&0&USB001
see that  USB001

install driver:
POS58 Printer Driver Install
english->NEXT->USB ... ->NEXT
select ${USB001}NEXT
install driver done

test demo:
start app
httpprinter\HttpPrinter_latest\HttpPrinter.exe
httpprinter\调用示例\Http协议示例(请注意跨域问题 )\html_get示例 HttpPrinter 4.0.0.79及以上\fastreport\fastreport_打印Pos小票.html
select printer
demo working
