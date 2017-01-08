EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:HDSP-816X
LIBS:88MPH-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA328P-P IC1
U 1 1 58718A06
P 3400 3250
F 0 "IC1" H 2650 4500 50  0000 L BNN
F 1 "ATMEGA328P-P" H 3800 1850 50  0000 L BNN
F 2 "misc:DIP28" H 3400 3250 50  0000 C CIN
F 3 "" H 3400 3250 50  0000 C CNN
	1    3400 3250
	1    0    0    -1  
$EndComp
Text GLabel 5850 2850 0    40   Input ~ 0
A
Text GLabel 5850 2950 0    40   Input ~ 0
F
Text GLabel 5850 3050 0    40   Input ~ 0
CK
Text GLabel 5850 3150 0    40   Input ~ 0
E
Text GLabel 7350 3450 2    40   Input ~ 0
DP
Text GLabel 7350 3350 2    40   Input ~ 0
D
Text GLabel 7350 3150 2    40   Input ~ 0
C
Text GLabel 7350 3050 2    40   Input ~ 0
G
Text GLabel 7350 2950 2    40   Input ~ 0
B
Text GLabel 7350 3250 2    40   Input ~ 0
CK1
Text GLabel 7350 2850 2    40   Input ~ 0
CK1
Text GLabel 5850 3250 0    40   Input ~ 0
CK1
Text GLabel 7800 2850 0    40   Input ~ 0
A
Text GLabel 7800 2950 0    40   Input ~ 0
F
Text GLabel 7800 3050 0    40   Input ~ 0
CK
Text GLabel 7800 3150 0    40   Input ~ 0
E
Text GLabel 9300 3450 2    40   Input ~ 0
DP
Text GLabel 9300 3350 2    40   Input ~ 0
D
Text GLabel 9300 3150 2    40   Input ~ 0
C
Text GLabel 9300 3050 2    40   Input ~ 0
G
Text GLabel 9300 2950 2    40   Input ~ 0
B
Text GLabel 9300 3250 2    40   Input ~ 0
CK2
Text GLabel 9300 2850 2    40   Input ~ 0
CK2
Text GLabel 7800 3250 0    40   Input ~ 0
CK2
Text GLabel 4750 4250 2    40   Input ~ 0
A
Text GLabel 4750 2350 2    40   Input ~ 0
F
Text GLabel 4750 2250 2    40   Input ~ 0
E
Text GLabel 4750 4350 2    40   Input ~ 0
B
$Comp
L HDSP-816X D1
U 1 1 58719A1C
P 6600 3150
F 0 "D1" H 6600 3050 50  0000 C CNN
F 1 "HDSP-816X" H 6600 3250 50  0000 C CNN
F 2 "misc:HDSP-816X" H 7450 2750 50  0001 C CNN
F 3 "DOCUMENTATION" H 7450 2650 50  0001 C CNN
	1    6600 3150
	1    0    0    -1  
$EndComp
$Comp
L HDSP-816X D2
U 1 1 58719A41
P 8550 3150
F 0 "D2" H 8550 3050 50  0000 C CNN
F 1 "HDSP-816X" H 8550 3250 50  0000 C CNN
F 2 "misc:HDSP-816X" H 9400 2750 50  0001 C CNN
F 3 "DOCUMENTATION" H 9400 2650 50  0001 C CNN
	1    8550 3150
	1    0    0    -1  
