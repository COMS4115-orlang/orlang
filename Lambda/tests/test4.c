#include<stdio.h>
#include <stdlib.h>
void* apply(void* f, void* arg){
	return (**((void* (**)(void*, void*)) f))(f, arg);
}
struct e_cls{
	void* (*call)(void*, void*);
	void *res, *operator_if, *n, *fac;
};
void* e_call(void* genenv, void* res){
	struct e_cls *env = (struct e_cls*) genenv;
	*((void**) env + 1) = res;
	void* _g = ((void*) 0);
	return _g;
}
void* e_init(void* operator_if, void* n, void* fac){
	struct e_cls* reserved = (struct e_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &e_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = n;
	*((void**) reserved + 4) = fac;
	return (void*) reserved;
}
struct g_cls{
	void* (*call)(void*, void*);
	void *res, *operator_if, *n, *fac;
};
void* g_call(void* genenv, void* res){
	struct g_cls *env = (struct g_cls*) genenv;
	*((void**) env + 1) = res;
	void* _eb = ((void*) 1);
	return _eb;
}
void* g_init(void* operator_if, void* n, void* fac){
	struct g_cls* reserved = (struct g_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &g_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = n;
	*((void**) reserved + 4) = fac;
	return (void*) reserved;
}
struct h_cls{
	void* (*call)(void*, void*);
	void *res, *operator_if, *n, *fac;
};
void* h_call(void* genenv, void* res){
	struct h_cls *env = (struct h_cls*) genenv;
	*((void**) env + 1) = res;
	void* _hb = (*((void**) env + 1 + 3));
	void* _ib = (*((void**) env + 1 + 2));
	void* _jb = ((void*) 1);
	void* _ac = (void*) ((long long)((long long) _ib - (long long) _jb));
	void* _bc = apply(_hb, _ac);
	void* _cc = (*((void**) env + 1 + 3));
	void* _dc = (*((void**) env + 1 + 2));
	void* _ec = ((void*) 2);
	void* _fc = (void*) ((long long)((long long) _dc - (long long) _ec));
	void* _gc = apply(_cc, _fc);
	void* _hc = (void*) ((long long)((long long) _bc + (long long) _gc));
	return _hc;
}
void* h_init(void* operator_if, void* n, void* fac){
	struct h_cls* reserved = (struct h_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &h_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = n;
	*((void**) reserved + 4) = fac;
	return (void*) reserved;
}
struct f_cls{
	void* (*call)(void*, void*);
	void *res, *operator_if, *n, *fac;
};
void* f_call(void* genenv, void* res){
	struct f_cls *env = (struct f_cls*) genenv;
	*((void**) env + 1) = res;
	void* _j = (*((void**) env + 1 + 1));
	void* _ab = (*((void**) env + 1 + 2));
	void* _bb = ((void*) 1);
	void* _cb = (void*) ((long long)((long long) _ab == (long long) _bb));
	void* _db = apply(_j, _cb);
	void* _fb = g_init(*((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _gb = apply(_db, _fb);
	void* _ic = h_init(*((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _jc = apply(_gb, _ic);
	return _jc;
}
void* f_init(void* operator_if, void* n, void* fac){
	struct f_cls* reserved = (struct f_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &f_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = n;
	*((void**) reserved + 4) = fac;
	return (void*) reserved;
}
struct d_cls{
	void* (*call)(void*, void*);
	void *operator_if, *n, *fac;
};
void* d_call(void* genenv, void* n){
	struct d_cls *env = (struct d_cls*) genenv;
	*((void**) env + 2) = n;
	void* _b = (*((void**) env + 1 + 0));
	void* _c = (*((void**) env + 1 + 1));
	void* _d = ((void*) 0);
	void* _e = (void*) ((long long)((long long) _c == (long long) _d));
	void* _f = apply(_b, _e);
	void* _h = e_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _i = apply(_f, _h);
	void* _ad = f_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _bd = apply(_i, _ad);
	return _bd;
}
void* d_init(void* operator_if, void* fac){
	struct d_cls* reserved = (struct d_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &d_call;
	*((void**) reserved + 1) = operator_if;
	*((void**) reserved + 3) = fac;
	return (void*) reserved;
}
struct ab_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *id, *fac;
};
void* ab_call(void* genenv, void* x){
	struct ab_cls *env = (struct ab_cls*) genenv;
	*((void**) env + 1) = x;
	void* _dd = (*((void**) env + 1 + 0));
	return _dd;
}
void* ab_init(void* operator_if, void* id, void* fac){
	struct ab_cls* reserved = (struct ab_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ab_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = id;
	*((void**) reserved + 4) = fac;
	return (void*) reserved;
}
struct db_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *id, *fac, *f, *applyFunc;
};
void* db_call(void* genenv, void* x){
	struct db_cls *env = (struct db_cls*) genenv;
	*((void**) env + 1) = x;
	void* _fd = (*((void**) env + 1 + 4));
	void* _gd = (*((void**) env + 1 + 0));
	void* _hd = apply(_fd, _gd);
	return _hd;
}
void* db_init(void* operator_if, void* id, void* fac, void* f, void* applyFunc){
	struct db_cls* reserved = (struct db_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &db_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = id;
	*((void**) reserved + 4) = fac;
	*((void**) reserved + 5) = f;
	*((void**) reserved + 6) = applyFunc;
	return (void*) reserved;
}
struct cb_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *id, *fac, *f, *applyFunc;
};
void* cb_call(void* genenv, void* f){
	struct cb_cls *env = (struct cb_cls*) genenv;
	*((void**) env + 5) = f;
	void* _id = db_init(*((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6));
	return _id;
}
void* cb_init(void* x, void* operator_if, void* id, void* fac, void* applyFunc){
	struct cb_cls* reserved = (struct cb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &cb_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = id;
	*((void**) reserved + 4) = fac;
	*((void**) reserved + 6) = applyFunc;
	return (void*) reserved;
}
struct eb_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *main, *id, *fac, *applyFunc;
};
void* eb_call(void* genenv, void* main){
	struct eb_cls *env = (struct eb_cls*) genenv;
	*((void**) env + 3) = main;
	void* _ae = (*((void**) env + 1 + 2));
	return _ae;
}
void* eb_init(void* x, void* operator_if, void* id, void* fac, void* applyFunc){
	struct eb_cls* reserved = (struct eb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &eb_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 4) = id;
	*((void**) reserved + 5) = fac;
	*((void**) reserved + 6) = applyFunc;
	return (void*) reserved;
}
struct bb_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *id, *fac, *applyFunc;
};
void* bb_call(void* genenv, void* applyFunc){
	struct bb_cls *env = (struct bb_cls*) genenv;
	*((void**) env + 5) = applyFunc;
	void* _de = (*((void**) env + 1 + 4));
	void* _ee = (*((void**) env + 1 + 4));
	void* _fe = (*((void**) env + 1 + 2));
	void* _ge = apply(_ee, _fe);
	void* _he = (*((void**) env + 1 + 3));
	void* _ie = apply(_ge, _he);
	void* _je = apply(_de, _ie);
	void* _af = (*((void**) env + 1 + 4));
	void* _bf = (*((void**) env + 1 + 2));
	void* _cf = apply(_af, _bf);
	void* _df = (*((void**) env + 1 + 0));
	void* _ef = apply(_cf, _df);
	void* _ff = apply(_je, _ef);
	void* _ce = eb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _be = apply(_ce, _ff);
	return _be;
}
void* bb_init(void* x, void* operator_if, void* id, void* fac){
	struct bb_cls* reserved = (struct bb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &bb_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = id;
	*((void**) reserved + 4) = fac;
	return (void*) reserved;
}
struct bb_env{
	 void* (*call) (void*, void*);
	void *x, *operator_if, *id, *fac, *applyFunc;
};
void* bb_app(void* f, void *x, void *operator_if, void *id, void *fac){
	struct bb_env* env = malloc(sizeof(*env));
	*((void**) env + 1) = x;
	*((void**) env + 2) = operator_if;
	*((void**) env + 3) = id;
	*((void**) env + 4) = fac;
	*((void**) env + 5) = NULL;
	void* _jd = cb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	*(void**)(_jd + 6 * sizeof(void*)) = _jd;
	return apply(f, _jd);
}
struct j_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *id, *fac;
};
void* j_call(void* genenv, void* id){
	struct j_cls *env = (struct j_cls*) genenv;
	*((void**) env + 3) = id;
	void* _hf = bb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _gf = bb_app(_hf, env->x, env->operator_if, env->id, env->fac);
	return _gf;
}
void* j_init(void* x, void* operator_if, void* fac){
	struct j_cls* reserved = (struct j_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &j_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 4) = fac;
	return (void*) reserved;
}
struct j_env{
	 void* (*call) (void*, void*);
	void *x, *operator_if, *id, *fac;
};
void* j_app(void* f, void *x, void *operator_if, void *fac){
	struct j_env* env = malloc(sizeof(*env));
	*((void**) env + 1) = x;
	*((void**) env + 2) = operator_if;
	*((void**) env + 4) = fac;
	*((void**) env + 3) = NULL;
	void* _ed = ab_init(*((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	*(void**)(_ed + 3 * sizeof(void*)) = _ed;
	return apply(f, _ed);
}
struct i_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *fac;
};
void* i_call(void* genenv, void* x){
	struct i_cls *env = (struct i_cls*) genenv;
	*((void**) env + 1) = x;
	void* _jf = j_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _if = j_app(_jf, env->x, env->operator_if, env->fac);
	return _if;
}
void* i_init(void* operator_if, void* fac){
	struct i_cls* reserved = (struct i_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &i_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = fac;
	return (void*) reserved;
}
struct c_cls{
	void* (*call)(void*, void*);
	void *operator_if, *fac;
};
void* c_call(void* genenv, void* fac){
	struct c_cls *env = (struct c_cls*) genenv;
	*((void**) env + 2) = fac;
	void* _cg = ((void*) 20);
	void* _bg = i_init(*((void**) env + 1), *((void**) env + 2));
	void* _ag = apply(_bg, _cg);
	return _ag;
}
void* c_init(void* operator_if){
	struct c_cls* reserved = (struct c_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &c_call;
	*((void**) reserved + 1) = operator_if;
	return (void*) reserved;
}
struct c_env{
	 void* (*call) (void*, void*);
	void *operator_if, *fac;
};
void* c_app(void* f, void *operator_if){
	struct c_env* env = malloc(sizeof(*env));
	*((void**) env + 1) = operator_if;
	*((void**) env + 2) = NULL;
	void* _cd = d_init(*((void**) env + 1), *((void**) env + 2));
	*(void**)(_cd + 3 * sizeof(void*)) = _cd;
	return apply(f, _cd);
}
struct b_cls{
	void* (*call)(void*, void*);
	void *operator_if;
};
void* b_call(void* genenv, void* operator_if){
	struct b_cls *env = (struct b_cls*) genenv;
	*((void**) env + 1) = operator_if;
	void* _eg = c_init(*((void**) env + 1));
	void* _dg = c_app(_eg, env->operator_if);
	return _dg;
}
void* b_init(){
	struct b_cls* reserved = (struct b_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &b_call;
	return (void*) reserved;
}
struct hb_cls{
	void* (*call)(void*, void*);
	void *t, *e, *c;
};
void* hb_call(void* genenv, void* e){
	struct hb_cls *env = (struct hb_cls*) genenv;
	*((void**) env + 2) = e;
	void* _hg = (*((void**) env + 1 + 2));
	void* _ig = (*((void**) env + 1 + 0));
	void* _jg = (*((void**) env + 1 + 1));
	void* _ah;
	if(_hg)
		_ah = apply(_ig, NULL);
	else
		_ah = apply(_jg, NULL);
	return _ah;
}
void* hb_init(void* t, void* c){
	struct hb_cls* reserved = (struct hb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &hb_call;
	*((void**) reserved + 1) = t;
	*((void**) reserved + 3) = c;
	return (void*) reserved;
}
struct gb_cls{
	void* (*call)(void*, void*);
	void *t, *c;
};
void* gb_call(void* genenv, void* t){
	struct gb_cls *env = (struct gb_cls*) genenv;
	*((void**) env + 1) = t;
	void* _bh = hb_init(*((void**) env + 1), *((void**) env + 2));
	return _bh;
}
void* gb_init(void* c){
	struct gb_cls* reserved = (struct gb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &gb_call;
	*((void**) reserved + 2) = c;
	return (void*) reserved;
}
struct fb_cls{
	void* (*call)(void*, void*);
	void *c;
};
void* fb_call(void* genenv, void* c){
	struct fb_cls *env = (struct fb_cls*) genenv;
	*((void**) env + 1) = c;
	void* _ch = gb_init(*((void**) env + 1));
	return _ch;
}
void* fb_init(){
	struct fb_cls* reserved = (struct fb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &fb_call;
	return (void*) reserved;
}

int main(){
	void* _dh = fb_init();
	void* _gg = b_init();
	void* _fg = apply(_gg, _dh);
	printf("%lld\n", ((long long)_fg));
	return 0;
}
/*; ModuleID = 'Orlang'
source_filename = "Orlang"

%struct.b_cls = type { i8* (i8*, i8*)*, i8* }
%struct.d_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.e_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.f_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.g_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.h_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.c_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.i_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.ab_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.j_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.cb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.db_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.bb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.eb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.fb_cls = type { i8* (i8*, i8*)*, i8* }
%struct.gb_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.hb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }

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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @e_init(i8* %operator_if, i8* %n, i8* %fac) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %n2 = alloca i8*, align 8
  store i8* %n, i8** %n2, align 8
  %fac3 = alloca i8*, align 8
  store i8* %fac, i8** %fac3, align 8
  %reserved = alloca %struct.e_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.e_cls* getelementptr (%struct.e_cls, %struct.e_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.e_cls*
  store %struct.e_cls* %space, %struct.e_cls** %reserved, align 8
  %struct_load = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast = bitcast %struct.e_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @e_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.e_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %n2, align 8
  %struct_load7 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.e_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %fac3, align 8
  %struct_load11 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.e_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.e_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

declare noalias i8* @malloc(i32)

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

define i8* @g_init(i8* %operator_if, i8* %n, i8* %fac) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %n2 = alloca i8*, align 8
  store i8* %n, i8** %n2, align 8
  %fac3 = alloca i8*, align 8
  store i8* %fac, i8** %fac3, align 8
  %reserved = alloca %struct.g_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.g_cls* getelementptr (%struct.g_cls, %struct.g_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.g_cls*
  store %struct.g_cls* %space, %struct.g_cls** %reserved, align 8
  %struct_load = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast = bitcast %struct.g_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @g_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.g_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %n2, align 8
  %struct_load7 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.g_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %fac3, align 8
  %struct_load11 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.g_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.g_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @h_init(i8* %operator_if, i8* %n, i8* %fac) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %n2 = alloca i8*, align 8
  store i8* %n, i8** %n2, align 8
  %fac3 = alloca i8*, align 8
  store i8* %fac, i8** %fac3, align 8
  %reserved = alloca %struct.h_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.h_cls* getelementptr (%struct.h_cls, %struct.h_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.h_cls*
  store %struct.h_cls* %space, %struct.h_cls** %reserved, align 8
  %struct_load = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast = bitcast %struct.h_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @h_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.h_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %n2, align 8
  %struct_load7 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.h_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %fac3, align 8
  %struct_load11 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.h_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.h_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @f_init(i8* %operator_if, i8* %n, i8* %fac) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %n2 = alloca i8*, align 8
  store i8* %n, i8** %n2, align 8
  %fac3 = alloca i8*, align 8
  store i8* %fac, i8** %fac3, align 8
  %reserved = alloca %struct.f_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.f_cls* getelementptr (%struct.f_cls, %struct.f_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.f_cls*
  store %struct.f_cls* %space, %struct.f_cls** %reserved, align 8
  %struct_load = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast = bitcast %struct.f_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @f_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.f_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %n2, align 8
  %struct_load7 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.f_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %fac3, align 8
  %struct_load11 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.f_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.f_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @d_init(i8* %operator_if, i8* %fac) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %fac2 = alloca i8*, align 8
  store i8* %fac, i8** %fac2, align 8
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %fac2, align 8
  %struct_load6 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.d_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.d_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
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

define i8* @ab_init(i8* %operator_if, i8* %id, i8* %fac) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %id2 = alloca i8*, align 8
  store i8* %id, i8** %id2, align 8
  %fac3 = alloca i8*, align 8
  store i8* %fac, i8** %fac3, align 8
  %reserved = alloca %struct.ab_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ab_cls* getelementptr (%struct.ab_cls, %struct.ab_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ab_cls*
  store %struct.ab_cls* %space, %struct.ab_cls** %reserved, align 8
  %struct_load = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ab_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ab_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.ab_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %id2, align 8
  %struct_load7 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.ab_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %fac3, align 8
  %struct_load11 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.ab_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.ab_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
  store i8* %argval, i8** %elem_ptr, align 8
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 5
  store i8* %argval, i8** %elem_ptr, align 8
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

define i8* @db_init(i8* %operator_if, i8* %id, i8* %fac, i8* %f, i8* %applyFunc) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %id2 = alloca i8*, align 8
  store i8* %id, i8** %id2, align 8
  %fac3 = alloca i8*, align 8
  store i8* %fac, i8** %fac3, align 8
  %f4 = alloca i8*, align 8
  store i8* %f, i8** %f4, align 8
  %applyFunc5 = alloca i8*, align 8
  store i8* %applyFunc, i8** %applyFunc5, align 8
  %reserved = alloca %struct.db_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.db_cls* getelementptr (%struct.db_cls, %struct.db_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.db_cls*
  store %struct.db_cls* %space, %struct.db_cls** %reserved, align 8
  %struct_load = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast = bitcast %struct.db_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @db_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load6 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.db_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %id2, align 8
  %struct_load9 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.db_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 3
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %fac3, align 8
  %struct_load13 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.db_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %f4, align 8
  %struct_load17 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.db_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %applyFunc5, align 8
  %struct_load21 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.db_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.db_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @cb_init(i8* %x, i8* %operator_if, i8* %id, i8* %fac, i8* %applyFunc) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %id3 = alloca i8*, align 8
  store i8* %id, i8** %id3, align 8
  %fac4 = alloca i8*, align 8
  store i8* %fac, i8** %fac4, align 8
  %applyFunc5 = alloca i8*, align 8
  store i8* %applyFunc, i8** %applyFunc5, align 8
  %reserved = alloca %struct.cb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.cb_cls* getelementptr (%struct.cb_cls, %struct.cb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.cb_cls*
  store %struct.cb_cls* %space, %struct.cb_cls** %reserved, align 8
  %struct_load = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.cb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @cb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.cb_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %operator_if2, align 8
  %struct_load9 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.cb_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 2
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %id3, align 8
  %struct_load13 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.cb_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 3
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %fac4, align 8
  %struct_load17 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.cb_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 4
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %applyFunc5, align 8
  %struct_load21 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.cb_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.cb_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 5
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @eb_init(i8* %x, i8* %operator_if, i8* %id, i8* %fac, i8* %applyFunc) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %id3 = alloca i8*, align 8
  store i8* %id, i8** %id3, align 8
  %fac4 = alloca i8*, align 8
  store i8* %fac, i8** %fac4, align 8
  %applyFunc5 = alloca i8*, align 8
  store i8* %applyFunc, i8** %applyFunc5, align 8
  %reserved = alloca %struct.eb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.eb_cls* getelementptr (%struct.eb_cls, %struct.eb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.eb_cls*
  store %struct.eb_cls* %space, %struct.eb_cls** %reserved, align 8
  %struct_load = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.eb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @eb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.eb_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %operator_if2, align 8
  %struct_load9 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.eb_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 2
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %id3, align 8
  %struct_load13 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.eb_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %fac4, align 8
  %struct_load17 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.eb_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %applyFunc5, align 8
  %struct_load21 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.eb_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.eb_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @bb_init(i8* %x, i8* %operator_if, i8* %id, i8* %fac) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %id3 = alloca i8*, align 8
  store i8* %id, i8** %id3, align 8
  %fac4 = alloca i8*, align 8
  store i8* %fac, i8** %fac4, align 8
  %reserved = alloca %struct.bb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.bb_cls* getelementptr (%struct.bb_cls, %struct.bb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.bb_cls*
  store %struct.bb_cls* %space, %struct.bb_cls** %reserved, align 8
  %struct_load = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.bb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @bb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load5 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.bb_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %operator_if2, align 8
  %struct_load8 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.bb_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 2
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %id3, align 8
  %struct_load12 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.bb_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 3
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %fac4, align 8
  %struct_load16 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.bb_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 4
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.bb_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @j_init(i8* %x, i8* %operator_if, i8* %fac) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %fac3 = alloca i8*, align 8
  store i8* %fac, i8** %fac3, align 8
  %reserved = alloca %struct.j_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.j_cls* getelementptr (%struct.j_cls, %struct.j_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.j_cls*
  store %struct.j_cls* %space, %struct.j_cls** %reserved, align 8
  %struct_load = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast = bitcast %struct.j_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @j_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load4 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.j_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %operator_if2, align 8
  %struct_load7 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.j_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 2
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %fac3, align 8
  %struct_load11 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.j_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.j_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @i_init(i8* %operator_if, i8* %fac) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %fac2 = alloca i8*, align 8
  store i8* %fac, i8** %fac2, align 8
  %reserved = alloca %struct.i_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.i_cls* getelementptr (%struct.i_cls, %struct.i_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.i_cls*
  store %struct.i_cls* %space, %struct.i_cls** %reserved, align 8
  %struct_load = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast = bitcast %struct.i_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @i_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load3 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.i_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %fac2, align 8
  %struct_load6 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.i_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.i_cls* %struct_load9 to i8*
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @hb_init(i8* %t, i8* %c) {
entry:
  %t1 = alloca i8*, align 8
  store i8* %t, i8** %t1, align 8
  %c2 = alloca i8*, align 8
  store i8* %c, i8** %c2, align 8
  %reserved = alloca %struct.hb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.hb_cls* getelementptr (%struct.hb_cls, %struct.hb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.hb_cls*
  store %struct.hb_cls* %space, %struct.hb_cls** %reserved, align 8
  %struct_load = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.hb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @hb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %t1, align 8
  %struct_load3 = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.hb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %c2, align 8
  %struct_load6 = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.hb_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.hb_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @gb_init(i8* %c) {
entry:
  %c1 = alloca i8*, align 8
  store i8* %c, i8** %c1, align 8
  %reserved = alloca %struct.gb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.gb_cls* getelementptr (%struct.gb_cls, %struct.gb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.gb_cls*
  store %struct.gb_cls* %space, %struct.gb_cls** %reserved, align 8
  %struct_load = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.gb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @gb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %c1, align 8
  %struct_load2 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.gb_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.gb_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
}

define i8* @fb_init() {
entry:
  %reserved = alloca %struct.fb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.fb_cls* getelementptr (%struct.fb_cls, %struct.fb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.fb_cls*
  store %struct.fb_cls* %space, %struct.fb_cls** %reserved, align 8
  %struct_load = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.fb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @fb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %struct_load1 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast2 = bitcast %struct.fb_cls* %struct_load1 to i8*
  ret i8* %struct_cast2
}
*/