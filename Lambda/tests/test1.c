#include<stdio.h>
#include <stdlib.h>
void* apply(void* f, void* arg){
	return (**((void* (**)(void*, void*)) f))(f, arg);
}
struct g_cls{
	void* (*call)(void*, void*);
	void *six, *operator_if, *main, *five3, *five2, *five;
};
void* g_call(void* genenv, void* main){
	struct g_cls *env = (struct g_cls*) genenv;
	*((void**) env + 3) = main;
	void* _b = (*((void**) env + 1 + 2));
	return _b;
}
void* g_init(void* six, void* operator_if, void* five3, void* five2, void* five){
	struct g_cls* reserved = (struct g_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &g_call;
	*((void**) reserved + 1) = six;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 4) = five3;
	*((void**) reserved + 5) = five2;
	*((void**) reserved + 6) = five;
	return (void*) reserved;
}
struct f_cls{
	void* (*call)(void*, void*);
	void *six, *operator_if, *five3, *five2, *five;
};
void* f_call(void* genenv, void* six){
	struct f_cls *env = (struct f_cls*) genenv;
	*((void**) env + 1) = six;
	void* _e = (*((void**) env + 1 + 4));
	void* _f = ((void*) 1000);
	void* _g = (void*) ((long long)((long long) _e * (long long) _f));
	void* _h = (*((void**) env + 1 + 3));
	void* _i = ((void*) 100);
	void* _j = (void*) ((long long)((long long) _h * (long long) _i));
	void* _ab = (void*) ((long long)((long long) _g + (long long) _j));
	void* _bb = (*((void**) env + 1 + 2));
	void* _cb = ((void*) 10);
	void* _db = (void*) ((long long)((long long) _bb * (long long) _cb));
	void* _eb = (void*) ((long long)((long long) _ab + (long long) _db));
	void* _fb = (*((void**) env + 1 + 0));
	void* _gb = (void*) ((long long)((long long) _eb + (long long) _fb));
	void* _d = g_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _c = apply(_d, _gb);
	return _c;
}
void* f_init(void* operator_if, void* five3, void* five2, void* five){
	struct f_cls* reserved = (struct f_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &f_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = five3;
	*((void**) reserved + 4) = five2;
	*((void**) reserved + 5) = five;
	return (void*) reserved;
}
struct i_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *five3, *five2, *five;
};
void* i_call(void* genenv, void* y){
	struct i_cls *env = (struct i_cls*) genenv;
	*((void**) env + 1) = y;
	void* _jb = ((void*) 6);
	return _jb;
}
void* i_init(void* x, void* operator_if, void* five3, void* five2, void* five){
	struct i_cls* reserved = (struct i_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &i_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = five3;
	*((void**) reserved + 5) = five2;
	*((void**) reserved + 6) = five;
	return (void*) reserved;
}
struct h_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *five3, *five2, *five;
};
void* h_call(void* genenv, void* x){
	struct h_cls *env = (struct h_cls*) genenv;
	*((void**) env + 1) = x;
	void* _ac = i_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	return _ac;
}
void* h_init(void* operator_if, void* five3, void* five2, void* five){
	struct h_cls* reserved = (struct h_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &h_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = five3;
	*((void**) reserved + 4) = five2;
	*((void**) reserved + 5) = five;
	return (void*) reserved;
}
struct e_cls{
	void* (*call)(void*, void*);
	void *operator_if, *five3, *five2, *five;
};
void* e_call(void* genenv, void* five3){
	struct e_cls *env = (struct e_cls*) genenv;
	*((void**) env + 2) = five3;
	void* _bc = h_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _cc = ((void*) 3);
	void* _dc = apply(_bc, _cc);
	void* _ec = ((void*) 6);
	void* _fc = apply(_dc, _ec);
	void* _ib = f_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _hb = apply(_ib, _fc);
	return _hb;
}
void* e_init(void* operator_if, void* five2, void* five){
	struct e_cls* reserved = (struct e_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &e_call;
	*((void**) reserved + 1) = operator_if;
	*((void**) reserved + 3) = five2;
	*((void**) reserved + 4) = five;
	return (void*) reserved;
}
struct fb_cls{
	void* (*call)(void*, void*);
	void *z, *y, *x, *v, *u, *operator_if, *g, *five2, *five, *f;
};
void* fb_call(void* genenv, void* z){
	struct fb_cls *env = (struct fb_cls*) genenv;
	*((void**) env + 1) = z;
	void* _ic = (*((void**) env + 1 + 0));
	return _ic;
}
void* fb_init(void* y, void* x, void* v, void* u, void* operator_if, void* g, void* five2, void* five, void* f){
	struct fb_cls* reserved = (struct fb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &fb_call;
	*((void**) reserved + 2) = y;
	*((void**) reserved + 3) = x;
	*((void**) reserved + 4) = v;
	*((void**) reserved + 5) = u;
	*((void**) reserved + 6) = operator_if;
	*((void**) reserved + 7) = g;
	*((void**) reserved + 8) = five2;
	*((void**) reserved + 9) = five;
	*((void**) reserved + 10) = f;
	return (void*) reserved;
}
struct eb_cls{
	void* (*call)(void*, void*);
	void *y, *x, *v, *u, *operator_if, *g, *five2, *five, *f;
};
void* eb_call(void* genenv, void* v){
	struct eb_cls *env = (struct eb_cls*) genenv;
	*((void**) env + 3) = v;
	void* _jc = fb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6), *((void**) env + 7), *((void**) env + 8), *((void**) env + 9));
	void* _ad = (*((void**) env + 1 + 8));
	void* _bd = (*((void**) env + 1 + 3));
	void* _cd = apply(_ad, _bd);
	void* _dd = (*((void**) env + 1 + 2));
	void* _ed = apply(_cd, _dd);
	void* _fd = apply(_jc, _ed);
	return _fd;
}
void* eb_init(void* y, void* x, void* u, void* operator_if, void* g, void* five2, void* five, void* f){
	struct eb_cls* reserved = (struct eb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &eb_call;
	*((void**) reserved + 1) = y;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 4) = u;
	*((void**) reserved + 5) = operator_if;
	*((void**) reserved + 6) = g;
	*((void**) reserved + 7) = five2;
	*((void**) reserved + 8) = five;
	*((void**) reserved + 9) = f;
	return (void*) reserved;
}
struct gb_cls{
	void* (*call)(void*, void*);
	void *z, *y, *x, *u, *operator_if, *g, *five2, *five, *f;
};
void* gb_call(void* genenv, void* z){
	struct gb_cls *env = (struct gb_cls*) genenv;
	*((void**) env + 1) = z;
	void* _hd = (*((void**) env + 1 + 0));
	void* _id = ((void*) 1);
	void* _jd = (void*) ((long long)((long long) _hd + (long long) _id));
	return _jd;
}
void* gb_init(void* y, void* x, void* u, void* operator_if, void* g, void* five2, void* five, void* f){
	struct gb_cls* reserved = (struct gb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &gb_call;
	*((void**) reserved + 2) = y;
	*((void**) reserved + 3) = x;
	*((void**) reserved + 4) = u;
	*((void**) reserved + 5) = operator_if;
	*((void**) reserved + 6) = g;
	*((void**) reserved + 7) = five2;
	*((void**) reserved + 8) = five;
	*((void**) reserved + 9) = f;
	return (void*) reserved;
}
struct db_cls{
	void* (*call)(void*, void*);
	void *y, *x, *u, *operator_if, *g, *five2, *five, *f;
};
void* db_call(void* genenv, void* u){
	struct db_cls *env = (struct db_cls*) genenv;
	*((void**) env + 3) = u;
	void* _gd = eb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6), *((void**) env + 7), *((void**) env + 8));
	void* _ae = gb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6), *((void**) env + 7), *((void**) env + 8));
	void* _be = (*((void**) env + 1 + 0));
	void* _ce = apply(_ae, _be);
	void* _de = apply(_gd, _ce);
	return _de;
}
void* db_init(void* y, void* x, void* operator_if, void* g, void* five2, void* five, void* f){
	struct db_cls* reserved = (struct db_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &db_call;
	*((void**) reserved + 1) = y;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = g;
	*((void**) reserved + 6) = five2;
	*((void**) reserved + 7) = five;
	*((void**) reserved + 8) = f;
	return (void*) reserved;
}
struct cb_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *g, *five2, *five, *f;
};
void* cb_call(void* genenv, void* y){
	struct cb_cls *env = (struct cb_cls*) genenv;
	*((void**) env + 1) = y;
	void* _ee = db_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6), *((void**) env + 7));
	void* _fe = (*((void**) env + 1 + 3));
	void* _ge = (*((void**) env + 1 + 1));
	void* _he = apply(_fe, _ge);
	void* _ie = ((void*) 2);
	void* _je = apply(_he, _ie);
	void* _af = ((void*) 3);
	void* _bf = (void*) ((long long)((long long) _je - (long long) _af));
	void* _cf = apply(_ee, _bf);
	return _cf;
}
void* cb_init(void* x, void* operator_if, void* g, void* five2, void* five, void* f){
	struct cb_cls* reserved = (struct cb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &cb_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = g;
	*((void**) reserved + 5) = five2;
	*((void**) reserved + 6) = five;
	*((void**) reserved + 7) = f;
	return (void*) reserved;
}
struct bb_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *g, *five2, *five, *f;
};
void* bb_call(void* genenv, void* x){
	struct bb_cls *env = (struct bb_cls*) genenv;
	*((void**) env + 1) = x;
	void* _df = cb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6));
	void* _ef = ((void*) 4);
	void* _ff = apply(_df, _ef);
	return _ff;
}
void* bb_init(void* operator_if, void* g, void* five2, void* five, void* f){
	struct bb_cls* reserved = (struct bb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &bb_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = g;
	*((void**) reserved + 4) = five2;
	*((void**) reserved + 5) = five;
	*((void**) reserved + 6) = f;
	return (void*) reserved;
}
struct ab_cls{
	void* (*call)(void*, void*);
	void *operator_if, *g, *five2, *five, *f;
};
void* ab_call(void* genenv, void* g){
	struct ab_cls *env = (struct ab_cls*) genenv;
	*((void**) env + 2) = g;
	void* _gf = bb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _hf = ((void*) 3);
	void* _if = apply(_gf, _hf);
	return _if;
}
void* ab_init(void* operator_if, void* five2, void* five, void* f){
	struct ab_cls* reserved = (struct ab_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ab_call;
	*((void**) reserved + 1) = operator_if;
	*((void**) reserved + 3) = five2;
	*((void**) reserved + 4) = five;
	*((void**) reserved + 5) = f;
	return (void*) reserved;
}
struct ib_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *five2, *five, *f;
};
void* ib_call(void* genenv, void* y){
	struct ib_cls *env = (struct ib_cls*) genenv;
	*((void**) env + 1) = y;
	void* _ag = (*((void**) env + 1 + 1));
	void* _bg = (*((void**) env + 1 + 0));
	void* _cg = (void*) ((long long)((long long) _ag * (long long) _bg));
	return _cg;
}
void* ib_init(void* x, void* operator_if, void* five2, void* five, void* f){
	struct ib_cls* reserved = (struct ib_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ib_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = five2;
	*((void**) reserved + 5) = five;
	*((void**) reserved + 6) = f;
	return (void*) reserved;
}
struct hb_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *five2, *five, *f;
};
void* hb_call(void* genenv, void* x){
	struct hb_cls *env = (struct hb_cls*) genenv;
	*((void**) env + 1) = x;
	void* _dg = ib_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	return _dg;
}
void* hb_init(void* operator_if, void* five2, void* five, void* f){
	struct hb_cls* reserved = (struct hb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &hb_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = five2;
	*((void**) reserved + 4) = five;
	*((void**) reserved + 5) = f;
	return (void*) reserved;
}
struct j_cls{
	void* (*call)(void*, void*);
	void *operator_if, *five2, *five, *f;
};
void* j_call(void* genenv, void* f){
	struct j_cls *env = (struct j_cls*) genenv;
	*((void**) env + 4) = f;
	void* _jf = ab_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _eg = hb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _fg = apply(_jf, _eg);
	return _fg;
}
void* j_init(void* operator_if, void* five2, void* five){
	struct j_cls* reserved = (struct j_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &j_call;
	*((void**) reserved + 1) = operator_if;
	*((void**) reserved + 2) = five2;
	*((void**) reserved + 3) = five;
	return (void*) reserved;
}
struct ac_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *five2, *five;
};
void* ac_call(void* genenv, void* y){
	struct ac_cls *env = (struct ac_cls*) genenv;
	*((void**) env + 1) = y;
	void* _hg = ((void*) 1);
	void* _ig = (*((void**) env + 1 + 1));
	void* _jg = ((void*) 2);
	void* _ah = (void*) ((long long)((long long) _ig - (long long) _jg));
	void* _bh = (void*) ((long long)((long long) _hg * (long long) _ah));
	void* _ch = (*((void**) env + 1 + 0));
	void* _dh = (void*) ((long long)((long long) _bh * (long long) _ch));
	return _dh;
}
void* ac_init(void* x, void* operator_if, void* five2, void* five){
	struct ac_cls* reserved = (struct ac_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ac_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = five2;
	*((void**) reserved + 5) = five;
	return (void*) reserved;
}
struct jb_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *five2, *five;
};
void* jb_call(void* genenv, void* x){
	struct jb_cls *env = (struct jb_cls*) genenv;
	*((void**) env + 1) = x;
	void* _eh = ac_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	return _eh;
}
void* jb_init(void* operator_if, void* five2, void* five){
	struct jb_cls* reserved = (struct jb_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &jb_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = five2;
	*((void**) reserved + 4) = five;
	return (void*) reserved;
}
struct d_cls{
	void* (*call)(void*, void*);
	void *operator_if, *five2, *five;
};
void* d_call(void* genenv, void* five2){
	struct d_cls *env = (struct d_cls*) genenv;
	*((void**) env + 2) = five2;
	void* _gg = j_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _fh = jb_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _gh = apply(_gg, _fh);
	void* _hc = e_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _gc = apply(_hc, _gh);
	return _gc;
}
void* d_init(void* operator_if, void* five){
	struct d_cls* reserved = (struct d_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &d_call;
	*((void**) reserved + 1) = operator_if;
	*((void**) reserved + 3) = five;
	return (void*) reserved;
}
struct fc_cls{
	void* (*call)(void*, void*);
	void *z, *y, *x, *operator_if, *g, *five, *f;
};
void* fc_call(void* genenv, void* z){
	struct fc_cls *env = (struct fc_cls*) genenv;
	*((void**) env + 1) = z;
	void* _ii = (*((void**) env + 1 + 0));
	void* _ji = ((void*) 1);
	void* _aj = (void*) ((long long)((long long) _ii + (long long) _ji));
	return _aj;
}
void* fc_init(void* y, void* x, void* operator_if, void* g, void* five, void* f){
	struct fc_cls* reserved = (struct fc_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &fc_call;
	*((void**) reserved + 2) = y;
	*((void**) reserved + 3) = x;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = g;
	*((void**) reserved + 6) = five;
	*((void**) reserved + 7) = f;
	return (void*) reserved;
}
struct ec_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *g, *five, *f;
};
void* ec_call(void* genenv, void* y){
	struct ec_cls *env = (struct ec_cls*) genenv;
	*((void**) env + 1) = y;
	void* _jh = (*((void**) env + 1 + 5));
	void* _ai = (*((void**) env + 1 + 3));
	void* _bi = (*((void**) env + 1 + 1));
	void* _ci = apply(_ai, _bi);
	void* _di = ((void*) 2);
	void* _ei = apply(_ci, _di);
	void* _fi = ((void*) 3);
	void* _gi = (void*) ((long long)((long long) _ei - (long long) _fi));
	void* _hi = apply(_jh, _gi);
	void* _bj = fc_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5), *((void**) env + 6));
	void* _cj = (*((void**) env + 1 + 0));
	void* _dj = apply(_bj, _cj);
	void* _ej = apply(_hi, _dj);
	return _ej;
}
void* ec_init(void* x, void* operator_if, void* g, void* five, void* f){
	struct ec_cls* reserved = (struct ec_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ec_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = g;
	*((void**) reserved + 5) = five;
	*((void**) reserved + 6) = f;
	return (void*) reserved;
}
struct dc_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *g, *five, *f;
};
void* dc_call(void* genenv, void* x){
	struct dc_cls *env = (struct dc_cls*) genenv;
	*((void**) env + 1) = x;
	void* _fj = ec_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _gj = ((void*) 4);
	void* _hj = apply(_fj, _gj);
	return _hj;
}
void* dc_init(void* operator_if, void* g, void* five, void* f){
	struct dc_cls* reserved = (struct dc_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &dc_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = g;
	*((void**) reserved + 4) = five;
	*((void**) reserved + 5) = f;
	return (void*) reserved;
}
struct cc_cls{
	void* (*call)(void*, void*);
	void *operator_if, *g, *five, *f;
};
void* cc_call(void* genenv, void* g){
	struct cc_cls *env = (struct cc_cls*) genenv;
	*((void**) env + 2) = g;
	void* _ij = dc_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _jj = ((void*) 3);
	void* _aab = apply(_ij, _jj);
	return _aab;
}
void* cc_init(void* operator_if, void* five, void* f){
	struct cc_cls* reserved = (struct cc_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &cc_call;
	*((void**) reserved + 1) = operator_if;
	*((void**) reserved + 3) = five;
	*((void**) reserved + 4) = f;
	return (void*) reserved;
}
struct hc_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *five, *f;
};
void* hc_call(void* genenv, void* y){
	struct hc_cls *env = (struct hc_cls*) genenv;
	*((void**) env + 1) = y;
	void* _cab = (*((void**) env + 1 + 1));
	void* _dab = (*((void**) env + 1 + 0));
	void* _eab = (void*) ((long long)((long long) _cab * (long long) _dab));
	return _eab;
}
void* hc_init(void* x, void* operator_if, void* five, void* f){
	struct hc_cls* reserved = (struct hc_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &hc_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = five;
	*((void**) reserved + 5) = f;
	return (void*) reserved;
}
struct gc_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *five, *f;
};
void* gc_call(void* genenv, void* x){
	struct gc_cls *env = (struct gc_cls*) genenv;
	*((void**) env + 1) = x;
	void* _fab = hc_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	return _fab;
}
void* gc_init(void* operator_if, void* five, void* f){
	struct gc_cls* reserved = (struct gc_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &gc_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = five;
	*((void**) reserved + 4) = f;
	return (void*) reserved;
}
struct bc_cls{
	void* (*call)(void*, void*);
	void *operator_if, *five, *f;
};
void* bc_call(void* genenv, void* f){
	struct bc_cls *env = (struct bc_cls*) genenv;
	*((void**) env + 3) = f;
	void* _bab = cc_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _gab = gc_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _hab = apply(_bab, _gab);
	return _hab;
}
void* bc_init(void* operator_if, void* five){
	struct bc_cls* reserved = (struct bc_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &bc_call;
	*((void**) reserved + 1) = operator_if;
	*((void**) reserved + 2) = five;
	return (void*) reserved;
}
struct jc_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *five;
};
void* jc_call(void* genenv, void* y){
	struct jc_cls *env = (struct jc_cls*) genenv;
	*((void**) env + 1) = y;
	void* _jab = ((void*) 1);
	void* _abb = (*((void**) env + 1 + 1));
	void* _bbb = ((void*) 2);
	void* _cbb = (void*) ((long long)((long long) _abb - (long long) _bbb));
	void* _dbb = (void*) ((long long)((long long) _jab * (long long) _cbb));
	void* _ebb = (*((void**) env + 1 + 0));
	void* _fbb = (void*) ((long long)((long long) _dbb * (long long) _ebb));
	return _fbb;
}
void* jc_init(void* x, void* operator_if, void* five){
	struct jc_cls* reserved = (struct jc_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &jc_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = five;
	return (void*) reserved;
}
struct ic_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *five;
};
void* ic_call(void* genenv, void* x){
	struct ic_cls *env = (struct ic_cls*) genenv;
	*((void**) env + 1) = x;
	void* _gbb = jc_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	return _gbb;
}
void* ic_init(void* operator_if, void* five){
	struct ic_cls* reserved = (struct ic_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ic_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = five;
	return (void*) reserved;
}
struct c_cls{
	void* (*call)(void*, void*);
	void *operator_if, *five;
};
void* c_call(void* genenv, void* five){
	struct c_cls *env = (struct c_cls*) genenv;
	*((void**) env + 2) = five;
	void* _iab = bc_init(*((void**) env + 1), *((void**) env + 2));
	void* _hbb = ic_init(*((void**) env + 1), *((void**) env + 2));
	void* _ibb = apply(_iab, _hbb);
	void* _ih = d_init(*((void**) env + 1), *((void**) env + 2));
	void* _hh = apply(_ih, _ibb);
	return _hh;
}
void* c_init(void* operator_if){
	struct c_cls* reserved = (struct c_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &c_call;
	*((void**) reserved + 1) = operator_if;
	return (void*) reserved;
}
struct ed_cls{
	void* (*call)(void*, void*);
	void *z, *y, *x, *operator_if, *g, *f;
};
void* ed_call(void* genenv, void* z){
	struct ed_cls *env = (struct ed_cls*) genenv;
	*((void**) env + 1) = z;
	void* _adb = (*((void**) env + 1 + 0));
	void* _bdb = ((void*) 1);
	void* _cdb = (void*) ((long long)((long long) _adb + (long long) _bdb));
	return _cdb;
}
void* ed_init(void* y, void* x, void* operator_if, void* g, void* f){
	struct ed_cls* reserved = (struct ed_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ed_call;
	*((void**) reserved + 2) = y;
	*((void**) reserved + 3) = x;
	*((void**) reserved + 4) = operator_if;
	*((void**) reserved + 5) = g;
	*((void**) reserved + 6) = f;
	return (void*) reserved;
}
struct dd_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *g, *f;
};
void* dd_call(void* genenv, void* y){
	struct dd_cls *env = (struct dd_cls*) genenv;
	*((void**) env + 1) = y;
	void* _bcb = (*((void**) env + 1 + 4));
	void* _ccb = (*((void**) env + 1 + 3));
	void* _dcb = (*((void**) env + 1 + 1));
	void* _ecb = apply(_ccb, _dcb);
	void* _fcb = ((void*) 2);
	void* _gcb = apply(_ecb, _fcb);
	void* _hcb = ((void*) 3);
	void* _icb = (void*) ((long long)((long long) _gcb - (long long) _hcb));
	void* _jcb = apply(_bcb, _icb);
	void* _ddb = ed_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4), *((void**) env + 5));
	void* _edb = (*((void**) env + 1 + 0));
	void* _fdb = apply(_ddb, _edb);
	void* _gdb = apply(_jcb, _fdb);
	return _gdb;
}
void* dd_init(void* x, void* operator_if, void* g, void* f){
	struct dd_cls* reserved = (struct dd_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &dd_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = g;
	*((void**) reserved + 5) = f;
	return (void*) reserved;
}
struct cd_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *g, *f;
};
void* cd_call(void* genenv, void* x){
	struct cd_cls *env = (struct cd_cls*) genenv;
	*((void**) env + 1) = x;
	void* _jdb = ((void*) 4);
	void* _idb = dd_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3), *((void**) env + 4));
	void* _hdb = apply(_idb, _jdb);
	return _hdb;
}
void* cd_init(void* operator_if, void* g, void* f){
	struct cd_cls* reserved = (struct cd_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &cd_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = g;
	*((void**) reserved + 4) = f;
	return (void*) reserved;
}
struct bd_cls{
	void* (*call)(void*, void*);
	void *operator_if, *g, *f;
};
void* bd_call(void* genenv, void* g){
	struct bd_cls *env = (struct bd_cls*) genenv;
	*((void**) env + 2) = g;
	void* _ceb = ((void*) 3);
	void* _beb = cd_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	void* _aeb = apply(_beb, _ceb);
	return _aeb;
}
void* bd_init(void* operator_if, void* f){
	struct bd_cls* reserved = (struct bd_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &bd_call;
	*((void**) reserved + 1) = operator_if;
	*((void**) reserved + 3) = f;
	return (void*) reserved;
}
struct gd_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if, *f;
};
void* gd_call(void* genenv, void* y){
	struct gd_cls *env = (struct gd_cls*) genenv;
	*((void**) env + 1) = y;
	void* _feb = (*((void**) env + 1 + 1));
	void* _geb = (*((void**) env + 1 + 0));
	void* _heb = (void*) ((long long)((long long) _feb * (long long) _geb));
	return _heb;
}
void* gd_init(void* x, void* operator_if, void* f){
	struct gd_cls* reserved = (struct gd_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &gd_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	*((void**) reserved + 4) = f;
	return (void*) reserved;
}
struct fd_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if, *f;
};
void* fd_call(void* genenv, void* x){
	struct fd_cls *env = (struct fd_cls*) genenv;
	*((void**) env + 1) = x;
	void* _ieb = gd_init(*((void**) env + 1), *((void**) env + 2), *((void**) env + 3));
	return _ieb;
}
void* fd_init(void* operator_if, void* f){
	struct fd_cls* reserved = (struct fd_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &fd_call;
	*((void**) reserved + 2) = operator_if;
	*((void**) reserved + 3) = f;
	return (void*) reserved;
}
struct ad_cls{
	void* (*call)(void*, void*);
	void *operator_if, *f;
};
void* ad_call(void* genenv, void* f){
	struct ad_cls *env = (struct ad_cls*) genenv;
	*((void**) env + 2) = f;
	void* _jeb = fd_init(*((void**) env + 1), *((void**) env + 2));
	void* _eeb = bd_init(*((void**) env + 1), *((void**) env + 2));
	void* _deb = apply(_eeb, _jeb);
	return _deb;
}
void* ad_init(void* operator_if){
	struct ad_cls* reserved = (struct ad_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ad_call;
	*((void**) reserved + 1) = operator_if;
	return (void*) reserved;
}
struct id_cls{
	void* (*call)(void*, void*);
	void *y, *x, *operator_if;
};
void* id_call(void* genenv, void* y){
	struct id_cls *env = (struct id_cls*) genenv;
	*((void**) env + 1) = y;
	void* _cfb = ((void*) 1);
	void* _dfb = (*((void**) env + 1 + 1));
	void* _efb = ((void*) 2);
	void* _ffb = (void*) ((long long)((long long) _dfb - (long long) _efb));
	void* _gfb = (void*) ((long long)((long long) _cfb * (long long) _ffb));
	void* _hfb = (*((void**) env + 1 + 0));
	void* _ifb = (void*) ((long long)((long long) _gfb * (long long) _hfb));
	return _ifb;
}
void* id_init(void* x, void* operator_if){
	struct id_cls* reserved = (struct id_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &id_call;
	*((void**) reserved + 2) = x;
	*((void**) reserved + 3) = operator_if;
	return (void*) reserved;
}
struct hd_cls{
	void* (*call)(void*, void*);
	void *x, *operator_if;
};
void* hd_call(void* genenv, void* x){
	struct hd_cls *env = (struct hd_cls*) genenv;
	*((void**) env + 1) = x;
	void* _jfb = id_init(*((void**) env + 1), *((void**) env + 2));
	return _jfb;
}
void* hd_init(void* operator_if){
	struct hd_cls* reserved = (struct hd_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &hd_call;
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
	void* _agb = hd_init(*((void**) env + 1));
	void* _bfb = ad_init(*((void**) env + 1));
	void* _afb = apply(_bfb, _agb);
	void* _acb = c_init(*((void**) env + 1));
	void* _jbb = apply(_acb, _afb);
	return _jbb;
}
void* b_init(){
	struct b_cls* reserved = (struct b_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &b_call;
	return (void*) reserved;
}
struct be_cls{
	void* (*call)(void*, void*);
	void *t, *e, *c;
};
void* be_call(void* genenv, void* e){
	struct be_cls *env = (struct be_cls*) genenv;
	*((void**) env + 2) = e;
	void* _dgb = (*((void**) env + 1 + 2));
	void* _egb = (*((void**) env + 1 + 0));
	void* _fgb = (*((void**) env + 1 + 1));
	void* _ggb;
	if(_dgb)
		_ggb = apply(_egb, NULL);
	else
		_ggb = apply(_fgb, NULL);
	return _ggb;
}
void* be_init(void* t, void* c){
	struct be_cls* reserved = (struct be_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &be_call;
	*((void**) reserved + 1) = t;
	*((void**) reserved + 3) = c;
	return (void*) reserved;
}
struct ae_cls{
	void* (*call)(void*, void*);
	void *t, *c;
};
void* ae_call(void* genenv, void* t){
	struct ae_cls *env = (struct ae_cls*) genenv;
	*((void**) env + 1) = t;
	void* _hgb = be_init(*((void**) env + 1), *((void**) env + 2));
	return _hgb;
}
void* ae_init(void* c){
	struct ae_cls* reserved = (struct ae_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &ae_call;
	*((void**) reserved + 2) = c;
	return (void*) reserved;
}
struct jd_cls{
	void* (*call)(void*, void*);
	void *c;
};
void* jd_call(void* genenv, void* c){
	struct jd_cls *env = (struct jd_cls*) genenv;
	*((void**) env + 1) = c;
	void* _igb = ae_init(*((void**) env + 1));
	return _igb;
}
void* jd_init(){
	struct jd_cls* reserved = (struct jd_cls*)malloc(sizeof(*reserved));
	*(void* (**) (void*, void*)) reserved = &jd_call;
	return (void*) reserved;
}

int main(){
	void* _jgb = jd_init();
	void* _cgb = b_init();
	void* _bgb = apply(_cgb, _jgb);
	printf("%lld\n", ((long long)_bgb));
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
%struct.h_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.i_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.j_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.ab_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.bb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.cb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.db_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.eb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.fb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.gb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.hb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.ib_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.jb_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.ac_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.bc_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.cc_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.dc_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.ec_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.fc_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.gc_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.hc_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.ic_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.jc_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.ad_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.bd_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.cd_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.dd_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8* }
%struct.ed_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8*, i8*, i8* }
%struct.fd_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.gd_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8*, i8* }
%struct.hd_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.id_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }
%struct.jd_cls = type { i8* (i8*, i8*)*, i8* }
%struct.ae_cls = type { i8* (i8*, i8*)*, i8*, i8* }
%struct.be_cls = type { i8* (i8*, i8*)*, i8*, i8*, i8* }

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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @g_init(i8* %six, i8* %operator_if, i8* %five3, i8* %five2, i8* %five) {
entry:
  %six1 = alloca i8*, align 8
  store i8* %six, i8** %six1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %five33 = alloca i8*, align 8
  store i8* %five3, i8** %five33, align 8
  %five24 = alloca i8*, align 8
  store i8* %five2, i8** %five24, align 8
  %five5 = alloca i8*, align 8
  store i8* %five, i8** %five5, align 8
  %reserved = alloca %struct.g_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.g_cls* getelementptr (%struct.g_cls, %struct.g_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.g_cls*
  store %struct.g_cls* %space, %struct.g_cls** %reserved, align 8
  %struct_load = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast = bitcast %struct.g_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @g_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %six1, align 8
  %struct_load6 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.g_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %operator_if2, align 8
  %struct_load9 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.g_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 2
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %five33, align 8
  %struct_load13 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.g_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %five24, align 8
  %struct_load17 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.g_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %five5, align 8
  %struct_load21 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.g_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.g_cls*, %struct.g_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.g_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

declare noalias i8* @malloc(i32)

define i8* @f_init(i8* %operator_if, i8* %five3, i8* %five2, i8* %five) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five32 = alloca i8*, align 8
  store i8* %five3, i8** %five32, align 8
  %five23 = alloca i8*, align 8
  store i8* %five2, i8** %five23, align 8
  %five4 = alloca i8*, align 8
  store i8* %five, i8** %five4, align 8
  %reserved = alloca %struct.f_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.f_cls* getelementptr (%struct.f_cls, %struct.f_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.f_cls*
  store %struct.f_cls* %space, %struct.f_cls** %reserved, align 8
  %struct_load = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast = bitcast %struct.f_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @f_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load5 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.f_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %five32, align 8
  %struct_load8 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.f_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %five23, align 8
  %struct_load12 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.f_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %five4, align 8
  %struct_load16 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.f_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.f_cls*, %struct.f_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.f_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
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

define i8* @i_init(i8* %x, i8* %operator_if, i8* %five3, i8* %five2, i8* %five) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %five33 = alloca i8*, align 8
  store i8* %five3, i8** %five33, align 8
  %five24 = alloca i8*, align 8
  store i8* %five2, i8** %five24, align 8
  %five5 = alloca i8*, align 8
  store i8* %five, i8** %five5, align 8
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %operator_if2, align 8
  %struct_load9 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.i_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 3
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %five33, align 8
  %struct_load13 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.i_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %five24, align 8
  %struct_load17 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.i_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %five5, align 8
  %struct_load21 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.i_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.i_cls*, %struct.i_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.i_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @h_init(i8* %operator_if, i8* %five3, i8* %five2, i8* %five) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five32 = alloca i8*, align 8
  store i8* %five3, i8** %five32, align 8
  %five23 = alloca i8*, align 8
  store i8* %five2, i8** %five23, align 8
  %five4 = alloca i8*, align 8
  store i8* %five, i8** %five4, align 8
  %reserved = alloca %struct.h_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.h_cls* getelementptr (%struct.h_cls, %struct.h_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.h_cls*
  store %struct.h_cls* %space, %struct.h_cls** %reserved, align 8
  %struct_load = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast = bitcast %struct.h_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @h_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load5 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.h_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %five32, align 8
  %struct_load8 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.h_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %five23, align 8
  %struct_load12 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.h_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %five4, align 8
  %struct_load16 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.h_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.h_cls*, %struct.h_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.h_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @e_init(i8* %operator_if, i8* %five2, i8* %five) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five22 = alloca i8*, align 8
  store i8* %five2, i8** %five22, align 8
  %five3 = alloca i8*, align 8
  store i8* %five, i8** %five3, align 8
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %five22, align 8
  %struct_load7 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.e_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %five3, align 8
  %struct_load11 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.e_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.e_cls*, %struct.e_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.e_cls* %struct_load14 to i8*
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 4
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
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

define i8* @fb_init(i8* %y, i8* %x, i8* %v, i8* %u, i8* %operator_if, i8* %g, i8* %five2, i8* %five, i8* %f) {
entry:
  %y1 = alloca i8*, align 8
  store i8* %y, i8** %y1, align 8
  %x2 = alloca i8*, align 8
  store i8* %x, i8** %x2, align 8
  %v3 = alloca i8*, align 8
  store i8* %v, i8** %v3, align 8
  %u4 = alloca i8*, align 8
  store i8* %u, i8** %u4, align 8
  %operator_if5 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if5, align 8
  %g6 = alloca i8*, align 8
  store i8* %g, i8** %g6, align 8
  %five27 = alloca i8*, align 8
  store i8* %five2, i8** %five27, align 8
  %five8 = alloca i8*, align 8
  store i8* %five, i8** %five8, align 8
  %f9 = alloca i8*, align 8
  store i8* %f, i8** %f9, align 8
  %reserved = alloca %struct.fb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.fb_cls* getelementptr (%struct.fb_cls, %struct.fb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.fb_cls*
  store %struct.fb_cls* %space, %struct.fb_cls** %reserved, align 8
  %struct_load = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.fb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @fb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %y1, align 8
  %struct_load10 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast11 = bitcast %struct.fb_cls* %struct_load10 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast11, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval12 = load i8*, i8** %x2, align 8
  %struct_load13 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.fb_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 3
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %v3, align 8
  %struct_load17 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.fb_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 4
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %u4, align 8
  %struct_load21 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.fb_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 5
  store i8* %argval20, i8** %elem_ptr23, align 8
  %argval24 = load i8*, i8** %operator_if5, align 8
  %struct_load25 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast26 = bitcast %struct.fb_cls* %struct_load25 to i8**
  %elem_ptr27 = getelementptr inbounds i8*, i8** %struct_cast26, i64 6
  store i8* %argval24, i8** %elem_ptr27, align 8
  %argval28 = load i8*, i8** %g6, align 8
  %struct_load29 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast30 = bitcast %struct.fb_cls* %struct_load29 to i8**
  %elem_ptr31 = getelementptr inbounds i8*, i8** %struct_cast30, i64 7
  store i8* %argval28, i8** %elem_ptr31, align 8
  %argval32 = load i8*, i8** %five27, align 8
  %struct_load33 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast34 = bitcast %struct.fb_cls* %struct_load33 to i8**
  %elem_ptr35 = getelementptr inbounds i8*, i8** %struct_cast34, i64 8
  store i8* %argval32, i8** %elem_ptr35, align 8
  %argval36 = load i8*, i8** %five8, align 8
  %struct_load37 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast38 = bitcast %struct.fb_cls* %struct_load37 to i8**
  %elem_ptr39 = getelementptr inbounds i8*, i8** %struct_cast38, i64 9
  store i8* %argval36, i8** %elem_ptr39, align 8
  %argval40 = load i8*, i8** %f9, align 8
  %struct_load41 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast42 = bitcast %struct.fb_cls* %struct_load41 to i8**
  %elem_ptr43 = getelementptr inbounds i8*, i8** %struct_cast42, i64 10
  store i8* %argval40, i8** %elem_ptr43, align 8
  %struct_load44 = load %struct.fb_cls*, %struct.fb_cls** %reserved, align 8
  %struct_cast45 = bitcast %struct.fb_cls* %struct_load44 to i8*
  ret i8* %struct_cast45
}

define i8* @eb_init(i8* %y, i8* %x, i8* %u, i8* %operator_if, i8* %g, i8* %five2, i8* %five, i8* %f) {
entry:
  %y1 = alloca i8*, align 8
  store i8* %y, i8** %y1, align 8
  %x2 = alloca i8*, align 8
  store i8* %x, i8** %x2, align 8
  %u3 = alloca i8*, align 8
  store i8* %u, i8** %u3, align 8
  %operator_if4 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if4, align 8
  %g5 = alloca i8*, align 8
  store i8* %g, i8** %g5, align 8
  %five26 = alloca i8*, align 8
  store i8* %five2, i8** %five26, align 8
  %five7 = alloca i8*, align 8
  store i8* %five, i8** %five7, align 8
  %f8 = alloca i8*, align 8
  store i8* %f, i8** %f8, align 8
  %reserved = alloca %struct.eb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.eb_cls* getelementptr (%struct.eb_cls, %struct.eb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.eb_cls*
  store %struct.eb_cls* %space, %struct.eb_cls** %reserved, align 8
  %struct_load = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.eb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @eb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %y1, align 8
  %struct_load9 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.eb_cls* %struct_load9 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast10, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval11 = load i8*, i8** %x2, align 8
  %struct_load12 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.eb_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 2
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %u3, align 8
  %struct_load16 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.eb_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 4
  store i8* %argval15, i8** %elem_ptr18, align 8
  %argval19 = load i8*, i8** %operator_if4, align 8
  %struct_load20 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast21 = bitcast %struct.eb_cls* %struct_load20 to i8**
  %elem_ptr22 = getelementptr inbounds i8*, i8** %struct_cast21, i64 5
  store i8* %argval19, i8** %elem_ptr22, align 8
  %argval23 = load i8*, i8** %g5, align 8
  %struct_load24 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.eb_cls* %struct_load24 to i8**
  %elem_ptr26 = getelementptr inbounds i8*, i8** %struct_cast25, i64 6
  store i8* %argval23, i8** %elem_ptr26, align 8
  %argval27 = load i8*, i8** %five26, align 8
  %struct_load28 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast29 = bitcast %struct.eb_cls* %struct_load28 to i8**
  %elem_ptr30 = getelementptr inbounds i8*, i8** %struct_cast29, i64 7
  store i8* %argval27, i8** %elem_ptr30, align 8
  %argval31 = load i8*, i8** %five7, align 8
  %struct_load32 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast33 = bitcast %struct.eb_cls* %struct_load32 to i8**
  %elem_ptr34 = getelementptr inbounds i8*, i8** %struct_cast33, i64 8
  store i8* %argval31, i8** %elem_ptr34, align 8
  %argval35 = load i8*, i8** %f8, align 8
  %struct_load36 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast37 = bitcast %struct.eb_cls* %struct_load36 to i8**
  %elem_ptr38 = getelementptr inbounds i8*, i8** %struct_cast37, i64 9
  store i8* %argval35, i8** %elem_ptr38, align 8
  %struct_load39 = load %struct.eb_cls*, %struct.eb_cls** %reserved, align 8
  %struct_cast40 = bitcast %struct.eb_cls* %struct_load39 to i8*
  ret i8* %struct_cast40
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

define i8* @gb_init(i8* %y, i8* %x, i8* %u, i8* %operator_if, i8* %g, i8* %five2, i8* %five, i8* %f) {
entry:
  %y1 = alloca i8*, align 8
  store i8* %y, i8** %y1, align 8
  %x2 = alloca i8*, align 8
  store i8* %x, i8** %x2, align 8
  %u3 = alloca i8*, align 8
  store i8* %u, i8** %u3, align 8
  %operator_if4 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if4, align 8
  %g5 = alloca i8*, align 8
  store i8* %g, i8** %g5, align 8
  %five26 = alloca i8*, align 8
  store i8* %five2, i8** %five26, align 8
  %five7 = alloca i8*, align 8
  store i8* %five, i8** %five7, align 8
  %f8 = alloca i8*, align 8
  store i8* %f, i8** %f8, align 8
  %reserved = alloca %struct.gb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.gb_cls* getelementptr (%struct.gb_cls, %struct.gb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.gb_cls*
  store %struct.gb_cls* %space, %struct.gb_cls** %reserved, align 8
  %struct_load = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.gb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @gb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %y1, align 8
  %struct_load9 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.gb_cls* %struct_load9 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast10, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval11 = load i8*, i8** %x2, align 8
  %struct_load12 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.gb_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 3
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %u3, align 8
  %struct_load16 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.gb_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 4
  store i8* %argval15, i8** %elem_ptr18, align 8
  %argval19 = load i8*, i8** %operator_if4, align 8
  %struct_load20 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast21 = bitcast %struct.gb_cls* %struct_load20 to i8**
  %elem_ptr22 = getelementptr inbounds i8*, i8** %struct_cast21, i64 5
  store i8* %argval19, i8** %elem_ptr22, align 8
  %argval23 = load i8*, i8** %g5, align 8
  %struct_load24 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.gb_cls* %struct_load24 to i8**
  %elem_ptr26 = getelementptr inbounds i8*, i8** %struct_cast25, i64 6
  store i8* %argval23, i8** %elem_ptr26, align 8
  %argval27 = load i8*, i8** %five26, align 8
  %struct_load28 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast29 = bitcast %struct.gb_cls* %struct_load28 to i8**
  %elem_ptr30 = getelementptr inbounds i8*, i8** %struct_cast29, i64 7
  store i8* %argval27, i8** %elem_ptr30, align 8
  %argval31 = load i8*, i8** %five7, align 8
  %struct_load32 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast33 = bitcast %struct.gb_cls* %struct_load32 to i8**
  %elem_ptr34 = getelementptr inbounds i8*, i8** %struct_cast33, i64 8
  store i8* %argval31, i8** %elem_ptr34, align 8
  %argval35 = load i8*, i8** %f8, align 8
  %struct_load36 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast37 = bitcast %struct.gb_cls* %struct_load36 to i8**
  %elem_ptr38 = getelementptr inbounds i8*, i8** %struct_cast37, i64 9
  store i8* %argval35, i8** %elem_ptr38, align 8
  %struct_load39 = load %struct.gb_cls*, %struct.gb_cls** %reserved, align 8
  %struct_cast40 = bitcast %struct.gb_cls* %struct_load39 to i8*
  ret i8* %struct_cast40
}

define i8* @db_init(i8* %y, i8* %x, i8* %operator_if, i8* %g, i8* %five2, i8* %five, i8* %f) {
entry:
  %y1 = alloca i8*, align 8
  store i8* %y, i8** %y1, align 8
  %x2 = alloca i8*, align 8
  store i8* %x, i8** %x2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %g4 = alloca i8*, align 8
  store i8* %g, i8** %g4, align 8
  %five25 = alloca i8*, align 8
  store i8* %five2, i8** %five25, align 8
  %five6 = alloca i8*, align 8
  store i8* %five, i8** %five6, align 8
  %f7 = alloca i8*, align 8
  store i8* %f, i8** %f7, align 8
  %reserved = alloca %struct.db_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.db_cls* getelementptr (%struct.db_cls, %struct.db_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.db_cls*
  store %struct.db_cls* %space, %struct.db_cls** %reserved, align 8
  %struct_load = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast = bitcast %struct.db_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @db_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %y1, align 8
  %struct_load8 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.db_cls* %struct_load8 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast9, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval10 = load i8*, i8** %x2, align 8
  %struct_load11 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.db_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 2
  store i8* %argval10, i8** %elem_ptr13, align 8
  %argval14 = load i8*, i8** %operator_if3, align 8
  %struct_load15 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast16 = bitcast %struct.db_cls* %struct_load15 to i8**
  %elem_ptr17 = getelementptr inbounds i8*, i8** %struct_cast16, i64 4
  store i8* %argval14, i8** %elem_ptr17, align 8
  %argval18 = load i8*, i8** %g4, align 8
  %struct_load19 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.db_cls* %struct_load19 to i8**
  %elem_ptr21 = getelementptr inbounds i8*, i8** %struct_cast20, i64 5
  store i8* %argval18, i8** %elem_ptr21, align 8
  %argval22 = load i8*, i8** %five25, align 8
  %struct_load23 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast24 = bitcast %struct.db_cls* %struct_load23 to i8**
  %elem_ptr25 = getelementptr inbounds i8*, i8** %struct_cast24, i64 6
  store i8* %argval22, i8** %elem_ptr25, align 8
  %argval26 = load i8*, i8** %five6, align 8
  %struct_load27 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast28 = bitcast %struct.db_cls* %struct_load27 to i8**
  %elem_ptr29 = getelementptr inbounds i8*, i8** %struct_cast28, i64 7
  store i8* %argval26, i8** %elem_ptr29, align 8
  %argval30 = load i8*, i8** %f7, align 8
  %struct_load31 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast32 = bitcast %struct.db_cls* %struct_load31 to i8**
  %elem_ptr33 = getelementptr inbounds i8*, i8** %struct_cast32, i64 8
  store i8* %argval30, i8** %elem_ptr33, align 8
  %struct_load34 = load %struct.db_cls*, %struct.db_cls** %reserved, align 8
  %struct_cast35 = bitcast %struct.db_cls* %struct_load34 to i8*
  ret i8* %struct_cast35
}

define i8* @cb_init(i8* %x, i8* %operator_if, i8* %g, i8* %five2, i8* %five, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %g3 = alloca i8*, align 8
  store i8* %g, i8** %g3, align 8
  %five24 = alloca i8*, align 8
  store i8* %five2, i8** %five24, align 8
  %five5 = alloca i8*, align 8
  store i8* %five, i8** %five5, align 8
  %f6 = alloca i8*, align 8
  store i8* %f, i8** %f6, align 8
  %reserved = alloca %struct.cb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.cb_cls* getelementptr (%struct.cb_cls, %struct.cb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.cb_cls*
  store %struct.cb_cls* %space, %struct.cb_cls** %reserved, align 8
  %struct_load = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.cb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @cb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load7 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.cb_cls* %struct_load7 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast8, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval9 = load i8*, i8** %operator_if2, align 8
  %struct_load10 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast11 = bitcast %struct.cb_cls* %struct_load10 to i8**
  %elem_ptr12 = getelementptr inbounds i8*, i8** %struct_cast11, i64 3
  store i8* %argval9, i8** %elem_ptr12, align 8
  %argval13 = load i8*, i8** %g3, align 8
  %struct_load14 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.cb_cls* %struct_load14 to i8**
  %elem_ptr16 = getelementptr inbounds i8*, i8** %struct_cast15, i64 4
  store i8* %argval13, i8** %elem_ptr16, align 8
  %argval17 = load i8*, i8** %five24, align 8
  %struct_load18 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast19 = bitcast %struct.cb_cls* %struct_load18 to i8**
  %elem_ptr20 = getelementptr inbounds i8*, i8** %struct_cast19, i64 5
  store i8* %argval17, i8** %elem_ptr20, align 8
  %argval21 = load i8*, i8** %five5, align 8
  %struct_load22 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast23 = bitcast %struct.cb_cls* %struct_load22 to i8**
  %elem_ptr24 = getelementptr inbounds i8*, i8** %struct_cast23, i64 6
  store i8* %argval21, i8** %elem_ptr24, align 8
  %argval25 = load i8*, i8** %f6, align 8
  %struct_load26 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast27 = bitcast %struct.cb_cls* %struct_load26 to i8**
  %elem_ptr28 = getelementptr inbounds i8*, i8** %struct_cast27, i64 7
  store i8* %argval25, i8** %elem_ptr28, align 8
  %struct_load29 = load %struct.cb_cls*, %struct.cb_cls** %reserved, align 8
  %struct_cast30 = bitcast %struct.cb_cls* %struct_load29 to i8*
  ret i8* %struct_cast30
}

define i8* @bb_init(i8* %operator_if, i8* %g, i8* %five2, i8* %five, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %g2 = alloca i8*, align 8
  store i8* %g, i8** %g2, align 8
  %five23 = alloca i8*, align 8
  store i8* %five2, i8** %five23, align 8
  %five4 = alloca i8*, align 8
  store i8* %five, i8** %five4, align 8
  %f5 = alloca i8*, align 8
  store i8* %f, i8** %f5, align 8
  %reserved = alloca %struct.bb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.bb_cls* getelementptr (%struct.bb_cls, %struct.bb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.bb_cls*
  store %struct.bb_cls* %space, %struct.bb_cls** %reserved, align 8
  %struct_load = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.bb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @bb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load6 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.bb_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %g2, align 8
  %struct_load9 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.bb_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 3
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %five23, align 8
  %struct_load13 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.bb_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %five4, align 8
  %struct_load17 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.bb_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %f5, align 8
  %struct_load21 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.bb_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.bb_cls*, %struct.bb_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.bb_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @ab_init(i8* %operator_if, i8* %five2, i8* %five, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five22 = alloca i8*, align 8
  store i8* %five2, i8** %five22, align 8
  %five3 = alloca i8*, align 8
  store i8* %five, i8** %five3, align 8
  %f4 = alloca i8*, align 8
  store i8* %f, i8** %f4, align 8
  %reserved = alloca %struct.ab_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ab_cls* getelementptr (%struct.ab_cls, %struct.ab_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ab_cls*
  store %struct.ab_cls* %space, %struct.ab_cls** %reserved, align 8
  %struct_load = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ab_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ab_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load5 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.ab_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %five22, align 8
  %struct_load8 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.ab_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %five3, align 8
  %struct_load12 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.ab_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %f4, align 8
  %struct_load16 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.ab_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.ab_cls*, %struct.ab_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.ab_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
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

define i8* @ib_init(i8* %x, i8* %operator_if, i8* %five2, i8* %five, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %five23 = alloca i8*, align 8
  store i8* %five2, i8** %five23, align 8
  %five4 = alloca i8*, align 8
  store i8* %five, i8** %five4, align 8
  %f5 = alloca i8*, align 8
  store i8* %f, i8** %f5, align 8
  %reserved = alloca %struct.ib_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ib_cls* getelementptr (%struct.ib_cls, %struct.ib_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ib_cls*
  store %struct.ib_cls* %space, %struct.ib_cls** %reserved, align 8
  %struct_load = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ib_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ib_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.ib_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %operator_if2, align 8
  %struct_load9 = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.ib_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 3
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %five23, align 8
  %struct_load13 = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.ib_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %five4, align 8
  %struct_load17 = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.ib_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %f5, align 8
  %struct_load21 = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.ib_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.ib_cls*, %struct.ib_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.ib_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @hb_init(i8* %operator_if, i8* %five2, i8* %five, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five22 = alloca i8*, align 8
  store i8* %five2, i8** %five22, align 8
  %five3 = alloca i8*, align 8
  store i8* %five, i8** %five3, align 8
  %f4 = alloca i8*, align 8
  store i8* %f, i8** %f4, align 8
  %reserved = alloca %struct.hb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.hb_cls* getelementptr (%struct.hb_cls, %struct.hb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.hb_cls*
  store %struct.hb_cls* %space, %struct.hb_cls** %reserved, align 8
  %struct_load = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.hb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @hb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load5 = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.hb_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %five22, align 8
  %struct_load8 = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.hb_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %five3, align 8
  %struct_load12 = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.hb_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %f4, align 8
  %struct_load16 = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.hb_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.hb_cls*, %struct.hb_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.hb_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @j_init(i8* %operator_if, i8* %five2, i8* %five) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five22 = alloca i8*, align 8
  store i8* %five2, i8** %five22, align 8
  %five3 = alloca i8*, align 8
  store i8* %five, i8** %five3, align 8
  %reserved = alloca %struct.j_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.j_cls* getelementptr (%struct.j_cls, %struct.j_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.j_cls*
  store %struct.j_cls* %space, %struct.j_cls** %reserved, align 8
  %struct_load = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast = bitcast %struct.j_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @j_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.j_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %five22, align 8
  %struct_load7 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.j_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 2
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %five3, align 8
  %struct_load11 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.j_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 3
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.j_cls*, %struct.j_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.j_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
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
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @ac_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.ac_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.ac_cls*
  store %struct.ac_cls* %struct_cast, %struct.ac_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.ac_cls*, %struct.ac_cls** %env, align 8
  %struct_cast4 = bitcast %struct.ac_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @ac_init(i8* %x, i8* %operator_if, i8* %five2, i8* %five) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %five23 = alloca i8*, align 8
  store i8* %five2, i8** %five23, align 8
  %five4 = alloca i8*, align 8
  store i8* %five, i8** %five4, align 8
  %reserved = alloca %struct.ac_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ac_cls* getelementptr (%struct.ac_cls, %struct.ac_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ac_cls*
  store %struct.ac_cls* %space, %struct.ac_cls** %reserved, align 8
  %struct_load = load %struct.ac_cls*, %struct.ac_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ac_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ac_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load5 = load %struct.ac_cls*, %struct.ac_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.ac_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %operator_if2, align 8
  %struct_load8 = load %struct.ac_cls*, %struct.ac_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.ac_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %five23, align 8
  %struct_load12 = load %struct.ac_cls*, %struct.ac_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.ac_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %five4, align 8
  %struct_load16 = load %struct.ac_cls*, %struct.ac_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.ac_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.ac_cls*, %struct.ac_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.ac_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @jb_init(i8* %operator_if, i8* %five2, i8* %five) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five22 = alloca i8*, align 8
  store i8* %five2, i8** %five22, align 8
  %five3 = alloca i8*, align 8
  store i8* %five, i8** %five3, align 8
  %reserved = alloca %struct.jb_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.jb_cls* getelementptr (%struct.jb_cls, %struct.jb_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.jb_cls*
  store %struct.jb_cls* %space, %struct.jb_cls** %reserved, align 8
  %struct_load = load %struct.jb_cls*, %struct.jb_cls** %reserved, align 8
  %struct_cast = bitcast %struct.jb_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @jb_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.jb_cls*, %struct.jb_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.jb_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %five22, align 8
  %struct_load7 = load %struct.jb_cls*, %struct.jb_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.jb_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %five3, align 8
  %struct_load11 = load %struct.jb_cls*, %struct.jb_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.jb_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.jb_cls*, %struct.jb_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.jb_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @d_init(i8* %operator_if, i8* %five) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five2 = alloca i8*, align 8
  store i8* %five, i8** %five2, align 8
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
  %argval5 = load i8*, i8** %five2, align 8
  %struct_load6 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.d_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.d_cls*, %struct.d_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.d_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @bc_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.bc_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.bc_cls*
  store %struct.bc_cls* %struct_cast, %struct.bc_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.bc_cls*, %struct.bc_cls** %env, align 8
  %struct_cast4 = bitcast %struct.bc_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 3
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @cc_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.cc_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.cc_cls*
  store %struct.cc_cls* %struct_cast, %struct.cc_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.cc_cls*, %struct.cc_cls** %env, align 8
  %struct_cast4 = bitcast %struct.cc_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @dc_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.dc_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.dc_cls*
  store %struct.dc_cls* %struct_cast, %struct.dc_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.dc_cls*, %struct.dc_cls** %env, align 8
  %struct_cast4 = bitcast %struct.dc_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @ec_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.ec_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.ec_cls*
  store %struct.ec_cls* %struct_cast, %struct.ec_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.ec_cls*, %struct.ec_cls** %env, align 8
  %struct_cast4 = bitcast %struct.ec_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @fc_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.fc_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.fc_cls*
  store %struct.fc_cls* %struct_cast, %struct.fc_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.fc_cls*, %struct.fc_cls** %env, align 8
  %struct_cast4 = bitcast %struct.fc_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @fc_init(i8* %y, i8* %x, i8* %operator_if, i8* %g, i8* %five, i8* %f) {
entry:
  %y1 = alloca i8*, align 8
  store i8* %y, i8** %y1, align 8
  %x2 = alloca i8*, align 8
  store i8* %x, i8** %x2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %g4 = alloca i8*, align 8
  store i8* %g, i8** %g4, align 8
  %five5 = alloca i8*, align 8
  store i8* %five, i8** %five5, align 8
  %f6 = alloca i8*, align 8
  store i8* %f, i8** %f6, align 8
  %reserved = alloca %struct.fc_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.fc_cls* getelementptr (%struct.fc_cls, %struct.fc_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.fc_cls*
  store %struct.fc_cls* %space, %struct.fc_cls** %reserved, align 8
  %struct_load = load %struct.fc_cls*, %struct.fc_cls** %reserved, align 8
  %struct_cast = bitcast %struct.fc_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @fc_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %y1, align 8
  %struct_load7 = load %struct.fc_cls*, %struct.fc_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.fc_cls* %struct_load7 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast8, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval9 = load i8*, i8** %x2, align 8
  %struct_load10 = load %struct.fc_cls*, %struct.fc_cls** %reserved, align 8
  %struct_cast11 = bitcast %struct.fc_cls* %struct_load10 to i8**
  %elem_ptr12 = getelementptr inbounds i8*, i8** %struct_cast11, i64 3
  store i8* %argval9, i8** %elem_ptr12, align 8
  %argval13 = load i8*, i8** %operator_if3, align 8
  %struct_load14 = load %struct.fc_cls*, %struct.fc_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.fc_cls* %struct_load14 to i8**
  %elem_ptr16 = getelementptr inbounds i8*, i8** %struct_cast15, i64 4
  store i8* %argval13, i8** %elem_ptr16, align 8
  %argval17 = load i8*, i8** %g4, align 8
  %struct_load18 = load %struct.fc_cls*, %struct.fc_cls** %reserved, align 8
  %struct_cast19 = bitcast %struct.fc_cls* %struct_load18 to i8**
  %elem_ptr20 = getelementptr inbounds i8*, i8** %struct_cast19, i64 5
  store i8* %argval17, i8** %elem_ptr20, align 8
  %argval21 = load i8*, i8** %five5, align 8
  %struct_load22 = load %struct.fc_cls*, %struct.fc_cls** %reserved, align 8
  %struct_cast23 = bitcast %struct.fc_cls* %struct_load22 to i8**
  %elem_ptr24 = getelementptr inbounds i8*, i8** %struct_cast23, i64 6
  store i8* %argval21, i8** %elem_ptr24, align 8
  %argval25 = load i8*, i8** %f6, align 8
  %struct_load26 = load %struct.fc_cls*, %struct.fc_cls** %reserved, align 8
  %struct_cast27 = bitcast %struct.fc_cls* %struct_load26 to i8**
  %elem_ptr28 = getelementptr inbounds i8*, i8** %struct_cast27, i64 7
  store i8* %argval25, i8** %elem_ptr28, align 8
  %struct_load29 = load %struct.fc_cls*, %struct.fc_cls** %reserved, align 8
  %struct_cast30 = bitcast %struct.fc_cls* %struct_load29 to i8*
  ret i8* %struct_cast30
}

define i8* @ec_init(i8* %x, i8* %operator_if, i8* %g, i8* %five, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %g3 = alloca i8*, align 8
  store i8* %g, i8** %g3, align 8
  %five4 = alloca i8*, align 8
  store i8* %five, i8** %five4, align 8
  %f5 = alloca i8*, align 8
  store i8* %f, i8** %f5, align 8
  %reserved = alloca %struct.ec_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ec_cls* getelementptr (%struct.ec_cls, %struct.ec_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ec_cls*
  store %struct.ec_cls* %space, %struct.ec_cls** %reserved, align 8
  %struct_load = load %struct.ec_cls*, %struct.ec_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ec_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ec_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load6 = load %struct.ec_cls*, %struct.ec_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.ec_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %operator_if2, align 8
  %struct_load9 = load %struct.ec_cls*, %struct.ec_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.ec_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 3
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %g3, align 8
  %struct_load13 = load %struct.ec_cls*, %struct.ec_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.ec_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %five4, align 8
  %struct_load17 = load %struct.ec_cls*, %struct.ec_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.ec_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %f5, align 8
  %struct_load21 = load %struct.ec_cls*, %struct.ec_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.ec_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.ec_cls*, %struct.ec_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.ec_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @dc_init(i8* %operator_if, i8* %g, i8* %five, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %g2 = alloca i8*, align 8
  store i8* %g, i8** %g2, align 8
  %five3 = alloca i8*, align 8
  store i8* %five, i8** %five3, align 8
  %f4 = alloca i8*, align 8
  store i8* %f, i8** %f4, align 8
  %reserved = alloca %struct.dc_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.dc_cls* getelementptr (%struct.dc_cls, %struct.dc_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.dc_cls*
  store %struct.dc_cls* %space, %struct.dc_cls** %reserved, align 8
  %struct_load = load %struct.dc_cls*, %struct.dc_cls** %reserved, align 8
  %struct_cast = bitcast %struct.dc_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @dc_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load5 = load %struct.dc_cls*, %struct.dc_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.dc_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %g2, align 8
  %struct_load8 = load %struct.dc_cls*, %struct.dc_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.dc_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %five3, align 8
  %struct_load12 = load %struct.dc_cls*, %struct.dc_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.dc_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %f4, align 8
  %struct_load16 = load %struct.dc_cls*, %struct.dc_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.dc_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.dc_cls*, %struct.dc_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.dc_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @cc_init(i8* %operator_if, i8* %five, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five2 = alloca i8*, align 8
  store i8* %five, i8** %five2, align 8
  %f3 = alloca i8*, align 8
  store i8* %f, i8** %f3, align 8
  %reserved = alloca %struct.cc_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.cc_cls* getelementptr (%struct.cc_cls, %struct.cc_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.cc_cls*
  store %struct.cc_cls* %space, %struct.cc_cls** %reserved, align 8
  %struct_load = load %struct.cc_cls*, %struct.cc_cls** %reserved, align 8
  %struct_cast = bitcast %struct.cc_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @cc_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.cc_cls*, %struct.cc_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.cc_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %five2, align 8
  %struct_load7 = load %struct.cc_cls*, %struct.cc_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.cc_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %f3, align 8
  %struct_load11 = load %struct.cc_cls*, %struct.cc_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.cc_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.cc_cls*, %struct.cc_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.cc_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @gc_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.gc_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.gc_cls*
  store %struct.gc_cls* %struct_cast, %struct.gc_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.gc_cls*, %struct.gc_cls** %env, align 8
  %struct_cast4 = bitcast %struct.gc_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @hc_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.hc_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.hc_cls*
  store %struct.hc_cls* %struct_cast, %struct.hc_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.hc_cls*, %struct.hc_cls** %env, align 8
  %struct_cast4 = bitcast %struct.hc_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @hc_init(i8* %x, i8* %operator_if, i8* %five, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %five3 = alloca i8*, align 8
  store i8* %five, i8** %five3, align 8
  %f4 = alloca i8*, align 8
  store i8* %f, i8** %f4, align 8
  %reserved = alloca %struct.hc_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.hc_cls* getelementptr (%struct.hc_cls, %struct.hc_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.hc_cls*
  store %struct.hc_cls* %space, %struct.hc_cls** %reserved, align 8
  %struct_load = load %struct.hc_cls*, %struct.hc_cls** %reserved, align 8
  %struct_cast = bitcast %struct.hc_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @hc_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load5 = load %struct.hc_cls*, %struct.hc_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.hc_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %operator_if2, align 8
  %struct_load8 = load %struct.hc_cls*, %struct.hc_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.hc_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %five3, align 8
  %struct_load12 = load %struct.hc_cls*, %struct.hc_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.hc_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %f4, align 8
  %struct_load16 = load %struct.hc_cls*, %struct.hc_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.hc_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.hc_cls*, %struct.hc_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.hc_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @gc_init(i8* %operator_if, i8* %five, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five2 = alloca i8*, align 8
  store i8* %five, i8** %five2, align 8
  %f3 = alloca i8*, align 8
  store i8* %f, i8** %f3, align 8
  %reserved = alloca %struct.gc_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.gc_cls* getelementptr (%struct.gc_cls, %struct.gc_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.gc_cls*
  store %struct.gc_cls* %space, %struct.gc_cls** %reserved, align 8
  %struct_load = load %struct.gc_cls*, %struct.gc_cls** %reserved, align 8
  %struct_cast = bitcast %struct.gc_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @gc_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.gc_cls*, %struct.gc_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.gc_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %five2, align 8
  %struct_load7 = load %struct.gc_cls*, %struct.gc_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.gc_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %f3, align 8
  %struct_load11 = load %struct.gc_cls*, %struct.gc_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.gc_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.gc_cls*, %struct.gc_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.gc_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @bc_init(i8* %operator_if, i8* %five) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five2 = alloca i8*, align 8
  store i8* %five, i8** %five2, align 8
  %reserved = alloca %struct.bc_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.bc_cls* getelementptr (%struct.bc_cls, %struct.bc_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.bc_cls*
  store %struct.bc_cls* %space, %struct.bc_cls** %reserved, align 8
  %struct_load = load %struct.bc_cls*, %struct.bc_cls** %reserved, align 8
  %struct_cast = bitcast %struct.bc_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @bc_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load3 = load %struct.bc_cls*, %struct.bc_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.bc_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %five2, align 8
  %struct_load6 = load %struct.bc_cls*, %struct.bc_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.bc_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.bc_cls*, %struct.bc_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.bc_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @ic_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.ic_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.ic_cls*
  store %struct.ic_cls* %struct_cast, %struct.ic_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.ic_cls*, %struct.ic_cls** %env, align 8
  %struct_cast4 = bitcast %struct.ic_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @jc_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.jc_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.jc_cls*
  store %struct.jc_cls* %struct_cast, %struct.jc_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.jc_cls*, %struct.jc_cls** %env, align 8
  %struct_cast4 = bitcast %struct.jc_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @jc_init(i8* %x, i8* %operator_if, i8* %five) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %five3 = alloca i8*, align 8
  store i8* %five, i8** %five3, align 8
  %reserved = alloca %struct.jc_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.jc_cls* getelementptr (%struct.jc_cls, %struct.jc_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.jc_cls*
  store %struct.jc_cls* %space, %struct.jc_cls** %reserved, align 8
  %struct_load = load %struct.jc_cls*, %struct.jc_cls** %reserved, align 8
  %struct_cast = bitcast %struct.jc_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @jc_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load4 = load %struct.jc_cls*, %struct.jc_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.jc_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %operator_if2, align 8
  %struct_load7 = load %struct.jc_cls*, %struct.jc_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.jc_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %five3, align 8
  %struct_load11 = load %struct.jc_cls*, %struct.jc_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.jc_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.jc_cls*, %struct.jc_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.jc_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @ic_init(i8* %operator_if, i8* %five) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %five2 = alloca i8*, align 8
  store i8* %five, i8** %five2, align 8
  %reserved = alloca %struct.ic_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ic_cls* getelementptr (%struct.ic_cls, %struct.ic_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ic_cls*
  store %struct.ic_cls* %space, %struct.ic_cls** %reserved, align 8
  %struct_load = load %struct.ic_cls*, %struct.ic_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ic_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ic_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load3 = load %struct.ic_cls*, %struct.ic_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.ic_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %five2, align 8
  %struct_load6 = load %struct.ic_cls*, %struct.ic_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.ic_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.ic_cls*, %struct.ic_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.ic_cls* %struct_load9 to i8*
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

define i8* @ad_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.ad_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.ad_cls*
  store %struct.ad_cls* %struct_cast, %struct.ad_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.ad_cls*, %struct.ad_cls** %env, align 8
  %struct_cast4 = bitcast %struct.ad_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @bd_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.bd_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.bd_cls*
  store %struct.bd_cls* %struct_cast, %struct.bd_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.bd_cls*, %struct.bd_cls** %env, align 8
  %struct_cast4 = bitcast %struct.bd_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @cd_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.cd_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.cd_cls*
  store %struct.cd_cls* %struct_cast, %struct.cd_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.cd_cls*, %struct.cd_cls** %env, align 8
  %struct_cast4 = bitcast %struct.cd_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @dd_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.dd_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.dd_cls*
  store %struct.dd_cls* %struct_cast, %struct.dd_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.dd_cls*, %struct.dd_cls** %env, align 8
  %struct_cast4 = bitcast %struct.dd_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @ed_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.ed_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.ed_cls*
  store %struct.ed_cls* %struct_cast, %struct.ed_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.ed_cls*, %struct.ed_cls** %env, align 8
  %struct_cast4 = bitcast %struct.ed_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @ed_init(i8* %y, i8* %x, i8* %operator_if, i8* %g, i8* %f) {
entry:
  %y1 = alloca i8*, align 8
  store i8* %y, i8** %y1, align 8
  %x2 = alloca i8*, align 8
  store i8* %x, i8** %x2, align 8
  %operator_if3 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if3, align 8
  %g4 = alloca i8*, align 8
  store i8* %g, i8** %g4, align 8
  %f5 = alloca i8*, align 8
  store i8* %f, i8** %f5, align 8
  %reserved = alloca %struct.ed_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ed_cls* getelementptr (%struct.ed_cls, %struct.ed_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ed_cls*
  store %struct.ed_cls* %space, %struct.ed_cls** %reserved, align 8
  %struct_load = load %struct.ed_cls*, %struct.ed_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ed_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ed_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %y1, align 8
  %struct_load6 = load %struct.ed_cls*, %struct.ed_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.ed_cls* %struct_load6 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast7, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval8 = load i8*, i8** %x2, align 8
  %struct_load9 = load %struct.ed_cls*, %struct.ed_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.ed_cls* %struct_load9 to i8**
  %elem_ptr11 = getelementptr inbounds i8*, i8** %struct_cast10, i64 3
  store i8* %argval8, i8** %elem_ptr11, align 8
  %argval12 = load i8*, i8** %operator_if3, align 8
  %struct_load13 = load %struct.ed_cls*, %struct.ed_cls** %reserved, align 8
  %struct_cast14 = bitcast %struct.ed_cls* %struct_load13 to i8**
  %elem_ptr15 = getelementptr inbounds i8*, i8** %struct_cast14, i64 4
  store i8* %argval12, i8** %elem_ptr15, align 8
  %argval16 = load i8*, i8** %g4, align 8
  %struct_load17 = load %struct.ed_cls*, %struct.ed_cls** %reserved, align 8
  %struct_cast18 = bitcast %struct.ed_cls* %struct_load17 to i8**
  %elem_ptr19 = getelementptr inbounds i8*, i8** %struct_cast18, i64 5
  store i8* %argval16, i8** %elem_ptr19, align 8
  %argval20 = load i8*, i8** %f5, align 8
  %struct_load21 = load %struct.ed_cls*, %struct.ed_cls** %reserved, align 8
  %struct_cast22 = bitcast %struct.ed_cls* %struct_load21 to i8**
  %elem_ptr23 = getelementptr inbounds i8*, i8** %struct_cast22, i64 6
  store i8* %argval20, i8** %elem_ptr23, align 8
  %struct_load24 = load %struct.ed_cls*, %struct.ed_cls** %reserved, align 8
  %struct_cast25 = bitcast %struct.ed_cls* %struct_load24 to i8*
  ret i8* %struct_cast25
}

define i8* @dd_init(i8* %x, i8* %operator_if, i8* %g, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %g3 = alloca i8*, align 8
  store i8* %g, i8** %g3, align 8
  %f4 = alloca i8*, align 8
  store i8* %f, i8** %f4, align 8
  %reserved = alloca %struct.dd_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.dd_cls* getelementptr (%struct.dd_cls, %struct.dd_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.dd_cls*
  store %struct.dd_cls* %space, %struct.dd_cls** %reserved, align 8
  %struct_load = load %struct.dd_cls*, %struct.dd_cls** %reserved, align 8
  %struct_cast = bitcast %struct.dd_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @dd_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load5 = load %struct.dd_cls*, %struct.dd_cls** %reserved, align 8
  %struct_cast6 = bitcast %struct.dd_cls* %struct_load5 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast6, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval7 = load i8*, i8** %operator_if2, align 8
  %struct_load8 = load %struct.dd_cls*, %struct.dd_cls** %reserved, align 8
  %struct_cast9 = bitcast %struct.dd_cls* %struct_load8 to i8**
  %elem_ptr10 = getelementptr inbounds i8*, i8** %struct_cast9, i64 3
  store i8* %argval7, i8** %elem_ptr10, align 8
  %argval11 = load i8*, i8** %g3, align 8
  %struct_load12 = load %struct.dd_cls*, %struct.dd_cls** %reserved, align 8
  %struct_cast13 = bitcast %struct.dd_cls* %struct_load12 to i8**
  %elem_ptr14 = getelementptr inbounds i8*, i8** %struct_cast13, i64 4
  store i8* %argval11, i8** %elem_ptr14, align 8
  %argval15 = load i8*, i8** %f4, align 8
  %struct_load16 = load %struct.dd_cls*, %struct.dd_cls** %reserved, align 8
  %struct_cast17 = bitcast %struct.dd_cls* %struct_load16 to i8**
  %elem_ptr18 = getelementptr inbounds i8*, i8** %struct_cast17, i64 5
  store i8* %argval15, i8** %elem_ptr18, align 8
  %struct_load19 = load %struct.dd_cls*, %struct.dd_cls** %reserved, align 8
  %struct_cast20 = bitcast %struct.dd_cls* %struct_load19 to i8*
  ret i8* %struct_cast20
}

define i8* @cd_init(i8* %operator_if, i8* %g, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %g2 = alloca i8*, align 8
  store i8* %g, i8** %g2, align 8
  %f3 = alloca i8*, align 8
  store i8* %f, i8** %f3, align 8
  %reserved = alloca %struct.cd_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.cd_cls* getelementptr (%struct.cd_cls, %struct.cd_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.cd_cls*
  store %struct.cd_cls* %space, %struct.cd_cls** %reserved, align 8
  %struct_load = load %struct.cd_cls*, %struct.cd_cls** %reserved, align 8
  %struct_cast = bitcast %struct.cd_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @cd_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load4 = load %struct.cd_cls*, %struct.cd_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.cd_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %g2, align 8
  %struct_load7 = load %struct.cd_cls*, %struct.cd_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.cd_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %f3, align 8
  %struct_load11 = load %struct.cd_cls*, %struct.cd_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.cd_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.cd_cls*, %struct.cd_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.cd_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @bd_init(i8* %operator_if, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %f2 = alloca i8*, align 8
  store i8* %f, i8** %f2, align 8
  %reserved = alloca %struct.bd_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.bd_cls* getelementptr (%struct.bd_cls, %struct.bd_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.bd_cls*
  store %struct.bd_cls* %space, %struct.bd_cls** %reserved, align 8
  %struct_load = load %struct.bd_cls*, %struct.bd_cls** %reserved, align 8
  %struct_cast = bitcast %struct.bd_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @bd_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load3 = load %struct.bd_cls*, %struct.bd_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.bd_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %f2, align 8
  %struct_load6 = load %struct.bd_cls*, %struct.bd_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.bd_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.bd_cls*, %struct.bd_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.bd_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @fd_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.fd_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.fd_cls*
  store %struct.fd_cls* %struct_cast, %struct.fd_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.fd_cls*, %struct.fd_cls** %env, align 8
  %struct_cast4 = bitcast %struct.fd_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @gd_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.gd_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.gd_cls*
  store %struct.gd_cls* %struct_cast, %struct.gd_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.gd_cls*, %struct.gd_cls** %env, align 8
  %struct_cast4 = bitcast %struct.gd_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @gd_init(i8* %x, i8* %operator_if, i8* %f) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %f3 = alloca i8*, align 8
  store i8* %f, i8** %f3, align 8
  %reserved = alloca %struct.gd_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.gd_cls* getelementptr (%struct.gd_cls, %struct.gd_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.gd_cls*
  store %struct.gd_cls* %space, %struct.gd_cls** %reserved, align 8
  %struct_load = load %struct.gd_cls*, %struct.gd_cls** %reserved, align 8
  %struct_cast = bitcast %struct.gd_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @gd_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load4 = load %struct.gd_cls*, %struct.gd_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.gd_cls* %struct_load4 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast5, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval6 = load i8*, i8** %operator_if2, align 8
  %struct_load7 = load %struct.gd_cls*, %struct.gd_cls** %reserved, align 8
  %struct_cast8 = bitcast %struct.gd_cls* %struct_load7 to i8**
  %elem_ptr9 = getelementptr inbounds i8*, i8** %struct_cast8, i64 3
  store i8* %argval6, i8** %elem_ptr9, align 8
  %argval10 = load i8*, i8** %f3, align 8
  %struct_load11 = load %struct.gd_cls*, %struct.gd_cls** %reserved, align 8
  %struct_cast12 = bitcast %struct.gd_cls* %struct_load11 to i8**
  %elem_ptr13 = getelementptr inbounds i8*, i8** %struct_cast12, i64 4
  store i8* %argval10, i8** %elem_ptr13, align 8
  %struct_load14 = load %struct.gd_cls*, %struct.gd_cls** %reserved, align 8
  %struct_cast15 = bitcast %struct.gd_cls* %struct_load14 to i8*
  ret i8* %struct_cast15
}

define i8* @fd_init(i8* %operator_if, i8* %f) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %f2 = alloca i8*, align 8
  store i8* %f, i8** %f2, align 8
  %reserved = alloca %struct.fd_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.fd_cls* getelementptr (%struct.fd_cls, %struct.fd_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.fd_cls*
  store %struct.fd_cls* %space, %struct.fd_cls** %reserved, align 8
  %struct_load = load %struct.fd_cls*, %struct.fd_cls** %reserved, align 8
  %struct_cast = bitcast %struct.fd_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @fd_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load3 = load %struct.fd_cls*, %struct.fd_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.fd_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %f2, align 8
  %struct_load6 = load %struct.fd_cls*, %struct.fd_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.fd_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.fd_cls*, %struct.fd_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.fd_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @ad_init(i8* %operator_if) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %reserved = alloca %struct.ad_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ad_cls* getelementptr (%struct.ad_cls, %struct.ad_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ad_cls*
  store %struct.ad_cls* %space, %struct.ad_cls** %reserved, align 8
  %struct_load = load %struct.ad_cls*, %struct.ad_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ad_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ad_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load2 = load %struct.ad_cls*, %struct.ad_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.ad_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.ad_cls*, %struct.ad_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.ad_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
}

define i8* @hd_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.hd_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.hd_cls*
  store %struct.hd_cls* %struct_cast, %struct.hd_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.hd_cls*, %struct.hd_cls** %env, align 8
  %struct_cast4 = bitcast %struct.hd_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @id_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.id_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.id_cls*
  store %struct.id_cls* %struct_cast, %struct.id_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.id_cls*, %struct.id_cls** %env, align 8
  %struct_cast4 = bitcast %struct.id_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @id_init(i8* %x, i8* %operator_if) {
entry:
  %x1 = alloca i8*, align 8
  store i8* %x, i8** %x1, align 8
  %operator_if2 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if2, align 8
  %reserved = alloca %struct.id_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.id_cls* getelementptr (%struct.id_cls, %struct.id_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.id_cls*
  store %struct.id_cls* %space, %struct.id_cls** %reserved, align 8
  %struct_load = load %struct.id_cls*, %struct.id_cls** %reserved, align 8
  %struct_cast = bitcast %struct.id_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @id_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %x1, align 8
  %struct_load3 = load %struct.id_cls*, %struct.id_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.id_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %operator_if2, align 8
  %struct_load6 = load %struct.id_cls*, %struct.id_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.id_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.id_cls*, %struct.id_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.id_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @hd_init(i8* %operator_if) {
entry:
  %operator_if1 = alloca i8*, align 8
  store i8* %operator_if, i8** %operator_if1, align 8
  %reserved = alloca %struct.hd_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.hd_cls* getelementptr (%struct.hd_cls, %struct.hd_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.hd_cls*
  store %struct.hd_cls* %space, %struct.hd_cls** %reserved, align 8
  %struct_load = load %struct.hd_cls*, %struct.hd_cls** %reserved, align 8
  %struct_cast = bitcast %struct.hd_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @hd_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %operator_if1, align 8
  %struct_load2 = load %struct.hd_cls*, %struct.hd_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.hd_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.hd_cls*, %struct.hd_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.hd_cls* %struct_load4 to i8*
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

define i8* @jd_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.jd_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.jd_cls*
  store %struct.jd_cls* %struct_cast, %struct.jd_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.jd_cls*, %struct.jd_cls** %env, align 8
  %struct_cast4 = bitcast %struct.jd_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @ae_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.ae_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.ae_cls*
  store %struct.ae_cls* %struct_cast, %struct.ae_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.ae_cls*, %struct.ae_cls** %env, align 8
  %struct_cast4 = bitcast %struct.ae_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @be_call(i8* %genenv, i8* %arg) {
entry:
  %genenv1 = alloca i8*, align 8
  store i8* %genenv, i8** %genenv1, align 8
  %arg2 = alloca i8*, align 8
  store i8* %arg, i8** %arg2, align 8
  %env = alloca %struct.be_cls*, align 8
  %struct_load = load i8*, i8** %genenv1, align 8
  %struct_cast = bitcast i8* %struct_load to %struct.be_cls*
  store %struct.be_cls* %struct_cast, %struct.be_cls** %env, align 8
  %argval = load i8*, i8** %arg2, align 8
  %struct_load3 = load %struct.be_cls*, %struct.be_cls** %env, align 8
  %struct_cast4 = bitcast %struct.be_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
}

define i8* @be_init(i8* %t, i8* %c) {
entry:
  %t1 = alloca i8*, align 8
  store i8* %t, i8** %t1, align 8
  %c2 = alloca i8*, align 8
  store i8* %c, i8** %c2, align 8
  %reserved = alloca %struct.be_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.be_cls* getelementptr (%struct.be_cls, %struct.be_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.be_cls*
  store %struct.be_cls* %space, %struct.be_cls** %reserved, align 8
  %struct_load = load %struct.be_cls*, %struct.be_cls** %reserved, align 8
  %struct_cast = bitcast %struct.be_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @be_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %t1, align 8
  %struct_load3 = load %struct.be_cls*, %struct.be_cls** %reserved, align 8
  %struct_cast4 = bitcast %struct.be_cls* %struct_load3 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast4, i64 1
  store i8* %argval, i8** %elem_ptr, align 8
  %argval5 = load i8*, i8** %c2, align 8
  %struct_load6 = load %struct.be_cls*, %struct.be_cls** %reserved, align 8
  %struct_cast7 = bitcast %struct.be_cls* %struct_load6 to i8**
  %elem_ptr8 = getelementptr inbounds i8*, i8** %struct_cast7, i64 3
  store i8* %argval5, i8** %elem_ptr8, align 8
  %struct_load9 = load %struct.be_cls*, %struct.be_cls** %reserved, align 8
  %struct_cast10 = bitcast %struct.be_cls* %struct_load9 to i8*
  ret i8* %struct_cast10
}

define i8* @ae_init(i8* %c) {
entry:
  %c1 = alloca i8*, align 8
  store i8* %c, i8** %c1, align 8
  %reserved = alloca %struct.ae_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.ae_cls* getelementptr (%struct.ae_cls, %struct.ae_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.ae_cls*
  store %struct.ae_cls* %space, %struct.ae_cls** %reserved, align 8
  %struct_load = load %struct.ae_cls*, %struct.ae_cls** %reserved, align 8
  %struct_cast = bitcast %struct.ae_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @ae_call, i8* (i8*, i8*)** %struct_cast, align 8
  %argval = load i8*, i8** %c1, align 8
  %struct_load2 = load %struct.ae_cls*, %struct.ae_cls** %reserved, align 8
  %struct_cast3 = bitcast %struct.ae_cls* %struct_load2 to i8**
  %elem_ptr = getelementptr inbounds i8*, i8** %struct_cast3, i64 2
  store i8* %argval, i8** %elem_ptr, align 8
  %struct_load4 = load %struct.ae_cls*, %struct.ae_cls** %reserved, align 8
  %struct_cast5 = bitcast %struct.ae_cls* %struct_load4 to i8*
  ret i8* %struct_cast5
}

define i8* @jd_init() {
entry:
  %reserved = alloca %struct.jd_cls*, align 8
  %malloccall = tail call i8* @malloc(i32 ptrtoint (%struct.jd_cls* getelementptr (%struct.jd_cls, %struct.jd_cls* null, i32 1) to i32))
  %space = bitcast i8* %malloccall to %struct.jd_cls*
  store %struct.jd_cls* %space, %struct.jd_cls** %reserved, align 8
  %struct_load = load %struct.jd_cls*, %struct.jd_cls** %reserved, align 8
  %struct_cast = bitcast %struct.jd_cls* %struct_load to i8* (i8*, i8*)**
  store i8* (i8*, i8*)* @jd_call, i8* (i8*, i8*)** %struct_cast, align 8
  %struct_load1 = load %struct.jd_cls*, %struct.jd_cls** %reserved, align 8
  %struct_cast2 = bitcast %struct.jd_cls* %struct_load1 to i8*
  ret i8* %struct_cast2
}
*/