
#include "cmpinclude.h"
#include "assert.h"
void init_assert(){do_init(VV);}
/*	macro definition for CHECK-TYPE	*/

static void L1()
{register object *base=vs_base;
	register object *sup=base+VM1; VC1
	vs_reserve(VM1);
	check_arg(2);
	vs_top=sup;
	{object V1=base[0]->c.c_cdr;
	if(endp(V1))invalid_macro_call();
	base[2]= (V1->c.c_car);
	V1=V1->c.c_cdr;
	if(endp(V1))invalid_macro_call();
	base[3]= (V1->c.c_car);
	V1=V1->c.c_cdr;
	if(endp(V1)){
	base[4]= Cnil;
	base[5]= Cnil;
	} else {
	base[4]= (V1->c.c_car);
	base[5]= Ct;
	V1=V1->c.c_cdr;}
	if(!endp(V1))invalid_macro_call();}
	V2= list(2,list(3,VV[2],base[2],list(2,VV[3],base[3])),Cnil);
	V3= list(2,VV[3],base[2]);
	if((base[5])==Cnil){
	goto T4;}
	V4= base[4];
	goto T2;
goto T4;
T4:;
	V4= list(2,VV[3],base[3]);
goto T2;
T2:;
	V5= list(6,VV[4],VV[5],VV[6],/* INLINE-ARGS */V3,base[2],V4);
	V6= (*(LnkLI53))(base[2]);
	base[6]= list(6,VV[0],VV[1],/* INLINE-ARGS */V2,/* INLINE-ARGS */V5,/* INLINE-ARGS */V6,VV[7]);
	vs_top=(vs_base=base+6)+1;
	return;
}
/*	macro definition for ASSERT	*/

static void L2()
{register object *base=vs_base;
	register object *sup=base+VM2; VC2
	vs_reserve(VM2);
	check_arg(2);
	vs_top=sup;
	{object V7=base[0]->c.c_cdr;
	if(endp(V7))invalid_macro_call();
	base[2]= (V7->c.c_car);
	V7=V7->c.c_cdr;
	if(endp(V7)){
	base[3]= Cnil;
	} else {
	base[3]= (V7->c.c_car);
	V7=V7->c.c_cdr;}
	if(endp(V7)){
	base[4]= Cnil;
	} else {
	base[4]= (V7->c.c_car);
	V7=V7->c.c_cdr;}
	base[5]= V7;}
	V8= list(2,base[2],Cnil);
	if((base[4])==Cnil){
	goto T10;}
	V9= listA(4,VV[4],VV[9],base[4],base[5]);
	goto T8;
goto T10;
T10:;
	V9= list(4,VV[4],VV[10],VV[11],list(2,VV[3],base[2]));
goto T8;
T8:;
	{object V11;
	object V12= base[3];
	if(endp(V12)){
	V10= Cnil;
	goto T12;}
	base[6]=V11=MMcons(Cnil,Cnil);
goto T13;
T13:;
	(V11->c.c_car)= (*(LnkLI53))((V12->c.c_car));
	V12=MMcdr(V12);
	if(endp(V12)){
	V10= base[6];
	goto T12;}
	V11=MMcdr(V11)=MMcons(Cnil,Cnil);
	goto T13;}
goto T12;
T12:;
	base[6]= listA(5,VV[0],VV[8],/* INLINE-ARGS */V8,V9,append(V10,VV[12]));
	vs_top=(vs_base=base+6)+1;
	return;
}
/*	local entry for function ASK-FOR-FORM	*/

static object LI3(V14)

object V14;
{	 VMB3 VMS3 VMV3
goto TTL;
TTL:;
	V15= list(4,VV[14],VV[15],VV[16],list(2,VV[3],(V14)));
	{object V16 = list(4,VV[13],/* INLINE-ARGS */V15,VV[17],list(3,VV[18],(V14),VV[19]));
	VMR3(V16)}
	return Cnil;
}
/*	macro definition for ECASE	*/

