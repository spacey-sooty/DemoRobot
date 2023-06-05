#pragma once

#include "globals.h"

#include <frc/XboxController.h>
#include <units/time.h>

#include <iostream>

struct intakeConfig {
  Gearbox &left;
  Gearbox &right;
};

enum class intakeState {
  kIdle,
  kIntaking,
  kHolding
};

class intake {
  public :
    intake(intakeConfig config, frc::XboxController &driver);
    ~intake();

    intakeConfig &GetConfig() { return _config; };

    void SetIntaking() { _state = intakeState::kIntaking; };
    void SetIdle() { _state = intakeState::kIdle; };
    void SetHolding() { _state = intakeState::kHolding; };

    void OnStart();
    void OnUpdate(units::second_t dt);

  private :
    intakeConfig _config;
    frc::XboxController &_driver;
    intakeState _state;
};