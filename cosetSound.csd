<CsoundSynthesizer>
<CsOptions>
; Select audio/midi flags here according to platform
-odac  ;;;realtime audio out
;-iadc    ;;;uncomment -iadc if realtime audio input is needed too
; For Non-realtime ouput leave only the line below:
; -o 24cellRow.wav -W ;;; for file output any platform
</CsOptions>
<CsInstruments>

sr = 44100
ksmps = 32
nchnls = 2
0dbfs  = 1

instr 1

ain	poscil3	.8,	1,	1,	0
;ain2	poscil3 .25,	193,	1,	.87
;ain3	poscil3	.25,	249,	1,	.21
;ain4	poscil3	.25,	567,	1,	.45
;aout 	=	ain	+	ain2	+	ain3	+	ain4
	outs	ain,	ain	

endin
	 
</CsInstruments>
<CsScore>
f	1	0	0	-23	"8cellWaveTableNoZeroPadAdjMap.txt"	

i	1	0	4

e
</CsScore>
</CsoundSynthesizer>
