#include<stdio.h>
#include <stdlib.h>
void* apply(void* f, void* arg){
	return (**((void* (**)(void*, void*)) f))(f, arg);
}
struct h_cls{
	void* (*call)(void*, void*);
	void *uselessMathLam, *uselessMath, *subtract, *operator_if, *main, *add2, *add;
};
void* h_call(void* genenv, void* main){
	struct h_cls *env = (struct h_cls*) genenv;
	*((void**) env + 5) = main;
	void* _b = (*((void**) env + 1 + 4));
	return _b;
}
void* h_init(void* uselessMathLam, void* uselessMath, void* subtract, void* operator_if, void* add2, void* add){
	struct h_cls* reserved = (struct h_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &h_call;
	*((void**) reserved + 1) = uselessMathLam;
	*((void**) reserved + 2) = uselessMath;
	*((void**) reserved + 3) = subtract;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 6) = add2;
	*((void**) reserved + 7) = add;
	return (void*) reserved;
}
struct g_cls{
	void* (*call)(void*, void*);
	void *uselessMathLam, *uselessMath, *subtract, *operator_if, *add2, *add;
};
void* g_call(void* genenv, void* uselessMathLam){
	struct g_cls *env = (struct g_cls*) genenv;
	*((void**) env + 1) = uselessMathLam;
	void* _e = (*((void**) env + 1 + 1));
	void* _f = ((void*) 1);
	void* _g = apply(_e, _f);
	void* _h = ((void*) 2);
	void* _i = apply(_g, _h);
	void* _d = h_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6));
	void* _c = apply(_d, _i);
	return _c;
}
void* g_init(void* uselessMath, void* subtract, void* operator_if, void* add2, void* add){
	struct g_cls* reserved = (struct g_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &g_call;
	*((void**) reserved + 2) = uselessMath;
	*((void**) reserved + 3) = subtract;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = add2;
	*((void**) reserved + 6) = add;
	return (void*) reserved;
}
struct j_cls{
	void* (*call)(void*, void*);
	void *y, *x, *uselessMath, *subtract, *operator_if, *add2, *add;
};
void* j_call(void* genenv, void* y){
	struct j_cls *env = (struct j_cls*) genenv;
	*((void**) env + 1) = y;
	void* _bb = (*((void**) env + 1 + 1));
	void* _cb = (*((void**) env + 1 + 0));
	void* _db = (void*) ((long long)((long long) _bb + (long long) _cb));
	return _db;
}
void* j_init(void* x, void* uselessMath, void* subtract, void* operator_if, void* add2, void* add){
	struct j_cls* reserved = (struct j_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &j_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = uselessMath;
	*((void**) reserved + 4) = subtract;
	*((void**) reserved + 5) = operator_if;
	*((void**) reserved + 6) = add2;
	*((void**) reserved + 7) = add;
	return (void*) reserved;
}
struct i_cls{
	void* (*call)(void*, void*);
	void *x, *uselessMath, *subtract, *operator_if, *add2, *add;
};
void* i_call(void* genenv, void* x){
	struct i_cls *env = (struct i_cls*) genenv;
	*((void**) env + 1) = x;
	void* _eb = j_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6));
	return _eb;
}
void* i_init(void* uselessMath, void* subtract, void* operator_if, void* add2, void* add){
	struct i_cls* reserved = (struct i_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &i_call;
	*((void**) reserved + 2) = uselessMath;
	*((void**) reserved + 3) = subtract;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = add2;
	*((void**) reserved + 6) = add;
	return (void*) reserved;
}
struct f_cls{
	void* (*call)(void*, void*);
	void *uselessMath, *subtract, *operator_if, *add2, *add;
};
void* f_call(void* genenv, void* uselessMath){
	struct f_cls *env = (struct f_cls*) genenv;
	*((void**) env + 1) = uselessMath;
	void* _fb = i_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _ab = g_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _j = apply(_ab, _fb);
	return _j;
}
void* f_init(void* subtract, void* operator_if, void* add2, void* add){
	struct f_cls* reserved = (struct f_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &f_call;
	*((void**) reserved + 2) = subtract;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = add2;
	*((void**) reserved + 5) = add;
	return (void*) reserved;
}
struct bb_cls{
	void* (*call)(void*, void*);
	void *y, *x, *subtract, *operator_if, *add2, *add;
};
void* bb_call(void* genenv, void* y){
	struct bb_cls *env = (struct bb_cls*) genenv;
	*((void**) env + 1) = y;
	void* _ib = (*((void**) env + 1 + 5));
	void* _jb = (*((void**) env + 1 + 2));
	void* _ac = (*((void**) env + 1 + 1));
	void* _bc = apply(_jb, _ac);
	void* _cc = ((void*) 1);
	void* _dc = apply(_bc, _cc);
	void* _ec = apply(_ib, _dc);
	void* _fc = (*((void**) env + 1 + 2));
	void* _gc = (*((void**) env + 1 + 0));
	void* _hc = apply(_fc, _gc);
	void* _ic = ((void*) 1);
	void* _jc = apply(_hc, _ic);
	void* _ad = apply(_ec, _jc);
	return _ad;
}
void* bb_init(void* x, void* subtract, void* operator_if, void* add2, void* add){
	struct bb_cls* reserved = (struct bb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &bb_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = subtract;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = add2;
	*((void**) reserved + 6) = add;
	return (void*) reserved;
}
struct ab_cls{
	void* (*call)(void*, void*);
	void *x, *subtract, *operator_if, *add2, *add;
};
void* ab_call(void* genenv, void* x){
	struct ab_cls *env = (struct ab_cls*) genenv;
	*((void**) env + 1) = x;
	void* _bd = bb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	return _bd;
}
void* ab_init(void* subtract, void* operator_if, void* add2, void* add){
	struct ab_cls* reserved = (struct ab_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ab_call;
	*((void**) reserved + 2) = subtract;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = add2;
	*((void**) reserved + 5) = add;
	return (void*) reserved;
}
struct e_cls{
	void* (*call)(void*, void*);
	void *subtract, *operator_if, *add2, *add;
};
void* e_call(void* genenv, void* add2){
	struct e_cls *env = (struct e_cls*) genenv;
	*((void**) env + 3) = add2;
	void* _cd = ab_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _hb = f_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _gb = apply(_hb, _cd);
	return _gb;
}
void* e_init(void* subtract, void* operator_if, void* add){
	struct e_cls* reserved = (struct e_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &e_call;
	*((void**) reserved + 1) = subtract;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 4) = add;
	return (void*) reserved;
}
struct cb_cls{
	void* (*call)(void*, void*);
	void *x, *subtract, *operator_if, *add;
};
void* cb_call(void* genenv, void* x){
	struct cb_cls *env = (struct cb_cls*) genenv;
	*((void**) env + 1) = x;
	void* _fd = (*((void**) env + 1 + 3));
	void* _gd = ((void*) 2);
	void* _hd = apply(_fd, _gd);
	void* _id = (*((void**) env + 1 + 0));
	void* _jd = apply(_hd, _id);
	return _jd;
}
void* cb_init(void* subtract, void* operator_if, void* add){
	struct cb_cls* reserved = (struct cb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &cb_call;
	*((void**) reserved + 2) = subtract;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = add;
	return (void*) reserved;
}
struct d_cls{
	void* (*call)(void*, void*);
	void *subtract, *operator_if, *add;
};
void* d_call(void* genenv, void* subtract){
	struct d_cls *env = (struct d_cls*) genenv;
	*((void**) env + 1) = subtract;
	void* _ae = cb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _ed = e_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _dd = apply(_ed, _ae);
	return _dd;
}
void* d_init(void* operator_if, void* add){
	struct d_cls* reserved = (struct d_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &d_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = add;
	return (void*) reserved;
}
struct eb_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *add;
};
void* eb_call(void* genenv, void* y){
	struct eb_cls *env = (struct eb_cls*) genenv;
	*((void**) env + 1) = y;
	void* _de = (*((void**) env + 1 + 1));
	void* _ee = (*((void**) env + 1 + 0));
	void* _fe = (void*) ((long long)((long long) _de - (long long) _ee));
	return _fe;
}
void* eb_init(void* x, void* operator_if, void* add){
	struct eb_cls* reserved = (struct eb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &eb_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = add;
	return (void*) reserved;
}
struct db_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *add;
};
void* db_call(void* genenv, void* x){
	struct db_cls *env = (struct db_cls*) genenv;
	*((void**) env + 1) = x;
	void* _ge = eb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	return _ge;
}
void* db_init(void* operator_if, void* add){
	struct db_cls* reserved = (struct db_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &db_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = add;
	return (void*) reserved;
}
struct c_cls{
	void* (*call)(void*, void*);
	void *operator_if, *add;
};
void* c_call(void* genenv, void* add){
	struct c_cls *env = (struct c_cls*) genenv;
	*((void**) env + 2) = add;
	void* _he = db_init(*((void**) env + 1), *((void**) env + 2));
	void* _ce = d_init(*((void**) env + 1), *((void**) env + 2));
	void* _be = apply(_ce, _he);
	return _be;
}
void* c_init(void* operator_if){
	struct c_cls* reserved = (struct c_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &c_call;
	*((void**) reserved + 1) = operator_if;
	return (void*) reserved;
}
struct gb_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if;
};
void* gb_call(void* genenv, void* y){
	struct gb_cls *env = (struct gb_cls*) genenv;
	*((void**) env + 1) = y;
	void* _af = (*((void**) env + 1 + 1));
	void* _bf = (*((void**) env + 1 + 0));
	void* _cf = (void*) ((long long)((long long) _af + (long long) _bf));
	return _cf;
}
void* gb_init(void* x, void* operator_if){
	struct gb_cls* reserved = (struct gb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &gb_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	return (void*) reserved;
}
struct fb_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if;
};
void* fb_call(void* genenv, void* x){
	struct fb_cls *env = (struct fb_cls*) genenv;
	*((void**) env + 1) = x;
	void* _df = gb_init(*((void**) env + 1), *((void**) env + 2));
	return _df;
}
void* fb_init(void* operator_if){
	struct fb_cls* reserved = (struct fb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &fb_call;
	*((void**) reserved + 2) = operator_if;
	return (void*) reserved;
}
struct b_cls{
	void* (*call)(void*, void*);
	void *operator_if;
};
void* b_call(void* genenv, void* operator_if){
	struct b_cls *env = (struct b_cls*) genenv;
	*((void**) env + 1) = operator_if;
	void* _ef = fb_init(*((void**) env + 1));
	void* _je = c_init(*((void**) env + 1));
	void* _ie = apply(_je, _ef);
	return _ie;
}
void* b_init(){
	struct b_cls* reserved = (struct b_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &b_call;
	return (void*) reserved;
}
struct jb_cls{
	void* (*call)(void*, void*);
	void *t, *e, *c;
};
void* jb_call(void* genenv, void* e){
	struct jb_cls *env = (struct jb_cls*) genenv;
	*((void**) env + 2) = e;
	void* _hf = (*((void**) env + 1 + 2));
	void* _if = (*((void**) env + 1 + 0));
	void* _jf = (*((void**) env + 1 + 1));
	void* _ag;
	if(_hf)
		_ag = apply(_if, NULL);
	else
		_ag = apply(_jf, NULL);
	return _ag;
}
void* jb_init(void* t, void* c){
	struct jb_cls* reserved = (struct jb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &jb_call;
	*((void**) reserved + 1) = t;
	*((void**) reserved + 3) = c;
	return (void*) reserved;
}
struct ib_cls{
	void* (*call)(void*, void*);
	void *t, *c;
};
void* ib_call(void* genenv, void* t){
	struct ib_cls *env = (struct ib_cls*) genenv;
	*((void**) env + 1) = t;
	void* _bg = jb_init(*((void**) env + 1), *((void**) env + 2));
	return _bg;
}
void* ib_init(void* c){
	struct ib_cls* reserved = (struct ib_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ib_call;
	*((void**) reserved + 2) = c;
	return (void*) reserved;
}
struct hb_cls{
	void* (*call)(void*, void*);
	void *c;
};
void* hb_call(void* genenv, void* c){
	struct hb_cls *env = (struct hb_cls*) genenv;
	*((void**) env + 1) = c;
	void* _cg = ib_init(*((void**) env + 1));
	return _cg;
}
void* hb_init(){
	struct hb_cls* reserved = (struct hb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &hb_call;
	return (void*) reserved;
}

int main(){
	void* _dg = hb_init();
	void* _gf = b_init();
	void* _ff = apply(_gf, _dg);
	printf("%lld\n", ((long long)_ff));
	return 0;
}
/*; ModuleID = 'Orlang'
source_filename = "Orlang"

%struct.b_cls = type { i8* (i8*, i8*)*, i8* }
%struct.c_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.d_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.e_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.f_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.g_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.h_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.i_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.j_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.ab_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.bb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.cb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.db_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.eb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.fb_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.gb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.hb_cls = type { i8* (i8*, i8*)*, i8* }
%struct.ib_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.jb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }

define i8* @apply(i8* %f, i8* %arg) {
entry:
  %f1 = alloca i8*, align 8
  store i8* %f, i8** %f1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %f_load = load i8*, i8** %f1, align 8
  %f_cast = bitcast i8* %f_load to i8* (i8*, i8*)**
  %f_fptr = load i8* (i8*, i8*)*, i8* (i8*, i8*)** %f_cast, align 8
  %arg1 = load i8*, i8** %f1, align 8
  %arg23 = load i8*, i8** %arg2, align 8
  %retval = call i8* %f_fptr(i8* %arg1, i8* %arg23)
  ret i8* %retval
}

define i8* @b_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.b_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.b_cls*
  store %struct.b_cls* %struct_cast, %struct.b_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.b_cls*, %struct.b_cls** %env, align 8
  %struct_cast4 = bitcast %struct.b_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @c_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.c_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.c_cls*
  store %struct.c_cls* %struct_cast, %struct.c_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.c_cls*, %struct.c_cls** %env, align 8
  %struct_cast4 = bitcast %struct.c_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @d_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.d_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.d_cls*
  store %struct.d_cls* %struct_cast, %struct.d_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.d_cls*, %struct.d_cls** %env, align 8
  %struct_cast4 = bitcast %struct.d_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @e_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.e_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.e_cls*
  store %struct.e_cls* %struct_cast, %struct.e_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.e_cls*, %struct.e_cls** %env, align 8
  %struct_cast4 = bitcast %struct.e_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @f_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.f_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.f_cls*
  store %struct.f_cls* %struct_cast, %struct.f_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.f_cls*, %struct.f_cls** %env, align 8
  %struct_cast4 = bitcast %struct.f_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @g_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.g_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.g_cls*
  store %struct.g_cls* %struct_cast, %struct.g_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.g_cls*, %struct.g_cls** %env, align 8
  %struct_cast4 = bitcast %struct.g_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @h_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.h_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.h_cls*
  store %struct.h_cls* %struct_cast, %struct.h_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.h_cls*, %struct.h_cls** %env, align 8
  %struct_cast4 = bitcast %struct.h_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 5
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @h_init(i8* %uselessMathLam, i8* %uselessMath, i8* %subtract, i8* %operator_if, i8* %add2, i8* %add) {
entry:
  %uselessMathLam1 = alloca i8*, align 8
  store i8* %uselessMathLam, i8** %uselessMathLam1, align 8
  %uselessMath2 = alloca i8*, align 8
  store i8* %uselessMath, i8** %uselessMath2, align 8
  %subtract3 = alloca i8*, align 8
  store i8* %subtract, i8** %subtract3, align 8
  %operator_if4 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if4, align 8
  %add25 = alloca i8*, align 8
  store i8* %add2, i8** %add25, align 8
  %add6 = alloca i8*, align 8
  store i8* %add, i8** %add6, align 8
  %reserved = alloca %struct.h_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.h_cls* getelementptr (%struct.h_cls, %struct.h_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.h_cls*
  store %struct.h_cls* %space, %struct.h_cls** %reserved, align 8
  %struct_load = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast = bitcast %struct.h_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @h_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %uselessMathLam1, align 8
  %struct_load7 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.h_cls* %struct_load7 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast8, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval9 = load i8*, i8** %uselessMath2, align 8
  %struct_load10 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast11 = bitcast %struct.h_cls* %struct_load10 to i8**
  %elem_ptr12 = getelementptr inbounds i8*, i8** %struct_cast11, i64 2
  store i8* %argval9, i8** %elem_ptr12, align 8
  %argval13 = load i8*, i8** %subtract3, align 8
  %struct_load14 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.h_cls* %struct_load14 to i8**
  %elem_ptr16 = getelementptr inbounds i8*, i8** %struct_cast15, i64 3
  store i8* %argval13, i8** %elem_ptr16, align 8
  %argval17 = load i8*, i8** %operator_if4, align 8
  %struct_load18 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast19 = bitcast %struct.h_cls* %struct_load18 to i8**
  %elem_ptr20 = getelementptr inbounds i8*, i8** %struct_cast19, i64 4
  store i8* %argval17, i8** %elem_ptr20, align 8
  %argval21 = load i8*, i8** %add25, align 8
  %struct_load22 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast23 = bitcast %struct.h_cls* %struct_load22 to i8**
  %elem_ptr24 = getelementptr inbounds i8*, i8** %struct_cast23, i64 6
  store i8* %argval21, i8** %elem_ptr24, align 8
  %argval25 = load i8*, i8** %add6, align 8
  %struct_load26 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast27 = bitcast %struct.h_cls* %struct_load26 to i8**
  %elem_ptr28 = getelementptr inbounds i8*, i8** %struct_cast27, i64 7
  store i8* %argval25, i8** %elem_ptr28, align 8
  %struct_load29 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast30 = bitcast %struct.h_cls* %struct_load29 to i8*
  ret i8* %struct_cast30
}

declare noalias i8* @malloc(i32)

define i8* @g_init(i8* %uselessMath, i8* %subtract, i8* %operator_if, i8* %add2, i8* %add) {
entry:
  %uselessMath1 = alloca i8*, align 8
  store i8* %uselessMath, i8** %uselessMath1, align 8
  %subtract2 = alloca i8*, align 8
  store i8* %subtract, i8** %subtract2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %add24 = alloca i8*, align 8
  store i8* %add2, i8** %add24, align 8
  %add5 = alloca i8*, align 8
  store i8* %add, i8** %add5, align 8
  %reserved = alloca %struct.g_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.g_cls* getelementptr (%struct.g_cls, %struct.g_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.g_cls*
  store %struct.g_cls* %space, %struct.g_cls** %reserved, align 8
  %struct_load = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast = bitcast %struct.g_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @g_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %uselessMath1, align 8
  %struct_load6 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.g_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %subtract2, align 8
  %struct_load9 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.g_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 3
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %operator_if3, align 8
  %struct_load13 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.g_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %add24, align 8
  %struct_load17 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.g_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %add5, align 8
  %struct_load21 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.g_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.g_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @i_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.i_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.i_cls*
  store %struct.i_cls* %struct_cast, %struct.i_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.i_cls*, %struct.i_cls** %env, align 8
  %struct_cast4 = bitcast %struct.i_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @j_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.j_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.j_cls*
  store %struct.j_cls* %struct_cast, %struct.j_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.j_cls*, %struct.j_cls** %env, align 8
  %struct_cast4 = bitcast %struct.j_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @j_init(i8* %x, i8* %uselessMath, i8* %subtract, i8* %operator_if, i8* %add2, i8* %add) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %uselessMath2 = alloca i8*, align 8
  store i8* %uselessMath, i8** %uselessMath2, align 8
  %subtract3 = alloca i8*, align 8
  store i8* %subtract, i8** %subtract3, align 8
  %operator_if4 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if4, align 8
  %add25 = alloca i8*, align 8
  store i8* %add2, i8** %add25, align 8
  %add6 = alloca i8*, align 8
  store i8* %add, i8** %add6, align 8
  %reserved = alloca %struct.j_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.j_cls* getelementptr (%struct.j_cls, %struct.j_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.j_cls*
  store %struct.j_cls* %space, %struct.j_cls** %reserved, align 8
  %struct_load = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast = bitcast %struct.j_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @j_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load7 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.j_cls* %struct_load7 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast8, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval9 = load i8*, i8** %uselessMath2, align 8
  %struct_load10 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast11 = bitcast %struct.j_cls* %struct_load10 to i8**
  %elem_ptr12 = getelementptr inbounds i8*, i8** %struct_cast11, i64 3
  store i8* %argval9, i8** %elem_ptr12, align 8
  %argval13 = load i8*, i8** %subtract3, align 8
  %struct_load14 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.j_cls* %struct_load14 to i8**
  %elem_ptr16 = getelementptr inbounds i8*, i8** %struct_cast15, i64 4
  store i8* %argval13, i8** %elem_ptr16, align 8
  %argval17 = load i8*, i8** %operator_if4, align 8
  %struct_load18 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast19 = bitcast %struct.j_cls* %struct_load18 to i8**
  %elem_ptr20 = getelementptr inbounds i8*, i8** %struct_cast19, i64 5
  store i8* %argval17, i8** %elem_ptr20, align 8
  %argval21 = load i8*, i8** %add25, align 8
  %struct_load22 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast23 = bitcast %struct.j_cls* %struct_load22 to i8**
  %elem_ptr24 = getelementptr inbounds i8*, i8** %struct_cast23, i64 6
  store i8* %argval21, i8** %elem_ptr24, align 8
  %argval25 = load i8*, i8** %add6, align 8
  %struct_load26 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast27 = bitcast %struct.j_cls* %struct_load26 to i8**
  %elem_ptr28 = getelementptr inbounds i8*, i8** %struct_cast27, i64 7
  store i8* %argval25, i8** %elem_ptr28, align 8
  %struct_load29 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast30 = bitcast %struct.j_cls* %struct_load29 to i8*
  ret i8* %struct_cast30
}

define i8* @i_init(i8* %uselessMath, i8* %subtract, i8* %operator_if, i8* %add2, i8* %add) {
entry:
  %uselessMath1 = alloca i8*, align 8
  store i8* %uselessMath, i8** %uselessMath1, align 8
  %subtract2 = alloca i8*, align 8
  store i8* %subtract, i8** %subtract2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %add24 = alloca i8*, align 8
  store i8* %add2, i8** %add24, align 8
  %add5 = alloca i8*, align 8
  store i8* %add, i8** %add5, align 8
  %reserved = alloca %struct.i_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.i_cls* getelementptr (%struct.i_cls, %struct.i_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.i_cls*
  store %struct.i_cls* %space, %struct.i_cls** %reserved, align 8
  %struct_load = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast = bitcast %struct.i_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @i_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %uselessMath1, align 8
  %struct_load6 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.i_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %subtract2, align 8
  %struct_load9 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.i_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 3
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %operator_if3, align 8
  %struct_load13 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.i_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %add24, align 8
  %struct_load17 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.i_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %add5, align 8
  %struct_load21 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.i_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.i_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @f_init(i8* %subtract, i8* %operator_if, i8* %add2, i8* %add) {
entry:
  %subtract1 = alloca i8*, align 8
  store i8* %subtract, i8** %subtract1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %add23 = alloca i8*, align 8
  store i8* %add2, i8** %add23, align 8
  %add4 = alloca i8*, align 8
  store i8* %add, i8** %add4, align 8
  %reserved = alloca %struct.f_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.f_cls* getelementptr (%struct.f_cls, %struct.f_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.f_cls*
  store %struct.f_cls* %space, %struct.f_cls** %reserved, align 8
  %struct_load = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast = bitcast %struct.f_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @f_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %subtract1, align 8
  %struct_load5 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.f_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %operator_if2, align 8
  %struct_load8 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.f_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %add23, align 8
  %struct_load12 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.f_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %add4, align 8
  %struct_load16 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.f_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.f_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @ab_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.ab_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.ab_cls*
  store %struct.ab_cls* %struct_cast, %struct.ab_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.ab_cls*, %struct.ab_cls** %env, align 8
  %struct_cast4 = bitcast %struct.ab_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @bb_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.bb_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.bb_cls*
  store %struct.bb_cls* %struct_cast, %struct.bb_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.bb_cls*, %struct.bb_cls** %env, align 8
  %struct_cast4 = bitcast %struct.bb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @bb_init(i8* %x, i8* %subtract, i8* %operator_if, i8* %add2, i8* %add) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %subtract2 = alloca i8*, align 8
  store i8* %subtract, i8** %subtract2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %add24 = alloca i8*, align 8
  store i8* %add2, i8** %add24, align 8
  %add5 = alloca i8*, align 8
  store i8* %add, i8** %add5, align 8
  %reserved = alloca %struct.bb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.bb_cls* getelementptr (%struct.bb_cls, %struct.bb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.bb_cls*
  store %struct.bb_cls* %space, %struct.bb_cls** %reserved, align 8
  %struct_load = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.bb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @bb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.bb_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %subtract2, align 8
  %struct_load9 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.bb_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 3
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %operator_if3, align 8
  %struct_load13 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.bb_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %add24, align 8
  %struct_load17 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.bb_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %add5, align 8
  %struct_load21 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.bb_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.bb_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @ab_init(i8* %subtract, i8* %operator_if, i8* %add2, i8* %add) {
entry:
  %subtract1 = alloca i8*, align 8
  store i8* %subtract, i8** %subtract1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %add23 = alloca i8*, align 8
  store i8* %add2, i8** %add23, align 8
  %add4 = alloca i8*, align 8
  store i8* %add, i8** %add4, align 8
  %reserved = alloca %struct.ab_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ab_cls* getelementptr (%struct.ab_cls, %struct.ab_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ab_cls*
  store %struct.ab_cls* %space, %struct.ab_cls** %reserved, align 8
  %struct_load = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ab_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ab_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %subtract1, align 8
  %struct_load5 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.ab_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %operator_if2, align 8
  %struct_load8 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.ab_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %add23, align 8
  %struct_load12 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.ab_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %add4, align 8
  %struct_load16 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.ab_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.ab_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @e_init(i8* %subtract, i8* %operator_if, i8* %add) {
entry:
  %subtract1 = alloca i8*, align 8
  store i8* %subtract, i8** %subtract1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %add3 = alloca i8*, align 8
  store i8* %add, i8** %add3, align 8
  %reserved = alloca %struct.e_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.e_cls* getelementptr (%struct.e_cls, %struct.e_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.e_cls*
  store %struct.e_cls* %space, %struct.e_cls** %reserved, align 8
  %struct_load = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast = bitcast %struct.e_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @e_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %subtract1, align 8
  %struct_load4 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.e_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %operator_if2, align 8
  %struct_load7 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.e_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 2
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %add3, align 8
  %struct_load11 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.e_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.e_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @cb_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.cb_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.cb_cls*
  store %struct.cb_cls* %struct_cast, %struct.cb_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.cb_cls*, %struct.cb_cls** %env, align 8
  %struct_cast4 = bitcast %struct.cb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @cb_init(i8* %subtract, i8* %operator_if, i8* %add) {
entry:
  %subtract1 = alloca i8*, align 8
  store i8* %subtract, i8** %subtract1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %add3 = alloca i8*, align 8
  store i8* %add, i8** %add3, align 8
  %reserved = alloca %struct.cb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.cb_cls* getelementptr (%struct.cb_cls, %struct.cb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.cb_cls*
  store %struct.cb_cls* %space, %struct.cb_cls** %reserved, align 8
  %struct_load = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.cb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @cb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %subtract1, align 8
  %struct_load4 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.cb_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %operator_if2, align 8
  %struct_load7 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.cb_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %add3, align 8
  %struct_load11 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.cb_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.cb_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @d_init(i8* %operator_if, i8* %add) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %add2 = alloca i8*, align 8
  store i8* %add, i8** %add2, align 8
  %reserved = alloca %struct.d_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.d_cls* getelementptr (%struct.d_cls, %struct.d_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.d_cls*
  store %struct.d_cls* %space, %struct.d_cls** %reserved, align 8
  %struct_load = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast = bitcast %struct.d_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @d_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load3 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.d_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %add2, align 8
  %struct_load6 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.d_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.d_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @db_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.db_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.db_cls*
  store %struct.db_cls* %struct_cast, %struct.db_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.db_cls*, %struct.db_cls** %env, align 8
  %struct_cast4 = bitcast %struct.db_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @eb_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.eb_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.eb_cls*
  store %struct.eb_cls* %struct_cast, %struct.eb_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.eb_cls*, %struct.eb_cls** %env, align 8
  %struct_cast4 = bitcast %struct.eb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @eb_init(i8* %x, i8* %operator_if, i8* %add) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %add3 = alloca i8*, align 8
  store i8* %add, i8** %add3, align 8
  %reserved = alloca %struct.eb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.eb_cls* getelementptr (%struct.eb_cls, %struct.eb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.eb_cls*
  store %struct.eb_cls* %space, %struct.eb_cls** %reserved, align 8
  %struct_load = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.eb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @eb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load4 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.eb_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %operator_if2, align 8
  %struct_load7 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.eb_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %add3, align 8
  %struct_load11 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.eb_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.eb_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @db_init(i8* %operator_if, i8* %add) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %add2 = alloca i8*, align 8
  store i8* %add, i8** %add2, align 8
  %reserved = alloca %struct.db_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.db_cls* getelementptr (%struct.db_cls, %struct.db_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.db_cls*
  store %struct.db_cls* %space, %struct.db_cls** %reserved, align 8
  %struct_load = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast = bitcast %struct.db_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @db_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load3 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.db_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %add2, align 8
  %struct_load6 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.db_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.db_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @c_init(i8* %operator_if) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %reserved = alloca %struct.c_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.c_cls* getelementptr (%struct.c_cls, %struct.c_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.c_cls*
  store %struct.c_cls* %space, %struct.c_cls** %reserved, align 8
  %struct_load = load %struct.c_cls*, %struct.c_cls** %reserved, align 8
  %struct_cast = bitcast %struct.c_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @c_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load2 = load %struct.c_cls*, %struct.c_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.c_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.c_cls*, %struct.c_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.c_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
}

define i8* @fb_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.fb_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.fb_cls*
  store %struct.fb_cls* %struct_cast, %struct.fb_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.fb_cls*, %struct.fb_cls** %env, align 8
  %struct_cast4 = bitcast %struct.fb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @gb_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.gb_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.gb_cls*
  store %struct.gb_cls* %struct_cast, %struct.gb_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.gb_cls*, %struct.gb_cls** %env, align 8
  %struct_cast4 = bitcast %struct.gb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @gb_init(i8* %x, i8* %operator_if) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %reserved = alloca %struct.gb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.gb_cls* getelementptr (%struct.gb_cls, %struct.gb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.gb_cls*
  store %struct.gb_cls* %space, %struct.gb_cls** %reserved, align 8
  %struct_load = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.gb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @gb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load3 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.gb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %operator_if2, align 8
  %struct_load6 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.gb_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.gb_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @fb_init(i8* %operator_if) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %reserved = alloca %struct.fb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.fb_cls* getelementptr (%struct.fb_cls, %struct.fb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.fb_cls*
  store %struct.fb_cls* %space, %struct.fb_cls** %reserved, align 8
  %struct_load = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.fb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @fb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load2 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.fb_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.fb_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
}

define i8* @b_init() {
entry:
  %reserved = alloca %struct.b_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.b_cls* getelementptr (%struct.b_cls, %struct.b_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.b_cls*
  store %struct.b_cls* %space, %struct.b_cls** %reserved, align 8
  %struct_load = load %struct.b_cls*, %struct.b_cls** %reserved, align 8
  %struct_cast = bitcast %struct.b_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @b_call, i8* (i8*, i8*)** %struct_cast, align 8
  %struct_load1 = load %struct.b_cls*, %struct.b_cls** %reserved, align 8
  %struct_cast2 = bitcast %struct.b_cls* %struct_load1 to i8*
  ret i8* %struct_cast2
}

define i8* @hb_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.hb_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.hb_cls*
  store %struct.hb_cls* %struct_cast, %struct.hb_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.hb_cls*, %struct.hb_cls** %env, align 8
  %struct_cast4 = bitcast %struct.hb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @ib_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.ib_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.ib_cls*
  store %struct.ib_cls* %struct_cast, %struct.ib_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.ib_cls*, %struct.ib_cls** %env, align 8
  %struct_cast4 = bitcast %struct.ib_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @jb_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.jb_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.jb_cls*
  store %struct.jb_cls* %struct_cast, %struct.jb_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.jb_cls*, %struct.jb_cls** %env, align 8
  %struct_cast4 = bitcast %struct.jb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @jb_init(i8* %t, i8* %c) {
entry:
  %t1 = alloca i8*, align 8
  store i8* %t, i8** %t1, align 8
  %c2 = alloca i8*, align 8
  store i8* %c, i8** %c2, align 8
  %reserved = alloca %struct.jb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.jb_cls* getelementptr (%struct.jb_cls, %struct.jb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.jb_cls*
  store %struct.jb_cls* %space, %struct.jb_cls** %reserved, align 8
  %struct_load = load %struct.jb_cls*, %struct.jb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.jb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @jb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %t1, align 8
  %struct_load3 = load %struct.jb_cls*, %struct.jb_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.jb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %c2, align 8
  %struct_load6 = load %struct.jb_cls*, %struct.jb_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.jb_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.jb_cls*, %struct.jb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.jb_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @ib_init(i8* %c) {
entry:
  %c1 = alloca i8*, align 8
  store i8* %c, i8** %c1, align 8
  %reserved = alloca %struct.ib_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ib_cls* getelementptr (%struct.ib_cls, %struct.ib_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ib_cls*
  store %struct.ib_cls* %space, %struct.ib_cls** %reserved, align 8
  %struct_load = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ib_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ib_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %c1, align 8
  %struct_load2 = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.ib_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.ib_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
}

define i8* @hb_init() {
entry:
  %reserved = alloca %struct.hb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.hb_cls* getelementptr (%struct.hb_cls, %struct.hb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.hb_cls*
  store %struct.hb_cls* %space, %struct.hb_cls** %reserved, align 8
  %struct_load = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.hb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @hb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %struct_load1 = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast2 = bitcast %struct.hb_cls* %struct_load1 to i8*
  ret i8* %struct_cast2
}
*/