$EndComp
Text GLabel 4750 4450 2    40   Input ~ 0
C
Text GLabel 4750 2150 2    40   Input ~ 0
D
Text GLabel 5300 2450 2    40   Input ~ 0
G
Text GLabel 5300 2550 2    40   Input ~ 0
DP
Text GLabel 4400 3000 2    40   Input ~ 0
D1
Text GLabel 4400 3100 2    40   Input ~ 0
D2
$Comp
L R R1
U 1 1 58719B76
P 4600 2150
F 0 "R1" V 4600 2000 50  0000 C CNN
F 1 "150" V 4600 2150 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 4530 2150 50  0001 C CNN
F 3 "" H 4600 2150 50  0000 C CNN
	1    4600 2150
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 58719C85
P 4600 2250
F 0 "R2" V 4600 2100 50  0000 C CNN
F 1 "150" V 4600 2250 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 4530 2250 50  0001 C CNN
F 3 "" H 4600 2250 50  0000 C CNN
	1    4600 2250
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 58719CA4
P 4600 2350
F 0 "R3" V 4600 2200 50  0000 C CNN
F 1 "150" V 4600 2350 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 4530 2350 50  0001 C CNN
F 3 "" H 4600 2350 50  0000 C CNN
	1    4600 2350
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 58719CC6
P 5150 2450
F 0 "R4" V 5150 2300 50  0000 C CNN
F 1 "150" V 5150 2450 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 5080 2450 50  0001 C CNN
F 3 "" H 5150 2450 50  0000 C CNN
	1    5150 2450
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 58719CEB
P 5150 2550
F 0 "R5" V 5150 2400 50  0000 C CNN
F 1 "150" V 5150 2550 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 5080 2550 50  0001 C CNN
F 3 "" H 5150 2550 50  0000 C CNN
	1    5150 2550
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 58719D39
P 4600 4250
F 0 "R6" V 4600 4100 50  0000 C CNN
F 1 "150" V 4600 4250 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 4530 4250 50  0001 C CNN
F 3 "" H 4600 4250 50  0000 C CNN
	1    4600 4250
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 58719DBC
P 4600 4350
F 0 "R7" V 4600 4200 50  0000 C CNN
F 1 "150" V 4600 4350 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 4530 4350 50  0001 C CNN
F 3 "" H 4600 4350 50  0000 C CNN
	1    4600 4350
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 58719DEA
P 4600 4450
F 0 "R8" V 4600 4300 50  0000 C CNN
F 1 "150" V 4600 4450 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 4530 4450 50  0001 C CNN
F 3 "" H 4600 4450 50  0000 C CNN
	1    4600 4450
	0    1    1    0   
$EndComp
$Comp
L Q_NPN_EBC Q1
U 1 1 58719FE0
P 6600 4200
F 0 "Q1" H 6900 4250 50  0000 R CNN
F 1 "Q_NPN_EBC" H 7200 4150 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 6800 4300 50  0001 C CNN
F 3 "" H 6600 4200 50  0000 C CNN
	1    6600 4200
	1    0    0    -1  
$EndComp
Text GLabel 6700 4000 1    40   Input ~ 0
CK1
$Comp
L R R10
U 1 1 5871A051
P 6250 4200
F 0 "R10" V 6150 4200 50  0000 C CNN
F 1 "1.2K" V 6250 4200 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 6180 4200 50  0001 C CNN
F 3 "" H 6250 4200 50  0000 C CNN
	1    6250 4200
	0    1    1    0   
$EndComp
$Comp
L GND #PWR01
U 1 1 5871A0C9
P 6700 4400
F 0 "#PWR01" H 6700 4150 50  0001 C CNN
F 1 "GND" H 6700 4250 50  0000 C CNN
F 2 "" H 6700 4400 50  0000 C CNN
F 3 "" H 6700 4400 50  0000 C CNN
	1    6700 4400
	1    0    0    -1  
$EndComp
Text GLabel 6100 4200 0    40   Input ~ 0
D1
$Comp
L Q_NPN_EBC Q2
U 1 1 5871A85D
P 8600 4200
F 0 "Q2" H 8900 4250 50  0000 R CNN
F 1 "Q_NPN_EBC" H 9200 4150 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 8800 4300 50  0001 C CNN
F 3 "" H 8600 4200 50  0000 C CNN
	1    8600 4200
	1    0    0    -1  
$EndComp
Text GLabel 8700 4000 1    40   Input ~ 0
CK2
$Comp
L R R11
U 1 1 5871A864
P 8250 4200
F 0 "R11" V 8150 4200 50  0000 C CNN
F 1 "1.2K" V 8250 4200 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 8180 4200 50  0001 C CNN
F 3 "" H 8250 4200 50  0000 C CNN
	1    8250 4200
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 5871A86A
P 8700 4400
F 0 "#PWR02" H 8700 4150 50  0001 C CNN
F 1 "GND" H 8700 4250 50  0000 C CNN
F 2 "" H 8700 4400 50  0000 C CNN
F 3 "" H 8700 4400 50  0000 C CNN
	1    8700 4400
	1    0    0    -1  
$EndComp
Text GLabel 8100 4200 0    40   Input ~ 0
D2
Text GLabel 4400 3950 2    40   Input ~ 0
BTN_A
Text GLabel 4400 4050 2    40   Input ~ 0
BTN_B
$Comp
L SW_PUSH BTN_1
U 1 1 5871C47D
P 5650 4950
F 0 "BTN_1" H 5800 5060 50  0000 C CNN
F 1 "SW_PUSH" H 5650 4870 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_6mm" H 5650 4950 50  0001 C CNN
F 3 "" H 5650 4950 50  0000 C CNN
	1    5650 4950
	1    0    0    -1  
