
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Motor(struct FB_Motor* inst)
{
	
	inst->integrator1.dt = inst->dt/inst->Tm;
	inst->integrator2.dt = inst->dt;
	
	inst->integrator1.in = inst->u / inst->ke - inst->w;
	FB_Integrator(&inst->integrator1);
	inst->integrator2.in = inst->integrator1.out;
	FB_Integrator(&inst->integrator2);
	inst->w = inst->integrator1.out;
	inst->phi = inst->integrator2.out;
}