static void L4()
{register object *base=vs_base;
	register object *sup=base+VM4; VC4
	vs_reserve(VM4);
	check_arg(2);
	vs_top=sup;
	{object V17=base[0]->c.c_cdr;
	if(endp(V17))invalid_macro_call();
	base[2]= (V17->c.c_car);
	V17=V17->c.c_cdr;
	base[3]= V17;
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	base[4]= vs_base[0];}
	{register object V18;
	register object V19;
	V18= reverse(base[3]);
	V20= list(2,VV[3],base[2]);
	{object V22;
	object V23= base[3];
	if(endp(V23)){
	V21= Cnil;
	goto T18;}
	base[5]=V22=MMcons(Cnil,Cnil);
goto T19;
T19:;
	{object V25= car((V23->c.c_car));
	if(!(type_of(V25)==t_cons||(V25)==Cnil)){
	goto T22;}}
	{object V26;
	object V27= car((V23->c.c_car));
	if(endp(V27)){
	(V22->c.c_cdr)= Cnil;
	goto T20;}
	base[6]=V26=MMcons(Cnil,Cnil);
goto T24;
T24:;
	(V26->c.c_car)= list(2,VV[3],(V27->c.c_car));
	V27=MMcdr(V27);
	if(endp(V27)){
	(V22->c.c_cdr)= base[6];
	goto T20;}
	V26=MMcdr(V26)=MMcons(Cnil,Cnil);
	goto T24;}
goto T22;
T22:;
	V29= list(2,VV[3],car((V23->c.c_car)));
	(V22->c.c_cdr)= make_cons(/* INLINE-ARGS */V29,Cnil);
goto T20;
T20:;
	{object cdr_V22=MMcdr(V22);while(!endp(cdr_V22)) {cdr_V22=MMcdr(cdr_V22);V22=MMcdr(V22);}}
	V23=MMcdr(V23);
	if(endp(V23)){
	base[5]=base[5]->c.c_cdr;
	V21= base[5];
	goto T18;}
	goto T19;}
goto T18;
T18:;
	V19= list(3,VV[20],VV[21],listA(5,VV[22],VV[23],/* INLINE-ARGS */V20,base[4],V21));
goto T27;
T27:;
	if(!(endp_prop((V18)))){
	goto T28;}
	V30= list(2,base[4],base[2]);
	base[5]= list(3,VV[20],make_cons(/* INLINE-ARGS */V30,Cnil),(V19));
	vs_top=(vs_base=base+5)+1;
	return;
goto T28;
T28:;
	if((caar((V18)))==Cnil){
	goto T32;}
	{object V32= caar((V18));
	if(!(type_of(V32)==t_cons||(V32)==Cnil)){
	goto T38;}}
	V31= list(3,VV[25],base[4],list(2,VV[3],caar((V18))));
	goto T36;
goto T38;
T38:;
	V31= list(3,VV[26],base[4],list(2,VV[3],caar((V18))));
goto T36;
T36:;
	V19= list(4,VV[24],V31,make_cons(VV[13],cdar((V18))),(V19));
goto T32;
T32:;
	V18= cdr((V18));
	goto T27;}
}
/*	macro definition for CCASE	*/

