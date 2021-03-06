#name: MIPS ELF got reloc n32
#as: -EB -n32 -KPIC
#source: ../../../gas/testsuite/gas/mips/elf-rel-got-n32.s
#ld: -melf32btsmipn32
#objdump: -D --show-raw-insn

.*: +file format elf32-n.*mips.*

Disassembly of section \.text:

100000a0 <fn>:
100000a0:	8f858064 	lw	a1,-32668\(gp\)
100000a4:	8f858064 	lw	a1,-32668\(gp\)
100000a8:	24a5000c 	addiu	a1,a1,12
100000ac:	8f858064 	lw	a1,-32668\(gp\)
100000b0:	3c010001 	lui	at,0x1
100000b4:	3421e240 	ori	at,at,0xe240
100000b8:	00a12821 	addu	a1,a1,at
100000bc:	8f858064 	lw	a1,-32668\(gp\)
100000c0:	00b12821 	addu	a1,a1,s1
100000c4:	8f858064 	lw	a1,-32668\(gp\)
100000c8:	24a5000c 	addiu	a1,a1,12
100000cc:	00b12821 	addu	a1,a1,s1
100000d0:	8f858064 	lw	a1,-32668\(gp\)
100000d4:	3c010001 	lui	at,0x1
100000d8:	3421e240 	ori	at,at,0xe240
100000dc:	00a12821 	addu	a1,a1,at
100000e0:	00b12821 	addu	a1,a1,s1
100000e4:	8f858018 	lw	a1,-32744\(gp\)
100000e8:	8ca5050c 	lw	a1,1292\(a1\)
100000ec:	8f858018 	lw	a1,-32744\(gp\)
100000f0:	8ca50518 	lw	a1,1304\(a1\)
100000f4:	8f858018 	lw	a1,-32744\(gp\)
100000f8:	00b12821 	addu	a1,a1,s1
100000fc:	8ca5050c 	lw	a1,1292\(a1\)
10000100:	8f858018 	lw	a1,-32744\(gp\)
10000104:	00b12821 	addu	a1,a1,s1
10000108:	8ca50518 	lw	a1,1304\(a1\)
1000010c:	8f818018 	lw	at,-32744\(gp\)
10000110:	00250821 	addu	at,at,a1
10000114:	8c25052e 	lw	a1,1326\(at\)
10000118:	8f818018 	lw	at,-32744\(gp\)
1000011c:	00250821 	addu	at,at,a1
10000120:	ac250544 	sw	a1,1348\(at\)
10000124:	8f818064 	lw	at,-32668\(gp\)
10000128:	88250000 	lwl	a1,0\(at\)
1000012c:	98250003 	lwr	a1,3\(at\)
10000130:	8f818064 	lw	at,-32668\(gp\)
10000134:	2421000c 	addiu	at,at,12
10000138:	88250000 	lwl	a1,0\(at\)
1000013c:	98250003 	lwr	a1,3\(at\)
10000140:	8f818064 	lw	at,-32668\(gp\)
10000144:	00310821 	addu	at,at,s1
10000148:	88250000 	lwl	a1,0\(at\)
1000014c:	98250003 	lwr	a1,3\(at\)
10000150:	8f818064 	lw	at,-32668\(gp\)
10000154:	2421000c 	addiu	at,at,12
10000158:	00310821 	addu	at,at,s1
1000015c:	88250000 	lwl	a1,0\(at\)
10000160:	98250003 	lwr	a1,3\(at\)
10000164:	8f818064 	lw	at,-32668\(gp\)
10000168:	24210022 	addiu	at,at,34
1000016c:	00250821 	addu	at,at,a1
10000170:	88250000 	lwl	a1,0\(at\)
10000174:	98250003 	lwr	a1,3\(at\)
10000178:	8f818064 	lw	at,-32668\(gp\)
1000017c:	24210038 	addiu	at,at,56
10000180:	00250821 	addu	at,at,a1
10000184:	a8250000 	swl	a1,0\(at\)
10000188:	b8250003 	swr	a1,3\(at\)
1000018c:	8f85801c 	lw	a1,-32740\(gp\)
10000190:	8f858020 	lw	a1,-32736\(gp\)
10000194:	8f858024 	lw	a1,-32732\(gp\)
10000198:	8f85801c 	lw	a1,-32740\(gp\)
1000019c:	00b12821 	addu	a1,a1,s1
100001a0:	8f858020 	lw	a1,-32736\(gp\)
100001a4:	00b12821 	addu	a1,a1,s1
100001a8:	8f858024 	lw	a1,-32732\(gp\)
100001ac:	00b12821 	addu	a1,a1,s1
100001b0:	8f858018 	lw	a1,-32744\(gp\)
100001b4:	8ca5050c 	lw	a1,1292\(a1\)
100001b8:	8f858018 	lw	a1,-32744\(gp\)
100001bc:	8ca50518 	lw	a1,1304\(a1\)
100001c0:	8f858018 	lw	a1,-32744\(gp\)
100001c4:	00b12821 	addu	a1,a1,s1
100001c8:	8ca5050c 	lw	a1,1292\(a1\)
100001cc:	8f858018 	lw	a1,-32744\(gp\)
100001d0:	00b12821 	addu	a1,a1,s1
100001d4:	8ca50518 	lw	a1,1304\(a1\)
100001d8:	8f818018 	lw	at,-32744\(gp\)
100001dc:	00250821 	addu	at,at,a1
100001e0:	8c25052e 	lw	a1,1326\(at\)
100001e4:	8f818018 	lw	at,-32744\(gp\)
100001e8:	00250821 	addu	at,at,a1
100001ec:	ac250544 	sw	a1,1348\(at\)
100001f0:	8f81801c 	lw	at,-32740\(gp\)
100001f4:	88250000 	lwl	a1,0\(at\)
100001f8:	98250003 	lwr	a1,3\(at\)
100001fc:	8f818020 	lw	at,-32736\(gp\)
10000200:	88250000 	lwl	a1,0\(at\)
10000204:	98250003 	lwr	a1,3\(at\)
10000208:	8f81801c 	lw	at,-32740\(gp\)
1000020c:	00310821 	addu	at,at,s1
10000210:	88250000 	lwl	a1,0\(at\)
10000214:	98250003 	lwr	a1,3\(at\)
10000218:	8f818020 	lw	at,-32736\(gp\)
1000021c:	00310821 	addu	at,at,s1
10000220:	88250000 	lwl	a1,0\(at\)
10000224:	98250003 	lwr	a1,3\(at\)
10000228:	8f818028 	lw	at,-32728\(gp\)
1000022c:	00250821 	addu	at,at,a1
10000230:	88250000 	lwl	a1,0\(at\)
10000234:	98250003 	lwr	a1,3\(at\)
10000238:	8f81802c 	lw	at,-32724\(gp\)
1000023c:	00250821 	addu	at,at,a1
10000240:	a8250000 	swl	a1,0\(at\)
10000244:	b8250003 	swr	a1,3\(at\)
10000248:	8f85805c 	lw	a1,-32676\(gp\)
1000024c:	8f858030 	lw	a1,-32720\(gp\)
10000250:	8f99805c 	lw	t9,-32676\(gp\)
10000254:	8f998030 	lw	t9,-32720\(gp\)
10000258:	8f99805c 	lw	t9,-32676\(gp\)
1000025c:	0320f809 	jalr	t9
10000260:	00000000 	nop
10000264:	8f998030 	lw	t9,-32720\(gp\)
10000268:	0320f809 	jalr	t9
1000026c:	00000000 	nop
10000270:	8f858068 	lw	a1,-32664\(gp\)
10000274:	8f858068 	lw	a1,-32664\(gp\)
10000278:	24a5000c 	addiu	a1,a1,12
1000027c:	8f858068 	lw	a1,-32664\(gp\)
10000280:	3c010001 	lui	at,0x1
10000284:	3421e240 	ori	at,at,0xe240
10000288:	00a12821 	addu	a1,a1,at
1000028c:	8f858068 	lw	a1,-32664\(gp\)
10000290:	00b12821 	addu	a1,a1,s1
10000294:	8f858068 	lw	a1,-32664\(gp\)
10000298:	24a5000c 	addiu	a1,a1,12
1000029c:	00b12821 	addu	a1,a1,s1
100002a0:	8f858068 	lw	a1,-32664\(gp\)
100002a4:	3c010001 	lui	at,0x1
100002a8:	3421e240 	ori	at,at,0xe240
100002ac:	00a12821 	addu	a1,a1,at
100002b0:	00b12821 	addu	a1,a1,s1
100002b4:	8f858018 	lw	a1,-32744\(gp\)
100002b8:	8ca50584 	lw	a1,1412\(a1\)
100002bc:	8f858018 	lw	a1,-32744\(gp\)
100002c0:	8ca50590 	lw	a1,1424\(a1\)
100002c4:	8f858018 	lw	a1,-32744\(gp\)
100002c8:	00b12821 	addu	a1,a1,s1
100002cc:	8ca50584 	lw	a1,1412\(a1\)
100002d0:	8f858018 	lw	a1,-32744\(gp\)
100002d4:	00b12821 	addu	a1,a1,s1
100002d8:	8ca50590 	lw	a1,1424\(a1\)
100002dc:	8f818018 	lw	at,-32744\(gp\)
100002e0:	00250821 	addu	at,at,a1
100002e4:	8c2505a6 	lw	a1,1446\(at\)
100002e8:	8f818018 	lw	at,-32744\(gp\)
100002ec:	00250821 	addu	at,at,a1
100002f0:	ac2505bc 	sw	a1,1468\(at\)
100002f4:	8f818068 	lw	at,-32664\(gp\)
100002f8:	88250000 	lwl	a1,0\(at\)
100002fc:	98250003 	lwr	a1,3\(at\)
10000300:	8f818068 	lw	at,-32664\(gp\)
10000304:	2421000c 	addiu	at,at,12
10000308:	88250000 	lwl	a1,0\(at\)
1000030c:	98250003 	lwr	a1,3\(at\)
10000310:	8f818068 	lw	at,-32664\(gp\)
10000314:	00310821 	addu	at,at,s1
10000318:	88250000 	lwl	a1,0\(at\)
1000031c:	98250003 	lwr	a1,3\(at\)
10000320:	8f818068 	lw	at,-32664\(gp\)
10000324:	2421000c 	addiu	at,at,12
10000328:	00310821 	addu	at,at,s1
1000032c:	88250000 	lwl	a1,0\(at\)
10000330:	98250003 	lwr	a1,3\(at\)
10000334:	8f818068 	lw	at,-32664\(gp\)
10000338:	24210022 	addiu	at,at,34
1000033c:	00250821 	addu	at,at,a1
10000340:	88250000 	lwl	a1,0\(at\)
10000344:	98250003 	lwr	a1,3\(at\)
10000348:	8f818068 	lw	at,-32664\(gp\)
1000034c:	24210038 	addiu	at,at,56
10000350:	00250821 	addu	at,at,a1
10000354:	a8250000 	swl	a1,0\(at\)
10000358:	b8250003 	swr	a1,3\(at\)
1000035c:	8f858034 	lw	a1,-32716\(gp\)
10000360:	8f858038 	lw	a1,-32712\(gp\)
10000364:	8f85803c 	lw	a1,-32708\(gp\)
10000368:	8f858034 	lw	a1,-32716\(gp\)
1000036c:	00b12821 	addu	a1,a1,s1
10000370:	8f858038 	lw	a1,-32712\(gp\)
10000374:	00b12821 	addu	a1,a1,s1
10000378:	8f85803c 	lw	a1,-32708\(gp\)
1000037c:	00b12821 	addu	a1,a1,s1
10000380:	8f858018 	lw	a1,-32744\(gp\)
10000384:	8ca50584 	lw	a1,1412\(a1\)
10000388:	8f858018 	lw	a1,-32744\(gp\)
1000038c:	8ca50590 	lw	a1,1424\(a1\)
10000390:	8f858018 	lw	a1,-32744\(gp\)
10000394:	00b12821 	addu	a1,a1,s1
10000398:	8ca50584 	lw	a1,1412\(a1\)
1000039c:	8f858018 	lw	a1,-32744\(gp\)
100003a0:	00b12821 	addu	a1,a1,s1
100003a4:	8ca50590 	lw	a1,1424\(a1\)
100003a8:	8f818018 	lw	at,-32744\(gp\)
100003ac:	00250821 	addu	at,at,a1
100003b0:	8c2505a6 	lw	a1,1446\(at\)
100003b4:	8f818018 	lw	at,-32744\(gp\)
100003b8:	00250821 	addu	at,at,a1
100003bc:	ac2505bc 	sw	a1,1468\(at\)
100003c0:	8f818034 	lw	at,-32716\(gp\)
100003c4:	88250000 	lwl	a1,0\(at\)
100003c8:	98250003 	lwr	a1,3\(at\)
100003cc:	8f818038 	lw	at,-32712\(gp\)
100003d0:	88250000 	lwl	a1,0\(at\)
100003d4:	98250003 	lwr	a1,3\(at\)
100003d8:	8f818034 	lw	at,-32716\(gp\)
100003dc:	00310821 	addu	at,at,s1
100003e0:	88250000 	lwl	a1,0\(at\)
100003e4:	98250003 	lwr	a1,3\(at\)
100003e8:	8f818038 	lw	at,-32712\(gp\)
100003ec:	00310821 	addu	at,at,s1
100003f0:	88250000 	lwl	a1,0\(at\)
100003f4:	98250003 	lwr	a1,3\(at\)
100003f8:	8f818040 	lw	at,-32704\(gp\)
100003fc:	00250821 	addu	at,at,a1
10000400:	88250000 	lwl	a1,0\(at\)
10000404:	98250003 	lwr	a1,3\(at\)
10000408:	8f818044 	lw	at,-32700\(gp\)
1000040c:	00250821 	addu	at,at,a1
10000410:	a8250000 	swl	a1,0\(at\)
10000414:	b8250003 	swr	a1,3\(at\)
10000418:	8f858060 	lw	a1,-32672\(gp\)
1000041c:	8f858048 	lw	a1,-32696\(gp\)
10000420:	8f998060 	lw	t9,-32672\(gp\)
10000424:	8f998048 	lw	t9,-32696\(gp\)
10000428:	8f998060 	lw	t9,-32672\(gp\)
1000042c:	0320f809 	jalr	t9
10000430:	00000000 	nop
10000434:	8f998048 	lw	t9,-32696\(gp\)
10000438:	0320f809 	jalr	t9
1000043c:	00000000 	nop
10000440:	1000ff17 	b	100000a0 <fn>
10000444:	8f858064 	lw	a1,-32668\(gp\)
10000448:	8f858018 	lw	a1,-32744\(gp\)
1000044c:	10000015 	b	100004a4 <fn2>
10000450:	8ca50584 	lw	a1,1412\(a1\)
10000454:	1000ff12 	b	100000a0 <fn>
10000458:	8f85801c 	lw	a1,-32740\(gp\)
1000045c:	8f858038 	lw	a1,-32712\(gp\)
10000460:	10000010 	b	100004a4 <fn2>
10000464:	00000000 	nop
10000468:	8f858024 	lw	a1,-32732\(gp\)
1000046c:	1000ff0c 	b	100000a0 <fn>
10000470:	00000000 	nop
10000474:	8f858018 	lw	a1,-32744\(gp\)
10000478:	1000000a 	b	100004a4 <fn2>
1000047c:	8ca50584 	lw	a1,1412\(a1\)
10000480:	8f858018 	lw	a1,-32744\(gp\)
10000484:	1000ff06 	b	100000a0 <fn>
10000488:	8ca50518 	lw	a1,1304\(a1\)
1000048c:	8f818018 	lw	at,-32744\(gp\)
10000490:	00250821 	addu	at,at,a1
10000494:	10000003 	b	100004a4 <fn2>
10000498:	8c2505a6 	lw	a1,1446\(at\)
	\.\.\.

