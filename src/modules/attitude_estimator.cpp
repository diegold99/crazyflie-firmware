#include "attitude_estimator.h"
#include <cmath>

// Class constructor
AttitudeEstimator :: AttitudeEstimator () : imu ( IMU_SDA , IMU_SCL )
{
phi = 0.0;
theta = 0.0;
psi = 0.0;
p = 0.0;
q = 0.0;
r = 0.0;
}
// Initialize class
void AttitudeEstimator :: init ()
{
    imu.init();
    
    //phi
    float somat = 0;
    float somat_2 = 0;
    float somat_3 = 0;
    for (int i=0; i <500; i ++)
    {
        imu.read();
        somat = somat + imu.gx;
        somat_2 = somat_2 + imu.gy;
        somat_3 = somat_3 + imu.gz ;
        wait (dt);
    }
    pbias = somat/500;   
    qbias = somat_2/500; 
    rbias = somat_3/500;
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator :: estimate ()
{
imu.read();
p = imu.gx - pbias;
q = imu.gy - qbias;
r = imu.gz - rbias;

// Acelerômetro phi
//float phi_a = atan2(-imu.ay, -imu.az);
//float phi_antigo = phi;
//phi = (1-alfa)*phi_antigo + alfa*phi_a;

// Giroscópio phi
//float phi_antigo = phi;
//float phi_g = phi_antigo + p*dt;
//phi = (1-alfa)*phi_g;

// Acelerômetro e Giroscópio phi
float phi_a = atan2(-imu.ay, -imu.az);
float phi_antigo = phi;
float phi_g = phi_antigo + p*dt;
phi = (1-alfa)*phi_g + alfa*phi_a;

// Acelerômetro e Giroscópio theta
float theta_a = atan2(imu.ax, -imu.az);
float theta_antigo = theta;
float theta_g = theta_antigo + q*dt;
theta = (1-alfa)*theta_g + alfa*theta_a;

// Giroscópio psi
float psi_antigo = psi;
float psi_g = psi_antigo + r*dt;
psi = psi_g;

}



