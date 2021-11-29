# include "horizontal_estimator.h"

// Class constructor
HorizontalEstimator :: HorizontalEstimator () : flow (PA_7 ,PA_6 ,PA_5 , PB_4 )
{
    x = 0.0;
    y = 0.0;
    u = 0.0;
    v = 0.0;
}

// Initialize class
void HorizontalEstimator :: init ()
{
    flow.init();
}

// Predict horizontal positions and velocities from model
void HorizontalEstimator :: predict ( float phi , float theta )
{
    x = x + u*dt;
    y = y + v*dt;
    u = u + g*theta*dt;
    v = v - g*phi*dt;
}

// Correct horizontal velocities with measurements
void HorizontalEstimator :: correct ( float phi , float theta , float p, float q, float z)
{
    float den = cos(phi)* cos(theta);
    if ( den > 0.5)
    {
    float d = z/den;

    flow.read();
    float u_m = d*(sigma*flow.px + q);
    float v_m = d*(sigma*flow.py - p);
    u = u + wc_11*dt*(u_m - u);
    v = v + wc_11*dt*(v_m - v);
    }
}