100004a4 <fn2>:
	\.\.\.
Disassembly of section \.reginfo:

100004b0 <\.reginfo>:
100004b0:	92020022 	.*
	\.\.\.
100004c4:	101085b0 	.*
Disassembly of section \.data:

101004d0 <_fdata>:
	\.\.\.

1010050c <dg1>:
	\.\.\.

10100548 <sp2>:
	\.\.\.

10100584 <dg2>:
	\.\.\.
Disassembly of section \.got:

101005c0 <_GLOBAL_OFFSET_TABLE_>:
101005c0:	00000000 	.*
101005c4:	80000000 	.*
101005c8:	10100000 	.*
101005cc:	1010050c 	.*
101005d0:	10100518 	.*
101005d4:	1011e74c 	.*
101005d8:	1010052e 	.*
101005dc:	10100544 	.*
101005e0:	100000a0 	.*
101005e4:	10100584 	.*
101005e8:	10100590 	.*
101005ec:	1011e7c4 	.*
101005f0:	101005a6 	.*
101005f4:	101005bc 	.*
101005f8:	100004a4 	.*
101005fc:	00000000 	.*
	\.\.\.
1010060c:	100000a0 	.*
10100610:	100004a4 	.*
10100614:	1010050c 	.*
10100618:	10100584 	.*
#pass
