#include "stdafx.h"
#ifndef __AOP_XZ_ROTATE_H__
#define  __AOP_XZ_ROTATE_H__
#include "term.h"
#include "a_op.h"
#include "trig_coefficients.h"


class AopXZRotate {
	//bilinear a-operator Term + Trig Function according to spin rotation
public:
	a_op aop;
	trig_coefficients trc;
	int sz_power; //power of sz-factor (sz is equal to 1/2 or -1/2)
//Methods
	void add_analytic_operator(term &t, int type, int n);//type: 0 - S_plus, 1 - S_minus

	bool operator==(const AopXZRotate TxzR2)const;
	
	bool operator<(const AopXZRotate TxzR2)const;
	
	void clear();
};

#endif //end of __AOP_XZ_ROTATE_H__