CoDeSys+[   �                   @        @   2.3.9.41�    @   ConfigExtension�          CommConfigEx7             CommConfigExEnd   ME�                  IB                    % QB                    %   ME_End   CM�      CM_End   CT�   ��������   CT_End   ConfigExtensionEnd/    @                             ���c +    @      ��������             ��{c        ;   @   O   C:\PROGRAM FILES (X86)\COMMON FILES\CAA-TARGETS\3S\LIB_PLCWINNT\SYSTASKINFO.LIB          TASKINFO           ct                CurTime    ��              systime             	   SysTime64    ��              tCycleStart            ��                 bReset            ��              bBeginCycle            ��           
   tCycleTime           ��                 tMin           ��              tMax           ��	              tLast           ��
           
   tCycleReal           ��           
   tJitterMax           ��              tJitterLast           ��                       8�RA  �    ����    J   C:\PROGRAM FILES (X86)\3S SOFTWARE\CODESYS V2.3\LIBRARY\ANALYZATIONNEW.LIB          ANALYZEEXPRESSION               InputExp            ��           	   DoAnalyze            ��              	   ExpResult            ��           	   OutString               ��                       ���A  �    ����           ANALYZEEXPRESSIONCOMBINED           Index            ��                 InputExp            ��           	   DoAnalyze            ��              	   ExpResult            ��              OutTable   	                        ExpressionResult           ��           	   OutString               ��	                       ���A  �    ����           ANALYZEEXPRESSIONTABLE           Index            ��                 InputExp            ��           	   DoAnalyze            ��              	   ExpResult            ��              OutTable   	                        ExpressionResult           ��                       ���A  �    ����           APPENDERRORSTRING               strOld               ��              strNew               ��                 AppendErrorString                                         ���A  �    ����    D   C:\PROGRAM FILES (X86)\3S SOFTWARE\CODESYS V2.3\LIBRARY\STANDARD.LIB          CONCAT               STR1               ��              STR2               ��                 CONCAT                                         HBC  �   ����           CTD           M             ��           Variable for CD Edge Detection      CD            ��           Count Down on rising edge    LOAD            ��	           Load Start Value    PV           ��
           Start Value       Q            ��           Counter reached 0    CV           ��           Current Counter Value             HBC  �   ����           CTU           M             ��            Variable for CU Edge Detection       CU            ��       
    Count Up    RESET            ��	           Reset Counter to 0    PV           ��
           Counter Limit       Q            ��           Counter reached the Limit    CV           ��           Current Counter Value             HBC  �   ����           CTUD           MU             ��            Variable for CU Edge Detection    MD             ��            Variable for CD Edge Detection       CU            ��
       
    Count Up    CD            ��           Count Down    RESET            ��           Reset Counter to Null    LOAD            ��           Load Start Value    PV           ��           Start Value / Counter Limit       QU            ��           Counter reached Limit    QD            ��           Counter reached Null    CV           ��           Current Counter Value             HBC  �   ����           DELETE               STR               ��              LEN           ��	              POS           ��
                 DELETE                                         HBC  �   ����           F_TRIG           M             ��                 CLK            ��           Signal to detect       Q            ��	           Edge detected             HBC  �   ����           FIND               STR1               ��	              STR2               ��
                 FIND                                     HBC  �   ����           INSERT               STR1               ��	              STR2               ��
              POS           ��                 INSERT                                         HBC  �   ����           LEFT               STR               ��              SIZE           ��                 LEFT                                         HBC  �   ����           LEN               STR               ��                 LEN                                     HBC  �   ����           MID               STR               ��              LEN           ��	              POS           ��
                 MID                                         HBC  �   ����           R_TRIG           M             ��                 CLK            ��           Signal to detect       Q            ��	           Edge detected             HBC  �   ����           REPLACE               STR1               ��	              STR2               ��
              L           ��              P           ��                 REPLACE                                         HBC  �   ����           RIGHT               STR               ��              SIZE           ��                 RIGHT                                         HBC  �   ����           RS               SET            ��              RESET1            ��	                 Q1            ��                       HBC  �   ����           RTC           M             ��              DiffTime            ��                 EN            ��              PDT           ��                 Q            ��              CDT           ��                       HBC  �   ����           SEMA           X             ��                 CLAIM            ��
              RELEASE            ��                 BUSY            ��                       HBC  �   ����           SR               SET1            ��              RESET            ��                 Q1            ��                       HBC  �   ����           TOF           M             ��           internal variable 	   StartTime            ��           internal variable       IN            ��       ?    starts timer with falling edge, resets timer with rising edge    PT           ��           time to pass, before Q is set       Q            ��       2    is FALSE, PT seconds after IN had a falling edge    ET           ��           elapsed time             HBC  �   ����           TON           M             ��           internal variable 	   StartTime            ��           internal variable       IN            ��       ?    starts timer with rising edge, resets timer with falling edge    PT           ��           time to pass, before Q is set       Q            ��       0    is TRUE, PT seconds after IN had a rising edge    ET           ��           elapsed time             HBC  �   ����           TP        	   StartTime            ��           internal variable       IN            ��       !    Trigger for Start of the Signal    PT           ��       '    The length of the High-Signal in 10ms       Q            ��           The pulse    ET           ��       &    The current phase of the High-Signal             HBC  �   ����    B   C:\PROGRAM FILES (X86)\3S SOFTWARE\CODESYS V2.3\LIBRARY\IECSFC.LIB          SFCACTIONCONTROL     
      S_FF                 RS    ��              L_TMR                    TON    ��              D_TMR                    TON    ��              P_TRIG                 R_TRIG    ��              SD_TMR                    TON    ��              SD_FF                 RS    ��              DS_FF                 RS    ��              DS_TMR                    TON    ��              SL_FF                 RS    ��              SL_TMR                    TON    ��           
      N            ��           Non stored action qualifier    R0            ��       #    Overriding reset action qualifier    S0            ��           Set (stored) action qualifier    L            ��	           Time limited action qualifier    D            ��
           Time delayed action qualifier    P            ��           Pulse action qualifier    SD            ��       *    Stored and time delayed action qualifier    DS            ��       %    Delayed and stored action qualifier    SL            ��       *    Stored and time limited action qualifier    T           ��           Current time       Q            ��       1    Associated action is executed, if Q equals TRUE             `W>D  �    ����    R   C:\PROGRAM FILES (X86)\COMMON FILES\CAA-TARGETS\3S\LIB_PLCWINNT\SYSLIBCALLBACK.LIB          SYSCALLBACKREGISTER            	   iPOUIndex           ��       !    POU Index of callback function.    Event            	   RTS_EVENT   ��           Event to register       SysCallbackRegister                                      (��H  �   ����           SYSCALLBACKUNREGISTER            	   iPOUIndex           ��       !    POU Index of callback function.    Event            	   RTS_EVENT   ��           Event to register       SysCallbackUnregister                                      (��H  �   ����    N   C:\PROGRAM FILES (X86)\COMMON FILES\CAA-TARGETS\3S\LIB_PLCWINNT\SYSLIBTIME.LIB          CURTIME                    
   SystemTime              	   SysTime64  ��                   8�RA  �   ����        	   CURTIMEEX                    
   SystemTime              	   SysTime64  ��              TimeDate         
                SystemTimeDate  ��                   8�RA  �   ����    N   C:\PROGRAM FILES (X86)\COMMON FILES\CAA-TARGETS\3S\LIB_PLCWINNT\SYSLIBFILE.LIB          SYSFILECLOSE               File           ��                 SysFileClose                                      8�RA  �   ����           SYSFILECOPY               FileDest    Q       Q    ��           
   FileSource    Q       Q    ��                 SysFileCopy                                     8�RA  �   ����           SYSFILEDELETE               FileName    Q       Q    ��                 SysFileDelete                                      8�RA  �   ����        
   SYSFILEEOF               File           ��              
   SysFileEOF                                      8�RA  �   ����           SYSFILEGETPOS               File           ��                 SysFileGetPos                                     8�RA  �   ����           SYSFILEGETSIZE               FileName    Q       Q    ��                 SysFileGetSize                                     8�RA  �   ����           SYSFILEGETTIME               FileName    Q       Q    ��           
   ftFileTime                  FILETIME        ��                 SysFileGetTime                                      8�RA  �   ����           SYSFILEOPEN               FileName    Q       Q    ��              Mode               ��       6    Use 'w' (write), 'r' (read) or 'rw' (read and write)       SysFileOpen                                     8�RA  �   ����           SYSFILEREAD               File           ��              Buffer           ��           Address (ADR) to Buffer    Size           ��                 SysFileRead                                     8�RA  �   ����           SYSFILERENAME               FileOldName    Q       Q    ��              FileNewName    Q       Q    ��                 SysFileRename                                      8�RA  �   ����           SYSFILESETPOS               File           ��              Pos           ��                 SysFileSetPos                                      8�RA  �   ����           SYSFILEWRITE               File           ��              Buffer           ��           Address (ADR) to Buffer    Size           ��                 SysFileWrite                                     8�RA  �   ����                  MOTOR           wAngle            Y                                ��{c  @    ����           PLC_PRG                             ��{c  @    ����           WASH     '   	   maxprogNr       @  -               SFCCurrentStep    Q       Q     -               SFCErrorAnalizationTable   	                        ExpressionResult            -               SFCError             -               i            -               CurStep            -               hFile            -               INIT                           _INIT                           RESET                            _RESET                            WAITDOORCLOSED                            _WAITDOORCLOSED                            _timeWAITDOORCLOSED                           _starttimeWAITDOORCLOSED                           LOADDATA                         	   _LOADDATA                         	   STOREDATA                         
   _STOREDATA                            WAITSTARTBUTTON                            _WAITSTARTBUTTON                            _timeWAITSTARTBUTTON                           _starttimeWAITSTARTBUTTON                           WATERLN                            _WATERLN                            _timeWATERLN                           _starttimeWATERLN                           WASH                            _WASH                         	   _timeWASH                           _starttimeWASH                           WATEROUT                         	   _WATEROUT                            _timeWATEROUT                           _starttimeWATEROUT                           WAITDOOROPENED                            _WAITDOOROPENED                            _timeWAITDOOROPENED                           _starttimeWAITDOOROPENED                              SFCInit            -               MyPara                  WashPara   -               MyPara1                  WashPara   -            
   MyWashPara   	                        WashPara           - 	                           _r|c  @   ����        
   WATERLNOUT           tWaterOn                    TON    V            	   tWaterOut                    TON    V               rScale            V                                s�|c  @    ����            
 �  
 -      Z   X   K   +   V   Y   S   J   ( =      K   =     K   #=     K   1=     K   F=                 S=         +     ��localhost   0�)         �i
   ��
 �)       @                       ���
A>E  ����   �@   ���  A>E 	 !   ,rk�� �� ��� ߔ�   S�� Prk�        A>E   A>E 	 �. 0rk�� �� ��  �� 	   Prk$� Ɯ�                  0tkEZ�     ,   ,                                                        K        @   ��{c*_        ��������                     CoDeSys 1-2.2   ����  ��������                     �          �      
   �         �         �          �                    "          $                                                   '          (          �          �          �          �          �         �          �          �          �         �          �          �          �          �         �      �   �       P  �          �         �       �  �                    ~          �          �          �          �          �          �          �          �          �          �          �          �          �          �          �          �          �       @  �       @  �       @  �       @  �       @  �       @  �         �         �          �       �  M         N          O          P          `         a          t          y          z          b         c          X          d         e         _          Q          \         R          K          U         X         Z         �          �         �      
   �         �         �         �         �         �          �          �         �      �����          �          �      (                                                                        "         !          #          $         �          ^          f         g          h          i          j          k         F          H         J         L          N         P         R          U         S          T          V          W          �          �          l          o          p          q          r          s         u          �          v         �          �      ����|         ~         �         x          z      (   �          �         %         �          �          �         @         �          �          �         &          �          	                   �          �          �         �          �         �          �          �          �          �          �          �          �          �          �          �          �                            I         J         K          	          L         M          �                             �          P         Q          S          )          	          	          �           	          +	       @  ,	       @  -	      ���������   �         �         �          �                    "          $                                                   '          (          �          �          �          �          �         �          �          �          �         �          �          �          �          �         �      �   �       P  �          �         �       �  �          �         �          �          �          �          �         �          �          �          �       �  �       �  �       �  �       �  �         �          a          t          y          z          b         c         X          d         e         _          Q          \         R          K          U         X         Z         �          �         �      
   �         �         �         �         �         �          �          �         �      �����          �          �      (                                                                        "         !          #          $         �          ^          f          g          h          i          j          k         F          H         J         L          N         P         R          U         S          T          V          W          �         �          l          o          p          q          r          s         u          �          v         �          w          x          �      ����|         ~         �         x          z      (   �          �         %         �          �          �         @         �          �          �      �  �      �  �         �          �         &          �          	                   �          �          �         �          �         �          �          �          �          �          �          �          �          �          �          �          �          �          �          �                                                 I         J         K          	          L         M          �                             �          P         Q          S          )          	          	          �           	          +	       @  ,	       @  -	      ������������������������  ��������                                                   �  	   	   Name                 ����
   Index                 ��         SubIndex                 �          Accesslevel          !         low   middle   high       Accessright          1      	   read only
   write only
   read-write       Variable    	             ����
   Value                Variable       Min                Variable       Max                Variable          5  
   	   Name                 ����
   Index                 ��         SubIndex                 �          Accesslevel          !         low   middle   high       Accessright          1      	   read only
   write only
   read-write    	   Type          ~         INT   UINT   DINT   UDINT   LINT   ULINT   SINT   USINT   BYTE   WORD   DWORD   REAL   LREAL   STRING    
   Value                Type       Default                Type       Min                Type       Max                Type          5  
   	   Name                 ����
   Index                 ��         SubIndex                 �          Accesslevel          !         low   middle   high       Accessright          1      	   read only
   write only
   read-write    	   Type          ~         INT   UINT   DINT   UDINT   LINT   ULINT   SINT   USINT   BYTE   WORD   DWORD   REAL   LREAL   STRING    
   Value                Type       Default                Type       Min                Type       Max                Type          d        Member    	             ����   Index-Offset                 ��         SubIndex-Offset                 �          Accesslevel          !         low   middle   high       Accessright          1      	   read only
   write only
   read-write       Min                Member       Max                Member          �  	   	   Name                 ����   Member    	             ����
   Value                Member    
   Index                 ��         SubIndex                 �          Accesslevel          !         low   middle   high       Accessright          1      	   read only
   write only
   read-write       Min                Member       Max                Member          �  	   	   Name                 ����
   Index                 ��         SubIndex                 �          Accesslevel          !         low   middle   high       Accessright          1      	   read only
   write only
   read-write       Variable    	             ����
   Value                Variable       Min                Variable       Max                Variable                         ����  ��������               �   _Dummy@    @   @@    @   @             ��@             ��@@   @     �v@@   ; @+   ����  ��������                                  �v@      4@   �             �v@      D@   �                       �       @                           �f@      4@     �f@                �v@     �f@     @u@     �f@        ���           Module.Root-1__not_found__    Steuerungskonfiguration���� IB          % QB          % MB          %    ��{c	D�|c     ��������           VAR_GLOBAL
END_VAR
                                                                                  "   , 4 4 ��             main
        
PLC_PRG();����                MotorSimd        Motor();WaterlnOut();����               0�{c             %      start   Called when program starts    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      stop   Called when program stops    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      before_reset   Called before reset takes place    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      after_reset   Called after reset took place    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      shutdown#   Called before shutdown is performed    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_cycletime_overflow)   Called when a cycletime overflow happened    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_watchdog%   Software watchdog OF IEC-task expired    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_fieldbus   Fieldbus error occurred    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 	   �      excpt_ioupdate   IO-update error    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 
   �      excpt_illegal_instruction   Illegal instruction    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_access_violation   Access violation    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_priv_instruction   Privileged instruction    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_dividebyzero   Division BY zero    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_fpu_error   FPU: Unspecified error    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_fpu_denormal_operand   FPU: Denormal operand    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_fpu_dividebyzero   FPU: Division BY zero    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_fpu_invalid_operation   FPU: Invalid operation    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_fpu_overflow   FPU: Overflow    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      excpt_fpu_stack_check   FPU: Stack check    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      after_reading_inputs   Called after reading of inputs    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      before_writing_outputs    Called before writing of outputs    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �   
   debug_loop   Debug loop at breakpoint    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
    �      interrupt_1   Interrupt 1    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 $   �      interrupt_2   Interrupt 2    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 %   �      interrupt_3   Interrupt 3    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 &   �      interrupt_4   Interrupt 4    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 '   �      interrupt_5   Interrupt 5    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 (   �      interrupt_6   Interrupt 6    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 )   �      interrupt_7   Interrupt 7    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 *   �      interrupt_8   Interrupt 8    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 +   �      interrupt_9   Interrupt 9    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 ,   �      interrupt_10   Interrupt 10    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 -   �      interrupt_11   Interrupt 11    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 .   �      interrupt_12   Interrupt 12    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 /   �      interrupt_13   Interrupt 13    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 0   �      interrupt_14   Interrupt 14    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 1   �      interrupt_15   Interrupt 15    h   FUNCTION systemevent: DWORD
VAR_INPUT
	dwEvent: DWORD;
	dwFilter: DWORD;
	dwOwner: DWORD;
END_VAR
 2   �   $����, � � �(               ��������           Standard ��{c	��{c      ��������                         	R�{c     ��������           VAR_CONFIG
END_VAR
                                                                                   '              ,     X�           Global_Variables ��{c	D�|c     ��������        �  VAR_GLOBAL

	xDoorClosed: BOOL;	(*����� �������*)
	xStart: BOOL;		(*������ ������ ����*)
	xLoad: BOOL;		(*������ ������ �������*)
	xSave: BOOL;		(*������ ������ ���������*)
	xReset: BOOL;	(*������ ������ �����*)

	xWaterOn: BOOL;		(*���� ������*)
	xPump: BOOL;		(*����� ����� ����*)
	xMotOn: BOOL;		(*����� �������*)

	byProg: BYTE;		(*�����*)
	xProgInc: BOOL;	(*������ ������ �������*)
	xProgDec: BOOL;
	ProgInc: R_TRIG;
	ProgDec: R_TRIG;
	xActPrgCng: BOOL;
END_VAR
                                                                                               '           	     ��������           Variable_Configuration ��{c	��{c	     ��������           VAR_CONFIG
END_VAR
                                                                                                 ~   |0|0 @t    @R   Arial @       HH':'mm':'ss @      dd'-'MM'-'yyyy   dd'-'MM'-'yyyy HH':'mm':'ss�����              �                -     �   ���  �3 ���   � ���     
    @��  ���     @      DEFAULT             �������      ~   |0|0 @t    @R   Arial @       HH':'mm':'ss @      dd'-'MM'-'yyyy   dd'-'MM'-'yyyy HH':'mm':'ss�����              �       )   HH':'mm':'ss @                             dd'-'MM'-'yyyy @       '   U   , N N ��           WashPara (�{c	(�{c      ��������        p   TYPE WashPara :
STRUCT
	Waterln:TIME;
	WashTime:TIME;
	WashTemp:WORD;
	WaterOut:TIME;
END_STRUCT
END_TYPE              Y   ,   r�           Motor ���c	��{c      ��������        *   PROGRAM Motor
VAR
	wAngle:WORD;
END_VAR�   (*�������� ������ ������ ��� ������������*)

IF xMotOn THEN
	wAngle:=wAngle+4;
	IF wAngle > 359 THEN
		wAngle:=0;
	END_IF
ELSE
	wAngle:=0;
END_IF               +   , 4 4 ��           PLC_PRG l�{c	��{c      ��������           PROGRAM PLC_PRG
VAR
END_VAR�   Wash;(*����� ��������� ������*)

(*����� ��������� ������ ������� Reset*)
Wash.SFCInit:=xReset;

(*����������� ��������� ��������� ������ �� ���������� �����*)
xWaterOn:=Wash.Waterln;
xPump:=Wash.WaterOut;
xActPrgCng:=Wash.WaitStartButton;

               -   , 0  ��           Wash ��c	_r|c      ��������        T  PROGRAM Wash
VAR CONSTANT
	maxprogNr:BYTE:=5;
END_VAR

VAR_INPUT
	SFCInit:BOOL;
	MyPara, MyPara1:WashPara;
	MyWashPara: ARRAY [0..maxProgNr] OF WashPara;
END_VAR

VAR
	SFCCurrentStep:STRING;
	SFCErrorAnalizationTable: ARRAY [0..15] OF ExpressionResult;
	SFCError:BOOL;
	i:BYTE;
	CurStep:WORD;
	hFile:DWORD;
END_VAR



       Init M     ��������           �������� Init ��cF   MyPara.Washtime:=T#1h20m;
MyPara.WashTemp:=100;
MyPara1:=MyPara;

       TRUE         Reset N     ��������           �������� Reset ��c�   FOR i:=0 TO maxProgNr DO
	MyWashPara[i].WaterOut:=T#5s;
	MyWashPara[i].WashTemp:=40 + i*5;
	MyWashPara[i].WashTime:=T#20s+WORD_TO_TIME(i*5000);
	MyWashPara[i].Waterln:=T#5s;
END_FOR

xMotOn:=FALSE;
xPump:=FALSE;
xWaterOn:=FALSE;
       TRUE         WaitDoorClosed T#0.001s O     ��������           �������� WaitDoorClosed ��c
   	LD		0
	ST		CurStep
         xDoorClosed        xLoad         LoadData J     ��������           �������� LoadData ��cP  (*������ ������� ������� �� �����*)
CASE CurStep OF
0:
	hFile:=SysFileOpen('D:\MyDatei.txt','r');
	IF hFile > 0 THEN
		CurStep := 1;
	ELSE
		CurStep:=2;
	END_IF
1:
	SysFileRead(File:=hFile,
					Buffer:=ADR(MyWashPara),
					Size:=SIZEOF(MyWashPara));
	CurStep:=2;
2:
	SysFileClose(File:=hFile);
	CurStep:=255;
END_CASE       CurStep=255 AND NOT xLoad      xSave      	   StoreData K     ��������           �������� StoreData ��c%  (*������ ������� ������� ������ �� �����*)
CASE CurStep OF
0:
	hFile:=SysFileOpen('D:\MyDatei.txt','w');
	CurStep:=1;

1:
	SysFileRead(File:=hFile,
					Buffer:=ADR(MyWashPara),
					Size:=SIZEOF(MyWashPara));
	CurStep:=2;
2:
	SysFileClose(File:=hFile);
	CurStep:=255;
END_CASE
       CurStep=255 AND NOT xSave     WaitDoorClosed       WaitStartButton T#0.001s R     ��������           �������� WaitStartButton ��c�   (*����� ������ ������*)

ProgInc(CLK:=xProgInc);
Progdec(CLK:=xProgDec);

IF ProgInc.Q AND byProg < maxProgNr THEN
	byProg:=byProg+1;
END_IF

IF ProgDec.Q AND byProg > 0 THEN
	byProg:=byProg-1;
END_IF       xStart         WaterlnMyWashPara[byProg].Waterln          TRUE         WashMyWashPara[byProg].WashTime  S     ��������           �������� Wash ��c   xMotOn:=TRUE;
       TRUE         WaterOutMyWashPara[byProg].WaterOut          TRUE         WaitDoorOpened T#0.001s         FALSE Z     ��������           Transition FALSE 	��c      �	�xDoorClosed�xStart  d      InitY                  V   , h h �        
   WaterlnOut s�|c	s�|c      ��������        T   PROGRAM WaterlnOut
VAR
	tWaterOn : TON;
	tWaterOut: TON;
	rScale:DWORD;
END_VAR�  (*�������� ���������� � ����� ���� ��� ������������*)

tWaterOn(IN:=xWaterOn, PT:=Wash.MyWashPara[byProg].Waterln);
tWaterOut(IN:=xPump, PT:=Wash.MyWashPara[byProg].WaterOut);

IF xWaterOn THEN
	rScale:= ((TIME_TO_DWORD(tWaterOn.ET))*100)/(TIME_TO_DWORD(tWaterOn.PT));
END_IF

IF xPump THEN
	rScale:=100- ((TIME_TO_DWORD(tWaterOut.ET))*100)/(TIME_TO_DWORD(tWaterOut.PT));
END_IF                X   , B����           Wash R�{c
    @�������c   �                                                                                                          
    @        P  ��� �   ���     ���                                             @                           ���   �    @	                       @                                                                                                           
    @        Z ( � G x 7     �     ���                                         	   start @                          ���   �    @	        .xStart             @                                                                                                          
    @        � F s� n   ���     ���                                             @                          ���   �   Arial Black @	                       @                                                                                                          
    @        � � KA� �   ���     ���                                            @                          ���   �    @	                       @                                                                                                           
    @        � � � � �   ���     �                                      .xDoorClosed       D @                          ���   �    @	    .xDoorClosed                 @                                                                                                           
    @        �2 �Q �A   ���     ���                                    .xLoad       Load @                          ���   �    @	        .xLoad             @                                                                                                           
    @        �Z �y �i   ���     ���                                    .xSave       Save @                          ���   �    @	        .xSave             @                                                                                                          
    @        ,^s�Or  ���     ���                                         	   reset @                          ���   �    @	        .xReset             @                                                                                                           
    @        Z � o }d   ���     ���                                             @                          ���   �    @	                       @                                                                                                           
    @        x #� �   ���     ���                                            + @                      	    ���   �    @	     	   .xProgInc             @                                                                                                           
    @        Tx i� ^�   ���     ���                                            - @                          ���   �    @	     	   .xProgDec             @                                                                                                           
    @        �  K= � -   ���     ���                                        Wash.SFCCurrentStep   %s @                          ���   �    @	                       @                                                                                                           
    @        "P Ue ;Z   ���     ���                                            Mode @                          ���   �    @	                       @                                                                                                           
    @        ,n K� ;}   ���     ���                                        .byProg   %s @                          ���   �    @	                       @                                                                                                          
    @        � Z o � d   ���     ���                                     !   Wash.MyWashPara[.byProg].WashTemp   %s @                          ���   �    @	                       @                                                                                                           
    @        � x � � �   ���     ���                                     !   Wash.MyWashPara[.byProg].WashTime   %s @                          ���   �    @	                       @       	� � J@� �                                                                                                 
    @         � � I?J� � �  �   ���     ���                           @                Motor.wAngle            ���   �    @	                                                                                                                                       
    @        Z |o }d |  ���     ���                -(WaterlnOut.rScale*2.2)                            @                          ���   �    @	                       @             �   ��   �   ��   � � � ���     �   ��   �   ��   � � � ���                  ����, � � �,         &   SysTaskInfo.lib 23.9.04 10:11:36 @8�RA*   AnalyzationNew.lib 16.12.04 14:50:08 @���A#   Standard.lib 4.10.05 11:14:46 @HBC!   IecSfc.lib 13.4.06 15:51:28 @`W>D)   SYSLIBCALLBACK.LIB 26.9.08 16:43:52 @(��H%   SysLibTime.lib 23.9.04 10:11:36 @8�RA%   SysLibFile.lib 23.9.04 10:11:36 @8�RA      taskinfo @                      Globale_Variablen @           7   AnalyzeExpression @      ExpressionResult                   AnalyzeExpressionCombined @          AnalyzeExpressionTable @          AppendErrorString @              Globale_Variablen @              CONCAT @                	   CTD @        	   CTU @        
   CTUD @           DELETE @           F_TRIG @        
   FIND @           INSERT @        
   LEFT @        	   LEN @        	   MID @           R_TRIG @           REPLACE @           RIGHT @           RS @        	   RTC @        
   SEMA @           SR @        	   TOF @        	   TON @           TP @               F   SFCActionControl @      SFCActionType       SFCStepType                      Globale_Variablen @           b   SysCallbackRegister @   	   RTS_EVENT       RTS_EVENT_FILTER       RTS_EVENT_SOURCE                   SysCallbackUnregister @               <   CurTime @      SystemTimeDate    	   SysTime64                   CurTimeEx @              Globale_Variablen @           *   SysFileClose @      FILETIME                   SysFileCopy @           SysFileDelete @           SysFileEOF @           SysFileGetPos @           SysFileGetSize @           SysFileGetTime @           SysFileOpen @           SysFileRead @           SysFileRename @           SysFileSetPos @           SysFileWrite @              Globale_Variablen @                          ��������           2 �  �           ����������������  
             ����  ��������        ����  ��������                      POU                 Motor  Y                   PLC_PRG  +                  Wash  -                
   WaterlnOut  V   ����              ���� ������                WashPara  U   ����              ������������                Wash  X   ����              ���������� ����������                Global_Variables                     Variable_Configuration  	   ����                                         ��������             ��{c�              �                 	   localhost            P      	   localhost            P      	   localhost            P     ��{c ��*