$EndComp
Text GLabel 5350 4950 0    40   Input ~ 0
BTN_A
$Comp
L GND #PWR03
U 1 1 5871C50D
P 5950 4950
F 0 "#PWR03" H 5950 4700 50  0001 C CNN
F 1 "GND" H 5950 4800 50  0000 C CNN
F 2 "" H 5950 4950 50  0000 C CNN
F 3 "" H 5950 4950 50  0000 C CNN
	1    5950 4950
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH BTN_2
U 1 1 5871C55D
P 5650 5300
F 0 "BTN_2" H 5800 5410 50  0000 C CNN
F 1 "SW_PUSH" H 5650 5220 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_6mm" H 5650 5300 50  0001 C CNN
F 3 "" H 5650 5300 50  0000 C CNN
	1    5650 5300
	1    0    0    -1  
$EndComp
Text GLabel 5350 5300 0    40   Input ~ 0
BTN_B
$Comp
L GND #PWR04
U 1 1 5871C564
P 5950 5300
F 0 "#PWR04" H 5950 5050 50  0001 C CNN
F 1 "GND" H 5950 5150 50  0000 C CNN
F 2 "" H 5950 5300 50  0000 C CNN
F 3 "" H 5950 5300 50  0000 C CNN
	1    5950 5300
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X04 P1
U 1 1 5871C919
P 6350 1950
F 0 "P1" H 6350 2200 50  0000 C CNN
F 1 "CONN_01X04" V 6450 1950 50  0000 C CNN
F 2 "misc:Strip_1x04" H 6350 1950 50  0001 C CNN
F 3 "" H 6350 1950 50  0000 C CNN
	1    6350 1950
	1    0    0    -1  
$EndComp
Text GLabel 6150 2100 0    40   Input ~ 0
WHITE
Text GLabel 6150 2000 0    40   Input ~ 0
GREEN
$Comp
L AVR-ISP-6 CON1
U 1 1 5871D05B
P 3550 1350
F 0 "CON1" H 3445 1590 50  0000 C CNN
F 1 "AVR-ISP-6" H 3285 1120 50  0000 L BNN
F 2 "misc:ICSP" V 3030 1390 50  0001 C CNN
F 3 "" H 3525 1350 50  0000 C CNN
	1    3550 1350
	1    0    0    -1  
$EndComp
Text GLabel 3950 1350 2    40   Input ~ 0
MOSI
$Comp
L GND #PWR05
U 1 1 5871D336
P 3950 1450
F 0 "#PWR05" H 3950 1200 50  0001 C CNN
F 1 "GND" V 3950 1250 50  0000 C CNN
F 2 "" H 3950 1450 50  0000 C CNN
F 3 "" H 3950 1450 50  0000 C CNN
	1    3950 1450
	0    -1   -1   0   
$EndComp
Text GLabel 3100 1250 0    40   Input ~ 0
MISO
Text GLabel 3100 1350 0    40   Input ~ 0
SCK
Text GLabel 3100 1450 0    40   Input ~ 0
RST
$Comp
L VCC #PWR06
U 1 1 5871E135
P 1550 2400
F 0 "#PWR06" H 1550 2250 50  0001 C CNN
F 1 "VCC" H 1550 2550 50  0000 C CNN
F 2 "" H 1550 2400 50  0000 C CNN
F 3 "" H 1550 2400 50  0000 C CNN
	1    1550 2400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 5871E2B7
P 2300 3600
F 0 "#PWR07" H 2300 3350 50  0001 C CNN
F 1 "GND" H 2300 3450 50  0000 C CNN
F 2 "" H 2300 3600 50  0000 C CNN
F 3 "" H 2300 3600 50  0000 C CNN
	1    2300 3600
	1    0    0    -1  
$EndComp
$Comp
L C_Small C1
U 1 1 5871E35D
P 2300 3500
F 0 "C1" H 2310 3570 50  0000 L CNN
F 1 "0.1uF" H 2310 3420 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 2300 3500 50  0001 C CNN
F 3 "" H 2300 3500 50  0000 C CNN
	1    2300 3500
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR08
U 1 1 5871E4AB
P 2450 4350
F 0 "#PWR08" H 2450 4100 50  0001 C CNN
F 1 "GND" H 2450 4200 50  0000 C CNN
F 2 "" H 2450 4350 50  0000 C CNN
F 3 "" H 2450 4350 50  0000 C CNN
	1    2450 4350
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 5871EA70
P 4900 3550
F 0 "R9" V 4800 3550 50  0000 C CNN
F 1 "10K" V 4900 3550 50  0000 C CNN
F 2 "misc:0.125_Resistor" V 4830 3550 50  0001 C CNN
F 3 "" H 4900 3550 50  0000 C CNN
	1    4900 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 2150 4450 2150
Wire Wire Line
	4450 2250 4400 2250
Wire Wire Line
	4400 2350 4450 2350
Wire Wire Line
	5000 2450 4950 2450