static void L5()
{register object *base=vs_base;
	register object *sup=base+VM5; VC5
	vs_reserve(VM5);
	check_arg(2);
	vs_top=sup;
	{object V33=base[0]->c.c_cdr;
	if(endp(V33))invalid_macro_call();
	base[2]= (V33->c.c_car);
	V33=V33->c.c_cdr;
	base[3]= V33;
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	base[4]= vs_base[0];}
	V34= list(2,base[4],base[2]);
	V35= make_cons(/* INLINE-ARGS */V34,Cnil);
	{object V37;
	object V38= base[3];
	if(endp(V38)){
	V36= Cnil;
	goto T44;}
	base[5]=V37=MMcons(Cnil,Cnil);
goto T45;
T45:;
	{register object V39;
	V39= (V38->c.c_car);
	{object V41= car((V39));
	if(!(type_of(V41)==t_cons||(V41)==Cnil)){
	goto T49;}}
	V40= list(3,VV[25],base[4],list(2,VV[3],car((V39))));
	goto T47;
goto T49;
T49:;
	V40= list(3,VV[26],base[4],list(2,VV[3],car((V39))));
goto T47;
T47:;
	(V37->c.c_car)= list(3,VV[28],V40,list(2,VV[29],make_cons(VV[13],cdr((V39)))));}
	V38=MMcdr(V38);
	if(endp(V38)){
	V36= base[5];
	goto T44;}
	V37=MMcdr(V37)=MMcons(Cnil,Cnil);
	goto T45;}
goto T44;
T44:;
	V42= list(2,VV[3],base[2]);
	{object V44;
	object V45= base[3];
	if(endp(V45)){
	V43= Cnil;
	goto T51;}
	base[5]=V44=MMcons(Cnil,Cnil);
goto T52;
T52:;
	{object V47= car((V45->c.c_car));
	if(!(type_of(V47)==t_cons||(V47)==Cnil)){
	goto T55;}}
	{object V48;
	object V49= car((V45->c.c_car));
	if(endp(V49)){
	(V44->c.c_cdr)= Cnil;
	goto T53;}
	base[6]=V48=MMcons(Cnil,Cnil);
goto T57;
T57:;
	(V48->c.c_car)= list(2,VV[3],(V49->c.c_car));
	V49=MMcdr(V49);
	if(endp(V49)){
	(V44->c.c_cdr)= base[6];
	goto T53;}
	V48=MMcdr(V48)=MMcons(Cnil,Cnil);
	goto T57;}
goto T55;
T55:;
	V51= list(2,VV[3],car((V45->c.c_car)));
	(V44->c.c_cdr)= make_cons(/* INLINE-ARGS */V51,Cnil);
goto T53;
T53:;
	{object cdr_V44=MMcdr(V44);while(!endp(cdr_V44)) {cdr_V44=MMcdr(cdr_V44);V44=MMcdr(V44);}}
	V45=MMcdr(V45);
	if(endp(V45)){
	base[5]=base[5]->c.c_cdr;
	V43= base[5];
	goto T51;}
	goto T52;}
goto T51;
T51:;
	V52= listA(6,VV[4],VV[31],VV[32],/* INLINE-ARGS */V42,base[4],V43);
	V53= (*(LnkLI53))(base[2]);
	V54= list(5,VV[20],VV[30],/* INLINE-ARGS */V52,/* INLINE-ARGS */V53,VV[33]);
	V55= make_cons(/* INLINE-ARGS */V54,Cnil);
	base[5]= list(2,VV[27],listA(3,VV[20],/* INLINE-ARGS */V35,append(V36,/* INLINE-ARGS */V55)));
	vs_top=(vs_base=base+5)+1;
	return;
}
/*	macro definition for TYPECASE	*/

static void L6()
{register object *base=vs_base;
	register object *sup=base+VM6; VC6
	vs_reserve(VM6);
	check_arg(2);
	vs_top=sup;
	{object V56=base[0]->c.c_cdr;
	if(endp(V56))invalid_macro_call();
	base[2]= (V56->c.c_car);
	V56=V56->c.c_cdr;
	base[3]= V56;}
	{register object V57;
	register object V58;
	register object V59;
	V57= reverse(base[3]);
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	V59= vs_base[0];
	V58= Cnil;
goto T62;
T62:;
	if(!(endp_prop((V57)))){
	goto T63;}
	V60= list(2,(V59),base[2]);
	base[4]= list(3,VV[20],make_cons(/* INLINE-ARGS */V60,Cnil),(V58));
	vs_top=(vs_base=base+4)+1;
	return;
goto T63;
T63:;
	if((caar((V57)))==(Ct)){
	goto T68;}
	if(!((caar((V57)))==(VV[34]))){
	goto T69;}
goto T68;
T68:;
	V58= make_cons(VV[13],cdar((V57)));
	goto T67;
goto T69;
T69:;
	V61= list(3,VV[2],(V59),list(2,VV[3],caar((V57))));
	V58= list(4,VV[24],/* INLINE-ARGS */V61,make_cons(VV[13],cdar((V57))),(V58));
goto T67;
T67:;
	V57= cdr((V57));
	goto T62;}
}
/*	macro definition for ETYPECASE	*/

