#pragma once

#include <ctre/Phoenix.h>
#include <frc/XboxController.h>
#include <frc/system/plant/DCMotor.h>
#include <frc/interfaces/Gyro.h>


struct Gearbox {
  TalonSRX controller;
  frc::DCMotor motor = frc::DCMotor::CIM(2);
};