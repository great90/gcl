
#include "cmpinclude.h"
#include "pcl_gazonk6.h"
void init_pcl_gazonk6(){do_init(VV);}
/*	function definition for CMP-ANON	*/

static void L1()
{register object *base=vs_base;
	register object *sup=base+VM1; VC1
	vs_check;
	check_arg(3);
	base[0]=MMcons(base[0],Cnil);
	base[1]=MMcons(base[1],base[0]);
	base[2]=MMcons(base[2],base[1]);
	vs_top=sup;
	base[3]= 
	make_cclosure_new(LC2,Cnil,base[2],Cdata);
	vs_top=(vs_base=base+3)+1;
	return;
}
/*	local function CLOSURE	*/

static void LC2(base0)
register object *base0;
{	register object *base=vs_base;
	register object *sup=base+VM2; VC2
	vs_check;
	{register object V1;
	check_arg(1);
	V1=(base[0]);
	vs_top=sup;
	{register object V2;
	V2= (base0[2]->c.c_car);
	base[1]= (V2);
	base[2]= VV[0];
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk12)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T3;}
	base[1]= STREF(object,(V2),0);
	base[2]= STREF(object,(V2),4);
	base[3]= STREF(object,(V2),8);
	base[4]= (V1);
	vs_top=(vs_base=base+2)+3;
	{object _funobj = base[1];if(type_of(_funobj)==t_cclosure && (_funobj->cc.cc_turbo))
                   (*(_funobj->cc.cc_self))(_funobj->cc.cc_turbo);
               else if (type_of(_funobj)==t_cfun) (*(_funobj->cc.cc_self))();
               else super_funcall_no_event(_funobj);}
	return;
	goto T3;
T3:;
	if(!(type_of((V2))==t_fixnum)){
	goto T12;}
	{object V3;
	object V4;
	if(type_of(V1)==t_structure){
	goto T18;}
	goto T16;
	goto T18;
T18:;
	if(!(((V1)->str.str_def)==(VV[1]))){
	goto T16;}
	V3= STREF(object,(V1),4);
	goto T14;
	goto T16;
T16:;{object V6;
	V6= (VV[3]->s.s_dbind);
	base[3]= small_fixnum(14);
	base[4]= (V1);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk13)();
	vs_top=sup;
	V7= vs_base[0];
	if(!((V6)==(CMPcar(V7)))){
	goto T21;}}
	V3= CMPcar(((V1))->cc.cc_turbo[12]);
	goto T14;
	goto T21;
T21:;
	V3= Cnil;
	goto T14;
T14:;
	if(((V3))==Cnil){
	goto T28;}
	V4= ((V3))->v.v_self[fix((V2))];
	goto T26;
	goto T28;
T28:;
	V4= Cnil;
	goto T26;
T26:;
	if(!(((V4))==(VV[4]))){
	goto T31;}
	base[3]= (V1);
	base[4]= (V2);
	vs_top=(vs_base=base+3)+2;
	(void) (*Lnk15)();
	return;
	goto T31;
T31:;
	base[3]= (V4);
	vs_top=(vs_base=base+3)+1;
	return;}
	goto T12;
T12:;
	{register object V9;
	V9= V2;
	base[1]= (V9);
	base[2]= VV[5];
	vs_top=(vs_base=base+1)+2;
	(void) (*Lnk12)();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T36;}
	{object V10;
	object V11;
	register object V12;
	V10= STREF(object,(V2),0);
	V11= make_cons((V1),Cnil);
	V12= STREF(object,(V2),4);
	if(((V12))==Cnil){
	goto T47;}
	if(!((CMPcdr((V12)))==Cnil)){
	goto T44;}
	goto T45;
	goto T47;
T47:;
	goto T44;
	goto T45;
T45:;
	base[1]= (V11);
	base[2]= CMPcar((V12));
	vs_top=(vs_base=base+1)+2;
	{object _funobj = (V10);if(type_of(_funobj)==t_cclosure && (_funobj->cc.cc_turbo))
                   (*(_funobj->cc.cc_self))(_funobj->cc.cc_turbo);
               else if (type_of(_funobj)==t_cfun) (*(_funobj->cc.cc_self))();
               else super_funcall_no_event(_funobj);}
	return;
	goto T44;
T44:;
	base[1]= (V10);
	base[2]= (V11);
	{object V13;
	V13= (V12);
	 vs_top=base+3;
	 while(V13!=Cnil)
	 {vs_push((V13)->c.c_car);V13=(V13)->c.c_cdr;}
	vs_base=base+2;}
	{object _funobj = base[1];if(type_of(_funobj)==t_cclosure && (_funobj->cc.cc_turbo))
                   (*(_funobj->cc.cc_self))(_funobj->cc.cc_turbo);
               else if (type_of(_funobj)==t_cfun) (*(_funobj->cc.cc_self))();
               else super_funcall_no_event(_funobj);}
	return;}
	goto T36;
T36:;
	base[1]= (V9);
	vs_top=(vs_base=base+1)+1;
	Lfunctionp();
	vs_top=sup;
	if((vs_base[0])==Cnil){
	goto T55;}
	base[1]= (V1);
	vs_top=(vs_base=base+1)+1;
	{object _funobj = (V2);if(type_of(_funobj)==t_cclosure && (_funobj->cc.cc_turbo))
                   (*(_funobj->cc.cc_self))(_funobj->cc.cc_turbo);
               else if (type_of(_funobj)==t_cfun) (*(_funobj->cc.cc_self))();
               else super_funcall_no_event(_funobj);}
	return;
	goto T55;
T55:;
	base[1]= VV[6];
	base[2]= VV[7];
	base[3]= VV[8];
	base[4]= VV[9];
	base[5]= V2;
	base[6]= VV[10];
	base[7]= (base0[1]->c.c_car);
	base[8]= VV[11];
	base[9]= (base0[0]->c.c_car);
	vs_top=(vs_base=base+1)+9;
	(void) (*Lnk16)();
	return;}}
	}
}
static void LnkT16(){ call_or_link(VV[16],(void **)(void *)&Lnk16);} /* ERROR */
static void LnkT15(){ call_or_link(VV[15],(void **)(void *)&Lnk15);} /* SLOT-UNBOUND-INTERNAL */
static object  LnkTLI14(object first,...){object V1;va_list ap;va_start(ap,first);V1=call_proc_new(VV[14],(void **)(void *)&LnkLI14,4098,first,ap);va_end(ap);return V1;} /* %CCLOSURE-ENV-NTHCDR */
static void LnkT13(){ call_or_link(VV[13],(void **)(void *)&Lnk13);} /* CCLOSURE-ENV-NTHCDR */
static void LnkT12(){ call_or_link(VV[12],(void **)(void *)&Lnk12);} /* STRUCTURE-SUBTYPE-P */

#ifdef SYSTEM_SPECIAL_INIT
SYSTEM_SPECIAL_INIT
#endif