Wire Wire Line
	4950 2550 5000 2550
Wire Wire Line
	4400 4250 4450 4250
Wire Wire Line
	4450 4350 4400 4350
Wire Wire Line
	4400 4450 4450 4450
Wire Wire Line
	3100 1250 3400 1250
Wire Wire Line
	3400 1350 3100 1350
Wire Wire Line
	3100 1450 3400 1450
Wire Wire Line
	3650 1250 3950 1250
Wire Wire Line
	3950 1350 3650 1350
Wire Wire Line
	3650 1450 3950 1450
Wire Wire Line
	2500 2000 2500 2750
Connection ~ 2500 2150
Wire Wire Line
	2500 4450 2500 4350
Wire Wire Line
	2500 4350 2450 4350
Text GLabel 4400 3600 2    40   Input ~ 0
RST
Wire Wire Line
	4750 3550 4400 3550
Wire Wire Line
	4400 3550 4400 3600
Connection ~ 2500 2450
Text GLabel 2500 2000 1    40   Input ~ 0
5V
Text GLabel 3950 1250 2    40   Input ~ 0
5V
Text GLabel 2300 3400 1    40   Input ~ 0
5V
Text GLabel 5050 3550 2    40   Input ~ 0
5V
$Comp
L SPST PWR1
U 1 1 5871C7FB
P 1550 2900
F 0 "PWR1" H 1550 3000 50  0000 C CNN
F 1 "SPST" H 1550 2800 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_Micro_SPST" H 1550 2900 50  0001 C CNN
F 3 "" H 1550 2900 50  0000 C CNN
	1    1550 2900
	0    1    1    0   
$EndComp
Text GLabel 1550 3400 3    40   Input ~ 0
5V
$Comp
L PWR_FLAG #FLG09
U 1 1 5871D018
P 1450 1550
F 0 "#FLG09" H 1450 1645 50  0001 C CNN
F 1 "PWR_FLAG" H 1450 1730 50  0000 C CNN
F 2 "" H 1450 1550 50  0000 C CNN
F 3 "" H 1450 1550 50  0000 C CNN
	1    1450 1550
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR010
U 1 1 5871D06C
P 1450 1550
F 0 "#PWR010" H 1450 1400 50  0001 C CNN
F 1 "VCC" H 1450 1700 50  0000 C CNN
F 2 "" H 1450 1550 50  0000 C CNN
F 3 "" H 1450 1550 50  0000 C CNN
	1    1450 1550
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG011
U 1 1 5871D0B9
P 1850 1550
F 0 "#FLG011" H 1850 1645 50  0001 C CNN
F 1 "PWR_FLAG" H 1850 1730 50  0000 C CNN
F 2 "" H 1850 1550 50  0000 C CNN
F 3 "" H 1850 1550 50  0000 C CNN
	1    1850 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 5871D106
P 1850 1550
F 0 "#PWR012" H 1850 1300 50  0001 C CNN
F 1 "GND" H 1850 1400 50  0000 C CNN
F 2 "" H 1850 1550 50  0000 C CNN
F 3 "" H 1850 1550 50  0000 C CNN
	1    1850 1550
	1    0    0    -1  
$EndComp
Text GLabel 4400 3850 2    40   Input ~ 0
WHITE
Text GLabel 4400 3750 2    40   Input ~ 0
GREEN
$Comp
L GND #PWR013
U 1 1 5871DAB9
P 6150 1900
F 0 "#PWR013" H 6150 1650 50  0001 C CNN
F 1 "GND" V 6150 1700 50  0000 C CNN
F 2 "" H 6150 1900 50  0000 C CNN
F 3 "" H 6150 1900 50  0000 C CNN
	1    6150 1900
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR014
U 1 1 5871DB06
P 6150 1800
F 0 "#PWR014" H 6150 1650 50  0001 C CNN
F 1 "VCC" V 6150 2000 50  0000 C CNN
F 2 "" H 6150 1800 50  0000 C CNN
F 3 "" H 6150 1800 50  0000 C CNN
	1    6150 1800
	0    -1   -1   0   
$EndComp
Text GLabel 4400 2450 2    40   Input ~ 0
MOSI
Text GLabel 4400 2550 2    40   Input ~ 0
MISO
Wire Wire Line
	4400 2450 4400 2500
Wire Wire Line
	4400 2500 4950 2500
Wire Wire Line
	4950 2500 4950 2450
Wire Wire Line
	4400 2550 4400 2600
Wire Wire Line
	4400 2600 4950 2600
Wire Wire Line
	4950 2600 4950 2550
Text GLabel 4400 2650 2    40   Input ~ 0
SCK
$EndSCHEMATC
