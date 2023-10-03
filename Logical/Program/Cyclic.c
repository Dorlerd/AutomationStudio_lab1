
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	fb_motor.ke = 0.24;
	fb_motor.Tm = 0.1;
	fb_motor.dt = 0.1;
	
	fb_motor_without_con.ke = 0.24;
	fb_motor_without_con.Tm = 0.1;
	fb_motor_without_con.dt = 0.1;
	
	fb_controller.k_i = 7.2;
	fb_controller.k_p = 0.78;
	fb_controller.max_abs_value = 24;
	fb_controller.temp_pos = 0;
	fb_controller.dt = 0.1;
	
	fb_motor_1.ke = 0.0241;
	fb_motor_1.Tm = 0.0226;
	fb_motor_1.dt = 0.01;
	
	fb_controller_1.k_i = 0.8;
	fb_controller_1.k_p = 0.018;
	fb_controller_1.max_abs_value = 24;
	fb_controller_1.temp_pos = 0;
	fb_controller_1.dt = 0.01;
	
	fb_motor_2.ke = 0.0735;
	fb_motor_2.Tm = 0.0147;
	fb_motor_2.dt = 0.01;
	
	fb_controller_2.k_i = 2.45;
	fb_controller_2.k_p = 0.036;
	fb_controller_2.max_abs_value = 24;
	fb_controller_2.temp_pos = 0;
	fb_controller_2.dt = 0.01;
	
	if(counter == 200)
	{
		Speed = 0;
		counter = 0;
	}
	if (counter == 50)
	{
		Speed = 50;
	}
	counter++;
	if (Enable)
	{
		fb_motor_without_con.u = Speed - feedback_without_con;
		FB_Motor(&fb_motor_without_con);
	
		feedback_without_con = fb_motor_without_con.w;
		
		
		
		fb_controller.e = Speed - feedback;
		FB_Regulator(&fb_controller);
	
		fb_motor.u = fb_controller.u;
		FB_Motor(&fb_motor);
	
		feedback = fb_motor.w;
		
		fb_controller_1.e = Speed - feedback_1;
		FB_Regulator(&fb_controller_1);
	
		fb_motor_1.u = fb_controller_1.u;
		FB_Motor(&fb_motor_1);
	
		feedback_1 = fb_motor_1.w;
		
		fb_controller_2.e = Speed - feedback_2;
		FB_Regulator(&fb_controller_2);
	
		fb_motor_2.u = fb_controller_2.u;
		FB_Motor(&fb_motor_2);
	
		feedback_2 = fb_motor_2.w;
	}	

}
