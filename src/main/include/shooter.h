#pragma once

#include "globals.h"

#include <units/time.h>

#include <iostream>

enum class shooterState {
  kShooting,
  kIdle
};

struct shooterConfig {
  Gearbox &spinner;
};

class shooter {
  public :
    shooter(shooterConfig config, frc::XboxController &_driver);
    ~shooter();

    shooterConfig &GetConfig() { return _config; };

    void SetShooting() { _state = shooterState::kShooting; }
    void SetIdle() { _state = shooterState::kIdle; }

    void OnStart();
    void OnUpdate(units::second_t dt);

  private :
    shooterConfig _config;
    frc::XboxController &_driver;
    shooterState _state;
};