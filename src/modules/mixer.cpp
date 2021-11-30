# include "mixer.h"
// Class constructor
Mixer :: Mixer () : motor_1 ( MOTOR1 ), motor_2 ( MOTOR2 ), motor_3 ( MOTOR3 ), motor_4 ( MOTOR4 )
{
motor_1 . period (1.0/500.0) ;
motor_2 . period (1.0/500.0) ;
motor_3 . period (1.0/500.0) ;
motor_4 . period (1.0/500.0) ;
motor_1 = 0.0;
motor_2 = 0.0;
motor_3 = 0.0;
motor_4 = 0.0;
}
// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer :: actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
mixer (f_t , tau_phi , tau_theta , tau_psi );
motor_1 = control_motor ( omega_1 );
motor_2 = control_motor ( omega_2 );
motor_3 = control_motor ( omega_3 );
motor_4 = control_motor ( omega_4 );
}
// Convert total trust force (N) and torques (N.m) to angular velocities ( rad /s)
void Mixer :: mixer ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    float divA= 4*kl;
    float divB = 4*kl*l;
    float divC = 4*kd;

    omega_1 = sqrt(f_t/divA - tau_phi/divB - tau_theta/divB - tau_psi/divC);
    omega_2 = sqrt(f_t/divA - tau_phi*divB + tau_theta/divB + tau_psi/divC);
    omega_3 = sqrt(f_t/divA + tau_phi/divB + tau_theta/divB - tau_psi/divC);
    omega_4 = sqrt(f_t/divA + tau_phi/divB - tau_theta/divB + tau_psi/divC);
}
// Convert desired angular velocity ( rad /s) to PWM signal (%)
float Mixer :: control_motor ( float omega )
{
    //PWM = a2*omega*omega + a1*omega
    return a2*omega*omega + a1*omega;
}