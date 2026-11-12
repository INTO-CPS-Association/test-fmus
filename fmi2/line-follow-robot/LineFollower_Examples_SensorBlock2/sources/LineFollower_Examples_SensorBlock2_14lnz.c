/* Linearization */
#include "LineFollower_Examples_SensorBlock2_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *LineFollower_Examples_SensorBlock2_linear_model_frame()
{
  return "model linear_LineFollower_Examples_SensorBlock2\n  parameter Integer n = 0; // states\n  parameter Integer k = 4; // top-level inputs\n  parameter Integer l = 1; // top-level outputs\n"
  "  parameter Real x0[0] = {%s};\n"
  "  parameter Real u0[4] = {%s};\n"
  "  parameter Real A[0,0] = zeros(0,0);%s\n"
  "  parameter Real B[0,4] = zeros(0,4);%s\n"
  "  parameter Real C[1,0] = zeros(1,0);%s\n"
  "  parameter Real D[1,4] = [%s];\n"
  "  Real x[0];\n"
  "  input Real u[4](start= u0);\n"
  "  output Real y[1];\n"
  "\n    Real 'u_robot_theta' = u[1];\n  Real 'u_robot_x' = u[2];\n  Real 'u_robot_y' = u[3];\n  Real 'u_robot_z' = u[4];\n  Real 'y_lf_1_sensor_reading' = y[1];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_LineFollower_Examples_SensorBlock2;\n";
}
const char *LineFollower_Examples_SensorBlock2_linear_model_datarecovery_frame()
{
  return "model linear_LineFollower_Examples_SensorBlock2\n  parameter Integer n = 0; // states\n  parameter Integer k = 4; // top-level inputs\n  parameter Integer l = 1; // top-level outputs\n  parameter Integer nz = 20; // data recovery variables\n"
  "  parameter Real x0[0] = {%s};\n"
  "  parameter Real u0[4] = {%s};\n"
  "  parameter Real z0[20] = {%s};\n"
  "  parameter Real A[0,0] = zeros(0,0);%s\n"
  "  parameter Real B[0,4] = zeros(0,4);%s\n"
  "  parameter Real C[1,0] = zeros(1,0);%s\n"
  "  parameter Real D[1,4] = [%s];\n"
  "  parameter Real Cz[20,0] = zeros(20,0);%s\n"
  "  parameter Real Dz[20,4] = [%s];\n"
  "  Real x[0];\n"
  "  input Real u[4](start= u0);\n"
  "  output Real y[1];\n"
  "  output Real z[20];\n"
  "\n  Real 'u_robot_theta' = u[1];\n  Real 'u_robot_x' = u[2];\n  Real 'u_robot_y' = u[3];\n  Real 'u_robot_z' = u[4];\n  Real 'y_lf_1_sensor_reading' = y[1];\n  Real 'z_lf_1_sensor_reading' = z[1];\n  Real 'z_robot_theta' = z[2];\n  Real 'z_robot_x' = z[3];\n  Real 'z_robot_y' = z[4];\n  Real 'z_robot_z' = z[5];\n  Real 'z_sensor1.ad_8bit1.ad_8bitblock1.half_lsb' = z[6];\n  Real 'z_sensor1.ad_8bit1.ad_8bitblock1.hold_signal' = z[7];\n  Real 'z_sensor1.ad_8bit1.ad_8bitblock1.lsb' = z[8];\n  Real 'z_sensor1.ad_8bit1.ad_8bitblock1.noise' = z[9];\n  Real 'z_sensor1.ad_8bit1.ad_8bitblock1.quantisized_signal' = z[10];\n  Real 'z_sensor1.ad_8bit1.ad_8bitblock1.windowed_signal' = z[11];\n  Real 'z_sensor1.ad_8bit1.i' = z[12];\n  Real 'z_sensor1.ambient_light1.i' = z[13];\n  Real 'z_sensor1.ambient_light1.o' = z[14];\n  Real 'z_sensor1.ambient_light1.reflected_power' = z[15];\n  Real 'z_sensor1.calculate_sensor_position1.rotated_x' = z[16];\n  Real 'z_sensor1.calculate_sensor_position1.rotated_y' = z[17];\n  Real 'z_sensor1.calculate_sensor_position1.sensor_position[1]' = z[18];\n  Real 'z_sensor1.calculate_sensor_position1.sensor_position[2]' = z[19];\n  Real 'z_sensor1.combitable2d1.y' = z[20];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_LineFollower_Examples_SensorBlock2;\n";
}
#if defined(__cplusplus)
}
#endif

