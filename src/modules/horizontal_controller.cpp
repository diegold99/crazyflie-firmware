# include "horizontal_controller.h"

// Class constructor
HorizontalController :: HorizontalController ()
{
    phi_r = 0.0;
    theta_r = 0.0;
}

// Control reference roll and pitch angles ( rad ) given reference positions (m) and current positions (m) and velocities (m/s)
void HorizontalController :: control ( float x_r , float y_r , float x, float y, float u, float v)
{
    float x_r_acc = control_siso(x_r, x, u, kp_12, kd_12);
    float y_r_acc = control_siso(y_r, y, v, kp_12, kd_12);
    theta_r = 1*x_r_acc/g;
    phi_r = -1*y_r_acc/g;
}

// Control acceleration given reference position (m) and current position (m) and velocity (m/s) with given controller gains
float HorizontalController :: control_siso ( float pos_r , float pos , float vel , float kp , float kd)
{
    //Controlador regulador de estados
    return kp*(pos_r - pos) + kd*(0-vel);
}