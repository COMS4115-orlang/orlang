#include<stdio.h>
#include <stdlib.h>
void* apply(void* f, void* arg){
	return (**((void* (**)(void*, void*)) f))(f, arg);
}
struct d_cls{
	void* (*call)(void*, void*);
	void *y, *operator_if, *main;
};
void* d_call(void* genenv, void* main){
	struct d_cls *env = (struct d_cls*) genenv;
	*((void**) env + 3) = main;
	void* _b = (*((void**) env + 1 + 2));
	return _b;
}
void* d_init(void* y, void* operator_if){
	struct d_cls* reserved = (struct d_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &d_call;
	*((void**) reserved + 1) = y;
	*((void**) reserved + 2) = operator_if;
	return (void*) reserved;
}
struct c_cls{
	void* (*call)(void*, void*);
	void *y, *operator_if;
};
void* c_call(void* genenv, void* y){
	struct c_cls *env = (struct c_cls*) genenv;
	*((void**) env + 1) = y;
	void* _e = (*((void**) env + 1 + 0));
	void* _d = d_init(*((void**) env + 1), *((void**) env + 2));
	void* _c = apply(_d, _e);
	return _c;
}
void* c_init(void* operator_if){
	struct c_cls* reserved = (struct c_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &c_call;
	*((void**) reserved + 2) = operator_if;
	return (void*) reserved;
}
struct g_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if;
};
void* g_call(void* genenv, void* x){
	struct g_cls *env = (struct g_cls*) genenv;
	*((void**) env + 1) = x;
	void* _h = (*((void**) env + 1 + 0));
	void* _i = ((void*) 0);
	void* _j = apply(_h, _i);
	return _j;
}
void* g_init(void* operator_if){
	struct g_cls* reserved = (struct g_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &g_call;
	*((void**) reserved + 2) = operator_if;
	return (void*) reserved;
}
struct h_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if;
};
void* h_call(void* genenv, void* y){
	struct h_cls *env = (struct h_cls*) genenv;
	*((void**) env + 1) = y;
	void* _cb = (*((void**) env + 1 + 1));
	void* _db = (*((void**) env + 1 + 0));
	void* _eb = (void*) ((long long)((long long) _cb + (long long) _db));
	return _eb;
}
void* h_init(void* x, void* operator_if){
	struct h_cls* reserved = (struct h_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &h_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	return (void*) reserved;
}
struct f_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if;
};
void* f_call(void* genenv, void* x){
	struct f_cls *env = (struct f_cls*) genenv;
	*((void**) env + 1) = x;
	void* _fb = h_init(*((void**) env + 1), *((void**) env + 2));
	void* _bb = g_init(*((void**) env + 2));
	void* _ab = apply(_bb, _fb);
	return _ab;
}
void* f_init(void* operator_if){
	struct f_cls* reserved = (struct f_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &f_call;
	*((void**) reserved + 2) = operator_if;
	return (void*) reserved;
}
struct e_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if;
};
void* e_call(void* genenv, void* x){
	struct e_cls *env = (struct e_cls*) genenv;
	*((void**) env + 1) = x;
	void* _ib = (*((void**) env + 1 + 0));
	void* _jb = ((void*) 1);
	void* _ac = (void*) ((long long)((long long) _ib + (long long) _jb));
	void* _hb = f_init(*((void**) env + 2));
	void* _gb = apply(_hb, _ac);
	return _gb;
}
void* e_init(void* operator_if){
	struct e_cls* reserved = (struct e_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &e_call;
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
	void* _dc = ((void*) 5);
	void* _cc = e_init(*((void**) env + 1));
	void* _bc = apply(_cc, _dc);
	void* _g = c_init(*((void**) env + 1));
	void* _f = apply(_g, _bc);
	return _f;
}
void* b_init(){
	struct b_cls* reserved = (struct b_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &b_call;
	return (void*) reserved;
}
struct ab_cls{
	void* (*call)(void*, void*);
	void *t, *e, *c;
};
void* ab_call(void* genenv, void* e){
	struct ab_cls *env = (struct ab_cls*) genenv;
	*((void**) env + 2) = e;
	void* _gc = (*((void**) env + 1 + 2));
	void* _hc = (*((void**) env + 1 + 0));
	void* _ic = (*((void**) env + 1 + 1));
	void* _jc;
	if(_gc)
		_jc = apply(_hc, NULL);
	else
		_jc = apply(_ic, NULL);
	return _jc;
}
void* ab_init(void* t, void* c){
	struct ab_cls* reserved = (struct ab_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ab_call;
	*((void**) reserved + 1) = t;
	*((void**) reserved + 3) = c;
	return (void*) reserved;
}
struct j_cls{
	void* (*call)(void*, void*);
	void *t, *c;
};
void* j_call(void* genenv, void* t){
	struct j_cls *env = (struct j_cls*) genenv;
	*((void**) env + 1) = t;
	void* _ad = ab_init(*((void**) env + 1), *((void**) env + 2));
	return _ad;
}
void* j_init(void* c){
	struct j_cls* reserved = (struct j_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &j_call;
	*((void**) reserved + 2) = c;
	return (void*) reserved;
}
struct i_cls{
	void* (*call)(void*, void*);
	void *c;
};
void* i_call(void* genenv, void* c){
	struct i_cls *env = (struct i_cls*) genenv;
	*((void**) env + 1) = c;
	void* _bd = j_init(*((void**) env + 1));
	return _bd;
}
void* i_init(){
	struct i_cls* reserved = (struct i_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &i_call;
	return (void*) reserved;
}

int main(){
	void* _cd = i_init();
	void* _fc = b_init();
	void* _ec = apply(_fc, _cd);
	printf("%lld\n", ((long long)_ec));
	return 0;
}
/*; ModuleID = 'Orlang'
source_filename = "Orlang"

%struct.b_cls = type { i8* (i8*, i8*)*, i8* }
%struct.c_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.d_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.e_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.f_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.g_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.h_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.i_cls = type { i8* (i8*, i8*)*, i8* }
%struct.j_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.ab_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }

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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @d_init(i8* %y, i8* %operator_if) {
entry:
  %y1 = alloca i8*, align 8
  store i8* %y, i8** %y1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %reserved = alloca %struct.d_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.d_cls* getelementptr (%struct.d_cls, %struct.d_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.d_cls*
  store %struct.d_cls* %space, %struct.d_cls** %reserved, align 8
  %struct_load = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast = bitcast %struct.d_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @d_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %y1, align 8
  %struct_load3 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.d_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %operator_if2, align 8
  %struct_load6 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.d_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.d_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

declare noalias i8* @malloc(i32)

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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.c_cls*, %struct.c_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.c_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
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

define i8* @g_init(i8* %operator_if) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %reserved = alloca %struct.g_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.g_cls* getelementptr (%struct.g_cls, %struct.g_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.g_cls*
  store %struct.g_cls* %space, %struct.g_cls** %reserved, align 8
  %struct_load = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast = bitcast %struct.g_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @g_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load2 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.g_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.g_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
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

define i8* @h_init(i8* %x, i8* %operator_if) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %reserved = alloca %struct.h_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.h_cls* getelementptr (%struct.h_cls, %struct.h_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.h_cls*
  store %struct.h_cls* %space, %struct.h_cls** %reserved, align 8
  %struct_load = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast = bitcast %struct.h_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @h_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load3 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.h_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %operator_if2, align 8
  %struct_load6 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.h_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.h_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @f_init(i8* %operator_if) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %reserved = alloca %struct.f_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.f_cls* getelementptr (%struct.f_cls, %struct.f_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.f_cls*
  store %struct.f_cls* %space, %struct.f_cls** %reserved, align 8
  %struct_load = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast = bitcast %struct.f_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @f_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load2 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.f_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.f_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
}

define i8* @e_init(i8* %operator_if) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %reserved = alloca %struct.e_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.e_cls* getelementptr (%struct.e_cls, %struct.e_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.e_cls*
  store %struct.e_cls* %space, %struct.e_cls** %reserved, align 8
  %struct_load = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast = bitcast %struct.e_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @e_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load2 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.e_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.e_cls* %struct_load4 to i8*
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @ab_init(i8* %t, i8* %c) {
entry:
  %t1 = alloca i8*, align 8
  store i8* %t, i8** %t1, align 8
  %c2 = alloca i8*, align 8
  store i8* %c, i8** %c2, align 8
  %reserved = alloca %struct.ab_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ab_cls* getelementptr (%struct.ab_cls, %struct.ab_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ab_cls*
  store %struct.ab_cls* %space, %struct.ab_cls** %reserved, align 8
  %struct_load = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ab_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ab_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %t1, align 8
  %struct_load3 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.ab_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %c2, align 8
  %struct_load6 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.ab_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.ab_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @j_init(i8* %c) {
entry:
  %c1 = alloca i8*, align 8
  store i8* %c, i8** %c1, align 8
  %reserved = alloca %struct.j_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.j_cls* getelementptr (%struct.j_cls, %struct.j_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.j_cls*
  store %struct.j_cls* %space, %struct.j_cls** %reserved, align 8
  %struct_load = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast = bitcast %struct.j_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @j_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %c1, align 8
  %struct_load2 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.j_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.j_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
}

define i8* @i_init() {
entry:
  %reserved = alloca %struct.i_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.i_cls* getelementptr (%struct.i_cls, %struct.i_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.i_cls*
  store %struct.i_cls* %space, %struct.i_cls** %reserved, align 8
  %struct_load = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast = bitcast %struct.i_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @i_call, i8* (i8*, i8*)** %struct_cast, align 8
  %struct_load1 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast2 = bitcast %struct.i_cls* %struct_load1 to i8*
  ret i8* %struct_cast2
}
*/