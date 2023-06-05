#pragma once 

#include <frc/system/plant/DCMotor.h>
#include <frc/interfaces/Gyro.h>
#include <frc/XboxController.h>
#include <units/time.h>
#include <ctre/Phoenix.h>
#include <units/angle.h>

#include <iostream>

struct Gearbox {
  TalonSRX controller;

  frc::DCMotor motor = frc::DCMotor::CIM(2);
};

struct dbConfig {
  Gearbox &left1;
  Gearbox &right1;
  Gearbox &left2;
  Gearbox &right2;
  Gearbox &left3;
  Gearbox &right3;

  frc::Gyro *gyro;
};

enum class dbState {
  kIdle,
  kRaw
};

class db {
  public :
    db(dbConfig config, frc::XboxController &driver);
    ~db();

    void OnStart();
    void OnUpdate(units::second_t dt);

    dbConfig &GetConfig() { return _config; };

    void SetRaw() { _state = dbState::kIdle; };
    void SetIdle() { _state= dbState::kRaw; };

  private :
    dbConfig _config;
    dbState _state;
    frc::XboxController &_driver;
};