static void L7()
{register object *base=vs_base;
	register object *sup=base+VM7; VC7
	vs_reserve(VM7);
	check_arg(2);
	vs_top=sup;
	{object V62=base[0]->c.c_cdr;
	if(endp(V62))invalid_macro_call();
	base[2]= (V62->c.c_car);
	V62=V62->c.c_cdr;
	base[3]= V62;
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	base[4]= vs_base[0];}
	{register object V63;
	register object V64;
	V63= reverse(base[3]);
	V65= list(2,VV[3],base[2]);
	{object V67;
	object V68= base[3];
	if(endp(V68)){
	V66= Cnil;
	goto T81;}
	base[5]=V67=MMcons(Cnil,Cnil);
goto T82;
T82:;
	(V67->c.c_car)= car((V68->c.c_car));
	V68=MMcdr(V68);
	if(endp(V68)){
	V66= base[5];
	goto T81;}
	V67=MMcdr(V67)=MMcons(Cnil,Cnil);
	goto T82;}
goto T81;
T81:;
	V64= list(2,VV[22],list(4,VV[35],/* INLINE-ARGS */V65,base[4],list(2,VV[3],V66)));
goto T85;
T85:;
	if(!(endp_prop((V63)))){
	goto T86;}
	V70= list(2,base[4],base[2]);
	base[5]= list(3,VV[20],make_cons(/* INLINE-ARGS */V70,Cnil),(V64));
	vs_top=(vs_base=base+5)+1;
	return;
goto T86;
T86:;
	V71= list(3,VV[2],base[4],list(2,VV[3],caar((V63))));
	V64= list(4,VV[24],/* INLINE-ARGS */V71,make_cons(VV[13],cdar((V63))),(V64));
	V63= cdr((V63));
	goto T85;}
}
/*	macro definition for CTYPECASE	*/

static void L8()
{register object *base=vs_base;
	register object *sup=base+VM8; VC8
	vs_reserve(VM8);
	check_arg(2);
	vs_top=sup;
	{object V72=base[0]->c.c_cdr;
	if(endp(V72))invalid_macro_call();
	base[2]= (V72->c.c_car);
	V72=V72->c.c_cdr;
	base[3]= V72;
	vs_base=vs_top;
	Lgensym();
	vs_top=sup;
	base[4]= vs_base[0];}
	V73= list(2,base[4],base[2]);
	V74= make_cons(/* INLINE-ARGS */V73,Cnil);
	{object V76;
	object V77= base[3];
	if(endp(V77)){
	V75= Cnil;
	goto T96;}
	base[5]=V76=MMcons(Cnil,Cnil);
goto T97;
T97:;
	V79= list(3,VV[2],base[4],list(2,VV[3],car((V77->c.c_car))));
	(V76->c.c_car)= list(3,VV[28],/* INLINE-ARGS */V79,list(2,VV[29],make_cons(VV[13],cdr((V77->c.c_car)))));
	V77=MMcdr(V77);
	if(endp(V77)){
	V75= base[5];
	goto T96;}
	V76=MMcdr(V76)=MMcons(Cnil,Cnil);
	goto T97;}
goto T96;
T96:;
	V80= list(2,VV[3],base[2]);
	{object V82;
	object V83= base[3];
	if(endp(V83)){
	V81= Cnil;
	goto T99;}
	base[5]=V82=MMcons(Cnil,Cnil);
goto T100;
T100:;
	(V82->c.c_car)= car((V83->c.c_car));
	V83=MMcdr(V83);
	if(endp(V83)){
	V81= base[5];
	goto T99;}
	V82=MMcdr(V82)=MMcons(Cnil,Cnil);
	goto T100;}
goto T99;
T99:;
	V85= list(3,VV[4],VV[36],list(4,VV[35],/* INLINE-ARGS */V80,base[4],list(2,VV[3],V81)));
	V86= make_cons(/* INLINE-ARGS */V85,Cnil);
	V87= listA(3,VV[20],/* INLINE-ARGS */V74,append(V75,/* INLINE-ARGS */V86));
	V88= (*(LnkLI53))(base[2]);
	base[5]= list(4,VV[27],/* INLINE-ARGS */V87,/* INLINE-ARGS */V88,VV[37]);
	vs_top=(vs_base=base+5)+1;
	return;
}
/*	local entry for function TYPECASE-ERROR-STRING	*/

static object LI9(V92,V93,V94)

