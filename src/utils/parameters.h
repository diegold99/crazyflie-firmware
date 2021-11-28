#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

// Lab 2 - a1 e a2
const float a1 = 1.174e-7;
const float a2 = 3.274e-12;

// Lab 3 - constante de sustentação
const float kl = 1.726e-08;

// Lab 4 - 
const float kd = 1.3134e-10;

// Lab 7 - a1 e a2
const float wc = 1; // rad/s
const float dt = 1/500; // s
const float alfa = wc*dt/(1+wc*dt);

// Lab 8 - Kp e Kd
const float kp_phi = 240.28;
const float kd_phi = 26.67;

const float kp_theta = 240.28;
const float kd_theta = 26.67;

const float kp_psi = 60.07;
const float kd_psi = 13.33;


// Lab 9 - Frequência de correção
const float dt20 = 1/20;
const float wc2 = 10; // rad/s
const float zeta = sqrt(2)/2 ;// fator de amortecimento
const float l1 = wc2*wc2;
const float l2 = 2*zeta*wc2;


#endif