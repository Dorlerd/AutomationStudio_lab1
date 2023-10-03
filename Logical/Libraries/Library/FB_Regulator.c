
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
void FB_Regulator(struct FB_Regulator* inst)
{
	

	inst->integrator.dt = inst->dt;
	
	inst->temp = inst->e * inst->k_p > inst->max_abs_value ? inst->max_abs_value : inst->e * inst->k_p;
	inst->temp = inst->e * inst->k_p < -inst->max_abs_value ? -inst->max_abs_value : inst->e * inst->k_p;	

	
	inst->integrator.in = inst->e * inst->k_i + inst->temp_pos;
	FB_Integrator(&inst->integrator);
	
	inst->temp += inst->integrator.out;
	inst->temp2 = inst->temp;
	
	inst->temp = inst->temp > inst->max_abs_value ? inst->max_abs_value : inst->temp;
	inst->temp = inst->temp < -inst->max_abs_value ? -inst->max_abs_value : inst->temp;
	
	inst->temp_pos = inst->temp - inst->temp2;
	
	inst->u = inst->temp;
}