object V92;object V93;register object V94;
{	 VMB9 VMS9 VMV9
goto TTL;
TTL:;
	{register object V95;
	register object V96;
	register object V97;
	V95= Cnil;
	V96= Cnil;
	V97= Cnil;
goto T107;
T107:;
	if(!(endp_prop((V94)))){
	goto T108;}
	goto T105;
goto T108;
T108:;
	if(!(type_of(car((V94)))==t_symbol)){
	goto T114;}
	V98= make_cons(car((V94)),Cnil);
	V95= make_cons(/* INLINE-ARGS */V98,(V95));
	{register object V99;
	V99= car((V94));
	V94= cdr((V94));
	goto T112;}
goto T114;
T114:;
	{object V100= caar((V94));
	if((V100!= VV[54]))goto T121;
	V94= append(cdar((V94)),cdr((V94)));
	goto T112;
goto T121;
T121:;
	if((V100!= VV[25]))goto T123;
	{
	object V101= cdar((V94));
	if(endp(V101)){
	goto T124;}
goto T125;
T125:;
	{register object V102;
	V102= (V101->c.c_car);
	V103= list(2,VV[25],(V102));
	V95= make_cons(/* INLINE-ARGS */V103,(V95));}
	V101=MMcdr(V101);
	if(endp(V101)){
	(void)(cdar((V94)));
	goto T124;}
	goto T125;}
goto T124;
T124:;
	{register object V104;
	V104= car((V94));
	V94= cdr((V94));
	goto T112;}
goto T123;
T123:;
	if((V100!= VV[55]))goto T131;
	V96= make_cons(cadar((V94)),(V96));
	{register object V105;
	V105= car((V94));
	V94= cdr((V94));
	goto T112;}
goto T131;
T131:;
	V95= make_cons(car((V94)),(V95));
	{register object V106;
	V106= car((V94));
	V94= cdr((V94));}}
goto T112;
T112:;
	goto T107;
goto T105;
T105:;
goto T146;
T146:;
	if(!(endp_prop((V96)))){
	goto T147;}
	goto T144;
goto T147;
T147:;
	if(!(type_of(car((V96)))==t_symbol)){
	goto T153;}
	V107= make_cons(car((V96)),Cnil);
	V97= make_cons(/* INLINE-ARGS */V107,(V97));
	{register object V108;
	V108= car((V96));
	V96= cdr((V96));
	goto T151;}
goto T153;
T153:;
	if(!((caar((V96)))==(VV[38]))){
	goto T161;}
	V96= append(cdar((V96)),cdr((V96)));
	goto T151;
goto T161;
T161:;
	V97= make_cons(car((V96)),(V97));
	{register object V109;
	V109= car((V96));
	V96= cdr((V96));}
goto T151;
T151:;
	goto T146;
goto T144;
T144:;
	base[0]= Cnil;
	base[1]= VV[39];
	base[2]= (V92);
	base[3]= (V93);
	base[4]= VV[40];
	{object V110;
	object V111= (V97);
	if(endp(V111)){
	base[5]= Cnil;
	goto T176;}
	base[6]=V110=MMcons(Cnil,Cnil);
goto T177;
T177:;
	(V110->c.c_cdr)= (*(LnkLI56))((V111->c.c_car));
	{object cdr_V110=MMcdr(V110);while(!endp(cdr_V110)) {cdr_V110=MMcdr(cdr_V110);V110=MMcdr(V110);}}
	V111=MMcdr(V111);
	if(endp(V111)){
	base[6]=base[6]->c.c_cdr;
	base[5]= base[6];
	goto T176;}
	goto T177;}
goto T176;
T176:;
	base[6]= VV[41];
	V112 = make_fixnum((long)length((V95)));
	V116= reverse((V95));
	{object V114;
	object V115= /* INLINE-ARGS */V116;
	if(endp(V115)){
	V113= Cnil;
	goto T181;}
	base[8]=V114=MMcons(Cnil,Cnil);
goto T182;
T182:;
	(V114->c.c_cdr)= (*(LnkLI56))((V115->c.c_car));
	{object cdr_V114=MMcdr(V114);while(!endp(cdr_V114)) {cdr_V114=MMcdr(cdr_V114);V114=MMcdr(V114);}}
	V115=MMcdr(V115);
	if(endp(V115)){
	base[8]=base[8]->c.c_cdr;
	V113= base[8];
	goto T181;}
	goto T182;}
goto T181;
T181:;
	base[7]= listA(3,(V97),V112,V113);
	vs_top=(vs_base=base+0)+8;
	Lformat();
	vs_top=sup;
	{object V117 = vs_base[0];
	VMR9(V117)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function TYPECASE-ERROR-STRINGS	*/

static object LI10(V119)

register object V119;
{	 VMB10 VMS10 VMV10
goto TTL;
TTL:;
	if(!((car((V119)))==(VV[25]))){
	goto T185;}switch((long)length(cdr((V119)))){
	case 0:
goto T188;
T188:;
	{object V120 = VV[42];
	VMR10(V120)}
	case 1:
goto T189;
T189:;
	{object V121 = list(2,VV[43],make_cons(cadr((V119)),Cnil));
	VMR10(V121)}
	case 2:
goto T190;
T190:;
	{object V122 = list(2,VV[44],cdr((V119)));
	VMR10(V122)}
	default:
goto T191;
T191:;
	{object V123 = list(2,VV[45],make_cons(cdr((V119)),Cnil));
	VMR10(V123)}
	{object V124 = Cnil;
	VMR10(V124)}}
	{object V125 = Cnil;
	VMR10(V125)}
goto T185;
T185:;
	if(!((car((V119)))==(VV[46]))){
	goto T194;}
	{object V126 = list(2,VV[47],cdr((V119)));
	VMR10(V126)}
goto T194;
T194:;
	if(endp_prop(cdr((V119)))){
	goto T196;}
	if(((VFUN_NARGS=2,(*(LnkLI57))(VV[48],cdr((V119)))))!=Cnil){
	goto T197;}
goto T196;
T196:;
	{object V127;
	{register object x= car((V119)),V128= VV[49];
	while(!endp(V128))
	if(type_of(V128->c.c_car)==t_cons &&eql(x,V128->c.c_car->c.c_car)){
	V127= (V128->c.c_car);
	goto T201;
	}else V128=V128->c.c_cdr;
	V127= Cnil;}
goto T201;
T201:;
	if(((V127))==Cnil){
	goto T203;}
	{object V129 = list(2,cadr((V127)),Cnil);
	VMR10(V129)}
goto T203;
T203:;
	V130= (*(LnkLI58))(car((V119)));
	{object V131 = list(2,VV[50],list(2,/* INLINE-ARGS */V130,car((V119))));
	VMR10(V131)}}
goto T197;
T197:;
	V132= (*(LnkLI58))(car((V119)));
	{object V133 = list(2,VV[51],list(2,/* INLINE-ARGS */V132,(V119)));
	VMR10(V133)}
	return Cnil;
}
/*	local entry for function BOIN-P	*/

static object LI11(V135)

object V135;
{	 VMB11 VMS11 VMV11
goto TTL;
TTL:;
	V137= symbol_name((V135));
	V138= elt(/* INLINE-ARGS */V137,0);
	{register object x= /* INLINE-ARGS */V138,V136= VV[52];
	while(!endp(V136))
	if(eql(x,V136->c.c_car)){
	{object V139 = V136;
	VMR11(V139)}
	}else V136=V136->c.c_cdr;
	{object V140 = Cnil;
	VMR11(V140)}}
	return Cnil;
}
static object  LnkTLI58(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[58],(void **)&LnkLI58,1,ap);va_end(ap);return V1;} /* BOIN-P */
static object  LnkTLI57(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_vproc(VV[57],(void **)&LnkLI57,ap);va_end(ap);return V1;} /* REMOVE */
static object  LnkTLI56(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[56],(void **)&LnkLI56,1,ap);va_end(ap);return V1;} /* TYPECASE-ERROR-STRINGS */
static object  LnkTLI53(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[53],(void **)&LnkLI53,1,ap);va_end(ap);return V1;} /* ASK-FOR-FORM */

#ifdef SYSTEM_SPECIAL_INIT
SYSTEM_SPECIAL_INIT
#endif

