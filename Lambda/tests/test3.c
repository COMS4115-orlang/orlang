#include<stdio.h>
#include <stdlib.h>
void* apply(void* f, void* arg){
	return (**((void* (**)(void*, void*)) f))(f, arg);
}
struct g_cls{
	void* (*call)(void*, void*);
	void *x, *tru, *operator_if, *main, *fls, *f;
};
void* g_call(void* genenv, void* main){
	struct g_cls *env = (struct g_cls*) genenv;
	*((void**) env + 4) = main;
	void* _b = (*((void**) env + 1 + 3));
	return _b;
}
void* g_init(void* x, void* tru, void* operator_if, void* fls, void* f){
	struct g_cls* reserved = (struct g_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &g_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = tru;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 5) = fls;
	*((void**) reserved + 6) = f;
	return (void*) reserved;
}
struct i_cls{
	void* (*call)(void*, void*);
	void *x, *tru, *res, *operator_if, *fls, *f;
};
void* i_call(void* genenv, void* res){
	struct i_cls *env = (struct i_cls*) genenv;
	*((void**) env + 3) = res;
	void* _ab = ((void*) 0);
	return _ab;
}
void* i_init(void* x, void* tru, void* operator_if, void* fls, void* f){
	struct i_cls* reserved = (struct i_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &i_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = tru;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = fls;
	*((void**) reserved + 6) = f;
	return (void*) reserved;
}
struct j_cls{
	void* (*call)(void*, void*);
	void *x, *tru, *res, *operator_if, *fls, *f;
};
void* j_call(void* genenv, void* res){
	struct j_cls *env = (struct j_cls*) genenv;
	*((void**) env + 3) = res;
	void* _db = ((void*) 1);
	return _db;
}
void* j_init(void* x, void* tru, void* operator_if, void* fls, void* f){
	struct j_cls* reserved = (struct j_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &j_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = tru;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = fls;
	*((void**) reserved + 6) = f;
	return (void*) reserved;
}
struct h_cls{
	void* (*call)(void*, void*);
	void *x, *tru, *res, *operator_if, *fls, *f;
};
void* h_call(void* genenv, void* res){
	struct h_cls *env = (struct h_cls*) genenv;
	*((void**) env + 3) = res;
	void* _h = (*((void**) env + 1 + 3));
	void* _i = (*((void**) env + 1 + 4));
	void* _j = apply(_h, _i);
	void* _bb = i_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6));
	void* _cb = apply(_j, _bb);
	void* _eb = j_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6));
	void* _fb = apply(_cb, _eb);
	return _fb;
}
void* h_init(void* x, void* tru, void* operator_if, void* fls, void* f){
	struct h_cls* reserved = (struct h_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &h_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = tru;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = fls;
	*((void**) reserved + 6) = f;
	return (void*) reserved;
}
struct ab_cls{
	void* (*call)(void*, void*);
	void *x, *tru, *res, *operator_if, *fls, *f;
};
void* ab_call(void* genenv, void* res){
	struct ab_cls *env = (struct ab_cls*) genenv;
	*((void**) env + 3) = res;
	void* _ib = ((void*) 0);
	return _ib;
}
void* ab_init(void* x, void* tru, void* operator_if, void* fls, void* f){
	struct ab_cls* reserved = (struct ab_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ab_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = tru;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = fls;
	*((void**) reserved + 6) = f;
	return (void*) reserved;
}
struct f_cls{
	void* (*call)(void*, void*);
	void *x, *tru, *operator_if, *fls, *f;
};
void* f_call(void* genenv, void* fls){
	struct f_cls *env = (struct f_cls*) genenv;
	*((void**) env + 4) = fls;
	void* _e = (*((void**) env + 1 + 2));
	void* _f = (*((void**) env + 1 + 1));
	void* _g = apply(_e, _f);
	void* _gb = h_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _hb = apply(_g, _gb);
	void* _jb = ab_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _ac = apply(_hb, _jb);
	void* _d = g_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _c = apply(_d, _ac);
	return _c;
}
void* f_init(void* x, void* tru, void* operator_if, void* f){
	struct f_cls* reserved = (struct f_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &f_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 2) = tru;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 5) = f;
	return (void*) reserved;
}
struct e_cls{
	void* (*call)(void*, void*);
	void *x, *tru, *operator_if, *f;
};
void* e_call(void* genenv, void* tru){
	struct e_cls *env = (struct e_cls*) genenv;
	*((void**) env + 2) = tru;
	void* _dc = (*((void**) env + 1 + 3));
	void* _ec = (*((void**) env + 1 + 0));
	void* _fc = ((void*) 1);
	void* _gc = (void*)((long long)!((long long) _fc));
	void* _hc = (void*) ((long long)((long long) _ec && (long long) _gc));
	void* _ic = apply(_dc, _hc);
	void* _cc = f_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _bc = apply(_cc, _ic);
	return _bc;
}
void* e_init(void* x, void* operator_if, void* f){
	struct e_cls* reserved = (struct e_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &e_call;
	*((void**) reserved + 1) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = f;
	return (void*) reserved;
}
struct d_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *f;
};
void* d_call(void* genenv, void* x){
	struct d_cls *env = (struct d_cls*) genenv;
	*((void**) env + 1) = x;
	void* _bd = (*((void**) env + 1 + 2));
	void* _cd = (*((void**) env + 1 + 0));
	void* _dd = ((void*) 0);
	void* _ed = (void*) ((long long)((long long) _cd || (long long) _dd));
	void* _fd = apply(_bd, _ed);
	void* _ad = e_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _jc = apply(_ad, _fd);
	return _jc;
}
void* d_init(void* operator_if, void* f){
	struct d_cls* reserved = (struct d_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &d_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = f;
	return (void*) reserved;
}
struct c_cls{
	void* (*call)(void*, void*);
	void *operator_if, *f;
};
void* c_call(void* genenv, void* f){
	struct c_cls *env = (struct c_cls*) genenv;
	*((void**) env + 2) = f;
	void* _id = ((void*) 1);
	void* _hd = d_init(*((void**) env + 1), *((void**) env + 2));
	void* _gd = apply(_hd, _id);
	return _gd;
}
void* c_init(void* operator_if){
	struct c_cls* reserved = (struct c_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &c_call;
	*((void**) reserved + 1) = operator_if;
	return (void*) reserved;
}
struct bb_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if;
};
void* bb_call(void* genenv, void* x){
	struct bb_cls *env = (struct bb_cls*) genenv;
	*((void**) env + 1) = x;
	void* _be = (*((void**) env + 1 + 0));
	return _be;
}
void* bb_init(void* operator_if){
	struct bb_cls* reserved = (struct bb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &bb_call;
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
	void* _ce = bb_init(*((void**) env + 1));
	void* _ae = c_init(*((void**) env + 1));
	void* _jd = apply(_ae, _ce);
	return _jd;
}
void* b_init(){
	struct b_cls* reserved = (struct b_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &b_call;
	return (void*) reserved;
}
struct eb_cls{
	void* (*call)(void*, void*);
	void *t, *e, *c;
};
void* eb_call(void* genenv, void* e){
	struct eb_cls *env = (struct eb_cls*) genenv;
	*((void**) env + 2) = e;
	void* _fe = (*((void**) env + 1 + 2));
	void* _ge = (*((void**) env + 1 + 0));
	void* _he = (*((void**) env + 1 + 1));
	void* _ie;
	if(_fe)
		_ie = apply(_ge, NULL);
	else
		_ie = apply(_he, NULL);
	return _ie;
}
void* eb_init(void* t, void* c){
	struct eb_cls* reserved = (struct eb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &eb_call;
	*((void**) reserved + 1) = t;
	*((void**) reserved + 3) = c;
	return (void*) reserved;
}
struct db_cls{
	void* (*call)(void*, void*);
	void *t, *c;
};
void* db_call(void* genenv, void* t){
	struct db_cls *env = (struct db_cls*) genenv;
	*((void**) env + 1) = t;
	void* _je = eb_init(*((void**) env + 1), *((void**) env + 2));
	return _je;
}
void* db_init(void* c){
	struct db_cls* reserved = (struct db_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &db_call;
	*((void**) reserved + 2) = c;
	return (void*) reserved;
}
struct cb_cls{
	void* (*call)(void*, void*);
	void *c;
};
void* cb_call(void* genenv, void* c){
	struct cb_cls *env = (struct cb_cls*) genenv;
	*((void**) env + 1) = c;
	void* _af = db_init(*((void**) env + 1));
	return _af;
}
void* cb_init(){
	struct cb_cls* reserved = (struct cb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &cb_call;
	return (void*) reserved;
}

int main(){
	void* _bf = cb_init();
	void* _ee = b_init();
	void* _de = apply(_ee, _bf);
	printf("%lld\n", ((long long)_de));
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
%struct.h_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.i_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.j_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.ab_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.bb_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.cb_cls = type { i8* (i8*, i8*)*, i8* }
%struct.db_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.eb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }

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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 4
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 4
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @g_init(i8* %x, i8* %tru, i8* %operator_if, i8* %fls, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %tru2 = alloca i8*, align 8
  store i8* %tru, i8** %tru2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %fls4 = alloca i8*, align 8
  store i8* %fls, i8** %fls4, align 8
  %f5 = alloca i8*, align 8
  store i8* %f, i8** %f5, align 8
  %reserved = alloca %struct.g_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.g_cls* getelementptr (%struct.g_cls, %struct.g_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.g_cls*
  store %struct.g_cls* %space, %struct.g_cls** %reserved, align 8
  %struct_load = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast = bitcast %struct.g_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @g_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.g_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %tru2, align 8
  %struct_load9 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.g_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 2
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %operator_if3, align 8
  %struct_load13 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.g_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 3
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %fls4, align 8
  %struct_load17 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.g_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %f5, align 8
  %struct_load21 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.g_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.g_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

declare noalias i8* @malloc(i32)

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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @i_init(i8* %x, i8* %tru, i8* %operator_if, i8* %fls, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %tru2 = alloca i8*, align 8
  store i8* %tru, i8** %tru2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %fls4 = alloca i8*, align 8
  store i8* %fls, i8** %fls4, align 8
  %f5 = alloca i8*, align 8
  store i8* %f, i8** %f5, align 8
  %reserved = alloca %struct.i_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.i_cls* getelementptr (%struct.i_cls, %struct.i_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.i_cls*
  store %struct.i_cls* %space, %struct.i_cls** %reserved, align 8
  %struct_load = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast = bitcast %struct.i_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @i_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.i_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %tru2, align 8
  %struct_load9 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.i_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 2
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %operator_if3, align 8
  %struct_load13 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.i_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %fls4, align 8
  %struct_load17 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.i_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %f5, align 8
  %struct_load21 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.i_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.i_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
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

define i8* @j_init(i8* %x, i8* %tru, i8* %operator_if, i8* %fls, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %tru2 = alloca i8*, align 8
  store i8* %tru, i8** %tru2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %fls4 = alloca i8*, align 8
  store i8* %fls, i8** %fls4, align 8
  %f5 = alloca i8*, align 8
  store i8* %f, i8** %f5, align 8
  %reserved = alloca %struct.j_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.j_cls* getelementptr (%struct.j_cls, %struct.j_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.j_cls*
  store %struct.j_cls* %space, %struct.j_cls** %reserved, align 8
  %struct_load = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast = bitcast %struct.j_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @j_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.j_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %tru2, align 8
  %struct_load9 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.j_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 2
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %operator_if3, align 8
  %struct_load13 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.j_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %fls4, align 8
  %struct_load17 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.j_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %f5, align 8
  %struct_load21 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.j_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.j_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @h_init(i8* %x, i8* %tru, i8* %operator_if, i8* %fls, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %tru2 = alloca i8*, align 8
  store i8* %tru, i8** %tru2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %fls4 = alloca i8*, align 8
  store i8* %fls, i8** %fls4, align 8
  %f5 = alloca i8*, align 8
  store i8* %f, i8** %f5, align 8
  %reserved = alloca %struct.h_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.h_cls* getelementptr (%struct.h_cls, %struct.h_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.h_cls*
  store %struct.h_cls* %space, %struct.h_cls** %reserved, align 8
  %struct_load = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast = bitcast %struct.h_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @h_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.h_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %tru2, align 8
  %struct_load9 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.h_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 2
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %operator_if3, align 8
  %struct_load13 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.h_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %fls4, align 8
  %struct_load17 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.h_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %f5, align 8
  %struct_load21 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.h_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.h_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @ab_init(i8* %x, i8* %tru, i8* %operator_if, i8* %fls, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %tru2 = alloca i8*, align 8
  store i8* %tru, i8** %tru2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %fls4 = alloca i8*, align 8
  store i8* %fls, i8** %fls4, align 8
  %f5 = alloca i8*, align 8
  store i8* %f, i8** %f5, align 8
  %reserved = alloca %struct.ab_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ab_cls* getelementptr (%struct.ab_cls, %struct.ab_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ab_cls*
  store %struct.ab_cls* %space, %struct.ab_cls** %reserved, align 8
  %struct_load = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ab_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ab_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.ab_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %tru2, align 8
  %struct_load9 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.ab_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 2
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %operator_if3, align 8
  %struct_load13 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.ab_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %fls4, align 8
  %struct_load17 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.ab_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %f5, align 8
  %struct_load21 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.ab_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.ab_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @f_init(i8* %x, i8* %tru, i8* %operator_if, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %tru2 = alloca i8*, align 8
  store i8* %tru, i8** %tru2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %f4 = alloca i8*, align 8
  store i8* %f, i8** %f4, align 8
  %reserved = alloca %struct.f_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.f_cls* getelementptr (%struct.f_cls, %struct.f_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.f_cls*
  store %struct.f_cls* %space, %struct.f_cls** %reserved, align 8
  %struct_load = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast = bitcast %struct.f_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @f_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load5 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.f_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %tru2, align 8
  %struct_load8 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.f_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 2
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %operator_if3, align 8
  %struct_load12 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.f_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 3
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %f4, align 8
  %struct_load16 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.f_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.f_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @e_init(i8* %x, i8* %operator_if, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %f3 = alloca i8*, align 8
  store i8* %f, i8** %f3, align 8
  %reserved = alloca %struct.e_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.e_cls* getelementptr (%struct.e_cls, %struct.e_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.e_cls*
  store %struct.e_cls* %space, %struct.e_cls** %reserved, align 8
  %struct_load = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast = bitcast %struct.e_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @e_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load4 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.e_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %operator_if2, align 8
  %struct_load7 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.e_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %f3, align 8
  %struct_load11 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.e_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.e_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @d_init(i8* %operator_if, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %f2 = alloca i8*, align 8
  store i8* %f, i8** %f2, align 8
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
  %argval5 = load i8*, i8** %f2, align 8
  %struct_load6 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.d_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.d_cls* %struct_load9 to i8*
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

define i8* @bb_init(i8* %operator_if) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %reserved = alloca %struct.bb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.bb_cls* getelementptr (%struct.bb_cls, %struct.bb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.bb_cls*
  store %struct.bb_cls* %space, %struct.bb_cls** %reserved, align 8
  %struct_load = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.bb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @bb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load2 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.bb_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.bb_cls* %struct_load4 to i8*
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @eb_init(i8* %t, i8* %c) {
entry:
  %t1 = alloca i8*, align 8
  store i8* %t, i8** %t1, align 8
  %c2 = alloca i8*, align 8
  store i8* %c, i8** %c2, align 8
  %reserved = alloca %struct.eb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.eb_cls* getelementptr (%struct.eb_cls, %struct.eb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.eb_cls*
  store %struct.eb_cls* %space, %struct.eb_cls** %reserved, align 8
  %struct_load = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.eb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @eb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %t1, align 8
  %struct_load3 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.eb_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %c2, align 8
  %struct_load6 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.eb_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.eb_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @db_init(i8* %c) {
entry:
  %c1 = alloca i8*, align 8
  store i8* %c, i8** %c1, align 8
  %reserved = alloca %struct.db_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.db_cls* getelementptr (%struct.db_cls, %struct.db_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.db_cls*
  store %struct.db_cls* %space, %struct.db_cls** %reserved, align 8
  %struct_load = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast = bitcast %struct.db_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @db_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %c1, align 8
  %struct_load2 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.db_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.db_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
}

define i8* @cb_init() {
entry:
  %reserved = alloca %struct.cb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.cb_cls* getelementptr (%struct.cb_cls, %struct.cb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.cb_cls*
  store %struct.cb_cls* %space, %struct.cb_cls** %reserved, align 8
  %struct_load = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.cb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @cb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %struct_load1 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast2 = bitcast %struct.cb_cls* %struct_load1 to i8*
  ret i8* %struct_cast2
}
*/