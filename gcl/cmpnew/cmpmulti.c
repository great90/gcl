
#include "cmpinclude.h"
#include "cmpmulti.h"
void init_cmpmulti(){do_init(VV);}
/*	local entry for function C1MULTIPLE-VALUE-CALL	*/

static object LI1(V2)

register object V2;
{	 VMB1 VMS1 VMV1
goto TTL;
TTL:;
	{object V3;
	object V4;
	V3= Cnil;
	V4= Cnil;
	if(!(endp_prop((V2)))){
	goto T3;}
	(void)((*(LnkLI38))(VV[0],small_fixnum(1),small_fixnum(0)));
goto T3;
T3:;
	if(!(endp_prop(cdr((V2))))){
	goto T7;}
	{object V5 = (*(LnkLI39))((V2));
	VMR1(V5)}
goto T7;
T7:;
	V4= (*(LnkLI40))(car((V2)));
	base[0]= cadr((V4));
	vs_top=(vs_base=base+0)+1;
	(void) (*Lnk41)();
	vs_top=sup;
	V3= vs_base[0];
	V2= (*(LnkLI42))(cdr((V2)),(V3));
	{object V6 = list(4,VV[0],(V3),(V4),(V2));
	VMR1(V6)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function C2MULTIPLE-VALUE-CALL	*/

static object LI2(V9,V10)

register object V9;object V10;
{	 VMB2 VMS2 VMV2
	bds_check;
goto TTL;
TTL:;
	{register object V11;
	register object V12;
	bds_bind(VV[1],symbol_value(VV[1]));
	V11= Cnil;
	V12= Cnil;
	if(!(endp_prop(cdr((V10))))){
	goto T19;}
	V11= (*(LnkLI43))((V9));
	bds_bind(VV[2],VV[3]);
	V13= (*(LnkLI44))(car((V10)));
	bds_unwind1;
	{object V14 = (VFUN_NARGS=3,(*(LnkLI45))((V9),VV[4],(V11)));
	bds_unwind1;
	VMR2(V14)}
goto T19;
T19:;
	setq(VV[5],number_plus(symbol_value(VV[5]),small_fixnum(1)));
	V12= symbol_value(VV[5]);
	V11= (*(LnkLI43))((V9));
	princ_str("\n	{object *V",VV[6]);
	(void)((*(LnkLI46))((V12)));
	princ_str("=base+",VV[6]);
	(void)((*(LnkLI46))((VV[1]->s.s_dbind)));
	princ_char(59,VV[6]);
	setq(VV[7],Ct);
	{register object V15;
	register object V16;
	V15= (V10);
	V16= car((V15));
goto T41;
T41:;
	if(!(endp_prop((V15)))){
	goto T42;}
	goto T37;
goto T42;
T42:;
	bds_bind(VV[2],VV[3]);
	V17= (*(LnkLI47))((V16),(V12));
	bds_unwind1;
	princ_str("\n	while(vs_base<vs_top)",VV[6]);
	princ_str("\n	{V",VV[6]);
	(void)((*(LnkLI46))((V12)));
	princ_str("[0]=vs_base[0];V",VV[6]);
	(void)((*(LnkLI46))((V12)));
	princ_str("++;vs_base++;}",VV[6]);
	V15= cdr((V15));
	V16= car((V15));
	goto T41;}
goto T37;
T37:;
	princ_str("\n	vs_base=base+",VV[6]);
	(void)((*(LnkLI46))((VV[1]->s.s_dbind)));
	princ_str(";vs_top=V",VV[6]);
	(void)((*(LnkLI46))((V12)));
	princ_char(59,VV[6]);
	setq(VV[7],Ct);
	(void)((VFUN_NARGS=3,(*(LnkLI45))((V9),VV[4],(V11))));
	princ_char(125,VV[6]);
	{object V18 = Cnil;
	bds_unwind1;
	VMR2(V18)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function C1MULTIPLE-VALUE-PROG1	*/

static object LI3(V20)

register object V20;
{	 VMB3 VMS3 VMV3
goto TTL;
TTL:;
	{object V21;
	object V22;
	V21= (VFUN_NARGS=0,(*(LnkLI48))());
	V22= Cnil;
	if(!(endp_prop((V20)))){
	goto T72;}
	(void)((*(LnkLI38))(VV[8],small_fixnum(1),small_fixnum(0)));
goto T72;
T72:;
	V22= (*(LnkLI49))(car((V20)),(V21));
	V20= (*(LnkLI42))(cdr((V20)),(V21));
	{object V23 = list(4,VV[8],(V21),(V22),(V20));
	VMR3(V23)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function C2MULTIPLE-VALUE-PROG1	*/

static object LI4(V26,V27)

object V26;object V27;
{	 VMB4 VMS4 VMV4
	bds_check;
goto TTL;
TTL:;
	{object V28;
	register object V29;
	object V30;
	setq(VV[5],number_plus(symbol_value(VV[5]),small_fixnum(1)));
	V28= symbol_value(VV[5]);
	setq(VV[5],number_plus(symbol_value(VV[5]),small_fixnum(1)));
	V29= symbol_value(VV[5]);
	V30= Cnil;
	bds_bind(VV[2],VV[3]);
	bds_bind(VV[9],Cnil);
	(void)((*(LnkLI44))((V26)));
	V30= (VV[9]->s.s_dbind);
	bds_unwind1;
	bds_unwind1;
	princ_str("\n	{object *V",VV[6]);
	(void)((*(LnkLI46))((V29)));
	princ_str("=vs_top;object *V",VV[6]);
	(void)((*(LnkLI46))((V28)));
	princ_str("=vs_base; vs_base=V",VV[6]);
	(void)((*(LnkLI46))((V29)));
	princ_char(59,VV[6]);
	{register object V31;
	register object V32;
	V31= (V27);
	V32= car((V31));
goto T99;
T99:;
	if(!(endp_prop((V31)))){
	goto T100;}
	goto T95;
goto T100;
T100:;
	bds_bind(VV[2],VV[10]);
	V33= (*(LnkLI47))((V32),(V29));
	bds_unwind1;
	V31= cdr((V31));
	V32= car((V31));
	goto T99;}
goto T95;
T95:;
	princ_str("\n	vs_base=V",VV[6]);
	(void)((*(LnkLI46))((V28)));
	princ_str(";vs_top=V",VV[6]);
	(void)((*(LnkLI46))((V29)));
	princ_str(";}",VV[6]);
	if(((V30))==Cnil){
	goto T118;}
	V34= car((V30));
	goto T116;
goto T118;
T118:;
	V34= Cnil;
goto T116;
T116:;
	{object V35 = (VFUN_NARGS=3,(*(LnkLI50))(VV[11],Cnil,V34));
	VMR4(V35)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function C1VALUES	*/

static object LI5(V37)

register object V37;
{	 VMB5 VMS5 VMV5
goto TTL;
TTL:;
	{object V38;
	V38= (VFUN_NARGS=0,(*(LnkLI48))());
	if(((V37))==Cnil){
	goto T122;}
	if((cdr((V37)))!=Cnil){
	goto T122;}
	if(!(type_of(car((V37)))==t_cons)){
	goto T121;}
	if(!(type_of(caar((V37)))==t_symbol)){
	goto T122;}
	{register object V39;
	V39= (*(LnkLI51))(caar((V37)));
	if((V39)==Cnil){
	goto T122;}
	if(!(type_of((V39))!=t_cons)){
	goto T133;}
	goto T131;
goto T133;
T133:;
	if(type_of((V39))==t_cons){
	goto T135;}
	goto T122;
goto T135;
T135:;
	if((cdr((V39)))==Cnil){
	goto T137;}
	goto T122;
goto T137;
T137:;
	if(!((((VV[12])==(car((V39)))?Ct:Cnil))==Cnil)){
	goto T122;}}
goto T131;
T131:;
goto T121;
T121:;
	{object V40 = (*(LnkLI52))(car((V37)));
	VMR5(V40)}
goto T122;
T122:;
	V37= (*(LnkLI42))((V37),(V38));
	{object V41 = list(3,VV[13],(V38),(V37));
	VMR5(V41)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function C2VALUES	*/

static object LI6(V43)

register object V43;
{	 VMB6 VMS6 VMV6
	bds_check;
goto TTL;
TTL:;
	{object V44;
	V44= symbol_value(VV[1]);
	bds_bind(VV[1],symbol_value(VV[1]));
	if(!((symbol_value(VV[2]))==(VV[14]))){
	goto T142;}
	if((cdr((V43)))==Cnil){
	goto T142;}
	if(!(type_of(symbol_value(VV[15]))==t_cons)){
	goto T142;}
	if(!((VV[16])==(car(symbol_value(VV[15]))))){
	goto T142;}
	(void)((VFUN_NARGS=2,(*(LnkLI53))(VV[17],cadr(symbol_value(VV[15])))));
goto T142;
T142:;
	if(((V43))!=Cnil){
	goto T153;}
	princ_str("\n	vs_base=vs_top=base+",VV[6]);
	(void)((*(LnkLI46))((V44)));
	princ_char(59,VV[6]);
	setq(VV[7],Ct);
	princ_str("\n	vs_base[0]=Cnil;",VV[6]);
	goto T151;
goto T153;
T153:;
	{register object V45;
	register object V46;
	V45= (V43);
	V46= car((V45));
goto T166;
T166:;
	if(!(endp_prop((V45)))){
	goto T167;}
	goto T162;
goto T167;
T167:;
	base[2]= list(2,VV[18],(*(LnkLI54))());
	bds_bind(VV[2],base[2]);
	V47= (*(LnkLI44))((V46));
	bds_unwind1;
	V45= cdr((V45));
	V46= car((V45));
	goto T166;}
goto T162;
T162:;
	princ_str("\n	vs_top=(vs_base=base+",VV[6]);
	(void)((*(LnkLI46))((V44)));
	princ_str(")+",VV[6]);
	V48= number_minus((VV[1]->s.s_dbind),(V44));
	(void)((*(LnkLI46))(/* INLINE-ARGS */V48));
	princ_char(59,VV[6]);
	setq(VV[7],Ct);
goto T151;
T151:;
	V49 = make_fixnum((long)length((V43)));
	V50= make_cons(VV[13],V49);
	{object V51 = (VFUN_NARGS=3,(*(LnkLI50))(VV[11],Cnil,/* INLINE-ARGS */V50));
	bds_unwind1;
	VMR6(V51)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function C1MULTIPLE-VALUE-SETQ	*/

static object LI7(V53)

object V53;
{	 VMB7 VMS7 VMV7
goto TTL;
TTL:;
	{register object V54;
	register object V55;
	V54= (VFUN_NARGS=0,(*(LnkLI48))());
	V55= Cnil;
	if(endp_prop((V53))){
	goto T188;}
	if(!(endp_prop(cdr((V53))))){
	goto T187;}
goto T188;
T188:;
	(void)((*(LnkLI38))(VV[19],small_fixnum(2),small_fixnum(0)));
goto T187;
T187:;
	if(endp_prop(cddr((V53)))){
	goto T192;}
	V56 = make_fixnum((long)length((V53)));
	(void)((*(LnkLI55))(VV[19],small_fixnum(2),V56));
goto T192;
T192:;
	{register object V57;
	register object V58;
	V57= car((V53));
	V58= car((V57));
goto T199;
T199:;
	if(!(endp_prop((V57)))){
	goto T200;}
	goto T195;
goto T200;
T200:;
	if(type_of((V58))==t_symbol){
	goto T204;}
	(void)((VFUN_NARGS=2,(*(LnkLI56))(VV[20],(V58))));
goto T204;
T204:;
	base[3]= (V58);
	vs_top=(vs_base=base+3)+1;
	Lconstantp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T207;}
	(void)((VFUN_NARGS=2,(*(LnkLI56))(VV[21],(V58))));
goto T207;
T207:;
	V58= (*(LnkLI57))((V58));
	V55= make_cons((V58),(V55));
	{register object V59;
	register object V60;
	V59= (V54);
	V61= car((V58));
	V62= structure_ref((V59),VV[22],0);
	V60= make_cons(/* INLINE-ARGS */V61,/* INLINE-ARGS */V62);
	(void)(structure_set((V59),VV[22],0,(V60)));}
	V57= cdr((V57));
	V58= car((V57));
	goto T199;}
goto T195;
T195:;
	V63= reverse((V55));
	{object V64 = list(4,VV[19],(V54),/* INLINE-ARGS */V63,(*(LnkLI49))(cadr((V53)),(V54)));
	VMR7(V64)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function MULTIPLE-VALUE-CHECK	*/

static object LI8(V67,V68)

object V67;object V68;
{	 VMB8 VMS8 VMV8
goto TTL;
TTL:;
	if((cdr((V67)))!=Cnil){
	goto T223;}
	{object V69 = Cnil;
	VMR8(V69)}
goto T223;
T223:;
	if((car((V68)))==(VV[23])){
	goto T225;}
	{object V70 = Cnil;
	VMR8(V70)}
goto T225;
T225:;
	{object V71;
	V71= caddr((V68));
	if(!(type_of((V71))==t_symbol)){
	goto T229;}
	{register object V72;
	V72= get((V71),VV[24],Cnil);
	if((V72)==Cnil){
	goto T229;}
	if(type_of((V72))==t_cons){
	goto T234;}
	goto T229;
goto T234;
T234:;
	if(((equal((V72),VV[25])?Ct:Cnil))==Cnil){
	goto T236;}
	goto T229;
goto T236;
T236:;
	if(!((cdr((V72)))==Cnil)){
	goto T229;}}
	{object V73 = (VFUN_NARGS=2,(*(LnkLI53))(VV[26],(V71)));
	VMR8(V73)}
goto T229;
T229:;
	{object V74 = Cnil;
	VMR8(V74)}}
	return Cnil;
}
/*	local entry for function C2MULTIPLE-VALUE-SETQ	*/

static object LI9(V77,V78)

register object V77;object V78;
{	 VMB9 VMS9 VMV9
	bds_check;
goto TTL;
TTL:;
	{object V79;
	V79= Cnil;
	(void)((*(LnkLI58))((V77),(V78)));
	bds_bind(VV[2],VV[3]);
	bds_bind(VV[9],Cnil);
	(void)((*(LnkLI44))((V78)));
	V79= (VV[9]->s.s_dbind);
	bds_unwind1;
	bds_unwind1;
	if(symbol_value(VV[27])==Cnil){
	goto T243;}
	(void)((*(LnkLI59))(Cnil,car((V79))));
goto T243;
T243:;
	{register object V80;
	V80= (V77);
goto T246;
T246:;
	if(!(endp_prop((V80)))){
	goto T247;}
	goto T244;
goto T247;
T247:;
	{register object V81;
	V81= car((V80));
	princ_str("\n	if(vs_base<vs_top){",VV[6]);
	(void)((*(LnkLI60))(VV[11],car((V81)),cadr((V81))));
	if(endp_prop(cdr((V80)))){
	goto T256;}
	princ_str("\n	vs_base++;",VV[6]);
goto T256;
T256:;
	princ_str("\n	}else{",VV[6]);
	(void)((*(LnkLI60))(Cnil,car((V81)),cadr((V81))));
	princ_char(125,VV[6]);}
	V80= cdr((V80));
	goto T246;}
goto T244;
T244:;
	if(((V77))!=Cnil){
	goto T268;}
	princ_str("\n	if(vs_base=vs_top){vs_base[0]=Cnil;vs_top=vs_base+1;}",VV[6]);
	{object V82 = (VFUN_NARGS=1,(*(LnkLI50))(VV[11]));
	VMR9(V82)}
goto T268;
T268:;
	if((symbol_value(VV[28]))==(VV[29])){
	goto T272;}
	princ_str("\n	",VV[6]);
	(void)((*(LnkLI61))());
goto T272;
T272:;
	V83= make_cons(VV[30],car((V77)));
	{object V84 = (VFUN_NARGS=1,(*(LnkLI50))(/* INLINE-ARGS */V83));
	VMR9(V84)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function C1MULTIPLE-VALUE-BIND	*/

static object LI10(V86)

object V86;
{	 VMB10 VMS10 VMV10
	bds_check;
goto TTL;
TTL:;
	{object V87;
	register object V88;
	register object V89;
	object V90;
	object V91;
	object V92;
	object V93;
	object V94;
	object V95;
	V87= (VFUN_NARGS=0,(*(LnkLI48))());
	V88= Cnil;
	V89= Cnil;
	V90= Cnil;
	V91= Cnil;
	V92= Cnil;
	V93= Cnil;
	V94= Cnil;
	V95= Cnil;
	bds_bind(VV[31],symbol_value(VV[31]));
	if(endp_prop((V86))){
	goto T286;}
	if(!(endp_prop(cdr((V86))))){
	goto T285;}
goto T286;
T286:;
	V96 = make_fixnum((long)length((V86)));
	(void)((*(LnkLI38))(VV[32],small_fixnum(2),V96));
goto T285;
T285:;
	base[2]= cddr((V86));
	base[3]= Cnil;
	vs_top=(vs_base=base+2)+2;
	(void) (*Lnk62)();
	if(vs_base<vs_top){
	V94= vs_base[0];
	vs_base++;
	}else{
	V94= Cnil;}
	if(vs_base<vs_top){
	V91= vs_base[0];
	vs_base++;
	}else{
	V91= Cnil;}
	if(vs_base<vs_top){
	V93= vs_base[0];
	vs_base++;
	}else{
	V93= Cnil;}
	if(vs_base<vs_top){
	V92= vs_base[0];
	vs_base++;
	}else{
	V92= Cnil;}
	if(vs_base<vs_top){
	V95= vs_base[0];
	}else{
	V95= Cnil;}
	vs_top=sup;
	(void)((*(LnkLI63))((V91)));
	{register object V97;
	register object V98;
	V97= car((V86));
	V98= car((V97));
goto T299;
T299:;
	if(!(endp_prop((V97)))){
	goto T300;}
	goto T295;
goto T300;
T300:;
	{object V99;
	V99= (*(LnkLI64))((V98),(V91),(V92),(V93));
	V89= make_cons((V98),(V89));
	V88= make_cons((V99),(V88));}
	V97= cdr((V97));
	V98= car((V97));
	goto T299;}
goto T295;
T295:;
	V90= (*(LnkLI49))(cadr((V86)),(V87));
	{register object V100;
	object V101;
	V100= reverse((V88));
	V101= car((V100));
goto T320;
T320:;
	if(!(endp_prop((V100)))){
	goto T321;}
	goto T316;
goto T321;
T321:;
	(VV[31]->s.s_dbind)= make_cons((V101),(VV[31]->s.s_dbind));
	V100= cdr((V100));
	V101= car((V100));
	goto T320;}
goto T316;
T316:;
	(void)((*(LnkLI65))((V89),(V93),(V92)));
	V94= (*(LnkLI66))((V95),(V94));
	(void)((*(LnkLI67))((V87),cadr((V94))));
	V102= structure_ref(cadr((V94)),VV[22],2);
	(void)(structure_set((V87),VV[22],2,/* INLINE-ARGS */V102));
	{register object V103;
	object V104;
	V103= (V88);
	V104= car((V103));
goto T341;
T341:;
	if(!(endp_prop((V103)))){
	goto T342;}
	goto T337;
goto T342;
T342:;
	(void)((*(LnkLI68))((V104)));
	V103= cdr((V103));
	V104= car((V103));
	goto T341;}
goto T337;
T337:;
	{object V105 = list(5,VV[32],(V87),reverse((V88)),(V90),(V94));
	bds_unwind1;
	VMR10(V105)}}
	base[0]=base[0];
	return Cnil;
}
/*	local entry for function C2MULTIPLE-VALUE-BIND	*/

static object LI11(V109,V110,V111)

object V109;object V110;object V111;
{	 VMB11 VMS11 VMV11
	bds_check;
goto TTL;
TTL:;
	{object V112;
	register object V113;
	object V114;
	V112= Cnil;
	V113= Cnil;
	bds_bind(VV[33],symbol_value(VV[33]));
	bds_bind(VV[1],symbol_value(VV[1]));
	bds_bind(VV[34],symbol_value(VV[34]));
	bds_bind(VV[35],symbol_value(VV[35]));
	V114= Cnil;
	(void)((*(LnkLI58))((V109),(V110)));
	{register object V115;
	register object V116;
	V115= (V109);
	V116= car((V115));
goto T360;
T360:;
	if(!(endp_prop((V115)))){
	goto T361;}
	goto T356;
goto T361;
T361:;
	{object V117;
	V117= (*(LnkLI69))((V116));
	if(((V117))==Cnil){
	goto T368;}
	{object V118;
	setq(VV[5],number_plus(symbol_value(VV[5]),small_fixnum(1)));
	V118= symbol_value(VV[5]);
	(void)(structure_set((V116),VV[30],1,(V117)));
	(void)(structure_set((V116),VV[30],4,(V118)));
	princ_str("\n	",VV[6]);
	if(((V112))!=Cnil){
	goto T375;}
	princ_char(123,VV[6]);
	V112= Ct;
goto T375;
T375:;
	base[5]= (V116);
	vs_top=(vs_base=base+5)+1;
	(void) (*Lnk70)();
	vs_top=sup;
	goto T365;}
goto T368;
T368:;
	V119= (*(LnkLI54))();
	(void)(structure_set((V116),VV[30],2,/* INLINE-ARGS */V119));}
goto T365;
T365:;
	V115= cdr((V115));
	V116= car((V115));
	goto T360;}
goto T356;
T356:;
	bds_bind(VV[2],VV[3]);
	bds_bind(VV[9],Cnil);
	(void)((*(LnkLI44))((V110)));
	V114= (VV[9]->s.s_dbind);
	bds_unwind1;
	bds_unwind1;
	if(symbol_value(VV[27])==Cnil){
	goto T390;}
	(void)((*(LnkLI59))(Cnil,car((V114))));
goto T390;
T390:;
	bds_bind(VV[34],(VV[34]->s.s_dbind));
	bds_bind(VV[33],(VV[33]->s.s_dbind));
	bds_bind(VV[35],(VV[35]->s.s_dbind));
	{register object V120;
	V120= (V109);
goto T393;
T393:;
	if(!(endp_prop((V120)))){
	goto T394;}
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	goto T391;
goto T394;
T394:;
	setq(VV[36],number_plus(symbol_value(VV[36]),small_fixnum(1)));
	V121= make_cons(symbol_value(VV[36]),Cnil);
	V113= make_cons(/* INLINE-ARGS */V121,(V113));
	princ_str("\n	if(vs_base>=vs_top){",VV[6]);
	(void)((*(LnkLI61))());
	if(type_of(car((V113)))!=t_cons)FEwrong_type_argument(Scons,car((V113)));
	(car((V113)))->c.c_cdr = Ct;
	(void)(car((V113)));
	princ_str("goto T",VV[6]);
	(void)((*(LnkLI46))(car(car((V113)))));
	princ_char(59,VV[6]);
	princ_char(125,VV[6]);
	(void)((*(LnkLI71))(car((V120)),VV[37]));
	if(endp_prop(cdr((V120)))){
	goto T412;}
	princ_str("\n	vs_base++;",VV[6]);
goto T412;
T412:;
	V120= cdr((V120));
	goto T393;}
goto T391;
T391:;
	princ_str("\n	",VV[6]);
	(void)((*(LnkLI61))());
	{object V122;
	setq(VV[36],number_plus(symbol_value(VV[36]),small_fixnum(1)));
	V122= make_cons(symbol_value(VV[36]),Cnil);
	princ_str("\n	",VV[6]);
	if(type_of((V122))!=t_cons)FEwrong_type_argument(Scons,(V122));
	((V122))->c.c_cdr = Ct;
	princ_str("goto T",VV[6]);
	(void)((*(LnkLI46))(car((V122))));
	princ_char(59,VV[6]);
	V113= reverse((V113));
	{register object V123;
	object V124;
	V123= (V109);
	V124= car((V123));
goto T436;
T436:;
	if(!(endp_prop((V123)))){
	goto T437;}
	goto T432;
goto T437;
T437:;
	if((cdr(car((V113))))==Cnil){
	goto T441;}
	princ_str("\ngoto T",VV[6]);
	(void)((*(LnkLI46))(car(car((V113)))));
	princ_char(59,VV[6]);
	princ_str("\nT",VV[6]);
	(void)((*(LnkLI46))(car(car((V113)))));
	princ_str(":;",VV[6]);
goto T441;
T441:;
	{object V125;
	V125= car((V113));
	V113= cdr((V113));}
	(void)((*(LnkLI71))((V124),Cnil));
	V123= cdr((V123));
	V124= car((V123));
	goto T436;}
goto T432;
T432:;
	if((cdr((V122)))==Cnil){
	goto T421;}
	princ_str("\ngoto T",VV[6]);
	(void)((*(LnkLI46))(car((V122))));
	princ_char(59,VV[6]);
	princ_str("\nT",VV[6]);
	(void)((*(LnkLI46))(car((V122))));
	princ_str(":;",VV[6]);}
goto T421;
T421:;
	base[4]= (V111);
	vs_top=(vs_base=base+4)+1;
	(void) (*Lnk72)();
	vs_top=sup;
	if(((V112))==Cnil){
	goto T473;}
	princ_char(125,VV[6]);
	{object V126 = Cnil;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR11(V126)}
goto T473;
T473:;
	{object V127 = Cnil;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	bds_unwind1;
	VMR11(V127)}}
	base[0]=base[0];
	return Cnil;
}
static void LnkT72(){ call_or_link(VV[72],(void **)&Lnk72);} /* C2EXPR */
static object  LnkTLI71(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[71],(void **)&LnkLI71,2,ap);va_end(ap);return V1;} /* C2BIND-LOC */
static void LnkT70(){ call_or_link(VV[70],(void **)&Lnk70);} /* WT-VAR-DECL */
static object  LnkTLI69(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[69],(void **)&LnkLI69,1,ap);va_end(ap);return V1;} /* C2VAR-KIND */
static object  LnkTLI68(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[68],(void **)&LnkLI68,1,ap);va_end(ap);return V1;} /* CHECK-VREF */
static object  LnkTLI67(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[67],(void **)&LnkLI67,2,ap);va_end(ap);return V1;} /* ADD-INFO */
static object  LnkTLI66(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[66],(void **)&LnkLI66,2,ap);va_end(ap);return V1;} /* C1DECL-BODY */
static object  LnkTLI65(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[65],(void **)&LnkLI65,3,ap);va_end(ap);return V1;} /* CHECK-VDECL */
static object  LnkTLI64(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[64],(void **)&LnkLI64,4,ap);va_end(ap);return V1;} /* C1MAKE-VAR */
static object  LnkTLI63(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[63],(void **)&LnkLI63,1,ap);va_end(ap);return V1;} /* C1ADD-GLOBALS */
static void LnkT62(){ call_or_link(VV[62],(void **)&Lnk62);} /* C1BODY */
static object  LnkTLI61(){return call_proc0(VV[61],(void **)&LnkLI61);} /* RESET-TOP */
static object  LnkTLI60(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[60],(void **)&LnkLI60,3,ap);va_end(ap);return V1;} /* SET-VAR */
static object  LnkTLI59(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[59],(void **)&LnkLI59,2,ap);va_end(ap);return V1;} /* RECORD-CALL-INFO */
static object  LnkTLI58(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[58],(void **)&LnkLI58,2,ap);va_end(ap);return V1;} /* MULTIPLE-VALUE-CHECK */
static object  LnkTLI57(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[57],(void **)&LnkLI57,1,ap);va_end(ap);return V1;} /* C1VREF */
static object  LnkTLI56(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_vproc(VV[56],(void **)&LnkLI56,ap);va_end(ap);return V1;} /* CMPERR */
static object  LnkTLI55(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[55],(void **)&LnkLI55,3,ap);va_end(ap);return V1;} /* TOO-MANY-ARGS */
static object  LnkTLI54(){return call_proc0(VV[54],(void **)&LnkLI54);} /* VS-PUSH */
static object  LnkTLI53(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_vproc(VV[53],(void **)&LnkLI53,ap);va_end(ap);return V1;} /* CMPWARN */
static object  LnkTLI52(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[52],(void **)&LnkLI52,1,ap);va_end(ap);return V1;} /* C1EXPR */
static object  LnkTLI51(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[51],(void **)&LnkLI51,1,ap);va_end(ap);return V1;} /* GET-RETURN-TYPE */
static object  LnkTLI50(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_vproc(VV[50],(void **)&LnkLI50,ap);va_end(ap);return V1;} /* UNWIND-EXIT */
static object  LnkTLI49(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[49],(void **)&LnkLI49,2,ap);va_end(ap);return V1;} /* C1EXPR* */
static object  LnkTLI48(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_vproc(VV[48],(void **)&LnkLI48,ap);va_end(ap);return V1;} /* MAKE-INFO */
static object  LnkTLI47(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[47],(void **)&LnkLI47,2,ap);va_end(ap);return V1;} /* C2EXPR-TOP* */
static object  LnkTLI46(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[46],(void **)&LnkLI46,1,ap);va_end(ap);return V1;} /* WT1 */
static object  LnkTLI45(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_vproc(VV[45],(void **)&LnkLI45,ap);va_end(ap);return V1;} /* C2FUNCALL */
static object  LnkTLI44(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[44],(void **)&LnkLI44,1,ap);va_end(ap);return V1;} /* C2EXPR* */
static object  LnkTLI43(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[43],(void **)&LnkLI43,1,ap);va_end(ap);return V1;} /* SAVE-FUNOB */
static object  LnkTLI42(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[42],(void **)&LnkLI42,2,ap);va_end(ap);return V1;} /* C1ARGS */
static void LnkT41(){ call_or_link(VV[41],(void **)&Lnk41);} /* COPY-INFO */
static object  LnkTLI40(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[40],(void **)&LnkLI40,1,ap);va_end(ap);return V1;} /* C1FUNOB */
static object  LnkTLI39(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[39],(void **)&LnkLI39,1,ap);va_end(ap);return V1;} /* C1FUNCALL */
static object  LnkTLI38(va_alist)va_dcl{object V1;va_list ap;va_start(ap);V1=call_proc(VV[38],(void **)&LnkLI38,3,ap);va_end(ap);return V1;} /* TOO-FEW-ARGS */

#ifdef SYSTEM_SPECIAL_INIT
SYSTEM_SPECIAL_INIT
#endif

